#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &arr, int x, int y, int n)
{
  for (int i = 0; i < x; ++i)
  {
    if (arr[i][y] == 1)
      return false;
  }

  int row = x;
  int col = y;

  while (row >= 0 and col >= 0)
  {
    if (arr[row][col] == 1)
      return false;
    row--;
    col--;
  }

  row = x;
  col = y;

  while (row >= 0 and col < n)
  {
    if (arr[row][col] == 1)
      return false;
    row--;
    col++;
  }

  return true;
}

bool nQueens(vector<vector<int>> &arr, int x, int n)
{
  if (x >= n)
    return true;
  for (int i = 0; i < n; ++i)
  {
    if (isSafe(arr, x, i, n) == true)
    {
      arr[x][i] = 1;
      if (nQueens(arr, x + 1, n) == true)
      {
        return true;
      }
      arr[x][i] = 0;
    }
  }
  return false;
}

int main()
{
  cout << "Enter size of chess board : " << endl;
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n, 0));
  bool flag = nQueens(arr, 0, n);
  cout << flag << endl;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (arr[i][j] == 1)
      {
        cout << "Q" << " ";
      }
      else
        cout << 0 << " ";
    }
    cout << endl;
  }
  return 0;
}