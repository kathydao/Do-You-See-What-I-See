#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <cstdlib>

using namespace std;

template <typename T>
class MonoStack{
public:
  MonoStack();
  MonoStack(int iSize, char descendingOrder);
  ~MonoStack();
  void push(T c);
  void increaseSize();
  T* getStackArr();
  int getTopCount();
  T pop();
  T peek();
  bool isEmpty();
  bool isFull();
  int size();

private:
  T* stackArr;
  int top;
  int count;
  int max;
  char descendingOrder;

};
#endif