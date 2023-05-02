import {DEFAULT_URL} from "../index";

const loginStateChanger = store => next => action =>{
    switch (action.type) {

        case "APP_LOGIN":{
            sendLoginRequest(store, action.value.history);
            return(next(action))
        }
        default:{next(action)}
    }
};

const sendLoginRequest = (store, history)=>{
    let user = {login: store.getState().loginState.login, password: store.getState().loginState.password};
    let req = new XMLHttpRequest();
    req.open("POST", `${DEFAULT_URL}/login`, true);
    req.onload = ()=>handleLoginResponse(req.responseText, store, history);
    req.onerror = ()=> alert("Сервер временно недоступен");
    req.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    req.send(`username=${user.login}&password=${user.password}`);
};

const  handleLoginResponse = (text, store, history)=>{
    let response = JSON.parse(text);

    if(response.status===200){
        window.localStorage.setItem("user", store.getState().loginState.login);
        store.dispatch({type:"APP_LOGIN_SUCCESS", value:store.getState().loginState.login});
        history.push("/application");
    }
    else store.dispatch({type: "LOGIN_SET_ERROR", value: true})
};

export default loginStateChanger;