#include <iostream>
#include <math.h>


using namespace std;
const float alpha=0.0025; //diffusibility  coefficient assumed as 0.0025

int main()
{
    int time;
    cout<<"enter the time step:";
    cin>>time;
    float tmp[20][20];
    float i=0,j=0,k=0;
    int m,n,o;
    for(m=0;m<=10;m=m+1)
    {
        j=0;
        for(n=0;n<=10;n=n+1)
        {
            if(pow((i-0.5),2)+pow((j-0.5),2)<0.2)
            {
                tmp[m][n]=40;           
            }
            else 
            {
                 tmp[m][n]=20;
            }
           
        j=j+0.1;
        }
        i=i+0.1;
    }
   
  int h=0;  

if(time>0)
{    
  for(h=0;h<=time;h++)
    {
       for(m=0;m<=10;m=m+1)
      {
        for(n=0;n<=10;n=n+1)
        {
          if(m!=0 && n!=0 && m!=10 && n!=10)  
          {
          tmp[m][n]=alpha/0.01*(tmp[m+1][n]-2*tmp[m][n]+tmp[m-1][n]+tmp[m][n+1]-2*tmp[m][n]+tmp[m][n-1])+tmp[m][n];

          }
          else 
          tmp[m][n]=20;
        }
      }
      
}
}

 for(m=0;m<=10;m=m+1)
    {
        for(n=0;n<=10;n=n+1)
        {
            cout<<tmp[m][n]<<"\t";
        }
        cout<<"\n\n\n";
    } 
}
