#include<bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr){
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    vector<int> count(range), output(n);
    for(int i = 0; i < n; i++){
        count[arr[i]-min]++;
    }
    for(int i = 1; i < count.size(); i++){
        count[i] += count[i-1];
    }
    for(int i = n-1; i >= 0; i--){
        output[count[arr[i]-min]-1] = arr[i];
        count[arr[i]-min]--;
    }
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    counting_sort(arr);
    for(int a: arr){
        cout << a << " ";
    }
    return 0;
}