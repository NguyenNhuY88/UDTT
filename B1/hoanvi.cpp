#include <iostream>
using namespace std;
int n;
bool used[123];
int a[123];

void show(){
    int i;

    for (i=1; i<=n; i++)
    {
        cout <<"\t" <<a[i] <<" ";
    }
    cout << endl;
}

void back(int pos){
    int i;
    if (pos==n+1)
    {
         show();

         return ;
    }
    for (i=1; i<=n; i++)
    {
        cout <<"i = " << i << endl;
        if (not used[i]){

        a[pos]=i;
        cout <<"a["<<pos<<"]= " << i << endl;
        used[i]=true;
        cout <<"use["<<i<<"]= " << used[i] << endl;
        back(pos+1);
        used[i]=false;
        cout <<"use["<<i<<"]= " << used[i] << endl;
        }
    }

}

main(){
    cin >> n;
    back(1);
    return 0;
}
