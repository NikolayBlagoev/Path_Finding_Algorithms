#include <cstddef>
#ifndef ASTAR
#define ASTAR
class Map{
    private:
            
    public:    
        int** map;
        int y;
        int x;
        Map(); 
        Map(int y, int x);
};

class Node{
    public:
    int fn,gn;
    Node* prev=NULL;
    Node* self;
    int y,x;
    Node(Node* prev,int y, int x, int gn, int fn);
};
    #endif
struct CompareFunc{
    bool operator ()(const Node& lhs, const Node& rhs){
        return lhs.fn > rhs.fn;
    }
};
