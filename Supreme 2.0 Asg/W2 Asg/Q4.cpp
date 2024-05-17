// Solid Half Diamond (Book-1,Pg-3)
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *

#include<iostream>
using namespace std;


int main(){
    int n = 5;
    // Method 1
    for (int row = 1; row <= n; row++){
        for(int col = 1; col <= n; col++){
            if(col <= row) cout<<"*";
        }
        cout<<endl;
    }
    for (int row = 1; row <= n; row++){
        for (int col = n; col >= 1; col--){
            if(row < col) cout<<"*";
        }
        cout<<endl;
    }
    // Method 2
    // for (int row = 1; row <= (n*2)-1; row++){
    //     if(row <= n)
    //     for(int col = 1; col <= n; col++){
    //         if(col <= row) cout<<"*";
    //     }
    //     if(row>n)
    //     for (int col = (n*2); col >= n; col--){
    //         if(row < col) cout<<"*";
    //     }
    //     cout<<endl;
    // }
    return 0;
}