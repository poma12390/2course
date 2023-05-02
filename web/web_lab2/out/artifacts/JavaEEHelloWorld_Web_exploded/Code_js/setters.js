new_r_value()
function new_r_value() {
    value_R = parseFloat(document.getElementById("r_value").innerText.split("=")[1])
    let z ="";
    if (value_R !== 0 && value_R !== "") {

        if ((""+value_R).length===1) {
            set_R_value("b" + value_R)
        } else {
            console.log(""+value_R)
            z = (""+value_R).split(".")
            set_R_value("b" + z[0] + "_" + z[1])
        }
    }
}
function new_y_value(){
    value_Y=parseFloat(document.getElementById("x_value").innerText.split("=")[1])
}
function new_x_value() {
    console.log(document.getElementById("y_value").innerText.split("=")[1]+ " log")
    value_X = parseFloat(document.getElementById("y_value").innerText.split("=")[1])
    document.getElementById("X_rez").setAttribute("value", value_X )
}
document.addEventListener('DOMContentLoaded', function () {
    new_x_value()
    new_y_value()
    console.log(value_X, value_Y + " x, y ")

    console.log(value_R + " R")
    drawPoint()
});

let prev_num=0
document.querySelector('#xParam').addEventListener('input', function (e) {
    let input = (e.target.value);
    if (isNaN(input) && input!=="-"){
        e.target.value=prev_num
    }else if(!e.target.value){
        prev_num=0
        document.getElementById("y_value").innerText = "X = " + prev_num
    }else if((parseFloat(e.target.value)>5) || (parseFloat(e.target.value)<-3)){
        e.target.value=prev_num
    }else if((input==="-")){

    }
    else {
        prev_num=parseFloat(e.target.value)
        document.getElementById("y_value").innerText = "X = " + prev_num
        new_x_value()
    }
});




function set_R_value(id){
    value_R=document.getElementById(id).getAttribute("value")
    document.getElementById("r_value").innerText = "R = " + value_R
    document.getElementById("R_rez").setAttribute("value",value_R )
    drawPoint()
}

function set_Y_value(id){
    id = document.getElementById(id)
    value_Y = (id.getAttribute("value"))
    document.getElementById("Y_rez").setAttribute("value",value_Y )
    document.getElementById("x_value").innerText = "Y = "+value_Y
}
