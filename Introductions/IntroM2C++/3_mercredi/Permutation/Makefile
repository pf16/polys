#  les commentaires
#  $^ la listes des dependances
#  $@  la cible 

CXXFLAGS= -O3 -Wall -Weffc++

all: TestPerm

TestPerm: TestPerm.o Permutation.o
	$(CXX) $^ -o $@

clean:
	-rm *.o *~ TestPerm

## les dependances pour obliger a relancer la compilation
## si l'on modifie un fichier inclus. 

TestPerm.o: Permutation.h
Permutation.o: Permutation.h
