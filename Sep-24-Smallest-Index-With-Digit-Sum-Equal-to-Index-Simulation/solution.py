from typing import List

class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        """
        Finds the smallest index i such that the sum of decimal digits of nums[i] equals i.
        Returns -1 if no such index exists.
        """
        for i, val in enumerate(nums):
            # Compute digit sum using arithmetic division
            digit_sum = 0
            temp = val
            while temp > 0:
                digit_sum += temp % 10
                temp //= 10
            
            # Since we traverse from left to right (0 to n-1),
            # the first match found is guaranteed to be the smallest index.
            if digit_sum == i:
                return i
                
        return -1
