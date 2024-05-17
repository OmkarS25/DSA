// Numeric Palindrome Equilateral Pyramid (Book-1,Pg-3)
//     1
//    121
//   12321
//  1234321
// 123454321

#include<iostream>
using namespace std;


int main(){
    int n = 5;
    for (int row = 1; row <= n; row++){
        // Blank spaces
        for (int col = row; col < n; col++){
            cout<<" ";
        }
        // Number in first half of pyramid
        for(int col = 1; col <= n; col++){
            if(col <= row) cout<<col;
        }
        // Number in second half of pyramid
        for (int col = row-1; col >= 1; col--){
            if(row > 1) cout<<col;
        }
        cout<<endl;
    }
    return 0;
}