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

    void pushBack(const T&);

    T& front();

    T front() const;

    void popFront();

    int size() const;

    class Iterator;
    class ConstIterator;

    ConstIterator begin() const;
    ConstIterator end() const;
    Iterator begin();
    Iterator end();

    
};

template <class T>
Queue<T>::Queue(): m_size(0), m_first(NULL), m_last(NULL){};

template <class T>
Queue<T>::Queue(const Queue<T>& other): m_size(0), m_first(NULL), m_last(NULL){

    Node<T> *temp = other.m_first;

    while(temp != NULL){

        pushBack(temp->m_data);
        temp = temp->m_nextNode;
    }
}

template <class T>
Queue<T>::~Queue(){

    while(m_size > 0){
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
        else{

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

template <class T>
class Queue<T>::Iterator{

    private:
    Queue<T> *m_queue;
    Node<T> *m_node;
    Iterator(Queue<T> *queue, Node<T> *node);
    friend class Queue<T>;

    public:
    T& operator*();
    //const
    Iterator& operator++();
    Iterator operator++(int);
    //const
    T* operator->();

    bool operator==(const Iterator& Iterator) const;
    bool operator!=(const Iterator& Iterator) const;
    
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
};

template<class T>
typename Queue<T>::Iterator Queue<T>::begin(){

    return Iterator(this, m_first);
}

template <class T> 
typename Queue<T>::Iterator Queue<T>::end(){

    return Iterator(this, m_last->m_nextNode);
}


template <class T>
Queue<T>::Iterator::Iterator(Queue<T> *queue, Node<T> *node):
m_queue(queue), m_node(node)
{}


template <class T>
T& Queue<T>::Iterator::operator*(){

    if(m_node! = NULL){
        return m_node->m_data;
    }
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++(){

    if(m_node != NULL){

        m_node = m_node->m_nextNode;
    }

    return *this;
}        

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int){

    ConstIterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool Queue<T>::Iterator::operator==(const Iterator& Iterator) const{

    if(m_queue == ConstIterator.m_queue && m_node == ConstIterator.m_node){

        return true;
    }
    else{
        return false;
    }
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator& Iterator) const{

    return !(*this == ConstIterator);
}

template <class T>
T* Queue<T>::Iterator::operator->(){

    if(m_node! = NULL){
        return &(m_node->m_data);
    }

}

template <class T>
class Queue<T>::ConstIterator{

    private:
    const Queue<T> *m_queue;
    const Node<T> *m_node;
    ConstIterator(const Queue<T> *queue, const Node<T> *node);
    friend class Queue<T>;

    public:
    const T& operator*() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    const T* operator->() const;

    bool operator==(const ConstIterator& ConstIterator) const;
    bool operator!=(const ConstIterator& ConstIterator) const;
    
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
};


template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const{

    return ConstIterator(this, m_first);
}

template <class T> 
typename Queue<T>::ConstIterator Queue<T>::end() const{

    return ConstIterator(this, m_last->m_nextNode);
}


template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T> *queue, const Node<T> *node):
m_queue(queue), m_node(node)
{}


template <class T>
const T& Queue<T>::ConstIterator::operator*() const{

    if(m_node! = NULL){
        return m_node->m_data;
    }
}

template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++(){

    if(m_node != NULL){

        m_node = m_node->m_nextNode;
    }

    return *this;
}        

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int){

    ConstIterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator& ConstIterator) const{

    if(m_queue == ConstIterator.m_queue && m_node == ConstIterator.m_node){

        return true;
    }
    else{
        return false;
    }
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& ConstIterator) const{

    return !(*this == ConstIterator);
}

template <class T>
const T* Queue<T>::ConstIterator::operator->() const{

    if(m_node! = NULL){
        return &(m_node->m_data);
    }

}

template <class T, class Condition>
Queue<T>& filter(const Queue<T>& queue, Condition c){

    Queue<T> result; 

    for(typename Queue<T>::ConstIterator it = queue.begin(); it != queue.end(); ++it){

        if(c(*it)){

            result.pushBack(*it);
        }
    }

    return result;
}

template <class T, class Condition>
void Transform (Queue<T>& queue, Condition c){

    for(typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it){

        c(*it);
    }
}

#endif //EX3_QUEUE_H
