// class_04 IsBSTAndCBT
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static bool isBST(TreeNode* head) {
    if (!head) return true;
    stack<TreeNode*> tmp;
    int pre = INT_MIN;
    while (!tmp.empty() || head) {
        if (head) {
            tmp.push(head);
            head = head->left;
        } else {
            head = tmp.top();
            tmp.pop();
            if (head->val > pre)
                pre = head->val;
            else
                return false;
            head = head->right;
        }
    }
    return true;
}

static bool isCBT(TreeNode* head) {
    if (!head) return true;
    queue<TreeNode*> que;
    bool leaf = false;
    TreeNode* l = NULL;
    TreeNode* r = NULL;
    que.push(head);
    while (!que.empty()) {
        head = que.front();
        que.pop();
        l = head->left;
        r = head->right;
        //应该是叶节点还有孩子，或有右没左，返回false
        if ((leaf && (l || r)) || (r && !l)) return false;
        //出现有左没右或没左没右，后续的结点都应该是叶节点
        if (l) que.push(l);
        if (r)
            que.push(r);
        else
            leaf = true;
    }
    return true;
}

// for test -- print tree
static string getSpace(int num) {
    string space;
    for (int i = 0; i < num; i++) space.push_back(' ');
    return space;
}

static void printInOrder(TreeNode* head, int height, string to, int len) {
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

static void printTree(TreeNode* head) {
    cout << "Binary Tree:" << endl;
    printInOrder(head, 0, "H", 17);
    cout << endl;
}

int main() {
    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->right = new TreeNode(6);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);
    head->right->left = new TreeNode(5);

    printTree(head);
    cout << isBST(head) << endl;
    cout << isCBT(head) << endl;
}