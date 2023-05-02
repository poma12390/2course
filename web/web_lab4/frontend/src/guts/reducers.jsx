import {combineReducers} from "redux";

const appReducer = (state = {}, action) => {

    switch (action.type) {

        case("APP_LOGIN_SUCCESS"): {
            return Object.assign({}, state, {user: action.value});
        }
        case("APP_LOGOUT"): {
            return Object.assign({}, state, {user: null});
        }
        case("APP_UPDATE_POINTS_SUCCESS"): {
            return Object.assign({}, state, {points: action.value});
        }
        case("APP_UPDATE_DRAWING_SUCCESS"): {
            return Object.assign({}, state, {drawing: action.value});
        }
        default:
            return state;
    }
};

const loginReducer = (state = {}, action) => {

    switch (action.type) {

        case("LOGIN_SET_LOGIN"): {
            return Object.assign({}, state, {
                login: action.value,
                formCorrect: action.value.length > 0 && state.password.length > 0
            });
        }
        case("LOGIN_SET_PASSWORD"): {
            return Object.assign({}, state, {
                password: action.value,
                formCorrect: action.value.length > 0 && state.login.length > 0
            });
        }
        case("LOGIN_SET_ERROR"): {
            return Object.assign({}, state, {error: action.value});
        }
        case("APP_LOGIN_SUCCESS"): {
            return Object.assign({}, state, {error: false, login: "", password: "", formCorrect: false});
        }
        default:
            return state;
    }
};

const registerReducer = (state = {}, action) => {

    switch (action.type) {

        case("REGISTER_SET_LOGIN"): {
            return Object.assign({}, state, {
                login: action.value,
                formCorrect: action.value.length > 0 && state.password.length > 0 && state.rPassword.length > 0
            });
        }
        case("REGISTER_SET_PASSWORD"): {
            return Object.assign({}, state, {
                password: action.value,
                formCorrect: action.value.length > 0 && state.login.length > 0 && state.rPassword.length > 0
            });
        }
        case("REGISTER_SET_R_PASSWORD"): {
            return Object.assign({}, state, {
                rPassword: action.value,
                formCorrect: action.value.length > 0 && state.login.length > 0 && state.password.length > 0
            });
        }
        case("REGISTER_SET_LOGIN_ERROR"): {
            return Object.assign({}, state, {loginError: action.value});
        }
        case("REGISTER_SET_PASSWORD_ERROR"): {
            return Object.assign({}, state, {passwordError: action.value});
        }
        case("APP_REGISTER_SUCCESS"): {
            return {login: "", password: "", rPassword: "", loginError: false, passwordError: false, formCorrect: false}
        }
        default:
            return state;
    }
};

const mainReducer = (state = {}, action) => {

    switch (action.type) {

        case "MAIN_SET_X": {
            return Object.assign({}, state, {xField: Number(action.value)});
        }
        case "MAIN_SET_Y": {
            if ((Number(action.value) || (Number(action.value) === 0 && action.value !== ""))
                && !action.value.match(/^-*[0-9]*\.$/) && Number(action.value) >= -3 && Number(action.value) <= 3) {
                return Object.assign({}, state, {yField: Number(action.value)});
            }
            if (action.value === "-" || action.value === "" || action.value === "." ||
                (action.value.match(/^-*[0-9]*\.$/) && Number(action.value) >= -3 && Number(action.value) <= 3)) {
                return Object.assign({}, state, {yField: action.value});
            }
            return state;
        }
        case "MAIN_SET_R": {
            return Object.assign({}, state, {rField: Number(action.value)});
        }
        case "APP_LOGOUT": {
            return {xField: -3, yField: "", rField: 0.5}
        }
        case "MAIN_SET_CHANGE_X": {
            if ((Number(action.value) || (Number(action.value) === 0 && action.value !== ""))
                && !action.value.match(/^-*[0-9]*\.$/) && Number(action.value) >= -3 && Number(action.value) <= 5) {
                return Object.assign({}, state, {xChange: Number(action.value)});
            }
            if (action.value === "-" || action.value === "" || action.value === "." ||
                (action.value.match(/^-*[0-9]*\.$/) && Number(action.value) >= -3 && Number(action.value) <= 5)) {
                return Object.assign({}, state, {xChange: action.value});
            }
            return state;
        }
        case "MAIN_SET_CHANGE_Y": {
            if ((Number(action.value) || (Number(action.value) === 0 && action.value !== ""))
                && !action.value.match(/^-*[0-9]*\.$/) && Number(action.value) >= -3 && Number(action.value) <= 3) {
                return Object.assign({}, state, {yChange: Number(action.value)});
            }
            if (action.value === "-" || action.value === "" || action.value === "." ||
                (action.value.match(/^-*[0-9]*\.$/) && Number(action.value) >= -3 && Number(action.value) <= 3)) {
                return Object.assign({}, state, {yChange: action.value});
            }
            return state;
        }
        case "MAIN_SET_CURRENT_POINT": {
            return Object.assign({}, state, {currentPoint: Number(action.value.id)});
        }
        default: {
            return state;
        }
    }
};

export default combineReducers({
    appState: appReducer,
    loginState: loginReducer,
    registerState: registerReducer,
    mainState: mainReducer
})