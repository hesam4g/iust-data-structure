#ifndef RBTREE_H
#define RBTREE_H
#include <mainwindow.h>
#include <math.h>
#include <iostream>
#include <QString>
using namespace std;

class node{
public:
    node* parent;
    node* left;
    node* right;

    int value;
    int color;
};


class RBtree{
public:
    QString preOrder;
    QString posOrder;
    QString inOrder;
    node **all_node;
    int * all_value;
    int * all_color;
    node* root;
    node NIL;
    int height;
    int size;
    RBtree()
    {
        root= & NIL;
        height=0;
        size=0;
        NIL.parent = &NIL;
        NIL.left = &NIL;
        NIL.right = &NIL;
        NIL.color=0;
        all_node = new node *[1];
        all_node[0]=root;
        all_color = new int [1];
        all_color[0]=0;
        all_value = new int [1];
        all_value[0]=-1;
    }

    void leftRotate(node* x)
    {
        node* y = x->right;
        x->right = y->left;
        if(y->left != &this->NIL)
            y->left->parent =x;
        y->parent = x->parent;
        if(x->parent == &this->NIL)
            this->root = y;
        else{
            if(x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(node* x)
    {
        node* y = x->left;
        x->left = y->right;
        if(y->right != & NIL)
            y->right->parent = x;
        y->parent = x->parent;
        if(x->parent == & NIL)
            root=y;
        else
            if(x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void insert(int n)
    {

    size++;
    node * x = root;
    node *y;
    if(root==&NIL)
        {
            root = new node;
            root->value = n;
            root->left = &NIL;
            root->right = &NIL;
            root->parent = &NIL;
            root->color=0;
        }
    else
        {
            while(x != &NIL)
                {
                y=x;
                if(n<x->value)
                    x=x->left;
                else
                    x=x->right;
                }
            if(n<y->value)
            {
                y->left=new node;
                y->left->parent=y;
                y->left->left=&NIL;
                y->left->right=&NIL;
                y->left->value=n;
                y->left->color=1;
                insertFix(y->right);
            }
            else
            {
                y->right=new node;
                y->right->parent=y;
                y->right->left=&NIL;
                y->right->right=&NIL;
                y->right->value=n;
                y->right->color=1;
                insertFix(y->right);
            }

        }
            getColor();
            getArray();
            pre();
            in();
            pos();
}

    void insertFix(node* z)
    {
        node * y;
        while(z->parent->color==1)
            {
                if(z->parent==z->parent->parent->left)
                    {
                    y=z->parent->parent->right;
                    if(y->color==1)
                        {
                        z->parent->color=0;
                        y->color=0;
                        z->parent->parent->color=1;
                        z=z->parent->parent;
                        }
                    else
                        {
                        if(z==z->parent->right)
                            {
                            z=z->parent;
                            leftRotate(z);
                            }
                        z->parent->color=0;
                        z->parent->parent->color=1;
                        rightRotate(z->parent->parent);
                        }
                    }
                else
                    {
                        y=z->parent->parent->left;
                        if(y->color==1)
                            {
                            z->parent->color=0;
                            y->color=0;
                            z->parent->parent->color=1;
                            z=z->parent->parent;
                            }
                        else
                            {
                            if(z==z->parent->left)
                                {
                                z=z->parent;
                                rightRotate(z);
                                }
                            z->parent->color=0;
                            z->parent->parent->color=1;
                            leftRotate(z->parent->parent);
                            }
                    }
    root->color=0;
            }
    }

    void clear(node* z)
    {
    node * y = z;
    node * x;
    int y_color = y->color;
    if(z->left==&NIL)
        {
        x = z->right;
        link(z,z->right);
        }
   else
        {
            if(z->right==&NIL)
                {
                x=z->left;
                link(z,z->left);
                }
            else
                {
                    y=min(z->right);
                    y_color=y->color;
                    x=y->right;
                if(y->parent == z)
                    x->parent=y;
                else
                    {
                    link(y,y->right);
                    y->right=z->right;
                    y->right->parent=y;
                    }
               link(z,y);
               y->left=z->left;
               y->left->parent = y;
               y->color = z->color;
                }
        }
    if(y_color==0)
        clearFix(x);
    getColor();
    getArray();
    pre();
    in();
    pos();
    }

    void clearFix(node* x)
    {
    node * w;
    while(x != root && x->color==0)
        {
            if(x==x->parent->left)
                {
                w=x->parent->right;
                if(w->color==1)
                    {
                    w->color=0;
                    x->parent->color=1;
                    leftRotate(x->parent);
                    w=x->parent->right;
                    }
                if(w->left->color=0 && w->right->color==0)
                    {
                    w->color=1;
                    x=x->parent;
                    }
                else
                    {
                        if(w->right->color ==0)
                            {
                            w->left->color=0;
                            w->color=1;
                            rightRotate(w);
                            w=x->parent->right;
                            }
                        w->color=x->parent->color;
                        x->parent->color=0;
                        w->right->color=0;
                        leftRotate(x->parent);
                        x=root;
                    }
                }
            else
                {
                w=x->parent->left;
                if(w->color==1)
                    {
                    w->color=0;
                    x->parent->color=1;
                    rightRotate(x->parent);
                    w=x->parent->left;

                    }
                if(w->right->color=0 && w->left->color==0)
                    {
                    w->color=1;
                    x=x->parent;
                    }
                else
                    {
                        if(w->left->color ==0)
                            {
                            w->right->color=0;
                            w->color=1;
                            leftRotate(w);
                            w=x->parent->left;
                            }
                        w->color=x->parent->color;
                        x->parent->color=0;
                        w->left->color=0;
                        rightRotate(x->parent);
                        x=root;
                    }
                }
        }
    x->color=0;

    }

    node* min(node* n)
    {
        if(n->left == NIL)
            return n;
        else
            return min(n->left);
    }

    void link(node* u,node* v)
    {
    if(u->parent==&NIL)
        root=v;
    else
        {
            if(u==u->parent->left)
                u->parent->left=v;
            else
                u->parent->right=v;
        }
    v->parent=u->parent;
    }

    node* getAddress(int n)
    {
        get_node();
        node **r=all_node;

        for(int i=1;i<height+1;i++)
            {
                if(all_node[i] != &NIL && all_node[i]->value == n)
                    return all_node[i];
            }
    }

    void getNode()
    {
            getNumber();
            delete[] all_node;
            all_node = new node * [height+10];
            all_node[0] = root;
            all_node[1] = root;
    for(int i = 1 ; i < (height/2)+1 ; i++)
             {
          all_node[i*2]=all_node[i]->left;
          all_node[i*2+1]=all_node[i]->right;
         }
    }

    void getArray()
    {
        getNode();
        delete [] all_value ;
        all_value = new int [height];

        for(int i = 1 ; i < height + 1 ; i++ )
            {
                if(all_node[i]  !=  &NIL)
                    all_value[i-1] = all_node[i]->value;
                else
                    all_value[i-1] = -1 ;
            }
    }

    void getColor()
    {

     getNode();
     delete [] all_color ;
     all_color = new int[height+1];

     for(int i = 1 ; i < height + 1 ; i++ )
        {

            if(all_node[i]  !=  &NIL)
                all_color[i-1] = all_node[i]->color;
            else
                all_color[i-1] = 0 ;
            }
    }

    void getNumber()
    {
        float a = log(size+1);
        float b = log(2);
        int c= a / b ;
        c = 2*c ;
        c=pow(2,c);
        node **r;
        r = all_node;
            c=c-1;
        while(check(c,r))
           c=((c+1)/2)-1;
        height = c;

    }

    bool check(int,node**)
    {
    for(int i=n ;i > (n+1)/2-1;i--)
            if(k[i] != &NIL)
                    {
                    return false;
                    break;
                    }
    return true;
    }

    int get_one_color(int a){return all_color[a];}

    int get_one_value(int a){return all_value[a];}

    QString posOr(int n)
    {
    QString q="";
    QString o;
    if(n <= height )
            {
                if(2*n <= height && all_value[2*n-1]!=-1)
                            q = q+ posOr(2*n);

                if(2*n+1 <= height && all_value[2*n]!=-1)
                            q = q+ posOr(2*n+1);
                 q=q+QString::number(all_node[n]->value,10)+"  ";
            }

    return q;
    }

    QString preOr(int n)
    {
    QString q="";
    ;

    if(n <= heigh )
            {
              q=q+QString::number(all_node[n]->value,10)+"  ";
                if(2*n <= height && all_value[2*n-1]!=-1)
                            q = q+ preOr(2*n);

                if(2*n+1 <= height && all_value[2*n]!=-1)
                            q = q+ preOr(2*n+1);
            }
    return q;
    }

    QString inOr(int n)
    {
    QString q="";
    QString o;
    if(n <= height )
            {
                if(2*n <= height && all_value[2*n-1]!=-1)
                    q = q+ inOr(2*n);
                q=q+QString::number(all_node[n]->value,10)+"  ";
                if(2*n+1 <= height && all_value[2*n]!=-1)
                    q = q+ inOr(2*n+1);
            }
    return q;
    }

    void pos()
    {
        posOrder= posOr(1);
    }

    void pre()
    {
        preOrder = preOr();
    }

    void in()
    {
        inOrder = inOr();
    }
};


#endif // RBTREE_H
