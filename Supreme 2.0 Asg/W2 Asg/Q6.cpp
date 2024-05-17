// Fancy Pattern #2 (Book-1,Pg-5)
// 1
// 2*3
// 4*5*6
// 7*8*9*10
// 7*8*9*10
// 4*5*6
// 2*3
// 1

#include<iostream>
using namespace std;


int main(){
    int n = 4;
    int count = 1;
    for (int row = 1; row <= n; row++){
        for (int col = 1; col <= row; col++){
            if(col > 1) cout<<"*";
            cout<<count++;
        }
        cout<<endl;
    }
    int start = count - n;
    for (int row = 1; row <= n; row++){
        int k = start;
        for(int col = 1; col <=n-row+1; col++){
            if(col > 1) cout<<"*";
            cout<<k++;
        }
        start = start - (n-row);
        cout<<endl;
    }
    
    return 0;
}