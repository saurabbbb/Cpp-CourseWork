#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    Node* reverseGroup(Node* head, int k) {
        if (!head || k <= 1) return head;
        Node *prev = nullptr, *curr = head, *next = nullptr;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next) head->next = reverseGroup(next, k);
        return prev;
    }

    void removeLoop(Node* loopNode) {
        Node* ptr1 = head;
        while (ptr1->next != loopNode->next) {
            ptr1 = ptr1->next;
            loopNode = loopNode->next;
        }
        loopNode->next = nullptr;
    }

public:
    LinkedList() : head(nullptr) {}

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the start.\n";
    }

    void insertAtEnd(int val) {
        if (!head) {
            head = new Node(val);
            cout << "Inserted " << val << " at the end.\n";
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = new Node(val);
        cout << "Inserted " << val << " at the end.\n";
    }

    void insertAtPosition(int val, int pos) {
        if (pos == 1) { insertAtStart(val); return; }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
        if (temp) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << " at position " << pos << ".\n";
        } else {
            cout << "Position out of bounds.\n";
        }
    }

    void detectAndRemoveLoop() {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                removeLoop(slow);
                cout << "Loop detected and removed.\n";
                return;
            }
        }
        cout << "No loop detected.\n";
    }

    void findNthFromEnd(int n) {
        Node *first = head, *second = head;
        for (int i = 0; i < n; i++) if (!first) { cout << "N is larger than the list size.\n"; return; }
        while (first) { first = first->next; second = second->next; }
        cout << "The " << n << "th node from the end is: " << second->data << endl;
    }

    void reverseInGroupsK(int k) {
        head = reverseGroup(head, k);
        cout << "Reversed list in groups of " << k << ".\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List: ";
        for (Node* temp = head; temp; temp = temp->next) cout << temp->data << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, pos, k;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Start\n2. Insert at End\n3. Insert at Position\n4. Detect & Remove Loop\n5. Find Nth Node from End\n6. Reverse in Groups of K\n7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtStart(val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                list.insertAtPosition(val, pos);
                break;
            case 4:
                list.detectAndRemoveLoop();
                break;
            case 5:
                cout << "Enter N (position from the end): ";
                cin >> pos;
                list.findNthFromEnd(pos);
                break;
            case 6:
                cout << "Enter K (group size for reverse): ";
                cin >> k;
                list.reverseInGroupsK(k);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
