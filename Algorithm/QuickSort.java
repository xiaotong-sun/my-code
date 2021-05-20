import java.util.Arrays;

public class QuickSort {
    public void quickSort(int[] a, int p, int r) {
        if (p < r) {
            int q = Partition(a, p, r);
            quickSort(a, p, q - 1); // 对枢轴左边的部分进行快排
            quickSort(a, q + 1, r); // 对枢轴右边的部分进行快排
        }
    }
    
    // Partition函数： 将大于枢轴的数放在右边，将小于枢轴的数放在左边，但是左半部分和右半部分不一定按顺序排列。
    public int Partition(int[] a, int p, int r) {
        int i = p, j = r + 1;
        int x = a[p];
        while (true) {
            while (a[--j] > x);
            while (a[++i] < x && i < r);
            if (i >= j) break;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        a[p] = a[j];
        a[j] = x;
        return j;
    }

    public static void main(String[] args) {
        int[] a = {46, 55, 13, 42, 94, 5, 17, 70};
        int r = a.length - 1;
        QuickSort test = new QuickSort();
        test.quickSort(a, 0, r);
        System.out.println(Arrays.toString(a));
    }
}