#include "Single_Linked_Node.cpp"

template <typename T> class stack {
private:
    Single_Linked_Node<T>* head;
    long long s_size = 0;
public:
    stack() {
        head = new Single_Linked_Node<T>();
    }

    void push(T t) {
        Single_Linked_Node<T>* n = new Single_Linked_Node(t);
        if(s_size)
            n->SetNextNode(head->GetNextNode());
        head->SetNextNode(n);
        ++s_size;
    }

    void pop() {
        if(!s_size)
            return;
        --s_size;
        Single_Linked_Node<T>* n = head->GetNextNode();
        if(s_size)
            head->SetNextNode(n->GetNextNode());
        delete n;
    }

    T top() {
        if(empty())
            throw std::exception();
        return head->GetNextNode()->GetValue();
    }

    long long size() { return s_size; }
    bool empty() { return !s_size; }
};