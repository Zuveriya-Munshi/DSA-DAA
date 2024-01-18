#include<iostream>
#include<map>
#define max 5
using namespace std;
class mapping
{
    int freq;
    string name;
    map<string,int> data;
public:
    void get();
    void lexiograph();
    void display();
};
void mapping::get()
{
    for(int i=0;i<max;i++)
    {
        cout<<"\nEnter string : ";
        cin>>name;

        data[name]++;
    }
}
void mapping::display()
{
    map<string,int>::iterator it = data.begin();
    cout<<"\n\n\t String \t\t Frequency "<<endl;
    while(it!=data.end())
    {

        cout<<"\t"<<it->first<<"\t\t"<<it->second<<endl;
        it++;
    }
}

int main()
{
    mapping m1;
    m1.get();
    m1.display();
   // m1.lexiograph();
    return 0;
}
