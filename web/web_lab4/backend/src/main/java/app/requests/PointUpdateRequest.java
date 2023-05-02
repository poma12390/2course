package app.requests;

import org.springframework.http.converter.HttpMessageNotReadableException;

public class PointUpdateRequest {

    private double x;
    private double y;
    private int id;

    public void check(){
        if(x<-5||x>5 ||y<-5||y>5){
            throw new HttpMessageNotReadableException("Out of range");
        }
    }

    public int getId() {
        return id;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setId(int id) {
        this.id = id;
    }
}