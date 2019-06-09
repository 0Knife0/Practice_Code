// class_04 SuccessorNode
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static TreeNode* getLefetMost(TreeNode* head) {
    if (!head) return head;
    while (head->left) {
        head = head->left;
    }
    return head;
}

static TreeNode* getSuccessorNode(TreeNode* head) {
    if (!head) return head;
    //有右孩子，返回右孩子中最左的叶节点
    if (head->right) return getLefetMost(head->right);
    //无右孩子，找父节点，直到父节点为其父节点的左孩子，返回父节点
    else {
        TreeNode* parent = head->parent;
        while (parent && parent->left != head) {
            head = parent;
            parent = head->parent;
        }
        return parent;
    }
}

int main() {
    TreeNode* head = new TreeNode(6);
    head->parent = NULL;
    head->left = new TreeNode(3);
    head->left->parent = head;
    head->left->left = new TreeNode(1);
    head->left->left->parent = head->left;
    head->left->left->right = new TreeNode(2);
    head->left->left->right->parent = head->left->left;
    head->left->right = new TreeNode(4);
    head->left->right->parent = head->left;
    head->left->right->right = new TreeNode(5);
    head->left->right->right->parent = head->left->right;
    head->right = new TreeNode(9);
    head->right->parent = head;
    head->right->left = new TreeNode(8);
    head->right->left->parent = head->right;
    head->right->left->left = new TreeNode(7);
    head->right->left->left->parent = head->right->left;
    head->right->right = new TreeNode(10);
    head->right->right->parent = head->right;

    TreeNode* test = head->left->left;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head->left->left->right;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head->left;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head->left->right;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head->left->right->right;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head->right->left->left;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head->right->left;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head->right;
    cout << test->val << " next: " << getSuccessorNode(test)->val << endl;
    test = head->right->right;  // 10's next is null
    cout << test->val << " next: " << getSuccessorNode(test) << endl;
}