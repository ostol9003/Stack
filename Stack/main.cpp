//
//  main.cpp
//  Stack
//
//  Created by Marcin Ostolski on 23/02/2022.
//

#include <iostream>
using namespace std;

const int LIMIT = 30;
typedef int item_t;
struct Stack
{
    int tab[LIMIT];
    item_t top;
};

void create(Stack &s){
    s.top = -1;
}

int isEmpty(Stack s){
    if(s.top == -1) return 1;
    return 0;
    
    //return (s.top == -1);
    
}

int isFull(Stack s){
    if(s.top==LIMIT-1)return 1;
    return 0;
}

void push(Stack &s, item_t x){
    if (!isFull(s))
    {
        s.top=s.top+1;
        s.tab[s.top]=x;
    }
}

item_t pop(Stack &s){
    if (!isEmpty(s))
    {
        s.top=s.top-1;
        return s.tab[s.top+1];
    }
    else
        return -1000;
}

item_t top(Stack &s){
    if (!isEmpty(s))
    {
        return s.tab[s.top];
    }
    else
        return -1000;
}

void decToBin(Stack &s, item_t x)
{
    while (x)
    {
        s.tab[++s.top] = x % 2;
        x/=2;
    }
    cout << "Liczba zapisana w systemie dwojkowym: ";
    for (int i=s.top; i>=0;i--) cout << s.tab[i];
    
}

void reverse(Stack &s)
{
    item_t tmp;
    for(int i=0;i<=(s.top/2);i++)
    {
        tmp=s.tab[i];
        s.tab[i]=s.tab[s.top-i];
        s.tab[s.top-i]=tmp;
    }
}
void printStack(Stack &s)
{
    for(int i=0;i<=s.top;i++)
        cout<<s.tab[i]<<", ";
}
int main()
{
    Stack s,sdtb;
    create(s);
    create(sdtb);
    
    item_t x;
    x = pop(s);
    cout << x <<endl;
    push(s, 11);
    push(s, 55);
    push(s, 31);
    push(s, -15);
    push(s, 551);
    push(s, 311);
    push(s, -151);
    cout << "Na szczycie stosu jest " << top(s) <<endl;
    cout << "Operacja pop: " << pop(s) << endl;
    cout << "Operacja pop: " << pop(s) << endl;
    cout << "Na szczycie stosu jest " << top(s) <<endl;
    
    
    // ZADANIE DOMOWE
    
    
    cout << "Wyswietlam stos przed odwroceniem: " << endl;
    printStack(s);
    reverse(s);
    cout << "\nWyswietlam stos po odwroceniu: " << endl;
    printStack(s);
    
    item_t dziesietna;
    cout << "\n\nPodaj liczbe dziesietna: " << endl;
    cin >> dziesietna;
    
    decToBin(sdtb, dziesietna);
    cout<<endl;
    
    
    return 0;
}
