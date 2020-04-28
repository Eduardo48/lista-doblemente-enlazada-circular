#ifndef CDLIST_H
#define CDLIST_H

#include "cdnode.h"

typedef struct _cdlist cdlist;

struct _cdlist{
    dnode *head;
    dnode *tail;
    int num;
};

cdlist *create_cdlist();//f
bool remove_cdlist(cdlist *l);//f

bool insert_init(cdlist *l, DATA data);//f
bool insert_end(cdlist *l, DATA data);//f
bool insert_cdlist(cdlist *l, DATA data, int pos);//f

bool remove_init(cdlist *l);//f
bool remove_end(cdlist *l);//f
bool remove_pos(cdlist *l ,int pos);//funciona bien

DATA search_cdlist(cdlist *l, int pos);
int locate_cdlist(cdlist *l, DATA data);

void print_cdlist(cdlist *l);//f

bool is_empty_cdlist(cdlist *l);//f
void empty_cdlist(cdlist *l);//f

bool delete_data(cdlist *l, DATA data);//f
#endif

