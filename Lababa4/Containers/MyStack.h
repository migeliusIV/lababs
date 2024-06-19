// ‘айл MyStack.h
// Ўаблонный класс MyStack на основе односв€зного списка.
#ifndef MyStack_h           // защита от повторной компил€ции
#define MyStack_h           // модуль подключен

namespace STACK {
    // Ўаблонный класс ListNode (узел односв€зного списка)
    template<typename INF, class FRIEND>
    class ListNode              // узел списка
    {
    private:
        INF d;                  // информационна€ часть узла
        ListNode* next;         // указатель на следующий узел списка
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

    // Ўаблонный класс MyStack на основе односв€зного списка.
    template<typename INF>
    class MyStack {
        typedef class ListNode<INF, MyStack<INF>> Node;
        

    public:
        Node* top;
        MyStack(void);           // конструктор
        MyStack(INF);
        ~MyStack(void);          // освободить динамическую пам€ть
        bool Empty(void);        // стек пустой?
        bool Push(INF);          // добавить узел в вершину стека
        bool Pop(void);          // удалить узел из вершины стека
        INF TopInf(void);        // считать информацию из вершины стека
        void Display();
        void RDisplay(Node*);
        
        //MyStack& operator=(const MyStack&);
    };    
}

#include "templ.tpp"

#endif