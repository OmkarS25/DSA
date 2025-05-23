/**
 * @brief This is Homework give in DoubtClass.
 * In this file, we will implement a Circular Deque and a Circular Queue.
 * These are two different Leetcode Questions. 
 * LC-641 Design Circular Deque
 * LC-622 Design Circular Queue
 */

// LC-641 Design Circular Deque

class MyCircularDeque {
    int size, front, rear, *arr;
public:
    MyCircularDeque(int k) {
        size = k;
        front = rear = -1;
        arr = new int[size];
    }
    
    bool insertFront(int value) {
        if (isFull()) return false; // Full case
        else if (isEmpty()) front = rear = 0; // Empty case
        else if (front == 0 && rear != size - 1) front = size - 1; // Circular case
        else front--; // Normal case
        arr[front] = value; // Insert value
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false; // Full case
        else if (isEmpty()) front = rear = 0; // Empty case
        else if (rear == size - 1 && front != 0) rear = 0; // Circular case
        else rear++; // Normal case
        arr[rear] = value; // Insert value
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        arr[front] = -1; // Clear the value
        if (front == rear) front = rear = -1; // One element case
        else if (front == size - 1) front = 0; // Circular case
        else front++; // Normal case
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        arr[rear] = -1; // Clear the value
        if (front == rear) front = rear = -1; // One element case
        else if (rear == 0) rear = size - 1; // Circular case
        else rear--; // Normal case
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[front]; // If empty, return -1 else return front;
    }

    int getRear() {
        return isEmpty() ? -1 : arr[rear]; // If empty, return -1 else return rear;
    }

    bool isEmpty() {
        return front == -1 && rear == -1; 
    }
    
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == front - 1); 
    }

    ~MyCircularDeque() {
        delete[] arr;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

// LC-622 Design Circular Queue
// Code Later

#include <iostream>
using namespace std;

int main() {
    // Test MyCircularDeque
    MyCircularDeque* deque = new MyCircularDeque(5);
    deque->insertLast(1);
    deque->insertLast(2);
    deque->insertFront(3);
    cout << deque->getFront() << endl; // Should print 3
    cout << deque->getRear() << endl;  // Should print 2
    deque->deleteFront();
    cout << deque->getFront() << endl; // Should print 1
    delete deque;
    
    return 0;
}