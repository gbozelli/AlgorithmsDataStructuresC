#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node *left;
  struct node *right;
  int key;
}node;

typedef struct node * tree;

tree create () {
  return NULL;
}

void print (tree t) {
  printf("%c",t->key);
}

void preorder (tree t) { 
  if (t != NULL) {
    print(t);
    preorder(t->left);
    preorder(t->right);
  }
}


tree insert (tree t, int key) {
  t = malloc(sizeof(node));
  t->left = NULL;
  t->right = NULL;
  t->key = key;
  return t;
};

void insertion (tree t, int key) {
  if (t!=NULL) {
    if (key>t->key) {
      insertion(t->right,key);
    } if (key<t->key) {
      insertion(t->left,key);
    }
  } else {
    t = insert(t,key);
  }
}

tree insertion1 (tree t, int key) {
  tree new = malloc(sizeof(node));
  if (t==NULL) {
    new->left = NULL;
    new->right = NULL;
    new->key = key;
    return new;
  }
  if (key>t->key) {
    insertion1(t->right,key);
  } if (key<t->key) {
    insertion1(t->left,key);
  }
}

tree removet (tree t, int key) {
  free(t);
  t = NULL;
  return t;
};

tree search (tree t, int key) {
  if (t==NULL || t->key == key) {
    return t;
  } if (key > t->key){
    search (t->right,key);
  } else {
    search (t->left, key);
  }
};

tree min(tree t){
  return t;
};

tree max(tree t){
  return t;
};

tree sucess(tree t){
  return t;
};

tree antecess(tree t){
  return t;
};

int main () {
  tree t = create();
  t = insert(t,8);
  t->left = insert(t->left,4);
  t->right = insert(t->right,9);
  t->left->left = insert(t->left->left,3);
  t->left->right = insert(t->left->right,5);
  t->right->right = insert(t->right->right,11);
  t->right->right->right = insert(t->right->right->right,13);
  preorder(t);
  t = insertion1(t,12);
  preorder(t);
  return 0;
}