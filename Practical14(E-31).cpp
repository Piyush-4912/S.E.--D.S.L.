//Write C++ Code to implement Dequeue operations.
#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of deque

// Class for Deque (Double Ended Queue)
class dequeue {
    int a[SIZE];       // Array to hold elements
    int front, rear;   // Indices for front and rear
    int count;         // Total number of elements

public:
    dequeue();                  // Constructor
    void add_at_beg(int);       // Insert at beginning
    void add_at_end(int);       // Insert at end
    void delete_fr_front();     // Delete from front
    void delete_fr_rear();      // Delete from rear
    void display();             // Display queue
};

// Constructor initializes front, rear, count
dequeue::dequeue() {
    front = -1;
    rear = -1;
    count = 0;
}

// Insert element at the beginning of the deque
void dequeue::add_at_beg(int item) {
    int i;

    if (front == -1) {  // First element insertion
        front++;
        rear++;
        a[rear] = item;
        count++;
    } else if (rear >= SIZE - 1) {  // Check for overflow
        cout << "\nInsertion is not possible, overflow!!!!";
    } else {
        // Shift elements right to make space at the beginning
        for (i = count; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = item;
        count++;
        rear++;
    }
}

// Insert element at the end of the deque
void dequeue::add_at_end(int item) {
    if (front == -1) {  // First element
        front++;
        rear++;
        a[rear] = item;
        count++;
    } else if (rear >= SIZE - 1) {  // Overflow check
        cout << "\nInsertion is not possible, overflow!!!";
    } else {
        a[++rear] = item;
        count++;
    }
}

// Display all elements of deque
void dequeue::display() {
    if (front == -1) {
        cout << "\nDeque is empty!";
        return;
    }

    cout << "\nDeque contains: ";
    for (int i = front; i <= rear; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Delete element from front of deque
void dequeue::delete_fr_front() {
    if (front == -1) {
        cout << "\nDeletion is not possible: Deque is empty";
        return;
    }

    cout << "\nThe deleted element is: " << a[front];

    if (front == rear) {  // Only one element
        front = rear = -1;
    } else {
        front++;
    }
    count--;
}

// Delete element from rear of deque
void dequeue::delete_fr_rear() {
    if (front == -1) {
        cout << "\nDeletion is not possible: Deque is empty";
        return;
    }

    cout << "\nThe deleted element is: " << a[rear];

    if (front == rear) {  // Only one element
        front = rear = -1;
    } else {
        rear--;
    }
    count--;
}

// Main function with menu
int main() {
    int choice, item;
    dequeue d1;

    do {
        cout << "\n\n########## DEQUE OPERATIONS ##########\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Display Deque\n";
        cout << "4. Delete element from front\n";
        cout << "5. Delete element from rear\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> item;
                d1.add_at_beg(item);
                break;

            case 2:
                cout << "Enter element to insert at end: ";
                cin >> item;
                d1.add_at_end(item);
                break;

            case 3:
                d1.display();
                break;

            case 4:
                d1.delete_fr_front();
                break;

            case 5:
                d1.delete_fr_rear();
                break;

            case 6:
                cout << "\n!!! PROGRAM TERMINATED SUCCESSFULLY !!!\n";
                break;

            default:
                cout << "\n!!! INVALID CHOICE !!!\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
