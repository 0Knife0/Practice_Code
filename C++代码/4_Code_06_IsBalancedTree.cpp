// class_04 IsBalancedTree
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Data {
    bool isB;
    int h;
    Data(bool x, int y) : isB(x), h(y) {}
};

//列出可能性，构造返回类型，假设左树返回此类型，右树返回此类型，做判断
static Data* getHeight(TreeNode* head) {
    if (!head) return new Data(true, 0);
    Data* leftData = getHeight(head->left);
    if (!leftData->isB) return new Data(false, 0);
    Data* rightData = getHeight(head->right);
    if (!rightData->isB) return new Data(false, 0);
    if (abs(leftData->h - rightData->h) > 1) return new Data(false, 0);
    return new Data(true, max(leftData->h, rightData->h) + 1);
}

static bool isBalance(TreeNode* head) { return getHeight(head)->isB; }

/* static int getHeight(TreeNode* head, int level, bool& res) {
    if (!head) return level;
    int lH = getHeight(head->left, level + 1, res);
    if (!res) return level;
    int rH = getHeight(head->right, level + 1, res);
    if (!res) return level;
    if (abs(lH - rH) > 1) res = false;
    return max(lH, rH);
}

static bool isBalance(TreeNode* head) {
    bool res = true;
    getHeight(head, 1, res);
    return res;
} */

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);

    cout << isBalance(head) << endl;
}