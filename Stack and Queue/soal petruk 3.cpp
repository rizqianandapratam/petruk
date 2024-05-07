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

    for (int i = 1; i < N; i += 2) {
        cout << nums[i] << " ";
    }

    return 0;
}

