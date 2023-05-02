display_ct()
function display_c(){
    console.log("timer")
    var refresh=13000;
    mytime=setTimeout('display_ct()',refresh)
}

function display_ct() {
    var x = new Date()
    var x1=x.toUTCString();// changing the display to UTC string
    document.getElementById('time').innerHTML = x1;
    tt=display_c();
}