#include<bits/stdc++.h>
using namespace std;

void bucket_sort(vector<int>& arr){
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    vector<vector<int>> bucket(range);
    for(int i = 0; i < n; i++){
        int index = (arr[i]-min)*(range-1)/range;
        bucket[index].push_back(arr[i]);
    }
    for(int i = 0; i < range; i++){
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    for(int i = 0; i < range; i++){
        for(int j = 0; j < bucket[i].size(); j++){
            arr[index++] = bucket[i][j];
        }
    }
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    bucket_sort(arr);
    for(int a: arr){
        cout << a << " ";
    }
    return 0;
}