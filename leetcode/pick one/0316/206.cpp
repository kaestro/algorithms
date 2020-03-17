#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reversed_head;
public:
    ListNode* reverseList(ListNode* head) {
        reverseNode(NULL, head);
        return reversed_head;
    }

    void reverseNode(ListNode* prev, ListNode* cur) {
        if (cur->next) {
            reverseNode(cur, cur->next);
        } else {
            reversed_head = cur;
        }
        cur->next = prev;
    }
};

class ans_Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL, *cur = head;
        ListNode* temp;
        while (cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
}

int main() {
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    one->next = two;
    two->next = three;
    three->next = four;

    Solution s;
    s.reverseList(one);

    cout << endl;

    return 0;
}