//
//  main.cpp
//  Stack
//
//  Created by Nadal Alyafaie on 10/27/15.
//  Copyright © 2015 Nadal Alyafaie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//pop,top,push,empty,and size

void die() {
    cout << "BAD INPUT\n";
    exit(EXIT_FAILURE);
}

class Stack {
    
private:
    vector<int>stackOperand =  {};
    
public:
    void pop();
    int top();
    void push(int);
    bool empty();
    int size();
    void print();
};




void Stack::print(){
    for(auto &i : stackOperand)
        cout << i << endl;
    
}



void Stack::pop(){
    if(stackOperand.size()<1)
        die();
    stackOperand.pop_back();
}



int Stack::top(){
    
    int endNumber;
    if(stackOperand.size()==0)
        die();
    endNumber = stackOperand.at(stackOperand.size() -1);
    
    return endNumber;
}



void Stack :: push(int number){
    
    stackOperand.push_back(number);
    
}



bool Stack :: empty(){
    if (stackOperand.size()==0) {
        return 1;
    }
    return 0;
}



int Stack :: size(){
    return stackOperand.size();
}





int main() {
    
    Stack myStack;
    int input;
    int number;
    char mathSign;
    
    cout << "Enter numbers\n";
    
    while (cin) {
        cin >> ws;
        input = cin.peek(); // Peek at next letter to read
        if (input == !cin) {break;}
        
        if (!isdigit(input)) //Should be +,-,*,/,%,^,E(which will end)
        {
            int tempNumber1;
            int tempNumber2;
            int FinalNumber;
            
            cin >> mathSign;
            
            tempNumber1 = myStack.top();
            myStack.pop();
            
            if (mathSign=='E') {
        
            }
            
            else{
            tempNumber2 = myStack.top();
            myStack.pop();
            }
            
            switch (mathSign) {
                case '+':
                    
                    FinalNumber = tempNumber1 + tempNumber2;
                    myStack.push(FinalNumber);
                    break;
                    
                case '-':
                    
                    FinalNumber = tempNumber1 - tempNumber2;
                    myStack.push(FinalNumber);
                    break;
                    
                case '*':
                    
                    FinalNumber = tempNumber1 * tempNumber2;
                    myStack.push(FinalNumber);
                    break;
                    
                case '/':
                    
                    FinalNumber = tempNumber1 / tempNumber2;
                    myStack.push(FinalNumber);
                    break;
                    
                case '^':
                    
                    FinalNumber = pow(tempNumber1, tempNumber2);
                    myStack.push(FinalNumber);
                    break;
                    
                case '%':
                    
                    FinalNumber = tempNumber1 % tempNumber2;
                    myStack.push(FinalNumber);
                    break;
                    
                case 'E':
                    if(myStack.size()>1)
                        die();
                    cout << tempNumber1;
                    break;
                    
                default:
                    die();
            }
            
            
            //somehow do the operation of tempnumber1 and tempNumber2 with the mathsign that was passed in and store it into FinalNumber.
        }
        
        else{
            
            cin >> number;
            myStack.push(number);
        }
        
    }
    
}
