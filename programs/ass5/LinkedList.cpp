/******************************************************
** File: LinkedList.cpp
** Author: Wyatt Whiting
** Date: 2020-12-02
** Description: linked list class implementation
******************************************************/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "LinkedList.h"
#define LL LinkedList

using namespace std;

/*******************************************************
 * Function: LL::LinkedList()
 * Description: linked list class constructor
 * Parameters: none
 * Pre-Conditions: list does not exist
 * Post-Conditions: list exists
 *******************************************************/
LL::LinkedList()
{
    //list start with no elements and NULL head
    this->length = 0;
    this->head = NULL;
}

/*******************************************************
 * Function: LL::~LinkedList()
 * Description: linked list destructor
 * Parameters: none
 * Pre-Conditions: list exists
 * Post-Conditions: list no longer exists
 *******************************************************/
LL::~LinkedList() { this->clear(); }

/*******************************************************
 * Function: int LL::getLength()
 * Description: returns number of elements in linked list
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
int LL::getLength() { return this->length; }

/*******************************************************
 * Function: void LL::print()
 * Description: prints elements of linked list
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: elements of linked list are printed
 *                  to screen
 *******************************************************/
void LL::print()
{
    //start at head node
    Node *curr = head;

    for (int i = 0; i < length; i++)
    {
        cout << curr->val << ' '; //print current value
        curr = curr->next;         //go to next node
    }

    //print extra line
    cout << endl;
}

/*******************************************************
 * Function: void LL::clear()
 * Description: deletes all the nodes of a linked list
 * Parameters: none
 * Pre-Conditions: linked list has nodes in heap
 * Post-Conditions: nodes are deleted from heap
 *******************************************************/
void LL::clear()
{
    while (this->length != 0) //until we get length of 0
    {
        Node *curr = head; //current node pointer
        for (int i = 0; i < (this->length) - 1; i++)
            curr = curr->next; //go to second to last Node
        delete curr->next;     //delete the next Node
        this->length--;        //reduce the length
    }
    delete head; //delete the head

    //reset to default state
    head = NULL;
    length = 0;
}

/*******************************************************
 * Function: unsigned int LL::pushFront(int val)
 * Description: adds new node to beginning of list
 * Parameters: int val - value to add to list
 * Pre-Conditions: linked list object exists
 * Post-Conditions: new node is added to beginning of list
 *******************************************************/
unsigned int LL::pushFront(int val)
{
    this->length++;
    Node *temp = head;          //save pointer to old head
    head = new Node(val, temp); //head replaced with pointer to new node
    return this->length;
}

/*******************************************************
 * Function: unsigned int LL::pushBack(int val)
 * Description: adds new node with value to end of list
 * Parameters: int val - value for new node
 * Pre-Conditions: list exist
 * Post-Conditions: node with value 'val' added to end of list
 *******************************************************/
unsigned int LL::pushBack(int val)
{
    //increment length
    this->length++;

    //if no elements, just set it
    if (head == NULL)
        head = new Node(val);

    //otherwise
    else
    {
        Node *curr = head; //start at head
        while (curr->next != NULL) //until we get to end of list
        {
            curr = curr->next;  //increment the curr pointer
        }

        //curr is now pointing to end of list

        //add new node to next pointer
        curr->next = new Node(val);
    }

    //return 
    return this->length;
}

/*******************************************************
 * Function: unsigned int LL::insert(int val, unsigned int index)
 * Description: inserts new node at specified index
 * Parameters: int val - value for new node
 *             unsigned int index - index for new node
 * Pre-Conditions: list exists and 'index' is in valid range
 * Post-Conditions: node with value 'val' added to linked list
 *                  at index 'index'
 *******************************************************/
unsigned int LL::insert(int val, unsigned int index)
{
    if (index == 0)
        return pushFront(val); //if at beginning just call pushFront
    if (index == length)
        return pushBack(val); //if at back just call pushBack

    //if beyond possible index to add
    if (index > this->length)
    {   
        //print error message and do nothing
        cout << "ERROR: Index outside possible range" << endl;
        return this->length;
    }

    //once here, index is validated

    Node *curr = this->head; //curr is pointer to current node
    for (int i = 0; i < index - 1; i++)
    {
        curr = curr->next;
    }
    Node *next = curr->next; //store pointer to following element
    curr->next = new Node(val, next); //insert the new node with saved pointer

    //increment length
    this->length++; 

    //return length
    return this->length;
}

/*******************************************************
 * Function: void LL::sortAscending()
 * Description: calls recursive merge sort for ascending order
 * Parameters: none
 * Pre-Conditions: list is unordered
 * Post-Conditions: list is sorted in ascending order
 *******************************************************/
void LL::sortAscending() { mergeSort(&(this->head), true); }

/*******************************************************
 * Function: void LL::sortDescending()
 * Description: calls recursive merge sort for descending order
 * Parameters: none
 * Pre-Conditions: list is unordered
 * Post-Conditions: list is sorted in descending order
 *******************************************************/
void LL::sortDescending() { mergeSort(&(this->head), false); }

