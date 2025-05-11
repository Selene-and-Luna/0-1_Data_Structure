#include <iostream>

template <typename T> class Single_Linked_Node {
private:
    T value;
    Single_Linked_Node<T>* next;
public:
    Single_Linked_Node() {
        next = nullptr;
    }

    Single_Linked_Node(T t) {
        next = nullptr;
        value = t;
    }

    ~Single_Linked_Node() {

    }

    T GetValue() { return value; }
    Single_Linked_Node<T>* GetNextNode() { return next; }
    void SetValue(T t) { value = t; }
    void SetNextNode(Single_Linked_Node<T>* n) { next = n; }
};