package beans;


import database.ResultDao;
import lombok.Data;

import javax.inject.Inject;
import javax.annotation.PostConstruct;
import java.io.Serializable;
import java.util.List;
import java.util.Locale;

@Data
public class ResultBean implements Serializable {
    private static final double[] X_VALUES = {-2, -1.5, -1, -0.5, -0, 0.5, 1, 1.5, 2};
    private static final double MIN_Y = -3;
    private static final double MAX_Y = 3;

    @Inject
    private ResultDao resultDao;

    private Result currResult;

    private Float x;

        private Float y;

    private Float r;
    private List<Result> resultList;

    @PostConstruct
    private void initialize() {
        currResult = new Result();
        updateLocal();
    }

    private void updateLocal() {
        resultList = resultDao.getAll();
    }

    public void addResult() {
        Result copyResult = new Result(currResult);
        resultDao.save(copyResult);
        updateLocal();
    }

    public void clearResults() {
        resultDao.clear();
        resultList = resultDao.getAll();
        updateLocal();
    }
}
