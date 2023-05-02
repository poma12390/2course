import React from "react";
import {connect} from "react-redux";

class InputXForm extends React.Component{
    render() {
        return(
            <table className="input-table">
                <tr>
                    <td>
                        <input type="checkbox" value="-5" name="x" id="x_-5"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === -5} />
                        <label htmlFor="x_-5">-5</label>
                    </td>
                    <td>
                        <input type="checkbox" value="-4" name="x" id="x_-4"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === -4} />
                        <label htmlFor="x_-4">-4</label>
                    </td>
                    <td>
                        <input type="checkbox" value="-3" name="x" id="x_-3"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === -3} />
                        <label htmlFor="x_-3">-3</label>
                    </td>

                </tr>
                <tr>
                    <td>
                        <input type="checkbox" value="-2" name="x" id="x_-2"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === -2} />
                        <label htmlFor="x_-2">-2</label>
                    </td>
                    <td>
                        <input type="checkbox" value="-1" name="x" id="x_-1"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === -1} />
                        <label htmlFor="x_-1">-1</label>
                    </td>
                    <td>
                        <input type="checkbox" value="0" name="x" id="x_0"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === 0} />
                        <label htmlFor="x_0">0</label>
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="checkbox" value="1" name="x" id="x_1"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === 1} />
                        <label htmlFor="x_1">1</label>
                    </td>
                    <td>
                        <input type="checkbox" value="2" name="x" id="x_2"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === 2} />
                        <label htmlFor="x_2">2</label>
                    </td>
                    <td>
                        <input type="checkbox" value="3" name="x" id="x_3"
                               onChange={(e) => this.props.dispatch({type:"MAIN_SET_X",value: e.target.value})}
                               checked={this.props.x === 3} />
                        <label htmlFor="x_3">3</label>
                    </td>
                </tr>
            </table>
        )
    }
}

const mapStateToProps = function(store) {
    return {
        x: store.mainState.xField,
    }
};

export default connect(mapStateToProps)(InputXForm)
