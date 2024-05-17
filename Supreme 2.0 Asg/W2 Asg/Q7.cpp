// Fancy Pattern #3 (Book-1,Pg-5)
// *
// *1*
// *121*
// *12321*
// *121*
// *1*
// *

#include<iostream>

using namespace std;


int main(){
    int n=4;
    // Generating Triangle
    for (int row = 0; row <= n; row++){
        cout<<"*";
        for (int col = 1; col <= row; col++){
             cout<<col;
        }
        for(int col = row-1; col >= 1; col--){
            cout<<col;
        }
        if(row!=0) cout<<"*";
        cout<<endl;
    }
    // Shrinking Triangle
    for (int row = n-1; row >= 0; row--){
        cout<<"*";
        for(int col = 1; col <= row; col++){
            cout<<col;
        }
        for (int col = row-1; col >= 1; col--){
            cout<<col;
        }
        if(row!=0) cout<<"*";
        cout<<endl;
    }
    
    return 0;
}