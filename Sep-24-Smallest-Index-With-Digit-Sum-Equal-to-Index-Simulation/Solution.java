class Solution {
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int digitSum = 0;
            int temp = nums[i];

            // Extract each digit using modulo 10 and division
            while (temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }

            // Return the first index that satisfies the condition
            if (digitSum == i) {
                return i;
            }
        }
        return -1;
    }
}
