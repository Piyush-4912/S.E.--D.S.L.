//Write C++ program to check well formedness of parenthesis using stack 
#include <iostream>
using namespace std;

#define size 10  // Define the maximum size of the stack

// Stack class for character stack
class stackexp {
    int top;          // Index of the top element
    char stk[size];   // Stack to store characters

public:
    stackexp() {
        top = -1;     // Stack is initially empty
    }

    void push(char);
    char pop();
    int isfull();
    int isempty();
};

// Push operation
void stackexp::push(char x) {
    if (isfull()) {
        cout << "\nStack Overflow! Cannot push '" << x << "'\n";
    } else {
        stk[++top] = x;
    }
}

// Pop operation
char stackexp::pop() {
    if (isempty()) {
        cout << "\nStack Underflow! Nothing to pop.\n";
        return '\0';  // Return null char if stack is empty
    } else {
        return stk[top--];
    }
}

// Check if stack is full
int stackexp::isfull() {
    return (top == size - 1);
}

// Check if stack is empty
int stackexp::isempty() {
    return (top == -1);
}

// Main function
int main() {
    stackexp s1;
    char exp[20], ch;
    int i = 0;
    
    cout << "\n\t!! Parenthesis Checker..!!!!" << endl;
    cout << "\nEnter the Expression to check whether it is well parenthesized: ";
    cin >> exp;

    // Early check if expression starts with a closing bracket
    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}')) {
        cout << "\nInvalid Expression: Cannot start with a closing bracket.\n";
        return 0;
    }

    // Traverse the expression
    while (exp[i] != '\0') {
        ch = exp[i];
        switch (ch) {
            case '(': case '[': case '{':
                s1.push(ch);  // Push opening brackets
                break;

            case ')':
                if (s1.pop() != '(')
                    goto invalid;
                break;
            case ']':
                if (s1.pop() != '[')
                    goto invalid;
                break;
            case '}':
                if (s1.pop() != '{')
                    goto invalid;
                break;
        }
        i++;
    }

    // If stack is empty, expression is well parenthesized
    if (s1.isempty()) {
        cout << "\nExpression is well parenthesized...\n";
    } else {
    invalid:
        cout << "\nSorry!!! Invalid Expression or not well parenthesized....\n";
    }

    return 0;
}
