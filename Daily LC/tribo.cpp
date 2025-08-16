#include <bits/stdc++.h>
using namespace std;

static vector<int> mem = {0, 1, 1};

class Solution {
public:
// iter
    int iter_tribonacci(int n) {
        int first = 0;
        int second = 1;
        int third = 1;
        if (n == 0) {
            return first;
        }
        if (n == 1) {
            return second;
        }
        if (n == 2) {
            return third;
        }
        int res = 0;
        for (int i = 2; i < n; i++) {
            int tmp2 = second;
            int tmp3 = third;
            res = first + second + third;
            first = tmp2;
            second = tmp3;
            third = res;
        }
        return res;
    }
// memo
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        vector<int> mem(n + 1, -1);
        mem[0] = 0;
        mem[1] = 1;
        mem[2] = 1;
        return helper(n, mem);
    }
    int helper(int n, vector<int>& mem){
        if (mem[n] >= 0) {
            return mem[n];
        } else {
            mem[n] = helper(n - 3, mem) + helper(n - 2, mem) + helper(n - 1, mem);
            return mem[n];
        }
    }
};