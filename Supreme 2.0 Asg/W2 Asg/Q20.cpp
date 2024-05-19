// Create Numbers using Digits (Book-1,Pg-10)

#include<iostream>
#include<vector>
using namespace std;

int MakeNumber(vector<int>& digits, int n){
    for(int i = 0; i<n; i++){
        cout<<"Enter the "<<i+1<<" digit : ";
        int temp;
        cin>>temp;
        digits.push_back(temp);
    }
    int num = 0;
    for(auto a : digits){
        num = num*10 + a;
    }
    return num;
}

int main(){
    vector<int> digits;
    int n = 0;
    cout<<"Enter how many digits you want to enter: ";
    cin>>n;
    int num = MakeNumber(digits, n);
    cout<<"THe number is :"<<num;

    return 0;
}