#include<iostream>
using namespace std;
#define v 7
#define inf 500
class SPA
{
 int G[v][v]={{0,2,3,1,0,0,0},
              {2,6,7,1,3,4,5},
              {1,3,4,0,0,6,5},
              {4,0,0,0,0,1,0},
              {0,0,0,1,2,0,0},
              {2,0,0,4,0,0,0},
              {3,2,0,0,0,0,5}};  
  public:            
 int show();
 void Shortest_path();
 int selectmin(int*,int*);
 };
 int SPA::show()
 {
   for(int i=0;i<v;i++)
   {
    for(int j=0;j<v;j++)
    {
    cout<<G[i][j]<<"\t";
    }
    cout<<endl;
    } 
  }
  void SPA:: Shortest_path()
  {
   int s,sv,cost=0,i;
   int dist[v],parent[v],visited[v];
   for(int i=0;i<v;i++)
   {
    dist[i]=500;
    parent[i]=-1;
    visited[i]=0;
    }
    cout<<"Enter source vertex"<<endl;
    cin>>sv;
    s=sv;
    dist[s]=0;
    for(int j=0;j<v-1;j++)
    {
      visited[s]=1;
      for(int i=0;i<v;i++) 
    {  
     if(G[s][i]!=0 && visited[i]==0 && G[s][i]<dist[i]) 
     {
      dist[i]=G[s][i];
      parent[i]=s;
         }
       }
     s=selectmin(dist,visited);  
     }
    for(int i=0;i<v;i++)
   {
    cost=cost+dist[i];
    }
   cout<<"cost of graph"<<cost<<endl;
   for(int i=0;i<v;i++) 
   {
    cout<<parent[i]<<"\t";
    }
   cout<<endl;
   for(int i=0;i<v;i++) 
   {
    cout<<dist[i]<<"\t";
    }
   cout<<endl;
   }
  int SPA:: selectmin(int dist[],int visited[])
  {
   int vertex;
   int min=inf;
   for(int i=0;i<v;i++) 
   {
   if(visited[i]==0 && dist[i]<min)
   {
    vertex=i;
    min=dist[i];
   }
 }
 return vertex;
 }             
  int main()
  {
  SPA s;
  int ch;
  {
   cout<<"\n1.show"<<endl;
   cout<<"\n2.Shortest_path"<<endl;
   cout<<"\n3.Exit"<<endl;
   do
   { 
    cout<<"Enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
     case 1:
     s.show();
     break;
     case 2:
     s.Shortest_path();
     break;
     case 3:
     exit (0);
    }
   }while(ch<4);
   }
  }  
     
    
    
    
    

   
