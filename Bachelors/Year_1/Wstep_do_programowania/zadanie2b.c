#include <stdio.h> 
int main() 
{ 
	int i,j, p,d,t, w1,w2,w3,k1,k2,k3; p = 0; d = 0; t = 0; 
	int tab[3][3] = { {1,2,3}, {3,1,2}, {2,3,1} }; 
	//wiersze
	for(i = 0; i < 3; ++i) 
	{ 
		for(j = 0; j < 3; ++j) 
		{ 
			if(tab[i][j] == 1){ ++p;} 
			if(tab[i][j] == 2){ ++d;} 
			if(tab[i][j] == 3){ ++t;} 
		} 
		if(i == 0 && p == 1 && d == 1 && t == 1)
		{ w1 = 1; } 
		if(i == 1 && p == 1 && d == 1 && t == 1)
		{ w2 = 1; } 
		if(i == 2 && p == 1 && d == 1 && t == 1)
		{ w3 = 1; } 
		p = d = t = 0; 
	} 
	//kolumny
	for(i = 0; i < 3; ++i)
	{ 
		for(j = 0; j < 3; ++j) 
		{ 
			if(tab[j][i] == 1)
			{ ++p;} 
			if(tab[j][i] == 2)
			{ ++d;} 
			if(tab[j][i] == 3)
			{ ++t;} 
		} 
		if(i == 0 && p == 1 && d == 1 && t == 1)
		{ k1 = 1; } 
		if(i == 1 && p == 1 && d == 1 && t == 1)
		{ k2 = 1; } 
		if(i == 2 && p == 1 && d == 1 && t == 1)
		{ k3 = 1; } p = d = t = 0; } 
		if(w1 == 1 && w2 == 1 && w3 == 1)
		{printf(" TAK "); }
		else
		{printf(" NIE ");} 
		return 0;
	}
