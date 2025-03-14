#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {} 
};

// Linked List class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {} 

    // Append an element to the end of the list
    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Search for an element and print its position (0-based index)
    void search(int x) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == x) {
                cout << index << "\n";
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "NO\n";
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = NULL; // Thay nullptr b?ng NULL
        Node* current = head;
        Node* next = NULL; // Thay nullptr b?ng NULL
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Print the linked list
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "append") {
            int x;
            cin >> x;
            list.append(x);
        } else if (command == "search") {
            int x;
            cin >> x;
            list.search(x);
        } else if (command == "reverse") {
            list.reverse();
        }
    }
    
    list.print();
    return 0;
}

