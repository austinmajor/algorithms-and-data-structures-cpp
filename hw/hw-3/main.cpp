#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//Declare node structure
struct node
{
    int data;
    node *next;
};

//Declare LinkedList class
class LinkedList
{
private:
    //Declare head, tail in private
    node *head, *tail;

public:
    //Default Constructor
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    //Add at front function
    void add_at_head(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    //Add at back function
    void add_at_tail(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    //Replace node value function
    void set(int pos, int val)
    {
        node *prev = new node;
        node *curr = new node;
        curr = head;

        for (int i = 0; i < pos - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        curr->data = val;
    }

    //Insert at index function
    void insert(int pos, int val)
    {
        node *prev = new node;
        node *curr = new node;
        node *temp = new node;
        curr = head;

        for (int i = 0; i < pos - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        temp->data = val;
        prev->next = temp;
        temp->next = curr;
    }

    //Delete function
    void del(int pos)
    {
        node *prev = new node;
        node *curr = new node;
        curr = head;

        for (int i = 0; i < pos - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
    }

    //Search for data at index function
    int search(int pos)
    {
        bool found = false;
        node *curr = head;
        int count = 0;
        while (curr != NULL)
        {
            if (count == pos)
            {
                found = true;
                return (curr->data);
            }
            count++;
            curr = curr->next;
        }
        return 0;
    }

    //Traverse function
    void traverse()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    //Reverse Linked List function
    LinkedList reverse()
    {
        LinkedList ll;
        node *curr = head;
        node *prev = NULL;
        node *temp = NULL;

        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ll.head = prev;
        return ll;
    }
};

//Parse function to get first 10 digits of summation
string parse_ans(string ans)
{
    string parse = "";
    for (int i = 0; i < 10; i++)
    {
        parse += ans[i];
    }
    return parse;
}

//Add nums function
//Takes an array of the number at x position for each 50-digit number
int add_nums(int dig[100])
{
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += dig[i];
    }
    return sum;
}

int main(void)
{
    //Variable Declarations
    int sum = 0, digits[100], carry = 0, count = 0;
    string inFile, line, strNum, temp, ans;
    LinkedList listlist[100], reverse;

    inFile = "nums.txt";

    //Read nums.txt file into program
    ifstream readfile(inFile);
    if (readfile.is_open())
    {
        while (getline(readfile, line))
        {
            for (int i = 49; i >= 0; i--)
            {
                //Add each digit of each 50 digit number to its own linked list
                listlist[count].add_at_head((line[i]) - '0');
            }
            count++;
        }

        readfile.close();

        for (int i = 49; i >= 0; i--)
        {
            sum = 0;
            //search for digits at position i for each 50 digit number
            for (int j = 0; j < 100; j++)
            {
                digits[j] = listlist[j].search(i);
            }

            //Add all the digits together
            sum = add_nums(digits);
            //Add the carry from the previous addition
            sum += carry;
            temp = "";
            strNum = to_string(sum);
            for (int j = 0; j < strNum.length(); j++)
            {
                if (j == strNum.length() - 1)
                    //Get right-most digit for final answer
                    ans = strNum[j] + ans;
                else
                    //Get other digits for carry
                    temp += strNum[j];
            }
            carry = stoi(temp);
        }

        ans = temp + ans;

        //Parse for the first 10 digits of the final answer
        cout << "Total: " << ans << endl
             << endl;
        cout << "First 10 digits: " << parse_ans(ans) << endl;
    }
    else
        cout << "Unable to open file.";

    return 0;
}