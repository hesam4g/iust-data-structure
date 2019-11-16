#include<QtCore/QCoreApplication>
#include<iostream>
#include<string>
using namespace std;
//this function check th number of ( and )
bool check_num(string word)
        {
        int a=0;
        for(int i=0;i<word.length();i++)
                if(word[i]=='(')
                        a++;
                else
                        a--;
        if(a==0)
                return true;
        else
                return false;
        }
//this func gig me position of first ()
int get_num(string word)
        {
        for(int i=0;i<word.length()-1;i++)
                if(word[i]=='(' && word[i+1]==')')
                        {
                        return i;
                        break;
                        }
        return -1;
        }
//this func remove the a and a+1 from string and return that
string remove(string word , int a)
        {
        string n="";
        for(int i=0;i<word.length();i++)
                if (i==a || i==a+1)
                        continue;
                else
                        n += word[i];
        return n;
        }
//this is main func that check balance of strig
bool rec(string word)
        {
        string a=word;
        if(get_num(word)==-1 || word=="()" || !check_num(word)||word.length()==0)
                if(word=="()"|| word.length()==0)
                        return true;
                else
                        return false;

        else
        {
        a=remove(a,get_num(word));
        return rec(a);
        }
        }
string term(string a)
{
 string b = "";
 for(int i=0;i<a.length();i++)
     if (a[i]=='(' || a[i]==')')
         b+=a[i];
 return b;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string word;
    cout<<"pleas enter your string  :  ";
    cin >> word;
    word=term(word);
    if(word.length()==0)
        cout<<"ok it is right"<<endl;
    else
    {
        if(rec(word))
            cout<<"ok it is right!!!"<<endl;
        else
            if(check_num)
                    cout<<"nope it is wronge!!! nember of ( unequal with number of )  "<<endl;
            else
                    cout<<"nope it is wronge!!! and you can change ( to ) or ) to ("<<endl;
    }
    return a.exec();
}
