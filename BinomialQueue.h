/**
*	@file : BinomialQueue.h
*	@author :  Haaris Chaudhry
*	@date : Apr 4, 2017
*	Purpose: This class implements a binomial queue
*/

#ifndef BINOMIAL_QUEUE
#define BINOMIAL_QUEUE

// The structure of the binomial queue node, as taken from the notes.
struct bqNode
{
    int key;
    int order;
    bqNode* fChild;
    bqNode* lSibling;
    bqNode* rSibling;

    bqNode( int aKey ) :
        key( aKey )
    {
        order = 0;
        fChild = nullptr;
        lSibling = this;
        rSibling = nullptr;
    }
};

class BinomialQueue
{
public:
    /**
    * Constructor for the BinomialQueue
    * @return An empty binomial queue
    */
    BinomialQueue();

    /**
    * Destructor for the binomial queue.
    */
    ~BinomialQueue();

    /**
    * Function that checks if the binomial queue is empty.
    * @return A bool value, true if the queue is empty, false otherwise.
    */
    bool isEmpty() const;

    /**
    * Function that is used to insert values into the queue.
    * @param aKey The value that is to be inserted into the queue.
    */
    void insert( int aKey );

    /**
    * Function that is used to delete the minimum value from the queue.
    */
    void deleteMin();

    /**
    * Function that is used to display the values in the queue level by level.
    */
    void levelOrderDisplay();

private:
    /**
    * Function that is used to destroy a tree.
    */
    void destroyTree(bqNode* aNode);

    /**
    * Function that is used to merge to queues together.
    * @param aOtherQueue The other queue that is to be merged with this one.
    */
    void merge( BinomialQueue & aOtherQueue );

    /**
    * Function that is used to compute the a combinatorial.
    * @param n The number of values to choose from.
    * @param r The number of values to choose.
    */
    int nCr( int n, int r );

    /**
    * Function that is used to display each tree in the queue in a levelorder fashion.
    * @param aRootNode The root of the current tree.
    * @param aOrder The order of the current tree.
    */
    void levelOrderDisplayByTree( bqNode* aRootNode, int aOrder );
    
    /**
    * Function that is used to concatenate two trees with the same order.
    * @param aT1 The first tree.
    * @param aT2 The second tree.
    */
    bqNode* concateTrees( bqNode *aT1, bqNode *aT2 );

    const static int SIZE = 10; // The size that we'll use for the queue, 10 should be big enough for this lab.
    bqNode* mTrees[SIZE];       // The array that will contain the trees.
    int mCurrentSize;           // The number of nodes contained in all.

};

#endif