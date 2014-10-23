
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
#define E 200

struct tree_node;

struct list_node{
	struct tree_node* data;
	struct list_node* next;
};

struct list{
	struct list_node* first;
	struct list_node* last;
	int size;
};

struct tree_node{
	int color;
	int number;
	struct list edges;
};

void add_edge(struct tree_node * a, struct tree_node * b){
	struct list * plist = &a->edges;
	struct list_node * node_add  = malloc(sizeof (struct list_node));
	node_add->next = NULL;
	node_add->data = b;
	if (plist->first){
		plist->last->next = node_add;
		plist->last = node_add;
	}else{
		plist->last = node_add;
		plist->first = node_add;
	}
	plist->size++;
}

int n, m;
int value[N];
struct tree_node v[N];

void travel_tree_node(struct tree_node * u){
	u.color = 1;
	struct list * plist = &u->edges;
	struct list_node * p = plist->first;
	
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
	return 0;
}

