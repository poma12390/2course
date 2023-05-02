package app.model;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

import javax.persistence.*;
import java.util.*;

@Entity
@Table(name="s_points")
@JsonIgnoreProperties({"hibernateLazyInitializer", "handler"})
public class Point {

    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    @Column(name = "id", nullable = false)
    private int id;
    @Column(name = "timestamp", nullable = false)
    private long date;
    @Column(name = "r", nullable = false)
    private Double r;
    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "owner", nullable = false)
    private User owner;
    @OneToMany(fetch = FetchType.EAGER, mappedBy = "point", cascade = CascadeType.ALL)
    private Set<PointHistoryElement> pointHistoryElements;

    public Point(Double r, User owner){
        this.pointHistoryElements = new LinkedHashSet<>();
        this.r = r;
        this.date = new Date().getTime();
        this.owner = owner;
    }

    public Point(){}

    public double getR() {
        return r;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public long getDate() {
        return date;
    }

    public void setDate(long date) {
        this.date = date;
    }

    public void setR(Double r) {
        this.r = r;
    }

    public User getOwner() {
        return owner;
    }

    public void setOwner(User owner) {
        this.owner = owner;
    }

    public Set<PointHistoryElement> getPointHistoryElements() {
        return pointHistoryElements;
    }

    public void setPointHistoryElements(Set<PointHistoryElement> pointHistoryElements) {
        this.pointHistoryElements = pointHistoryElements;
    }
}