import {createStore} from 'redux';
import reducers from './reducers';
import middleware from "./combineStateChangers";


const initialState = {
    appState:{
        user: window.localStorage.getItem("user"),
        points: [],
        drawing: []
    },

    loginState:{
        login: "",
        password: "",
        error: false,
        formCorrect: false
    },

    registerState: {
        login: "",
        password: "",
        rPassword: "",
        loginError: false,
        passwordError: false,
        formCorrect: false
    },

    mainState: {
        xField: -3,
        yField: "",
        rField: 0.5,
        xChange: "",
        yChange: "",
        currentPoint: 0
    }
};

const store = createStore(reducers, initialState, middleware);

export default store;