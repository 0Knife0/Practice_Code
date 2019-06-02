// class_03 StackAndQueueConvert
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class TwoStacksQueue {
   private:
    stack<int> stackPush;
    stack<int> stackPop;

   public:
    TwoStacksQueue() = default;

    void push(int pushInt) { stackPush.push(pushInt); }

    int pop() {
        if (stackPush.empty() && stackPop.empty())
            throw "Queue is empty!";
        else if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        int top = stackPop.top();
        stackPop.pop();
        return top;
    }

    int peek() {
        if (stackPush.empty() && stackPop.empty())
            throw "Queue is empty!";
        else if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        return stackPop.top();
    }
};

class TwoQueuesStack {
   private:
    queue<int> Queue;
    queue<int> Help;

   public:
    TwoQueuesStack() = default;

    void posh(int pushInt) { Queue.push(pushInt); }

    int pop() {
        if (Queue.empty()) throw "Stack is empty!";
        while (Queue.size() > 1) {
            Help.push(Queue.front());
            Queue.pop();
        }
        int res = Queue.front();
        Queue.pop();
        swap(Queue, Help);
        return res;
    }

    int top() {
        if (Queue.empty()) throw "Stack is empty!";
        while (Queue.size() != 1) {
            Help.push(Queue.front());
            Queue.pop();
        }
        int res = Queue.front();
        Queue.pop();
        Help.push(res);
        swap(Help, Queue);
        return res;
    }
};

int main() {}