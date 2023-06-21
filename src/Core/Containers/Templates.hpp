//
//  Templates.hpp
//  App
//
//  Created by Austin Horn on 10/14/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Templates_hpp
#define Templates_hpp

#include <iostream> // std::cin, std::cout
#include <new>      // std::bad_alloc
#include <cmath>    // std::ceil, std::log

////////////////////////////////////////////////////////////
/// \namespace list
///
/// \brief Contains custom built list types
///
/// \class list
/// 
////////////////////////////////////////////////////////////
namespace lists
{

    ////////////////////////////////////////////////////////////
    /// \class list
    ///
    /// \brief Double linked list
    ////////////////////////////////////////////////////////////
    template <typename T>
    class list
    {
    private:
        struct Node
        {
            T mPayload;
            struct Node *mNext, *mPrev;
            Node(T t = 0, struct Node *n = nullptr, struct Node *p = nullptr) : mPayload{t}, mNext{n}, mPrev{p} {}
        };
        
        struct Node *mRoot;
        struct Node **mEnvPtr;
        unsigned int mSize;
        
        bool isThere(struct Node *);  /* Check if node exists in list                                       */
        void altClear(struct Node *); /* Recursive Method for deleting an entire list beginning at the root */
        void printFwd(struct Node *);
        void printBwd();
    public:
        list();           /* Default Constructor                                                */
        ~list();          /* Destructor                                                         */
        
        struct Node * getNewNode(T &);
        void clear();                 /* Delete entire list                                                 */
        void insert(struct Node *);   /* Insert node function with preallocated Node pointer parameter      */
        void remove(struct Node *);   /* Delete node function with mPayload type parameter                  */
        void print(const bool);
    };

    /* Default Constructor */
    template <typename T>
    list<T>::list() : mRoot{nullptr}, mEnvPtr{nullptr}, mSize{0}
    {
        this->clear(); // Create fresh list
    }

    /* Destructor */
    template <typename T>
    list<T>::~list()
    {
        this->clear(); // Deletes entire list
    }

    /*  */
    template <typename T>
    void list<T>::altClear(struct Node *p)
    {
        if ( p ) // Check that mNode is not nullptr, if true:
        {
            struct Node *q = p->mNext; /* Fetch mRoot's mNext node to be new mRoot (may be nullptr) */
            p->mNext = nullptr;        /* Break link                                                */
            delete p;                  /* Delete old mRoot                                          */
            altClear(q);             /* Recursively delete new mRoot                                */
        }
    }

    /* Public method for list deletion */
    template <typename T>
    void list<T>::clear()
    {
        this->altClear(this->mRoot); // Calls private recursive delete method altClear()
    }

    /*  */
    template <typename T>
    struct list<T>::Node * list<T>::getNewNode(T &t)
    {
        return new struct Node(t, nullptr, nullptr);
    }

    /* Private Method for determining if Node already exists in list */
    template <typename T>
    bool list<T>::isThere(struct Node *p)
    {
        this->mEnvPtr = &this->mRoot;
        
        while( *this->mEnvPtr  &&  (*this->mEnvPtr)->mPayload <= p->mPayload )
            this->mEnvPtr = &(*this->mEnvPtr)->mNext;

        return *this->mEnvPtr && (*this->mEnvPtr)->mPayload == p->mPayload;
    }

    /*  */
    template <typename T>
    void list<T>::insert(struct Node *p)
    {
        // If p has unique mPayload
        if ( !isThere(p) )
        {
            // Attempt memory allocation for a pointer to type Node
            try
            {
                // Point p to dereferenced environment pointer to type Node
                struct Node *q = *this->mEnvPtr;
                
                // Create new node
                *this->mEnvPtr = new struct Node;
                
                // Assign contents
                (*this->mEnvPtr)->mPayload = p->mPayload;
                (*this->mEnvPtr)->mNext = q;
                q->mPrev = (*this->mEnvPtr);
                
                // Increment number of nodes in list
                this->mSize++;
            }
            // Catch bad allocation of memory
            catch (const std::bad_alloc& excpt)
            {
                std::cout << "std::bad_alloc::what(): " << excpt.what() << std::endl;
            }
        }
        else
        {
            std::cout << "Node: <" << p << "> already exists in list." << std::endl;
        }
    }

    /*  */
    template <typename T>
    void list<T>::remove(struct Node *p)
    {
        if ( isThere(p) )
        {
            struct Node *q = *this->mEnvPtr;
            *this->mEnvPtr = (*this->mEnvPtr)->mNext;
            
            q->mNext = nullptr;
            delete q;
            
            // Decrement number of noders in list
            this->mSize--;
        }
    }

    /* Public Print Method */
    template <typename T>
    void list<T>::print(const bool fwdPrint)
    {
        if ( fwdPrint )
            printFwd(this->mRoot);
        else
            printBwd();
    }

    /* Private Forward Printing Method (Starts At Root) */
    template <typename T>
    void list<T>::printFwd(struct Node *p)
    {
        if ( p )
        {
            std::cout<<'('<<p->mPayload<<')';
            
            p = p->mNext;
            
            if (p)
                std::cout << " ←→ ";
            else
                std::cout << " ← tail" << std::endl;
            
            this->printFwd(p);
        }
    }

    /* Private Backward Printing Method (Starts At Root) */
    template <typename T>
    void list<T>::printBwd()
    {
        
    }


} // MARK: End of namespace 'list'
























////////////////////////////////////////////////////////////
/// \namespace tree
///
/// \brief Contains custom built tree types
///
/// \class tree
///
////////////////////////////////////////////////////////////
namespace tree
{
    ////////////////////////////////////////////////////////////
    /// \class list
    ///
    /// \brief Double linked list
    ////////////////////////////////////////////////////////////
    template <typename T>
    class tree {
    protected:
        struct node {
            T m_payload;
            struct node *m_left, *m_right;
            node() : m_left(nullptr), m_right(nullptr) { }
        };
        
