#include <iostream>
#include <queue>

using namespace std;

void print_queue(queue<int> q) {
	if (!q.empty()) {
		cout << q.front();
		q.pop();
	}

	while (!q.empty()) {
		cout << " " << q.front();
		q.pop();
	}

	cout << endl;
}

int main() {
	int N, val;
	queue<int> q;
	string command;

	cin >> N;
	while (N--) {
		cin >> command;

		if (command == "push") {
			cin >> val;
			q.push(val);
			print_queue(q);
		} else {
			if (!q.empty()) {
				q.pop();
				print_queue(q);
			}
		}
	}
}
