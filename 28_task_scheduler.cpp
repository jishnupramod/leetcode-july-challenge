/*
You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. 
Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> cnts;
        for (char ch : tasks) ++cnts[ch];
        priority_queue<int> pq;
        for (auto t : cnts) pq.push(t.second);
        int res = 0;
        while (!pq.empty()) {
            vector<int> tmp;
            int time = 0;
            for (int i=0; i<n+1; ++i) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top()-1);
                    pq.pop();
                    ++time;
                }
            }
            for (int t : tmp) {
                if (t)
                    pq.push(t);
            }
            res += pq.empty() ? time : n+1;
        }
        return res;
    }
};