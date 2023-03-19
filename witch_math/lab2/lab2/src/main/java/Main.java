import parsers.*;
import solvers.*;

public class Main {
    public static void main(String[] args) {
        //−1.8x^3-2.94x^2+10.37x+5.38
        String func="-1.8x^3-2.94x^2+10.37x+5.38";
        double[] x = function_parser.find_index(func);
        System.out.println(default_solver.find_y(x, 1));
    }
}