/*********************
*   Geoff Overfield  *
*      Stack Data    *
*      Structure     *
*********************/

#ifndef Stack_h
#define Stack_h
#include <iostream>
using namespace std;

template <typename T>
struct Node;

template <typename T>
class Stack
{
private:
    Node<T> *top;
public:
    Stack()
    {
        top = NULL;
    }
    ~Stack();
    
    bool isStackEmpty();
    void Push(T &ref);
    bool Pop(T &ref);
    void Display();
    Node<T> *GetNewNode(T &ref);
};

template <typename T>
struct Node
{
    T item;
    Node<T> *next;
    Node(T ref)
    {
        item = ref;
        next = NULL;
    }
    Node() : next(NULL){}
}

template <typename T>
bool Stack<T>::isStackEmpty()
{
    return top == NULL;
}

template <typename T>
Stack<T>::~Stack()
{
    if (!isStackEmpty())
    {
        Node<T> *curr = top;
        Node<T> *tempPtr;
        while (curr != 0)
        {
            tempPtr = curr;
            curr = curr->next;
            delete tempPtr;
        }
    }
}

template <typename T>
Node<T> *Stack<T>::GetNewNode(T &ref)
{
    Node<T> *newPtr = new Node<T>(ref);
    return newPtr;
}

template <typename T>
void Stack<T>::Push(T &ref)
{
    Node<T> *newPtr = GetNewNode(ref);
    if (isStackEmpty())
        top = newPtr;
    else
    {
        newPtr->next = top;
        top = newPtr;
    }
}

template <typename T>
bool Stack<T>::Pop(T &ref)
{
    if (isStackEmpty())
        return false;
    else
    {
        Node<T> *temp = top;
        if (top->next == NULL)
            top = NULL;
        else top = top->next;
        delete temp;
        return true;
    }
}

template <typename T>
void Stack<T>::Display()
{
    if (isStackEmpty())
    {
        cout << "The Stack is empty\n"<<endl;
        return;
    }
    
    Node<T> *curr = top;
    cout<<"Contents of Stack:\n"<<endl;
    while (cur != NULL)
    {
        cout << curr->item << endl;
        curr = curr->next;
    }
    cout << endl;
}

#endif /* Stack_h */
