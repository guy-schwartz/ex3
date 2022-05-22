//
// Created by Guy Schwartz on 19/05/2022.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

template <class T>
class Node{
    public:
    T m_data;
    Node<T> *m_nextNode;
    Node<T> *m_previousNode;

    Node(T t): m_data(t),  m_nextNode(NULL), m_previousNode(NULL)
    {
    }
};

template <class T>
class Queue{
    private:
    Node<T> *m_first;
    Node<T> *m_last;
    int m_size;

    public:

    
    Queue();

    Queue(const Queue<T>&);

    ~Queue();

    Queue<T>& operator=(const Queue<T>&);

    bool empty() const;

    void pushBack(const T&);

    T& front();

    T front() const;

    void popFront();

    int size() const;

    class Iterator;
    Iterator begin() const;
    Iterator end() const;

    
};

template <class T>
Queue<T>::Queue(): size(0), first(NULL), last(NULL){};

template <class T>
Queue<T>::Queue(const Queue<T>& other): size(0), first(NULL), last(NULL){

    Node<T> *temp = other.m_first;

    while(temp != NULL){

        pushBack(temp->m_data);
        temp = temp->m_nextNode;
    }
}

template <class T>
Queue<T>::~Queue(){

    while(m_size > o){
        popFront();        
    }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){

    if(this == other){

        return *this;
    }

    while(m_size > 0){

        popFront();
    }

    Node<T> *temp = other.m_first;

    while(temp != Null){

        pushBack(temp->m_data);
        temp = temp->m_nextNode;
    }

    return *this;
}

template <class T>
void Queue<T>::pushBack(const T& data){

        Node<T> *temp = new Node<T>(data);
        
        if(m_size == 0){

            m_first = m_last = temp;
        }
        else{

            m_last->m_nextNode = temp;
            m_last = temp;
        }

        m_size++;
}

template <class T>
T& Queue<T>::front(){

    retuen m_first->m_data;
}

template <class T>
T Queue<T>::front() const{

    retuen m_first->m_data;
}

template <class T>
void Queue<T>::popFront(){

    if(size > 0){

        if(m_first == m_last){
            
            delete m_first;
            m_first = m_last = NULL;
        }
        elae{

        Node<T> *temp = m_first;
        m_first = m_first->m_nextNode;
        delete temp;
        }
        m_size--;
    }
}

template <class T>
int Queue<T>::size() const{
     
     return m_size;
}

/*template <class T>
bool Queue<T>::empty() const{

    return first == NULL;
}*/




#endif //EX3_QUEUE_H
