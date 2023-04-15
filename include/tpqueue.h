// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>
#include <string>

template <typename T, int size>
class TPQueue {
 private:
 T *arr;
  int begin, end;
  int;
  int stepBack(int index) {
      int res = --index;
      if (res < 0)
        res += size+1;
      return res;
  }
  int stepForward(int index) {
      int res = ++index;
      if (res > size)
        res -= size + 1;
      return res;
      }

 public:
TPQueue():
begin(0), end(0), count(0) {
arr = new T[size + 1];
}
~TPQueue() {
delete[] arr;
}
void push(const T& value) {
  if (isFull()) {
  throw std::string("is Full!");
  } else {
  int flag = end;
  for (int i = begin; i < end; i++) {
  if (value.prior > arr[i].prior) {
  flag = i;
  break;
  }
  }
  for (int i = end; i > flag; i--) {
  arr[i % size] = arr[(i - 1) % size];
  }
  arr[flag % size] = value;
  count++;
  end++;
}
}
T pop() {
assert(count > 0);
T item = arr[begin];
count--;
begin = stepForward(begin);
return item;
}
T get() const {
assert(count > 0);
return arr[begin];
}
bool isEmpty() const {
return count == 0;
}
bool isFull() const {
return count == size;
}
};
struct SYM {
char ch;
int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
