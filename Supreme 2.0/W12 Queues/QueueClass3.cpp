// Question 1: first non repeating character in a stream
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "ababc";
    queue<char> q;
    int freq[26] = {0};
    // har char ko pakdo frequency store kro queue mai dalo aur check kro
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch - 'a']++;
        // queue ke ander push taki track rakh pao
        q.push(ch);

        // answer find kro
        while (!q.empty())
        {
            char frontChar = q.front();
            // check freq
            if (freq[frontChar - 'a'] > 1)
            {
                // not an answer
                q.pop();
            }
            else
            {
                //==1 vala case
                // unique character
                cout << frontChar << " ";
                break;
            }
        }
        if (q.empty())
        {
            // no answer found
            cout << '#' << " ";
        }
    }
    return 0;
}
// Question 2: Gas Station Leetcode->134
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0;
    int balance = 0;
    // index from where we are starting the movement
    int start = 0;

    // har ek index ko check kar raha hai, ki wo answer hai ya nahi
    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance + gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }
    // if (balance - deficit >= 0)
    //     return start;
    // else
    //     return -1;
    return (balance - deficit >= 0) ? start : -1; // My changes
}

// Question 3:Sliding windows Maximum Leetcode->239
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;
    int size = nums.size();
    // Step-1 first window process till k size
    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        // chotte elements ko pop kardo
        while (!dq.empty() && element > nums[dq.back()])
        {
            dq.pop_back();
        }
        // new max index ko insert kardo
        dq.push_back(i);
    }

    // Step-2 remaining window ko process karlo
    //     answer ko store karlo
    //     removal
    //     addition of new max index
    for (int i = k; i < size; i++)
    {

        ans.push_back(nums[dq.front()]);

        // Removal of out of range elements
        if (i - dq.front() >= k) dq.pop_front();
        int element = nums[i];
        // chotte elements ko pop kardo
        while (!dq.empty() && element > nums[dq.back()])
        {
            dq.pop_back();
        }
        // addition of new max index
        dq.push_back(i);
    }
    
    // Step-3 last window ka answer store kardo
    ans.push_back(nums[dq.front()]);

    return ans;
}
