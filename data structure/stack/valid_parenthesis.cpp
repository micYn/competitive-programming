#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 101
char a[MAX_SIZE];
int top = -1;

void push(char ele) {
    if (top <= MAX_SIZE - 1) {
        a[++top] = ele;
    }
    else {
        cout << "Stack is full. Cannot push: " << ele << "\n";
    }
}

char pop() {
    if (top >= 0) {
        char ele = a[top];
        top--;
        return ele;
    }
    else {
        cout << "Stack is empty. Cannot pop.\n";
        return '-1';
    }
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top >= MAX_SIZE;
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')' || open == '[' && open == ']' || open == '{' && open == '}');
}

bool isBalanced(string expression) {
    // Write your code here
    int strlength = expression.length();
    for (int i = 0; i < strlength; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(expression[i]);
        }
        else {
            char ele = pop();
            if(isEmpty()){
                return false;
            }
            if (isMatchingPair(ele, expression[i])) {
                continue;
            }
            else{
                return false;
            }
        }
    }
    return isEmpty() ;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        int n = str.length();
        cout << str << " : ";
        bool ans = isBalanced(str);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}