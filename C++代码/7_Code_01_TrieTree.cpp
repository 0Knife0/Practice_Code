// class_07 TrieTree
#include <iostream>
#include <string>

using namespace std;

class TrieNode {
   public:
    int path;             //节点被经过几次
    int end;              //以该节点结尾的数量
    TrieNode* nexts[26];  // 26个字母，还可以使用map实现

    TrieNode() {
        path = 0;
        end = 0;
        for (int i = 0; i < 26; i++) nexts[i] = NULL;
    }
};

class TrieTree {
   private:
    TrieNode* root;

   public:
    TrieTree() { root = new TrieNode(); }
    ~TrieTree() { delete root; }

    void insert(string word) {
        if (word.empty()) return;
        TrieNode* node = root;
        int index = 0;
        for (int i = 0; i < word.size(); i++) {
            index = word[i] - 'a';
            if (node->nexts[index] == NULL) node->nexts[index] = new TrieNode();
            node = node->nexts[index];
            node->path++;
        }
        node->end++;
    }

    int search(string word) {
        if (word.empty()) return 0;
        TrieNode* node = root;
        int index = 0;
        for (int i = 0; i < word.size(); i++) {
            index = word[i] - 'a';
            if (node->nexts[index] == NULL) return 0;
            node = node->nexts[index];
        }
        return node->end;
    }

    void del(string word) {
        if (search(word) != 0) {
            TrieNode* node = root;
            int index = 0;
            for (int i = 0; i < word.size(); i++) {
                index = word[i] - 'a';
                if (--node->nexts[index]->path == 0) {
                    node->nexts[index] = NULL;
                    return;
                }
                node = node->nexts[index];
            }
            node->end--;
        }
    }

    int prefixNumber(string pre) {
        if (pre.empty()) return 0;
        TrieNode* node = root;
        int index = 0;
        for (int i = 0; i < pre.size(); i++) {
            index = pre[i] - 'a';
            if (node->nexts[index] == NULL) return 0;
            node = node->nexts[index];
        }
        return node->path;
    }
};

int main() {
    TrieTree* trie = new TrieTree();
    cout << trie->search("zuo") << endl;
    trie->insert("zuo");
    cout << trie->search("zuo") << endl;
    trie->del("zuo");
    cout << trie->search("zuo") << endl;
    trie->insert("zuo");
    trie->insert("zuo");
    trie->del("zuo");
    cout << trie->search("zuo") << endl;
    trie->del("zuo");
    cout << trie->search("zuo") << endl;
    trie->insert("zuoa");
    trie->insert("zuoac");
    trie->insert("zuoab");
    trie->insert("zuoad");
    trie->del("zuoa");
    cout << trie->search("zuoa") << endl;
    cout << trie->prefixNumber("zuo") << endl;
}