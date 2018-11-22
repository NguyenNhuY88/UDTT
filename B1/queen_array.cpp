#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int A[100],n;
int Cost[100][100];
int maxSum = 0;
//int result[100];

//void Show()
//{
//    for(int i=0;i<n;i++)
//    {
//        for(int j =0; j < n; j++)
//        {
//            if(result[i]==j)
//            {
//                cout<<" x ";
//            }
//            else cout  <<" O ";
//        }
//        cout<<endl;
//    }
//}

void CalCost()
{
    int sum= 0;
    for(int i=0;i<n;i++)
    {
        for(int j =0; j < n; j++)
        {
            if(A[i]==j)
            {
                sum+=Cost[i][j];
                cout<<" x ";
            }
            else cout  <<" O ";
        }
        cout<<endl;
    }
    cout <<"sum = " << sum;
    cout<<"\n -------------------" << endl;
    if(maxSum < sum)
    {
        maxSum = sum;
//        for(int i = 0; i < n; i++)
//        {
//            result[i] = A[i];
//        }
    }
}

void Queen(int row)
{
    if(row == n)
    {
        CalCost();
    }
    else{
        for(int col = 0; col < n ;++col)
        {
            bool ok = true;
            for(int k=0;k <= row;k++)
            {
                if(A[k]==col||abs(col-A[k])==abs(row-k)){ok=false;break;}
            }
            if(ok)
            {
                A[row] = col;
                Queen(row+1);
            }
        }

    }
}

int main()
{
    ifstream InFile ("queen_MaxSum.txt");
    InFile >> n;
    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
            InFile >> Cost[i][j];
    }

    Queen(0);

    cout<<"Max sum = " << maxSum << endl;

    return 0;
}
