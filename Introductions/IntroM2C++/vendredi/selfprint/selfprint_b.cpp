#include <iostream>
using namespace std;

const char quote = char(34), comma = char(44), * b[] = {
"#include <iostream>",
"using namespace std;",
"",
"const char quote = char(34), comma = char(44), * b[] = {",
"};",
"",
"int main()",
"{",
"  for (int i = 0; i < 4; i++) cout << b[i] << endl;",
"  for (int i = 0; i < 13; i++) {cout << quote << b[i] << quote; if (i < 12) cout << comma; cout << endl;}",
"  for (int i = 4; i < 13; i++) cout << b[i] << endl;",
"  return 0;",
"}"
};

int main()
{
  for (int i = 0; i < 4; i++) cout << b[i] << endl;
  for (int i = 0; i < 13; i++) {cout << quote << b[i] << quote; if (i < 12) cout << comma; cout << endl;}
  for (int i = 4; i < 13; i++) cout << b[i] << endl;
  return 0;
}
