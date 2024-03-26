#include "node.h"

template <class T>
Node<T>::Node() : next(nullptr) { }

template <class T>
Node<T>::Node(const T& e) : data(e), next(nullptr) { }

template <class T>
T& Node<T>::getData()
{
   return data;
}

template <class T>
void Node<T>::setData(const T& e)
{
    data = e;
}
