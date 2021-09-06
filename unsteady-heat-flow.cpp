#include <iostream>
#include <math.h>


using namespace std;
const float alpha=0.0025; //diffusibility  coefficient assumed as 0.0025

int main()
{
    int time;           //time step
    cout<<"enter the time step:";
    cin>>time;
    float tmp[20][20];   // temperature matrix
    float i=0,j=0,k=0;
    int m,n,o;
    for(m=0;m<=10;m=m+1)   // initializing the square grid with temperature following the boundary and initial conditions
    {
        j=0;
        for(n=0;n<=10;n=n+1)
        {
            if(pow((i-0.5),2)+pow((j-0.5),2)<0.2)  // inside the circle
            {
                tmp[m][n]=40;           
            }
            else 
            {
                 tmp[m][n]=20;    // outside the circle
            }
           
        j=j+0.1;
        }
        i=i+0.1;
    }
   
  int h=0;  

if(time>0)             // time evolution of the system
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
          // dynamically changing the grid with time evolution
          }
          else 
          tmp[m][n]=20; // maintainig constant 20 degrees on boundaries
        }
      }
      
}
}

 for(m=0;m<=10;m=m+1)
    {
        for(n=0;n<=10;n=n+1)
        {
            cout<<tmp[m][n]<<"\t"; // displaying the grid
        }
        cout<<"\n\n\n";
    } 
}
