#include <iostream>
#include <stack>
#include <string>

using namespace std;

void check(char completedLine[], int size) {
    stack<char> stack;
    bool flag = true;

    for (int i = 0; i < size; i++) {
        if (completedLine[i] == '(' || completedLine[i] == '[') {
            stack.push(completedLine[i]);
        } 
        else if (completedLine[i] == ')') {
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            } else {
                flag = false;
                break;
            }
        } 
        else if (completedLine[i] == ']') {
            if (!stack.empty() && stack.top() == '[') {
                stack.pop();
            } else {
                flag = false;
                break;
            }
        }
    }

    if (flag && stack.empty()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main() {
    string line;

    while (true) {
        getline(cin, line);

        if (line == ".") {
            break;
        }

        check(&line[0], line.length());
    }

    return 0;
}
