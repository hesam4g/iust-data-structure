#ifndef RB_TREE_H
#define RB_TREE_H
#include <mainwindow.h>
#include <math.h>
#include <iostream>
#include <QString>
using namespace std;

struct node
{
node * parents;
node * left;
node * right;
int value;
int color;

};

class RB_tree
{
/*private:
    node nil;
    node * root;
    int heigh;
    int size;
*/
public:
    QString inorder;
    QString postorder;
    QString preorder;
    node **all_node;
    int * all_value;
    int * all_color;
    node nil;
    node * root;
    int heigh;
    int size;
    RB_tree()
        {

        root= & nil;
        heigh=0;
        size=0;
        nil.parents = &nil;
        nil.left = &nil;
        nil.right = &nil;
        nil.color=0;
        all_node = new node *[1];
        all_node[0]=root;
         all_color = new int [1];
        all_color[0]=0;
         all_value = new int [1];
        all_value[0]=-1;

        }
    void left_rotate(node * x)
        {
        node *y=x->right;
        x->right=y->left;
        if(y->left != & nil)
            y->left->parents=x;
        y->parents=x->parents;
        if(x->parents==& nil)
            root=y;
        else
            if(x==x->parents->left)
                x->parents->left=y;
            else
                x->parents->right=y;
        y->left=x;
        x->parents=y;
        }
    void right_rotate(node * x)
        {
        node *y=x->left;
        x->left=y->right;
        if(y->right != & nil)
            y->right->parents=x;
        y->parents=x->parents;
        if(x->parents==& nil)
            root=y;
        else
            if(x==x->parents->right)
                x->parents->right=y;
            else
                x->parents->left=y;
        y->right=x;
        x->parents=y;
        }
    void inser_fixup(node * z)
        {
        node * y;
        while(z->parents->color==1)
            {
                if(z->parents==z->parents->parents->left)
                    {
                    y=z->parents->parents->right;
                    if(y->color==1)
                        {
                        z->parents->color=0;
                        y->color=0;
                        z->parents->parents->color=1;
                        z=z->parents->parents;
                        }
                    else
                        {
                        if(z==z->parents->right)
                            {
                            z=z->parents;
                            left_rotate(z);
                            }
                        z->parents->color=0;
                        z->parents->parents->color=1;
                        right_rotate(z->parents->parents);
                        }
                    }
                else
                    {
                        y=z->parents->parents->left;
                        if(y->color==1)
                            {
                            z->parents->color=0;
                            y->color=0;
                            z->parents->parents->color=1;
                            z=z->parents->parents;
                            }
                        else
                            {
                            if(z==z->parents->left)
                                {
                                z=z->parents;
                                right_rotate(z);
                                }
                            z->parents->color=0;
                            z->parents->parents->color=1;
                            left_rotate(z->parents->parents);
                            }
                    }

            }
    root->color=0;
    }
    void insert(int n)
        {

        size++;
        node * x = root;
        node *y;
        if(root==&nil)
            {
                root = new node;
                root->value = n;
                root->left = &nil;
                root->right = &nil;
                root->parents = &nil;
                root->color=0;
            }
        else
            {
                while(x != &nil)
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
                    y->left->parents=y;
                    y->left->left=&nil;
                    y->left->right=&nil;
                    y->left->value=n;
                    y->left->color=1;
                    inser_fixup(y->right);
                }
                else
                {
                    y->right=new node;
                    y->right->parents=y;
                    y->right->left=&nil;
                    y->right->right=&nil;
                    y->right->value=n;
                    y->right->color=1;
                    inser_fixup(y->right);
                }

            }
                get_color();

