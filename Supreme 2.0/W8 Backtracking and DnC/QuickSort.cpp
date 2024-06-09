#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// void quickSort(vector<int> arr, int start, int end){
//     if(start >= end) return;
//     if(start < end){
//         int pivot = arr[end];
//         int i = start - 1;
//         for(int j = start; j < end; j++){
//             if(arr[j] < pivot){
//                 i++;
//                 swap(arr[i], arr[j]);
//             }
//         }
//         swap(arr[i+1], arr[end]);
//         quickSort(arr, start, i);
//         quickSort(arr, i+2, end);
//     }
// }

void quickSort(vector<int> arr, int start, int end){
    if(start >= end) return;
    int pivot = end;
    int i = start - 1;
    int j = start;
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++; // i is the correct position for pivot element.
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i-1);
    quickSort(arr, i+1, end);
}

int main(){
    return 0;
}