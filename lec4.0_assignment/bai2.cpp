#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int value, priority;
    Node* next;
    Node* prev;
    Node(int v, int p) : value(v), priority(p), next(NULL), prev(NULL) {}
};

// Priority Queue using Doubly Linked List
class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() : head(NULL) {}
    
    // Enqueue operation: insert based on priority
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (!head || priority > head->priority) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next && temp->next->priority >= priority) {
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    // Dequeue operation: remove highest priority element
    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }
    
    // Print queue elements
    void printQueue() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->value << ", " << temp->priority << ")";
            if (temp->next) cout << "; ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;
    
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }
    
    pq.printQueue();
    return 0;
}

