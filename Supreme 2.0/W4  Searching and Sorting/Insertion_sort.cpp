#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    insertionSort(arr);
    for(auto i: arr){
        cout << i << " ";
    }
    return 0;
}