#include<iostream>
using namespace std;
char stack[20];
int top=-1;
void push(char x)
{
   stack[++top]=x;
   if(top>=20)
        cout<<"Stack is full";
   else{top++;
   stack[top]=x;}
}
char pop()
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
}
int priority(char x){
if(x=='(')
    return 0;
    if(x=='+'|| x=='-')
        return 1;
    if(x=='/'|| x=='*')
        return 2;
}
int main(){
 char exp[20];
 char *e,x;
 cout<<"Enter the expreesion: ";
 cin>>exp;
 while(*e!='\0')
    {
        if(isalnum(*e))
            cout<<*e;
        else if(*e=='(')
        push(*e);
        else if(*e==')')
            {while((x=pop())!='(')
                   cout<<x;
        }

    else
        while(priority(stack[top])>=priority(*e))
        cout<<pop();
          push(*e);

 }
 e++;
 while(top!=-1)
 {
     cout<<pop();
 }}

