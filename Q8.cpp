#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int *queue;
    int front, rear;

public:
    CircularQueue(int size) {
        this->size = size;
        queue = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enQueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enQueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        queue[rear] = item;
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot deQueue." << endl;
            return -1;
        }
        int item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return item;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot get Front." << endl;
            return -1;
        }
        return queue[front];
    }

    int Rear() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot get Rear." << endl;
            return -1;
        }
        return queue[rear];
    }
};

int main() {
    CircularQueue cq(5);

    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);

    cout << "Front: " << cq.Front() << endl;  // Output: 1
    cout << "Rear: " << cq.Rear() << endl;    // Output: 3

    cq.deQueue();
    cq.enQueue(4);

    cout << "Front: " << cq.Front() << endl;  // Output: 2
    cout << "Rear: " << cq.Rear() << endl;    // Output: 4

    cq.deQueue();
    cq.deQueue();
    cq.deQueue();

    if (cq.isEmpty()) {
        cout << "Queue is empty." << endl;     // Output: Queue is empty.
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
