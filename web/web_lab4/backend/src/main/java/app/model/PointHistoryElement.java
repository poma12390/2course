package app.model;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

import javax.persistence.*;
import java.util.Date;

@Entity
@Table(name= "s_point_history")
@JsonIgnoreProperties({"hibernateLazyInitializer", "handler"})
public class PointHistoryElement {

    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    @Column(name = "id", nullable = false)
    private int id;
    @Column(name = "timestamp", nullable = false)
    private long date;
    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "point_id", nullable = false)
    private Point point;
    @Column(name = "x", nullable = false)
    private Double x;
    @Column(name = "y", nullable = false)
    private Double y;
    @Column(name = "ch", nullable = false)
    private boolean isCheck;

    public PointHistoryElement(){}

    public PointHistoryElement(Point point, double x, double y){
        this.point = point;
        this.x = x;
        this.y = y;
        double r = point.getR();
        this.isCheck = (x<=0 && y>=0 && y<=r && x>=-r/2) || (x>=0 && y<=0 && x*x+y*y<=r*r/4) || (x>=0 && y>=0 && (x+2*y)<r);
        this.date = new Date().getTime();
    }

    public int getId() {
        return id;
    }

    public long getDate() {
        return date;
    }

    public Double getX() {
        return x;
    }

    public Double getY() {
        return y;
    }

    public boolean getIsCheck() {
        return isCheck;
    }
}
