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
    void merge(vector<int>& nums1, int m, vector<int>& n2, int n) {
        vector<int>::const_iterator init=nums1.begin();
        vector<int>::const_iterator end=nums1.begin()+m;
        vector<int> n1(init,end);
        int p1 = 0;
        int p2 = 0;
        int c=0;
        for (int i =0;i<m+n;i++){
            
        }
    }
};
int main() {
    Solution s;
    vector<int> v = {1,3,5,7,9,0,0,0,0};
    vector<int> b = {2,4,6,8};
    print_vector(v);
    print_vector(b);
    s.merge(v,5,b,4);
    print_vector(v);

}