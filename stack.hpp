/***************************************************************
  Ayden Petersen
  stack.hpp
  Project 5

  This file contains the declarations and definitions for a stack class
  template and its related functions.

***************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include <vector>
template <typename T>
class Stack{
    std::vector<T> stack;
    public:
    Stack();
    Stack(T node);
    void push(T node);
    void pop();
    T peek() const;
    bool empty() const;
};
    template <typename T>
    Stack<T>::Stack() {}
    template <typename T>
    Stack<T>::Stack(T node) {stack.push_back(node);}

    template <typename T>
    void Stack<T>::push(T node) {stack.push_back(node);}

    template <typename T>
    void Stack<T>::pop() {
        if (stack.size() != 0) {stack.pop_back();}
        return;
    }
    template <typename T>
    bool Stack<T>::empty() const {return (stack.size() == 0);}

    template <typename T>
    T Stack<T>::peek() const {return stack[stack.size()-1];}

#endif
