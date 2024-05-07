#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); 

    stack<int> s;

    for (int i = 0; i < N; ++i) {
        string command;
        getline(cin, command);

        stringstream ss(command);
        string cmd;
        ss >> cmd;

        if (cmd == "push") {
            int num;
            ss >> num;
            s.push(num);
        } else if (cmd == "pop") {
            if (!s.empty()) {
                s.pop();
            }
        }

        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    return 0;
}


