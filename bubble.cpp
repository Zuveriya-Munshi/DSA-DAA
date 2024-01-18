#include<iostream>
//#include<ctime>
#include<vector>
#include<sys/time.h>
#include<time.h>
#include<math.h>
//#include<cstdlib>
using namespace std;

void bsort(vector<int> arr, string s){
struct timeval t;
int n = arr.size();
gettimeofday(&t,NULL);
double t1=(double)t.tv_sec + t.tv_usec * 0.000001;
int flag=0;
double compare=0;
for(int i = 0;i<n;i++){
    for(int j = 0;j<n-i-1;j++){
        flag = 0;
        compare++;
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1]= temp;
            flag = 1;
        }
    }
    if(flag==0){
        break;
    }
}
      gettimeofday(&t,NULL);
      double t2 = (double)t.tv_sec + t.tv_usec * 0.000001;

      double total = t2 - t1;
      cout<<s<<" Time = "<<total;
      cout<<"\nComparisons : "<<compare<<endl;
}
 int main(){
    vector<int> arr;
    int n;
    cout<<"Enter Number of Elements : ";
    cin>>n;
    for(int i =0;i<n;i++){
        arr.push_back(i);
    }
    bsort(arr,"Best");
    arr.clear();

    for(int i =0;i<n;i++){
        int x = rand() % n;
        arr.push_back(x);
    }
    bsort(arr,"Average");

    arr.clear();
    for(int i =n;i>0;i--){
        arr.push_back(i);
    }
    bsort(arr,"Worst");
    return 0;
 }

