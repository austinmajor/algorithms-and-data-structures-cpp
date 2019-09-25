#include <iostream>
#define PRINT_EMPTY_ERROR cerr << "\n ERROR: Empty Linked List!";

using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node()
    {
        next = NULL;
    }
    Node(int d)
    { //constructor to initialize a node with a value
        data = d;
        next = NULL;
        prev = NULL;
    }

    void setData(int);
    int getData();
    void setNext(Node *);
    Node *getNext();
    void setPrev(Node *);
    Node *getPrev();
};

class DoubleLinkList
{
    Node *head;

    bool isEmpty()
    {
        return (head == NULL) ? true : false;
    }

public:
    DoubleLinkList()
    {
        head = NULL;
    }

    void insHead(int);
    void insTail(int);
    void insAfter(int elem, int pos);

    void delHead();
    void delTail();
    void delElem(int);

    bool search(int);

    void traverse_inorder();
    void traverse_revorder();
};

/*** MEMBER FUNCTION DEFINITIONS ***/
void Node::setData(int d)
{
    data = d;
}
int Node::getData()
{
    return data;
}

void Node::setNext(Node *A)
{
    next = A;
}
Node *Node::getNext()
{
    return next;
}

void Node::setPrev(Node *A)
{
    prev = A;
}
Node *Node::getPrev()
{
    return prev;
}

void DoubleLinkList::insHead(int d)
{
    Node *temp = new Node(d);

    if (isEmpty())
    {
        head = temp;
    }
    else
    {
        temp->setNext(head);
        head->setPrev(temp);
        head = temp;
    }
}

void DoubleLinkList::insTail(int d)
{
    Node *temp = new Node(d);
    Node *loc = head;

    if (isEmpty())
    {
        PRINT_EMPTY_ERROR;
        return;
    }

    while (loc->getNext() != NULL) //traverse to last node
        loc = loc->getNext();

    loc->setNext(temp);
    temp->setPrev(loc);
}

void DoubleLinkList::insAfter(int d, int pos)
{
    Node *temp = new Node(d);
    Node *loc = head;

    if (isEmpty())
    {
        PRINT_EMPTY_ERROR;
    }
    else
    {
        while (loc != NULL)
        {
            if (loc->getData() == pos)
            {
                if (loc->getNext() == NULL)
                {
                    insTail(d);
                }
                else
                {
                    temp->setPrev(loc);
                    temp->setNext(loc->getNext()); //set the pointers of temp

                    loc = loc->getNext(); //go to node after temp
                    loc->setPrev(temp);   //set the pointers

                    loc = temp->getPrev(); //go to node before temp
                    loc->setNext(temp);    //set the pointers
                }

                return;
            }
            else
                loc = loc->getNext();
        }
    }

    cerr << "\n ERROR: " << pos << " not found in list!"; //control reaches here only if pos wasn't found
}

void DoubleLinkList::delHead()
{
    Node *temp = head;

    if (isEmpty())
    {
        PRINT_EMPTY_ERROR;
    }

    else if (head->getNext() == NULL)
    {
        cout << "\n Deleting Element: " << temp->getData(); //temps points to head btw
        head = NULL;
        delete temp;
    }
    else
    {
        cout << "\n Deleting Element: " << temp->getData();

        head = head->getNext();
        head->setPrev(NULL);

        delete temp;
    }
}

void DoubleLinkList::delTail()
{
    Node *temp = head;
    Node *loc;
    if (isEmpty())
    {
        PRINT_EMPTY_ERROR;
    }
    else if (head->getNext() == NULL)
    {
        cout << "\n Deleting Element: " << temp->getData(); //temps points to head btw
        head = NULL;
        delete temp;
    }
    else
    {

        while (temp->getNext() != NULL)
        { //traverse to the end of the list
            loc = temp;
            temp = temp->getNext();
        }

        loc->setNext(NULL);

        cout << "\n Deleting Element: " << temp->getData();

        delete temp;
    }
}

void DoubleLinkList::delElem(int d)
{
    Node *temp = head;
    Node *loc = head;

    if (isEmpty())
    {
        PRINT_EMPTY_ERROR;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->getData() == d)
            {
                if (temp == head)
                    delHead();
                else if (temp->getNext() == NULL)
                    delTail();
                else
                {
                    loc->setNext(temp->getNext());

                    loc = loc->getNext();

                    loc->setPrev(temp->getPrev());

                    cout << "\n Deleting Element: " << temp->getData();
                }
                return;
            }
            else
            {
                loc = temp;
                temp = temp->getNext();
            }

        } //end of while()

        cerr << "\n ERROR: " << d << " not found in Linked List!";
    }
}

bool DoubleLinkList::search(int key)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->getData() == key)
            return true;
        else
            temp = temp->getNext();
    }

    return false; //control reaches here only if the key was not found in the list
}

void DoubleLinkList::traverse_inorder()
{
    Node *temp = head;

    if (isEmpty())
    {
        PRINT_EMPTY_ERROR;
        return;
    }

    cout << " HEAD ";
    while (temp != NULL)
    {
        cout << " <--> " << temp->getData();
        temp = temp->getNext();
    }
    cout << " <--> NULL ";
}

void DoubleLinkList::traverse_revorder()
{
    Node *temp = head;

    if (isEmpty())
    {
        PRINT_EMPTY_ERROR;
        return;
    }

    cout << " NULL ";
    while (temp->getNext() != NULL) //traverse to last node
        temp = temp->getNext();

    while (temp != NULL)
    {
        cout << " <--> " << temp->getData();
        temp = temp->getPrev();
    }
    cout << " <--> HEAD ";
}

int main()
{

    DoubleLinkList DL;

    int choice;
    int num, pos;

    do
    {
        cout << "\n [DOUBLY LINKED LIST IMPLEMENTATION]";
        cout << "\n 1. Insert to head";
        cout << "\n 2. Insert to tail";
        cout << "\n 3. Insert after an element";
        cout << "\n 4. Delete from head";
        cout << "\n 5. Delete from tail";
        cout << "\n 6. Delete particular element";
        cout << "\n 7. Search";
        cout << "\n 8. In-order traversal";
        cout << "\n 9. Reverse-order traversal";
        cout << "\n 0. EXIT";
        cout << "\n Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n Enter element to insert to head: ";
            cin >> num;
            DL.insHead(num);
            break;
        case 2:
            cout << "\n Enter element to insert to tail: ";
            cin >> num;
            DL.insTail(num);
            break;
        case 3:
            cout << "\n Enter element to insert into list: ";
            cin >> num;
            cout << "\n After which element should it be inserted: ";
            cin >> pos;
            DL.insAfter(num, pos);
            break;
        case 4:
            DL.delHead();
            break;
        case 5:
            DL.delTail();
            break;
        case 6:
            cout << "\n Enter element you wish to delete: ";
            cin >> num;
            DL.delElem(num);
            break;
        case 7:
            cout << "\n Enter element to search: ";
            cin >> num;
            if (DL.search(num))
                cout << "\n Element FOUND!";
            else
                cout << "\n Element NOT FOUND!";
            break;
        case 8:
            cout << "\n Elements of linked list: \n\t";
            DL.traverse_inorder();
            break;
        case 9:
            cout << "\n Element of linked list (in reverse order): \n\t";
            DL.traverse_revorder();
            break;
        case 0:
            cout << "\n Thank You For Using Doubly Linked List!";
            break;
        default:
            cerr << "\n ERROR: Invalid Choice!";
            break;
        }
        cout << "\n\n";
    } while (choice != 0);
    return 0;
}
