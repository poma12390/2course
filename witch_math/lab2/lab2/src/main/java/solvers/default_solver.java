package solvers;

public class default_solver {
    public static double find_y(double[] indexes, double x){
        double result=0;
        for (int i=0; i<indexes.length; i++){

            result+=indexes[i]*Math.pow(x, i);
        }
        return result;
    }
}
