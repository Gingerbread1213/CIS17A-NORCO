
// Module 2
// Pointer
    // How pointer work
    // the advantages of using pointer

// 这次的代码我分section创建了不同的function
// 在学习某个section的时候 单独打开某一个 将剩下的section 用// 给comment掉
// 这样可以更加清晰

// 在学习指针之前，必须明白一个基础逻辑
// 所有的object，例如 int bool 这些变量，以及一些function
// 在创建以后都会被储存在memory里
// 计算机为了更容易找到他们，都给他们各自标记上了地址
// 计算机在运行程序时会先临时的将这些object创建，最后在结束运行的时候统一销毁
// 为了更加灵活的运用这些地址，并且以一个更加底层的方式去操纵内存
// c++ 创建了指针变量
// 指针变量中储存的是一个变量中的地址
// 详细的运作将会在后面的程序中解释


#include <iostream>
#include <memory>


void s1();
void s2();
void s2_1(int &x);
void s3();
void s4();
void s5();
void s5_1(int *x);
void s6();
void s7();
int *s7_1(int x);
void s8();


using namespace std;

int main(){
    
    //s1();
    //s2();
    //s3();
    //s4();
    //s5();
    //s6();
    //s7();
    //s8();
    
    return 0;
}



void s1(){
    
    int num = 1;
    cout << "这是num的地址： " << &num << endl;
    // & 符号是取址符（获取地址的符号）
    //所以上面的指令会在程序中打出 num 地址
    
    return;
}



void s2(){
    
    // 如果你没tmd忘
    // 之前在上一节课的时候有学过一个东西叫 reference function
    // 这种函数的用处就是可以通过地址来直接更改你放入的数据
    // 而不是返回一个值
    // 例如s2_1
    
    int x;
    s2_1(x);
    cout << "这是你刚刚输入的数字： " << x << endl;
    

    // 指针变量的使用就类似于这种方法
    // 他也可以通过地址来直接修改你的值
    
    
    int *intptr = nullptr; // 这是一个int类型的指针，它只可以装载int类型object的地址
    // *(指针)
    // 在创建指针时最好提前将指针指向一个空地址 “nullptr”
    int num = 4;
    intptr = &num; // 把intptr的指针指向了num
    
    cout << "我是num的地址： " << intptr << endl; //这个会打出num的地址
    cout << "我是num： " << *intptr << endl; //这个会打出num中储存的值
    
    *intptr=10; // 这样就把10通过intptr这个指针中储存的地址，储存进了num里
    
    cout << "我是新的num： " << *intptr << endl; //这个会打出改变后num中储存的值
    cout << "我是新的num： " << num << endl; //这个会打出改变后num中储存的值
    
}
void s2_1(int &x){
    
    cout << "Please enter a number: ";
    cin >> x;
    
    return;
}


void s3(){
    
    // 实际上 array 本身也是一个pointer性质的变量
    // 例如：
    
    int arr[3] = {1,2,3};
    cout << "这是arr的地址： " << arr << endl;
    // 只有在 arr 之后的括号中输入想要的数位才能得到想要的值
    
    // 那既然 arr 是一个地址，那我们如果使用指针来读取这个array会发生什么？
    
    cout << "这是直接使用指针读取的arr：" << *arr << endl;
    
    // 你会发现我们可以读取出来这个数组的第0位
    // 那如果直接将arr，也就是这个数组的地址存进指针呢？
    
    int *arrptr = arr;
    cout << "这是arr的第二位：" << arrptr[2] << endl;
    
    // 也就是说我们可以直接通过指针的方式来读取array中任意位置的值
    
    // 还有一个比较二的方法
    cout << "这是arr的第一位：" << *(arrptr+1) << endl;
    // (arrptr+1) 代表arr的地址 加 一个int在内存中占的位置（+2 就是两个int在内存中占的位置）
    
    
    return;
}


void s4(){
    
    // 接下来简单的介绍几个有关于指针的运算
    
    int num[3] = {1,2,3};
    int *numptr = num;
    
    cout << *numptr << endl; //这是最开始的样子
    
    numptr++;
    cout << "after ++: " << *numptr << endl; // 指针往前进一位
    numptr--;
    cout << "after --: " << *numptr << endl; // 指针向后退一位
    
    numptr+=1; // 跟++一样
    cout << "after +=: " << *numptr << endl; // 指针往前进一位
    
    cout << "目前两个数组相差的数量： " << numptr-num << endl;
    
    // 这个没啥好说的，记住就完了
    
    return;
}

void s5(){
    
    // 我们也可以将指针变量放入函数当中
    // 并且性质跟reference一样，可以在函数当中对值做出改变
    
    int x=2;
    s5_1(&x);
    cout << "这是你刚刚输入的值" << x << endl;
    
    // 除了可以将指针作为变量，也可以将其定义为常量 const
    const int RATES = 2;
    const int *rates=&RATES; // 这种指针只可以指向一个const int，不可以指向int或者其他的
    
    int num = 3;
    int const *numptr = &num; // 这个是一个常量指针，意思是说只可以指向一个地址，不可以改变
    cout << "这是num的地址" << &num <<endl;
    cout << "这也是num的地址"<< numptr << endl; //如果指向别的地址了就会报错，你可以自己试试
    
    const int index = 3;
    const int *const indexptr = &index; // 这个就是把两个综合一下，只能指向一个存储着常量的地址的常量指针
    
    return;
}

void s5_1(int *x){
    
    cout << "输入一个数字： ";
    cin >> *x;
    
    return;
    
}

void s6(){
    
    //动态内存分配（dynamic memory allocation）
    //是很重要也是很复杂的指针的一个部分
    //这个东西是个双刃剑，设计的好的话会大大的降低你的空间复杂度和时间复杂度，设计的不好就会造成内存泄漏（memory leak）
        // 内存泄漏是很麻烦的
        // 假如我们把每次程序结束的清理环节看作是丢垃圾
        // 把我们用过的东西都收集起来一起销毁掉
        // 设计有失误的动态内存分配逻辑就好像是你不小心扔在床底下的零食袋
            // 而且我知道你肯定tmd有很多没扔的
        // 这些垃圾在清理的时候被遗落了，它的地址丢失了，电脑没办法重新找到它
        // 那这个垃圾就一直呆在内存里 直到你有一个办法去清理它
    
    int *numptr = nullptr;
    numptr = new int; // 指令 new 会给这个指针分配一个int类型的内存
    
    cout << *numptr; // 在给它放入任何东西之前，它会显示0
    
    delete numptr; // 最后在结尾把创建的指针内存用 delete指令删除掉
}


void s7(){
    
    // 同样我们也可以构建一个函数它的返回值是一个指针
    
    int *arr = s7_1(3);

    for(int i=0; i<3; i++){
        
        cout << *(arr+i)<< " ";
        
    }
    
    delete arr;
    
    // 这个函数会动态分配一个array
    // 之后把这个array的地址作为返回值存在指针里
    // 换句话讲就是函数在一个地址里存了东西，然后函数外的人提取了地址，再去地址里找东西
    
    return;
}

int *s7_1(int x){
    
    int *y = nullptr;
    if(x==1){return nullptr;}
    y = new int[x];
    for(int i=0; i<x; i++){
        
        *(y+i) = 1;
        
    }
    
    return y;
}



void s8(){
    
    // 当然也有一个很方便的东西可以自动清理分配的动态内存
    // 这个叫 smart pointer
    
    unique_ptr<int> ptr(new int);
    
    *ptr = 99;
    cout << *ptr << endl;
    
    return;
}
