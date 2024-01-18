#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    FILE *fin;
    //ifstream fin;
    //ofstream fout;
    int s,a[50];
    fin=fopen("file.txt","r");
    int i=0;
    while(fscanf(fin,"%d",&s)>0)
    {
        a[i]=s;
        i++;
    }
    for(int j=0;j<i;j++)
    {
        cout<<a[j]<<" ";
    }
    int sum=0;
    for(int k=0;k<i;k++)
    {
        sum+=a[k];
    }
    float mean;
    mean=sum/float(i);
    cout<<"\nMean : "<<mean<<endl;

    float var;
    for(int k=0;k<i;k++)
    {
        var+=((a[k]-mean)*(a[k]-mean));
    }
    var/=float(i);
    cout<<"\nVariance  : "<<var<<endl;
    float sd;
    sd = sqrt(var);
    cout<<"Standard Deviation : "<<sd;
    fclose(fin);




    return 0;
}
