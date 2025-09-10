#include <vector>
using namespace std;

/*
Question:
---------
Given an array of integers nums containing n + 1 integers 
where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.

Constraints:
------------
1. You must solve without modifying nums.
2. You must use only constant extra space.

⚡ Algorithm Recap:
------------------
Think of the array as a linked list:
   index -> nums[index]

Because values are in [1..n], every nums[i] points to a valid index.
If there’s a duplicate, it means two indices point to the same number,
which creates a cycle in this "linked list".

We can use Floyd's Cycle Detection Algorithm (Tortoise & Hare):
1. Phase 1: Detect the cycle.
   - slow = nums[slow]
   - fast = nums[nums[fast]]
   - Loop until slow == fast.

2. Phase 2: Find the entry of the cycle.
   - Reset fast = nums[0].
   - Move both slow and fast one step at a time.
   - First meeting point = duplicate number.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Detect cycle
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];         // move by 1 step
            fast = nums[nums[fast]];   // move by 2 steps
        } while (slow != fast);

        // Phase 2: Find cycle entry (duplicate number)
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];   // move both one step
            fast = nums[fast];
        }

        // Duplicate number found
        return slow;
    }
};
