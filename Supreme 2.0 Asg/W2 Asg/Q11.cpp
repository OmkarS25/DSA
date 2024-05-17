// Display Area of Circle (Book-1,Pg-7)

#include<iostream>
using namespace std;

float circle_area(float radius){
    float area = 3.14 * radius * radius;
    return area;
}
int main(){
    float radius = 5.23;
    float area = circle_area(radius);
    cout<<"Area :"<<area;
    return 0;
}