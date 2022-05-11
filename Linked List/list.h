// Fig. 21.4: list.h
// Template List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List {

public:
   List();      // constructor
   ~List();     // destructor

   // added functions **
   List(const List& x);                // copy constructor
   List& operator=(const List& x);     // assignement operator
   // **

   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );

   // new functions **
   bool insertMiddle( const NODETYPE &, int x );
   bool removeMiddle( NODETYPE &, int x );
   // **

   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
   void print() const;

private:
   ListNode< NODETYPE > *firstPtr;  // pointer to first node
   ListNode< NODETYPE > *lastPtr;   // pointer to last node

   // utility function to allocate new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE & );

}; // end class List

// default constructor
template< class NODETYPE >
List< NODETYPE >::List()
   : firstPtr( 0 ),
     lastPtr( 0 )
{
   // empty body

} // end List constructor

// destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) {    // List is not empty
//      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )         // delete remaining nodes
      {
         tempPtr = currentPtr;

// commented out the output -- no need to print what we are deallocating
//         cout << tempPtr->data << '\n';

         currentPtr = currentPtr->nextPtr;
         delete tempPtr;

      }

   }

//   cout << "All nodes destroyed\n\n";

} // end List destructor

// copy constructor
template< class NODETYPE >
List< NODETYPE >::List(const List& x) {

  ListNode< NODETYPE > *currentPtr = x.firstPtr;

  firstPtr = lastPtr = 0;     // reset first and last to null
  this->insertAtBack(currentPtr->data);    // catch first value

  while (currentPtr->nextPtr != 0) {    // while data is not null pointer
    currentPtr = currentPtr->nextPtr;   // walk through
    this->insertAtBack(currentPtr->data);
  }
  // no deletes

}
// assignment operator
template< class NODETYPE >
List< NODETYPE >& List< NODETYPE >:: operator= (const List &x) {

  ListNode< NODETYPE > *currentPtr = x.firstPtr;

  if (this != &x) {  // only make copy if the original is not this object

    this->~List();    // deconstructed old list
    firstPtr = lastPtr = 0;     // reset first and last to null
    this->insertAtBack(currentPtr->data);    // catch first value

    while (currentPtr->nextPtr != 0) {    // while data is not null pointer
      currentPtr = currentPtr->nextPtr;   // move through list
      this->insertAtBack(currentPtr->data);
      // assign next pointer in walkthrough to new pointer
    }
    // after delete then set first and last to null
    // then insert
  }
  return *this;  // return this object

}

// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;

   } // end else

} // end function insertAtFront

// insert node at back of list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;

   } // end else

} // end function insertAtBack

// new functions **
template< class NODETYPE >
bool List< NODETYPE >:: insertMiddle( const NODETYPE &value, int x )
{
  ListNode< NODETYPE > *newPtr = getNewNode( value );
  ListNode< NODETYPE > *currentPtr = firstPtr;

  if ( isEmpty() ) { // if the list is empty
    firstPtr = lastPtr = newPtr;
    return true;
  }
  else {
    if (x <= 1) {
      insertAtFront(value);
      return true;
    }

    for (int i = 1; i != x - 1; i++) {      // walk through
      currentPtr = currentPtr->nextPtr;     // move until position is found
      if (currentPtr == lastPtr) {          // if position is out of bounds
        newPtr->nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr = newPtr;
        lastPtr = newPtr;       // re-assigns last pointer to the new one
        return true;
      }
    }

    newPtr->nextPtr = currentPtr->nextPtr;
    currentPtr->nextPtr = newPtr;
    currentPtr = newPtr;
    return true;
  }
}

template< class NODETYPE >
bool List< NODETYPE >:: removeMiddle(NODETYPE &value, int x )
{
  if (isEmpty())
    return false;

  else {

    ListNode< NODETYPE > *tempPtr = firstPtr;

    if (x < 1)
      return false;

    if (x == 1) {   // to delete first node
      firstPtr = tempPtr->nextPtr;      // store second node as first node
      value = tempPtr->data;
      delete tempPtr;   // delete temp
      return true;
    }

    for (int i = 0; i < x - 2; i++) {  // to find the node n - 1
      tempPtr = tempPtr->nextPtr;
      if (tempPtr->nextPtr == 0)
        return false; // fix this error: when it is one larger than the size
    }
    // return false for failed

    ListNode< NODETYPE > *tempPtr2 = tempPtr->nextPtr; // variable for nth node
    tempPtr->nextPtr = tempPtr2->nextPtr; // this is n + 1 node

    value = tempPtr2->data;
    delete tempPtr2;

    return true;
  }
}
// end new functions **


// delete node from front of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )  // List is empty
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;  // data being removed
      delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromFront

// delete node from back of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         // locate second-to-last element
         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = 0;

      } // end else

      value = tempPtr->data;
      delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromBack

// is List empty?
template< class NODETYPE >
bool List< NODETYPE >::isEmpty() const
{
   return firstPtr == 0;

} // end function isEmpty

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
   const NODETYPE &value )
{
   return new ListNode< NODETYPE >( value );

} // end function getNewNode

// display contents of List
template< class NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) {
      cout << "The list is empty\n\n";
      return;

   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;

   } // end while

   cout << "\n\n";

} // end function print

#endif

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
