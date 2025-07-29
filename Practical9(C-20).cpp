/*The ticket booking system of Cinemax theater has to be implemented using C++ program. 
There  10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats  at rows. 
Assume some random booking to start with. Use array to store pointers (Head pointer) to each row.  
On demand a) The list of available seats is to be displayed b) The seats are to be booked c) The booking  can be cancelled.*/

#include <iostream> 
#include <stdlib.h> 
using namespace std;

// Node structure for doubly circular linked list
class node {
public:
    node* next;      // Pointer to next node
    node* prev;      // Pointer to previous node
    int seat;        // Seat number
    string id;       // ID of the person who booked the seat
    int status;      // 0 = Available, 1 = Booked
};

// Cinemax class containing the main functionality
class cinemax {
public:
    node* head, *tail, *temp;

    // Constructor to initialize head
    cinemax() {
        head = NULL;
    }

    // Member functions
    void create_list();  // Create 70 seats in a doubly circular linked list
    void display();      // Display all seat statuses
    void book();         // Book a seat
    void cancel();       // Cancel a booking
    void avail();        // Show only available seats
};

// Create 70 seat nodes in circular doubly linked list
void cinemax::create_list() {
    temp = new node;
    temp->seat = 1;
    temp->status = 0;
    temp->id = "null";
    tail = head = temp;

    // Create remaining 69 seats
    for (int i = 2; i <= 70; i++) {
        node *p = new node;
        p->seat = i;
        p->status = 0;
        p->id = "null";
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = head;     // Circular link
        head->prev = tail;
    }
}

// Display current seat status (booked/available)
void cinemax::display() {
    int r = 1;
    node* temp = head;
    int count = 0;

    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "                             Screen this way                                        \n";
    cout << "------------------------------------------------------------------------------------\n";

    while (temp->next != head) {
        if (temp->seat < 10)
            cout << "S0" << temp->seat << " :";
        else
            cout << "S" << temp->seat << " :";

        if (temp->status == 0)
            cout << "|___| ";
        else
            cout << "|_B_| ";  // Booked seat

        count++;
        if (count % 7 == 0)
            cout << endl;

        temp = temp->next;
    }

    // Print last node
    cout << "S" << temp->seat << " :";
    if (temp->status == 0)
        cout << "|___| ";
    else
        cout << "|_B_| ";
}

// Book a seat by entering seat number and user ID
void cinemax::book() {
    int x;
    string y;

label:
    cout << "\nEnter seat number to be booked (1-70): ";
    cin >> x;
    cout << "Enter your ID number: ";
    cin >> y;

    if (x < 1 || x > 70) {
        cout << "Invalid seat number. Try again.\n";
        goto label;
    }

    node* temp = head;
    while (temp->seat != x) {
        temp = temp->next;
    }

    if (temp->status == 1) {
        cout << "Seat already booked!\n";
    } else {
        temp->status = 1;
        temp->id = y;
        cout << "Seat " << x << " booked successfully!\n";
    }
}

// Cancel a booking using seat number and user ID
void cinemax::cancel() {
    int x;
    string y;

label1:
    cout << "Enter seat number to cancel booking (1-70): ";
    cin >> x;
    cout << "Enter your ID: ";
    cin >> y;

    if (x < 1 || x > 70) {
        cout << "Invalid seat number. Try again.\n";
        goto label1;
    }

    node* temp = head;
    while (temp->seat != x) {
        temp = temp->next;
    }

    if (temp->status == 0) {
        cout << "Seat not booked yet!\n";
    } else {
        if (temp->id == y) {
            temp->status = 0;
            temp->id = "null";
            cout << "Booking for seat " << x << " has been cancelled.\n";
        } else {
            cout << "Wrong ID. Cannot cancel booking!\n";
        }
    }
}

// Display only available seats
void cinemax::avail() {
    int count = 0;
    node* temp = head;

    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "                             Screen this way                                        \n";
    cout << "------------------------------------------------------------------------------------\n";

    while (temp->next != head) {
        if (temp->status == 0) {
            if (temp->seat < 10)
                cout << "S0" << temp->seat << " :|___| ";
            else
                cout << "S" << temp->seat << " :|___| ";
            count++;
        } else {
            cout << "               ";
        }

        if (count % 7 == 0)
            cout << endl;

        temp = temp->next;
    }

    // Last node
    if (temp->status == 0) {
        cout << "S" << temp->seat << " :|___| ";
    }
}

// Main function
int main() {
    cinemax obj;
    obj.create_list();  // Create the seat layout

    int ch;
    char c = 'y';

    while (c == 'y' || c == 'Y') {
        obj.display();
        cout << "\n*********************************************\n";
        cout << "               CINEMAX MOVIE THEATRE         \n";
        cout << "*********************************************\n";
        cout << "\nEnter Choice:\n";
        cout << "1. Current Seat Status\n";
        cout << "2. Book a Seat\n";
        cout << "3. View Available Seats\n";
        cout << "4. Cancel a Seat\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: obj.display(); break;
            case 2: obj.book(); break;
            case 3: obj.avail(); break;
            case 4: obj.cancel(); break;
            default: cout << "Invalid choice.\n";
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> c;
    }

    cout << "\nThank you for using CINEMAX Seat Booking System!\n";
    return 0;
}
