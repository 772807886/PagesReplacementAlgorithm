#pragma once
#include <cstring>
template <typename T>
/**
 * ջ
 */
class Stack {
public:
    //ջ
    Stack(const unsigned int size = 10, const unsigned int increase = 10);
    //��������
    ~Stack();
    //ȡ����
    unsigned int size() const;
    //�Ƿ�Ϊ��
    bool isEmpty() const;
    //�Ƿ�����
    bool isFull() const;
    //ȡջ��
    T& getTop() const;
    //ȡջ��
    T& getBottom() const;
    //��ջ
    Stack<T>& push(const T& node);
    //��ջ
    Stack<T>& pop();
    //��ջ
    Stack<T>& pop(T& node);
    //���
    Stack<T>& clear();
private:
    //ջ��ַ
    T* stack;
    //������ַ
    unsigned int top;
    //ջ����
    unsigned int max;
    //�Զ������С
    unsigned int increase;
    //�Զ�����
    void inc();
};

//���캯��
template <typename T>
inline Stack<T>::Stack(const unsigned int size, const unsigned int increase) {
    this->max = size;
    this->increase = increase;
    this->top = -1;
    this->stack = new T[max];
}

//��������
template <typename T>
inline Stack<T>::~Stack() {
    delete[] stack;
}

//ȡ����
template<typename T>
inline unsigned int Stack<T>::size() const {
    return max;
}

//�Ƿ�Ϊ��
template<typename T>
inline bool Stack<T>::isEmpty() const {
    return top == -1;
}

//�Ƿ�����
template<typename T>
inline bool Stack<T>::isFull() const {
    return top == max - 1;
}

//ȡջ��
template<typename T>
inline T & Stack<T>::getTop() const {
    if(isEmpty()) {
        throw "Empty Stack!";
    }
    return stack[top];
}

//ȡջ��
template<typename T>
inline T & Stack<T>::getBottom() const {
    if(isEmpty()) {
        throw "Empty Stack!";
    }
    return stack[0];
}

//��ջ
template<typename T>
inline Stack<T>& Stack<T>::push(const T & node) {
    if(isFull()) {
        inc();
    }
    stack[++top] = node;
    return *this;
}

//��ջ
template<typename T>
inline Stack<T>& Stack<T>::pop() {
    if(!isEmpty()) {
        top--;
    }
    return *this;
}

//��ջ
template<typename T>
inline Stack<T>& Stack<T>::pop(T & node) {
    if(!isEmpty()) {
        node = stack[top--];
    }
    return *this;
}

//���
template<typename T>
inline Stack<T>& Stack<T>::clear() {
    top = -1;
    return *this;
}

//�Զ�����
template<typename T>
inline void Stack<T>::inc() {
    T* temp = new T[max + increase];
    memcpy(temp, stack, max * sizeof(T));
    delete[] stack;
    max += increase;
    stack = temp;
}
