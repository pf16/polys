#include <iostream>
#include <string>
using namespace std;

int main ()
{
  cout << "Comment vous appelez-vous ?\n";
  string s, t;
  cin >> s >> t;
  cout << "Bonjour, " << s + ' ' + t << endl;
}
