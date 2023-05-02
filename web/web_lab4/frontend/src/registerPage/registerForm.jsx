import React from "react";
import {connect} from "react-redux";

class RegisterForm extends React.Component{
    render() {
        return(
            <main className="container">
                <div className="registration-window">
                    <div className="registration">
                        <h2 className="welcome">Регистрация</h2>
                        <label className="input-group">Имя пользователя
                            <input className="login-input" type="text" value={this.props.login}
                                   onChange={event => this.props.dispatch({
                                       type: "REGISTER_SET_LOGIN",
                                       value: event.target.value.replace(" ", "")})}/>
                            <div className={!this.props.loginError? 'hidden' : 'warn'}>
                                <span className="error">Пользователь с таким именем уже существует</span>
                            </div>
                        </label>
                        <label className="input-group">Пароль
                            <input className="login-input" type="password" value={this.props.password}
                                   onChange={event => this.props.dispatch({
                                       type:"REGISTER_SET_PASSWORD",
                                       value: event.target.value})}/>
                        </label>
                        <label className="input-group">Повторите пароль
                            <input className="login-input" type="password" value={this.props.rPassword}
                                   onChange={event => this.props.dispatch({
                                       type:"REGISTER_SET_R_PASSWORD",
                                       value: event.target.value})}/>
                        </label>
                        <div className={!this.props.passwordError? 'hidden' : 'warn'}>
                            <span className="error">Пароли не совпадают</span>
                        </div>
                        <button className="login-button" onClick={this.register} disabled={!this.props.formCorrect}>Зарегестрироваться</button>
                        <button className="login-button register" onClick={this.redirectToLogin}>Назад</button>
                    </div>
                </div>
            </main>
        )
    }
    redirectToLogin = () =>{this.props.history.push("/authorisation")};
    register = () =>{
       this.props.dispatch({type: "APP_REGISTER", value:{history: this.props.history}})
    };
}

const mapStateToProps = function(store) {
    return {
        user: store.appState.user,
        login: store.registerState.login,
        password: store.registerState.password,
        rPassword: store.registerState.rPassword,
        passwordError: store.registerState.passwordError,
        loginError: store.registerState.loginError,
        formCorrect: store.registerState.formCorrect
    }
};

export default connect(mapStateToProps)(RegisterForm);