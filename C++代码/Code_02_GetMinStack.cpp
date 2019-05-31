// class_03 GetMinStack
#include <iostream>
#include <stack>

using namespace std;

class MyStack1 {
   private:
    stack<int> stackData;
    stack<int> stackMin;

   public:
    MyStack1() = default;

    void push(int newNum) {
        if (stackMin.empty())
            stackMin.push(newNum);
        else if (stackMin.top() < newNum)
            stackMin.push(stackMin.top());
        else
            stackMin.push(newNum);
        stackData.push(newNum);
    }

    int pop() {
        if (stackData.empty()) throw "Your stack is empty.";
        int top = stackData.top();
        stackMin.pop();
        stackData.pop();
        return top;
    }

    int getmin() {
        if (stackMin.empty()) throw "Your stack is empty.";
        return stackMin.top();
    }
};

int main() {
    MyStack1 stack1;
    stack1.push(3);
    cout << stack1.getmin() << endl;
    stack1.push(4);
    cout << stack1.getmin() << endl;
    stack1.push(1);
    cout << stack1.getmin() << endl;
    cout << stack1.pop() << endl;
    cout << stack1.getmin() << endl;
}