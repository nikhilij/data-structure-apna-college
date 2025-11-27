#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            if (curr->val == val) {
                prev->next = nextNode;
                delete curr;
            } else {
                prev = curr;
            }
            curr = nextNode;
        }
        ListNode* newhead = dummy->next;
        delete dummy;
        return newhead;
    }
};

// helpers
ListNode* buildList(const vector<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : vals) {
        ListNode* node = new ListNode(v);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

void printList(ListNode* head) {
    bool first = true;
    for (ListNode* p = head; p != nullptr; p = p->next) {
        if (!first) cout << " ";
        cout << p->val;
        first = false;
    }
    cout << "\n";
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // n
    // a1 a2 ... an
    // val
    //
    // Example:
    // 7
    // 1 2 6 3 4 5 6
    // 6

    int n;
    if (!(cin >> n)) return 0;
    vector<int> vals;
    vals.reserve(max(0, n));
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        vals.push_back(x);
    }
    int val;
    cin >> val;

    ListNode* head = buildList(vals);
    Solution sol;
    ListNode* res = sol.removeElements(head, val);

    printList(res);
    deleteList(res);
    return 0;
}