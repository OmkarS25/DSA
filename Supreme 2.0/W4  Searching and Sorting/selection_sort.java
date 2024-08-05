import java.util.Random;

public class selection_sort {
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    public static void main(String[] args) {
        int size = 1000;
        long start, end;
        double c;
        Random random = new Random();
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = random.nextInt(1000);
        }
        start = System.nanoTime();
        selectionSort(a);
        end = System.nanoTime();
        c = (double) (end - start);
        System.out.println("\nSelection Sort with "+size+" elements.");
        System.out.println("Time: " + c);
    }
}