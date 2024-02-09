/*******************************************************************************
** CPSC 131: Part 1 - Sequence Containers
**           Singly Linked List Quiz
**
** Implement the insert_after function for a null-terminated list.  Insert at the beginning of a list by passing a null pointer.
** Return an pointer to the newly inserted node.
*******************************************************************************/


#include <iostream>
#include <utility>
#include <array>
#include <iomanip>





template<typename T>
struct SLL
{
  struct Node
  {
    Node() = default;
    Node( T value ) : _data{ std::move( value ) } {}
    T      _data = T{};
    Node * _next = nullptr;
  };

  Node *      _head = nullptr;
  Node *      _tail = nullptr;
  std::size_t _size = 0;



  Node * insert_after( Node * position, T const & data )
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
      // Create a new node
      Node * newNode = new Node(data);

      // Check position is null, if so insert at the beginning 
      if(!position)

      {

        newNode->_next = _head; // Point the new node to the current head like we learned in class
        _head = newNode; // Set the head to newNode

        // Check to see if list is empty, update tail with new node 
        if(!_tail)

        _tail = newNode;
      }
      else
      {
        newNode->_next = position->_next; // set the point of the new node next to the next position
        position->_next = newNode; 
        // update that position to new nodes
        if(position == _tail)
            _tail = newNode;
            // see if inserted after the current tail and if so update the tail to thew new node.

      } 

      _size++;
      // add the size 
      // return the new node info 

      return newNode;
    /////////////////////// END-TO-DO (1) ////////////////////////////
  }


  void print ()
  {
    std::cout << "  _head -> ";
    for( const Node * p = _head; p != nullptr; p = p->_next )  std::cout << '{' << p->_data << ", " << std::setw( 14 ) << p->_next << "} -> ";
    std::cout << "\u03A6\n";

    std::cout << "             ";
    for( const Node * p = _head; p != nullptr; p = p->_next )  std::cout << '(' << std::setw(14) << p << ")        ";
    std::cout << '\n';

    if( _tail == nullptr ) std::cout << "  _tail -> \u03A6\n";
    else                   std::cout << "  _tail -> {" << _tail->_data << ", " << std::setw(14) << _tail->_next << "}\n"
                                     << "             (" << std::setw(14) << _tail << ")\n";

    std::cout << "  _size =  " << _size << "\n\n\n";
  }
};






int main()
{
  std::cout << std::setfill( '0' ) << std::showbase;



  SLL<unsigned int> theList;
  // Sketch the initial state of the list.
  // Be mindful how you sketch.  Note the required 3 lines, attribute and null terminator names, and the arrow syntax.  Be sure to not
  // place your sketch in comments (the autograder's code review pass ignores comments)
  // For example:
  #if 0
       _head -> 73 -> 94 -> 13 -> Φ       (will also accept NULL instead of Φ)
       _tail -> 13
       _size = 3
  ///////////////////////// TO-DO (2) //////////////////////////////
        // initial state 
        _head -> Φ
        _tail -> Φ
        _size = 0
  /////////////////////// END-TO-DO (2) ////////////////////////////
  #endif
  theList.print();


  auto n1 = theList.insert_after( nullptr, 20 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  // Be mindful to how you sketch.  Note the required 3 lines, attribute and null terminator names, and the arrow syntax
  #if 0
  ///////////////////////// TO-DO (3) //////////////////////////////
    // nullptr 20
     _head -> 20 -> Φ
     _tail -> 20
     _size = 1
  /////////////////////// END-TO-DO (3) ////////////////////////////
  #endif


  auto n2 = theList.insert_after( nullptr, 10 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  // Be mindful to how you sketch.  Note the required 3 lines, attribute and null terminator names, and the arrow syntax
  #if 0
  ///////////////////////// TO-DO (4) //////////////////////////////
    // nullptr 10
      _head -> 10 -> 20 -> Φ
      _tail -> 20
      _size = 2
  /////////////////////// END-TO-DO (4) ////////////////////////////
  #endif


  theList.insert_after( n1, 40 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  // Be mindful to how you sketch.  Note the required 3 lines, attribute and null terminator names, and the arrow syntax
  #if 0
  ///////////////////////// TO-DO (5) //////////////////////////////
 // n1 points to node w/ 20
    _head -> 10 -> 20 -> 40 -> Φ
    _tail -> 40
     _size = 3
  /////////////////////// END-TO-DO (5) ////////////////////////////
  #endif


  theList.insert_after( n2, 30 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  // Be mindful to how you sketch.  Note the required 3 lines, attribute and null terminator names, and the arrow syntax
  #if 0
  ///////////////////////// TO-DO (6) //////////////////////////////
  // where n2 points to node w/ 10
       _head -> 10 -> 30 -> 20 -> 40 -> Φ
       _tail -> 40
       _size = 4
  /////////////////////// END-TO-DO (6) ////////////////////////////
  #endif
}
