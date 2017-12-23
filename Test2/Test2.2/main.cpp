#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "list.h"

using namespace std;

int main(int argc, char** argv)
{
    List* list = createList();
    insert(sentinel(list), 3, nullprt);
    insert(first(list), 2, sentinel(list));
    insert(next(first(list)), 7, first(list));
    
    deleteList(list);
    return 0;
}

