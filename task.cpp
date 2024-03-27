#include <iostream>

// Реализация стека с использованием массива
class Stack {
private:
    int* stack;
    int top;
    int capacity;

public:
    Stack(int size) {
        stack = new int[size];
        top = -1;
        capacity = size;
    }

    void push(int item) {
        if (isFull()) {
            std::cout << "Stack is full. Cannot push item." << std::endl;
            return;
        }
        stack[++top] = item;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop item." << std::endl;
            return -1;
        }
        return stack[top--];
    }

    int topItem() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot retrieve top item." << std::endl;
            return -1;
        }
        return stack[top];
    }

    int size() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

// Реализация стека с использованием связанного списка
class Node {
public:
    int data;
    Node* next;
};

class StackLL {
private:
    Node* top;

public:
    StackLL() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop item." << std::endl;
            return -1;
        }
        int item = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return item;
    }

    int topItem() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot retrieve top item." << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Реализация очереди с использованием массива
class Queue {
private:
    int* queue;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        queue = new int[size];
        front = -1;
        rear = -1;
        capacity = size;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue item." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        queue[++rear] = item;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue item." << std::endl;
            return -1;
        }
        int item = queue[front++];
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return item;
    }

    int size() {
        return rear - front + 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }
};

// Реализация очереди с использованием связанного списка
class QueueLL {
private:
    Node* front;
    Node* rear;

public:
    QueueLL() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
    }
};