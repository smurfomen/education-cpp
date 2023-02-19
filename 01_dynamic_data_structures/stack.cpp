#include <iostream>

class List
{
    struct Node {
        char value;
        Node * next;

        Node(int v, Node * n = nullptr) : value(v), next(n)
        { }
    };

    Node * head;
public:
    List() : head(nullptr)
    { }

    void push_front(char c) {
        if(!head)
            head = new Node(c);
        else
        {
            Node * tmp = head;
            head = new Node(c, tmp);
        } 
    }

    void push_back(char c) {
        if(!head)
            head = new Node(c);
        else
        {
            Node * tmp = head;
            while(tmp->next)
                tmp = tmp->next;

            tmp->next = new Node(c);
        }
    }

    char at(int i) {
        if(empty())
            throw std::out_of_range("at::index out of range");

        Node *tmp = head;
        while(i != 0) {
            if(!tmp->next)
                break;

            tmp = tmp->next;
            i--;
        }

        if (i)
            throw std::out_of_range("at::index out of range");

        return tmp->value;
    }

    char pop_front() {
        if(!head)
            throw std::out_of_range("pop_front::list is empty");
        else
        {
            Node * tmp = head;
            head = head->next;
            char c = tmp->value;
            delete tmp;
            return c;
        }
    }

    char pop_back() {
        if(!head)
            throw std::out_of_range("pop_back::list is empty");
        else
        {
            Node * tmp = head;
            while(tmp->next && tmp->next->next)
                tmp = tmp->next;

            char c = tmp->next->value;
            delete tmp->next;
            tmp->next = nullptr;
            return c;
        }
    }

    void clear() {
        while(head)
        {
            Node * tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    bool empty() {
        return head == nullptr;
    }

    size_t size() {
        size_t s;
        Node * tmp = head;
        while(tmp) {
            tmp = tmp->next;
            ++s;
        }

        return s;
    }
};


class Stack : public List {
public:
    Stack() : List()
    { }

    void at(int i) = delete;
    void push_back() = delete;
    void pop_back() = delete;

    void push(char c)
    {
        push_front(c);
    }

    char pop()
    {
        return pop_front();
    }
};

int main()
{
    Stack s;

    for(char i = 65; i < 91; ++i) {
        s.push(i);
    }

    char c = 0;
    while(!s.empty()){
        c = s.pop();
        std::cout << c << " ";
    }

    return 0;
}