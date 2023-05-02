import React from "react";
import {withRouter} from "react-router-dom";
import MainContainer from "./MainContainer";
const MainPage = withRouter((props)=>{
    return(<MainContainer history={props.history} store={props.store}/>)
});

export default MainPage;
