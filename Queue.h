/**
*	@file : Queue.h
*	@author :  Haaris Chaudhry
*	@date : 2015.2.27
*	Purpose: The queue class will simulate a queue where first in items are first out.  This particular class will utilize an interface
*				provided by QueueInterface.h.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "QNode.h"
#include "PrecondViolatedExcep.h"
#include <string>

template <class ItemType>
class Queue
{
public:
    /**
    *  @pre None.
    *  @post None.
    *  @return None (this is the destructor, it deallocates the memory reserved by every Node that was created).
    */
    ~Queue();

    /**
    *  @pre None.
    *  @post Creates a Queue object with a m_front member variable that points to nullptr and a m_size of 0.
    *  @return A Queue object.
    */
    Queue();

    /**
    *  @pre A value of type ItemType.
    *  @post Adds a Node with a value of type ItemType to the end of the Queue.
    *  @return None. (throws a PrecondViolatedExcep exception if memory allocation was unsuccessful)
    */
    void enqueue( const ItemType& newEntry ) throw ( PrecondViolatedExcep );
    /**
    *  @pre None
    *  @post Removes a Node from the front of the Queue.
    *  @return None (throws PrecondViolatedExcep if a removal is attempted on empty queue.)
    */
    void dequeue() throw( PrecondViolatedExcep );

    /**
    *  @pre None
    *  @post None
    *  @return Returns a value of type ItemType contained within the front Node of the Queue (throws PrecondViolatedExcep if peek attempted on empty Queue).
    */
    ItemType peekFront() const throw( PrecondViolatedExcep );

    /**
    *  @pre None.
    *  @post None.
    *  @return Returns true or false depending on whether the queue is empty or not.
    */
    bool isEmpty() const;

private:
    QNode <ItemType>* m_front;  //A Node pointer of type ItemType that points to the first Node of the Queue.
    int m_size; //A member variable that keeps track of the number of nodes in the Queue.
};

#include "Queue.hpp"
#endif