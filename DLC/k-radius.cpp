#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v) {
    cout << "[ ";
    for (auto i : v) {
        cout << i << "  "; 
    }
    cout << "]" << endl;
}

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 2*k) {
            return vector<int>(n, -1);
        }    
        vector<int> res = vector<int>(n,-1);
        res[k] = 0;
        long tmp = res[k];
        for (int i = 0; i <= 2*k; i++) {
            tmp += nums[i];
        }
        res[k] = tmp / (2*k + 1);
        for (int i = k + 1; i <= n - k - 1; i++) {
            tmp = tmp - nums[i - k - 1] + nums[i + k];
            res[i] = tmp / (2*k + 1);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {7,4,3,9,1,8,5,2,6};
    print_vector(s.getAverages(v, 3));

}