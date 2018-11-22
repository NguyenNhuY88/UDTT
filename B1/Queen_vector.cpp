#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n;
int Cost[100][100];
int maxSum = 0;
void print_queen(const vector<int>& queen)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (queen[i] == j){
                sum+=Cost[i][j];
                cout << " X ";
            }
            else cout << " O ";
        }
        cout << endl;
    }
    cout <<"sum = " << sum;
    cout <<"\n------------\n";
    if(maxSum < sum)
    {
        maxSum = sum;
    }

}

bool consistent(int row, int col, const vector<int>& queen)
{
    int k = queen.size();
    for (int i = 0; i < k; i++) {
        if (col == queen[i]) return false;
       // if (row == i) { cout <<"row = " << i << endl;return false;}
        if (row+col == i+queen[i]) return false;
        if (row-col == i-queen[i]) return false;
    }
    return true;
}

void recursive_backtracking(vector<int>& queen)
{
    if (queen.size() == n) {
        print_queen(queen);
       // return true;
    }
    int row = queen.size(); // select unassigned queen
    for (int col = 0; col < n; col++) {
        if (consistent(row,col,queen)) {
            queen.push_back(col);
          //  bool result = recursive_backtracking(queen);
          //  if (result) return result;
          recursive_backtracking(queen);
            queen.pop_back();
        }
    }
   // return false;
}

int main()
{
   // cin >> n;
    vector<int> queen;

       ifstream InFile ("queen_MaxSum.txt");
    InFile >> n;
    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
            InFile >> Cost[i][j];
    }


    recursive_backtracking(queen);

    cout <<"maxSum = " << maxSum;
    return 0;
}
