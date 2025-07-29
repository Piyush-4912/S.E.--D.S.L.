/*Write C++ program for storing appointment schedule for day. Appointments are booked randomly  using linked list. 
Set start and end time and min and max duration for visit slot. Write functions for 
A) Display free slots B) Book appointment C) Sort list based on time D) Cancel appointment ( check validity,  time bounds, availability) E) Sort list based on time using pointer manipulation*/
#include<iostream>
using namespace std;

// Global variable to store the number of slots
int size;

// Define structure for Singly Linked List Node representing an appointment slot
struct SLL_Node {
    int start;      // Start time of the appointment slot
    int end;        // End time of the appointment slot
    int min;        // Minimum duration allowed
    int max;        // Maximum duration allowed
    int flag;       // Status of slot: 0 = Free, 1 = Booked
    struct SLL_Node *next; // Pointer to the next slot
}*head;             // Head pointer of the linked list

// Class for handling appointment scheduling operations
class App_Shedule {
public:
    void create_Shed();     // Create appointment slots
    void display_Shed();    // Display all appointment slots
    void book_App();        // Book an appointment slot
    void cancel_App();      // Cancel a booked appointment
    void sort_App();        // Sort appointments by start time
} A1; // Create a global object A1 of App_Shedule

int main() {
    int ch;
    char ans;

    // Menu-driven loop for user operations
    do {
        cout << "\n\n *** Menu ***";
        cout << "\n 1. Create Appointment Schedule";
        cout << "\n 2. Display Free Slots";
        cout << "\n 3. Book an Appointment";
        cout << "\n 4. Cancel an Appointment";
        cout << "\n 5. Sort slots based on Time";
        cout << "\n\n\t Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1: A1.create_Shed(); break;
            case 2: A1.display_Shed(); break;
            case 3: A1.book_App(); break;
            case 4: A1.cancel_App(); break;
            case 5: A1.sort_App(); break;
            default: cout << "\n\t Wrong choice!!!";
        }

        cout << "\n\n\t Do you want to continue? (y/n) : ";
        cin >> ans;
    } while(ans == 'y');

    return 0;
}

// Function to create appointment schedule
void App_Shedule::create_Shed() {
    int i;
    struct SLL_Node *temp, *last;
    head = NULL;

    cout << "\n\n\t How many Appointment Slots: ";
    cin >> size;

    // Loop to create 'size' number of appointment slots
    for(i = 0; i < size; i++) {
        temp = new(struct SLL_Node);

        // Input appointment slot details
        cout << "\n\n\t Enter Start Time: ";
        cin >> temp->start;
        cout << "\n\t Enter End Time: ";
        cin >> temp->end;
        cout << "\n\n\t Enter Minimum Duration: ";
        cin >> temp->min;
        cout << "\n\t Enter Maximum Duration: ";
        cin >> temp->max;

        temp->flag = 0;       // Set status to free
        temp->next = NULL;

        // Append to linked list
        if(head == NULL) {
            head = temp;
            last = head;
        } else {
            last->next = temp;
            last = last->next;
        }
    }
}

// Function to display the current appointment schedule
void App_Shedule::display_Shed() {
    int cnt = 1;
    struct SLL_Node *temp;
    temp = head;

    cout << "\n\n\t ****Appointment Schedule****";
    cout << "\n\n\t Srno.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus";

    while(temp != NULL) {
        cout << "\n\n\t " << cnt;
        cout << "\t " << temp->start;
        cout << "\t " << temp->end;
        cout << "\t " << temp->min;
        cout << "\t " << temp->max;
        cout << "\t " << (temp->flag ? "-Booked-" : "--Free--");

        temp = temp->next;
        cnt++;
    }
}

// Function to book an appointment slot
void App_Shedule::book_App() {
    int start;
    struct SLL_Node *temp;

    cout << "\n\n\t Please enter Appointment time: ";
    cin >> start;

    temp = head;
    while(temp != NULL) {
        if(start == temp->start) {
            if(temp->flag == 0) {
                cout << "\n\n\t Appointment Slot is Booked!!!";
                temp->flag = 1;
            } else {
                cout << "\n\n\t Appointment Slot is not Available!!!";
            }
            return;
        }
        temp = temp->next;
    }

    cout << "\n\n\t No such time slot found!";
}

// Function to cancel a booked appointment
void App_Shedule::cancel_App() {
    int start;
    struct SLL_Node *temp;

    cout << "\n\n\t Please enter Appointment time to Cancel: ";
    cin >> start;

    temp = head;
    while(temp != NULL) {
        if(start == temp->start) {
            if(temp->flag == 1) {
                cout << "\n\n\t Your Appointment Slot is Canceled!!!";
                temp->flag = 0;
            } else {
                cout << "\n\n\t Your Appointment was not Booked!!!";
            }
            return;
        }
        temp = temp->next;
    }

    cout << "\n\n\t No such time slot found!";
}

// Function to sort appointment slots by their start time
void App_Shedule::sort_App() {
    int i, j, val;
    struct SLL_Node *temp;

    // Simple Bubble Sort based on start time
    for(i = 0; i < size - 1; i++) {
        temp = head;
        while(temp->next != NULL) {
            if(temp->start > temp->next->start) {
                // Swap start time
                val = temp->start;
                temp->start = temp->next->start;
                temp->next->start = val;

                // Swap end time
                val = temp->end;
                temp->end = temp->next->end;
                temp->next->end = val;

                // Swap min duration
                val = temp->min;
                temp->min = temp->next->min;
                temp->next->min = val;

                // Swap max duration
                val = temp->max;
                temp->max = temp->next->max;
                temp->next->max = val;

                // Also swap booking status
                val = temp->flag;
                temp->flag = temp->next->flag;
                temp->next->flag = val;
            }
            temp = temp->next;
        }
    }

    cout << "\n\n\t The Appointments got Sorted!!!";
}
