
// 这章节主要内容：
// Abstract Data Type （抽象数据类型）
    // struct
    // pointer struct
    // enumerated



#include <iostream>

using namespace std;

struct student{
    
    int age;
    string name;
    double finalGrade;
    long studentId;
    
};



void s1();
void s2();
void s3();
void s4();
student s4_1();
void s5();
void s6();
void s7();

int main(){
    
    //s1();
    //s2();
    //s3();
    //s4();
    //s5();
    //s6();
    //s7();
    
    return 0;
}



void s1(){
    
    // 抽象数据类型用通俗的话来讲就是由程序员自己设计的一个数据类型
    // 这个数据类型会有自己独特的特性
    // 那系统自带的int 类型来讲，它是c++设计来只存储整数的
    // 除此之外的任何一种数据都不会被它所接受
    // 或者int[] 一个整数的数组
    // 这个数组里会包括存储的数据以及一些功能性函数（例如前面学过的查找长度）
    
    // 抽象数据类型中，程序员可以自行对数据结构进行定义
    // 其中最简单方式就是使用 struct 的方法来构建
    
    struct student{
        
        int age;
        string name;
        double finalGrade;
        long studentId;
        
    };
    // 就像上面一样，你可以设置一个数据类型来存储一个学生的信息
    // 储存他的年纪，名字等等
    // 同时你也可以对里面的每一个成员进行单独的更改
    
    student Bella; // 首先我们可以创建一个学生，将它命名为Bella
    Bella.name = "Bella"; // 我们用 . 来表示读取数据中的某个成员
    Bella.age = 100;
    Bella.finalGrade = 3.5;
    Bella.studentId = 2894169;
    //通过以上的指令，我们创建了一个名字叫Bella，id 为 2894169，期末成绩考了3.5分的一百岁学生
    
    cout << "name: " << Bella.name << " Age: " << Bella.age << endl;
    
    
    // 除了上面那种麻烦的方法，其实还有更简单直接往创建的数据中输入信息的方式
    
    student Christina = { 200 ,"Christina", 2.5, 382692};
    
    cout << "name: " << Christina.name << " Age: " << Christina.age << endl;
    //但是这样个缺点就是一次必须初始化所有的信息，不可以跳过不填
    
    
    return;
}

void s2(){
    
    struct student{
        
        int age;
        string name;
        double finalGrade;
        long studentId;
        
    };
    //除了创建单个的学生，我们还可以创建一个学生array
    
    student stuarr[3];
    stuarr[0].name = "Bella";
    stuarr[1].name = "Christina";
    stuarr[2].name = "Vincent";
    
    for (int i=0; i<3; i++){
        
        cout << stuarr[i].name << endl;
        
    }
    // 这样就把三个学生的信息都放进了一个 student 类型的 array里面
    
    
    
    
    return;
}

void s3(){
    
    
    // 接下来，我们还可以对我们自己设计的数据类型进行一个升级
    // 将一个自定义的数据类型 作为另外一个自定义数据类型的其中一个成员
    
    struct daily{
        
        int wakeUp;
        int lunchTime;
        int sleepTime;
        
    };
    
    struct student{
        
        int age;
        string name;
        double finalGrade;
        long studentId;
        daily newDay;
        
        
    };
    
    // 当然，我们也可以用同样的方法来插入或者读取数据类型中的数据类型中的某一个值
    
    student a;

    a.newDay.wakeUp=11;
    cout <<a.newDay.wakeUp << endl;
    
    
    
    
    return;
}


void s4(){
    
    // 会不会觉得像刚刚那样创建的方法太麻烦
    // 如果数量多了就很不好进行输入了
    // 于是我们也可以通过一个函数来储存数据
    // 依旧以student来举例
    
    
    student Bella = s4_1();
    
    
    cout << "name: " << Bella.name << " Age: " << Bella.age << endl;
    
    // 可以通过这种返回值的方式来更简洁的为数据输入信息
    
}


student s4_1(){
    
    student newStu;
    cout << "写名: ";
    cin >> newStu.name;
    cout << "多大了: ";
    cin >> newStu.age;
    
    return newStu;
}


void s5(){
    
    // 自定义的类型也可以使用指针的方式为他分配内存
    
    student Bella;
    Bella.name = "Bella";
    student *stuptr = nullptr;

    stuptr = &Bella;
    
    
    //  我们可以用两节课前学的方法来读取指针
    
    cout << (*stuptr).name << endl;
    
    // 当然也有另一种方法
    
    cout << stuptr->name << endl;
    
    // 这两种方法的区别在于读取地址的顺序
        // （*stuprt）会首先将地址中的值调取出来，之后再获取当前值里一个名叫 name 的成员
        // stuptr-> 的方法主要是通过运算符 -> 来直接调取地址中的值
    // 两种方法都是可以的，没有太多区别
    // 我反正是爱用第二种 因为打得快一点
    
    return;
}

void s6(){
    
    // union 其实跟struct是很相似的
    // 区别在于
        // union 里所有的成员都使用同一个储存空间
        // union 只可以被定义一次
            // 也就是说 假如我们创建了一个union
            // 当我们想接着创建一个新的object的时候 上一个就会被覆盖
    
    // 这个一般也不咋用 所以不用太明白，想学自己去查查
    
    
    return;
}


void s7(){
    
    // enumerated data type (枚举)
    // 简单来说就是把数据列举成不同的level
    // 例如
        // 天气「晴天，阴天，雨天，刮风，下雪」
    // 这种方法可以更好的将对象进行分类
    
    enum Day{ Monday, Tuesday, Wednesday, Thursday, Friday};
    
    Day workday;
    workday = Wednesday;
    cout << "This is workday: " << workday << endl; // 这样可以输出这一天在list里面的位置
    
    // 其实可以把它想象成一个带有struct 的 array
    // 但是在创建数据的时候就只能调用这个array里有的值
    
    // 这个就会报错
    // workday = ok;
    
    // 当然你也可以直接通过以下这种方法来输入值
    
    workday = static_cast<Day>(3);
    
    // 你也可以给一个普通的数据类型放入 enum 里的值
    
    int x;
    x = Wednesday; // 这样就会给x放入2，因为本身Wednesday在数组里是第二位
    
    cout << "This is x: " << x << endl;
    
    // 通过 enum的方式，可以进行许多逻辑运算
    // 详细的ppt上都有 其实就是用数字来做各种loop 没有太多的定义类的东西需要解释
    
    return;
}


