// Fancy Pattern #1 (Book-1,Pg-4)
// ********1********
// *******2*2*******
// ******3*3*3******
// *****4*4*4*4*****
// ****5*5*5*5*5****

#include<iostream>
using namespace std;
void solve (int n){ // Not solved
    for (int row = 1; row <= n; row++){
        // Portion 1
        for(int col = 1; col<n; col++){
            cout<<"*";
        }
        // Portion 2
        for (int col = n; col >= 1; col--){
            if(row < col) cout<<"*";
        }
        // Portion 3
        for (int col = row; col <= n; col++){
            if(row == col) cout<<row;
        }
        // Portion 4
        for (int col = row; col <= n; col++){
            if(row == col) cout<<row;
        }
        // Portion 5
        for (int col = 1; col <= n; col++){
            if(row > col) cout<<"*";
        }
        // Portion 6
        for(int col = 1; col<n; col++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void solve2(int n){ // Solved
    for (int row = 1; row <= n; row++){
        // Portion 1
        for (int col = (n*2)-row; col > 1; col--){
            cout<<"*";
        }
        // Portion 2
        for (int col = 1; col <= row; col++){
            cout<<row<<"*";
        }
        // Portion 3
        for (int col = 1; col < (n*2)-row-1; col++){
            cout<<"*";
        }
        cout<<endl;
    }
    
}
int main(){
    int n = 5;
    //solve(n);
    solve2(n);
    return 0;
}