#include <iostream>
#include <vector>
using namespace std;
int main() {

    vector<int> a(5); //创建一个容量为5的vector向量
    //[0,0,0,0,0]


    a.push_back(1); //在尾部插入1
    a.push_back(2); //在尾部插入2
    //[0,0,0,0,1,2]


    a.pop_back(); //删除尾部最后一个元素
    //[0,0,0,0,0,1]


    cout << a.front() << endl; //返回第一个数据
    cout << a.back() << endl; //返回最后一个数据
    //a.front() = 0;a.back()=1;


    int i = 2;
    cout << a.at(i) << endl; //返回指定位置的数据
    cout << a[i] << endl; //返回指定位置的数据
    //a.at(i) = 0;a[i] = 0;


    cout << a.data() + 1 << endl; //返回第二个元素的地址
    cout << &a[1] << endl; //返回第二个元素的地址
    //a.date() + 1 =0x151189a1aa4;&a[1] = 0x151189a1aa4;


    cout << a.size() << endl; //返回元素个数
    cout << a.capacity() << endl; //返回容量:vector自动扩容为之前的两倍
    //a.size() = 6;a.capacity() = 10;


    a.begin(); //返回第一个元素的迭代器
    a.end(); //返回最后一个元素后一个位置的迭代器
    a.rbegin(); //返回最后一个元素的迭代器
    a.rend(); //返回第一个元素前一个位置的迭代器
    //迭代器可以通俗理解成地址


    auto it= a.begin() + 5;
    //auto为一中类型推导关键字，用于让编译器自动推导变量类型。例如：auto i=10,i的类型为int;auto i=0.1,i的类型为double
    //此处auto it= a.begin() + ;自动推导it类型为:std::vector<int>::iterator it
    cout << *it << endl; //返回第6个元素的值
    cout << *(a.data() + 5) << endl; //返回第6个元素的值
    cout << *(a.end() - 1) << endl; //返回最后一个元素的值
    cout << a.empty() << endl; //判断是否为空,为空返回1，不为空返回0
    //*it=1;*(a.data() + 5)=1;*(a.end() - 1)=1;a.empty()=0;


    a.reserve(200); //更改容器容量大小
    cout << a.capacity() << endl; //返回容量
    //a.capacity() = 200;


    a.assign({1, 2, 3, 4});//将容器重新赋值为{1,2,3,4}，size变为4，capacity不变
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i;
    }
    cout << endl;
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    //a = {1,2,3,4};a.size() = 4;a.capacity() = 4;


    a.assign(5, 2); //将容器的size变为5且所有元素重新赋值为2，但capacity不变
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i;
    }
    cout << endl;
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    //a={2,2,2,2,2};a.size() = 5;a.capacity() = 200;


    vector<int> b;
    b.assign(a.begin(), a.end()); //将a的元素全部赋值给b，b的size与a的size相同，但b的capacity与自身的size相同
    for (auto i = b.begin(); i != b.end(); i++) {
        cout << *i;
    }
    cout << endl;
    cout << b.size() << endl;
    cout << b.capacity() << endl;
    //b={2,2,2,2,2};b.size() = 5;b.capacity() = 5;


    a.emplace_back(1);//在尾部添加一个元素与push_back()用法基本相同
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i;
    }
    cout << endl;
    a.emplace(a.begin()+1, 3);//在指定位置插入元素
    cout<<*(a.begin()+1);
    cout << endl;
    //*(a.begin()+1)=3;a=[2,3,2,2,2,1];


    a.insert(a.begin()+1,6);//在指定位置插入一个元素与a.emplace(pos,val)用法基本相同
    cout<<*(a.begin()+1);
    cout << endl;
    //*(a.begin()+1)=6;a=[2,6,3,2,2,2,1];

    a.erase(a.begin()+1);//删除指定位置的元素
    a.erase(a.begin(), a.end()-1);//a.erase(first,last)删除[first,last)之间的元素，包括first，不包括last
    cout<<a.size();
    cout << endl;
    //a=[1];


    a.resize(5, 1);;//将size改为5，若size小于原size，则删除多余的元素，若size大于原size，则添加x元素补全size
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i;
    }
    cout << endl;
    //a=[1,1,1,1,1];
    a.resize(3);
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i;
    }
    cout << endl;
    //a=[1,1,1];


    a.clear();//清空容器
    cout << a.size() << endl;

    return 0;
}