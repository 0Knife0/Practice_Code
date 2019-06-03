// class_03
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printCommonPart(ListNode* head1, ListNode* head2) {
    cout << "Common Part: ";
    while (head1 && head2) {
        if (head1->val < head2->val)
            head1 = head1->next;
        else if (head1->val > head2->val)
            head2 = head2->next;
        else {
            cout << head1->val << " ";
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    cout << endl;
}

void printLinkedList(ListNode* head) {
    cout << "Linked List: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);
    head1->next->next->next = new ListNode(6);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(5);
    head2->next->next->next = new ListNode(7);
    head2->next->next->next->next = new ListNode(8);

    printLinkedList(head1);
    printLinkedList(head2);
    printCommonPart(head1, head2);
}