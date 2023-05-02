canvas = document.getElementById("canvas");
ctx = canvas.getContext("2d");
let value_R = 0;
createSMTH()
let value_Y=0
addToTable()


function addToTable(){
    console.log("im in " + document.cookie)
    let output =""
    let input = Cookies.get("input_data");
    console.log(input + " input ")
    if(input !== undefined && input !== "") {
        let arr_data = input.split("/");
        for (let i = 0; i < arr_data.length - 1; i++) {
            let mass_value = arr_data[i].split(";");
            output += "<tr>"
            for (let j = 1; j < mass_value.length; j++) {
                output += "<td>"
                output += mass_value[j];
                output += "</td>"
            }
            output += "</tr>"
        }
        document.getElementById("rezTable").innerHTML=output
    }
    //document.getElementById("rezTable").innerHTML=output
    console.log(output + "output")
}

// function clearTable(){
//     Cookies
// }


function drawPoint(){

    let y=value_Y
    let r=value_R
    let x=document.getElementById("xParam").value.replace(/[,]/,".")

    if(x > 1.5*r || y > 1.5*r || x < -1.5 * r || y < -1.5 *r ){

    }else {
        createSMTH()
        ctx.fillStyle = "red";
        ctx.beginPath();
        ctx.moveTo(768, 390);
        ctx.arc(768 + 220 * x / r, 380 - 220 * y / r, 6, 0, 2 * Math.PI);
        ctx.fill();
        ctx.closePath()
    }
}

function createSMTH(){

    ctx.canvas.width  = window.innerWidth;
    ctx.canvas.height = window.innerHeight;
    // ctx.clearRect(0, 0, 1000, 1000);
    ctx.lineWidth = 5
    ctx.moveTo(768, 50); //высота 660 длина 660
    ctx.lineTo(768, 710);
    ctx.moveTo(438, 380);
    ctx.lineTo(1148, 380); //коорд плоскость

    ctx.moveTo(768,50);
    ctx.lineTo(790,80);
    ctx.moveTo(768,50);
    ctx.lineTo(746,80);
    ctx.moveTo(1148,380);
    ctx.lineTo(1118,358);
    ctx.moveTo(1148,380);
    ctx.lineTo(1118,402); //стрелочки


    ctx.font = "30px Arial";
    ctx.moveTo(790,160);
    ctx.lineTo(746,160);
    ctx.fillText(value_R, 800,170)
    ctx.moveTo(790,270);
    ctx.lineTo(746,270);
    ctx.fillText(value_R/2, 800,280)
    ctx.moveTo(790,490);
    ctx.lineTo(746,490);
    ctx.fillText(-value_R/2, 800,500)
    ctx.moveTo(790,600);
    ctx.lineTo(746,600);//верт отметины
    ctx.fillText(-value_R, 800,610)

    ctx.moveTo(548,358)
    ctx.lineTo(548,402);
    ctx.fillText(-value_R, 538,440)
    ctx.moveTo(658,358)
    ctx.lineTo(658,402);
    ctx.fillText(-value_R/2, 648,440)
    ctx.moveTo(878,358)
    ctx.lineTo(878,402);
    ctx.fillText(value_R/2, 868,440)
    ctx.moveTo(988,358)
    ctx.lineTo(988,402); //горизонт отметины
    ctx.fillText(value_R, 978,440)

    ctx.stroke();

    ctx.lineWidth = 2

    ctx.moveTo(825,65)
    ctx.lineTo(810,90)
    ctx.moveTo(807,65)
    ctx.lineTo(815,78) //Y

    ctx.moveTo(1160,415)
    ctx.lineTo(1145,440)
    ctx.moveTo(1145,415)
    ctx.lineTo(1160,440) //X

     // ctx.moveTo(768,490)
     // ctx.lineTo(658,380)
    ctx.stroke()
    ctx.fillStyle = "rgba(91,95,201,0.58)";

    ctx.lineWidth = 2

    ctx.strokeStyle = "rgba(91,95,201,0.54)"

    ctx.beginPath();
    // ctx.arc(769, 381, 110, 0.5*Math.PI, 0 , true); //сектор круга
    ctx.fillRect(768,380,110,-220) //прямоугольник
    // ctx.arc(769, 381, 110, 0.5*Math.PI, 0 , true); //сектор круга
    ctx.moveTo(768,380);//треугольник
    ctx.lineTo(658,380)
    ctx.lineTo(768,270)
    // ctx.moveTo(768,380)
    // ctx.lineTo(768,490)
    // ctx.lineTo(878,380)
    ctx.closePath()
    ctx.fill();

    ctx.beginPath();
    ctx.moveTo(768, 380);
    ctx.lineTo(768, 490);
    ctx.moveTo(768, 380);
    ctx.arc(768,380,110,0.5*Math.PI, 0,true);
    ctx.closePath()
    ctx.fill()

    ctx.stroke()

}
