#include <iostream>
using namespace std;

void update(int *p)
{
    *p = (*p) * 2;
}
void increment(int** p)
{
    ++(**p);
}

int main()
{
    /*
    //1
    int first = 8;
    int second = 18;
    int* ptr = &second;
    *ptr = 9;
    cout<<first<<" "<<second<<endl;

    //2
    int first = 6;
    int* p = &first;
    int* q = p;
    (*q)++;
    cout<<first<<endl;

    //3
    int first = 6;
    int* p = &first;
    cout<<(*p)++<<" "<<first<<endl;

    //4
    int* p = 0;
    int first = 110;
    *p = first;
    cout<<*p<<endl;   // Error!!

    //5
    int first = 6;
    int second = 11;
    int* third = &second;
    first = *third;
    *third = *third + 2;
    cout<<first<<" "<<second<<endl;

    //6
    float f = 12.5;
    float p = 21.5;
    float* ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout<<*ptr<<" "<<f<<" "<<p<<endl;

    //7
    int arr[5];
    int* ptr;
    cout<<sizeof(arr)<<" "<<sizeof(ptr)<<endl;

    //8
    int arr[] = {11,21,13,14};
    cout<<*(arr)<<" "<<*(arr+1)<<endl;

    //9
    int arr[6] = {11,21,31};
    int* p = arr;
    cout<<p[2]<<endl;

    //10
    int arr[5] = {11,21,31,41,51};
    int* p = arr++;
    cout<<*p<<endl;  //  Error [ arr value can not be changed. ]

    //11
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout<<*ptr<<endl;

    //12
    char ch[] = "abcde";
    char* p = &ch[0];
    cout<<ch[0]<<" "<<p[0]<<endl;
    p++;
    cout<<p<<endl;
    
    // 13
    int i = 10;
    update(&i);
    cout << i << endl;
    
    //14
    int first = 110;
    int* p = &first;
    int** q = &p;
    int second = (**q)++ + 9;
    cout<<first<<" "<<second<<endl;
    
    //15
    int first = 100;
    int*p = &first;
    int** q = &p;
    int second = ++(**q);
    int* r = *q;
    ++(*r);
    cout<<first<<" "<<second<<endl;
    */

    //16
    int num=110;
    int* ptr = &num;
    increment(&ptr);
    cout<<num<<endl;

    return 0;
}