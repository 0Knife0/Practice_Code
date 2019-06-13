// class_04 CompleteTreeNodeNumber
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int mostLeftLevel(TreeNode* head, int level) {
    while (head) {
        level++;
        head = head->left;
    }
    return level - 1;
}

//右子树左边界到最后一层，左子树满；没到，右子树满
static int bs(TreeNode* head, int level, int h) {
    if (level == h) return 1;
    if (mostLeftLevel(head->right, level + 1) == h)
        return (1 << (h - level)) + bs(head->right, level + 1, h);
    else
        return (1 << (h - level - 1)) + bs(head->left, level + 1, h);
}

static int nodeNum(TreeNode* head) {
    if (!head) return 0;
    return bs(head, 1, mostLeftLevel(head, 1));
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    cout << nodeNum(head) << endl;
}