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
    
  List* dato = (List*) malloc (sizeof(List));
  dato->head=NULL;
  dato->tail=NULL;
  dato->current=NULL;
     return dato;
}

void * firstList(List * list) {
  if(list->head != NULL){
    list->current= list->head;
  }
  else
  {
    return NULL;
  }
 
    return list->head->data;
}

void * nextList(List * list) {
  if(list->current == NULL)
  {
    return NULL;
  }
  if(list->current->next != NULL){
     list->current=list->current->next;
    }
  else{
    return NULL;
  }
    return list->current->data;
}

void * lastList(List * list) {
  /*La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. */
    if(list->head != NULL && list->tail != NULL){
       list->current= list->tail;
       return list->current->data;
    }
    return NULL;
}

void * prevList(List * list) {
    if(list->current!=NULL && list->current->prev != NULL )
    {
        list->current=list->current->prev;
        return list->current->data;
    }
    return NULL;
}

void pushFront(List * list, void * dato) {
    
    Node* nuevo_nodo;
    nuevo_nodo->data = dato;
    if(list->head != NULL)
    {
        nuevo_nodo->next=list->head;
        list->head->prev=nuevo_nodo;
    }
    list->head=nuevo_nodo;
    list->head->prev=NULL;

}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
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