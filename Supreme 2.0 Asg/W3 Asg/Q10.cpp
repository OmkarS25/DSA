// Wave Print a Matrix (Book-1,Pg-20) (GFG)

#include<iostream>
#include<vector>
using namespace std;

void wavePrintMatrix_colWise(vector<vector<int>> &arr){
    const int n = arr.size();
    const int m = arr[0].size();
    for(int j=0; j<m; j++){
        if(j%2 == 0){
            for(int i=0; i<n; i++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int i=n-1; i>=0; i--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

void wavePrintMatrix_rowWise(vector<vector<int>> &arr){
    const int n = arr.size();
    const int m = arr[0].size();
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            for(int j=0; j<m; j++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int j=m-1; j>=0; j--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

int main(){
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    wavePrintMatrix_colWise(arr);
    cout<<endl;
    wavePrintMatrix_rowWise(arr);
    return 0;
}