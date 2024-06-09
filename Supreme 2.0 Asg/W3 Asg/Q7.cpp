// Missing Elements from an array with duplicate (Book-1,Pg-17)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMissingByNegMarkingMethod(int arr[], int n){
    // Negative Marking Method
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    for(int i=0; i<=n; i++){
        int index = abs(arr[i]);
        if(arr[index-1] > 0){
            arr[index -1] *= -1;
        }
    } 
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // } 
    for(int i=0; i<n; i++){ 
        if(arr[i] > 0) 
        // cout<<i+1<<" ";
        return i+1;
    }
    return -1;
}

void findMissingBySortSwapMethod(int arr[], int n){
    // Sorting + Swaping Method
    int i=0;
    while(i<n){
        int index = arr[i]-1;
        if(arr[i] != arr[index]){
            swap(arr[i], arr[index]);
        }
        else i++;
    }
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,3,5,3,4};
    int n = sizeof(arr)/sizeof(int);
    // int missingno = findMissingByNegMarkingMethod(arr, n);
    // cout<<"\nMissing No. is : "<<missingno;
    findMissingBySortSwapMethod(arr, n);
    return 0;
}