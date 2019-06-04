// class_03 SmallerEqualBigger
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void arrPartition(vector<ListNode*>& nodeArr, int pivot) {
    int small = -1;
    int big = nodeArr.size();
    int index = 0;
    while (index != big) {
        if (nodeArr[index]->val < pivot)
            swap(nodeArr[++small], nodeArr[index++]);
        else if (nodeArr[index]->val == pivot)
            index++;
        else
            swap(nodeArr[index], nodeArr[--big]);
    }
}

//利用额外数组排好序在链接起来
ListNode* listPartition1(ListNode* head, int pivot) {
    if (!head) return head;
    ListNode* cur = head;
    int i = 0;
    vector<ListNode*> nodeArr;
    while (head) {
        nodeArr.push_back(head);
        head = head->next;
    }
    arrPartition(nodeArr, pivot);
    for (i = 1; i != nodeArr.size(); i++) nodeArr[i - 1]->next = nodeArr[i];
    nodeArr[i - 1]->next = NULL;
    return nodeArr[0];
}

//利用3条链表
ListNode* listPartition2(ListNode* head, int pivot) {
    ListNode* sH = NULL;
    ListNode* sT = NULL;
    ListNode* eH = NULL;
    ListNode* eT = NULL;
    ListNode* bH = NULL;
    ListNode* bT = NULL;
    ListNode* next = NULL;

    while (head) {
        next = head->next;
        head->next = NULL;
        if (head->val < pivot) {
            if (!sH) {
                sH = head;
                sT = head;
            } else {
                sT->next = head;
                sT = head;
            }
        } else if (head->val == pivot) {
            if (!eH) {
                eH = head;
                eT = head;
            } else {
                eT->next = head;
                eT = head;
            }
        } else {
            if (!bH) {
                bH = head;
                bT = head;
            } else {
                bT->next = head;
                bT = head;
            }
        }
        head = next;
    }
    //如果中间部分为空，中间部分尾结点等于小于部分尾结点
    if (sT) {
        sT->next = eH;
        eT = eT == NULL ? sT : eT;
    }
    if (eT) eT->next = bH;
    return sH != NULL ? sH : eH != NULL ? eH : bH;
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
    ListNode* head1 = new ListNode(7);
    head1->next = new ListNode(9);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(8);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(2);
    head1->next->next->next->next->next->next = new ListNode(5);
    printLinkedList(head1);
    // head1 = listPartition1(head1, 5);
    head1 = listPartition2(head1, 5);
    printLinkedList(head1);
}