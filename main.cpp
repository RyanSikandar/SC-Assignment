#include <iostream>
#include "LinkedListStack.h"

int main() {
    LinkedListStack<int> stack;

    std::cout << "Pushing 10, 20, 30 onto the stack.\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << "\n";
    std::cout << "Stack size: " << stack.size() << "\n";

    std::cout << "Popping the top element.\n";
    stack.pop();

    std::cout << "Top element after pop: " << stack.top() << "\n";
    std::cout << "Stack size after pop: " << stack.size() << "\n";

    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n";

    std::cout << "Popping all elements.\n";
    stack.pop();
    stack.pop();

    std::cout << "Is the stack empty now? " << (stack.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
