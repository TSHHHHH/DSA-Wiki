#include <iostream>

bool isPalindrome(std::string s)
{
  if (s.size() == 0)
    return true;

  std::string buffer{};

  for (int i = 0; i < s.size(); ++i)
  {
    if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9'))
    {
      buffer += s[i];
    }
    else if ('A' <= s[i] && s[i] <= 'Z')
    {
      buffer += tolower(s[i]);
    }
  }

  auto begin = buffer.begin();
  auto end = buffer.end() - 1;

  while (begin < end)
  {

    if (*begin != *end)
      return false;

    ++begin;
    --end;
  }

  return true;
}

int main()
{
  std::string s = "A man, a plan, a canal: Panama";

  std::cout << isPalindrome(s) << std::endl;

  return 0;
}