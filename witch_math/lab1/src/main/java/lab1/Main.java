package lab1;

import java.util.Arrays;
import java.util.Scanner;



public class Main {
    static float[][] array;

    static Scanner sc;
    static int array_size;
    static int number;
    private static void print_array(){
        for (int i = 0; i < array_size; i++){
            for (int j = 0; j < array_size+1; j++){
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void input_array(){
        array = new float[array_size][array_size + 1];
        for (int i = 0; i < array_size; i++)
            for (int j = 0; j < array_size+1; j++)
                array[i][j] = sc.nextInt();
    }

    public static void main(String[] args) {
        sc=new Scanner(System.in);
        array_size = 3;
        float accuracy=0.001f;
        //input_array();
        array= new float[][]{{5, -1, 3, 5}, {1, -4, 2, 20}, {2, -1, 5, 10}};
        print_array();

        Utils ut=new Utils(array_size);
        ut.change_column(array);
        ut.first_approx(array);
        while(accuracy<ut.cur_accuracy){
            ut.approximation(array, array_size);
            System.out.println(ut.cur_accuracy);
        }

        print_array();
    }
}