
//============================================================================
// Name        : 0012.c
// Author      : sww
// Version     : 1.0
// Time	       : 2014-10-23 20:32:09
//===========================================================================

#include <stdio.h>
#include <stdlib.h>

#define N 101
#define M 101

struct tree_node;

struct list_node{
	struct tree_node* data;
	struct list_node* next;
};

struct list{
	struct list_node* first;
};

struct tree_node{
	int color;
	int number;
	struct list edges;
	int f[M];
};

void add_edge(struct tree_node * a, struct tree_node * b){
	struct list * plist = &a->edges;
	struct list_node * node_add  = malloc(sizeof (struct list_node));
	node_add->next = plist->first;
	node_add->data = b;
	plist->first = node_add;
}

int n, m;
int value[N];
struct tree_node v[N];

void travel_tree_node(struct tree_node * u){
	int i, j;
	u->color = 1;
	struct list * plist = &u->edges;
	struct list_node * p = plist->first;
	while (p){
		if (p->data->color == 0){
			travel_tree_node (p->data);
		}
		p = p->next;
	}
	u->f[1] = value[u->number];
	p = plist->first;
	while (p){
		if (p->data->color == 2){
			struct tree_node * v = p->data;
			for (i=m; i>=2; i--){
				for (j=1; j<i; j++){
					int nvalue = v->f[j] + u->f[i-j];
					if (nvalue > u->f[i]){
						u->f[i]= nvalue;
					}
				}
			}
		}
		p= p->next;
	}
/*	printf("%d:", u->number);
	for (i=1; i<=m; i++)	
		printf(" %d", u->f[i]);
	puts("");
*/
	u->color = 2;
}

int main() {
	int i, a, b;
	scanf("%d %d", &n, &m);
	for (i=1; i<=n; i++){
		scanf("%d", &value[i]);
		v[i].number = i;
	}
	for (i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		add_edge(&v[a], &v[b]);
		add_edge(&v[b], &v[a]);
	}

	travel_tree_node(&v[1]);
	printf("%d\n", v[1].f[m]);
	return 0;
}

