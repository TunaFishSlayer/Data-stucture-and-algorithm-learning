#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct nnode {
  char key[256];
  struct nnode *left;
  struct nnode *rsib;
};
 
struct ntree {
  struct nnode *root;
  long size;
};

struct nnode *nnode(const char *key) {
  struct nnode *n = malloc(sizeof(struct nnode));
  strcpy(n->key, key);
  n->left = n->rsib = NULL;
}
 
struct ntree *ntree() {
  struct ntree *t = malloc(sizeof(struct ntree));
  t->root = NULL;
  t->size = 0;
}
 
int nloop(struct nnode *n, void *u,int (*cb)(struct nnode *n, void *u)) {
  if (!n) {
    return 0;
  }
  if (cb(n, u)) {
    return 1;
  }
  if (nloop(n->left, u, cb)) {
    return 1;
  }
  if (nloop(n->rsib, u, cb)) {
    return 1;
  }
  return 0;
}
 
struct nk {
  struct nnode *n;
  const char *k;
};
 
int ncmp_key(struct nnode *n, void *u) {
  struct nk *nk = u;
  if (strcmp(n->key, nk->k) == 0) {
    nk->n = n;
    return 1;
  }
  return 0;
}
 
struct nnode *nfind(struct ntree *t, const char *key) {
  struct nk nk = {NULL, key};
  nloop(t->root, &nk, ncmp_key);
  return nk.n;
}
 
struct ntree *nadd(struct ntree *t, const char *pkey,const char *nkey) {
  if (t->root == NULL) {
    t->root = nnode(nkey);
    return t;
  }
  struct nnode *p = nfind(t, pkey);
  if (!p) {
    return NULL;
  }
  struct nnode *nn = nnode(nkey);
  if (p->left == NULL) {
    p->left = nn;
    return t;
  }
  struct nnode *x = p->left;
  while (x->rsib != NULL) {
    x = x->rsib;
  }
  x->rsib = nn;
  return t;
}
 
int nprint_node(struct nnode *n, void *u) {
  printf("%s:", n->key);
  struct nnode *x = n->left;
  while (x) {
    printf(" %s", x->key);
    x = x->rsib;
  }
  printf("\n");
  return 0;
}
 
void nprint(struct ntree *t) {
  nloop(t->root, NULL, nprint_node);
}
int main() {
  struct ntree *t = ntree();
  char child[21],parent[21];
  scanf("%s %s",&child,&parent);
  nadd(t,NULL,parent);
  nadd(t,parent,child);
  while(scanf("%s %s", &child, &parent) > 1) {       
        if(strcmp(child, "***") == 0 ) {
            break;
        }
        nadd(t,parent,child);}
  nprint(t);
}
