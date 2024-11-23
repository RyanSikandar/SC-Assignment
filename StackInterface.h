#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template <typename T>
class StackInterface {
public:
    virtual ~StackInterface() {}

    virtual void push(const T& element) = 0;   // Add an element to the stack
    virtual void pop() = 0;                   // Remove the top element
    virtual T top() const = 0;                // Return the top element
    virtual bool isEmpty() const = 0;         // Check if the stack is empty
    virtual size_t size() const = 0;          // Return the stack size
};

#endif // STACK_INTERFACE_H
