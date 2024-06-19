namespace STACK {
// remove into the .ipp file
    template<typename INF, class FRIEND>
    ListNode<INF, FRIEND>::ListNode(INF data) {
        d = data;
        next = nullptr;
        //std::cout << "ListNode constructed completely" << std::endl;
    }

    template<typename INF, class FRIEND>
    ListNode<INF, FRIEND>& ListNode<INF, FRIEND>::operator=(ListNode& node) {
        this->d = node.d;
        return *this;
    }

    template<typename INF>
    MyStack<INF>::MyStack() {
        top = nullptr;
    }

    template<typename INF>
    MyStack<INF>::MyStack(INF data) {
        top = new Node(data);
    }

    template<typename INF>
    MyStack<INF>::~MyStack() {
        while (top != nullptr) {
            Node* ptr = top;
            top = top->next;
            delete ptr;
        }
    }

    template<typename INF>
    bool MyStack<INF>::Empty(void) {
        if (top == nullptr)
            return true;
        else
            return false;
    }

    template<typename INF>
    bool MyStack<INF>::Push(INF data) {
        Node* ptr = new Node;
        ptr->next = top;
        top = ptr;
        top->d = data;
        return true;
    }

    template<typename INF>
    bool MyStack<INF>::Pop() {
        if (!Empty()) {
            std::cout << "Popping" << std::endl;
            Node* ptr = top;
            top = top->next;
            delete ptr; // delete is working because next node doesn't remove by deconst.
            return true;
        }
        return false;
    }

    template<typename INF>
    INF MyStack<INF>::TopInf() {
        if (!this->Empty())
            return top->d;
        else
            return 0;
    }

    template<typename INF>
    void MyStack<INF>::Display() {
        typedef class ListNode<INF, MyStack<INF>> Node;
        Node* ptr = top;
        while (ptr->next != nullptr) {
            std::cout << ptr->d << " * ";
            ptr = ptr->next;
        }
        std::cout << ptr->d << std::endl;
    }

    template<typename INF>
    void MyStack<INF>::RDisplay(Node* point) {
        Node* ptr = top;
        if (point->next != nullptr) {
            this->RDisplay(point->next);
        }
        std::cout << point->d << " * ";
    }
}