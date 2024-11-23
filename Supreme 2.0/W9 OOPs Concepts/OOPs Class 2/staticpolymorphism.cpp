#include <iostream>
#include <string>
#include <vector>

using namespace std;

// fn overloading
// int add(int a, int b)
// {
//     return a + b;
// }

// double add(double a, double b)
// {
//     return a + b;
// }

// int add(int a, int b, int c)
// {
//     return a + b + c;
// }

// fn overloading
class Vector
{
    int x, y;

public:
    // Vector(int x, int y)
    // {
    //     this->x = x;
    //     this->y = y;
    // }

    // init list
    Vector(int _x, int _y) : x(_x), y(_y) {}

    // op overloading
    void operator+=(const Vector &src)
    {
        // this would point to v1
        // src would be ref to v2
        // this->x = this->x + src.x;
        // this->y = this->y + src.y;

        this->x += src.x;
        this->y += src.y;
    }

    Vector operator+(const Vector &src)
    {
        // this would point to v1
        // src would be ref to v2
        // this->x = this->x + src.x;
        // this->y = this->y + src.y;

        return {this->x + src.x, this->y + src.y};
    }

    void operator++()
    {
        this->x++;
        this->y++;
    }

    void display()
    {
        cout << "x:" << x << " "
             << "y:" << y << endl;
    }
};

int main()
{
    // cout << add(1, 5) << endl;
    // cout << add(5.6, 4.5) << endl;
    // cout << add(1, 2, 3) << endl;

    Vector v1(2, 3);
    Vector v2(4, 5);
    Vector v3 = v1 + v2;
    v3.display();

    v1 += v2;
    // v1 - v2; same can be done as v1.operator-(v2);
    v1.display();

    ++v1;
    // addtion answer should be stored in v1;
    v1.display();
    return 0;
}