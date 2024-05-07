#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i < N; ++i) {
        if (nums[i] % 2 != 0) {
            cout << nums[i] << " ";
        }
    }

    return 0;
}

