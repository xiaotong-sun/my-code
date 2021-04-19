import java.util.HashMap;
import java.util.Map;

/* leetcode: 220.存在重复元素III (桶排序)

对于元素 x，其影响的区间为 [x - t, x + t]。
于是我们可以设定桶的大小为 t + 1。如果两个元素同属一个桶，那么这两个元素必然符合条件。
如果两个元素属于相邻桶，那么我们需要校验这两个元素是否差值不超过 t。
如果两个元素既不属于同一个桶，也不属于相邻桶，那么这两个元素必然不符合条件。

具体地，我们遍历该序列，假设当前遍历到元素 x，那么我们首先检查 x 所属于的桶是否已经存在元素，
如果存在，那么我们就找到了一对符合条件的元素，否则我们继续检查两个相邻的桶内是否存在符合条件的元素。

实现方面，我们将 int 范围内的每一个整数 x 表示为x=(t+1)×a+b(0≤b≤t)的形式，这样 x 即归属于编号为 a 的桶。
因为一个桶内至多只会有一个元素，所以我们使用哈希表实现即可。
 */

class Solution {
    long size;
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        size = t + 1;
        Map<Long, Long> map = new HashMap<>();
        for (int i = 0; i < nums.length; i ++) {
            // long的原因是测试时可能会产生大整数
            long u = (long)nums[i];
            long idx = getIdx(u);
            // 目标桶已存在（桶不为空），说明前面已有 [u - t, u + t] 范围的数字
            if (map.containsKey(idx)) {
                return true;
            }
            // 检查相邻的桶
            long left = idx - 1;
            long right = idx + 1;
            if (map.containsKey(left) && u - map.get(left) <= t) {
                return true;
            }
            if (map.containsKey(right) && map.get(right) - u <= t) {
                return true;
            }
            // 创建桶
            map.put(idx, u);
            /* 移除在范围[i-k,i]之外，最早创建的桶。因为如果不移除的话，在范围之外的值会创建相应的桶，
            而这个值已经超出范围了，所以它所对应的桶已经没有意义了，并且每个桶只存一个值，如果不移除的话，
            会对新加入的值产生影响。
             */
            if (i >= k) {
                map.remove(getIdx(nums[i - k]));
            }
        }
        return false;
    }
    /*
    这个idx计算方法很特别，对整数，负数采取了不同的方案，要好好理解。
    请借助一下桶理解：
    每个桶的范围：[-6~-1]，[0~5], [6~11]
    每个桶的标号：  -1       0      1
     */
    private long getIdx(long u) {
        return u >= 0 ? u / size : (u + 1) / size - 1;
    }
}