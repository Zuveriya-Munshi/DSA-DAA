#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums) {
    int last = nums.size() - 1;

    for (int i = nums.size() - 2; i >= 0; i--) {
        if (i + nums[i] >= last) {
            last = i;
        }
    }

    return last <= 0;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    if (canJump(nums)) {
        cout << "true"<< endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
