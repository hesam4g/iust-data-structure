#include<QtCore/QCoreApplication>
#include <string>
#include <iostream>

using namespace std;

class node
{
public:
        node();
        int data;
        node* next;
};

node::node()
{
    next = NULL ;
    data=0;
}

class linkList
{
public:
        bool sign;
        node* root;
        linkList();
        linkList(string);
        bool checkZero();
        linkList* add(linkList *);
        linkList* sub(linkList *);
        linkList* mul(linkList *);
        linkList* pwe(linkList *);
};

linkList::linkList()
{
        root = new node();
        sign = false;
}

linkList::linkList(string s)
{
        sign=false;
        root = new node();
        node* p = root;
        for(int i=s.length()-1 ; i>=0 ; i--){
                p->data = s[i]-'0';
                if(i!=0)
                {
                        p->next=new node;
                        p = p->next;
                }
                else
                        p->next = NULL;
        }
}

linkList* linkList::add(linkList* B)
{
        if(B==NULL)
                return this;
        linkList* result = new linkList();
        node* r = result->root;
        node* p1 = this->root;
        node* p2 = B->root;
        int carry = 0;
        while(p1 != NULL && p2!= NULL)
        {
                r->data =(p1->data + p2->data + carry)%10;
                carry = (p1->data + p2->data + carry)/10;
                if(carry!=0 || p1->next!=NULL || p2->next!=NULL )
                {
                        r->next = new node();
                        r=r->next;
                }
                p1 = p1->next;
                p2 = p2->next;
        }
        node* p3 ;

        if(p1!=NULL && p2==NULL)
                p3=p1;
        if(p1==NULL && p2!=NULL)
                p3=p2;
        else
                p3=NULL;
        while(p3 != NULL)
        {
                r->data = (p3->data + carry)%10;
                carry = (p3->data+carry)/10;
                if(carry!=0 || p3->next!=NULL)
                        r->next = new node();
                p3 = p3->next ;
                r = r->next;
        }
        if(carry!=0)
        {
                r->data=carry;
        }

        return result;

}

linkList* linkList::sub(linkList* B)
{
        if(B==NULL)
                return this;
        linkList* result = new linkList();
        linkList* power = new linkList();
        int  counter = false;
        node* powerPtr = power->root;
        node* r = result->root;
        node* p1 = this->root;
        node* p2 = B->root;

        int carry = 0;

        int a,b;

        while(p1!=NULL || p2!= NULL)
        {
                powerPtr->data = 0 ;
                powerPtr->next = new node();
                powerPtr = powerPtr->next;
                ///////////////////
                if(p1!=NULL)
                        a = p1->data ;
                else
                        a =0;
                if(p2!=NULL)
                        b = p2->data ;
                else
                        b =0;
                //////////////////
                if(a-carry >= b )
                {
                        r->data = a - b - carry;
                        carry=0;
                }
                else {
                        r->data = 10 + a - b - carry;
                        carry = 1 ;
                }
                if((p1!=NULL && p1->next!=NULL) || (p2!=NULL &&  p2->next!=NULL))
                {
                        r->next = new node();
                        r = r->next;
                }
                if(p1!=NULL)
                        p1 = p1->next;
                if(p2!=NULL)
                        p2 = p2->next;

        }

        if(carry==1)
        {
                powerPtr->data = 1 ;
                result = power->sub(result);
                result->sign = true ;
        }
        return result;
}

linkList* linkList::mul(linkList* B)
{
        linkList *result = new linkList();
        node* r = result->root;
        node* p1 = this->root;
        node* p2 = B->root;
        int carry = 0;
        int counter=-1;
        while(p2!= NULL)
        {
                counter++;
                for(int i=0; i<counter ;i++ )
                {
                        if(r->next==NULL)
                                r->next=new node();
                        r = r->next ;
                }
                while(p1 != NULL)
                {
                        int tmp = r->data ;
                        r->data = ((p1->data * p2->data)+carry+tmp)%10;
                        carry = ((p1->data * p2->data)+carry+tmp)/10;
                        if((carry!=0 || p1->next!=NULL) && r->next== NULL )
                        {
                                r->next = new node();
                        }
                        r = r->next;
                        p1 = p1->next;

                }
                if(carry!=0)
                {
                        r->data = carry ;
                        carry = 0;
                }
                p1 = this->root;
                r = result->root;
                p2 = p2->next;
        }
        return result;
}

linkList* linkList::pwe(linkList* B)
{
    linkList* result = new linkList("1");

    while(B->checkZero())
    {
        result = result->mul(this);
        B = B->sub(&linkList("1"));
    }
    return result;
}

void show(linkList *A)
{
        if(A->sign)
                cout << "- ";
        for (node* p = A->root ; p!= NULL ; p=p->next)
                cout << p->data << "   ";
        cout<<"\n";
}

bool linkList::checkZero()
{
    int i=0;
    node* t=this->root;
    for(node* p = this->root ; p!= NULL ; p=p->next)
    {
        if(p->data!=0)
            i++;
    }
    this->root = t;
    if(i!=0)
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
        QCoreApplication app(argc, argv);
        linkList* A = new linkList("2343");
        linkList* B = new linkList("105");
        linkList* C = new linkList("134456784567890");
        linkList* D = new linkList("123457876543563234");
        linkList* res1 = NULL ;
        linkList* res2 = NULL ;
        show(A);
        show(B);
        show(C);
        show(D);
        res1 = A->pwe(B);
        res2 = C->sub(D);
        show(res1);
        show(res2);
        return app.exec();
}
