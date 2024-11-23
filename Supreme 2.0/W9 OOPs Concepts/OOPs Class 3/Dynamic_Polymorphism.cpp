#include <iostream>
using namespace std;

// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    virtual void makeSound()
    {
        cout << "Animal makes a sound" << endl;
    }

    virtual ~Animal()
    {
        cout<<"~Animal dtor"<<endl;
    }
}; 

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "Dog barks" << endl;
    }

    ~Dog()
    {
        cout<<"~Dog dtor"<<endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "Cat meows" << endl;
    }

    ~Cat()
    {
        cout<<"~Cat dtor"<<endl;
    }
};

class Parrot : public Animal
{
public:
    void makeSound() override
    {
        cout << "Parrot mithu mithu" << endl;
    }
    
    ~Parrot()
    {
        cout<<"~Parrot dtor"<<endl;
    }
};

void sound(Animal *animal){
    animal->makeSound(); // This line is polymorphic
    // animal->makeSound() is behaving as per required object allocated at runtime.
}

int main()
{
    // Dynamic allocation with late binding.
    Animal *animal = new Dog();
    sound(animal);
    delete animal;

    animal = new Cat();
    sound(animal);
    delete animal;

    animal = new Parrot();
    sound(animal);
    delete animal;

    // Static allocation but late binding.
    // Animal *animalPtr;
    // Dog dogObj;
    // Cat catObj;
    // Parrot parrotObj;

    // animalPtr = &dogObj;
    // animalPtr->makeSound(); // Output: "Dog barks"

    // animalPtr = &catObj;
    // animalPtr->makeSound(); // Output: "Cat meows"

    // animalPtr = &parrotObj;
    // animalPtr->makeSound(); // Output: "Parrot mithu mithu"

    return 0;
}