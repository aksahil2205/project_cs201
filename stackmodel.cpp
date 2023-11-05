#include<bits/stdc++.h>
using namespace std;

struct tickets{
    int taxi = 12;
};

struct player{
    struct tickets ticket;
    int posn;
}detective[3], x;

 void turn(int i, char s){
   
     if(s == 'T'){
        detective[i].ticket.taxi--;
        x.ticket.taxi++;
        return;}
   
 }






