package lab1;

import java.util.Arrays;

public class Utils {
    float[] cur_x;

    float cur_accuracy=0;

    public Utils(int size) {
        cur_x= new float[size];
        cur_accuracy=1;
    }

    public void approximation(float[][] matrix, int array_size){
        float k;
        cur_accuracy=0;
        for (int i=0; i<array_size; i++){
            k=cur_x[i];
            cur_x[i]=0;
            for (int j=0; j<array_size; j++){
                if (i==j){
                    cur_x[i]+=matrix[i][j]/matrix[i][array_size];
                }else{
                    cur_x[i]+=matrix[i][j]*cur_x[j]/matrix[i][array_size];
                }
            }
            cur_accuracy = Math.max(cur_accuracy, (Math.min(k, cur_x[i])/Math.max(k, cur_x[i]))-1);
        }

        System.out.println(Arrays.toString(cur_x));
    }

    public void first_approx(float[][] matrix){
        for (int i=0; i< Main.array_size; i++){
            cur_x[i]=matrix[i][i]/matrix[i][Main.array_size];
        }
        System.out.println(Arrays.toString(cur_x));
    }

    public void change_column(float[][] matrix){
        float k;
        for (int i=0; i< Main.array_size; i++){
            k=-1*matrix[i][i];
            matrix[i][i]=-1*matrix[i][Main.array_size];
            matrix[i][Main.array_size]=k;
        }

    }


}
