// Common Elements in 3 Sorted Array (Book-1,Pg-19) (GFG)

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<functional>
#include<set>
using namespace std;

class Solution {
public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> ans;
        int i=0, j=0, k=0;
        set<int> st;
        
        while (i<arr1.size(), j<arr2.size(), k<arr3.size()){
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                // ans.push_back(arr1[i]);
                st.insert(arr1[i]);
                i++, j++, k++;
            }
            else if(arr1[i] < arr2[j]) i++;
            else if(arr2[j] < arr3[k]) j++;
            else k++;
        }
        
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
    }
};