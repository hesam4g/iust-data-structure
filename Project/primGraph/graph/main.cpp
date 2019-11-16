#include <iostream>
#include <conio.h>
using namespace std;

#define inf 9999
#define max 40


void prim(int g[][max],int n)
{
        int lowcost[max],closest[max];
        int i,j,k,min;
        for(i=2;i<=n;i++)
        {
                lowcost[i]=g[1][i];
                closest[i]=1;
        }

        lowcost[1]=0;

        for(i=2;i<=n;i++)

        {
                min=inf;
                k=0;

                for(j=2;j<=n;j++)
                        if((lowcost[j]<min)&&(lowcost[j]!=0))
                        {
                                min=lowcost[j];
                                k=j;
                        }

                cout<<closest[k]<<' '<<k<<' '<<min<<"\t";
                lowcost[k]=0;

                for(j=2;j<=n;j++)
                    if(g[k][j]<lowcost[j])
                    {
                        lowcost[j]=g[k][j];
                        closest[j]=k;
                    }
                cout<<endl;

        }

}



int makeMatrix(int g[][max])
{
        int n,e,i,j,k,v1,v2,weight;

        cout<<"How many vertices? :";
        cin>>n;
        cout<<endl<<endl<<"How many edges? :";
        cin>>e;
        cout<<endl;

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                g[i][j]=inf;

        for(k=1;k<=e;k++)
        {
                cout<<"edge number "<<k<<" enter "<<endl<<"source : ";
                cin>>v1;
                cout<<"destination : ";
                cin>>v2;
                cout<<"weight : ";
                cin>>weight;
                g[v1][v2]=weight;
                g[v2][v1]=weight;
                cout<<endl<<endl;
        }

        return n;
}


void showMatrix(int g[][max],int n)
{
        int i,j;
        cout<<"\t";
        for(i=1;i<=n;i++)

                cout<<i<<"\t";

        for(i=1;i<=n;i++)

        {
                cout<<"\n"<<i<<"\t";

                for(j=1;j<=n;j++)
                        if(g[i][j] == inf)
                                cout<<0<<"\t";
                        else
                                cout<<g[i][j]<<"\t";

        }

        cout<<"\n";
}


int main()
{
        int g[max][max],n;
        n=makeMatrix(g);

        cout<<"Matrix of the graph is:"<<endl<<endl;

        showMatrix(g,n);

        cout<<"minimom derakhte faragir:\n";

        prim(g,n);
        getch();

        return 0;

}
