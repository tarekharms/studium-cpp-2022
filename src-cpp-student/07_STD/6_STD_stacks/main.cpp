//  main.cpp
//  6_STD_stacks


#include <iostream>
#include "intStack.hpp"
#include "genericStack.hpp"
#include <vector>
#include <list>


void use_intStack(){
  intStack s_1;
  for(int i=0; i<10;i++){
    s_1.push(i*i);
  }
  std::cout << "s_1 : " << std::endl;
  s_1.print();
  // replace top element by 4711:
  s_1.pop();
  s_1.push(4711);
  // swap topmost two elements:
  int tmp1 = s_1.pop();
  int tmp2 = s_1.pop();
  s_1.push(tmp1);
  s_1.push(tmp2);
  std::cout << "draining s_1 : " << std::endl;
  while(!s_1.isEmpty()){
    std::cout << s_1.pop() << std::endl;
  }
}


void use_genericStack(){
  genericStack<int, 20> s_2;
  genericStack<double, 30> s_3;
  for(int i=0; i<10;i++){
    s_2.push(i*i);
    s_3.push(i*i * 1.1);
  }
  s_2.print();
  s_3.print();
}

void use_std_containers(){
  std::vector<int> v;
  v.push_back(17);         // append an element at the end
  int i = v.back();        // get last element
  int j = v[0];            // access by subscript operator
  if ((i==j) && (i==17)){  //
    v.pop_back();          // remove last element
    v.clear();             // remove all elements
  }
  long s = v.size();       // get size; size() <= max_size()
  std::list<long> l;
  l.push_back(17);         // append an element at the end
  l.push_front(s);         // put an element in front of the list
}

void printVector(const std::vector<int>& v){
  for(int j=0; j<v.size(); j++){
    std::cout << "[" << j << "]=" << v[j] << ", ";
  }
  std::cout << std::endl;
}

void use_std_algorithms(){
  std::vector<int> v(100);
  for(int i=0; i<10; i++){
    v[i*i] = i;
  }
  v.push_back(17);
  printVector(v);
  std::sort(v.begin(), v.end());
  printVector(v);
  std::transform(v.begin(), v.end(), v.begin(),
                 [](int i) { return i*10; }); // use lambda expression here
  printVector(v);
}

int main(int argc, const char * argv[]) {
  std::cout << "use_intStack()" << std::endl;
  std::cout << "--------------" << std::endl;
  use_intStack();
  std::cout << "use_genericStack()" << std::endl;
  std::cout << "------------------" << std::endl;
  use_genericStack();

  std::cout << "use_std_containers()" << std::endl;
  std::cout << "------------------" << std::endl;
  use_std_containers();
  std::cout << "use_std_algorithms()" << std::endl;
  std::cout << "------------------" << std::endl;
  use_std_algorithms();
  
  return 0;
}
