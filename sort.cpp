#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of ele : ";
    cin>>n;
    vector<int>nos(n);

    for(int i=0;i<n;i++)
    {
        cin>>nos[i];
    }
    cout<<"Before Sort\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<nos[i]<<" " ;
    }

    cout<<"After Sort\n\n";
    sort(nos.begin(),nos.end());
    for(int i=0;i<n;i++)
    {
        cout<<nos[i]<<" " ;
    }

    return 0;
}
