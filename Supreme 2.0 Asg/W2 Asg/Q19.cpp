// Count all Set Bits of Number (Book-1,Pg-10)

#include<iostream>
using namespace std;

// Normal Method
// int countBits(int num){
//     int count = 0;
//     while(num > 0){
//         int bit = num % 2;
//         if(bit == 1){
//             count++;
//         }
//         num = num/2;
//     }
//     return count;
// }

// Bitwise Method
int countBits(int num){
    int count = 0;
    while(num){
        if(num&1) count++;
        num = num >> 1;
    }
    return count;
}
int main(){
    int n = 21;
    cout<<"No. of bits in "<<n<<" : "<<countBits(n);
    return 0;
}