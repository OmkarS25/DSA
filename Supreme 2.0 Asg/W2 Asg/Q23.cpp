// Binary representation of a Number (Book-1,Pg-11)

#include<iostream>
#include<cmath>
using namespace std;

int intToBinary(int num){
    int binaryno = 0, i = 0;
    while(num){
        int bit = (num&1);
        binaryno = bit*pow(10, i++) + binaryno;
        num = num>>1;
    }
    return binaryno;
}

int binaryToInt(int num){
    int decimal = 0, i = 0;
    while(num){
        int bit = num%10;
        decimal = decimal + bit*pow(2, i++);
        num /= 10;
    }
    return decimal;
}

int main(){
    int n = 10;
    cout<<"The binary form of "<<n<<" is : "<<intToBinary(n)<<endl;
    cout<<"The decimal form of "<<intToBinary(n)<<" is : "<<binaryToInt(intToBinary(n));
    return 0;
}