//------------------------------------------------------------------------------
// basic_node_type.cpp
//
// Demos linked list nodes.
//
// A linked list contains list items called "nodes".
// A node can be a struct instance or a class instance.
// 
// Each node contains a data value plus a pointer to 
// another node.
// 
// You can connect two nodes by setting one node pointer's
// value to be the address of the other node.
// 
// The last node in the list has its node pointer set to nullptr.
//
// When a struct or class of type T has a member variable
// of type T*, the instances are meant to be linked together
// into a list.
//------------------------------------------------------------------------------
#include <iostream>
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr char CRLF = '\n';

// A linked list node can use a struct
struct SNode {
    int   data;
    struct SNode* pNext;

    SNode(int _data) : data(_data), pNext(nullptr) { }
};

// A linked list node can use a class instance
class CNode {
public:
    char   data;
    CNode* pNext;

    CNode(char _data) : data(_data), pNext(nullptr) { }
};

//------------------------------------------------------------------------------
// entry point 
//------------------------------------------------------------------------------
int main() {

    // syntax for using struct instance nodes
    struct SNode* pSNode = new SNode(8);
    cout << "(struct) pSNode->data: " << pSNode->data << CRLF;
    cout << "(struct) pSNode->pNext: " << pSNode->pNext << CRLF;
    cout << CRLF;

    // free this node's memory
    delete pSNode;

    // syntax for using class instance nodes
    CNode* pCNode = new CNode('z');
    cout << "(class instance) pCNode->data: " << pCNode->data << CRLF;
    cout << "(class instance) pCNode->pNext: " << pCNode->pNext << CRLF;
    cout << CRLF;

    // free this node's memory
    delete pCNode;

    // we can link two class instance nodes together

    // first, we create the nodes

    // create the first node 
    CNode* pCNode1 = new CNode('a');
    cout << "Address of first node (pCNode1): " << pCNode1 << CRLF;

    // create the second node
    CNode* pCNode2 = new CNode('b');
    cout << "Address of second node (pCNode2): " << pCNode2 << CRLF;

    // link the first node to the second one
    pCNode1->pNext = pCNode2;

    // display the list

    cout << "The List of two nodes:\n\n";

    cout << "Data in first node (pCNode1): " << pCNode1->data << CRLF;
    cout << "First node points to second node (pCNode2): " 
        << pCNode1->pNext << CRLF;

    // follow the first node's pointer to access the second node
    cout << "Data in second node (pCNode2): " 
        << pCNode1->pNext->data << CRLF;
    cout << "Second node points to 0 because it's the last node in the list: "
        << pCNode2->pNext << CRLF;

    cout << CRLF;

    // we can traverse a list with a loop

    // save the original node pointer to the beginning (head) of the list!
    // use a temporary pointer to point to each node in turn

    // start at the list head
    CNode* pTemp = pCNode1;
    while (pTemp != nullptr) {

        // display node data
        cout << pTemp->data;

        // follow the link (pointer) to the next node in the list
        pTemp = pTemp->pNext;
    }

    cout << CRLF;

    // free all node memory using the original pointers we got from new
    delete pCNode1;
    delete pCNode2;

    cin.get();

    return 0;
}