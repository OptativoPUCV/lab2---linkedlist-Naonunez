#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *Lista=(List*) malloc(sizeof(List));
  Lista->head=NULL;

  return Lista;
}

void * firstList(List * list) {
  if (list!=NULL && list->head !=NULL){
    return list->head->data;
  }
  return NULL;
}

void * nextList(List * list) {
  if (list!=NULL){
    if (list->current==NULL || list->current->next==NULL){
      return NULL;
    }
    
    list->current=list->current->next;
    return list->current->data;
  }
    return NULL;
}

void * lastList(List * list) {
  int size=sizeof(list);
  for (int i=0;i<size+1;i++){
    list->current=list->current->next;
  }
  
  return list->current->data;
}

void * prevList(List * list) {
  if (list!=NULL && list->current!=NULL && list->current->prev!=NULL){
    list->current=list->current->prev;
    return list->current->data;
  }
  return NULL;
}

void pushFront(List * list, void * data) {
  if (list!=NULL){
    Node *dato= createNode(data);

    if (list->head!=NULL){
      dato->next=list->head;
      list->head->prev=dato;
    }
    list->head=dato;

    if (list->tail==NULL){
      list->tail=dato;
    }
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  if (list!=NULL){
    Node *dato= createNode(data);
    
    if (list->current->next!=NULL){
      dato->next=list->current->next;
      list->current->prev=dato;
    }
    list->current=dato;
  }
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}