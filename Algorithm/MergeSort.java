package exercise4;

import java.util.Arrays;

/*
    归并排序的关健分为两个，一个是拆分，一个是合并，分别对应着 sort 和 merge 函数。
    在 sort 函数中，要理清楚如何拆分，无论是 sort1，还是 sort2，核心思想都是：二分和递归。
    在 merge 函数中，如何进行排序，如何处理残余的序列是重点。
*/

public class MergeSort {
    /* 仅在原数组的基础上进行拆分，不需要创建新数组来存放copy的序列，但这需要传入额外的参数 */
    public int[] sort1(int[] nums, int low, int high) {
        if (low == high) {
            return new int[] {nums[low]};
        }
        int mid = low + (high - low) / 2;
        int[] left = sort1(nums, low, mid);
        int[] right = sort1(nums, mid + 1, high);
        return merge(left, right);
    }

    /* 借助辅助空间来存储复制的子数组，这种方式比较容易理解，而且参数列表比较简单 */
    public int[] sort2(int[] nums) {
        if (nums.length == 1) {
            return nums;
        }
        int mid = nums.length / 2;
        int[] left = Arrays.copyOfRange(nums, 0, mid); // 复制从0到mid但不包括mid的序列
        int[] right = Arrays.copyOfRange(nums, mid, nums.length);
        return merge(sort2(left), sort2(right));
    }

    public int[] merge(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;
        /* 进行左右两个数组的比较，并将小的数放入result中 */
        while (i < left.length && j < right.length) {
            if (left[i] < right[j]) {
                result[k ++] = left[i ++];
            } else {
                result[k ++] = right[j ++];
            }
        }
        /* 将左数组或者右数组的剩余数插入result中 */
        /* 注意不能写成如下形式,因为剩余的数可能并不止一个:
        if (i < left.length) {
            result[k ++] = left[i ++];
        } else {
            result[k ++] = right{j ++];
        }
       */
        while (i < left.length) {
            result[k ++] = left[i ++];
        }
        while (j < right.length){
            result[k ++] = right[j ++];
        }
        return result;
    }

    public static void main(String[] args) {
        MergeSort test = new MergeSort();
        int[] nums = {8,4,2,6,1,9,4,3,7,1,2,5,10,99,4,5,7};
        int low = 0;
        int high = nums.length - 1;
        int[] result = test.sort1(nums, low, high);
        int[] result2 = test.sort2(nums);
        System.out.println(Arrays.toString(result));
        System.out.println(Arrays.toString(result2));
    }
}
