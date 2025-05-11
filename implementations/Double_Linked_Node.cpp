#include <iostream>

template <typename T> class Double_Linked_Node {
private:
    T value;
    Double_Linked_Node<T>* prev;
    Double_Linked_Node<T>* next;
public:
    Double_Linked_Node() {
        prev = nullptr;
        next = nullptr;
    }

    Double_Linked_Node(T t) {
        prev = nullptr;
        next = nullptr;
        value = t;
    }

    ~Double_Linked_Node() {

    }

    T GetValue() { return value; }
    Double_Linked_Node<T>* GetPrevNode() { return prev; }
    Double_Linked_Node<T>* GetNextNode() { return next; }
    void SetValue(T t) { value = t; }
    void SetPrevNode(Double_Linked_Node<T>* n) { prev = n; }
    void SetNextNode(Double_Linked_Node<T>* n) { next = n; }
};