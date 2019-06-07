// class_04 PreInPosTraversal
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrderRecur(TreeNode* head) {
    if (!head) return;
    cout << head->val << " ";
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}

void inOrderRecur(TreeNode* head) {
    if (!head) return;
    preOrderRecur(head->left);
    cout << head->val << " ";
    preOrderRecur(head->right);
}

void posOrderRecur(TreeNode* head) {
    if (!head) return;
    preOrderRecur(head->left);
    preOrderRecur(head->right);
    cout << head->val << " ";
}

void preOrderUnRecur(TreeNode* head) {
    cout << "pre-order: ";
    if (head) {
        stack<TreeNode*> tmp;
        tmp.push(head);
        while (!tmp.empty()) {
            head = tmp.top();
            tmp.pop();
            cout << head->val << " ";
            if (head->left) tmp.push(head->left);
            if (head->right) tmp.push(head->right);
        }
    }
    cout << endl;
}

void inOrderUnRecur(TreeNode* head) {
    cout << "in-order: ";
    if (head) {
        stack<TreeNode*> tmp;
        while (!tmp.empty() || head) {
            if (head) {
                tmp.push(head);
                head = head->left;
            } else {
                head = tmp.top();
                tmp.pop();
                cout << head->val << " ";
                head = head->right;
            }
        }
    }
    cout << endl;
}

void posOrderUnRecur(TreeNode* head) {
    cout << "pos-order: ";
    if (head) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(head);
        while (!s1.empty()) {
            head = s1.top();
            s1.pop();
            s2.push(head);
            if (head->right) s1.push(head->right);
            if (head->left) s1.push(head->left);
        }
        while (!s2.empty()) {
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }
    cout << endl;
}

int main() {
    TreeNode* head = new TreeNode(5);
    head->left = new TreeNode(3);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(2);
    head->left->right = new TreeNode(4);
    head->left->left->left = new TreeNode(1);
    head->right->left = new TreeNode(7);
    head->right->left->left = new TreeNode(6);
    head->right->right = new TreeNode(10);
    head->right->right->left = new TreeNode(9);
    head->right->right->right = new TreeNode(11);

    // recursive
    cout << "==============recursive==============" << endl;
    cout << "pre-order: ";
    preOrderRecur(head);
    cout << endl;
    cout << "in-order: ";
    inOrderRecur(head);
    cout << endl;
    cout << "pos-order: ";
    posOrderRecur(head);
    cout << endl;

    // unrecursive
    cout << "============unrecursive=============" << endl;
    preOrderUnRecur(head);
    inOrderUnRecur(head);
    posOrderUnRecur(head);
}