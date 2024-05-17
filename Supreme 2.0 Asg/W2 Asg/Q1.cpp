// Numeric Hollow Half Pyramid (Book-1,Pg-2)
// 1
// 12
// 1 3
// 1  4
// 12345
#include<iostream>
using namespace std;


int main(){
    int n = 5;
    // Outer Loop
    for(int row = 1; row <= n; row++){
        // Inner Loop
        for (int col = 1; col <= row; col++){
            if(row == 1 || row == 2 || row == n) cout<<col;
            else if(col == 1 || col == row) cout<<col;
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}