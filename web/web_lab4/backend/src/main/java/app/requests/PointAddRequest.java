package app.requests;

import app.model.*;
import org.springframework.http.converter.HttpMessageNotReadableException;

import java.io.Serializable;

public class PointAddRequest implements Serializable {

    private double x;
    private double y;
    private double r;

    public Point createPoint(User user){

        Point point = new Point(r, user);
        point.getPointHistoryElements().add(new PointHistoryElement(point,x,y));
        return point;
    }

    public void check(){

        if(x<-5||x>5||y<-5||y>5||r<0||r>5){
            throw new HttpMessageNotReadableException("Out of range");
        }
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setR(double r) {
        this.r = r;
    }
}
