#include <stdio.h>
#include <stdlib.h>
#include "cdlist.h"

int main(){
    cdlist *l;
    l = create_cdlist();
    insert_cdlist(l, 0, 0);
    insert_cdlist(l, 2, 0);
    insert_cdlist(l,3,1);
    insert_cdlist(l,5,2);
    print_cdlist(l);
    insert_cdlist(l,11,2);
    print_cdlist(l);
    delete_data(l,11);
    print_cdlist(l);
    remove_pos(l,2);
    print_cdlist(l);
    remove_end(l);
    print_cdlist(l);
    remove_init(l);
    print_cdlist(l);
    insert_cdlist(l, 2, 0);
     print_cdlist(l);
    delete_data(l,2);
     print_cdlist(l);
     insert_end(l,5);
     print_cdlist(l);
    remove_cdlist(l);

    return 0;
}
