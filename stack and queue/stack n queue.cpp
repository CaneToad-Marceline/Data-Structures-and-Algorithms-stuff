#include <iostream>

using namespace std;

class Stack {
private:
    int size;
    int topIndex;
    int capacity;
    int *stack;

public:
    Stack(int stackSize) {
        size = 0; // Start with an empty stack
        capacity = stackSize; // Maximum capacity of the stack
        stack = new int[capacity];
        topIndex = -1;
    }

    void push(int value) {
        // Check if the stack is full
        if (size == capacity) {
            cout << "Stack is full. Cannot push.\n";
            return;
        }

        topIndex++;
        stack[topIndex] = value;
        size++;
    }

    void pop() {
        // Check if the stack is empty
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }

        topIndex--;
        size--;
    }

    int top() {
        // Check if the stack is empty
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return -1; // or any other suitable default value
        }

        return stack[topIndex];
    }

    bool isEmpty() {
        return (size == 0);
    }

    int getSize() {
        return size;
    }
};

int main() {
    cout << endl;
    Stack stack(3);

    stack.push(5);
    stack.push(3);
    stack.push(7);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    stack.push(100);

    cout << "Stack size: " << stack.getSize() << endl;

    while (!stack.isEmpty()) {
        stack.pop();
    }
    cout << "Stack size after pop all: " << stack.getSize() << endl;

    return 0;
}

