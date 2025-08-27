/*Given an integer array nums of length n where all the integers of nums are in the range [1, n]
 and each integer appears at most twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant auxiliary space,
excluding the space needed to store the output

⚡ Idea: In-place Marking
Since numbers are in range [1..n], we can use the array itself to track visits.
🔹 Approach
For each number num, map it to an index idx = abs(num) - 1.
If nums[idx] is positive, mark it visited by flipping sign → nums[idx] = -nums[idx].
If nums[idx] is already negative, that means we’ve seen num before → it’s a duplicate.*/

#include <iostream>
#include <vector>
#include <cmath> // for abs()
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
            {
                // already visited → duplicate found
                res.push_back(abs(nums[i]));
            }
            else
            {
                nums[idx] = -nums[idx]; // mark visited
            }
        }
        return res;
    }
};

// ===================
// Driver Code
// ===================
int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution obj;
    vector<int> ans = obj.findDuplicates(nums);

    cout << "Duplicates: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
