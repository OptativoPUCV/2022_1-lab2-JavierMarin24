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

void pushFront(List * list, void * data) {
    Node* nuevo_nodo;
    nuevo_nodo = createNode(data);
    if(list != NULL && list->head != NULL)
    {
        nuevo_nodo->next=list->head;
        list->head->prev = nuevo_nodo;
        list->head= nuevo_nodo;
        list->head->prev = NULL;
    }
    else
    {
        list->head=nuevo_nodo;
        list->tail=nuevo_nodo;
    }

}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node* nuevo_nodo;
    nuevo_nodo = createNode(data);
    if(list->head != NULL && list->current != NULL && list->current != list->tail)
    {
        nuevo_nodo->next=list->current->next;
        list->current->next->prev=nuevo_nodo;
        list->current->next=nuevo_nodo;
        nuevo_nodo->prev=list->current;
        
    }
    else{
        list->current->next=nuevo_nodo;
        nuevo_nodo->prev=list->current;
        nuevo_nodo->next=NULL;
        list->tail=nuevo_nodo;
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
    void *aux;
    
    if(list->head!=NULL && list->current != NULL && list->current != list->tail && list->current != list->head)
    {
        aux=list->current->data;
        list->current->prev->next=list->current->next;
        list->current->next->prev=list->current->prev;
        aux=list->current;
        free(list->current);
        return aux;
       
    }
    else{
        if(/*list->current->prev != NULL &&*/ list->current->next == NULL )
        {

            aux=list->current->data;
           list->tail=list->current->prev;
            list->current->prev->next=NULL;
            free(list->current);
            return aux;

        }
        else{
            if(list->current==list->head)
            {
                aux=list->current->data;
                list->head=list->current->next;
                list->current->next->prev=NULL;
                
                free(list->current);
                return aux;
            }
            else{
                list=NULL;
                return NULL;
            }
        }

    }
   
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}