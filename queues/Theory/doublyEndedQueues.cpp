// implementing deque at our own

#include <iostream>
using namespace std;

class Deque {
    int front;
    int rear;
    int *arr;
    int size;

public:
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || ((rear + 1) % size == front));
    }

    bool pushFront(int n) {
        if (isFull()) {
            cout << "queue is full" << endl;
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }

        arr[front] = n;
        return true;
    }

    bool pushRear(int n) {
        if (isFull()) {
            cout << "queue is full" << endl;
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = n;
        return true;
    }

    int popFront() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) {    // single element
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }

        return ans;
    }

    int popRear() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }

        return ans;
    }

    int getfront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getrear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};
