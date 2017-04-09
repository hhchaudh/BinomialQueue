/**
*	@file : QNode.h
*	@author :  Haaris Chaudhry
*	@date : 2016.2.12
*	Purpose: QNode header file.  The QNode class will simulate a "node" that holds an integer
*          value and points to another node.
*/

#ifndef QNODE_H
#define QNODE_H

template <class T>
class QNode
{
public:
    /**
    *  @pre None
    *  @post Creates and initializes a QNode object with default values.
    *  @return Initialized QNode class with default values (m_value = 0 and m_next = nullptr)
    */
    QNode();

    /**
    *  @pre A type T parameter
    *  @post Creates and initializes a QNode object with passed in value.
    *  @return Initialized QNode class with m_value = val and m_next = nullptr
    */
    QNode( T val );

    /**
    *  @pre None
    *  @post None
    *  @return Returns the m_value contained in the QNode object
    */
    T getValue() const;

    /**
    *  @pre A type T parameter
    *  @post Sets the m_value to the passed in value.
    *  @return None
    */
    void setValue( T val );

    /**
    *  @pre None
    *  @post None
    *  @return Returns the node that the current QNode object is pointing to. (returns m_next)
    */
    QNode<T>* getNext() const;

    /**
    *  @pre A QNode object (or nullptr)
    *  @post Sets m_next to point to the same QNode object that the passed in pointer is pointing to.
    *  @return None
    */
    void setNext( QNode<T>* next );

private:
    T m_value; //The type T value contained within the QNode object
    QNode<T>* m_next; //The pointer that points to the next QNode object
};

#include "QNode.hpp"
#endif