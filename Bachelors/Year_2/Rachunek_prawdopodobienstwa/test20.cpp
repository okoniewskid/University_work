#include <cstdlib>
#include <iostream>
#include <ctime> 
int E11=2167;
int E12=7097;
int E13=736;
int E21=4664;
int E22=4569;
int E23=767;
int E31=223;
int E32=9445;
int E33=332;
int m=101319;

using namespace std;

void losuj2(int ile);
void losuj3(int ile);

int losuj(int E1, int E2, int E3)
            {
            int tb[3]={E1, E2, E3};
            int n=rand()%(10000)+1;
            for(int i=0; i<2; i++)
                    for(int j=0; j<2; j++)
                            if(tb[j]>tb[j+1])
                               swap(tb[j], tb[j+1]);   
            n-=tb[0];
            if(n<=0)
                    {
                    if(tb[0]==E1)
                                 return 1;
                    else if(tb[0]==E2) 
                                 return 2;  
                    else
                                 return 3;
                    }
            else
                    {
                    n-=tb[1];
                    if(n<=0)
                            {
                            if(tb[1]==E1)
                                 return 1;
                            else if(tb[1]==E2) 
                                 return 2;  
                            else
                                 return 3;
                            }
                    else
                            {
                            if(tb[2]==E1)
                                 return 1;
                            else if(tb[2]==E2) 
                                 return 2;  
                            else
                                 return 3;
                            }
                    }
            } 
       
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int l=losuj(E11, E12, E13), powtorznia=0, cz1=0, cz2=0, cz3=0, ilepr=0, ilekl=0,
        ilee1=0, ile=0, j=0;
    bool powrot=false;
    cz1++;
    for(int i=0; i<m-1; i++)
            {
            if(l==1)
                  {
                  ile++;
                  ilee1+=ile;
                  powtorznia++;
                  if(powtorznia>=m-100)
                                       {
                                       cout<<"1";
                                       if((m-powtorznia-1)%25==0)
                                                        cout<<endl;
                                       }
                  ile=0;
                  ilekl++;
                  if(powrot==false)
                                   {
                                   ilepr++;
                                   powrot=true;
                                   }
                  l=losuj(E11, E12, E13);
                  cz1++;
                  }  
            else if(l==2)
                  {
                  ile++;
                  powtorznia++;
                  if(powtorznia>=m-100)
                                       {
                                       cout<<"2";
                                       if((m-powtorznia-1)%25==0)
                                                        cout<<endl;
                                       }
                  if(powrot==false)
                                   ilepr++;
                  l=losuj(E21, E22, E23);
                  cz2++;
                  } 
            else
                  {
                  ile++;
                  powtorznia++;
                  if(powtorznia>=m-100)
                                       {
                                       cout<<"3";
                                       if((m-powtorznia-1)%25==0)
                                                        cout<<endl;
                                       }
                  if(powrot==false)
                                   ilepr++;
                  l=losuj(E31, E32, E33); 
                  cz3++;
                  }
            }
    cout<<endl;
    cout<<"Czestosc E1: "<<(double)cz1/m<<endl;
    cout<<"Czestosc E2: "<<(double)cz2/m<<endl;
    cout<<"Czestosc E3: "<<(double)cz3/m<<endl;
    cout<<endl;
    cout<<"Po raz pierwszy powrocil do wierzcholka E1 po "<<ilepr<<" krokach."<<endl;
    cout<<endl;
    cout<<"Srednia liczba krokow po ktorych lancuch powraca do wierzcholka E1: "<<(double)ilee1/ilekl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
