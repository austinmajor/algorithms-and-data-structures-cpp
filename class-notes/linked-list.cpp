// 20190909_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

// define Node

typedef int dataType;

struct Node
{
    dataType data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(dataType value) : data(value), next(nullptr) {}
};

// for Node* pointer type
typedef Node *NodePtr;

// function prototype
void traverse(Node *head);
void add_head_1(NodePtr &head, dataType num);

// add_head_1_5, which uses reference and pointer;
void add_head_1_5(Node *&head, dataType num);

// add_head_2(), which uses double pointer
void add_head_2(Node **head, dataType num);

// add at tail
void add_tail(NodePtr &head, dataType num);

// TO_DO: search a number

// delete function
void del(NodePtr &head, dataType num);

// big Oh analysis

// doubly linked list

int main()
{

    NodePtr head = nullptr;

    add_head_1(head, 10);
    add_head_1(head, 20);

    add_head_1_5(head, 30);

    add_head_2(&head, 40);

    traverse(head);
}

void traverse(Node *head)
{
    for (Node *tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->next)
    {
        std::cout << tempPtr->data << "\n";
    }
}

void add_head_1(NodePtr &head, dataType num)
{
    Node *temp = new Node(num);
    temp->next = head;
    head = temp;
}

void add_head_1_5(Node *&head, dataType num)
{
    Node *temp = new Node(num);
    temp->next = head;
    head = temp;
}

void add_head_2(Node **head, dataType num)
{
    Node *temp = new Node(num);
    temp->next = *head;
    *head = temp;
}

void add_tail(NodePtr &head, dataType num)
{
    if (head == nullptr)
    {
        add_head_1(head, num);
        return;
    }
    NodePtr curr = head;

    // this loop will point curr to the last node.
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    // the curr should be pointing at the last node
    Node *temp = new Node(num);
    curr->next = temp;
}

void del(NodePtr &head, dataType num)
{
    // case 1: the l.l. is empty
    if (head == nullptr)
    {
        return;
    }

    // case 2: the head node matches the target num
    if (head->data == num)
    {
        NodePtr temp = head;
        head = head->next;
        delete temp;
        return;
    }

    //case 3 & 4
    NodePtr prev = nullptr;
    NodePtr curr = head;
    while (curr != nullptr && curr->data != num)
    {
        prev = curr;
        curr = curr->next;
    }

    // after the loop, either we exhaust the linked list with no matching,
    // or we have found the match.

    // case 3: no match found in linked list
    if (curr == nullptr)
    {
        return;
    }

    // case 4: curr is pointing at the target num
    prev->next = curr->next;
    delete curr;
}
