#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

class Process
{
private:
    int id;            // process id
    int arrival_time;  // arival time
    int time_needed;   // burst time
    int finished_time; // finished time
public:
    // default constructor
    Process()
    {
        finished_time = -1;
    }

    // constructor with arguments
    Process(int a, int b, int c)
    {
        id = a;
        arrival_time = b;
        time_needed = c;
        finished_time = -1;
    }

    // setter functions
    void setID(int a)
    {
        id = a;
    }
    void setArrivalTime(int a)
    {
        arrival_time = a;
    }
    void setTimeNeeded(int a)
    {
        time_needed = a;
    }
    void setFinishedTime(int a)
    {
        finished_time = a;
    }

    // getter functions
    int getID()
    {
        return (id);
    }
    int getArrivalTime()
    {
        return (arrival_time);
    }
    int getTimeNeeded()
    {
        return (time_needed);
    }
    int getFinishedTime()
    {
        return (finished_time);
    }
};

// process finish , and update finished time
void finish(Process *p, int s, int id, int t)
{
    for (int i = 0; i < s; i++)
    {
        if (p[i].getID() == id)
        {
            p[i].setFinishedTime(t);
            break;
        }
    }
}

// print all process
void print(Process *p, int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << "Process ID : " << p[i].getID();
        cout << " , Arrival Time : " << p[i].getArrivalTime();
        cout << " , Time Needed : " << p[i].getTimeNeeded();
        cout << " , Finished Time : " << p[i].getFinishedTime();
        cout << endl;
    }
}

// main function
int main()
{
    ifstream in("r.txt");
    ;

    // 5 process in array
    Process *p = new Process[5];
    int a, b, c;

    // taking input from file

    for (int i = 0; i < 5; i++)
    {
        in >> a;
        in >> b;
        in >> c;
        p[i].setID(a);
        p[i].setArrivalTime(b);
        p[i].setTimeNeeded(c);
    }

    cout << "Finished input taking";

    int time_frame = 4; // frame sate by 4

    queue<Process> queue; // for ready process

    vector<int> vec;  // process ids from algorithm
    vector<int> vect; // corresponding finished time of process

    // set initial time
    int time = 0;

    // for checking , either process arrived or not

    // 0 mean not arrived
    // 1 mean arrived

    int *count = new int[5];
    for (int i = 0; i < 5; i++)
    {
        count[i] = 0;
    }

    // initially lod ready process in queue
    for (int i = 0; i < 5; i++)
    {
        if (p[i].getArrivalTime() <= time && count[i] == 0)
        {
            queue.push(p[i]);
            count[i] = 1;
        }
    }

    // loop continue until queue is empty
    while (!queue.empty())
    {
        // get first process from queue
        Process cur = queue.front();
        queue.pop(); // pop from queue

        // if execution time of current process is less tha 4
        if (cur.getTimeNeeded() < 4)
        {
            time += cur.getTimeNeeded();

            // edit finish witn time
            finish(p, 5, cur.getID(), time);

            // check all process are arrived or not
            for (int i = 0; i < 5; i++)
            {
                if (count[i] == 0 && p[i].getArrivalTime() <= time)
                {
                    queue.push(p[i]);
                    count[i] = 1;
                }
            }

            // id
            vec.push_back(cur.getID());
            //time
            vect.push_back(cur.getTimeNeeded());
        }
        else
        {
            // set remainning time to execute
            cur.setTimeNeeded(cur.getTimeNeeded() - 4);
            time += 4;

            // check all process are arrived or not
            for (int i = 0; i < 5; i++)
            {
                if (count[i] == 0 && p[i].getArrivalTime() <= time)
                {
                    queue.push(p[i]);
                    count[i] = 1;
                }
            }

            // if time ramain for next execution , then load in queue
            if (cur.getTimeNeeded() > 0)
            {
                queue.push(cur);
            }
            else
            {
                // edit finish witn time
                finish(p, 5, cur.getID(), time);
            }

            //id
            vec.push_back(cur.getID());
            //time
            vect.push_back(4);
        }
    }

    // reset time
    time = 0;

    // print process id with time
    for (int i = 0; i < vec.size(); i++)
    {
        cout << endl
             << "[ Process ID " << vec.at(i) << " ] " << time << "-" << (time + vect.at(i));
        time += vect.at(i);
    }

    cout << "\n\nProcesses are :-\n";
    print(p, 5);

    system("pause");

    return (0);
}