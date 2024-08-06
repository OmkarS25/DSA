#include<bits/stdc++.h>
using namespace std;

void radix_sort(vector<int>& arr){
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    for(int exp = 1; max/exp > 0; exp *= 10){
        vector<int> output(n), count(10);
        for(int i = 0; i < n; i++){
            count[(arr[i]/exp)%10]++;
        }
        for(int i = 1; i < 10; i++){
            count[i] += count[i-1];
        }
        for(int i = n-1; i >= 0; i--){
            output[count[(arr[i]/exp)%10]-1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for(int i = 0; i < n; i++){
            arr[i] = output[i];
        }
    }
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    radix_sort(arr);
    for(int a: arr){
        cout << a << " ";
    }
    return 0;
}