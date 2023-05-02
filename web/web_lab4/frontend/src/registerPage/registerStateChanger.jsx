import {DEFAULT_URL} from "../index";

const registerStateChanger = store => next => action =>{
    switch (action.type) {

        case "APP_REGISTER":{
            register(store, action.value.history);
            return(next(action))
        }
        case "APP_REGISTER_SUCCESS":{
            store.dispatch({type: "LOGIN_SET_LOGIN", value: store.getState().registerState.login});
            store.dispatch({type: "LOGIN_SET_PASSWORD", value: store.getState().registerState.password});
            store.dispatch({type: "APP_LOGIN", value:{history: action.value.history}});
            return(next(action));
        }
        default:{next(action)}
    }
};

const register = (store, history)=>{

    if(store.getState().registerState.password===store.getState().registerState.rPassword){
        store.dispatch({type: "REGISTER_SET_PASSWORD_ERROR",value: false});
        sendLoginRequest(store, history)
    }
    else{
        store.dispatch({type: "REGISTER_SET_PASSWORD_ERROR",value: true});
    }
};

const sendLoginRequest = (store, history)=>{
    let user = {login: store.getState().registerState.login, password: store.getState().registerState.password};
    let req = new XMLHttpRequest();
    req.open("POST", `${DEFAULT_URL}/register`, true);
    req.onload = ()=>handleRegisterResponse(req.responseText, store, history);
    req.onerror = ()=> alert("Сервер временно недоступен");
    req.setRequestHeader('Content-Type', 'application/json');
    req.send(JSON.stringify(user));
};

const handleRegisterResponse = (text, store, history)=>{
    let response = JSON.parse(text);

    if(response.status===200){
        store.dispatch({type: "APP_REGISTER_SUCCESS", value:{history: history}})
    }
    else store.dispatch({type: "REGISTER_SET_LOGIN_ERROR",value: true});
};

export default registerStateChanger;