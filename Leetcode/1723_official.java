import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int minimumTimeRequired(int[] jobs, int k) {
        Arrays.sort(jobs);
        int low = 0, high = jobs.length - 1;
        while (low < high) {
            int temp = jobs[low];
            jobs[low] = jobs[high];
            jobs[high] = temp;
            high --;
            low ++;
        }
        low = jobs[0];
        high = Arrays.stream(jobs).sum();
        while (low < high) {
            int mid = (low + high) >> 1;
            if (check(jobs, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public boolean check(int[] jobs, int k, int limit) {
        int[] workloads = new int[k];
        return backtrack(jobs, workloads, 0, limit);
    }

    // i refers to the ith job which will be allocation
    public boolean backtrack(int[] jobs, int[] workloads, int i, int limit) {
        if (i == jobs.length) {
            return true;
        }
        int cur = jobs[i];
        // j refers to the jth worker
        for (int j = 0; j < workloads.length; j ++){
            if (workloads[j] + cur <= limit) {
                workloads[j] += cur;
                if (backtrack(jobs, workloads, i + 1, limit)) {
                    return true;
                }
                workloads[j] -= cur;
            }
            if (workloads[j] == 0 || workloads[j] + cur == limit) {
                return false;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Solution test = new Solution();
        int[] jobs = {3,2,3};
        System.out.println(test.minimumTimeRequired(jobs, 3));
    }
}