import React from "react";
import {withRouter} from "react-router-dom";
import LoginForm from "./LoginForm";

const LoginPage = withRouter((props)=>{
    return(<LoginForm history={props.history}/>)
});

export default LoginPage;
