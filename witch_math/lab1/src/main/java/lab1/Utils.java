package lab1;

import java.util.TreeMap;

public class Utils {
    private final float[] cur_x;

    private final float[] xAccuracy;

    private int n=0;

    float cur_accuracy=0;

    public Utils(int size) {
        cur_x= new float[size];
        xAccuracy= new float[size];
        cur_accuracy=1;
    }

    public void printResult(){
        System.out.println(n + " Итерация");
        System.out.print("Вектора неизвестных ");
        for (int i=0; i<cur_x.length; i++) {
            System.out.printf("x%d(%d)=%5.4f ", i+1, n, cur_x[i]);
        }

        if(n!=0) {System.out.println(); System.out.print("Вектора погрешностей ");}
        for (int i=0; i<xAccuracy.length; i++) {
            if(n==0) break;
            System.out.printf("|x%d(%d)-x%d(%d)|=%5.4f ", i+1, n, i+1, n-1, xAccuracy[i]);
        }
        System.out.println();
        System.out.printf("Точность %5.4f%n", cur_accuracy);

    }

    void approximation(float[][] matrix, int array_size){
        n+=1;
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
            xAccuracy[i]=Math.abs(k-cur_x[i]);
            cur_accuracy = Math.max(cur_accuracy, ((Math.max(Math.abs(k), Math.abs(cur_x[i]))/Math.min(Math.abs(k), Math.abs(cur_x[i])))-1));
        }


    }

    void first_approx(float[][] matrix){
        for (int i=0; i< Main.array_size; i++){
            cur_x[i]=matrix[i][i]/matrix[i][Main.array_size];
        }
        printResult();
    }

    private void change_strings(float[][] matrix, int a, int b){
        float k;
        for (int i=0; i< Main.array_size; i++){
            k=matrix[a][i];
            matrix[a][i]=matrix[b][i];
            matrix[b][i]=k;

        }
    }

    void refactor(float[][] matrix){
        change_column(matrix);
        first_approx(matrix);
    }

    void change_column(float[][] matrix){
        float k;
        for (int i=0; i< Main.array_size; i++){
            k=-1*matrix[i][i];
            matrix[i][i]=-1*matrix[i][Main.array_size];
            matrix[i][Main.array_size]=k;
        }

    }
    public boolean check_diagonal(float[][] matrix){
        TreeMap<Integer, Integer> treeMap = new TreeMap<>();
        boolean isStrict=false;
        for(int i=0; i<Main.array_size; i++){
            for(int j=0; j<Main.array_size; j++){
                int k=check_dominance(matrix, i, j);
                if (k>=0){
                    treeMap.put(j, i);
                    if(k==1){
                        isStrict=true;
                    }
                    break;
                }
            }
        }

        if(treeMap.size()!=Main.array_size || !isStrict){
            return false;
        }
        float[][] oldMatrix = new float[Main.array_size][Main.array_size+1];
        for(int i=0; i<Main.array_size; i++){
            if (Main.array_size + 1 >= 0) System.arraycopy(matrix[i], 0, oldMatrix[i], 0, Main.array_size + 1);
        }
        for (Integer newRow:treeMap.keySet()){
            int oldRow = treeMap.get(newRow);
            for(int j=0; j<Main.array_size+1; j++){
                matrix[newRow][j]=oldMatrix[oldRow][j];
            }
        }

        return true;
    }

    private int  check_dominance(float[][] matrix, int row, int column){
        float element=Math.abs( matrix[row][column]);
        float sum=-element;
        for(int i=0; i<Main.array_size; i++){
            sum+=Math.abs(matrix[row][i]);
        }
        return Float.compare(element, sum);
    }




}
