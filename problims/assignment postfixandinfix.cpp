#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    node* next;
};

class stack {
    node* top;
public:
    stack() {
        top = NULL;
    }
    ~stack() {
        while (top != NULL) {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    bool isEmpty() {
        return top == NULL;
    }
    void push(int value) {
        node* newnode = new node;
        newnode->data = value;
        newnode->next = top;
        top = newnode;
    }
    int pop() {
        if (top == NULL) {
            cout << "Stack is empty. Nothing to delete." << endl;
            return -1;
        }
        node* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        return value;
    }
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }
    void display() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string exp) {
    stack s;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c == ' ')
            continue;

        
        if (c >= '0' && c <= '9') {
            result += c;
            result += ' ';
        }


        else if (c == '(') {
            s.push(c);
        }

        
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += (char)s.pop();
                result += ' ';
            }
            if (s.isEmpty()) {
                cout << "Mismatched parentheses: missing '('" << endl;
                return "";
            }
            s.pop(); 
        }

        
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                result += (char)s.pop();
                result += ' ';
            }
            s.push(c);
        }

        else {
            cout << "Invalid character: " << c << endl;
            return "";
        }
    }

    
    while (!s.isEmpty()) {
        int top = s.pop();
        if (top == '(') {
            cout << "Mismatched parentheses: missing ')'" << endl;
            return "";
        }
        result += (char)top;
        result += ' ';
    }

    return result;
}

int evaluatePostfix(string exp) {
    stack s;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c == ' ')
            continue;

        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (s.isEmpty()) {
                cout << "Error: missing operand before operator '" << c << "'" << endl;
                return -1;
            }

            int val2 = s.pop();

            if (s.isEmpty()) {
                cout << "Error: missing operand for operator '" << c << "'" << endl;
                return -1;
            }

            int val1 = s.pop();

            if (c == '+') s.push(val1 + val2);
            else if (c == '-') s.push(val1 - val2);
            else if (c == '*') s.push(val1 * val2);
            else if (c == '/') {
                if (val2 == 0) {
                    cout << "Error: division by zero" << endl;
                    return -1;
                }
                s.push(val1 / val2);
            }
        }
        else {
            cout << "Invalid character in postfix expression: " << c << endl;
            return -1;
        }
    }

    if (s.isEmpty()) {
        cout << "Invalid expression" << endl;
        return -1;
    }

    int result = s.pop();

    if (!s.isEmpty()) {
        cout << "Too many operands in expression" << endl;
        return -1;
    }

    return result;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    if (postfix == "") return 0;

    cout << "Postfix: " << postfix << endl;

    int result = evaluatePostfix(postfix);

    if (result != -1) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
