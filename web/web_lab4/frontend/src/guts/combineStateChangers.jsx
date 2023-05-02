import {applyMiddleware} from "redux";
import loginStateChanger from "../loginPage/loginStateChanger";
import registerStateChanger from "../registerPage/registerStateChanger";
import mainStateChanger from "../mainPage/mainStateChanger";
export default applyMiddleware(loginStateChanger, registerStateChanger, mainStateChanger);