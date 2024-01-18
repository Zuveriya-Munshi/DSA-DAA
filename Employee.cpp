#include <iostream>
#include <fstream>
#include<conio.h>
using namespace std;
class Employee
{
    int empID;
    char empName[20];
    char addr[15], dept[20], pos[10];
    int salary;

public:
    void getData()
    {
        cout << "Enter Employee Id : ";
        cin >> empID;
        cout << "Enter Employee Name : ";
        cin >> empName;
        cout << "Enter Employee Address : ";
        cin >> addr;
        cout << "Enter Department : ";
        cin >> dept;
        cout << "Enter Position : ";
        cin >> pos;
        cout << "Enter Salary : ";
        cin >> salary;
    }
    void display()
    {
        cout << "Employee ID   : " << empID << endl;
        cout << "Employee Name : " << empName << endl;
        cout << "Address       : " << addr << endl;
        cout << "Department    : " << dept << endl;
        cout << "Position      : " << pos << endl;
        cout << "Salary        : " << salary << endl<<endl;
    }
    int getId()
    {
        return empID;
    }
};
void AddEmp();
void seachEmp();
void dispAll();
void deleteEmp();
void updateEmp();
Employee e;
fstream f;
int main()
{

    int ch;

    while (true)
    {
        system("cls");
        cout << "\n 1) Add an Employee \n 2) Search an Employee \n 3) Update an Employee \n 4) Delete an Employee \n 5) Display \n 6) Exit";
        cout << "\nEnter your choice  : ";
        cin >> ch;
        switch (ch)
        {
        case 1:

            AddEmp();
            cout<<"\nEmployee is Added";
            cout << "\nEnter any key...";
            getch();
            break;


        case 2:

            seachEmp();
            cout << "\nEnter any key...";
            getch();

            break;

        case 3:
          updateEmp();
          cout<<"\nEmployee Records are updated";
            cout << "\nEnter any key...";
            getch();

            break;

        case 4:


            deleteEmp();
            cout<<"\nEmployee Deleted";
            cout << "\nEnter any key...";
            getch();

            break;

        case 5:
            cout<<"\nEmployee Details";
            dispAll();
            cout << "\nEnter any key...";
            getch();

            break;

        case 6:
            exit(0);
        default:
            cout << "\nInvalid Choice ";
            exit(0);
            break;
        }
    }

    return 0;
}

void AddEmp()
{
    char ch = 'y';
    f.open("emp.txt", ios::out | ios::app);
    while (ch == 'y' || ch == 'Y')
    {
        e.getData();
        f.write((char *)&e, sizeof(e));
        cout << "Add more Employee.. ? ";
        cin >> ch;
    }

    f.close();
}
void seachEmp()
{
    int empID, flag = 0;
    f.open("emp.txt", ios::in);
    if (!f)
    {
        cout << "\nFile not found";
    }
    else
    {
        cout << "\nEnter id of the Employee to be searched : ";
        cin >> empID;
        f.read((char *)&e, sizeof(e));
        while (!f.eof())
        {
            if (empID == e.getId())
            {
                flag = 1;
                e.display();
           }
            f.read((char *)&e, sizeof(e));
        }
        if (flag == 0)
        {
            cout << "\nEmployee not found";
        }
    }
    f.close();
}
void updateEmp()
{
    int x, empID;
    cout << "\nEnter id to be update : ";
    cin >> empID;
    f.open("emp.txt",ios::in|ios::out);
    if (!f)
    {
        cout << "\nFile not found";
        exit(0);
    }
    while(f.read((char *)&e, sizeof(e)))
    {
        if(e.getId()==empID)
        {
            e.getData();
            int pos=sizeof(e);
            f.seekp(-pos,ios::cur);
            f.write((char *)&e, sizeof(e));
        }
    }

    f.close();
}
void deleteEmp()
{
    int empID;
    cout << "\nEnter id to be Delete : ";
    cin >> empID;
    ofstream f1;
    f1.open("new.txt",ios::out);
    f.open("emp.txt",ios::in);
    if (!f)
    {
        cout << "\nFile not found";
        exit(0);
    }
    else
    {
        f.read((char *)&e, sizeof(e));
         while (!f.eof())
        {
            if (empID != e.getId())
            {

                f1.write((char *)&e, sizeof(e));
            }
            f.read((char *)&e, sizeof(e));
        }


    }



    f1.close();
    f.close();
    remove("emp.txt");
    rename("new.txt","emp.txt");
}
void dispAll()
{
    f.open("emp.txt", ios::in);
    if (!f)
    {
        cout << "\nFile not found";
        exit(0);
    }

    else
    {
        f.read((char *)&e, sizeof(e));
        while (!f.eof())
        {
            e.display();
            f.read((char *)&e, sizeof(e));
        }
    }
    f.close();
}
