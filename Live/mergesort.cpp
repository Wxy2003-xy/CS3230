#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int k = lists.size();
//         if (k < 1) {
//             ListNode sentinel = ListNode();
//             return &sentinel;
//         }
//         vector<int> ptrs(k, 0);
//         ListNode res = merge(lists, k);
//         return &res;
//     }

//     ListNode merge(vector<ListNode*>& lists, int k) {
//         int c = 0;
//         for (int i = 0; i < k; i++) {
//             if (lists[c]->val > lists[i]->val) {
//                 c = i;
//             }
//         }
//         int v = lists[c]->val;
//         lists[c] = lists[c]->next;
//         return ListNode(v, &merge(lists, k));
//     }
// };

class Solution {
    public: 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> n1(nums1.begin(), nums1.begin() + m);
        int p1 = 0; 
        int p2 = 0;
        int i = 0;
        while (p1 < n1.size() && p2 < nums2.size()) {
            if (n1[p1] <= nums2[p2]) {
                nums1[i++] = n1[p1++];
            } else {
                nums1[i++] = nums2[p2++];
            }
        }
        while (p1 < m) nums1[i++] = n1[p1++];
        while (p2 < n) nums1[i++] = nums2[p2++];
        return ;
    }
    void merge_noexspace(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* i = new ListNode();
        ListNode* curr = i;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2 ? list2 : nullptr;
        return i->next;
    }
    ListNode* mergeLists(vector<ListNode*>& l) {

    }
};
ListNode* makeList(const vector<int>& v) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int x : v) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

// ----- Main -----
int main() {
    Solution sol;
    // ListNode* a = makeList({1,3,5});
    // ListNode* b = makeList({2,4,6});
    // cout << "Merging [1,3,5] and [2,4,6]:\n";
    // printList(sol.mergeTwoLists(a,b));
    // ListNode* c = makeList({});
    // ListNode* d = makeList({1,2,3});
    // cout << "Merging [] and [1,2,3]:\n";
    // printList(sol.mergeTwoLists(c,d));
    // ListNode* e = makeList({1,1,2,4});
    // ListNode* f = makeList({1,3,3,5});
    // cout << "Merging [1,1,2,4] and [1,3,3,5]:\n";
    // printList(sol.mergeTwoLists(e,f));
    vector<int> m = {1,3,5,0,0,0,0};
    vector<int> n = {2,4,6,8};
    sol.merge(m,3,n,4);
    for (auto i : m) {
        cout << i << ", ";
    }


    return 0;
}