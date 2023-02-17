package lab1;

import java.io.*;
import java.util.Scanner;



public class Main {
    static float[][] array;

    static Scanner sc;
    static int array_size;
    static float accuracy;

    private static void print_array(){
        for (int i = 0; i < array_size; i++){
            for (int j = 0; j < array_size+1; j++){
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void inputFromKeyboard(){
        System.out.print("Введите количество уравнений в матрице: ");
        array_size = sc.nextInt();
        input_array();
        System.out.print("Введите точность(раздилитель запятая): ");
        accuracy= sc.nextFloat();
    }

    private static void inputFromFile(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Введите путь к файлу: ");

        try {
            String file = br.readLine();
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line;

            array_size= Integer.parseInt(reader.readLine());
            accuracy=Float.parseFloat(reader.readLine());
            array=new float[array_size][array_size+1];
            int k=0;
            while ((line = reader.readLine()) != null) {
                    String[] line1 = line.trim().split(" ");
                    for (int j=0; j<line1.length; j++) {
                        array[k][j] = Float.parseFloat(line1[j]);
                    }
                    k+=1;

            }
        }catch (FileNotFoundException e){
            System.out.println("Файл не найден");
        }
        catch (IOException e) {
            System.out.println("Проблемы с файлом");
            System.exit(1);
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Некорректное количество элементов в ряду ");
            System.exit(1);
        }
    }
//C:\Users\pomat\Documents\Itmo\2course\witch_math\lab1\src\main\resources\test.txt
    private static void input_array(){
        System.out.println("Введите матрицу:");
        array = new float[array_size][array_size + 1];
        for (int i = 0; i < array_size; i++)
            for (int j = 0; j < array_size+1; j++)
                array[i][j] = sc.nextInt();
    }


    public static void main(String[] args) {
        sc=new Scanner(System.in);
        System.out.print("Открыть из файла/Считать с клавиатуры (1/2):  ");
        int type=sc.nextInt();
        if (type==1){
            inputFromFile();
        } else if (type==2) {
            inputFromKeyboard();
        }else {
            System.out.println("Другие варианты времмено недоступны");
        }

        print_array();
        Utils ut=new Utils(array_size);
        boolean test=(ut.check_diagonal(array));

        if (test){
            System.out.println("После проверки на диагональное преобладание");
            print_array();
            ut.refactor(array);
            while(ut.cur_accuracy>accuracy){
                ut.approximation(array, array_size);
                ut.printResult();
            }
        }
        else{
            System.out.println("Невозможность достижения диагонального преобладания");
        }
    }
}