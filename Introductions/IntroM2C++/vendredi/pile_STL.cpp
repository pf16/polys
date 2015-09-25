#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<int> l;
  for (int i = 0; i < 10; i++)
    l.push(i);
  while (!l.empty())
    {
      cout << l.top() << endl;
      l.pop();
    }
}
