# visitor_ptr
一个原始指针的封装，用于补充STL的智能指针

## 说明
visitor_ptr是一种不持有资源的指针，类似于原始指针，但是可以避免使用原始指针，保持一致性(强迫症必备)<br>

### 例子
```
#include <utility>
#include <memory>
#include <iostream>
#include "visitor_ptr.h"

void func(Fuck *f){
  std::cout<<"func:"<<f->a<<std::endl;
}

struct Fuck{
  int a;
  
  Fuck(int d):a(a){}
  ~Fuck() = default;
  
  void fuck(){
    std::cout<<"fuck"<<a<<std::endl;
  }
};

int main(int argc,char *argv[]){
  auto up = std::make_unique<Fuck>(123);
  auto vp = std::visitor_ptr<Fuck>(up);//initilizing visitor_ptr through unique_ptr
  vp->fuck();//operator->()
  std::cout<<vp.get()<<std::endl;//same as unique_ptr
  func(vp);//same as raw pointer
  return 0;
}
```
