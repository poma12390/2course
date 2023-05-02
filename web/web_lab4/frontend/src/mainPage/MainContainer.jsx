import React from "react";
import {connect} from "react-redux";
import InputXForm from "./inputXForm";
import InputRForm from "./inputRForm";
import Canvas from "./canvas";
import ResultTable from "./resultTable";
import "../css/Main_styles.css"
import "../css/reg_login.css"

class MainContainer extends React.Component{
    constructor(props){
        super(props);
        if(this.props.user===null) this.props.history.push("/login");
        else this.props.dispatch({type: "APP_GET_POINTS", value:{history: this.props.history}})
    }

    render() {
        return(
            <div className="main">
                <h2>Добро пожаловать, {this.props.user}</h2>
                <h1>Определение попадания точки в область</h1>
                <Canvas/>
                <h2>Координата X</h2>
                <InputXForm/>
                <h2>Координата Y</h2>
                <div>
                    <input className="y" type="text" value={this.props.y} placeholder="от -3 до 3" onChange={event => this.props.dispatch({
                        type: "MAIN_SET_Y",
                        value: event.target.value.replace(",",".")})}/>
                </div>
                <h2>Радиус</h2>
                <InputRForm/>
                <button className="submit-button" onClick={()=>this.props.dispatch({
                    type: "MAIN_ADD_POINT",
                    value:{x: this.props.x, y:this.props.y, r:this.props.r}
                })} disabled={this.props.y===""||this.props.y==="-"||this.props.y==="."}>Проверить</button>
                <button className="submit-button" onClick={this.exit}>Выйти</button><br/>
                <ResultTable/>
            </div>
        )
    }

    exit = ()=>{
        this.props.dispatch({type: "APP_LOGOUT", value: {history: this.props.history}});
    }
}

const mapStateToProps = function(store) {
    return {
        user: store.appState.user,
        x: store.mainState.xField,
        y: store.mainState.yField,
        r: store.mainState.rField,
    }
};

export default connect(mapStateToProps)(MainContainer);