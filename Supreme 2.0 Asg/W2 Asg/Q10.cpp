// Butterfly Pattern (Book-1,Pg-7)
// *                 *
// * *             * *
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *
// * * * * * * * * * *
// * * * *     * * * * 
// * * *         * * *
// * *             * *
// *                 *

#include<iostream>
using namespace std;


int main(){
    int n = 5;
    // Upper Part
    for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
            cout<<"* ";
        }
        for(int col=n-row; col>=1; col--){
            cout<<"  ";
        }
        for(int col=n-row; col>=1; col--){
            cout<<"  ";
        }
        for(int col=1; col<=row; col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    // Lower Part
    for(int row=n; row>=1; row--){
        for(int col=1; col<=row; col++){
            cout<<"* ";
        }
        for(int col=n-row; col>=1; col--){
            cout<<"  ";
        }
        for(int col=n-row; col>=1; col--){
            cout<<"  ";
        }
        for(int col=1; col<=row; col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}