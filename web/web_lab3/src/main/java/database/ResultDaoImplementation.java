package database;

import beans.Result;
import utils.HibernateSessionFactoryUtil;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.*;
import javax.enterprise.inject.Default;

@Default
public class ResultDaoImplementation implements ResultDao {
    private final EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("ResultUnit");
    private final EntityManager entityManager = entityManagerFactory.createEntityManager();

    @Override
    public void save(Result result) {

        EntityTransaction transaction = entityManager.getTransaction();

        try {
            transaction.begin();
            entityManager.persist(result);
            transaction.commit();
        } catch (Exception e) {
            transaction.rollback();
        }
    }

    @Override
    public boolean clear() {
        EntityTransaction transaction = entityManager.getTransaction();

        try {
            transaction.begin();
            entityManager.createQuery("delete from Result").executeUpdate();
            transaction.commit();
            return true;
        } catch (Exception e) {
            transaction.rollback();
            return false;
        }
    }

    @Override
    public List<Result> getAll() {
        EntityTransaction transaction = entityManager.getTransaction();
        List<Result> list;
        transaction.begin();
        list = entityManager.createQuery("select result from Result result ORDER BY id", Result.class).getResultList();
        transaction.commit();

        return list;
    }


}
