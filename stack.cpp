#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;           // Pointer to dynamically allocated array
    int top;          // Index of the top element
    int capacity;     // Maximum capacity of the stack

public:
    // Constructor to initialize stack
    Stack(int size = 10) {
        capacity = size;
        arr = new T[capacity];  // Allocate memory for the stack array
        top = -1;               // Initialize top to -1 (indicating stack is empty)
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(const T& value) {
        if (top == capacity - 1) {  // Check if the stack is full
            cout << "Stack overflow! Unable to push " << value << endl;
            return;
        }
        arr[++top] = value;  // Increment top and add the element
    }

    // Function to remove and return the top element from the stack
    T pop() {
        if (top == -1) {  // Check if the stack is empty
            throw runtime_error("Stack underflow! Cannot pop from an empty stack.");
        }
        return arr[top--];  // Return the top element and decrement top
    }

    // Function to return the top element without removing it
    T peek() const {
        if (top == -1) {  // Check if the stack is empty
            throw runtime_error("Stack is empty! Cannot peek.");
        }
        return arr[top];  // Return the top element
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;  // If top is -1, the stack is empty
    }

    // Function to check if the stack is full
    bool isFull() const {
        return top == capacity - 1;  // If top is at the last index, the stack is full
    }

    // Function to get the current size of the stack
    int size() const {
        return top + 1;  // Size is the index of the top + 1
    }
};

int main() {
    Stack<int> stack(5);  // Create a stack with a capacity of 5

    // Push some elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the top element of the stack
    cout << "Top element is: " << stack.peek() << endl;

    // Pop an element from the stack
    cout << "Popped element is: " << stack.pop() << endl;

    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Push more elements to test overflow
    stack.push(40);
    stack.push(50);
    stack.push(60);  // This will cause an overflow since the stack can hold only 5 elements

    // Display the size of the stack
    cout << "Current stack size: " << stack.size() << endl;

    // Pop all elements from the stack
    while (!stack.isEmpty()) {
        cout << "Popped element: " << stack.pop() << endl;
    }

    // Try to pop from an empty stack (will throw an exception)
    try {
        stack.pop();
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
