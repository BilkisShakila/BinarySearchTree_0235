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

class BinaryTree
{
public :
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initialize root to null
    }

    void insert()
    {
        int x;
        cout << "Masukkan nilai :";
        cin >> x;

        //step 1: allocate memory for the new node 
        Node *newNode = new Node();

        //step 2 : assign value to the data field of new node 
        newNode->info = x;

        //step 3: make the left and right child of the new node point to NULL
        newNode->leftchild = nullptr;
        newNode->righchild = nullptr;

        //step 4: locate the node whice will be the parent 
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        //step 5:  if parent is NULL (tree is empaty)
        if (parent == nullptr)
        {
            //sa: mark the node as ROOT 
            ROOT = newNode;

            //5b : exit
            return;
        }

        //step 6: if the value in the data field of new node is less than that of parent
        if (x < parent->info)
        {
            //6a : make the left child of parent point to the new node
            parent->leftchild = newNode;

            //6b : Exit
            return;
        }
        //step 7 : if the value in the data field of the new node is greater than of the parent
        else if (x > parent->info)
        {
            //7a: make the right child of parent point to the new node 
            parent->righchild = newNode;

            //7b : exit 
            return;
        }
    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
        // this functional seacrhes the currentnode of the specifield node as well as the current Node of this its parent
        currentNode = ROOT;
        parent = nullptr;
        while((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->righchild;
        }
    }
    
    void inorder(Node *ptr)
    {
        if (isEmpaty())
        {
            cout << "Tree is empaty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->righchild);

    }

    