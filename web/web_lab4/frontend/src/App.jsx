import React from 'react';
import {Switch, Route} from "react-router-dom";
import loginPage from "./loginPage/loginPage";
import registerPage from "./registerPage/registerPage";
import mainPage from "./mainPage/mainPage";
import "./css/common.css"
import "./css/header.css"
import "./css/form.css"


class App extends React.Component{
    render() {
        return (
            <div className="App">
                <Header />
                <Switch>
                    <Switch>
                        <Route exact path="/authorisation" component={loginPage}/>
                        <Route exact path="/registration" component={registerPage}/>
                        <Route path="/" component={mainPage}/>
                    </Switch>
                </Switch>
            </div>
        );
    }
}

const Header = ()=>{
    return(
        <header className="header">
            <div className="title-container">
                <h2 className="pointify-title">Лабораторная работа №4 - Вариант 345</h2>
                <h3 className="pointify-author">
                    Created by-
                    <a className="author" href="https://github.com/poma12390"
                       target="_blank" rel="noopener noreferrer">
                       Кочнев Роман</a>
                </h3>
            </div>
        </header>
    )
};
export default App;