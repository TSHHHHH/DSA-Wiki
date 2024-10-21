#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(n_temp);

  int cnter{};
  int output{};

  while (n > 0)
  {
    if (n % 2 == 1)
    {
      ++cnter;
    }
    else
    {
      if (cnter > output)
      {
        output = cnter;
      }

      cnter = 0;
    }
    n /= 2;
  }

  if (cnter > output)
  {
    output = cnter;
  }

  cout << output << endl;

  return 0;
}
