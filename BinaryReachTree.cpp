#include <iostream>
using namespace std;

class Node
{
public :
    int info;
    Node *leftchild;
    Node *righchild;

    // contructor for the node class
    Node()
    {
        leftchild = nullptr; //initialize left child to null
        righchild = nullptr; // initialize right child to null
    }
};

