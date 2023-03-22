
// C string
// C++ 里其实没有string这个类
// 在C++眼里，string其实就是一个char array
// 也就是字符串


#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <string>


using namespace std;

void s1();
void s2();
void s3();
void s4();
void s5();

int main(){
    
    //s1();
    //s2();
    //s3();
    //s4();
    //s5();
}

void s1(){
    
    char a;
    cout << "input any thing: ";
    cin.get(a);
    cout << "The input is ";
    if( isalpha(a) ){
        cout << "a letter" << endl;
    }
    if (isdigit(a)){
        cout << "a number" << endl;
    }
    if (isupper(a)){
        cout << "a upper letter" << endl;
    }
    if (islower(a)){
        cout << "a lower letter" << endl;
    }
    if (isspace(a)){
        cout << "a white space" << endl;
    }
    
    // cctype 里有很多已经定义好了的方法：
        // isalpha(a) 看它是不是字母
        // isdigit(a) 看它是不是数字
        // isupper(a) 看它是不是大写
        // islower(a) 看它是不是小写
        // isspace(a) 看它是不是空格
    
    return;
}

void s2(){
    
    char upa = 'A', loa = 'a';
    cout << tolower(upa) << endl; // 这样打出来的ASCI代码
    cout << toupper(loa) << endl;
    
    upa = tolower(upa);
    loa = toupper(loa);
    
    cout << upa << endl; //只有在把这串代码存进char里之后才会变成字母
    cout << loa << endl;
    
    return;
}


void s3(){
    
    char arr[] = "ok";
    cout << strlen(arr) << endl; // 这个方法会返回你char array的长度
    
    char arr2[] = "yes";
    cout << strcat(arr, arr2) << endl; // 这个方法会把两个array 合并， arr2放在arr后面
    
    strcpy(arr, arr2);
    cout << arr << endl; // 这个方法会把arr2复制给arr1
    
    char arr3[] = "sdhahyesfuckyou";
    cout << strstr(arr3,arr2) << endl; // 他会检索之后得到这个单词之后的东西
    
    return;
}



void s4(){
    
    int a;
    long b;
    double c;

    a = atoi("1234"); // char 转 int
    cout << a << endl;
    b = atol("123"); // char 转 long
    cout << b << endl;
    c = atof("17.89"); // char 转 double
    cout << c << endl;
    
    
    return;
}

void s5(){
    
    string a = "ok"; // 这个没啥好说的，就是定义字符串
    
    string myname("ok"); // 跟上面一样 string y = "ok";
    cout << myname <<endl;
    
    string yourname(myname); // string x = y;
    cout << yourname << endl;
    
    string aname(myname,1); // 只要myname[1]到myname[size]的东西
    cout << aname << endl;
    
    string verb(myname,0,1);
    cout << verb << endl; // 只要myname[0]到myname[1]的东西
    
    string noname('A',5);
    cout << noname << endl; // 5个A
    
    
    return;
}


// 最后ppt结尾有个表格，里面装了一堆c++ string的函数
// 大概的看一下，不用记住 随用随找就行了
