#include <iostream>
using namespace std;
 
int main() 
{
  cout << "serie des un" << endl;
  float sp,sn;
  sn =0;
  for(int n=0;n<1000000000; n=n+1)
    {
      sp = sn;
      sn = sp +1;
      if( sp == sn) 
	{
	  cout << " n =" << n << " sp =" << sp << endl; 
          break; // on sort de la boucle 
	}
    }
  return 0;
}
