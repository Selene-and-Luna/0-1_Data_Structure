#include "Single_Linked_Node.cpp"

template <typename T> class queue {
private:
    Single_Linked_Node<T>* head;
    Single_Linked_Node<T>* tail;
    long long q_size = 0;
public:
    queue() {
        head = new Single_Linked_Node<T>();
        tail = new Single_Linked_Node<T>();
        head->SetNextNode(tail);
        tail->SetNextNode(head);
    }

    void push(T t) {
        Single_Linked_Node<T>* n = new Single_Linked_Node(t);
        if(!q_size)
            head->SetNextNode(n);
        tail->GetNextNode()->SetNextNode(n);
        tail->SetNextNode(n);
        ++q_size;
    }

    void pop() {
        if(!q_size)
            return;
        --q_size;
        Single_Linked_Node<T>* n = head->GetNextNode();
        if(!q_size)
            tail->SetNextNode(head);
        head->SetNextNode(n->GetNextNode());
        delete n;
    }

    T front() {
        if(empty())
            throw std::exception();
        return head->GetNextNode()->GetValue();
    }

    T back() {
        if(empty())
            throw std::exception();
        return tail->GetNextNode()->GetValue();
    }

    long long size() { return q_size; }
    bool empty() { return !q_size; }
};
