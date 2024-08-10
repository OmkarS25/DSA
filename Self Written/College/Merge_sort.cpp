#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, vector<int> & temp, int start, int end){
    int mid = (start + end)/2;
    int idx_tmp = start;
    int i = start, j = mid+1;
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[idx_tmp++] = arr[i++];
        }
        else{
            temp[idx_tmp++] = arr[j++];
        }
    }
    while(i<=mid)
        temp[idx_tmp++] = arr[i++];
    while(j<=end)
        temp[idx_tmp++] = arr[j++];
    while(start<=end){
        arr[start] = temp[start];
        start++;
    }
}

void merge_sort(vector<int>& arr, vector<int>& temp, int start, int end){
    if(start >= end) return;
    int mid = (start + end)/2;
    merge_sort(arr, temp, start, mid);
    merge_sort(arr, temp, mid+1, end);
    merge(arr, temp, start, end);
}

void sort_array(vector<int>& arr){
    int n = arr.size();
    vector<int> temp(n,0);
    merge_sort(arr, temp, 0, n-1);
}

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> a,b; 
    for (int i = 0; i < 1000; i++) {
        int num = rand();
        a.push_back(num);
        b.push_back(num);
    }
    chrono::high_resolution_clock::time_point start_time_merge = chrono::high_resolution_clock::now();
    sort_array(a);
    chrono::high_resolution_clock::time_point end_time_merge = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> runtime_merge = end_time_merge - start_time_merge;
    cout << "\n" << "Runtime: " << runtime_merge.count() << " nanoseconds\n";
    chrono::high_resolution_clock::time_point start_time_bubble = chrono::high_resolution_clock::now();
    bubbleSort(b);
    chrono::high_resolution_clock::time_point end_time_bubble = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> runtime = end_time_bubble - start_time_bubble;
    cout << "\n" << "Runtime: " << runtime.count() << " nanoseconds";
    return 0;
}