#include <iostream>
#include <cmath>

int ilecyfr=4;

void rsort(int t[], int n, int b[])
{ int u=1000;
  int max=2;
  int *t_orig=t;
  int tura=0;
	for(int r=1;r<=max;r*=u)
    {   std::cout<<"tura "<< ++tura<<std::endl;
	    if(r==1)
	    {
		for(int i=0;i<n;i++)
	           if(t[i]>max) max=t[i]; 
		u=ceil(sqrt(max));
		if(u<100) 
	           u=100;
	    }
        int ile[u];  
		for(int i=0;i<u;i++) //zerowanie liczników
		  ile[i]=0;
	    for(int i=0;i<n;i++)  //zliczanie
	      ile[t[i]/r%u]++;
		for(int i=1;i<u;i++)  //akumulacja
		  ile[i]+=ile[i-1];
	    for(int i=n-1;i>=0;i--)  // wpis do bufora
	      b[--ile[t[i]/r%u]]=t[i];
       int *s;s=t;t=b;b=s;
     }
   if(t!=t_orig)
   for(int i=0;i<n;i++)    // przepisanie 
     t_orig[i]=t[i];	
}

    const  int n=100000000;
    int t[n],b[n];
int main()
{
try{
int *t=new int[n];
int *b=new int[n];
if(!(t && b)) return 0;
cout<<"ola1"<<endl;
    for(int i=0;i<n;i++)
       t[i]=abs(1271*i % 100000000);
cout<<"ola2"<<endl;

    rsort(t,n,b);

cout<<"ola3"<<endl;
    for(int i=1;i<n;i++)
      if(t[i]<t[i-1])
        {cout<<"error"<<endl;
         //return -1;
         }
cout<<"good"<<endl;return 0;
cout<<"ola4"<<endl;
    for(int i=0;i<n;i++)
      cout<<t[i]<<' ';
    cout<<endl;
cout<<"ola5"<<endl;
    delete []t;
    delete []b;
}
catch(...)
{
    cout<<"brak pamięci"<<endl;
}

}

