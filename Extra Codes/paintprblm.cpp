#include<iostream>
using namespace std;

int getpaintways(int n , int k){
    // if (n==0) return 0;
    if (n==1) return k;
    if (n==2) return k + k*(k-1);
    int ans = (k-1)*(getpaintways(n-1,k)+ getpaintways(n-2,k));
    return ans;
}

int main(){
    int k = 3, n = 3  ;
    cout << "The code is now begining."<<endl;
    int ans = getpaintways(k,n);
    cout <<"The ans is : "<< ans;
    return 0;
}