#include <stdio.h>
#include <stdlib.h>

struct Wezel{
	int key;
	int rank;
	struct Wezel *p;	
};

struct Wezel *MakeSet(int k){
	struct Wezel *x = malloc(sizeof(struct Wezel));
	x->key=k;
	x->rank=0;
	x->p=x;
	return x;	
}

struct Wezel *FindSet(struct Wezel *x){
	if(x->p != x) return FindSet(x->p);
	return x->p;
}

void Union(struct Wezel *x, struct Wezel *y){
	x=FindSet(x);
	y=FindSet(y);
	if(x->rank > y->rank) y->p=x;
	else{
		x->p=y;
		if(x->rank == y->rank) y->rank++;
	}
}

int main(){
	struct Wezel *Z[10];
	Z[0] = MakeSet(0);
	Z[1] = MakeSet(1);
	Z[2] = MakeSet(2);
	Z[3] = MakeSet(3);
	Z[4] = MakeSet(4);
	Z[5] = MakeSet(5);
	Z[6] = MakeSet(6);
	Z[7] = MakeSet(7);
	Z[8] = MakeSet(8);
	Z[9] = MakeSet(9);
	Union(FindSet(Z[0]),FindSet(Z[1]));
	Union(FindSet(Z[2]),FindSet(Z[3]));
	Union(FindSet(Z[1]),FindSet(Z[2]));
	Union(FindSet(Z[5]),FindSet(Z[6]));
	Union(FindSet(Z[7]),FindSet(Z[8]));
	Union(FindSet(Z[3]),FindSet(Z[5]));
	Union(FindSet(Z[0]),FindSet(Z[7]));
	printf("0 => %d\n",Z[0]->rank);
	printf("1 => %d\n",Z[1]->rank);
	printf("2 => %d\n",Z[2]->rank);
	printf("3 => %d\n",Z[3]->rank);
	printf("4 => %d\n",Z[4]->rank);
	printf("5 => %d\n",Z[5]->rank);
	printf("6 => %d\n",Z[6]->rank);
	printf("7 => %d\n",Z[7]->rank);
	printf("8 => %d\n",Z[8]->rank);
	printf("9 => %d\n",Z[9]->rank);
	return 0;
}
