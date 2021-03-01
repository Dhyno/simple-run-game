#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include"print_game.h"
using namespace std;
struct game{
private:
    int arr_map[360];
    int body[8]={1,41,81,121,161,201,241,281};
    int em_body=0;
    int score=0;
public:

    void handle_map();
    int show_map_body(int&,int&,int,char*,int&,int&);
    void reset_body();
    void handle_input(char*,int*,int&);

}g_map,reset;;

int main()
{
    char rep;
    print_1();
    Sleep(1000);
    while(1)
    {
       g_map.handle_map();
       system("cls");
       print_2();
       rep=getch();
       g_map=reset;
       if(rep=='n')
         break;
    }
    return 0;
}

void game::handle_map()
{
    int re_val=0;
    int con=0;

    int j_ind=0;
    int k_ind=0;
    int bod_ind=0;

    srand(time(0));
    char input='l';
    int pos=319;
    int user_ind=7;
    g_map.em_body=rand()%7+1;
    while(1)
    {
        con=g_map.show_map_body(j_ind,k_ind,bod_ind,&input,pos,user_ind);
        g_map.handle_input(&input,&pos,user_ind);
        if(re_val==40)
        {
            g_map.reset_body();
            g_map.em_body=rand()%7+1;
            re_val=0;
        }
        re_val++;
        if(con==1)
            g_map.score+=10;
        else if(con==2)
        {
            cout<<"game over\n";
            break;
        }
        cout<<"\nscore : "<<g_map.score<<endl;
        system("cls");
        input='l';
    }
}
int game::show_map_body(int& j,int& k,int bod,char* inp,int& position,int& i_user)
{
    int a=0;
    for(j=0;j<360;j++)
    {
        if(k==40)
        {
            cout<<"|"<<endl;
            k=0;
        }
        else if(g_map.body[bod]==j && bod!=g_map.em_body)
        {
            cout<<"->";
            bod++;
        }
        else if(g_map.body[bod]==j && bod==g_map.em_body)
        {
            cout<<"  ";
            bod++;
        }
        else if(j>=321)
            cout<<"=";
        else if(position==j)
            cout<<"*";
        else if((i_user==g_map.em_body)&& g_map.body[7]==319)
            a=1;
        else if((i_user!=g_map.em_body)&& g_map.body[7]==319)
            a=2;
        else
            cout<<" ";
        k++;
    }
    for(j=0;j<8;j++)
        g_map.body[j]+=1;
    if(kbhit())
        *inp=getch();
    return a;
}
void game::reset_body()
{
    for(int i=0;i<8;i++)
    {
        g_map.body[i]-=40;
    }
}
void game::handle_input(char* inp,int* position,int& i_user)
{
    if(*inp=='w'&&(*position<=319&&*position>=79))
    {
        *position-=40;
        i_user-=1;
    }
    else if(*inp=='s'&&(*position>=39&& *position<=279))
    {
        *position+=40;
        i_user+=1;
    }

}













