#include "Double_Linked_Node.cpp"

template <typename T> class queue {
private:
    Double_Linked_Node<T>* head;
    Double_Linked_Node<T>* tail;
    long long q_size = 0;
public:
    queue() {
        head = new Double_Linked_Node<T>();
        tail = new Double_Linked_Node<T>();
        head->SetNextNode(tail);
        tail->SetPrevNode(head);
    }

    void push(T t) {
        Double_Linked_Node<T>* n = new Double_Linked_Node(t);
        n->SetNextNode(tail);
        tail->GetPrevNode()->SetNextNode(n);
        tail->SetPrevNode(n);
        ++q_size;
    }

    void pop() {
        if(!q_size)
            return;
        --q_size;
        Double_Linked_Node<T>* n = head->GetNextNode();
        if(!q_size)
            n->GetNextNode()->SetPrevNode(head);
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
        return tail->GetPrevNode()->GetValue();
    }

    long long size() { return q_size; }
    bool empty() { return !q_size; }
};
