#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

// Function to trim leading and trailing whitespaces
string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";  // No non-space characters
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  string queryCntStr;
  getline(cin, queryCntStr);
  int queryCnt = stoi(queryCntStr);

  unordered_map<string, string> phoneBook;

  for (int i = 0; i < queryCnt; ++i)
  {
    string line;
    getline(cin, line);
    stringstream ss(line);

    string name;
    ss >> name;
    string number;
    ss >> number;

    phoneBook[name] = number;

    // cout << "name: " << name << " number: " << number << endl;
  }

  string nameToQuery;
  while(getline(cin, nameToQuery)){
    stringstream ss(nameToQuery);

    string name;
    ss >> name;

    // cout << "nameToQuery: " << nameToQuery << endl;
    // cout << "phoneBook.count(nameToQuery): " << phoneBook.count(nameToQuery) << endl;

    if (phoneBook.count(name) > 0)
    {
      cout << name << "=" << phoneBook[name] << endl;
    }
    else
    {
      cout << "Not found" << endl;
    }
  }

  return 0;
}
