#ifndef BIRD_H // Can also write : #if !defined(BIRD_H)
#define BIRD_H 
// This is written so that even if the #include is written multiple times
// then also this file will be included only once.

#include<iostream>

class Bird{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
    // Classes that inherits this class 
    // has to implement pure virtual functions.
};

class Sparrow : public Bird{
private:
    void eat(){
        std::cout << "Sparrow is eating\n";
    }
    void fly(){
        std::cout << "Sparrow is flying\n";
    }
};

class Eagle : public Bird{
private:
    void eat(){
        std::cout << "Eagle is eating\n";
    }
    void fly(){
        std::cout << "Eagle is flying\n";
    }
};

class Pigeon : public Bird{
private:
    void eat(){
        std::cout << "Pigeon is eating\n";
    }
    void fly(){
        std::cout << "Pigeon is flying\n";
    }
};

#endif // BIRD_H