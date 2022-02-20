singleton单例设计模式定义
一个类仅有一个实例，并且提供对外唯一访问的函数/方法
- 通常实例构造函数是私有的，外部类无法通过调用构造方法创建实例。那也就意味着构造函数位于private内。
- 提供公开的get方法可以获取实例
主要应用于日志系统以及线程池中
总体可以参考https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
实现方法包括以下几种：
1. 饿汉
  在类加载的时候完成了初始化。缺点是即使不调用get也会初始化实例，占内存
```
#include <iostream>

using namespace std;

class Singleton {
   static Singleton *instance = new Singleton;
   int data;
    
   
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }

   public:
   static Singleton *getInstance() {
      return instance;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
   }
};


//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   return 0;
}
```
2. lazy
仅仅在调用*getInstance()获取实例的时候才初始化。缺点 不是线程安全的方法。为了确保线程级别的安全要尝试加锁。
```
#include <iostream>

using namespace std;

class Singleton {
   static Singleton *instance;
   int data;
 
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }

   public:
   static Singleton *getInstance() {
      if (!instance)
      instance = new Singleton;
      return instance;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   return 0;
}
```
3. lazy 线程安全的方法（上锁）
缺点是
```
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Singleton {
   static Singleton *instance;
   int data;
   std::mutex lock;
 
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }

   public:
   static Singleton *getInstance() {
      unique_lock<mutex> locker(lock)
      if (!instance)
      {
          instance = new Singleton;
          lock.unlock();
    
      }
      return instance;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   return 0;
}
```
4. double check 

