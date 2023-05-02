
function chek_input(){
    let input = document.getElementById("xParam");
    if(!/^-?\d+(\.|,)?\d*$/i.test(input.value)){
        alert("Значение \"X\" не валидно");
        input.value = "";
        flag = false;
    }else if(input.value.replace(/[,]/,".") >= -3 && input.value.replace(/[,]/,".") <= 5){
        if(/(\.|,)$/i.test(input.value)){
            alert("Значение \"X\" не валидно");
            input.value = "";
            flag = false;
        }else{
            value_X = input.value.replace(/[,]/,".");
            document.getElementById('y_value').innerText = "X = " + input.value;
            flag = true;
            drawPoint()
        }
    }else if(/(\.|,)$/i.test(input.value)) {
        alert("Значение \"X\" не валидно");
        input.value = "";
        flag = false;
    }else{
        alert("Выход за пределы, введите число в интервале [-3;5]");
        flag = false;
    }
}
let cookies_data="";
function getData(){
    const xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState === XMLHttpRequest.DONE) {
            if(Cookies.get('input_data') !== undefined) {
                cookies_data = Cookies.get('input_data');
            }
            cookies_data += php_response(xhr.responseText);
            console.log(cookies_data + " data")
            Cookies.set("input_data", cookies_data);
            addToTable();
        }
    }
    xhr.open('GET', 'server_checking.php?'+'x='+value_Y+'&y='+value_X+'&r='+value_R);
    xhr.send();
}

function php_response(param) {
    console.log(param + " param")
    if(param.split("/")[0].split(";")[0] == ""){
        alert("Ошибка в отправленных данных");
    }else{
        console.log(param + " php response ")
        drawPoint() ;
        return param;
    }
}

let button = document.getElementById("input");
button.onclick = function() {
    chek_input();
    if(flag) {
        getData()
    }
}