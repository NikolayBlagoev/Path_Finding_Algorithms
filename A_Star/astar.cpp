#include "astar.h"


#include <cstdlib>

Map::Map(int y, int x) {     
            this->map = (int**) std::calloc(y,sizeof(int*));
            this->x=x;
            this->y=y;
            for(int i = 0; i<x; i++) map[i] = (int*) std::calloc(x,sizeof(int));
}

Node::Node(Node* prev,int y, int x, int gn, int fn){
            this->prev = prev;
            this->fn = fn;
            this->gn = gn;
            this->y = y;
            this->x = x;
            this->self = this;
}