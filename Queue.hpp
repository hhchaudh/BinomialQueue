/**
*	@file : Queue.hpp
*	@author :  Haaris Chaudhry
*	@date : 2015.2.27
*	Purpose: Implementation of the Queue class.
*/

template <class ItemType>
Queue<ItemType>::Queue()
{
    m_front = nullptr;
    m_size = 0;
}

//ItemTypehe destructor will loop through the list and deallocate the memory held by each QNode
template <class ItemType>
Queue<ItemType>::~Queue()
{
    QNode<ItemType>* temp = nullptr;  //we need a temp variable to hold the QNode to be deleted

    while( !isEmpty() )
    {
        temp = m_front;  //temp point to the first QNode in the list
        m_front = m_front->getNext();  //m_front then points to the second QNode in the list
        delete temp;  //the QNode that temp is pointing to is deleted
        m_size--; //a QNode has been deleted in the list, so we decrease the size
    }

    m_front = nullptr; //set m_front to nullptr because there are no more QNode objects to point to
}

//Adds a QNode object to the front of the list
template <class ItemType>
void Queue<ItemType>::enqueue( const ItemType& newEntry ) throw ( PrecondViolatedExcep )
{
    if( m_front == nullptr )  //Is the list empty? Then m_front will point to this new QNode object
    {
        try
        {
            m_front = new QNode<ItemType>( newEntry );
            m_size++;
        }
        catch( std::bad_alloc& e )
        {
            std::string message = "Memory could not be allocated";
            throw PrecondViolatedExcep( message );
        }
    }
    else  //If the list is not empty, then newNode is a pointer that will point to a new QNode object
    {
        try
        {
            QNode<ItemType>* newNode = new QNode<ItemType>( newEntry );  //ItemTypehe object pointed to by newNode will have newEntry as its m_value
            QNode<ItemType>* temp = m_front;
            while( temp->getNext() != nullptr )
            {
                temp = temp->getNext();
            }
            temp->setNext( newNode );
            m_size++;  //we added a new QNode object to the list, so we should increment the size
        }
        catch( std::bad_alloc& e )
        {
            std::string message = "Memory could not be allocated";
            throw PrecondViolatedExcep( message );
        }
    }
}

template <class ItemType>
void Queue<ItemType>::dequeue() throw( PrecondViolatedExcep )
{
    if( m_front == nullptr )
    {
        throw PrecondViolatedExcep( "Removal attempted on an empty queue" );
    }
    else
    {
        QNode<ItemType>* temp = m_front;
        m_front = m_front->getNext();
        delete temp;
        m_size--;
    }
}

template <class ItemType>
ItemType Queue<ItemType>::peekFront() const throw( PrecondViolatedExcep )
{
    if( isEmpty() )
    {
        throw PrecondViolatedExcep( "Peek attempted on an empty queue" );
    }
    else
    {
        return m_front->getValue();
    }
}

template <class ItemType>
bool Queue<ItemType>::isEmpty() const
{
    if( m_size == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

