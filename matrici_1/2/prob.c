//2. Se citesc n si m	 reprezentand numarul de linii	 
//respectiv de coloane ale unei matrici.Apoi se 
//citesc elementele matricii.
//Sã se determine câte coloane ale matricei 
//au elementele distincte douã câte douã.				

#include<stdio.h>

#define MAX 100

void read_matrix(int a[MAX][MAX], int n, int m)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

}

void print_matrix(int a[MAX][MAX], int n, int m)
{
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			//printf("%d ", a[i][j]);
		}
		//printf("\n");
	}

}


int main() {

	int n, m, matrix[MAX][MAX];
	scanf("%d%d", &n, &m);
	int pereche_gasita;
	int numaram_la_linii = 0;

	read_matrix(matrix, n, m);
	
	for (int j = 0; j < m; j++) {
		pereche_gasita = 0;
		for (int i = 0; i < n; i++) {
			if (matrix[i][j] == matrix[i+1][j]) {
				pereche_gasita=1;
				//printf(" omg %d %d---- %d",i, j, pereche_gasita);
			}
			else
				continue;
		}
		//printf("\n");
		if (pereche_gasita!=0)
			numaram_la_linii++;
	}
	//printf("\n");

	
	//printf("\n");

	//print_matrix(matrix, n, m);
	
	//printf("\n");

	int distincte;
	distincte = m - numaram_la_linii;

	printf("%d\n", distincte);
	//printf("%d\n", numaram_la_linii);

	return 0;
}
