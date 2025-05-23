// Find first repeating element (Book-1,Pg-18) (GFG)

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<functional>
using namespace std;

// Self Written OR Raw Code
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        // Naive Approach
        // const int n = arr.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(arr[i] == arr[j]) return i+1;
        //     }
        // }
        // return -1;
        
        // Optimized Approach 
        unordered_map<int, int> map;
        const int n = arr.size();
        for(int i=0; i<n; i++){
            map[arr[i]]++;
        }
        for(int i=0; i<n; i++){
            if(map[arr[i]] > 1) return i+1;
        }
        return -1;
    }
};

// With the help of AI
// class Solution {
// public:
//     // Function to return the position of the first repeating element.
//     int firstRepeatedByVector(int arr[], int n) {
//         vector<int> twice(1000001,0);
//         int minindex = INT_MAX;
//         for(int i=0; i<n; i++){
//             if(twice[arr[i]]){
//                 minindex = min(minindex, twice[arr[i]]);
//             }
//             else{
//             twice[arr[i]] = i+1;
//             }
//         }
//         if(minindex == INT_MAX) return -1;
//         return minindex;
//     }
//     int firstRepeatedByHashMap(int arr[], int n){
//         unordered_map<int,int> hash;
//         int minindex = INT_MAX;
//         for(int i=0; i<n; i++){
//             if(hash[arr[i]]) minindex = min(minindex, hash[arr[i]]);
            
//         }
//         return minindex;
//     }
// };