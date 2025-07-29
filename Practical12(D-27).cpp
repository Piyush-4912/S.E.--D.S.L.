//Write a C++ program for Expression conversion as infix to postfix and its evaluation using stack .
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

// Function to return precedence (weight) of an operator
int getWeight(char ch) {
    switch (ch) {
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;  // For operands
    }
}

// Function to convert infix expression to postfix
void infix2postfix(char infix[], char postfix[], int size) {
    stack<char> s;     // Stack to hold operators
    int i = 0, k = 0;  // i -> index for infix, k -> index for postfix
    char ch;

    while (i < size) {
        ch = infix[i];

        // If opening parenthesis, push to stack
        if (ch == '(') {
            s.push(ch);
        }
        // If closing parenthesis, pop until '(' is found
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix[k++] = s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.pop();  // Remove '(' from stack
            }
        }
        // If operand (not operator), add to postfix
        else if (getWeight(ch) == 0) {
            postfix[k++] = ch;
        }
        // If operator
        else {
            // Pop operators with higher or equal precedence
            while (!s.empty() && s.top() != '(' &&
                   getWeight(ch) <= getWeight(s.top())) {
                postfix[k++] = s.top();
                s.pop();
            }
            s.push(ch);
        }

        i++;
    }

    // Pop any remaining operators from stack
    while (!s.empty()) {
        postfix[k++] = s.top();
        s.pop();
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
}

// Main function
int main() {
    char infix[100];
    cout << "\nEnter Infix Expression to Convert into Postfix: ";
    cin >> infix;

    int size = strlen(infix);
    char postfix[size + 1];  // +1 for null terminator

    infix2postfix(infix, postfix, size);

    cout << "\nYour Infix Expression   :: " << infix;
    cout << "\nYour Postfix Expression :: " << postfix << endl;

    return 0;
}
