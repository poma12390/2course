import React from "react";
import {connect} from "react-redux";

class Canvas extends React.Component{
    render() {
        return(
            <div className="canvas-div">
                <canvas ref="canvas" height="450px" width="450px" onClick={(event => this.handleClick(event))}/>
            </div>
        )
    }

    componentDidMount() {
        this.canvas = this.refs.canvas;
        this.i = 40;
        this.updateCanvas();
    }

    componentDidUpdate(prevProps, prevState, snapshot) {
        this.updateCanvas();
    }

    updateCanvas(){
        this.clear(this.canvas);
        this.drawArea(this.props.r, this.i, this.canvas);
        this.drawAxis(this.i, this.canvas);
        for (let point of this.props.points){
            this.drawPoint(point.x, point.y, point.ch?'lime':'red', this.i, this.canvas)
        }
    }

    drawAxis(i, canvas) {
        const ctx = canvas.getContext('2d');
        let h = canvas.height;
        let w = canvas.width;
        ctx.strokeStyle = "black";
        ctx.lineWidth = 2;
        ctx.beginPath();
        ctx.moveTo(w/2, h);
        ctx.lineTo(w/2, 0);
        ctx.lineTo(w/2+3, 7);
        ctx.moveTo(w/2, 0);
        ctx.lineTo(w/2-3, 7);
        this.drawDigitsX(ctx, i, w, h);
        ctx.stroke();
        ctx.beginPath();
        ctx.moveTo(0, h/2);
        ctx.lineTo(w, h/2);
        ctx.lineTo(w-7, h/2+3);
        ctx.moveTo(w, h/2);
        ctx.lineTo(w-7, h/2-3);
        this.drawDigitsY(ctx, i, w, h);
        ctx.stroke();
    }

    drawDigitsX(ctx, i, w, h) {
        let t=w/2;
        for (let j=0; j<5; j++){
            t+=i;
            ctx.moveTo(t, h/2+3);
            ctx.lineTo(t, h/2-3)
        }
        t=w/2;
        for (let j=0; j<5; j++){
            t-=i;
            ctx.moveTo(t, h/2+3);
            ctx.lineTo(t, h/2-3)
        }
    }

    drawDigitsY(ctx, i, w, h) {
        let t=h/2;
        for (let j=0; j<5; j++){
            t+=i;
            ctx.moveTo(w/2+3, t);
            ctx.lineTo(w/2-3, t);
        }
        t=h/2;
        for (let j=0; j<5; j++){
            t-=i;
            ctx.moveTo(w/2+3, t);
            ctx.lineTo(w/2-3, t);
        }
    }

    drawArea(r, i, canvas) {
        const ctx = canvas.getContext('2d');
        let h = canvas.height;
        let w = canvas.width;
        ctx.strokeStyle = "#2f9aff";
        ctx.fillStyle = "#2f9aff";
        ctx.beginPath();
        ctx.arc(w/2,h/2,r*i/2,0,Math.PI/2,false);
         ctx.moveTo(w/2, h/2);
         ctx.lineTo(w/2+r*i, h/2);
         ctx.lineTo(w/2, h/2-r*i/2);
        ctx.rect(w/2, h/2, -r*i/2, -r*i);
        ctx.moveTo(w/2, h/2);
        ctx.lineTo(w/2, h/2+r*i/2);
        ctx.lineTo(w/2+r*i/2, h/2);
        ctx.fill();
    }

    clear(canvas){
        canvas.getContext('2d').clearRect(0, 0, canvas.width, canvas.height);
    }

    handleClick(event){
        let obj = event.target;
        let x = Number(((event.pageX - window.pageXOffset - obj.getBoundingClientRect().x - obj.width/2)/this.i).toFixed(2));
        let y = Number((-(event.pageY - window.pageYOffset - obj.getBoundingClientRect().y - obj.height/2)/this.i).toFixed(2));
        if(!(x<-5||x>5||y<-5||y>5)){
            this.props.dispatch({type: "MAIN_ADD_POINT", value:{x:x,y:y,r:this.props.r}})
        }
    }

    drawPoint(x, y, color, i, canvas) {
        let ctx = canvas.getContext('2d');
        ctx.fillStyle = color;
        ctx.beginPath();
        ctx.arc(canvas.width/2+x*i,canvas.height/2-y*i,2,0,Math.PI*2, true);
        ctx.fill();
    }
}

const mapStateToProps = function(store) {
    return {
        points: store.appState.drawing,
        r: store.mainState.rField,
    }
};


export default connect(mapStateToProps)(Canvas);
