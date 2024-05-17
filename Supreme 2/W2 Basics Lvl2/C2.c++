// This class is continution of Coditions and Loops.

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number = ";
    cin>>n;
    // Cotinuing Patterns...
    // Q1 Full Pyramid
    for(int rows=0; rows<n; rows++){
        //Space
        for(int col=0; col<n-rows-1; col++){
            cout<<" ";
        } 
        //stars
        for(int col=0; col<rows+1; col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    // Q8 Fancy Pattern 
     
    for(int row=0; row<n; row++){
        // inner loop 
        for(int col=0; col<2*row+1; col++){
            if(col%2 == 0){
                // odd number 
                cout << "*";
            }
            else {
                cout<<row+1;
            }
        }
        cout << endl;
    }
    
    // other way to solve 
    for(int row=0; row<n; row++){
        // inner loop 
        for(int col=0; col<row+1; col++){
            if(col == row){
                // odd number 
                cout << row + 1;
            }
            else {
                cout<<row+1<< "*";
            }
        }
        cout << endl;
    }

    // Q9 
    

    return 0;
}