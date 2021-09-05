#include <iostream>
#include <math.h>
#include "matplotlibcpp.h"
namespace plt=matplotlibcpp;
using namespace std;
const float alpha=0.0025;

int main()
{
    float tmp[30][20][20];
    float i=0,j=0,k=0;
    int m,n,o;
    for(m=0;m<=10;m=m+1)
    {
        j=0;
        for(n=0;n<=10;n=n+1)
        {
            if(pow((i-0.5),2)+pow((j-0.5),2)<0.2)
            {
                tmp[0][m][n]=40;           
            }
            else 
            {
                 tmp[0][m][n]=20;
            }
           
        j=j+0.1;
        }
        i=i+0.1;
    }
   
    
    for(o=0;o<=20;o++)
    {
       for(m=0;m<=10;m=m+1)
      {
        for(n=0;n<=10;n=n+1)
        {
          if(m!=0 && n!=0 && m!=10 && n!=10)  
          {
          tmp[o+1][m][n]=alpha/0.01*(tmp[o][m+1][n]-2*tmp[o][m][n]+tmp[o][m-1][n]+tmp[o][m][n+1]-2*tmp[o][m][n]+tmp[o][m][n-1])+tmp[o][m][n];

          }
          else 
          tmp[o+1][m][n]=20;
        }
      }
    }

 for(m=0;m<=10;m=m+1)
    {
        for(n=0;n<=10;n=n+1)
        {
            cout<<tmp[21][m][n]<<"\t";
        }
        cout<<"\n\n\n";
    } 
}
