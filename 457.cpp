#include <iostream>
#include <cstring>
using namespace std;

#define DNA_LENGTH 10
#define POPULATION_LENGTH 40

void print_population(int *population) {
	for (int i = 0; i < POPULATION_LENGTH; i++) {
		switch (population[i]) {
			case 0:
				cout << " ";
				break;
			case 1:
				cout << ".";
				break;
			case 2:
				cout << "x";
				break;
			case 3:
				cout << "W";
				break;
		}
	}
	cout << endl;
}

int main(void) {
	int cases;
	int dna[DNA_LENGTH];
	int population[POPULATION_LENGTH];
	int next_population[POPULATION_LENGTH];
	
	cin >> cases;
	
	while (cases--) {
		for (int i = 0; i < DNA_LENGTH; i++)
			cin >> dna[i];
		
		memset(population, 0, POPULATION_LENGTH * sizeof(int));

		
		for (int i = 0; i < 50; i++) {
			if (i == 0) {
				// TODO: if POPULATION_LENGTH is odd then 
				// there should be no -1
				population[POPULATION_LENGTH/2 - 1] = 1;
			} else {
				
				for (int y = 0; y < POPULATION_LENGTH; y++) {
					if (y == 0) {
						next_population[y] = dna[population[y] + population[y + 1]];
					} else if (y == POPULATION_LENGTH - 1) {
						next_population[y] = dna[population[y - 1] + population[y]];
					} else {
						next_population[y] = dna[population[y - 1] + population[y] + population[y + 1]];
					}
				}
				
				for (int y = 0; y < POPULATION_LENGTH; y++)
					population[y] = next_population[y];
			}
			
			print_population(population);
		}
		
		
		if (cases)
			cout << endl;
	}
	
	
	return 0;
}
