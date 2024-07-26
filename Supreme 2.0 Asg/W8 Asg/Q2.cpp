// In-place merge sort
#include<bits/stdc++.h>
using namespace std;

class Solution {
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

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    Solution obj;
    obj.mergeSort(arr, 0, arr.size()-1);
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}