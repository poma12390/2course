import React from "react";
import {connect} from "react-redux";

class LoginForm extends React.Component{
    render() {
        return(
            <main className="container">
                <div className="login-window">
                    <div className="login">
                        <h2 className="welcome">Добро пожаловать</h2>
                        <label className="input-group">Имя пользователя
                            <span className="lighting"></span>
                            <input className="login-input" type="text" value={this.props.login}
                                   onChange={event => this.props.dispatch({
                                       type: "LOGIN_SET_LOGIN",
                                       value: event.target.value.replace(" ", "")})}/>
                        </label>
                        <label className="input-group">Пароль
                            <span className="lighting"></span>

                            <input className="login-input" type="password" value={this.props.password}
                                   onChange={event => this.props.dispatch({
                                       type: "LOGIN_SET_PASSWORD",
                                       value: event.target.value})}/>
                        </label>
                        <button className="login-button"  disabled={!this.props.formCorrect}
                                onClick={this.sendLoginRequest}>Войти</button>
                    </div>
                    <div className="registration-suggest">
                        <h4 className="question-text">Регистрация</h4>
                        <div className={!this.props.error? 'hidden' : 'warn'}>
                            <span className="error">Неверное имя пользователя или пароль</span>
                        </div>
                        <button className="login-button" onClick={this.redirectToRegister}>Зарегистрироваться</button>
                    </div>
                </div>
            </main>
        )
    }

    sendLoginRequest = () =>{
        this.props.dispatch({type:"APP_LOGIN", value:{history: this.props.history}})
    };

    redirectToRegister = () =>{this.props.history.push("/registration")};
}

const mapStateToProps = function(store) {
    return {
        user: store.appState.user,
        login: store.loginState.login,
        password: store.loginState.password,
        error: store.loginState.error,
        formCorrect: store.loginState.formCorrect
    }
};

export default connect(mapStateToProps)(LoginForm)