// class_03 IsPalindromeList

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// need n extra space
bool isPalindrome1(ListNode* head) {
    stack<ListNode*> tmp;
    ListNode* cur = head;
    while (cur) {
        tmp.push(cur);
        cur = cur->next;
    }
    cur = head;
    while (!tmp.empty()) {
        if (cur->val != tmp.top()->val)
            return false;
        else {
            cur = cur->next;
            tmp.pop();
        }
    }
    return true;
}

// need n/2 extra space
bool isPalindrome2(ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    ListNode* right = head->next;
    ListNode* cur = head;
    while (cur->next && cur->next->next) {
        right = right->next;
        cur = cur->next->next;
    }
    stack<ListNode*> tmp;
    while (right) {
        tmp.push(right);
        right = right->next;
    }
    while (!tmp.empty()) {
        if (head->val != tmp.top()->val) return false;
        head = head->next;
        tmp.pop();
    }
    return true;
}

// need O(1) extra space
bool isPalindrome3(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* n1 = head;
    ListNode* n2 = head;
    //找中间节点
    while (n2->next && n2->next->next) {
        n1 = n1->next;
        n2 = n2->next->next;
    }

    n2 = n1->next;
    n1->next = NULL;
    ListNode* n3 = NULL;
    //翻转右半部分链表
    while (n2) {
        n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    n3 = n1;
    n2 = head;
    bool res = true;
    while (n1 && n2) {
        if (n1->val != n2->val) {
            res = false;
            break;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    //复原右半部分
    n1 = n3->next;
    n3->next = NULL;
    while (n1) {
        n2 = n1->next;
        n1->next = n3;
        n3 = n1;
        n1 = n2;
    }
    return res;
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
    ListNode* head = NULL;
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    head->next = new ListNode(1);
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    printLinkedList(head);
    cout << isPalindrome1(head) << " | ";
    cout << isPalindrome2(head) << " | ";
    cout << isPalindrome3(head) << " | " << endl;
    printLinkedList(head);
    cout << "=========================" << endl;
}