        struct node *m_root;
        struct node **m_envPtr;
        unsigned int m_nodeCount, m_levelCount;

        //****************************************************************************************
        // Recursive procedure with a public wrapper: void listType::delete()
        // Called by create() and the destructor
        void altDelete(struct node *p)  {
            if (p) {
                altDelete(p->m_left);
                altDelete(p->m_right);
                delete p;
            }
        }
        
        //****************************************************************************************
        // Counts the number of levels in a tree or subtree
        int countLevels(struct node *p) {
            m_levelCount = 0;
            altCountLevels(p, 1);
            return m_levelCount;
        }

        //****************************************************************************************
        // Recursive, called by int countLevels(struct node)
        void altCountLevels(struct node *p, int i) {
            if(p) {
                if(i > m_levelCount)
                    m_levelCount = i;

                altCountLevels(p->m_left, i+1);
                altCountLevels(p->m_right, i+1);
            }
                
        }

        //****************************************************************************************
        // Calculates the number of levels in a perfect tree
        int calcLvls() {
            return std::ceil(std::log(m_nodeCount+1)/std::log(2));
        }

        //****************************************************************************************
        /// Rotates tree to the m_left
        void rotL(struct node **dp) {
            struct node *p = *dp;
            *dp = p->m_right;
            p->m_right = (*dp)->m_left;
            (*dp)->m_left = p;
        }

        //****************************************************************************************
        /// Rotates tree to the m_left
        void rotR(struct node **dp) {
            struct node *p = *dp;
            *dp = p->m_left;
            p->m_left = (*dp)->m_right;
            (*dp)->m_right = p;
        }

        //****************************************************************************************
        /// Balance tree
        void balanceTree(struct node **dp) {
            if (!(*dp)) {
                return; // Already balanced
            }
            else {
                balanceTree(&(*dp)->m_left);
                balanceTree(&(*dp)->m_right);
                
                int leftSize = countLevels((*dp)->m_left);
                int rightSize = countLevels((*dp)->m_right);
                
                if (leftSize == rightSize  ||  (leftSize+1) == rightSize  ||  (leftSize-1) == rightSize)
                    return;
                else {
                    // Node has inside m_left grandchild
                    if ((*dp)->m_left  &&  (*dp)->m_left->m_right)
                        rotL( &(*dp)->m_left );
                    // Node has inside m_right grandchild
                    if ((*dp)->m_right  &&  (*dp)->m_right->m_left)
                        rotR(&(*dp)->m_right);
                    
                    // Rotate tree to smaller side
                    if (leftSize < rightSize)
                        rotL(dp);
                    else if (leftSize > rightSize)
                        rotR(dp);
                    // Call recursively
                    balanceTree(dp);
                }
            }
        }

    public:

        ///****************************************************************************************
        /// Constructor
        tree() : m_root(nullptr), m_envPtr(nullptr), m_nodeCount(0) {
            create();
        }
        
        //****************************************************************************************
        // Destructor
        ~tree() {
            altDelete(m_root);
        }

        //****************************************************************************************
        /// Initializes members for new tree
        void create() {
            altDelete(m_root);
            m_root = nullptr;
        }

        //****************************************************************************************
        /// Check if a node already exists in tree
        bool isThere(T &e) {
            m_envPtr = &m_root;
            
            while( *m_envPtr  &&  (*m_envPtr)->m_payload != e )
                if((*m_envPtr)->m_payload > e)
                    m_envPtr=&(*m_envPtr)->m_left;
                else
                    m_envPtr=&(*m_envPtr)->m_right;

            return *m_envPtr;
        }

        //****************************************************************************************
        /// Insert node into tree
        void insert(T e) {
            if(!isThere(e)) {
                *m_envPtr = new struct node;
                (*m_envPtr)->m_payload=e;
                m_nodeCount++;
            }
        }

        //****************************************************************************************
        /// Remove node from tree
        void remove(T &e) {
            /// Set envPtr
            if (isThere(e)) {
                /// Node does NOT have 2 children
                if (!(*m_envPtr)->m_left || !(*m_envPtr)->m_right) {
                    if ( (*m_envPtr)->m_left ) {
                        struct node *p = *m_envPtr;
                        p = *this->m_envPtr;
                        *this->m_envPtr = (*this->m_envPtr)->m_left;
                        delete p;
                    }
                    else {
                        struct node *p = *m_envPtr;
                        p = *this->m_envPtr;
                        *this->m_envPtr = (*this->m_envPtr)->m_right;
                        delete p;
                    }
                }
                /// Node DOES have 2 children
                else {
                    struct node **dp = m_envPtr;
                    dp = &(*m_envPtr)->m_left;
                    
                    while ((*dp)->m_right)
                        dp = &(*dp)->m_right;
                    
                    struct node *p = *m_envPtr;
                    struct node *q = *dp;
                    
                    *dp = q->m_left;
                    q->m_left = p->m_left;
                    q->m_right = p->m_right;
                    *m_envPtr = q;
                    delete p;
                    
                    m_nodeCount--;
                }
            }
        }
        
        //****************************************************************************************
        // Executes balance routine
        void balance() {
            balanceTree(&m_root);
        }

        //****************************************************************************************
        ///
        void showTreeStats() {
            std::cout<<"\n\nm_nodeCount = "<<m_nodeCount<<"\tcalcLvls = "<<calcLvls()<<"\tcntLvls = "<<countLevels(m_root)<<std::endl;
        }
    };

} // MARK: End of namespace 'tree'


#endif /* Templates_hpp */