                get_array();
                pre();
                in();
                pos();




    }
    void delete_fixup(node * x)
        {
        node * w;
        while(x != root && x->color==0)
            {
                if(x==x->parents->left)
                    {
                    w=x->parents->right;
                    if(w->color==1)
                        {
                        w->color=0;
                        x->parents->color=1;
                        left_rotate(x->parents);
                        w=x->parents->right;

                        }
                    if(w->left->color=0 && w->right->color==0)
                        {
                        w->color=1;
                        x=x->parents;
                        }
                    else
                        {
                            if(w->right->color ==0)
                                {
                                w->left->color=0;
                                w->color=1;
                                right_rotate(w);
                                w=x->parents->right;
                                }
                            w->color=x->parents->color;
                            x->parents->color=0;
                            w->right->color=0;
                            left_rotate(x->parents);
                            x=root;
                        }
                    }
                else
                    {
                    w=x->parents->left;
                    if(w->color==1)
                        {
                        w->color=0;
                        x->parents->color=1;
                        right_rotate(x->parents);
                        w=x->parents->left;

                        }
                    if(w->right->color=0 && w->left->color==0)
                        {
                        w->color=1;
                        x=x->parents;
                        }
                    else
                        {
                            if(w->left->color ==0)
                                {
                                w->right->color=0;
                                w->color=1;
                                left_rotate(w);
                                w=x->parents->left;
                                }
                            w->color=x->parents->color;
                            x->parents->color=0;
                            w->left->color=0;
                            right_rotate(x->parents);
                            x=root;
                        }
                    }
            }
        x->color=0;

        }
    void transplant(node * u,node *v)
        {
        if(u->parents==&nil)
            root=v;
        else
            {
                if(u==u->parents->left)
                    u->parents->left=v;
                else
                    u->parents->right=v;
            }
        v->parents=u->parents;

        }
    node * min(node * n)
        {
        if(n->left == &nil)
            return n;
        else
            return min(n->left);
        }
    void delet(node * z)
        {
        node * y = z;
        node * x;
        int y_color = y->color;
        if(z->left==&nil)
            {
            x = z->right;
            transplant(z,z->right);
            }
       else
            {
                if(z->right==&nil)
                    {
                    x=z->left;
                    transplant(z,z->left);
                    }
                else
                    {
                        y=min(z->right);
                        y_color=y->color;
                        x=y->right;
                    if(y->parents == z)
                        x->parents=y;
                    else
                        {
                        transplant(y,y->right);
                        y->right=z->right;
                        y->right->parents=y;
                        }
                   transplant(z,y);
                   y->left=z->left;
                   y->left->parents = y;
                   y->color = z->color;
                    }
            }
        if(y_color==0)
            delete_fixup(x);
        get_color();
        get_array();
        pre();
        in();
        pos();

        }
    node * get_addres(int n)
    {

        get_node();
        node **r=all_node;

        for(int i=1;i<heigh+1;i++)
            {
                if(all_node[i] != &nil && all_node[i]->value == n)
                    return all_node[i];


            }

    }
    bool cheack(int n , node ** k)
        {
        for(int i=n ;i > (n+1)/2-1;i--)
                if(k[i] != &nil)
                        {
                        return false;
                        break;
                        }
        return true;
        }
    void get_node()
        {
                get_num();
                delete[] all_node;
                all_node = new node * [heigh+10];
                all_node[0] = root;
                all_node[1] = root;
        for(int i = 1 ; i < (heigh/2)+1 ; i++)
                 {
              all_node[i*2]=all_node[i]->left;
              all_node[i*2+1]=all_node[i]->right;
             }


        }
    void get_array()
    {

        get_node();
        delete [] all_value ;
        all_value = new int [heigh];

        for(int i = 1 ; i < heigh + 1 ; i++ )
            {
                if(all_node[i]  !=  &nil)
                    all_value[i-1] = all_node[i]->value;
                else
                    all_value[i-1] = -1 ;
            }

    }

    void get_color()
    {

     get_node();
     delete [] all_color ;
     all_color = new int[heigh+1];

     for(int i = 1 ; i < heigh + 1 ; i++ )
        {

            if(all_node[i]  !=  &nil)
                all_color[i-1] = all_node[i]->color;
            else
                all_color[i-1] = 0 ;
            }
    }
  void  get_num()
    {
    float a = log(size+1);
    float b = log(2);
    int c= a / b ;
    c = 2*c ;
    c=pow(2,c);
    node **r;
    r = all_node;
        c=c-1;
    while(cheack(c,r))
       c=((c+1)/2)-1;
    heigh = c;
    }
  int get_one_color(int a){return all_color[a];}
  int get_one_value(int a){return all_value[a];}
  QString inorde(int n)
          {
          QString q="";
          QString o;
          //o.number(root->value,10);
          if(n <= heigh )
                  {

                      if(2*n <= heigh && all_value[2*n-1]!=-1)
                                  q = q+ inorde(2*n);
                      q=q+QString::number(all_node[n]->value,10)+"  ";
                      if(2*n+1 <= heigh && all_value[2*n]!=-1)
                                  q = q+ inorde(2*n+1);
                  }

          return q;

          }
  void in()
  {
      //return "salam";
      inorder= inorde(1);

  }
  QString preorde(int n)
          {
          QString q="";
          ;

          if(n <= heigh )
                  {
                    q=q+QString::number(all_node[n]->value,10)+"  ";
                      if(2*n <= heigh && all_value[2*n-1]!=-1)
                                  q = q+ preorde(2*n);

                      if(2*n+1 <= heigh && all_value[2*n]!=-1)
                                  q = q+ preorde(2*n+1);
                  }

          return q;

          }
  void pre()
  {
      //return "salam";
      preorder= preorde(1);

  }
  QString posorde(int n)
          {
          QString q="";
          QString o;
          //o.number(root->value,10);
          if(n <= heigh )
                  {

                      if(2*n <= heigh && all_value[2*n-1]!=-1)
                                  q = q+ posorde(2*n);

                      if(2*n+1 <= heigh && all_value[2*n]!=-1)
                                  q = q+ posorde(2*n+1);
                       q=q+QString::number(all_node[n]->value,10)+"  ";
                  }

          return q;

          }
  void pos()
  {
      //return "salam";
      postorder= posorde(1);

  }
};

#endif // RB_TREE_H
