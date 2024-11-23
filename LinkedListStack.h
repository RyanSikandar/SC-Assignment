#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include "StackInterface.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>

/**
 * @class LinkedListStack
 * @brief A stack implementation using a singly linked list.
 * 
 * Implements the StackInterface<T> to provide stack operations
 * such as push, pop, top, isEmpty, and size.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class LinkedListStack : public StackInterface<T> {
private:
    Node<T>* topNode; ///< Pointer to the top node in the stack.
    size_t count;     ///< Number of elements currently in the stack.

public:
    /**
     * @brief Default constructor.
     * Initializes an empty stack.
     */
    LinkedListStack() : topNode(nullptr), count(0) {}

    /**
     * @brief Destructor.
     * Frees all dynamically allocated memory in the stack.
     */
    ~LinkedListStack() {
        while (!isEmpty())
            pop();
    }

    /**
     * @brief Push an element onto the stack.
     * 
     * Adds a new element to the top of the stack.
     * 
     * @param element The element to add to the stack.
     */
    void push(const T& element) override {
        Node<T>* newNode = new Node<T>(element); // Create a new node
        newNode->next = topNode;                // Link new node to the current top
        topNode = newNode;                      // Update topNode to the new node
        ++count;                                // Increment the count
    }

    /**
     * @brief Remove the top element from the stack.
     * 
     * Deletes the top element and adjusts the top pointer.
     * If the stack is empty, an error message is displayed.
     */
    void pop() override {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node<T>* temp = topNode;   // Store the current top node
        topNode = topNode->next;  // Move topNode to the next node
        delete temp;              // Delete the old top node
        --count;                  // Decrement the count
    }

    /**
     * @brief Get the top element of the stack.
     * 
     * Returns the value of the top element without removing it.
     * 
     * @throws std::runtime_error if the stack is empty.
     * @return T The top element of the stack.
     */
    T top() const override {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty. No top element.");
        }
        return topNode->data;
    }

    /**
     * @brief Check if the stack is empty.
     * 
     * @return true if the stack is empty, false otherwise.
     */
    bool isEmpty() const override {
        return topNode == nullptr;
    }

    /**
     * @brief Get the number of elements in the stack.
     * 
     * @return size_t The size of the stack.
     */
    size_t size() const override {
        return count;
    }
};

#endif // LINKED_LIST_STACK_H
