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

void change(Stack &s, item_t x)
{
   while (x)
   {
       s.tab[++s.top] = x % 2;
       x/=2;
   }
    cout << "Liczba zapisana w systemie dwojkowym: ";
    for (int i=s.top; i>=0;i--) cout << s.tab[i];
    
}

int main()
{
    Stack s;
    create(s);
    item_t x;
    x = pop(s);
    cout << x <<endl;
//    push(s, 11);
//    push(s, 55);
//    push(s, 31);
//    push(s, -15);
//    cout << "Na szczycie stosu jest " << top(s) <<endl;
//    cout << "Operacja pop: " << pop(s) << endl;
//    cout << "Operacja pop: " << pop(s) << endl;
//    cout << "Na szczycie stosu jest " << top(s) <<endl;
    
    item_t dziesietna;
    cout << "Podaj liczbe dziesietna: " << endl;
    cin >> dziesietna;
    
    change(s, dziesietna);

    //...
    return 0;
}
