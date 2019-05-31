// class_03 Array_To_Stack_Queue
#include <iostream>
#include <vector>

using namespace std;

//使用数组实现栈
class ArrayStack {
   private:
    int *arr;
    int size;

   public:
    ArrayStack(int initSize) {
        if (initSize < 0) throw "The init size is less than 0";
        arr = new int[initSize];
        size = 0;
    }

    ~ArrayStack() { delete arr; }

    int peek() {
        if (size == 0) return NULL;
        return arr[size - 1];
    }

    void push(int obj) {
        if (size == sizeof(arr) / sizeof(arr[0])) throw "The queue is full";
        arr[size++] = obj;
    }

    int pop() {
        if (size == 0) throw "The queue is empty";
        return arr[--size];
    }
};

//使用数组实现队列
class ArrayQueue {
   private:
    int *arr;
    int size;
    int first;
    int last;

   public:
    ArrayQueue(int initSize) {
        if (initSize < 0) throw "The init size is less than 0";
        arr = new int[initSize];
        size = 0;
        first = 0;
        last = 0;
    }

    int peek() {
        if (size == 0) return NULL;
        return arr[first];
    }

    void push(int obj) {
        if (size == sizeof(arr) / sizeof(arr[0])) throw "The queue is full";
        size++;
        arr[last] = obj;
        last = last == sizeof(arr) / sizeof(arr[0]) - 1 ? 0 : last + 1;
    }

    int poll() {
        if (size == 0) throw "The queue is empty";
        size--;
        int tmp = first;
        first = first == sizeof(arr) / sizeof(arr[0]) - 1 ? 0 : first + 1;
        return arr[tmp];
    }
};

int main() {}