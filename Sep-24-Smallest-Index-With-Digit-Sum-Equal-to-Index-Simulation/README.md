# Smallest Index With Digit Sum Equal to Index - Simulation / Array

**Problem Link:** [LeetCode - Smallest Index With Digit Sum Equal to Index](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/)  
**Difficulty:** Easy  
**Date:** Sep 24, 2026  
**Topics:** `Array`, `Math`, `Simulation`

---

## 💡 Intuition & Thought Process

The problem asks us to find the **smallest index** $i$ where the sum of the digits of the element `nums[i]` is equal to the index $i$ itself. If no such index exists, we return `-1`.

### Human-First Thinking:
1. **"Smallest Index" is our superpower**: Whenever a problem asks for the *smallest* index that satisfies a condition, our natural instinct should be to scan from left to right (from $i = 0$ to $n-1$).
2. The very **first** index that satisfies `digit_sum(nums[i]) == i` is guaranteed to be the smallest possible answer. We can stop immediately and return it—no need to examine the rest of the array.
3. **Calculating Digit Sum**: To get the sum of the digits of a number, we can repeatedly peel off the last digit using modulo $10$ (`val % 10`) and discard it using integer division (`val / 10`) until the number reaches $0$.

---

## 📊 Visual Explanation & Walkthrough

Let's trace through **Example 2**: `nums = [1, 10, 11]`

```text
Index (i)   nums[i]   Digits Processed        Digit Sum   Condition (Sum == i)   Result
---------------------------------------------------------------------------------------
   0           1      1                        1          1 == 0  ❌ (False)      Continue
   1          10      1 + 0                    1          1 == 1  ✅ (Match!)     Return 1
   2          11      (Skipped because we return early on smallest match!)
```

### Visual Step-by-Step for an Element:
```text
  Number: 10
  ┌───────────────┐
  │ 10 % 10 = 0   │ ──> sum = 0
  │ 10 / 10 = 1   │
  ├───────────────┤
  │  1 % 10 = 1   │ ──> sum = 0 + 1 = 1
  │  1 / 10 = 0   │
  └───────────────┘
  Final Digit Sum = 1
  Compare: (sum == index) => (1 == 1) => Match found at index 1!
```

---

## ⚙️ Approach

1. **Iterate** linearly through the array from `i = 0` to `n - 1`.
2. **Compute Digit Sum**:
   - Initialize `digit_sum = 0` and `temp = nums[i]`.
   - While `temp > 0`, extract the last digit with `temp % 10`, add it to `digit_sum`, and reduce `temp` with `temp /= 10`.
3. **Check Condition**:
   - If `digit_sum == i`, return `i` immediately.
4. **Fallback**:
   - If the loop finishes without finding any match, return `-1`.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \times D)$ where $N$ is the length of `nums` and $D$ is the maximum number of digits of any number in `nums`.
  - Given the constraint $0 \le \text{nums}[i] \le 1000$, the number of digits $D \le 4$.
  - Therefore, digit extraction takes at most $4$ iterations per element, making the runtime effectively $\mathcal{O}(N)$, which is optimal and runs in ~0ms.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
  - We only use a couple of scalar variables (`digit_sum`, `temp`, `i`) to process elements in-place.

---

# Code

```c++ []
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            int total = 0;

            while (x > 0) {
                total += x % 10;
                x /= 10;
            }

            if (total == i) {
                return i;
            }
        }
        return -1;
    }
};
```
```java []
class Solution {
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            int total = 0;

            while (x > 0) {
                total += x % 10;
                x /= 10;
            }

            if (total == i) {
                return i;
            }
        }
        return -1;
    }
}
```
```python []
class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            x = nums[i]
            total = 0

            while x > 0:
                total += x % 10
                x //= 10

            if total == i:
                return i

        return -1
```
