#include <iostream>
using namespace std;

#define N       5
#define ARRLEN 10


void ndsort(int b[]) {
	int i = 0, j = 0;
	
	
	
	for ( j = 1; j < ARRLEN; j++ ) {
		int key = b[j];
		i = j - 1;
		
		while ( i >= 0 && b[i] > key) {

			b[i + 1] = b[i];
			i = i - 1;
		}
		b[i + 1] = key;
	}
}

void nisort(int b[]) {
	int i = 0, j = 0;
	
	
	
	for ( j = 1; j < ARRLEN; j++ ) {
		int key = b[j];
		i = j - 1;
		
		while ( i >= 0 && b[i] < key) {

			b[i + 1] = b[i];
			i = i - 1;
		}
		b[i + 1] = key;
	}
}

int lsearch(int b[], int v) {
	
	for ( int i = 0; i < ARRLEN; i++)
		if (b[i] == v)
			return i;
	
	return 0;
}

void bsumm(int c[], int b1[], int b2[]) {
	int i, tmp = 0;
	
	for ( i = N - 1; i >= 0; i-- )
		cout << "i = " << i << endl;
		tmp = c[i + 1] + b1[i] + b2[i];
		switch(tmp) {
			case 0:
				c[i + 1] = 0;
				break;
			case 1:
				c[i + 1] = 1;
				break;
			case 2:
				c[i + 1] = 0;
				c[i] = 1;
				break;
			case 3:
				c[i + 1] = 1;
				c[i] = 1;
				break;
		}
}

int main() {
	int a[ARRLEN] = {1,6,4,2,4,5,6,7,8,2};
	
	cout << "Before:" << endl;
	
	for (int i = 0; i< ARRLEN; i++) {
		cout << a[i] << ";";
	}
	cout << endl;
	
	ndsort(a);
	
	cout << "Non-decreasing order:" << endl;
	
	for (int i = 0; i< ARRLEN; i++) {
		cout << a[i] << ";";
	}
	cout << endl;
	
	nisort(a);
	
	cout << "Non-increasing order:" << endl;
	
	for (int i = 0; i< ARRLEN; i++) {
		cout << a[i] << ";";
	}
	cout << endl;
	
	int v = 3;
	
	int videx = lsearch(a, v);
	
	cout << videx << endl;
	
	int b1[N] = {1,0,0,1,1};
	int b2[N] = {1,0,1,1,1};
	int c[N + 1] = {0,0,0,0,0};
	
	bsumm(c, b1, b2);
	
	for (int i = 0; i < N; i++)
		cout << c[i] << ";";
		
	cout << endl;
	
	return 0;
}
