// class_04 SerializeAndReconstructTree
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static string serialByPre(TreeNode* head) {
    if (!head) return "#!";
    string res = to_string(head->val) + "!";
    res += serialByPre(head->left);
    res += serialByPre(head->right);
    return res;
}

static void split(const string& src, const char separator,
                  vector<string>& values) {
    values.clear();
    istringstream str(src);
    string tmp;
    while (getline(str, tmp, separator)) values.push_back(tmp);
}

static TreeNode* reconPreOrder(queue<string>& que) {
    string value = que.front();
    que.pop();
    if (value == "#") return NULL;
    TreeNode* head = new TreeNode(stoi(value));
    head->left = reconPreOrder(que);
    head->right = reconPreOrder(que);
    return head;
}

static TreeNode* reconByPreString(string preStr) {
    vector<string> values;
    split(preStr, '!', values);
    queue<string> que;
    for (int i = 0; i < values.size(); i++) que.push(values[i]);
    return reconPreOrder(que);
}

static string serialByLevel(TreeNode* head) {
    if (!head) return "#!";
    string res = to_string(head->val) + "!";
    queue<TreeNode*> que;
    que.push(head);
    while (!que.empty()) {
        head = que.front();
        que.pop();
        if (head->left) {
            res += to_string(head->left->val) + "!";
            que.push(head->left);
        } else
            res += "#!";
        if (head->right) {
            res += to_string(head->right->val) + "!";
            que.push(head->right);
        } else
            res += "#!";
    }
    return res;
}

static TreeNode* generateNodeByString(string val) {
    if (val == "#") return NULL;
    return new TreeNode(stoi(val));
}

static TreeNode* reconByLevelString(string levelStr) {
    vector<string> values;
    split(levelStr, '!', values);
    int index = 0;
    TreeNode* head = generateNodeByString(values[index++]);
    queue<TreeNode*> que;
    if (head) que.push(head);
    TreeNode* node = NULL;
    while (!que.empty()) {
        node = que.front();
        que.pop();
        node->left = generateNodeByString(values[index++]);
        node->right = generateNodeByString(values[index++]);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
    }
    return head;
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
    TreeNode* head = NULL;
    printTree(head);

    string pre = serialByPre(head);
    cout << "serialize tree by pre-order: " << pre << endl;
    head = reconByPreString(pre);
    cout << "reconstruct tree by pre-order, ";
    printTree(head);

    string level = serialByLevel(head);
    cout << "serialize tree by level: " << level << endl;
    head = reconByLevelString(level);
    cout << "reconstruct tree by level, ";
    printTree(head);

    cout << "====================================" << endl;

    head = new TreeNode(1);
    printTree(head);

    pre = serialByPre(head);
    cout << "serialize tree by pre-order: " << pre << endl;
    head = reconByPreString(pre);
    cout << "reconstruct tree by pre-order, ";
    printTree(head);

    level = serialByLevel(head);
    cout << "serialize tree by level: " << level << endl;
    head = reconByLevelString(level);
    cout << "reconstruct tree by level, ";
    printTree(head);

    cout << "====================================" << endl;

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->right->right = new TreeNode(5);
    printTree(head);

    pre = serialByPre(head);
    cout << "serialize tree by pre-order: " << pre << endl;
    head = reconByPreString(pre);
    cout << "reconstruct tree by pre-order, ";
    printTree(head);

    level = serialByLevel(head);
    cout << "serialize tree by level: " << level << endl;
    head = reconByLevelString(level);
    cout << "reconstruct tree by level, ";
    printTree(head);

    cout << "====================================" << endl;

    head = new TreeNode(100);
    head->left = new TreeNode(21);
    head->left->left = new TreeNode(37);
    head->right = new TreeNode(-42);
    head->right->left = new TreeNode(0);
    head->right->right = new TreeNode(666);
    printTree(head);

    pre = serialByPre(head);
    cout << "serialize tree by pre-order: " << pre << endl;
    head = reconByPreString(pre);
    cout << "reconstruct tree by pre-order, ";
    printTree(head);

    level = serialByLevel(head);
    cout << "serialize tree by level: " << level << endl;
    head = reconByLevelString(level);
    cout << "reconstruct tree by level, ";
    printTree(head);

    cout << "====================================" << endl;
}