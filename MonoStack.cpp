#include "MonoStack.h"
#include <iostream>
#include <string>

using namespace std;

//Class constructor 
template <typename T>
MonoStack<T>::MonoStack(){
  stackArr = NULL;
  count = 0;
  max = 0;
  top = -1;
}

//Class overloaded constructor
template <typename T>
MonoStack<T>::MonoStack(int iSize, char descendingOrder){
  count = 0;
  top = -1;
  max = iSize;
  this->descendingOrder = descendingOrder;
  stackArr = new T[iSize];
}

//Class destructor 
template <typename T>
MonoStack<T>::~MonoStack(){
  delete[] stackArr;
}

//Popping values from the stack, organizing the them in monotonic direction, and add them into new stack 
template <typename T>
void MonoStack<T>::push(T c){
  //Checks if the stack is full
  if (isFull()){
    //If it is then the function increaseSize is called to increase the size of the stack
    increaseSize();
  }
  
  //While the monotonic direction is descending, continue to pop the element from the stack for as long as it is not empty and less than c
  if (descendingOrder == 'd'){
    while (!isEmpty() && stackArr[top] < c){
      pop();
    }
  } else {
    while (!isEmpty() && stackArr[top] > c){
      pop();
    }
  }
  //After reorganized in monotonic direction, pushes new element c into new stack, and increase the count 
  stackArr[++top] = c;
  ++count;
}

//Increasing the capacity of the stack of the stack
template <typename T>
void MonoStack<T>::increaseSize(){
  T* temp = new T[2 * max];
  for (int i = 0; i < max; ++i){
    temp[i] = stackArr[i];
  }
  max *= 2;
  delete[] stackArr;
  stackArr = temp;
}

//Return the pointer array of the stack 
template <typename T>
T* MonoStack<T>::getStackArr(){
  return stackArr;
}

//Return the number of items that are in the stack as an integer
template <typename T>
int MonoStack<T>::getTopCount(){
  return top;
}

//Pop elements from the stack, decreasing the count
template <typename T>
T MonoStack<T>::pop(){
  --count;
  return stackArr[--top];
}

//Peek the top of the stack 
template <typename T>
T MonoStack<T>::peek(){
  return stackArr[top];
}

//Boolean to check if the stack is empty or not 
template <typename T>
bool MonoStack<T>::isEmpty(){
  return (count==0);
}

//Boolean to check if the stack is full
template <typename T>
bool MonoStack<T>::isFull(){
  return (count==max);
}

//Returns the count of size of the stack as an integer
template <typename T>
int MonoStack<T>::size(){
  return count;
}

