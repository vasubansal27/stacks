// implementation of stack using array

#include <bits/stdc++.h>
using namespace std;
struct MyStack{
    int *arr;    //dynamic array
    int cap;
    int top;
    MyStack(int c){
        cap=c;
        arr=new int [cap];
        top=-1;
    }
    
    void push(int x){
        if(top==cap-1){cout<<"Stack is full"<<endl;return;}
        top++;
        arr[top]=x;
    }
    
    int pop(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return INT_MIN;}
        int res=arr[top];
        top--;
        return res;
    }
    
    int peek(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return INT_MIN;}
        return arr[top];
    }
    
    int size(){
        return (top+1);
    }
    
    bool isEmpty(){
        return top==-1;
    }
    void display()
    {
        cout << "The elements are : ";
        if(top==-1)
        {
            cout << "Empty stack";
            return;
        }
        for(int i=0;i<=top;i++)
           cout << arr[i] << " ";
    }
};

int main()
{
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    s.display();
  
    return 0; 
}





//implementation of stack using vector


#include <bits/stdc++.h>
using namespace std;

struct MyStack{
    vector<int> v;
    
    void push(int x){
        v.push_back(x);
    }
    
    int pop(){
        int res=v.back();
        v.pop_back();
        return res;
    }
    
    int peek(){
        return v.back();
    }
    
    int size(){
        return v.size();
    }
    
    bool isEmpty(){
        return v.empty();
    }
};

int main()
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0; 
}






//implementation of stack using linked list

#include <bits/stdc++.h>
using namespace std;

//node for linked list
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
//for stack
struct MyStack{
    Node *head;
    int sz;
    MyStack(){
        head=NULL;
        sz=0;
    }
    
    void push(int x){
        Node *temp=new Node(x);
        temp->next=head;
        head=temp;
        sz++;
    }
    
    int pop(){
        if(head==NULL){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        int res=head->data;
        Node *temp=head;
        head=head->next;
        delete(temp);
        sz--;
        return res;
    }
    
    int peek(){
        if(head==NULL){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        return head->data;
    }
    
    int size(){
        return sz;
    }
    
    bool isEmpty(){
        return head==NULL;
    }
};

int main()
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0; 
}





//REVERSE ARRAY
void reverseArray(int n, int* arr){
       stack<int> st;
       for(int i=0;i<n;i++){
           st.push(arr[i]);
       }
       int i =0;
       while(!st.empty()){
           arr[i++] = st.top();
           st.pop();
       }
    }






//GETMIN FOR EACH ELEMENT

stack<int > as;  //using auxilary array
//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
   // your code here
   stack<int> st;
   for(int i=0;i<n;i++){
       st.push(arr[i]);
       if(as.empty())
           as.push(arr[i]);
       else if(arr[i]<=as.top())
           as.push(arr[i]);
  }
  //cout<<as.top()<<endl;
   return st;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    // your code here
     while(s.empty()==false){
       if(s.top()!=as.top()){
           cout<<as.top()<<" ";
           s.pop();
       }
       else{
           cout<<as.top()<<" ";
           s.pop();
           as.pop();
       }
   }
}




//PARANTHESES CHECKER

bool ispar(string s)
    {
        // Your code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return 0;
                }
                else{
                    char val = st.top();
                    st.pop();
                    if(s[i]==']' && val!='['){
                        return 0;
                    }
                    else if(s[i]==')' && val!='('){
                        return 0;
                    }
                    else if(s[i]=='}' && val!='{'){
                        return 0;
                    }
                }
            }
        }
        if(st.empty()){
            return 1;
        }
        else{
            return 0;
        }
    }


//STOCK SPAN  PROBLEM 
//number of elements less than or equal it before it consecutively
//indices
stack<int>s;
s.push(0) //index of first element
for(int i=1;i<n;i++)
{
    while(!s.empty() && arr[s.top()]<=arr[i])
                s.pop();
    int span=(s.empty())?(i+1):(i-s.top());
    cout < span < " ";
    s.push(i);
}


