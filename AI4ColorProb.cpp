#include<bits/stdc++.h>
using namespace std ;
#define N 3

struct node
{
    node *parent ;
    int mat[N][N] ;
    int x, y  ;
    int cost  ;
    int level ; 
} ;
int printMatrix(int mat[N][N])
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cout << mat[i][j] << " " ;
        cout << endl ;
    }
}
node *NewNode(int mat[N][N], int x, int y, int newX, int newY, int level, node *parent)
{
    node *Node = new node ;
    Node->parent = parent ;
    memcpy(Node->mat, mat, sizeof(Node->mat)) ; // copying datafrom parent node to current node
    swap(Node->mat[x][y], Node->mat[newX][newY]) ; // move title by 1 position ..
    Node->cost = INT_MAX ;
    Node->level = level  ;

    Node->x = newX ;
    Node->y = newY ;
    return Node ;
}

int row[] = {1,0,-1,0} ;
int col[] = {0,-1,0,1} ;

int calculateCost(int initial[N][N], int final[N][N])
{
    int count = 0 ;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(initial[i][j] && (initial[i][j] != final[i][j])) count++ ;
        }
    }
    return count ;
}

int isSafe(int x, int y)
{
    return (x>=0 && x<N && y>= 0 && y<N) ;
}

void printPath(node *root)
{
    if(root == NULL) return ;
    printPath(root->parent) ;
    printMatrix(root->mat)  ;
    cout << endl ;
}

struct comp
{
    bool operator()(const node*lhs, const node*rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level) ;
    }
} ;

void solve(int initial[N][N], int x, int y, int final[N][N])
{
    priority_queue<node*, vector<node*>, comp> pq ;
    node *root = NewNode(initial, x, y, x, y, 0, NULL) ;
    root->cost = calculateCost(initial, final) ;
    pq.push(root) ;
    while(!pq.empty())
    {
        node* min = pq.top() ;
        pq.pop() ;
        if(min->cost == 0)
        {
            printPath(min) ;
            return ;
        }

        for(int i=0; i<4; i++)
        {
            if(isSafe(min->x + row[i], min->y + col[i]))
            {
                node *child = NewNode(min->mat, min->x, min->y, min->x+row[i], min->y+col[i], min->level+1, min) ;
                child->cost = calculateCost(child->mat, final)   ;
                pq.push(child) ;
            }
        }
    }
}
int main()
{
    int initial[N][N] = 
    {
        {1,2,3},
        {5,6,0},
        {7,8,4}
    } ;
    int final[N][N] = 
    {
        {1,2,3},
        {5,8,6},
        {0,7,4}
    } ;
    int x = 1 ; int y = 2 ;
    
    solve(initial, x, y, final) ;
    return 0 ;
}