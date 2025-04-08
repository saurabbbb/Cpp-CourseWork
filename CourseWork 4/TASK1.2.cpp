#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full. Cannot push " << value << ".\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack.\n";
    }

    int pop() {
        if (top < 0) {
            cout << "Stack is empty. Cannot pop.\n";
            return -1;
        }
        return arr[top--];
    }

    void findMiddle() {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return;
        }
        int midIndex = top / 2;
        cout << "Middle element: " << arr[midIndex] << endl;
    }

    void reverseBottomHalf() {
        if (top < 1) {
            cout << "Not enough elements to reverse bottom half.\n";
            return;
        }

        int half = (top + 1) / 2;
        for (int i = 0; i < half / 2; i++) {
            swap(arr[i], arr[half - 1 - i]);
        }
        cout << "Bottom half reversed.\n";
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Find Middle Element\n";
        cout << "4. Reverse Bottom Half\n";
        cout << "5. Display Stack\n";
        cout << "0. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                value = stack.pop();
                if (value != -1)
                    cout << "Popped: " << value << endl;
                break;

            case 3:
                stack.findMiddle();
                break;

            case 4:
                stack.reverseBottomHalf();
                break;

            case 5:
                stack.display();
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
