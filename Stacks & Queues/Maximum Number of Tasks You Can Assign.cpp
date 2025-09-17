/*You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed 
integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength 
of each worker is stored in a 0-indexed integer array workers, with the jth worker having 
workers[j] strength. Each worker can only be assigned to a single task and must have a strength
 greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).

Additionally, you have pills magical pills that will increase a worker's strength by strength.
You can decide which workers receive the magical pills, however, you may only give each worker
at most one magical pill.
Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, 
return the maximum number of tasks that can be completed.


Example 1:

Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
Output: 3
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)
*/

#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// using deque
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int n = tasks.size(), m = workers.size();
        int left = 0, right = min(n, m), ans = 0;

        // Binary search on number of tasks that can be assigned
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;        // possible → try more
                left = mid + 1;
            } else {
                right = mid - 1;  // not possible → try fewer
            }
        }
        return ans;
    }

private:
    bool canAssign(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        deque<int> dq;
        int n = tasks.size();
        int m = workers.size();
        int ptr = m - 1; // pointer to strongest worker in the last 'mid'
        int p = pills;

        // Assign hardest 'mid' tasks from tasks[n - mid ... n-1]
        for (int i = mid - 1; i >=0; --i) {

            // Push all workers that could handle this task with a pill
            while (ptr >= m - mid && workers[ptr] + strength >= tasks[i]) {
                dq.push_front(workers[ptr]);
                --ptr;
            }

            if (dq.empty()) return false; // no worker available

            // Strongest worker can handle the task directly
            else if (dq.back() >= tasks[i]) {
                dq.pop_back();
            } 
            // Weakest worker + pill handles the task
            else {
                if (p == 0) return false;
                dq.pop_front();
                --p;
            }
        }
        return true;
    }
};


// using multiset
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 1, right = min(n, m), ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;        // possible → try more
                left = mid + 1;
            } else {
                right = mid - 1;  // not possible → try less
            }
        }
        return ans;
    }

private:
    bool canAssign(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int p = pills;
        multiset<int> ws;

        // strongest 'mid' workers
        for (int i = workers.size() - mid; i < workers.size(); i++) {
            ws.insert(workers[i]);
        }

        // assign hardest 'mid' tasks
        for (int i = mid - 1; i >= 0; i--) {
            int task = tasks[i];

            // Case 1: strongest worker handles it directly
            auto it = prev(ws.end());
            if (*it >= task) {
                ws.erase(it);
            }
            // Case 2: use pill on a weaker worker
            else {
                if (p == 0) return false;
                auto rep = ws.lower_bound(task - strength);
                if (rep == ws.end()) return false;
                ws.erase(rep);
                p--;
            }
        }
        return true;
    }
};