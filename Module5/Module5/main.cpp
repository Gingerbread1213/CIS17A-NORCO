

// file operation在c++中是非常重要的
// 你可以通过用fstream中的各种功能来替代终端，或者储存数据
// 这一章节主要讲了各种fstream自带的函数以及iomanip的使用方法


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void s1();
void s2();
void s3();
bool s3_1(fstream &x, string name);
void s4();
void s5();
void s6();

int main(){
    
    //s1();
    //s2();
    //s3();
    //s4();
    //s5();
    s6();
    
    return 0;
}


void s1(){
    
    // 首先介绍三种方式
    // ifstream
    // ofstream
    // fstream
    
    ifstream infile1("s1_1.txt"); //首先，用ifstream来打开我们已经编辑好的文档
    int x;
    infile1 >> x; // 将文档中的字输入进我们准备好的容器里
    cout << x << endl; //再通过c++的方式读取出来
    infile1.close(); // 最后要记得关闭
    
    ofstream outfile1("s1_3.txt"); //用ofstream的方法啦打开文档
    int y = 3;
    outfile1 << y; // 将我们已经准备好的值存进去
    outfile1.close(); // 关闭文件
    
    // 结果可以去 s1_3.txt 里面查看
    
    
    // 与前两种类似，只不过这一种需要在最后标注要存储的类别
    fstream infile2("s1_1.txt", ios::in);
    fstream outfile("s1_2.txt", ios::out);
    
    int num;
    for(int i=0; i<10; i++){
        infile2 >> num;
        outfile << num;
    }
    
    infile2.close();
    outfile.close();
    
    
    // 除了in 和 out以外，ppt中还介绍了好多别的方法
    // 用于针对存储不同类型的文件或者数据
    
    
    // 除此以外你还可以通过以下的方法运用fstream
    
    ifstream outfile4("s1_1.txt");
    int alpha = 0;
    while(outfile4){ //只要我还在读取，就会进行循环
        outfile4 >> alpha;
        cout << alpha << " ";
    }
    
    
    return;
}


void s2(){
    
    setw(2);
    setprecision(2);
    
    //这个不讲了啊，上学期都学过的
    
    return;
}


void s3(){
    
    
    // 同样 fstream 也可以被应用在函数当中
    // 最简单的就是创建一个像ppt中一样检测file有没有被成功打开的函数
    fstream newData;
    cout << s3_1(newData,"newData.txt") << endl; //不会成功，因为没有这个file
    cout << s3_1(newData,"s1_3.txt") << endl; // 会成功，因为有这个file
    
    newData.close();
    
    // 然后在ppt 12.4 里面有一堆乱七八糟的方法可以用来检测读取文件的情况
    // 大概的看一下，等到要用的时候现学就行了
    
}

bool s3_1(fstream &x, string name){
    
    x.open(name,ios::in);
    if(x.fail()){
        return false;
    }else{
        return true;
    }
    
    return false;
}



void s4(){
   
    
    // 这部分接着讲一些c++ file的一些方法
    
    ifstream infile("s4_1.txt");
    
    string name;
    getline(infile, name);
    cout << name << endl;
    // 这个其实跟getline（cin，name）一样，只不过这是用ifstream的方式把文档里的内容输入进去
    // 而不是让用户用手在terminal里面输入
    
    char letter;
    infile.get(letter); // 这个方法会读取下标处的第一个字母
    cout << letter << endl;
    infile.close();
    
    ofstream outfile("s4_2.txt");
    outfile.put(97);
    outfile.close();
    
    return;
}



void s5(){
    
    // Binary files
    // 也就是说这里面所有的内容都是由二进制的方法写出来的 （1/0）
    // 这种文件是没法用正常的方法存储和读取的
    
    fstream outfile;
    fstream infile;
    int num = 12;
    int newnum;
    outfile.open("s5_1.dat",ios::out|ios::binary); //创建一个file然后将读取类型设为binary
    outfile.write(reinterpret_cast<char *>(&num), sizeof(num)); //将num的地址以二进制的方式写进这个dat file里面
    outfile.close();
    
    infile.open("s5_1.dat",ios::in|ios::binary); // 重新打开这个 dat 文件
    infile.read(reinterpret_cast<char *>(&newnum), sizeof(newnum)); // 将里面存储的值以二进制的方式读取出来 放进 newnum 中
    infile.close();
    
    
    cout << newnum << endl;
    
    
    // 这种方法比较复杂，但是有一个好处就是在转换格式的时候会更加方便
    // 详细的原因说了也记不住 有兴趣就自己查一下
    
    return;
}


void s6(){
    
    //接下来是一个下标指令
    // 首先科普一下啥叫下标
        // 你每次打字的时候是不是都会有一个竖杠 然后你打的字就会出现在这个竖杠的后面
        // 这个竖杠的位置就是你下的标
        // c++ 在读取文件的时候也会根据文档的内容下标
    
    ifstream infile("s6_1.txt");
    
    int num;
    
    infile.seekg(5L,ios::beg); //这个指令会在你打开文档的第五个 byte 处下标
    infile >> num; // 之后存储你从下标后的东西
    long int position;
    position = infile.tellg();
    cout << "this is the current position: " << position << endl;
    cout << "this is the number that will be saved: " << num << endl;
    infile.close();

    
    ofstream outfile("s6_1.txt");
    infile.seekg(10L,ios::beg);//这个指令会在你打开文档的第十个 byte 处下标
    outfile << num; // 把你刚刚的数字放进去
    
    outfile.close();

    
    
    return;
}


// 终于nmd写完了，这一节真是nmd又臭又长























