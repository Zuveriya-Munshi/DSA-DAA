#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<process.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n,i;
    char *str,ch;
    if(argc!=3)
    {
        cout<<"Can't open file\n";
        cout<<"Invalid number of arguments! : "<<argc;
        exit(3);
    }
    cout<<"Enter size of the String :";
    cin>>n;
    str = new char[n];
    cout<<"Enter one String :";
    fgets(str,n,stdin);
    cout<<"string is "<<str;
    ofstream fout;
    fout.open(argv[1],ios::out);
    for(i=0;i<str[i];i++)
    {
        fout.put(str[i]);
    }
    fout.close();
    ifstream fin;
    fin.open(argv[1],ios::in);
    fout.open(argv[2],ios::out);
    cout<<"\nContents of the first file : "<<argv[1];
    while(fin)
    {
        fin.get(ch);
        cout<<ch;
        fout.put(ch);

    }
    fin.close();
    fout.close();
    fin.open(argv[2],ios::in);
    cout<<"\nContents of the COPIED file : "<<argv[2];
    while(fin)
    {

        fin.get(ch);
        cout<<ch;
    }
    fin.close();
    getch();

}
