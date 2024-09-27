// Key Pair (GFG)/ Two Sum (LC-1) (Book-1,Pg-13)

#include<vector>
#include<algorithm>
using namespace std;
// Leetcode solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found 
    }
};

// GFG Solution
class Solution1{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
		sort(arr, arr+n);
		int i = 0, j = n-1;
		while(i<j){
			if(arr[i] + arr[j] == x) return true;
			if(arr[i] + arr[j] > x) j--;
			else i++;
		}
		return false;
	}
};