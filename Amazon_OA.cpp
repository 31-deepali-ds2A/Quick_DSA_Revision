#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void fun(vector<int>& arr, int budget) {
    int n = arr.size();
    priority_queue<int> pq;  // max-heap
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        pq.push(arr[i]);

        int count = 0;
        int tempSum = sum;
        priority_queue<int> temp = pq;  // copy heap for simulation

        // remove largest until sum fits budget
        while (tempSum > budget && !temp.empty()) {
            tempSum -= temp.top();
            temp.pop();
            count++;
        }

        cout << count << endl;  // min removals at index i
    }
}

int main() {
    int n, budget;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter budget: ";
    cin >> budget;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    fun(arr, budget);
    return 0;
}


// optimal
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void fun(vector<int>& arr, int budget) {
    int n = arr.size();
    priority_queue<int> pq;  // max-heap
    int sum = 0;
    int removed = 0;         // total removals so far

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        pq.push(arr[i]);

        while (sum > budget && !pq.empty()) {
            sum -= pq.top();   // remove largest
            pq.pop();
            removed++;
        }

        cout << removed << endl;  // removals needed up to index i
    }
}

int main() {
    int n, budget;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter budget: ";
    cin >> budget;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    fun(arr, budget);
    return 0;
}
