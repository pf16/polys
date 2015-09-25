class Permutation {
	int n;
	int *v;
   public:
	Permutation (int=0);
	Permutation (const Permutation&);
	Permutation (int, const int *);
	~Permutation () {delete [] v;}
	bool next();
	void rand();
	int signature () const;
	int operator[] (int i) {return i <= n ? v[i - 1] + 1 : i;}
	int ordre () const;
	Permutation inverse();
//      bool operator== (const Permutation &) const;
	friend bool operator== (const Permutation &, const Permutation &);
	Permutation& operator= (const Permutation&);
	friend Permutation operator* (const Permutation&, const Permutation&);
	friend ostream& operator<< (ostream&, const Permutation&);
	void printCycles (ostream&) const;
};
