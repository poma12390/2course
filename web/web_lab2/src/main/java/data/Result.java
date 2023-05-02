package data;

public class Result {
    private  double x;
    private  double y;
    private  double r;

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setR(double r) {
        this.r = r;
    }

    private final String currTime;
    private double executionTime;
    private final boolean hit;

    public Result(double x, double y, double r, String currTime, double executionTime, boolean hit) {
        this.x = x;
        this.y = y;
        this.r = r;
        this.currTime = currTime;
        this.executionTime = executionTime;
        this.hit = hit;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double getR() {
        return r;
    }

    public String getCurrTime() {
        return currTime;
    }

    public double getExecutionTime() {
        return executionTime;
    }

    public void setExecutionTime(double executionTime) {
        this.executionTime = executionTime;
    }

    public boolean getHit() {
        return hit;
    }
}
