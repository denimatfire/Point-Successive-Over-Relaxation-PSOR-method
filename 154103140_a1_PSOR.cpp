#include <iostream>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
    int n,m,i,j, iter=0;
    float t0[101][101],t1[101][101], error=0, dx,dy, beta,x,y;

    cout<<" enter n(x axis) and m(y axis) values \n";
    cin>>n>>m;

    //cout<<"\n length of horizontal and vertical side \n";
    //cin>>l>>b;
    float l=1, b=1;
    dx=l/(n-1);
    dy=b/(m-1);

    cout<<"\t"<<dx<<"\t"<<dy;

    beta=dx/dy;

  cout<<"\n"<<beta<<endl;

  float w=1.94;

    for(i=0; i<n; i++)
    {
        t0[i][0]=1;
        t0[i][m-1]=0;


    }
    for (j=0; j<m; j++)
    {
         t0[0][j]=1;
        t0[n-1][j]=1;

    }

    for(i=1; i<n-1; i++)
    {
        for(j=1; j<m-1; j++)
        {
            t0[i][j]=0;
        }
    }
   /* for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<t0[i][j]<<" ";
        }
        cout<<"\n";
    }*/

clock_t begin, end;
double cpu_time_used;
begin = clock();

 do
{ float s=0;

 for(i=1; i<n-1; i++ )
{
    for(j=1; j<m-1; j++)
    {

        t1[i][j]=(1-w)*t0[i][j] + (w*(t0[i+1][j] + t0[i-1][j] + pow(beta, 2)*(t0[i][j+1] + t0[i][j-1]) ))/(2*(1+ pow(beta, 2)));
        s=s+ pow((t1[i][j]-t0[i][j]), 2);
        t0[i][j]=t1[i][j];

    }
}
error= sqrt(s/((m-2)*(n-2))) ;
iter++;
}while(error> 0.000001);
cout<<" no of iteration =\t"<<iter<<"for w= "<<w<<"\n";

 ofstream thefile("cfd.txt");

  for(x=0,i=0; i<n; i++,x=x+dx){
    for (y=0,j=0; j<m; j++,y=y+dy){
        thefile<<x<<"\t"<<y<<"\t"<<t0[i][j]<<"\n";
    }
  }

end = clock();
cpu_time_used = ((double) (end - begin))/ CLOCKS_PER_SEC;
cout<<" \n"<<cpu_time_used;
    return 0;
}
