/**
*	@file : QNode.cpp
*	@author :  Haaris Chaudhry
*	@date : 2015.2.12
*	Purpose: The QNode implementation file.
*/

//The default constructor sets m_value and m_next to 0 and nullptr respectively.
//These values are set by way of the set methods


template <class T>
QNode<T>::QNode()
{
    m_value = T();
    setNext( nullptr );
}

//Using the set methods, this constructor sets m_value and m_next to val and nullptr respectively.
template <class T>
QNode<T>::QNode( T val )
{
    setValue( val );
    setNext( nullptr );
}

//Returns the value of m_value contained within the called QNode object
template <class T>
T QNode<T>::getValue() const
{
    return m_value;
}

//Sets the m_value contained within the called QNode object
template <class T>
void QNode<T>::setValue( T val )
{
    m_value = val;
}

//Returns the pointer of the called object that is pointing another QNode (or nullptr)
template <class T>
QNode<T>* QNode<T>::getNext() const
{
    return m_next;
}

//Sets m_next to point to the same object that the passed in pointer is pointing to.
template <class T>
void QNode<T>::setNext( QNode<T>* next )
{
    m_next = next;
}