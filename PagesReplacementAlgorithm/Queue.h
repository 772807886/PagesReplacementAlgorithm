#pragma once
/**
 * ���нڵ�
 */
template <typename T>
struct QueueNode {
    T data;
    QueueNode<T>* pNext;
};

/**
 * ����
 */
template <typename T>
class Queue {
public:
    //����
    Queue();
    //��������
    ~Queue();
    //�Ƿ�Ϊ��
    bool isEmpty() const;
    //��ͷ�ڵ�
    T& getHead() const;
    //��β�ڵ�
    T& getTail() const;
    //���
    Queue<T>& enqueue(const T& node);
    //����
    Queue<T>& dequeue();
    //����
    Queue<T>& dequeue(T& node);
private:
    //ͷ�ڵ�
    QueueNode<T>* head;
    //β�ڵ�
    QueueNode<T>* tail;
};

//���캯��
template <typename T>
inline Queue<T>::Queue() {
    head = tail = new QueueNode<T>;
    head->pNext = nullptr;
}

//��������
template <typename T>
inline Queue<T>::~Queue() {
    while(!isEmpty()) {
        dequeue();
    }
    delete head;
}

//�Ƿ�Ϊ��
template<typename T>
inline bool Queue<T>::isEmpty() const {
    return head->pNext == nullptr;
}

//��ͷ�ڵ�
template<typename T>
inline T & Queue<T>::getHead() const {
    if(isEmpty()) {
        throw "Empty Queue!";
    } else {
        return head->pNext->data;
    }
}

//��β�ڵ�
template<typename T>
inline T & Queue<T>::getTail() const {
    if(isEmpty()) {
        throw "Empty Queue!";
    } else {
        return tail->data;
    }
}

//���
template<typename T>
inline Queue<T>& Queue<T>::enqueue(const T & node) {
    tail->pNext = new QueueNode<T>;
    tail = tail->pNext;
    tail->data = node;
    tail->pNext = nullptr;
    return *this;
}

//����
template<typename T>
inline Queue<T>& Queue<T>::dequeue() {
    if(isEmpty()) {
        return *this;
    }
    QueueNode<T>* temp = head->pNext;
    head->pNext = temp->pNext;
    delete temp;
    return *this;
}

//����
template<typename T>
inline Queue<T>& Queue<T>::dequeue(T & node) {
    if(isEmpty()) {
        return *this;
    }
    QueueNode<T>* temp = head->pNext;
    node = temp->data;
    head->pNext = temp->pNext;
    delete temp;
    return *this;
}
