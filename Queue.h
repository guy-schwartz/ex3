//
// Created by Guy Schwartz on 19/05/2022.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
#include <iostream>

template <class T>
class Node{
    public:
    T m_data;
    Node<T> *m_nextNode;

    explicit Node(T t): m_data(t),  m_nextNode(NULL)
    {}
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

    class EmptyQueue{};
};

template <class T>
Queue<T>::Queue():  m_first(NULL), m_last(NULL), m_size(0){}

template <class T>
Queue<T>::Queue(const Queue<T>& other):  m_first(NULL), m_last(NULL), m_size(0){

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

    while(temp != NULL){

        pushBack(temp->m_data);
        temp = temp->m_nextNode;
    }

    return *this;
}

template <class T>
void Queue<T>::pushBack(const T& data){
    Node<T> *temp=NULL;
    try{
         temp = new Node<T>(data);
    } catch(const std::bad_alloc&){};

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
    if(!m_size)
    {
        throw EmptyQueue();
    }
    return m_first->m_data;
}

template <class T>
T Queue<T>::front() const{
    if(!m_size)
    {
        throw EmptyQueue();
    }
    return m_first->m_data;
}

template <class T>
void Queue<T>::popFront(){
    if(m_size > 0){

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
    class InvalidOperation{};
};

template<class T>
typename Queue<T>::Iterator Queue<T>::begin(){
    if(!m_size)
    {
        //throw EmptyQueue();
    }
    return Iterator(this, m_first);
}

template <class T> 
typename Queue<T>::Iterator Queue<T>::end(){
    if(!m_size)
    {
        throw EmptyQueue();
    }
    return Iterator(this, m_last->m_nextNode);
}


template <class T>
Queue<T>::Iterator::Iterator(Queue<T> *queue, Node<T> *node):
m_queue(queue), m_node(node)
{}


template <class T>
T& Queue<T>::Iterator::operator*(){
    if(m_queue==NULL||m_node==NULL){
        throw InvalidOperation();
    }
    else{
        return m_node->m_data;
    }
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++(){
    if(m_queue==NULL||m_node==NULL){
        throw InvalidOperation();
    }
    else{

        m_node = m_node->m_nextNode;
    }

    return *this;
}        

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int){
    if(m_queue==NULL||m_node==NULL){
        throw InvalidOperation();
    }
    ConstIterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool Queue<T>::Iterator::operator==(const Iterator& Iterator) const{

    if(m_queue == Iterator.m_queue && m_node == Iterator.m_node){

        return true;
    }
    else{
        return false;
    }
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator& Iterator) const{

    return !(*this == Iterator);
}

template <class T>
T* Queue<T>::Iterator::operator->(){
    if(m_queue==NULL||m_node==NULL){
        throw InvalidOperation();
    }
    else{
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
    class InvalidOperation{};
};


template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const{
    if(!m_size)
    {
        //throw EmptyQueue();
    }
    return ConstIterator(this, m_first);
}

template <class T> 
typename Queue<T>::ConstIterator Queue<T>::end() const{
    if(!m_size)
    {
        throw EmptyQueue();
    }
    return ConstIterator(this, m_last->m_nextNode);
}


template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T> *queue, const Node<T> *node):
m_queue(queue), m_node(node)
{}


template <class T>
const T& Queue<T>::ConstIterator::operator*() const{
    if(m_queue==NULL||m_node==NULL){
        throw InvalidOperation();
    }
    else{
        return m_node->m_data;
    }
}

template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++(){
    if(m_queue==NULL||m_node==NULL){
        throw InvalidOperation();
    }
    else{

        m_node = m_node->m_nextNode;
    }

    return *this;
}        

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int){
    if(m_queue==NULL||m_node==NULL){
        throw InvalidOperation();
    }
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

    if(m_node!= NULL){
        return &(m_node->m_data);
    }

}

template <class T, class Condition>
Queue<T> filter(const Queue<T>& queue, Condition c){

    Queue<T> result; 

    for(typename Queue<T>::ConstIterator it = queue.begin(); it != queue.end(); ++it){

        if(c(*it)){

            result.pushBack(*it);
        }
    }

    return result;
}

template <class T, class Condition>
void transform (Queue<T>& queue, Condition c){

    for(typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it){

        c(*it);
    }
}

#endif //EX3_QUEUE_H
