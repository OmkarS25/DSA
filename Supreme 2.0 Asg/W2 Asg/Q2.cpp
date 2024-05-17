// Numeric Hollow Inverted Half Pyramid (Book-1,Pg-2)
// 12345
// 2  5
// 3 5
// 45
// 5
#include<iostream>
using namespace std;


int main(){
    int n = 5;
    for (int row = 1; row <= n; row++){
        for(int col = row; col<=n; col++){
            if(row == 1 || row == col || col == n) cout<<col;
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}