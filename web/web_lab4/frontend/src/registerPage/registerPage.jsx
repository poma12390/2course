import React from "react";
import {withRouter} from "react-router-dom";
import RegisterForm from "./registerForm";

const RegisterPage = withRouter(({history})=>{
    return(<RegisterForm history={history}/>)
});

export default RegisterPage;
