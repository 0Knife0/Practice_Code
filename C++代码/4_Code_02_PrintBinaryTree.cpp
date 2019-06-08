// class_04 PrintBinaryTree
#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string getSpace(int num) {
    string space;
    for (int i = 0; i < num; i++) space.push_back(' ');
    return space;
}

void printInOrder(TreeNode* head, int height, string to, int len) {
    if (!head) return;
    printInOrder(head->right, height + 1, "v", len);
    string val = to + to_string(head->val) + to;
    int lenM = val.size();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) + val << endl;
    printInOrder(head->left, height + 1, "^", len);
}

void printTree(TreeNode* head) {
    cout << "Binary Tree:" << endl;
    printInOrder(head, 0, "H", 17);
    cout << endl;
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(-222222222);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(INT_MIN);
    head->right->left = new TreeNode(55555555);
    head->right->right = new TreeNode(66);
    head->left->left->right = new TreeNode(777);
    printTree(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->right->left = new TreeNode(5);
    head->right->right = new TreeNode(6);
    head->left->left->right = new TreeNode(7);
    printTree(head);

    head = new TreeNode(1);
    head->left = new TreeNode(1);
    head->right = new TreeNode(1);
    head->left->left = new TreeNode(1);
    head->right->left = new TreeNode(1);
    head->right->right = new TreeNode(1);
    head->left->left->right = new TreeNode(1);
    printTree(head);
}