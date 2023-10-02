#include <iostream>
#include <fstream>
using namespace std;

struct TodoList
{
    int srno;
    string taskdesc;
    string status;
};

class Tasks
{
    public:
        TodoList task;
        void AddTask();
        void DisplayTask();
        void SearchTask();
        void RemoveTask();
        void MarkTask();
        void ModifyTask();
};

void Tasks::AddTask()
{
    cout << "\n======================================================================\n";

    char ans;
    ofstream fout;

    fout.open("TodoList.txt", ios::out | ios::binary);

    if (!fout.is_open())
    {
        cout << " --> To-do List can not be opened ";
        exit(0);
    }

    do
    {
        cout << "\n >> Enter Sr No Of Task   ::  ";
        cin >> task.srno;

        cout << "\n >> Enter Task Description      ::  ";
        cin >> task.taskdesc;

        cout << "\n >> Enter Status Of Task  ::  ";
        cin >> task.status;

        fout.write((char *)&task, sizeof(task));

        cout << "\n >> Do You Want To Add More Tasks 'y' For Yes :: ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << "\n======================================================================\n";
    
    fout.close();
}

void records::DisplayTask()
{
    cout << "\n======================================================================\n";

    ifstream fin;

    fin.open("TodoList.txt", ios::in | ios::binary);

    if (!fin) // file not found
    {
        cout << "\n --> To-do List Not Found ! \n Check Local Directory, Or Try Creating The To-do List First From Menu Option \n ";
        return;
    }

    else
    {
        fin.read((char *)&task, sizeof(task)); // read first record

        cout << " \n Sr No \t\t Task Description \t\t Task Status ";

        while (!fin.eof()) // read file till  end of file
        {
            cout << "\n   "
                 << task.srno << " \t\t  " << task.taskdesc << " \t\t  " << task.status;

            fin.read((char *)&task, sizeof(task));
            // read next record
        }
    }

    cout << "\n\n======================================================================\n";

    fin.close();
}

void records::SearchTask()
{
    cout << "\n======================================================================\n";

    int sr;
    ifstream fin;

    fin.open("TodoList.txt", ios::in | ios::binary); // open file in reading mode
    bool flag = false;

    cout << "\n >> Enter Sr No :: ";
    cin >> sr;

    if (!fin)
    {
        cout << " --> Error ! ";
    }

    else
    {
        while (!fin.eof()) 
        {
            fin.read((char *)&task, sizeof(task));

            if (task.srno == sr) 
            {
                flag = true; // set flag
                cout << "\n --> Task List Found ... \n";
                cout << " \n \t Sr No \t\t\t Task Description \t\t\t Task Status;
                cout << "\n"<< task.srno << "\t" << task.taskdesc << "\t" << task.status;
                break;
            }
        }
    }

    if (flag == 0) 
    {
        cout << "\n --> Task Not Found ! \n";
    }

    cout << "\n======================================================================\n";

    fin.close();
}

void records::RemoveTask()
{
    cout << "\n======================================================================\n";

    int rno, flag = 0;

    cout << "\n >> Enter Sr No of The Task :: ";
    cin >> rno;

    fstream fin("TodoList.txt", ios::in | ios::binary); // open file in read mode
    fstream fout("temp.txt", ios::out | ios::binary);  // create new temp file for temporary data storage

    if (!fin)
    {
        cout << "\n --> To-do List Not Found !\n Check Local Directory, Or Try Creating The To-do List First From Menu Option \n ";
        return;
    }

    else
    {
        fin.read((char *)&task, sizeof(task));

        while (!fin.eof())
        {
            if (task.srno != rno) // if current record is not that to be updated
            {
                fout.write((char *)&task, sizeof(task)); // write to the temp file
            }

            else // if current record is that ts to be updated
            {
                cout << "\n --> Record Found and RemoveTaskd! \n";
                flag = 1;
            }

            fin.read((char *)&task, sizeof(task)); // read next record from the
        }

        fin.close();
        fout.close();
        remove("TodoList.txt");
        rename("temp.txt", "TodoList.txt");

        if (flag == 0) // flag remained same then
        {
            cout << "\n --> Record With Roll No " << rno << " Is Not Found In The File 'StudentData.dat' \n";
        }
    }

    cout << "\n======================================================================\n";

}

void records::MarkTask()
{
    cout << "\n======================================================================\n";

    cout << "\n >>> Fill Student Details :- \n \n ";

    // cin.ignore();

    fstream fout("TodoList.txt", ios::app | ios::binary); // open file in append mode
    fstream fin("TodoList.txt", ios::in | ios::binary);   // open file in read with different pointer
    student rec1;

    fin.read((char *)&rec1, sizeof(rec1));

    int flag = 0;

    while (!fin.eof()) // read file till end for roll no. validity check
    {
        if (rec1.srno == task.srno)
        {
            cout << "\n Student With Roll No. " << task.srno << " already exist !\n";
            flag = 1;
            break;
        }

        else
        {
            fin.read((char *)&rec1, sizeof(rec1)); // read next record
        }
    }

    if (flag == 0) // if roll no. is unique then only write to the file
    {
        cout << "\n >> Name     ::  ";
        cin >> task.taskdesc;
        cout << "\n >> Address  ::  ";
        cin >> task.add;
        cout << "\n >> Roll No  ::  ";
        cin >> task.srno;
        cout << "\n Division    ::  ";
        cin >> task.status;

        fout.write((char *)&task, sizeof(task)); // write to the file
        cout << "\n --> Record Added Successfully To The File !\n";
    }
    cout << "\n======================================================================\n";

    fin.close();
}

void records::ModifyTask()
{
    cout << "\n======================================================================\n";

    int rno, flag = 0;

    cout << "\n >> Enter Roll No Of The Student  ::  ";
    cin >> rno;

    ifstream fin;
    fin.open("TodoList.txt", ios::in | ios::binary); // open file in read mode
    ofstream fout;
    fout.open("temp.txt", ios::out | ios::binary); // create new temp file for temporary data storage

    if (!fin)
    {
        cout << " \n --> File Not Found !\n Check Local Directory, Or Try Creating The File First From Menu Option \n ";
        return;
    }
    else
    {
        fin.read((char *)&task, sizeof(task));

        while (!fin.eof())
        {
            if (task.srno != rno) // if current record is not that to be updated
            {
                fout.write((char *)&task, sizeof(task)); // write to the temp file
            }
            else // if current record is that ts to be updated
            {
                cout << "\n --> Record Found ! \n";
                flag = 1;
                cout << " \n >>> Fill student details :- \n ";
                cout << "\n >> Name      ::  ";
                cin >> task.taskdesc;
                cout << "\n >> Roll No   ::  " << rno;
                task.srno = rno;
                cin.ignore();
                cout << "\n >> Address   ::  ";
                cin >> task.add;
                cout << "\n >> Division  ::  ";
                cin >> task.status;
                fout.write((char *)&task, sizeof(task));                          // write to the file
                cout << "\n --> Record Updated Successfully To The File ! \n "; // write updated record to the temp file
            }
            fin.read((char *)&task, sizeof(task)); // read next record from the
        }
        fin.close();
        fout.close();

        remove("TodoList.txt");
        rename("temp.txt", "TodoList.txt");

        if (flag == 0) // flag remained same then
        {
            cout << "\n --> Record With Roll No " << rno << " Is Not Found In The File 'TodoList.txt' \n";
        }
    }
    cout << "\n======================================================================\n";

}

int main()
{
    records obj;
    int ch, key;
    char ans;

    cout << "\n \t\t ===============================";
    cout << "\n \t\t ||   FILE HANDLING PROGRAM   ||";
    cout << "\n \t\t =============================== \n ";

    do
    {
        cout << "\n======================================================================\n";
        cout << "\n >>> Student Information :- " << endl;
        cout << "\n 1] Add a New Task \t\t 2] Display the Task List  \n\n 3] Remove a Task \t\t 4] Search a Task \n\n 5] Mark a Task as Done \t\t 6] Modify a Task \n\n 7] Exit To-do List ";
        cout << "\n\n >> Enter Your Choice :: ";
        cin >> ch;

        cout << "\n======================================================================\n";

        switch (ch)
        {
        case 1:
            obj.AddTask();
            break;
        case 2:
            obj.DisplayTask();
            break;
        case 3:
            obj.RemoveTask();
            break;
        case 4:
            obj.SearchTask();
            break;
        case 5:
            obj.MarkTask();
            break;
        case 6:
            obj.ModifyTask();
            break;
        }
    } while (ch != 7);

    cout << "\n --> To-do List Exited Successfully \n ";
    cout << "\n======================================================================\n";

    return 1;
}
