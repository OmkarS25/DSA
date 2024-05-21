// Sort Colors (LC-75) (Book-1,Pg-15)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void sortColorsbyThreePointers(vector<int>& nums){
        int l=0, m=0, h=nums.size()-1;
        while(m<h){
            if(nums[m] == 0){
                swap(nums[m],nums[h]);
                l++;
                m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
    void sortColorsbySortFucntion(vector<int>& nums){
        sort(nums.begin(), nums.end());
    }
    void sortColorsbyCounting(vector<int>& nums) {
        int n0=0,n1=0,n2=0;
        int size=nums.size();
        for(int i=0; i<size; i++){
            if(nums[i]==0){
                n0++;
            }
            else if (nums[i]==1){
                n1++;
            }
            else if (nums[i]==2){
                n2++;
            }
        }
        int index=0;
        while(n0--){
            nums[index]=0;
            index++;
        }
        while(n1--){
            nums[index]=1;
            index++;
        }
        while(n2--){
            nums[index]=2;
            index++;
        }
    }
};
