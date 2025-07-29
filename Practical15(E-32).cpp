/*Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. 
Write C++ program to simulate the system using circular queue using array*/
#include <iostream>
using namespace std;

const int MAX = 5;  // Maximum number of orders allowed in queue

// PizzaParlour class simulates order management using Circular Queue
class PizzaParlour {
    int front, rear;
    int orders[MAX];

public:
    PizzaParlour() {
        front = rear = -1;  // Queue is initially empty
    }

    bool addOrder(int id);   // Function to accept new order
    void serveOrder();       // Function to serve order (FIFO)
    void display();          // Display current orders
};

// Function to add new order to circular queue
bool PizzaParlour::addOrder(int id) {
    if (rear == -1) {  // First order
        front = rear = 0;
        orders[rear] = id;
        return true;
    } else {
        int pos = (rear + 1) % MAX;
        if (pos == front) {
            cout << "\n!!! Please wait. Cafe is Full !!!\n";
            return false;  // Queue is full
        } else {
            rear = pos;
            orders[rear] = id;
            return true;
        }
    }
}

// Function to serve (remove) order from front of the queue
void PizzaParlour::serveOrder() {
    if (front == -1) {
        cout << "\n!!! No Orders in Cafe. Cafe is Empty !!!\n";
        return;
    }

    cout << "\nOrder No. " << orders[front] << " is processed.\n";

    if (front == rear) {
        // Only one order was present
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to display current orders in the queue
void PizzaParlour::display() {
    if (front == -1) {
        cout << "\nCafe is Empty. No orders.\n";
        return;
    }

    cout << "Order IDs: ";
    int i = front;
    while (i != rear) {
        cout << orders[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << orders[rear] << endl;  // Print last element
}

// Main function with menu
int main() {
    int ch;
    int id = 1000;  // Order ID starts from 1001
    PizzaParlour q;

    do {
        cout << "\n----------------------------------------";
        cout << "\n********** M E N U **********\n";
        cout << "1. Accept order\n";
        cout << "2. Serve order\n";
        cout << "3. Display orders\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                id++;
                if (q.addOrder(id)) {
                    cout << "Thank you for your order. Order ID is: " << id << endl;
                } else {
                    id--;  // Rollback ID if not inserted
                }
                break;

            case 2:
                q.serveOrder();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "\n~~~~~~~ Thank You. Keep Visiting. ~~~~~~~~~\n";
                break;

            default:
                cout << "\n!!! Invalid Choice. Try Again !!!\n";
        }

    } while (ch != 4);

    return 0;
}
