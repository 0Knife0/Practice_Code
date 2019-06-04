// class_03 CopyListWithRandom
#include <iostream>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* rand;
    ListNode(int x) : val(x), next(NULL), rand(NULL) {}
};

ListNode* copyListWithRand1(ListNode* head) {
    map<ListNode*, ListNode*> tmp;
    ListNode* cur = head;
    while (cur) {
        tmp[cur] = new ListNode(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        tmp[cur]->next = tmp[cur->next];
        tmp[cur]->rand = tmp[cur->rand];
        cur = cur->next;
    }
    return tmp[head];
}

ListNode* copyListWithRand2(ListNode* head) {
    if (!head) return NULL;
    ListNode* cur = head;
    ListNode* next = NULL;
    //将拷贝节点连接到原节点后面
    while (cur) {
        next = cur->next;
        cur->next = new ListNode(cur->val);
        cur->next->next = next;
        cur = next;
    }
    cur = head;
    //设置拷贝节点的rand指针
    ListNode* curCopy = NULL;
    while (cur) {
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand != NULL ? cur->rand->next : NULL;
        cur = next;
    }
    ListNode* res = head->next;
    cur = head;
    //把拷贝节点串起来
    while (cur) {
        next = cur->next->next;
        curCopy = cur->next;
        cur->next = next;
        curCopy->next = next != NULL ? next->next : NULL;
        cur = next;
    }
    return res;
}

void printRandLinkedList(ListNode* head) {
    ListNode* cur = head;
    cout << "order: ";
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    cur = head;
    cout << "rand:  ";
    while (cur) {
        if (cur->rand)
            cout << cur->rand->val << " ";
        else
            cout << "- ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;
    ListNode* res1 = NULL;
    ListNode* res2 = NULL;
    printRandLinkedList(head);
    res1 = copyListWithRand1(head);
    printRandLinkedList(res1);
    // res2 = copyListWithRand2(head);
    printRandLinkedList(res2);
    printRandLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    head->rand = head->next->next->next->next->next;        // 1->6
    head->next->rand = head->next->next->next->next->next;  // 2->6
    head->next->next->rand = head->next->next->next->next;  // 2->5
    head->next->next->next->rand = head->next->next;        // 4->3
    head->next->next->next->next->rand = NULL;              // 5->NULL
    head->next->next->next->next->next->rand = head->next->next->next;  // 6->4

    printRandLinkedList(head);
    res1 = copyListWithRand1(head);
    printRandLinkedList(res1);
    res2 = copyListWithRand2(head);
    printRandLinkedList(res2);
    printRandLinkedList(head);
    cout << "=========================" << endl;
}