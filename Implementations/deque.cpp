#include "Double_Linked_Node.cpp"

template <typename T> class deque {
private:
    Double_Linked_Node<T>* head;
    Double_Linked_Node<T>* tail;
    long long dq_size = 0;
public:
    deque() {
        head = new Double_Linked_Node<T>();
        tail = new Double_Linked_Node<T>();
        head->SetNextNode(tail);
        tail->SetPrevNode(head);
    }

    void push_front(T t) {
        Double_Linked_Node<T>* n = new Double_Linked_Node(t);
        n->SetNextNode(head->GetNextNode());
        n->SetPrevNode(head);
        head->GetNextNode()->SetPrevNode(n);
        head->SetNextNode(n);
        ++dq_size;
    }

    void push_back(T t) {
        Double_Linked_Node<T>* n = new Double_Linked_Node(t);
        n->SetNextNode(tail);
        n->SetPrevNode(tail->GetPrevNode());
        tail->GetPrevNode()->SetNextNode(n);
        tail->SetPrevNode(n);
        ++dq_size;
    }

    void pop_front() {
        if(!dq_size)
            return;
        --dq_size;
        Double_Linked_Node<T>* n = head->GetNextNode();
        n->GetNextNode()->SetPrevNode(head);
        head->SetNextNode(n->GetNextNode());
        delete n;
    }

    void pop_back() {
        if(!dq_size)
            return;
        --dq_size;
        Double_Linked_Node<T>* n = tail->GetPrevNode();
        n->GetPrevNode()->SetNextNode(tail);
        tail->SetPrevNode(n->GetPrevNode());
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
    
    long long size() { return dq_size; }
    bool empty() { return !dq_size; }
};