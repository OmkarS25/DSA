// Spiral Print a Matrix (Book-1,Pg-20) (LC-64)

#include<iostream>
#include<vector>
using namespace std;

void spiralPrintMatrix_clockWise(vector<vector<int>> &arr){
    int top = 0, bottom = arr.size()-1, left = 0, right = arr[0].size()-1;
    while(top<=bottom && left<=right){
        for(int i=left; i<=right; i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int i=top; i<=bottom; i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom; i>=top; i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
    }
}

void spiralPrintMatrix_antiClockWise(vector<vector<int>> &arr){
    int top = 0, bottom = arr.size()-1, left = 0, right = arr[0].size()-1;
    while(top<=bottom && left<=right){
        for(int i=top; i<=bottom; i++){
            cout<<arr[i][left]<<" ";
        }
        left++;
        for(int i=left; i<=right; i++){
            cout<<arr[bottom][i]<<" ";
        }
        bottom--;
        if(left<=right){
            for(int i=bottom; i>=top; i--){
                cout<<arr[i][right]<<" ";
            }
            right--;
        }
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                cout<<arr[top][i]<<" ";
            }
            top++;
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
    spiralPrintMatrix_clockWise(arr);
    cout<<endl;
    spiralPrintMatrix_antiClockWise(arr);
    return 0;
}   
// Output: 1 2 3 4 8 12 16 20 19 18 17 13 9 5 6 7 11 15 14 10
//         1 5 9 13 17 18 19 20 16 12 8 4 3 2 6 10 14 15 11 7