/**
*	@file : BinomialQueue.cpp
*	@author :  Haaris Chaudhry
*	@date : Apr 4, 2017
*	Purpose: This class implements a binomial queue
*/
#include <iostream>
#include "BinomialQueue.h"
#include "Queue.h"

// The constructor
BinomialQueue::BinomialQueue()
{
    // Set all tree pointers in the mTrees array to nullptr because we don't have anything yet.
    for( int i = 0; i < SIZE; i++ )
    {
        mTrees[i] = nullptr;
    }

    // Set the number of nodes in the tree to zero.
    mCurrentSize = 0;
}

// The destructor
BinomialQueue::~BinomialQueue()
{
    // If a tree exists at the current index of mTrees, destroy it.
    for( int i = 0; i < SIZE; i++ )
    {
        if( mTrees[i] )
        {
            destroyTree( mTrees[i] );
        }
    }
}

bool BinomialQueue::isEmpty() const
{
    return mCurrentSize == 0;
}

// Insert by first taking the passed in value and creating a node that encases it.
// Then create a new queue that contains that single node and merge it with the current queue.
void BinomialQueue::insert( int aKey )
{
    BinomialQueue newQueue;
    bqNode* newNode = new bqNode( aKey );
    newQueue.mTrees[0] = newNode;

    merge( newQueue );

    mCurrentSize++;
}

// Function to delete the minimum value in the queue.
void BinomialQueue::deleteMin()
{
    if( isEmpty() )
    {
        return;
    }

    int minIndex = -1;

    // First find the minimum value, which will be among the roots, so we just check the root at each
    // index of mTrees.
    for( int i = 0; i < SIZE; i++ )
    {
        if( mTrees[i] )
        {
            if( minIndex == -1 )
            {
                minIndex = i;
            }
            else
            {
                if( mTrees[i]->key < mTrees[minIndex]->key )
                {
                    minIndex = i;
                }
            }
        }
    }

    // Delete the found root while saving the rest of the tree for later merging.
    bqNode* remainingTree = mTrees[minIndex]->fChild;
    delete mTrees[minIndex];
    mTrees[minIndex] = nullptr;
    mCurrentSize--;

    // Create a queue that will be used to merge with the current queue.
    BinomialQueue queueToMerge;

    // Split up the remaining tree so that it is now a binomial queue, then merge it with the current queue.
    for( int i = 0; i < minIndex; i++ )
    {
        queueToMerge.mTrees[i] = remainingTree;
        if( remainingTree->rSibling )
        {
            remainingTree = remainingTree->rSibling;
        }
        queueToMerge.mTrees[i]->lSibling = queueToMerge.mTrees[i];
        queueToMerge.mTrees[i]->rSibling = nullptr;
    }
    

    merge( queueToMerge );
}

// Function to display each level of each tree in the queue.
void BinomialQueue::levelOrderDisplay()
{
    for( int i = 0; i < SIZE; i++ )
    {
        // Make sure there is a tree at the current element before we try and display its level order.
        if( mTrees[i] )
        {
            levelOrderDisplayByTree( mTrees[i], i );
            std::cout << "---\n";
        }
    }
}

// Function to destroy a tree by first traversing through each sibling to the last one and then
// going down to the first child if it exists.
void BinomialQueue::destroyTree(bqNode* aNode)
{
    if( aNode->rSibling )
    {
        destroyTree( aNode->rSibling );
    }

    if( aNode->fChild )
    {
        destroyTree( aNode->fChild );
    }

    delete aNode;
}

void BinomialQueue::merge( BinomialQueue& aOtherQueue )
{
    bqNode* carry = nullptr;

    // This method of carrying merges down through the queue was discussed in lab and is 
    // described on page 278 of the text.
    for( int i = 0; i < SIZE; i++ )
    {
        bqNode* t1 = mTrees[i];
        bqNode* t2 = aOtherQueue.mTrees[i];

        int mergeCase = t1 == nullptr ? 0 : 1;
        mergeCase += t2 == nullptr ? 0 : 2;
        mergeCase += carry == nullptr ? 0 : 4;

        switch( mergeCase )
        {
        case 0:
        case 1:
            break;
        case 2:
            mTrees[i] = t2;
            aOtherQueue.mTrees[i] = nullptr;
            break;
        case 3:
            carry = concateTrees( t1, t2 );
            mTrees[i] = aOtherQueue.mTrees[i] = nullptr;
            break;
        case 4:
            mTrees[i] = carry;
            carry = nullptr;
            break;
        case 5:
            carry = concateTrees( t1, carry );
            mTrees[i] = nullptr;
            break;
        case 6:
            carry = concateTrees( t2, carry );
            aOtherQueue.mTrees[i] = nullptr;
            break;
        case 7:
            mTrees[i] = carry;
            carry = concateTrees( t1, t2 );
            aOtherQueue.mTrees[i] = nullptr;
            break;
        }
    }
}

// Got this function from http://stackoverflow.com/questions/9330915/number-of-combinations-n-choose-r-in-c
int BinomialQueue::nCr( int n, int r )
{
    if( r > n ) return 0;
    if( r * 2 > n ) r = n - r;
    if( r == 0 ) return 1;

    int result = n;
    for( int i = 2; i <= r; ++i ) {
        result *= ( n - i + 1 );
        result /= i;
    }
    return result;
}

// Displays the level order of a tree.
void BinomialQueue::levelOrderDisplayByTree( bqNode* aRootNode, int aOrder )
{
    // We want to know how many values to display per level, pascals trying will be useful for this.
    int* pascalVals = new int[aOrder + 1];
    int valsDisplayed = 0;
    int pascalIndex = 0;

    // Using the given order, we compute each coefficient.
    for( int i = 0; i <= aOrder; i++ )
    {
        pascalVals[i] = nCr( aOrder, i );
    }

    // We'll use a queue to store children, the root is used as the first value in the queue.
    Queue<bqNode*> queue;

    queue.enqueue( aRootNode );

    while( !queue.isEmpty() )
    {
        // The current node is saved as the first node in the queue.
        bqNode* curNode = queue.peekFront();

        while( curNode )
        {
            // We'll go ahead and display each sibling of curNode while saving 
            // any children we find to the queue.
            if( curNode->fChild )
            {
                queue.enqueue( curNode->fChild );
            }

            std::cout << curNode->key << " ";

            // We check if we've reached the limit of values that can be displayed for the current level.
            // If we reach the limit, then move on to the next level and increment the index used for the
            // pascal array.
            valsDisplayed++;
            if( valsDisplayed == pascalVals[pascalIndex] )
            {
                std::cout << "\n";
                valsDisplayed = 0;
                pascalIndex++;
            }

            // Keep going through each sibling
            curNode = curNode->rSibling;
        }

        // When there are no more sibling to display, we take the first node out of the queue.
        queue.dequeue();
    }

    delete[] pascalVals;
}

// This code was translated from the pseudocode that was given at the end of the notes for concatendated queues.
bqNode* BinomialQueue::concateTrees( bqNode* aT1, bqNode* aT2 )
{
    if( aT1->key > aT2->key )
    {
        return concateTrees( aT2, aT1 );
    }

    if( aT1->order == 0 )
    {
        aT1->fChild = aT2;
        aT1->order += 1;

        return aT1;
    }

    aT2->lSibling = aT1->fChild->lSibling;
    aT2->lSibling->rSibling = aT2;
    aT1->fChild->lSibling = aT2;
    aT1->order = aT1->order + 1;

    return aT1;
}
