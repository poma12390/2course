package app.repository;

import app.model.PointHistoryElement;

import org.springframework.data.jpa.repository.JpaRepository;

public interface PointHistoryElementRepository extends JpaRepository<PointHistoryElement, Integer> {

}
