// Find Pivot Index (Book-1,Pg-13) (LC-724)

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0, left_sum = 0;
        total_sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (left_sum == total_sum - left_sum - nums[i]) return i;
            left_sum += nums[i];
        }
        return -1;
    }
    // Lakshaya's solution
    // using two vectors to store the prefix and then compare which 
    // index matches in both the arrays, which will be middle point.
    // MY solution
    // int pivotIndex(vector<int>& nums){
    // int index = -1, n = nums.size();
    // for(int i=0; i<n; i++){
    //     int left=0, right=0;
    //     for(int j=0; j<n; j++){
    //         if(j<i) left += nums[j];
    //         else if(j>i) right += nums[j]; 
    //     }
    //     if(left == right){
    //         index = i;
    //         break;
    //     }
    // }
    // return index;
    // }

    // accumulate example
    // int pivotIndex(vector<int>& nums) {
    //    for(int i=0;i<nums.size();i++){
    //     int a=accumulate(nums.begin(),nums.begin()+i,0);
    //     int b=accumulate(nums.begin()+i+1,nums.end(),0);
    //     if(a==b){
    //         return i;
    //     }
    //    }
    // return -1;
    // }
};