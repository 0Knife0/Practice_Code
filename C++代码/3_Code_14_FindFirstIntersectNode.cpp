// class_03 FindFirstIntersectNode
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getLoopNode(ListNode* head) {
    if (!head || !head->next || !head->next->next) return NULL;
    ListNode* n1 = head->next;
    ListNode* n2 = head->next->next;
    //检查是否有环
    while (n1 != n2) {
        if (!n2->next || !n2->next->next) return NULL;
        n1 = n1->next;
        n2 = n2->next->next;
    }
    //有环，快指针返回头部，再次相遇即入口
    n2 = head;
    while (n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}

ListNode* noLoop(ListNode* head1, ListNode* head2) {
    if (!head1 || !head2) return NULL;
    ListNode* cur1 = head1;
    ListNode* cur2 = head2;
    int n = 0;
    while (cur1) {
        cur1 = cur1->next;
        n++;
    }
    while (cur2) {
        cur2 = cur2->next;
        n--;
    }
    if (cur1 != cur2) return NULL;
    cur1 = n > 0 ? head1 : head2;
    cur2 = cur1 == head1 ? head2 : head1;
    n = abs(n);
    while (n != 0) {
        n--;
        cur1 = cur1->next;
    }
    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

ListNode* bothLoop(ListNode* head1, ListNode* loop1, ListNode* head2,
                   ListNode* loop2) {
    ListNode* cur1 = NULL;
    ListNode* cur2 = NULL;
    if (loop1 == loop2) {
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while (cur1 != loop1) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2) {
            n--;
            cur2 = cur2->next;
        }
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while (n) {
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    } else {
        cur1 = loop1->next;
        while (cur1 != loop1) {
            if (cur1 == loop2) return loop1;
            cur1 = cur1->next;
        }
        return NULL;
    }
}

ListNode* getIntersectNode(ListNode* head1, ListNode* head2) {
    if (!head1 || !head2) return NULL;
    ListNode* loop1 = getLoopNode(head1);
    ListNode* loop2 = getLoopNode(head2);
    if (!loop1 && !loop2) return noLoop(head1, head2);
    if (loop1 && loop2) return bothLoop(head1, loop1, head2, loop2);
    return NULL;
}

int main() {
    // 1->2->3->4->5->6->7->null
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(6);
    head1->next->next->next->next->next->next = new ListNode(7);

    // 0->9->8->6->7->null
    ListNode* head2 = new ListNode(0);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(8);
    head2->next->next->next = head1->next->next->next->next->next;  // 8->6
    cout << getIntersectNode(head1, head2)->val << endl;

    // 1->2->3->4->5->6->7->4...
    head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(6);
    head1->next->next->next->next->next->next = new ListNode(7);
    head1->next->next->next->next->next->next =
        head1->next->next->next;  // 7->4

    // 0->9->8->2...
    head2 = new ListNode(0);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(8);
    head2->next->next->next = head1->next;  // 8->2
    cout << getIntersectNode(head1, head2)->val << endl;

    // 0->9->8->6->4->5->6..
    head2 = new ListNode(0);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(8);
    head2->next->next->next = head1->next->next->next->next->next;  // 8->6
    cout << getIntersectNode(head1, head2)->val << endl;
}