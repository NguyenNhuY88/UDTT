#include<iostream>
using namespace std;

int a[12];
int n;

void Print()
{
     for(int i=1;i<=n;i++)
     cout<<a[i];
     cout<<"\n";
}
void MyTry(int k)
{
     if(k==n) Print();
     else
     {
          a[k+1]=0; MyTry(k+1);
          a[k+1]=1; MyTry(k+1);
     }
}

int main()
{
     cin>>n;
     MyTry(0);
}
