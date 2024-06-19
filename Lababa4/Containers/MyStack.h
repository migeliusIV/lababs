// ���� MyStack.h
// ��������� ����� MyStack �� ������ ������������ ������.
#ifndef MyStack_h           // ������ �� ��������� ����������
#define MyStack_h           // ������ ���������

namespace STACK {
    // ��������� ����� ListNode (���� ������������ ������)
    template<typename INF, class FRIEND>
    class ListNode              // ���� ������
    {
    private:
        INF d;                  // �������������� ����� ����
        ListNode* next;         // ��������� �� ��������� ���� ������
        ListNode(void) {
            //std::cout << "ListNode constructed" << std::endl;
            next = nullptr;
        }
        ListNode(INF);
        ~ListNode() { next = nullptr; }
        friend FRIEND;

    public:
        ListNode& operator=(ListNode&);
    };

    // ��������� ����� MyStack �� ������ ������������ ������.
    template<typename INF>
    class MyStack {
        typedef class ListNode<INF, MyStack<INF>> Node;
        

    public:
        Node* top;
        MyStack(void);           // �����������
        MyStack(INF);
        ~MyStack(void);          // ���������� ������������ ������
        bool Empty(void);        // ���� ������?
        bool Push(INF);          // �������� ���� � ������� �����
        bool Pop(void);          // ������� ���� �� ������� �����
        INF TopInf(void);        // ������� ���������� �� ������� �����
        void Display();
        void RDisplay(Node*);
        
        //MyStack& operator=(const MyStack&);
    };    
}

#include "templ.tpp"

#endif