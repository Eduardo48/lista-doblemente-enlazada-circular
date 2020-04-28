#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cdlist.h"

cdlist *create_cdlist(){
    cdlist *l = (cdlist*)malloc(sizeof(cdlist));
    l->head = NULL;
    l->tail = NULL;
    l->num = 0;
    return l;
}

bool remove_cdlist(cdlist *l){
    if(!is_empty_cdlist(l))
        empty_cdlist(l);
    free(l);
    return true;
}

DATA search_cdlist(cdlist *l, int pos){
    int i;
    if(pos == 0) return l->head->data;
    else if(pos == l->num-1) return l->tail->data;
    else if(pos >0 && pos < l->num-1){
        dnode *t = l->head->next;
        for( i=1; i<l->num-2; i++){
            if(i==pos) return i;
            t = t->next;
        }
    }
    return -1;
}

dnode* search_dnode_cdlist(cdlist *l, int pos){
    int i;
    if(pos == 0) return l->head;
    else if(pos == l->num-1) return l->tail;
    else if(pos >0 && pos < l->num-1){
        dnode *t = l->head->next;
        for( i=1; i<l->num-1; i++){
            if(i==pos) return t;
            t = t->next;
        }
    }
    return NULL;
}

int locate_cdlist(cdlist *l, DATA data){
    int i;
    dnode *t = l->head;
    for( i= 0; i < l->num-1; i++){
        if(t->data==data) return i;
        t = t->next;
    }
    return -1;
}

void print_cdlist(cdlist *l){
    int i;
    dnode *t = l->head;
    printf("[ ");
    for( i=0; i < l->num-1; i++){
        printf("%d, ", t->data);
        t = t->next;
    }
    printf("%d ", t->data);
    printf("]\n");
}

void empty_cdlist(cdlist *l){
    if(is_empty_cdlist(l)) return;
    dnode *t = l->head;
    while(remove_init(l));
}

bool delete_data(cdlist *l, DATA data){
    int i;
    dnode *t = l->head;
    for( i =0; i < l->num; i++){
        if(t->data == data){
            if(t == l->head) return remove_init(l);
            else if(t==l->tail)return remove_end(l);
            return remove_pos(l,i);
        }
        t=t->next;
    }
}

bool is_empty_cdlist(cdlist *l){
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}

bool insert_init(cdlist* l, DATA data){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(is_empty_cdlist(l)){
       nuevo->next=nuevo;
       nuevo->prev=nuevo;
       l->head=nuevo;
       l->tail=nuevo;
        l->num =1;
        return true;
    }
    nuevo->next = l->head;
    l->head->prev = nuevo;
    nuevo->prev=l->tail;
     l->tail->next=nuevo;
     l->head=nuevo;
    l->num++;
    return true;
}

bool insert_end(cdlist* l, DATA data){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(is_empty_cdlist(l)){
        l->head = nuevo;
        l->tail = nuevo;
        l->head->prev=l->tail;
        l->tail->next=l->head;
        l->num =1;
        return true;
    }
    l->tail->next = nuevo;
    nuevo->prev = l->tail;
    l->tail = nuevo;
    l->tail->next=l->head;
    l->head->prev=l->tail;
    l->num++;
    return true;
}

bool insert_cdlist(cdlist* l, DATA data,  int pos){
    int i;
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(pos ==0) return insert_init(l, data);
    else if(pos == l->num-1)
        return insert_end(l,data);
    else if(pos >0 && pos<= l->num-1 || pos==1 && l->num==2){
        dnode *t = l->head->next;
        for(i =1; i < pos; i++){ // i = 1 Y pos = 1
            t= t->next;
        }
        dnode *prev = t->prev;
        prev->next = nuevo;
        nuevo->next = t;
        nuevo->prev = prev;
        t->prev = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool remove_init(cdlist *l){
    if(l == NULL || is_empty_cdlist(l)) return false;
    if(l->head ==l->tail){
        remove_dnode(l->head);
        l->tail->next=NULL;
        l->head->prev=NULL;
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->head;
    l->head=t->next;
    t->next=NULL;
    t->prev=NULL;
    l->head->prev=l->tail;
    l->tail->next=l->head;
    remove_dnode(t);
    l->num--;
    return true;
}

bool remove_end(cdlist *l){
    if(l == NULL || is_empty_cdlist(l)) return false;
    if(l->head ==l->tail){
        l->head->prev=NULL;
        l->tail->next=NULL;
        remove_dnode(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->tail->prev;
    l->tail->next=NULL;
    l->tail->prev=NULL;
    t->next= l->head;
    l->head->prev=t;
    remove_dnode(l->tail);
    l->tail = t;
    l->num--;
    return true;
}



bool remove_pos(cdlist *l ,int pos){
    int i;
    if(pos == 0){
        return remove_init(l);
    }else if(pos == l->num-1){
        return remove_end(l);
    }else if(pos>0 && pos <= l->num-1 || pos==1 && l->num==2){
        dnode *t = l->head->next;
        for( i =1; i < pos; i++){
            t= t->next;
        }
        dnode *prev = t->prev;
        dnode *next = t->next;
        prev->next = next;
        next->prev = prev;
        t->next = NULL;
        t->prev = NULL;
        remove_dnode(t);
        l->num--;
        return true;
    }
    return false;
}

