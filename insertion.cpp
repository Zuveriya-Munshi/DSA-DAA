#include<iostream>
//#include<ctime>
#include<vector>
#include<sys/time.h>
#include<time.h>
#include<math.h>
//#include<cstdlib>
using namespace std;

void in_sort(vector<int> arr, string s){
struct timeval t;
int n = arr.size();
gettimeofday(&t,NULL);
double t1=(double)t.tv_sec + t.tv_usec * 0.000001;
int tmp;
int j,key;
double compare=0;
for(int i = 1;i<n;i++){
    j = i-1;
    key = arr[i];
    compare++;
    while(j>=0 && arr[j]>key){
        //swap(arr[j],arr[i]);
        compare++;
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
//for(int i = 0;i<n;i++){
  //  cout<<arr[i]<<endl;
//}
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
    in_sort(arr,"Best");
    arr.clear();

    for(int i =0;i<n;i++){
        int x = rand() % n;
        arr.push_back(x);
    }
    in_sort(arr,"Average");

    arr.clear();
    for(int i =n;i>0;i--){
        arr.push_back(i);
    }
    in_sort(arr,"Worst");
    return 0;
 }

