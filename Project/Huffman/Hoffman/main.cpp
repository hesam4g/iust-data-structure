#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <QList>
#include <string>
using namespace std;


class node
{
public:
    char content;
    int times;
    node* left;
    node* right;
    bool isLeaf;
    node *baba;
    node();

    node(char x,int n);
    node make_baba (node* r,node* l);
    void goLeft();
    void goRight();

};

node::node()
{
    times = 0;
}

node::node(char x, int n)
{
    content = x;
    times = n;
    isLeaf = true;
    left = NULL;
    right = NULL;
    baba =NULL;
}

node node::make_baba(node *r, node *l)
{
    node* parent =new node();
    r->baba = parent;
    l->baba = parent;
    parent->content='&';
    parent->times = r->times + l->times;
    parent->isLeaf = false;
    parent->left = l;
    parent->right = r;
    return *parent;
}

void node::goLeft()
{
    this->times = this->left->times;
    this->content = this->left->content;
}

void node::goRight()
{
    this->times = this->right->times;
    this->content = this->right->times;
}

QList<node> read()
{
    ifstream inFile("info.txt");
    QList<node> nodes;
    char inchar;
    int inNum;
    while(inFile>>inchar)
    {
        inFile>>inNum;
        node l(inchar,inNum);
        nodes.append(l);
    }
    inFile.close();
    return nodes;
}


QList<node> sort(QList<node> nodes)
{
    int j,i;
    int n = nodes.size();
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(nodes.at(i).times>nodes.at(j).times)
                nodes.swap(i,j);
    return nodes;
}


node Huffman(QList<node> nodes)
{
    int len = nodes.size();
    node tmp;
    while(len != 1)
    {
        QList<node> nodes2 = sort(nodes);
        node l=nodes2.at(1);
        node r=nodes2.at(0);
        tmp =r.make_baba(&r,&l);
        //node* tmp = new node();
        //*tmp = r.make_baba(&r,&l);
        nodes.clear();
        nodes.append(tmp);

        for(int i=2;i<len;i++)
            nodes.append(nodes2.at(i));
        len = nodes.size();
    }
    return nodes.at(0);
}


void showDecode(node root,int code)
{
    node *r = root.right;
    node *l = root.left;
    node tmp =r->make_baba(r,l);
    QList<int> a;
    while(code>0)
    {
        a.push_front(code%10);
        code=code/10;
    }
    for(int i=0;i<a.size();i++)
    {
        if(a.at(i)==0)
            tmp.goLeft();
        if(a.at(i)==1)
            tmp.goRight();
    }

    cout<<endl<<endl<<tmp.content;

}


int main()
{
    QList<node> nodes = read();
    QList<node> nodes2 = sort(nodes);
    node root = Huffman(nodes);
    cout<<root.times<<endl;

    showDecode(root,0);
    showDecode(root,1);
    showDecode(root,10);
    showDecode(root,11);
    cout<<endl<<"   "<<root.times<<endl;
    //cout<<endl<<root.times<<endl;
    getch();
    return 0;
}
