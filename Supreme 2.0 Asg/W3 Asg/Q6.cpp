// Find Duplicate Number (Book-1,Pg-16) (LC-287)

#include<iostream>
#include<vector>
#include<string>
#include<algorithm> // Add this header for find()
using namespace std;

class Solution {
public:
    int findDuplicateByNegMarking(vector<int>& nums){
        // By marking the visited number as negative and then if it again tries to change
        // to positive then return that number as duplicate.
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]);

            if(nums[index] < 0){
                ans = index;
                break;
            }

            nums[index] *= ans;
        }
        return ans;
    }
    int findDuplicateBySwapSortMethod(vector<int>& nums){
        // By swaping the numbers of 0th index to the actual index the number should be.
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[0] == nums[nums[0]]){
                ans = nums[0];
                break;
            }
            swap(nums[0], nums[nums[0]]);
        }
        return ans;
    }
    int findDuplicateBySortMethod(vector<int>& nums) {
        // By Sorting and matching the index.
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;
    }
};