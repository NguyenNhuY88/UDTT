#include<iostream>
using namespace std;

int n;
int X[10];
int D[2];
int res = 0;
void printX()
{

    for(int i = 1; i <=n; i++)
    {
        cout <<X[i] <<" ";
    }
    cout << endl;
}
void backtrack(int i)
{
    if(i== n)
    {
        printX();
    }
    else
    {
        if(D[0] >= D[1])
        {
            if(D[0] +1 <= n/2)
            {
                D[0]++;
                X[i+1] = 0;
                backtrack(i+1);
                X[i+1] = 1;
                    backtrack(i+1);
            }
            else
            {
                D[1] ++;
                    X[i+1] = 1;
                    backtrack(i+1);
            }
        }



    }
 /*
    for(int j= 0 ; j < 2; j++)
    {
        //D[0] (
        //D[1]  )
        if(D[j] + 1 <= n/2)
        {
            D[j]++;
            X[i] = j;
            if(D[0] >= D[1])
            {
                if(i ==n)
                {
                    res++;
                    printX();

                }
                else backtrack(i+1);
            }
            D[j]--;
        }
    }
*/
}

int  main()
{
    cin >> n;
    X[n];
    backtrack(1);
   // cout << "\t " << res << endl;
    return 0;
}
