package app.service;

import app.model.*;
import app.repository.PointHistoryElementRepository;
import app.repository.PointRepository;
import org.springframework.stereotype.Service;

import java.util.LinkedHashSet;
import java.util.Set;

@Service
public class DataService {

    private final PointRepository pointRepository;

    private final PointHistoryElementRepository elementRepository;

    public DataService(PointRepository repository, PointHistoryElementRepository elementRepository){
        this.pointRepository = repository;
        this.elementRepository = elementRepository;
    }

    public void addPoint(Point p){
        pointRepository.save(p);
        elementRepository.save((PointHistoryElement) p.getPointHistoryElements().toArray()[0]);
    }

    public Set<Point> updatePoint(int id, User user, double x, double y){

        Set<Point> points = user.getPoints();
        for (Point point : points){
            if(point.getId()==id){
                PointHistoryElement element = new PointHistoryElement(point,x,y);
                point.getPointHistoryElements().add(element);
                elementRepository.save(element);
                return points;
            }
        }
        return null;
    }

    public Set<Point> deletePoint(int id, User user){
        Set<Point> points = user.getPoints();
        for (Point point : points){
            if(point.getId()==id){
                Set<Point> set = new LinkedHashSet<>(points);
                set.remove(point);
                pointRepository.delete(point);
                return set;
            }
        }
        return null;
    }
}
