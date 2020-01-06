#include <iostream>

using namespace std;

#include <iostream>

using namespace std;


void problema1()
{
    int r,n;
    cin>>n;
    r=0;
    do
    {
        r=(r*10+n%10)*10;
        n=n/100;
    }while(n>100);
    cout<<"r="<<r;
}
void problema2()
{
    int k,i,x,c,n;
    cin>>n;
    k=9;
    for(i=1;i<=n;i++)
    {
        cout<<"x=";
        cin>>x;
        c=x/10%10;
        if (c<k)
            k=c;
    }
    cout<<"k="<<k;
}
void problema3()
 {
     int max,n;
     cin>>n;
    max=0;
    do
    {
        n=n/10;
        if(max<n%10)
            max=n%10;

    }while(n!=0);
    cout<<"max="<<max;
}
void problema4()
{
    int a,b,c;
    cout<<"c=";
    cin>>c;
    cout<<"a=";
    cin>>a;
    cout<<"b";
    cin>>b;
    c=2*a-b;
    a=a-b;
    a=c-a;
    b=2*a-c;
}
void problema5()
{
    int x,y,z,t;
    cin>>x;
    cin>>y;
    cout<<"x=";
    cin>>x;
    cout<<"y=";\
    cin>>y;
    z=1;
    t=0;
    while (x>=z)
      {
          if (x%z==y)
          t=z;
      z=z+1;
      }
    cout<<"t="<<t;
}
void problema6()
{
    int y,x;
    cout<<"x=";
    cin>>x;
    y=0;
    do
    {
        y=y*10+9-x%10;

    }while((x>y)||(y!=0));
    cout<<"y="<<y;
}
void problema7()
{
  cout<<"a)";
}
void problema8()
{
    int x,y;
    cin>>x;
    cin>>y;
    while(x*y!=0)
        if (x>y)
    {
        x=x%y;
        y=y%x;
    }
    cout<<x+y;
}
void problema9()
{
    cout<<"b)";
}
void problema10()
{
    int x,y,z;
    cin>>x;
    cin>>y;
    while(y>0)
    {
        z=x%y;
        x=2*y;
        y=2*z;
    }
    cout<<"x="<<x;
}
void problema11()
{
    cout<<"a)";
}
void problema12()
{
    int i,j,p,n;
    cin>>n;
    for(i=1;i<n;i++)
      {
          p=1;
          for(j=i;j>=2;j--)
            p=p*j;
      }
     cout<<p/(i*2);
}
void problema13()
{

     int s,v,a,b;
     s=0;
     cin>>v;
     while(v!=0)
     {
         a=v%10;
         b=v/10%10;
         s=s+a*10+b;
         cout<<"v=";
         cin>>v;
     }
     cout<<"s="<<s;
}
void problema14()
{
 cout<<"c)";
}
void problema15()
{
    int a,b,c;
    cin>>a;
    cin>>b;
     if(a>b)
        {
        c=b;
        b=a;
        a=c;
        }
        while(a<=b)
        {
            cout<<"a="<<a;
            a=a*4;
        }
     cout<<"a="<<a;
}
void problema16()
{
    cout<<"d)";
}
void problema17()
{
    int a,b,k;
    cin>>a;
    cin>>b;
     k=0;
     b=(a+1)*(a+2)/2;
     while(b>=a)
         {
             b=b-a;
             k=k+1;
         }
    cout<<"b="<<b;
    cout<<"k="<<k;
}
void problema18()
{
    cout<<"b)";
}
void problema19()
{
    cout<<"d)";
}
void problema20()
{
    cout<<"a)";
}
void problema21()
{
    cout<<"a)";
}
void problema22()
{
    int n,m;
    cin>>n;
    cin>>m;
    while (n<=m)
    {
        n=n+1;
        m=m-1;
    }
    while(m<n)
    {
        m=m+1;
        n=n-1;
    }
    cout<<"n="<<n;
}
void problema23()
{
    float x;
    cin>>x;
    int y;
    y=(int)x;
    x=x-y;
    while(x!=(int)x)
       x=x*10;
    if(x=y)
        cout<<1;
    else
        cout<<2;
}
void problema24()
{
    cout<<"c)";
}
void problema25()
{   int i,k,j,a[10][10];
    for(i=1;i<=8;i++)
            k=1;
            for(j=1;j<=8;j++)
              {
                a[i][j]=k;
                k=k+1;
              }
}
void problema26()
{   int c,i,n;
    c=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        c=(c+1)%10;
        cout<<"c="<<c<<" ";
    }
}
void problema27()
{
    int t,a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    while(a<=b)
    {     if(a%c==0)
             cout<<a;
          a=a+1;
    }
    cout<<"a="<<a;
}
void problema28()
{
    int n,p,c;
    p=1;
    n=279;
    c=0;
    while(n>=100)
    {
        p=p*10;
        n=n-100;
        c=c+1;
    }
}
void problema29()
{
    int x,y;
    cin>>x;
    cin>>y;

    if(x<y)
    {
        x=x-y;
        y=x+y;
        x=y-x;
    }
    while(x>=y)
    {
        cout<<"A";
        x=x-y;
        cout<<"B";
    }
}
void problema30()
{
    int y,x;
    cin>>x;
    y=0;
    do
    {
        x=x/10;
        y=y+1;
    }while(x%100==0);
}
void problema31()
{
  cout<<"a)";
}
void problema32()
{
    int x,y;
    cin>>x;
    cin>>y;
    if(x>y)
        y=x;
    if(x%2==0)
        x=x+1;
    while(x<=y)
    {
        x=x+2;
        cout<<"*";
    }
}
void problema33()
{
    cout<<"c)";
}
void problema34()
{
   int i,a,n;
   cin>>a;
   cin>>n;
   for(i=1;i<=n;i++)
       if (i%2==0)
         a=a-i*i;
       else
         a=a+i*i;
   cout<<a;
}
void problema35()
{
    cout<<"a)";
}
void problema36()
{
    int i,n,j;
    cin>>n;
    for(i=1;i<n;i++)
      {
          if(i%2==0)
            cout<<"#";
          for(j=i+1;j<=n;j++)
            cout<<"*";
      }

}
void problema37()
{
    cout<<"a)";
}
void problema38()
{
    cout<<"c)";
}
void problema39()
{
    cout<<"d)";
}
void problema40()
{
    int s,n;
    cin>>n;
    s=10;
    while(n>0)
      {
          if (n%10<s)
           s=n%10;
          else
            s=-1;
        n=n/10;
      }
    cout<<s;

}
void problema41()
{
    cout<<"c)";
}
void problema42()
{
    cout<<"a)";
}
void problema43()
{
    int s,n;

    s=-1;
    while(n>0)
    {
        if(n%10>s)
           s=n%10;
         else
            s=11;
        n=n/10;
    }
    cout<<s;
}
void problema44()
{
    cout<<"d)";
}
void problema45()
{
    int y,z,x;
    cin>>z;
    cin>>x;
    while(x>0)
    {
        cin>>y;
        if(z<y-x)
            cout<<x%10<<",";
        else
        cout<<y%10<<",";
    }

}
void problema46()
{
    int t,a,b,x;
    cin>>a;
    cin>>b;
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    for(x=a;x<=b;x--)

        if(x%2!=0)
            cout<<x;
}
void problema47()
{
    cout<<"b)";
}
void problema48()
{
    int x,y;
    cin>>x;
    while(x>0)
    {
        cin>>y;
        if(x>y)
            cout<<x%10;
        else
            cout<<y%10;
        x=y;
    }
}
void problema49()
{
    cout<<"a),c),d)";
}
void problema50()
{
   int z,p,c,n;
   cin>>n;
   z=0;
   p=1;
   while(n>0)
   {
       c=n%10;
       n=n/10;
       if(c%3==0)
        z=z+p*9-c;
   }
   cout<<z;
}
int main()
{
    int x;
    cout<<"Problema: ";
    cin>>x;
    switch(x)
    {
    case 1:
        cout<<"Problema 1:"<<endl;
        problema1();
        break;
    case 2:
        cout<<endl<<"Problema 2:"<<endl;
        problema2();
        break;
    case 3:
        cout<<endl<<"Problema 3:"<<endl;
        problema3();
        break;
    case 4:
        cout<<endl<<"Problema 4:"<<endl;
        problema4();
        break;
    case 5:
        cout<<endl<<"Problema 5:"<<endl;
        problema5();
        break;
    case 6:
        cout<<"Problema 6:"<<endl;
        problema6();
        break;
    case 7:
        cout<<endl<<"Problema 7:"<<endl;
        problema7();
        break;
    case 8:
        cout<<endl<<"Problema 8:"<<endl;
        problema8();
        break;
    case 9:
        cout<<endl<<"Problema 9:"<<endl;
        problema9();
        break;
    case 10:
        cout<<endl<<"Problema 10:"<<endl;
        problema10();
        break;
    case 11:
        cout<<endl<<"Problema 11:"<<endl;
        problema11();
        break;
    case 12:
        cout<<endl<<"Problema 12:"<<endl;
        problema12();
        break;
    case 13:
        cout<<endl<<"Problema 13:"<<endl;
        problema13();
        break;
    case 14:
        cout<<endl<<"Problema 14:"<<endl;
        problema14();
        break;
    case 15:
        cout<<endl<<"Problema 15:"<<endl;
        problema15();
        break;
    case 16:
        cout<<endl<<"Problema 16:"<<endl;
        problema16();
        break;
    case 17:
        cout<<endl<<"Problema 17:"<<endl;
        problema17();
        break;
    case 18:
        cout<<endl<<"Problema 18:"<<endl;
        problema18();
        break;
    case 19:
        cout<<endl<<"Problema 19:"<<endl;
        problema19();
        break;
    case 20:
        cout<<endl<<"Problema 20:"<<endl;
        problema20();
        break;
    case 21:
        cout<<endl<<"Problema 21:"<<endl;
        problema21();
        break;
    case 22:
        cout<<endl<<"Problema 22:"<<endl;
        problema22();
        break;
    case 23:
        cout<<endl<<"Problema 23:"<<endl;
        problema23();
        break;
    case 24:
        cout<<endl<<"Problema 24:"<<endl;
        problema24();
        break;
    case 25:
        cout<<endl<<"Problema 25:"<<endl;
        problema25();
        break;
    case 26:
        cout<<endl<<"Problema 26:"<<endl;
        problema26();
        break;
    case 27:
        cout<<endl<<"Problema 27:"<<endl;
        problema27();
        break;
    case 28:
        cout<<endl<<"Problema 28:"<<endl;
        problema28();
        break;
    case 29:
        cout<<endl<<"Problema 29:"<<endl;
        problema29();
        break;
    case 30:
        cout<<endl<<"Problema 30:"<<endl;
        problema30();
        break;
    case 31:
        cout<<endl<<"Problema 31:"<<endl;
        problema31();
        break;
    case 32:
        cout<<endl<<"Problema 32:"<<endl;
        problema32();
        break;
    case 33:
        cout<<endl<<"Problema 33:"<<endl;
        problema33();
        break;
    case 34:
        cout<<endl<<"Problema 34:"<<endl;
        problema34();
        break;
    case 35:
        cout<<endl<<"Problema 35:"<<endl;
        problema35();
        break;
    case 36:
        cout<<endl<<"Problema 36:"<<endl;
        problema36();
        break;
    case 37:
        cout<<endl<<"Problema 37:"<<endl;
        problema37();
        break;
    case 38:
        cout<<endl<<"Problema 38:"<<endl;
        problema38();
        break;
    case 39:
        cout<<endl<<"Problema 39:"<<endl;
        problema39();
        break;
    case 40:
        cout<<endl<<"Problema 40:"<<endl;
        problema40();
        break;
    case 41:
        cout<<endl<<"Problema 41:"<<endl;
        problema41();
        break;
    case 42:
        cout<<endl<<"Problema 42:"<<endl;
        problema42();
        break;
    case 43:
        cout<<endl<<"Problema 43:"<<endl;
        problema43();
        break;
    case 44:
        cout<<endl<<"Problema 44:"<<endl;
        problema44();
        break;
    case 45:
        cout<<endl<<"Problema 45:"<<endl;
        problema45();
        break;
    case 46:
        cout<<endl<<"Problema 46:"<<endl;
        problema46();
        break;
    case 47:
        cout<<endl<<"Problema 47:"<<endl;
        problema47();
        break;
    case 48:
        cout<<endl<<"Problema 48:"<<endl;
        problema48();
        break;
    case 49:
        cout<<endl<<"Problema 49:"<<endl;
        problema49();
        break;
    case 50:
        cout<<endl<<"Problema 50:"<<endl;  //kk
        problema50();
        break;
    }

}
