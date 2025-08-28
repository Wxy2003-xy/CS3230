#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int idx_map(int zero_idx, int ofst, int n) {
        if (ofst == 0) {
            return zero_idx;
        }
        if (zero_idx + ofst < n) {
            return zero_idx + ofst;
        } else {
            return zero_idx + ofst - n;
        }
    }
    int binary_search(vector<int>& v, int target, int (*map)(int, int, int), int ofst) {
        int n = v.size();
        int init = 0; 
        int end = n - 1;
        while (end >= init) {
            int mid_idx = (init + end) / 2;
            int mid = v[map(mid_idx, ofst, n)];
            if (mid == target) {
                return mid_idx;
            } 
            if (mid > target) {
                end = mid_idx - 1;
            } else {
                init = mid_idx + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        int init = 0; 
        int end = n - 1;
        int curr_min = min(nums[init], nums[end]);
        int stride = n / 2;
        bool to_right = true;
        while (nums[init] > nums[end] && stride > 0) {
            if (to_right) {
                init += stride;
                if (init >= n) {
                    init -= n;
                }
                end += stride;
                if (end >= n) {
                    end -= n;
                }
                stride /= 2;
                if (min(nums[init], nums[end]) < curr_min) {
                    to_right = false;
                    curr_min = min(nums[init], nums[end]);
                }
            } else {
                init -= stride;
                if (init < 0) {
                    init += n;
                }
                end -= stride;
                if (end < 0) {
                    end += n;
                }
                stride /= 2;
                if (min(nums[init], nums[end]) > curr_min) {
                    to_right = true;
                }
            }
        }
        // sorted.
        int sym_idx = binary_search(nums, target, idx_map, init);
        if (sym_idx < 0) {
            return -1;
        } else {
            return idx_map(sym_idx, init, n);
        }
    }
};

int main() {
    vector<int> v = {
    266,267,268,269,271,278,282,292,293,298,
    6,9,15,19,21,26,33,35,37,38,
    39,46,49,54,65,71,74,77,79,82,
    83,88,92,93,94,97,104,108,114,115,
    117,122,123,127,128,129,134,137,141,
    142,144,147,150,154,160,163,166,169,
    172,173,177,180,183,184,188,198,203,208,
    210,214,218,220,223,224,233,236,241,243,253,256,257,262,263};
    int t = 208;
    Solution s;
    cout << s.search(v, t) << endl;
}