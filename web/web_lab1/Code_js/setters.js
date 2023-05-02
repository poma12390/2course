function set_R_value(id){
    value_R=document.getElementById(id).getAttribute("value")
    document.getElementById("r_value").innerText = "R = " + value_R
    createSMTH()
}

function set_Y_value(id){
    id = document.getElementById(id)
    value_Y = (id.getAttribute("value"))
    document.getElementById("x_value").innerText = "Y = "+value_Y
}