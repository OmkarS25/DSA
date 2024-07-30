#include<iostream>
using namespace std;

#define PI 3.14159465
#define MAXX(x,y) (x > y ? x : y)

float circleArea(float r){
    return PI*r*r;
}
float circlePerimeter(float r){
    return 2*PI*r;
}
int fun(){
    int a = 10;
    int b = 20;
    int c = MAXX(a,b);
}

int main(){
    cout<<"Area of Circle: "<<circleArea(65.4)<<endl;
    return 0;
}