
// 这一章节的主要内容有以下几点：
    // 1. Search
        // linear search
        // binary search
    // 2. Sorting
        // bubble sort
        // Selection sort

#include <iostream>
#include <string>

using namespace std;
int linearSearch(int x[], int n, int value);
int BinarySearch(int x[], int n, int value);
void bubbleSort(int x[], int n);
void selectionSort(int x[], int n);

int main(){
    
    int x[9] = {1,2,3,4,5,6,7,8,9};
    int y[8] = {2,3,5,1,2,12,4,6};
    
    
    cout << linearSearch(x, 9, 6) << endl;
    cout << BinarySearch(x, 9, 6) << endl;
    bubbleSort(y, 8);
    selectionSort(y, 8);
    
    return 0;
}

//线性查找的逻辑最简单，就是一个一个的找。从第一个找，直到你想要的值或者结尾
 // 因此我们编写的逻辑也会比较简单
 // 注：所有被 ### 框起来的都是在编写程序之前构建的伪代码（Pseudocode）

// ##############
// 调取三个不同的变量：需要查找的array，需要找到的值，array的长度
// 创建一个循环，次数为array的长度
// 每次循环都会通过逻辑来判断当前位置上的东西 是否 与要找的值相同
    // 相同：返回位置
    // 不同：接着走
// 当循环走完时都没有找到，那就返回 -1 （在这里-1代表无）

// ##############
int linearSearch(int x[], int n, int value){
    
    for (int i=0; i<n; i++){
        
        if(x[i]==value){
            return i;
        }
        
    }
    
    return -1;
}

//Benefits:
//– Easy algorithm to understand
//– Array can be in any order
//Disadvantages:
//– Inefficient (slow): for array of N elements, examines N/2 elements on average for value in array, N elements for value not in array



// 接下来要做的事binary search，又叫二叉搜索
// 二叉搜索的逻辑是通过判断数字的大小来决定寻找的方向
// 换句话说就是以二进制的方法来进行查找

// ##############
// 调取三个变量： 需要查找的array（x），array的长度（n），要在array中找到的值（index）
// 创建三个int变量：head=0 tail=n mid=n/2
// 创建一个循环：
    // 从array的mid位置开始找起
    // 如果比mid大就把head设置为mid+1，mid设置成（head+tail）/2
    // 如果比mid小就把tail设置为mid-1，mid设置成（head+tail）/2
    // 或者在第三种情况，就是等于的时候，就直接返回当前的位置
// 如果跑完了循环还不行就直接返回 -1
// ##############

int BinarySearch(int x[], int n, int value){
    
    int head = 0;
    int tail = n-1;
    int mid;
    
    while (head<=tail) {
        mid = (head+tail)/2;
        if(value > x[mid]){
            head = mid+1;
        }else if(value <x[mid]){
            tail = mid-1;
        }else{
            return mid;
        }
    }
    
    return -1;
}


// • Benefits:
// – Much more efficient than linear search. For array of N elements, performs at most comparisons
// • Disadvantages:
// – Requires that array elements be sorted

// Bubble sort 的逻辑就是循环来比较两个数字（n,n+1）之间的大小从而整理数组的顺序
// ##############

// 调取两个变量：需要搜索的array（x），array的长度（n）
// 创建两个变量： temp，pos=0
// 创建一个循环，这个循环会在pos等于n+1的时候结束：
    //如果pos上数字大于pos+1位置上的数字
        // 交换这两个数字
        // 并且设置pos=0
    //或者 pos=pos+1

// cout出整个数组
// ##############



void bubbleSort(int x[], int n){
    
    int temp;
    int pos=0;
    
    while(pos != n){
        
        if(x[pos]>x[pos+1]){
            temp = x[pos+1];
            x[pos+1] = x[pos];
            x[pos]=temp;
            pos = 0;
        }else{
            pos++;
        }
        
    }
    
    for(int i = 0; i<n; i++){
        
        cout << x[i] << " ";
        
    }
    cout << endl;
    
    return;
}

// 我的代码跟ppt的有出入，但是逻辑是一样的
// ppt上是通过使用一个swap作为开关进行循环 我是转为用检索的位置

// • Benefit:
// – Easy to understand and implement
// • Disadvantage:
// – Inefficient: slow for large arrays


// Selection Sort 的逻辑是通过分辨当前值在数组中大小的地位来单独的为其分配位置
// 例如：将最小的放在第一位，第二小的其次

// ##############
// 调用两个变量：要sort的array（x），array的长度（n）
// 自行创建两个个变量 temp, min
// 创建一个会运行n次循环：
    // 创建一个会运行n-nowpos次数的循环：
        //检索剩下array中的最小数
    // x[i]上放min
    // nowpos++
//cout 整个sorted array
// ##############

void selectionSort(int x[], int n){
    
    int temp;
    int min;
    
    for (int i=0;i<n;i++){
        min = x[i];
        for(int j=i;j<n;j++){
            
            if(x[j]<min){
                min = x[j];
            }
            
        }
        x[i]=min;
    }
    
    for(int i = 0; i<n; i++){
        
        cout << x[i] << " ";
        
    }
    cout << endl;
    
    return;
}


// ppt上的逻辑比较笨拙，用了太多的变量
// 但好处是可以很清晰的解释出selection sort的逻辑
// 我上面的代码是用了 nest for loop的一个变种
// 也根据selection sort的逻辑写出了更优化的答案

// • Benefit:
// – More efficient than Bubble Sort, since fewer exchanges
// • Disadvantage:
// – May not be as easy as Bubble Sort to understand



// 在ppt的最后简单的介绍了 vector（向量）
// 向量这个类别中有很多好用的function可以很直接的帮助你来达到很多目的
// 但是缺点是 vector 要比 array 占更多的内存
