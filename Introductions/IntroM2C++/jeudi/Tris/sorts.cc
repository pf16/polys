#include <iostream>#include <iomanip>#include <cstdlib>#include <cmath>#include <time.h>using namespace std;class Table { protected:  int longueur;  float *valeurs; public:  const char *nom;  Table(int);  float& operator[] (int);  void hasard();  bool triee();  virtual void tri() = 0;  void teste();  friend ostream& operator<< (ostream&, const Table&);  ~Table() {    //    cerr << "Destruction d'un tableau de longueur " << longueur << endl;    delete[] valeurs;  }};Table::Table (int n){//  cerr << "Creation d'un tableau de longueur " << n << endl;  longueur = n;   nom = "";  valeurs = new float[n];}float& Table::operator[] (int n) {  if ((n < 0) || (n >= longueur))    {      cerr << "Acces incorrect a l'element d'indice " << n << endl;      exit(0);    }  return valeurs[n];}void Table::hasard (){  for (int i = 0; i < longueur; i++) valeurs[i] = rand() / (float)RAND_MAX;}bool Table::triee (){  for (int i = 1; i < longueur; i++) if (valeurs[i-1] > valeurs[i]) return false;  return true;}ostream& operator<< (ostream& s, const Table& t){  for (int i = 0; i < t.longueur; i++) s << t.valeurs[i] << " ";  return s << endl;}void Table::teste(){  hasard();  cout << nom << " " << flush;//  cout << *this;  clock_t depart = clock();  tri();  cout << (clock() - depart) / (float)CLOCKS_PER_SEC << endl;//  cout << *this;  if (!triee()) cout << "Erreur...";}class BubbleTable : public Table { public:  BubbleTable(int n) : Table(n) {nom = "Tri a bulle";}  void tri();};void BubbleTable::tri(){  for (int n = longueur; --n;)    for (int i = 0; i < n; i++)      if (valeurs[i] > valeurs[i + 1])      {        float x = valeurs[i];        valeurs[i] = valeurs[i + 1];        valeurs[i + 1] = x;      }}class SelectTable : public Table { public:  SelectTable(int n) : Table(n) {nom = "Tri par selection";}  void tri();};void SelectTable::tri(){  int i, j, n;  for (n = longueur; --n;)  {    float x = valeurs[i = n];    for(j = 0; j < n; j++)      if (valeurs[j] > x) x = valeurs[i = j];    valeurs[i] = valeurs[n];    valeurs[n] = x;   }}class InsertTable : public Table { public:  InsertTable(int n) : Table(n) {nom = "Tri par insertion";}  void tri();};void InsertTable::tri(){  for(int i = 1; i < longueur; i++)  {    int j;    float x = valeurs[i];    for (j = i; j && (valeurs[j - 1] > x); j--)      valeurs[j] = valeurs[j - 1];    valeurs[j] = x;  }}class ShellTable : public Table { public:  ShellTable(int n) : Table(n) {nom = "Tri de Shell";}  void tri();};void ShellTable::tri(){  int h;  for(h = 1; h <= longueur; h = 3 * h + 1);  while(h /= 3)    for(int i = h; i < longueur; i++)    {      float x = valeurs[i];      int j;      for (j = i; (j >= h) && (valeurs[j - h] > x); j -= h)	valeurs[j] = valeurs[j - h];      valeurs[j] = x;    }}class HeapTable : public Table {  void sift (int l, int r); public:  HeapTable(int n) : Table(n) {nom = "Tri par tas";}  void tri();};void HeapTable::sift(int l, int r){  float x = valeurs[l];  for(int j = 2 * l + 1; j < r; l = j, j = 2 * l + 1)  {    if ((j + 1 < r) && (valeurs[j] < valeurs[j + 1])) j++;    if (valeurs[j] <= x) break;    valeurs[l] = valeurs[j];  }  valeurs[l] = x;}void HeapTable::tri(){  int n;  for (n = longueur / 2; n--;) sift(n, longueur);  for (n = longueur; --n;)  {    float x = valeurs[0];    valeurs[0] = valeurs[n];    valeurs[n] = x;    sift(0, n);  }}class QuickTable : public Table {  void quick (int l, int r); public:  QuickTable (int n) : Table(n) {nom = "Tri rapide";}  void tri();};void QuickTable::quick(int l, int r){  while (r - l > 1)  {    float x = valeurs[(l + r) / 2];    int i, j;    for(i = l, j = r - 1; i <= j; i++, j--)    {      while (valeurs[i] < x) i++;      while (valeurs[j] > x) j--;      if (i > j) break;      float y = valeurs[i]; valeurs[i] = valeurs[j]; valeurs[j] = y;    }    if (r - i > j + 1 - l)      {quick(l, j + 1); l = i;}    else      {quick(i, r); r = j + 1;}  }}void QuickTable::tri() {quick (0, longueur);}int main(){  int taille;  for(;;)  {    cout << "Donnez la taille des tableaux: ";    cin >> taille;    if (taille < 2) break;    if (taille <= 100000)      {	{BubbleTable(taille).teste();}	{SelectTable(taille).teste();}	{InsertTable(taille).teste();}      }    {ShellTable(taille).teste();}    {HeapTable(taille).teste();}    {QuickTable(taille).teste();}    cout << endl;  }  return 0;}