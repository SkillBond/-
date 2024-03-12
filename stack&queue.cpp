//Стек через массив: 
#include <iostream> 
#define MAX_SIZE 100 
 
class Stack { 
private: 
    int top; 
    int arr[MAX_SIZE]; 
 
public: 
    Stack() { 
        top = -1; 
    } 
 
    void push(int val) { 
        if (top >= MAX_SIZE - 1) { 
            std::cout << "Stack Overflow" << std::endl; 
        } else { 
            arr[++top] = val; 
        } 
    } 
 
    void pop() { 
        if (top < 0) { 
            std::cout << "Stack Underflow" << std::endl; 
        } else { 
            top--; 
        } 
    } 
 
    int peek() { 
        if (top < 0) { 
            std::cout << "Stack is empty" << std::endl; 
            return 0; 
        } else { 
            return arr[top]; 
        } 
    } 
 
    bool isEmpty() { 
        return top < 0; 
    } 
}; 
//Очередь через массив: 
 
#include <iostream> 
#define MAX_SIZE 100 
 
class Queue { 
private: 
    int front, rear; 
    int arr[MAX_SIZE]; 
 
public: 
    Queue() { 
        front = -1; 
        rear = -1; 
    } 
 
    void enqueue(int val) { 
        if (rear == MAX_SIZE - 1) { 
            std::cout << "Queue Overflow" << std::endl; 
        } else { 
            if (front == -1) { 
                front = 0; 
            } 
            arr[++rear] = val; 
        } 
    } 
 
    void dequeue() { 
        if (front == -1 || front > rear) { 
            std::cout << "Queue Underflow" << std::endl; 
        } else { 
            front++; 
        } 
    } 
 
    int peek() { 
        if (front == -1 || front > rear) { 
            std::cout << "Queue is empty" << std::endl; 
            return 0; 
        } else { 
            return arr[front]; 
        } 
    } 
 
    bool isEmpty() { 
        return front == -1 || front > rear; 
    } 
}; 
//Стек через список: 

#include <iostream> 
 
class Node { 
public: 
    int data; 
    Node* next; 
 
    Node(int val) { 
        data = val; 
        next = nullptr; 
    } 
}; 
 
class Stack { 
private: 
    Node* top; 
 
public: 
    Stack() { 
        top = nullptr; 
    } 
 
    void push(int val) { 
        Node* newNode = new Node(val); 
        if (top == nullptr) { 
            top = newNode; 
        } else { 
            newNode->next = top; 
            top = newNode; 
        } 
    } 
 
    void pop() { 
        if (top == nullptr) { 
            std::cout << "Stack Underflow" << std::endl; 
        } else { 
            Node* temp = top; 
            top = top->next; 
            delete temp; 
        } 
    } 
 
    int peek() { 
        if (top == nullptr) { 
            std::cout << "Stack is empty" << std::endl; 
            return 0; 
        } else { 
            return top->data; 
        } 
    } 
 
    bool isEmpty() { 
        return top == nullptr; 
    } 
}; 
//Очередь через список: 
  
#include <iostream> 
 
class Node { 
public: 
    int data; 
    Node* next; 
 
    Node(int val) { 
        data = val; 
        next = nullptr; 
    } 
}; 
 
class Queue { 
private: 
    Node* front; 
    Node* rear; 
 
public: 
    Queue() { 
        front = nullptr; 
        rear = nullptr; 
    } 
 
    void enqueue(int val) { 
        Node* newNode = new Node(val); 
        if (rear == nullptr) { 
            front = newNode; 
            rear = newNode; 
        } else { 
            rear->next = newNode; 
            rear = newNode; 
        } 
    } 
 
    void dequeue() { 
        if (front == nullptr) { 
            std::cout << "Queue Underflow" << std::endl; 
        } else { 
            Node* temp = front; 
            front = front->next; 
            if (front == nullptr) { 
                rear = nullptr; 
            } 
            delete temp; 
        } 
    } 
 
    int peek() { 
        if (front == nullptr) { 
            std::cout << "Queue is empty" << std::endl; 
            return 0; 
        } else { 
            return front->data; 
        } 
    } 
 
    bool isEmpty() { 
        return front == nullptr; 
    } 
};