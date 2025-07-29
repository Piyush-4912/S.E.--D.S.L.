//Write C++ Code to implement queue operations.
#include <iostream>
#define MAX 10
using namespace std;

// Structure to define the queue
struct queue {
    int data[MAX];
    int front, rear;
};

// Queue class with operations
class Queue {
    struct queue q;

public:
    Queue() {
        q.front = q.rear = -1; // Initialize front and rear to -1
    }

    int isempty();           // Check if queue is empty
    int isfull();            // Check if queue is full
    void enqueue(int);      // Insert element into queue
    int delqueue();         // Delete element from queue
    void display();         // Display elements in queue
};

// Check if queue is empty
int Queue::isempty() {
    return (q.front == q.rear) ? 1 : 0;
}

// Check if queue is full
int Queue::isfull() {
    return (q.rear == MAX - 1) ? 1 : 0;
}

// Insert an element into queue
void Queue::enqueue(int x) {
    q.data[++q.rear] = x;
}

// Delete (dequeue) an element from queue
int Queue::delqueue() {
    return q.data[++q.front];
}

// Display elements from front to rear
void Queue::display() {
    cout << "\nQueue elements: ";
    for (int i = q.front + 1; i <= q.rear; i++)
        cout << q.data[i] << " ";
    cout << endl;
}

// Main function
int main() {
    Queue obj;
    int ch, x;

    do {
        cout << "\n\t\t########## MENU ##########\n";
        cout << "1. Insert an element in Queue\n";
        cout << "2. Delete an element from Queue\n";
        cout << "3. Display remaining Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                if (!obj.isfull()) {
                    cout << "\nEnter your element: ";
                    cin >> x;
                    obj.enqueue(x);
                    cout << "Element inserted.\n";
                } else {
                    cout << "\nQueue is overflow!\n";
                }
                break;

            case 2:
                if (!obj.isempty()) {
                    cout << "\nDeleted Element = " << obj.delqueue() << endl;
                } else {
                    cout << "\nQueue is underflow!\n";
                }
                obj.display();
                break;

            case 3:
                if (!obj.isempty()) {
                    obj.display();
                } else {
                    cout << "\nQueue is empty!\n";
                }
                break;

            case 4:
                cout << "\nProgram Terminated Successfully.\n";
                break;

            default:
                cout << "\nInvalid Choice! Try again.\n";
        }
    } while (ch != 4);

    return 0;
}