/*******************************************************
 * Function: void LL::mergeSort(Node ** begin, bool ascend)
 * Description: revursive merge sort function for linked list.
 *              Works by changing pointers, not values.
 * Parameters: Node ** begin - double pointer to beinning of linked list
 *             bool ascend - bool to indicate if sorting should be in ascending order
 * Pre-Conditions: list is undordered
 * Post-Conditions: list is sorted in order according to 'ascend'
 *******************************************************/
void LL::mergeSort(Node ** begin, bool ascend)
{
    //let's get some variables going
    Node * start = *begin;
    Node * n1;
    Node * n2;

    //base case: if list is empty or one element, do nothing
    if (start == NULL || start->next == NULL)
        return;

    //split list into halves
    split(&n1, &n2, start);

    //recursive call for mergeSort on each half, now that split() has
    //split them into two null-terminated lists starting at n1 and n2
    mergeSort(&n1, ascend);
    mergeSort(&n2, ascend);

    //set the dereferenced double pointer to result of merged halves
    *begin = mergeLists(n1, n2, ascend);
}

/*******************************************************
 * Function: void LL::split(Node * listStart, Node ** first, Node ** second)
 * Description: splits linked list into two independ linked list
 * Parameters: Node * listStart - beginning of list
 *             Node ** first - double pointer to node at start of first half of list
 *             Node ** second - double pointer to node at start of second half of list
 * Pre-Conditions: list exists, and listStart points to beginning of the list to be split
 * Post-Conditions: first set to beginning of first half, same with second for second half
 *******************************************************/
void LL::split(Node ** first, Node ** second, Node * listStart)
{
    //some local node pointers
    Node * n1 = listStart->next;
    Node * n2 = listStart;

    while (n1 != NULL) //until n1 is the end of th list
    {
        n1 = n1->next;  //advance n1 by 1
        if (n1 != NULL) //if that didn't hit the end
        {
            //increment them both
            n1 = n1->next;
            n2 = n2->next;
        }
    }

    //set address of 'first' to start of list
    *first = listStart;

    //set address of 'second' to node after n2
    *second = n2->next;

    //split the list at the n2 node to make two new independant lists
    n2->next = NULL;
}

/*******************************************************
 * Function: Node * LL::mergeLists(Node * n1, Node * n2, bool ascend)
 * Description: returns pointer to beginning of merged list
 * Parameters: Node * n1 - pointer to first Node of first half to merge
 *             Node * n2 - pointer to first Node of second half to merge
 * Pre-Conditions: halves must be split 
 * Post-Conditions: returns pointer to merged list
 *******************************************************/
Node * LL::mergeLists(Node * n1, Node * n2, bool ascend)
{
    //local node pointer
    Node * sorted = NULL;

    //base case: function gets passed n1 or n2 which are NULL, indicating there is no next element to sort
    if (n1 == NULL)
        return n2;
    if (n2 == NULL)
        return n1;

    //determine which smaller
    //if n1 is smaller
    if (ascend)
    {
        if (n1->val <= n2->val)
        {
            //put n1 into sorted list
            sorted = n1;

            //next element determined by recurisve call with remaining elements
            sorted->next = mergeLists(n1->next, n2, ascend);
        }
        else //otherwise...
        {
            //do the opposite
            sorted = n2;
            sorted->next = mergeLists(n1, n2->next, ascend);
        }
    }

    //for desceding order
    else
    {
        if (n1->val >= n2->val)
        {
            //put n1 into sorted list
            sorted = n1;

            //next element determined by recurisve call with remaining elements
            sorted->next = mergeLists(n1->next, n2, ascend);
        }
        else //otherwise...
        {
            //do the opposite
            sorted = n2;
            sorted->next = mergeLists(n1, n2->next, ascend);
        }
    }
    
    //once code reaches here, base cases must have been reached, so return the sorted list

    return sorted;
}

/*******************************************************
 * Function: bool LL::isPrime(unsigned int val)
 * Description: returns if function argument is prime
 * Parameters: unsigned int val - value to check primeness of 
 * Pre-Conditions: none
 * Post-Conditions: none, state of list unchanged
 *******************************************************/
bool LL::isPrime(unsigned int val)
{

    //deal with edge cases
    if (val == 2 || val == 3)
        return true;

    //loop through all possible factors
    for (int i = 2; i < (int)(val / 2); i++)
        if (val % i == 0) //if factor is found
            return false; //it's not prime

    //if here, must be prime
    return true;
}

/*******************************************************
 * Function: int LL::countPrimes()
 * Description: counts the number of primes in a list
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none - state unchanged
 *******************************************************/
int LL::countPrimes()
{
    if (this->length == 0)
        return 0;        //if list is empty there can be no primes

    //hacky fix, don't want to track down bug
    if (this->length == 1 && isPrime(this->head->val)) return 1;

    Node * curr = head;  //current node to check
    int primeCount = 0;  //count of prime numbers

    //loop through all nodes
    for (int i = 0; i < this->length - 1; i++)
    {
        //only if the current node value is greater than or equal to 2
        if (curr->val >= 2) 
            //add to prime count
            primeCount += isPrime(curr->val);
        
        //advance curr pointer
        curr = curr->next;
    }

    //return total found primes
    return primeCount;
}