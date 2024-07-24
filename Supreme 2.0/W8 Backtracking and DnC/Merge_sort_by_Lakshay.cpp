#include<bits/stdc++.h>
using namespace std;
// Leetcode 912
// Here, we are trying to avoid the new and delete operations.
// So, we are passing the temp array as a parameter to the function.
class Solution {
public:
    void merge(vector<int>& v, vector<int>& temp, int start, int mid, int end){
        int i = start, j = mid + 1;
        // first array = start -> mid
        // second array = mid + 1 -> end
        // merged array => start -> end
        int k = start;

        while(i <= mid && j <= end){
            if(v[i] <= v[j])
                temp[k++] = v[i++];
            else
                temp[k++] = v[j++];
        }

        // handle remaining elements in case of diff array size
        while(i <= mid)
            temp[k++] = v[i++];

         while(j <= end)
            temp[k++] = v[j++];

        // let;s copy merged data
        while(start <= end){
            v[start] = temp[start];
            start++;
        }
    }

    void mergeSort(vector<int>& v, vector<int>& temp, int start, int end){
        if(start >= end) return;

        int mid = (start + end) / 2;
        // divide
        mergeSort(v, temp, start, mid);
        mergeSort(v, temp, mid + 1, end);

        // conqour
        merge(v, temp, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};

class Solution1 {
    // This is the inplace merge sort
    public:
    void merge(vector<int> &arr, int l, int mid, int r) {
        int i = l;
        int j = mid + 1;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                i++;
            } else {
                int value = arr[j];
                int index = j;

                while (index != i) {
                    arr[index] = arr[index - 1];
                    index--;
                }
                arr[i] = value;
                i++, mid++, j++;
            }
        }
    }
    void mergeSort(vector<int> &arr, int l, int r) {
        if(l<r) {
            int mid = l + (r-l)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
};

int main(){
    Solution s;
    vector<int> v = {10, 7, 8, 9, 1, 5};
    vector<int> res = s.sortArray(v);
    for(auto i: res){
        cout << i << " ";
    }
    return 0;
}