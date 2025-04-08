#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int value) {
        if (size == MAX_SIZE) {
            cout << "Queue Overflow! Cannot enqueue " << value << ".\n";
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        size++;
        cout << value << " enqueued.\n";
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return val;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % MAX_SIZE;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    void reverseFirstK(int k) {
        if (k > size || k < 0) {
            cout << "Invalid K value.\n";
            return;
        }

        // Copy first K elements to temp stack
        int stack[MAX_SIZE], top = -1;
        for (int i = 0; i < k; i++) {
            int idx = (front + i) % MAX_SIZE;
            stack[++top] = arr[idx];
        }

        // Put them back in reverse
        for (int i = 0; i < k; i++) {
            int idx = (front + i) % MAX_SIZE;
            arr[idx] = stack[top--];
        }

        cout << "First " << k << " elements reversed.\n";
    }

    void interleaveHalves() {
        if (size % 2 != 0) {
            cout << "Interleaving requires even number of elements.\n";
            return;
        }

        int mid = size / 2;
        int temp[MAX_SIZE];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[(front + i) % MAX_SIZE];
        }

        int index = 0;
        for (int i = 0; i < mid; i++) {
            arr[index++] = temp[i];
            arr[index++] = temp[i + mid];
        }

        front = 0;
        rear = size - 1;

        cout << "Halves interleaved.\n";
    }
};

int main() {
    Queue q;
    int choice, value, k;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Reverse First K Elements\n";
        cout << "4. Interleave First and Second Halves\n";
        cout << "5. Display Queue\n";
        cout << "0. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                value = q.dequeue();
                if (value != -1)
                    cout << "Dequeued: " << value << endl;
                break;

            case 3:
                cout << "Enter K: ";
                cin >> k;
                q.reverseFirstK(k);
                break;

            case 4:
                q.interleaveHalves();
                break;

            case 5:
                q.display();
                break;

            case 0:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
