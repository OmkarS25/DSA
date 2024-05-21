// Moving all negative number to the leftside of an array (Book-1,Pg-16)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    void bySortFunction(vector<int>& nums){
        sort(nums.begin(), nums.end());
    }
    void byDutchNationFlag(vector<int>&nums){
        int l=0, h=nums.size()-1;
        while(l<h){
            if(nums[l]<0) l++;
            else if(nums[h]>0) h--;
            else swap(nums[l],nums[h]);
        }
    }
};
int main(){
    vector<int> nums = {2,5,-1,68,4,-6,-2,6,8,-7,-10,3,0};
    cout<<"Before Sorting : ";
    for(int a : nums) cout<<a<<" ";
    cout<<endl;
    Solution obj;
    obj.byDutchNationFlag(nums);
    // obj.bySortFunction(nums);
    cout<<"After Sorting : ";
    for(int a : nums) cout<<a<<" ";
    return 0;
}