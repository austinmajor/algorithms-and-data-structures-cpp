#include <iostream>

using namespace std;

// define Node
typedef int dataType;

struct Node
{
    dataType data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(dataType value) : data(value), next(nullptr) {}
};

void traverse(Node *head)
{
    for (Node *tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->next)
    {
        cout << tempPtr->data << endl;
    }
}

// define NodePtr
typedef Node *NodePtr;

void add_head_1(NodePtr &head, dataType num)
{
    Node *temp = new Node(num);

    temp->next = head;

    head = temp;
}

int main()
{
    // Node n1(11);
    // Node n2(22);
    // Node n3(33);
    // Node n4(44);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;

    // option 1
    // Node* head = &n1;
    // traverse(head);

    // option 2
    // int a = 10;
    // int* pa = &a;
    // int** ppa = &pa;

    // cout << a << "\t" << &a << endl;
    // cout << pa << "\t" << &pa << endl;
    // cout << ppa << "\t" << &ppa << endl;
    // cout << *ppa << "\t" << **ppa << endl;

    // option 3
    NodePtr head = nullptr;
    add_head_1(head, 10);
    add_head_1(head, 20);
    add_head_1(head, 30);
    traverse(head);

    return 0;
}