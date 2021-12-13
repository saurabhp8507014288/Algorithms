// implemeting floydd wrshall algo
 
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9      

int main()
{
    cout<<"Note : enter -1 for INFINITY"<<endl;

    int n,a;
    cout<<"enter size: ";
    cin>>n;
    int arr[n][n],dist[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a;
            if(a<0)
            {
                arr[i][j]=INF;
            }
            else
            {
                arr[i][j]=a;                                        
            }
            dist[i][j]=arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    cout<<"shortest path"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
            {
                cout<<"INF ";
            }
            else
            {
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}