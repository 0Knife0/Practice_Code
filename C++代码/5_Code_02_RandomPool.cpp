// class_05 RandomPool
#include <iostream>
#include <map>
#include <random>
#include <string>

using namespace std;

class Pool {
   private:
    map<string, int> keyIndexMap;
    map<int, string> indexKeyMap;
    int size = 0;

   public:
    void ins(string key) {
        if (this->keyIndexMap.find(key) == this->keyIndexMap.end()) {
            this->keyIndexMap.insert({key, this->size});
            this->indexKeyMap.insert({this->size++, key});
        }
    }

    void del(string key) {
        if (this->keyIndexMap.find(key) != this->keyIndexMap.end()) {
            int deleteIndex = this->keyIndexMap[key];
            int lastIndex = --this->size;
            string lastKey = this->indexKeyMap[lastIndex];
            this->keyIndexMap.insert({lastKey, deleteIndex});
            this->indexKeyMap.insert({deleteIndex, lastKey});
            this->keyIndexMap.erase(key);
            this->indexKeyMap.erase(lastIndex);
        }
    }

    string getRandom() {
        //使用static，每次函数调用之间会保持住状态
        static uniform_int_distribution<unsigned> u(0, this->size - 1);
        static default_random_engine e;
        if (this->size == 0) return NULL;
        int randomIndex = u(e);
        if (this->indexKeyMap.find(randomIndex) != this->indexKeyMap.end())
            return this->indexKeyMap[randomIndex];
        else
            return NULL;
    }
};

int main() {
    Pool pool;
    pool.ins("zuo");
    pool.ins("cheng");
    pool.ins("yun");
    cout << pool.getRandom() << endl;
    cout << pool.getRandom() << endl;
    cout << pool.getRandom() << endl;
    cout << pool.getRandom() << endl;
    cout << pool.getRandom() << endl;
    cout << pool.getRandom() << endl;
}