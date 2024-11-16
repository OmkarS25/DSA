// Bubble Sort, Selection Sort, Insertion Sort

import java.util.Random; 

public class Practical_1 { 
    private static void bubblesort(int size){
        long start, end; double c;
        Random random = new Random(); 
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = random.nextInt(1000);
        }
        start = System.nanoTime();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) { 
                if (a[j + 1] < a[j]) {
                    int t = a[j]; 
                    a[j] = a[j + 1]; 
                    a[j + 1] = t;
                }
            }
        }
        end = System.nanoTime(); c = (double) (end - start);
        System.out.println("\nBUBBLE SORT"); 
        System.out.println("Time:" + c);
    }

    private static void selectionsort(int size){
        long start, end; double c;
        Random random = new Random(); 
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = random.nextInt(1000);
        }
        start = System.nanoTime();
        for (int i = 0; i < size - 1; i++) {
            int min = i;
            for (int j = i + 1; j < size; j++) {
                if (a[j] < a[min]) {
                    min = j;
                }
            }
            int t = a[min]; 
            a[min] = a[i]; 
            a[i] = t;
        }
        end = System.nanoTime(); c = (double) (end - start);
        System.out.println("\nSELECTION SORT"); 
        System.out.println("Time:" + c);
    }

    private static void insertionsort(int size){
        long start, end; double c;
        Random random = new Random(); 
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = random.nextInt(1000);
        }
        start = System.nanoTime();
        for (int i = 1; i < size; i++) {
            int t = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > t) {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = t;
        }
        end = System.nanoTime(); c = (double) (end - start);
        System.out.println("\nINSERTION SORT"); 
        System.out.println("Time:" + c);
    }
    public static void main(String[] args) { 
        int size = 1000;
        bubblesort(size);
        selectionsort(size);
        insertionsort(size);
    }
}