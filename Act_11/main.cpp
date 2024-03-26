#include <iostream>
#include <windows.h>
#include <string.h>

#include "stack.h"
#include "queue.h"
#include "E.h"

using namespace std;

int main() {
    char e;
    E elem;
    E sum,rest,mul,div,pot,para,parc;
    e = '+';
    sum.setElement(e);
    e = '-';
    rest.setElement(e);
    e = '*';
    mul.setElement(e);
    e = '/';
    div.setElement(e);
    e = '^';
    pot.setElement(e);
    e = '(';
    para.setElement(e);
    e = ')';
    parc.setElement(e);
    Stack<E> myStack;
    Queue<E> myQueue;
    char mychar[1024];
    int lon;
    cout << "Ingrese la cadena a comvertir a posfija" << endl;
    cin >> mychar;
    lon = strlen(mychar);
    for(int i(0) ; i <= lon ; i++) {
        elem.setElement(mychar[i]);
        switch(mychar[i]) {
        case '(':
            try {
                myStack.push(elem);
            } catch(Stack<E>::Exception ex) {
                cout << ex.what() << endl;
            }
            break;
        case ')':
            try {
                while(!myStack.isEmpty()){
                    if(myStack.getTop() == para ) {
                        myStack.pop();
                        break;
                    } else {
                        myQueue.enqueue(myStack.getTop());
                        myStack.pop();
                    }
                }
            } catch(Stack<E>::Exception ex) {
                cout << ex.what() << endl;
            }
            break;
        case '+':
            try {
                if(myStack.isEmpty() == true) {
                    myStack.push(elem);
                    break;
                }
                if(myStack.getTop() == para ) {
                    myStack.push(elem);
                    break;
                }
                while(!myStack.isEmpty()) {
                    if(myStack.getTop() == para ) {
                        myStack.pop();
                        break;
                    } else {
                        myQueue.enqueue(myStack.getTop());
                        myStack.pop();
                    }
                }
            } catch(Stack<E>::Exception ex) {
                cout << ex.what() << endl;
            }
        case '-':
            try {
                if(myStack.isEmpty() == true) {
                    myStack.push(elem);
                    break;
                }
                if(myStack.getTop() == para) {
                    myStack.push(elem);
                    break;
                }
                while(!myStack.isEmpty()) {
                    if(myStack.getTop() == para) {
                        myStack.pop();
                        break;
                    } else {
                        myQueue.enqueue(myStack.getTop());
                        myStack.pop();
                    }
                }
            } catch(Stack<E>::Exception ex) {
                cout << ex.what() << endl;
            }
        case '*':
            try {
                if(myStack.isEmpty() == true) {
                    myStack.push(elem);
                    break;
                }
                if(myStack.getTop() == para) {
                    myStack.push(elem);
                    break;
                }
                if( myStack.getTop() == pot or myStack.getTop() == mul or myStack.getTop() == div ) {
                    myQueue.enqueue(myStack.getTop());
                    myStack.pop();
                    myStack.push(elem);
                } else {
                    myStack.push(elem);
                }

            } catch(Stack<E>::Exception ex) {
                cout << ex.what() << endl;
            }
            break;
        case '/':
            try {
                if(myStack.isEmpty() == true) {
                    myStack.push(elem);
                    break;
                }
                if(myStack.getTop() == para) {
                    myStack.push(elem);
                    break;
                }
                if( myStack.getTop() == pot or myStack.getTop() == mul or myStack.getTop() == div ) {
                    myQueue.enqueue(myStack.getTop());
                    myStack.pop();
                    myStack.push(elem);
                } else {
                    myStack.push(elem);
                }
            } catch(Stack<E>::Exception ex) {
                cout << ex.what() << endl;
            }
            break;
        case '^':

            try {
                if(myStack.isEmpty() == true) {
                    myStack.push(elem);
                    break;
                }
                if(myStack.getTop() == para) {
                    myStack.push(elem);
                    break;
                }
                if( myStack.getTop() == pot ) {
                    myQueue.enqueue(myStack.getTop());
                    myStack.pop();
                    myStack.push(elem);
                } else {
                    myStack.push(elem);
                }
            } catch(Stack<E>::Exception ex) {
                cout << ex.what() << endl;
            }
            break;
        default:
            try {
                myQueue.enqueue(elem);
            } catch(Stack<E>::Exception ex) {
                cout << ex.what() << endl;
            }
            break;
        }
    }
    try {
        while(!myStack.isEmpty()) {
            myQueue.enqueue(myStack.getTop());
            myStack.pop();
        }
    } catch(Stack<E>::Exception ex) {
        cout << ex.what() << endl;
    }
    cout << "El resultado es: ";
    while( !myQueue.isEmpty() ){
        cout << myQueue.getFront();
        myQueue.dequeue();
    }
    cout << endl << endl;
    gets(mychar);
    return 0;
}

