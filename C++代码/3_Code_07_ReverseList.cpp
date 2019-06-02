// class_03 ReverseList

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

struct DoubleNode {
    int val;
    DoubleNode* last;
    DoubleNode* next;
    DoubleNode(int x) : val(x), last(NULL), next(NULL) {}
};

DoubleNode* reverseList(DoubleNode* head) {
    DoubleNode* pre = NULL;
    DoubleNode* next = NULL;
    while (head != NULL) {
        next = head->next;
        head->last = next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

void printLinkedList(ListNode* head) {
    cout << "Linked List: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void printDoubleLinkedList(DoubleNode* head) {
    cout << "Double Linked List: ";
    DoubleNode* end = NULL;
    while (head) {
        cout << head->val << " ";
        end = head;
        head = head->next;
    }
    cout << "| ";
    while (end) {
        cout << end->val << " ";
        end = end->last;
    }
    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    printLinkedList(head1);
    head1 = reverseList(head1);
    printLinkedList(head1);

    DoubleNode* head2 = new DoubleNode(1);
    head2->next = new DoubleNode(2);
    head2->next->last = head2;
    head2->next->next = new DoubleNode(3);
    head2->next->next->last = head2->next;
    head2->next->next->next = new DoubleNode(4);
    head2->next->next->next->last = head2->next->next;
    printDoubleLinkedList(head2);
    printDoubleLinkedList(reverseList(head2));
}