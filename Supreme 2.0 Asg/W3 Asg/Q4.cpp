// Missing Number (Book-1,Pg-15) (LC-268)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int binarySearchMethod(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int start = 0 ,end = nums.size()-1;
        int mid = (start+end)/2;
        int ans = nums.size();
        while(start <= end) {
            if(nums[mid] == mid) {
                start = mid + 1;
            }
            else if(nums[mid] != mid) {
                ans = mid;
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
        return ans;   
    }
    int sortingMethod(vector<int>& nums){
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
    int xorMethod(vector<int>& nums){
        int len = nums.size(), missingno = 0;
        for(int i=0; i<len; i++){
            missingno = missingno ^ nums[i] ^ (i+1);
        }
        return missingno;
    }
    int missingNumber(vector<int>& nums) {
        // return xorMethod(nums);
        // return sortingMethod(nums);
        return binarySearchMethod(nums);
    }
};