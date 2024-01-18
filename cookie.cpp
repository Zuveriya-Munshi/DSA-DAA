#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int count = 0;
        int i = 0;
        int j = 0;

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        while (i < s.size() && j < g.size()) {
            if (s[i] >= g[j]) {
                count++;
                i++;
                j++;
            } else {
                i++;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    std::vector<int> g = {1, 2, 3};
    std::vector<int> s = {1, 1};

    int contentChildren = solution.findContentChildren(g, s);

    std::cout << "The maximum number of content children is: " << contentChildren << std::endl;

    return 0;
}

