// KM to Miles (Book-1,Pg-10)

#include<iostream>
using namespace std;


int main(){
    // 1 Mile = 1.609344 KM
    // 1 KM = 0.621371
    double KM = 0;
    cout<<"Enter the distance in KM :";
    cin>>KM;
    double miles = 0.621371 * KM;
    cout<<"The distance in miles is :"<<miles;
    return 0;
}
