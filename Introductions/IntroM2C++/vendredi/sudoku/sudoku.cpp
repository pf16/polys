//Version du 30 septembre 2013, Dominique Bernardi
#include <iostream>
#include <fstream>
using namespace std;

const int lig = 3, col = 3, s = lig * col;
inline int rect (int l, int c) {return (l/lig)*lig + c/col;}

bool ligne[s][s], colonne[s][s], rectangle[s][s];
// ligne[l][x] (== true) signifie que la valeur x+1 n'aaparait pas en ligne l.
int valeur[s][s];

void efface ()
{
  for (int l = 0; l < s; l++)
    for (int c = 0; c < s; c++)
      ligne[l][c] = colonne[l][c] = rectangle[l][c] = true;
}

void affiche ()
{
  for (int l = 0; l < s; l++)
    {
      for (int c = 0; c < s; c++)
	if (int v = valeur [l][c]) cout << v; else cout << '.';
      cout << endl;
    }
  cout << endl;
}

void lis (const char *fname)
{
  ifstream f(fname);
  for (int l = 0; l < s; l++, f.get())
    for (int c = 0; c < s; c++)
      {
	int x = f.get() - '1'; if (x < 0 || x >= s) x = -1;
	if ((valeur[l][c] = x + 1))
	  ligne[l][x] = colonne[c][x] = rectangle[rect(l,c)][x] = false;
      }
}

void explore (int l, int c)
{
  if (l == s) {affiche (); return;}
  if (c == s) {explore (l + 1, 0); return;}
  if (valeur[l][c]) {explore (l, c + 1); return;}
  for (int x = 0; x < s; x++)
    if(ligne[l][x] && colonne[c][x] && rectangle[rect(l,c)][x])
      {
	ligne[l][x] = colonne[c][x] = rectangle[rect(l,c)][x] = false;
	valeur[l][c] = x + 1; explore (l, c + 1); valeur[l][c] = 0;
	ligne[l][x] = colonne[c][x] = rectangle[rect(l,c)][x] = true;
      }
}

void essai(const char * fname) {efface (); lis(fname); affiche (); explore (0, 0);}

int main (int argc, char * const argv[])
{
  essai ("test1.dta"); essai ("test2.dta"); essai ("test3.dta"); essai ("test4.dta");
  return 0;
}
