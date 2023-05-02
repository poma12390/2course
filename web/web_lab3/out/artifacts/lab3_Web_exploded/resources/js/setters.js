let checks=document.getElementsByClassName("form__x-btn")

new_r_value()
function new_r_value() {
    value_R = parseFloat(document.getElementById("r_value").innerText.split("=")[1])
    let z ="";

    if (value_R !== 0 && value_R !== "" && !isNaN(value_R)) {
        if ((""+value_R).length===1) {
            set_R_value("b" + value_R)
        } else {
            z = (""+value_R).split(".")
            set_R_value("b" + z[0] + "_" + z[1])
        }
    }else {
        value_R=0
        document.getElementById("r_value").innerText = "R = " + value_R
        document.getElementById("R_rez").setAttribute("value",value_R )
    }
}
function new_y_value(){
    value_Y=parseFloat(document.getElementById("y_value").innerText.split("=")[1])
    document.getElementById("Y_rez").setAttribute("value", value_Y )
    drawPoint()
}
function new_x_value() {
    //console.log(document.getElementById("y_value").innerText.split("=")[1]+ " log")
    value_X = parseFloat(document.getElementById("x_value").innerText.split("=")[1])
    document.getElementById("X_rez").setAttribute("value", value_X )
}

function reset_check_box(id){
    for (var i = 0; i < checks.length; i++) {

        if (checks[i].id!==id){
            console.log(checks[i].id + " ids " + id)
            checks[i].checked =false
        }
        checks[i].check = false


    }
}
// document.addEventListener('DOMContentLoaded', function () {
//     var url = window.location.pathname;
//     console.log(url)
//     if(url !== '/JavaEEHelloWorld_Web_exploded/  '){
//         window.location.replace("/JavaEEHelloWorld_Web_exploded/");
//     }
//     new_x_value()
//     new_y_value()
//     console.log(value_X, value_Y + " x, y ")
//
//     console.log(value_R + " R")
//     drawPoint()
// });


let prev_num=0
document.querySelector('#yParam').addEventListener('input', function (e) {
    let input = (e.target.value);
    if (isNaN(input) && input!=="-"){
        e.target.value=prev_num
    }else if(!e.target.value){
        prev_num=0
        document.getElementById("y_value").innerText = "Y = " + prev_num
    }else if((parseFloat(e.target.value)>5) || (parseFloat(e.target.value)<-3)){
        e.target.value=prev_num
    }else if((input==="-")){

    }
    else {
        prev_num=parseFloat(e.target.value)
        document.getElementById("y_value").innerText = "Y = " + prev_num
        new_y_value()

    }
});




function set_R_value(id){

    value_R=document.getElementById(id).getAttribute("value")
    document.getElementById("r_value").innerText = "R = " + value_R
    document.getElementById("R_rez").setAttribute("value",value_R )
    reset_check_box(id)
    drawPoint()


}

function set_X_value(id){
    id = document.getElementById(id)
    value_X = (id.getAttribute("value"))
    document.getElementById("X_rez").setAttribute("value",value_X )
    document.getElementById("x_value").innerText = "X = "+value_X
    drawPoint()
}
