// Find first repeating element (Book-1,Pg-18) (GFG)

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeatedByVector(int arr[], int n) {
        vector<int> twice(1000001,0);
        int minindex = INT_MAX;
        for(int i=0; i<n; i++){
            if(twice[arr[i]]){
                minindex = min(minindex, twice[arr[i]]);
            }
            else{
            twice[arr[i]] = i+1;
            }
        }
        if(minindex == INT_MAX) return -1;
        return minindex;
    }
    int firstRepeatedByHashMap(int arr[], int n){
        unordered_map<int,int> hash;
        int minindex = INT_MAX;
        if()
    }
};