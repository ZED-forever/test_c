#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>




// //不同枚举不能使用同一个变量名
// enum Color{
//     RED,
//     GREEN,
//     BLUE
// };
// enum Color2{
//     YELLOW,
//     BLUE,//报错  冲突了
//     GREEN//报错
// };
// int main(){
//     enum Color a = RED;
//     enum Color2 b = BLUE;
//     printf("%d %d %d \n",RED,GREEN,BLUE);
//     printf("%d\n",a);
//     printf("%d\n",b);
//     return 0;
// }

// int my_strncmp(char* str1,char* str2,int count){
//     while(count &&(*str1 == *str2)){
//         if(*str1 == '\0'){
//             return 0;
//         }
//         str1++;
//         str2++;
//         count--;
//     }
//     if(*str1 == *str2){
//         return 0;
//     }else if(*str1 > *str2){
//         return 1;
//     }else{
//         return -1;
//     }
// }
// int main(){
//     char* arr1 = "abcdef";
//     char* arr2 = "abcdef";
//     printf("ret = %d\n",my_strncmp(arr1,arr2,6));
//     return 0;
// }


// //自己实现一个offsetof的宏
// #define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
// //(struct_name*)0   把0强制类型转换为结构体的指针，这样结构体的地址可以看作从0开始计算
// //((struct_name*)0)->member_name   取出结构体成员
// //&(((struct_name*)0)->member_name) 取出结构体成员的地址（这个就是相对0的字节数）
// //(int)&(((struct_name*)0)->member_name)   转换为int
// struct S2
// {
// 	char c1;//0
// 	int i;//4
// 	char c2;//8
// };
// int main(){
//     printf("%d\n",OFFSETOF(struct S2,c1));
//     printf("%d\n",OFFSETOF(struct S2,i));
//     printf("%d\n",OFFSETOF(struct S2,c2));
//     return 0;
// }



// //带副作用的宏参数
// #define MAX(a, b) ( (a) > (b) ? (a) : (b) ) //三目操作符
// int main(){
//     int x = 10;
//     int y = 11;
//     int max = MAX(x++, y++);
//     printf("x=%d y=%d max=%d\n", x, y, max);//输出的结果是什么？// 11  13  12
//     //此处的x自加了一次，y自加了两次，但是第二次自加是先返回再自加，max = 12
//     return 0;
// }

// //##的使用 连接两边的符号，并组成新的标识符
// #define CAT(x,y) x##y
// int main(){
//     int ZhangSan = 54;
//     printf("%d\n",CAT(Zhang,San));//54
//     return 0;
// }



// //宏的使用， 注意要加括号，防止计算的顺序变化
// #define SQUARE( x ) x * x
// int main(){
//     int ret = SQUARE( 5 );  //int ret = 5 * 5;//25
//     printf("%d\n",ret);
//     ret = SQUARE( 5+1 );  //int ret = 5+1*5+1; // 11
//     printf("%d\n",ret);
//     ret = 5*SQUARE( 5+1 );//int ret = 5*5+1*5+1; //31
//     printf("%d\n",ret);
//     return 0;
// }



// //不使用柔性数组，在结构体中实现一个可变的数组
// struct S{
//     int a;
//     int* arr;//指针
// };
// int main(){
//     struct S* ps = (struct S*)malloc(sizeof(struct S));//这里的ps初始化可以不用malloc
//     //如果使用struct S ps = {0,NULL};初始化也是可以的，但是这样就是结构体在栈区
//     //结构体中的可变数组的内容在堆区
//     ps->arr = (int*)malloc(5 * sizeof(int));//在这里开辟可变的数组，并将指针赋给结构体中的成员
//     int i =0;
//     for(i=0;i<5;i++){
//         ps->arr[i] = i;
//     }
//     for(i=0;i<5;i++){
//         printf("%d ",ps->arr[i]);
//     }
//     printf("\n");
//     int* pi = (int*)malloc(10 * sizeof(int));
//     if(pi!=NULL){
//         ps->arr = pi;
//     }
//     for(i=0;i<10;i++){
//         ps->arr[i] = i;
//     }
//     for(i=0;i<10;i++){
//         printf("%d ",ps->arr[i]);
//     }
//     printf("\n");
//     free(ps->arr);
//     ps->arr = NULL;
//     free(ps);
//     ps=NULL;
//     return 0;
// }


// //柔性数组的定义和使用
// struct S{
//     int a;
//     int arr[];//未知大小-柔性数组成员-数组是可以调整的  也可以写作int arr[0]
// };
// int main(){
//     struct S s;
//     printf("%d\n",sizeof(s));//4
//     //柔性数组的使用
//     struct S* ps = (struct S*)malloc(sizeof(struct S)+5*sizeof(int));
//     ps->a = 100;
//     int i =0;
//     for(i=0;i<5;i++){
//         ps->arr[i] = i;
//     }
//     for(i=0;i<6;i++){
//         printf("%d\n",*((int*)ps+i));
//     }
//     struct S* ps2 = realloc(ps,44);  //通过realloc调整数组大小
//     if(ps2 != NULL){
//         ps = ps2;
//     }
//     for(i=0;i<10;i++){
//         ps->arr[i] = i;
//     }
//     for(i=0;i<10;i++){
//         printf("%d ",ps->arr[i]);
//     }
//     free(ps);
//     ps =NULL;
//     return 0;
// }



// //笔试题1
// void GetMemory(char *p)
// {
// 	p = (char *)malloc(100);//这里不仅开辟了空间，而且函数调用过后临时变量p会被销毁
//     //从而根本找不到这个空间了
// }
// void Test(void)
// {
// 	char *str = NULL;
// 	GetMemory(str);//注意这里是传值，因为需要修改str，并且直接传入了str。应该传入&str
// 	strcpy(str, "hello world");
// 	printf(str);//这个写法是可以的printf("abcdef");
// }
// int main(){
//     Test();
//     return 0;
// }



// //联合成员的大小
// union Un{
//     int a;//4字节  对齐数4
//     char arr[5];//5字节  对齐数1
// };
// int main(){
//     union Un u;
//     printf("%d\n",sizeof(u));//8
//     return 0;
// }



// //联合体用于确定系统大小端
// int check_sys(){
//     union Un{
//         int i;
//         char c;
//     }u;
//     u.i = 1;
//     return u.c;
// }
// int main(){
//     int ret = check_sys();
//     if(ret ==1){
//         printf("小端\n");
//     }else{
//         printf("大端\n");
//     }
//     return 0;
// }


// //联合（共用体）
// union Un
// {
//  int i;
//  char c;
// };
// int main(){
//     union Un un;
//     // 下面输出的结果是一样的吗？
//     printf("%d\n", sizeof(un));//4
//     printf("%p\n", &un);//000000000061FE1C
//     printf("%p\n", &(un.i));//000000000061FE1C
//     printf("%p\n", &(un.c));//000000000061FE1C
//     //下面输出的结果是什么？
//     un.i = 0x11223344;
//     un.c = 0x55;
//     printf("i = %x\n", un.i);//i = 11223355
//     return 0 ;
// }


// //枚举
// enum Day//星期
// {
//     //枚举的可能取值   常量
// 	Mon,
// 	Tues,
// 	Wed,
// 	Thur,
// 	Fri,
// 	Sat,
// 	Sun
// };
// enum Sex//性别
// {
//     //可以赋初始值
// 	MALE = 2,
// 	FEMALE = 4,
// 	SECRET = 8
// };
// enum Color//颜色
// {
// 	RED,//0
// 	GREEN,//1
// 	BLUE//2
// };
// int main(){
//     enum Sex s = MALE;
//     printf("%d\n",s);//2
//     printf("%d %d %d\n",RED,GREEN,BLUE);//0 1 2
//     return 0;
// }


// //位段
// struct A
// {
// 	int _a:2;//冒号后面的数字是指需要的bit空间
// 	int _b:5;
// 	int _c:10;
// 	int _d:30;
// };
// int main(){
//     struct A a = {2,15,255,1023};
//     //0111111110111110
//     printf("%d\n", sizeof(struct A));//8
//     return 0;
// }



// //offsetof查看成员在结构体中的偏移量
// #include <stddef.h>
// struct S2
// {
// 	char c1;//0
// 	int i;//4
// 	char c2;//8
// };
// int main(){
//     printf("%d\n",offsetof(struct S2,c1));
//     printf("%d\n",offsetof(struct S2,i));
//     printf("%d\n",offsetof(struct S2,c2));
// }


// //设置默认对齐数
// #pragma pack(8)//设置默认对齐数为8
// struct S1
// {
// 	char c1;
// 	int i;
// 	char c2;
// };
// #pragma pack()//取消设置的默认对齐数，还原为默认
// #pragma pack(1)//设置默认对齐数为1
// struct S2
// {
// 	char c1;
// 	int i;
// 	char c2;
// };
// #pragma pack()//取消设置的默认对齐数，还原为默认
// int main()
// {
//     //输出的结果是什么？
//     printf("%d\n", sizeof(struct S1));
//     printf("%d\n", sizeof(struct S2));
// 	return 0;
// }


// //结构体内存对齐
// struct S1{
// 	char c1;
//     int a;
//     char c2;
// };
// struct S2{
//     char c1;
//     char c2;
//     int a;
// };
// int main(){
//     struct S1 s1 = {0};
//     struct S2 s2 = {0};
//     printf("%d\n",sizeof(s1));//12
//     printf("%d\n",sizeof(s2));//8
//     return 0;
// }



// //自己实现memmove
// void* my_memmove(void* dest,void* src,size_t num){
//     void* temp = dest;
//     char* tmp1 = (char*)dest;
//     char* tmp2 = (char*)src;
//     if(dest < src){
//         //这种情况从前向后拷贝
//         while(num--){
//             *tmp1 = *tmp2;
//             tmp1++;
//             tmp2++;
//             // *(char*)dest = *(char*)src;
//             // ++(char*)dest;//这种写法在我的环境中会报错，显示左边的值不能修改。
//             // //应该还是把dest和src看作了void*
//             // ++(char*)src;
//         }
//     }else{
//         //这种情况从后往前拷贝
//         while(num--){
//             *(tmp1+num) = *(tmp2+num);
//             // *((char*) dest+num) = *((char*)src+num);
//         }
//     }
//     return temp;
// }
// int main(){
//     int arr1[] ={1,2,3,4,5,6,7,8,9};
//     my_memmove(arr1+2,arr1,20);

//     return 0;
// }


// //memcpy的使用
// struct {
//     char name[40];
//     int age;
// } person, person_copy;
// int main ()
// {
//     char myname[] = "Pierre de Fermat";
//     /* using memcpy to copy string: */
//     memcpy ( person.name, myname, strlen(myname)+1 );
//     person.age = 46;
//     /* using memcpy to copy structure: */
//     memcpy ( &person_copy, &person, sizeof(person) );
//     printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );
//     return 0;
// }



// //strerror的使用
// #include <errno.h>
// int main ()
// {
//     FILE * pFile;
//     pFile = fopen ("unexist.ent","r");
//     if (pFile == NULL){
//         //strerror(errno)正确写法
//         printf ("Error opening file unexist.ent: %s\n",strerror(errno));
//     }else{
//         printf("open file success\n");
//     }
//     //errno: Last error number
//     return 0;
// }

//strtol的使用
// int main()
// {
//     char *p = "zhangpengwei@bitedu.tech";
//     const char* sep = ".@";
//     char arr[30];
//     char *str = NULL;
//     strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
//     for(str=strtok(arr, sep); str != NULL; str=strtok(NULL, sep))
//     {
//         printf("%s\n", str);
//     }
// }


// //自己写的strstr
// char* my_strstr(const char* s1,const char* s2){
//     assert(s1 != NULL);
//     assert(s2 != NULL);
//     char* tmp1 = (char*)s1;
//     char* tmp2 = (char*)s2;
//     //排除空字符串
//     if(*tmp2 == '\0'){
//         return tmp1;
//     }
//     while(*tmp1){
//         //这里是关键，tmp1和tmp2分别记录当前的s1,s2起始点
//         //不会受到后面子循环中指针加减的影响
//         s2 = tmp2;
//         s1 = tmp1;
//         //这里先处理找到了的情况，如果全部找到了就直接返回地址
//         //如果没找到就把tmp1++，找下一个地址的
//         while((*s1 != '\0')&&(*s2 != '\0')&&(*s1 == *s2)){
//             s1++;
//             s2++;
//         }
//         if(*s2 == '\0'){
//             return tmp1;//找到了的情况
//         }
//         tmp1++;
//     }
//     return NULL;//找不到的情况
// }
// int main(){
//     const char* s1 = "abbcdef";
//     const char* s2 = "bcd";
//     char* ret = my_strstr(s1,s2);
//     if(ret == NULL){
//         printf("子串不存在！\n");
//     }else{
//         printf("%s\n",ret);
//     }
//     return 0;
// }


// int my_strcmp(char* str1,char* str2){
//     while(*str1 == *str2){
//         if(*str1 =='\0'){
//             return 0;
//         }
//         str1++;
//         str2++;
//     }
//     if(*str1 > *str2){
//         return 1;
//     }else{
//         return -1;
//     }
// }
// int main(){
//     char a[] = "fff";
//     char b[] = "abcdef";
//     int ret = my_strcmp(b,a);
//     printf("%d\n",ret);

//     return 0;    
// }
// //strcmp函数测试
// // 第一个字符串大于第二个字符串，则返回大于0的数字//这个数字不一定是1
// // 第一个字符串等于第二个字符串，则返回0
// // 第一个字符串小于第二个字符串，则返回小于0的数字
// int main(){
//     char a[] = "fff";
//     char b[] = "abcdef";
//     int ret = strcmp(a,b);
//     printf("%d\n",ret);

//     return 0;
// }



// //自己写strcat
// char* my_strcat(char* dest,const char* src){//const防止修改src字符串
//     assert(dest !=NULL);  //判断空指针
//     assert(src);
//     char* tmp = dest;
//     while(*dest){ 
//         dest++;
//     }
//     while(*dest++=*src++){//简化写法
//         ;
//     }
//     return tmp;
// }
// int main(){
//     char arr1[20] = "hello ";
//     char arr2[] = "world";
//     my_strcat(arr1,arr2);
//     printf("%s\n",arr1);
//     return 0;
// }



// //杨氏矩阵，矩阵每一行从左到右递增，矩阵从上到下递增
// //请编写一个程序在杨氏矩阵中查找一个数是否存在
// //要求时间复杂度小于o(N)
// //思路：每次取右上角的数字x与待查找的数字k相比。如果x大，则排除所在列，如果x小则排除所在行

// void findnum(int arr[3][3],int k,int row,int col,int res[3]){
//     int x = 0;
//     int y = col-1;
//     while(x<=row-1 && y>=0){
//         if(arr[x][y]>k){
//             y--;
//         }else if(arr[x][y]<k){
//             x++;
//         }else{
//             res[0] = 1;
//             res[1] = x+1;
//             res[2] = y+1; 
//             break;
//         }
//     }
// }
// int main(){
//     int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//     int k = 7;//待查找的数
//     int res[3] = {0};
//     findnum(arr,k,3,3,res);//传入数组，待查找的数，行数和列数
//     if(*res == 1){
//         printf("找到了！行数=%d,列数=%d\n",*(res+1),*(res+2));//我这里指针返回列表，不知道会不会没有了
//     }else{
//         printf("没找到！\n");
//     }
//     return 0;
// }


// //字符串旋转，把左边的指定个数的字符移动到右边，同时字符顺序不变
// //abcdef   旋转两个字符   cdefab  暴力交换
// void left_move(char* s,int k){
//     int sz = strlen(s);
//     int i = 0;
//     for(i=0;i<k;i++){
//         int j = 0;
//         char tmp = *s;
//         for(j=0;j<sz-1;j++){
//             *(s+j) = *(s+j+1);
//         }
//         *(s+sz-1) = tmp;
//     }
// }
// //三次交换法
// //abcedf
// //bafdec  交换左边，交换右边
// //cedfab  整个交换
// void reverse(char* left,char* right){
//     while(left<right){
//         char tmp = *left;
//         *left = *right;
//         *right = tmp;
//         left++;
//         right--;
//     }
// }
// void left_move(char* s,int k){
//     int sz = strlen(s);
//     reverse(s,s+k-1);
//     reverse(s+k,s+sz-1);
//     reverse(s,s+sz-1);
// }
// // 比较两个字符串是不是交换相等，穷举法
// int is_left_move(char* s1,char* s2){
//     int sz = strlen(s1);
//     int i=0;
//     for(i=0;i<sz;i++){
//         left_move(s1,1);//这里每次交换后都会改变s1，所以每次只移动一次
//         int ret = strcmp(s1,s2);//strcmp比较两个字符串，相同则为0
//         if(ret ==0){
//             return 1;
//         }
//     }
//     return 0;
// }
// //比较两个字符串是不是交换相等，增加字符后对比
// //abcdef 和  cdefab相比，可以把abcedfb变成abcedfabcedf这样所有可能的旋转字符串都是新字符串的子串
// //strcat可以把两个字符串合并  strcat(arr1,arr2)  arr1后面增加了arr2的内容，注意：arr1的大小一定要足够
// //注意：使用strcat(arr1,arr1)会崩溃，因为在追加的时候也会修改arr1中的内容，从而'\0'被修改，不能停止了。
// //可以使用strncat(arr1,arr1,count)这个count就是用来判断什么时候停止的
// int is_left_move(char* s1,char* s2){
//     int sz1 = strlen(s1);
//     int sz2 = strlen(s2);
//     if(sz1 != sz2){//防止找到bcdef这种一段的字符串
//         return 0;
//     }
//     strncat(s1,s1,sz1);
//     char* ret = strstr(s1,s2);
//     if(ret==NULL){
//         return 0;
//     }else{
//         return 1;
//     }
// }
// int main(){
//     char arr1[] = "abcdef";
//     char arr2[] = "cdefab";
//     left_move(arr1,5); 
//     printf("%s\n",arr1);
//     int ret = is_left_move(arr1,arr2);
//     if (ret == 1)
//     {
//         printf("Yes\n");
//     }else{
//         printf("No\n");
//     }
    
//     return 0;
// }



// //喝汽水，计算汽水数量
// //1块钱1瓶，2个空瓶换一个新的，总共喝多少瓶
// int main(){
//     int total = 0;
//     int money = 0;
//     int empty = 0;
//     scanf("%d",&money);
//     total = money;
//     empty = money;
//     while(empty>=2){
//         total += empty / 2;
//         empty = empty / 2 + empty % 2;
//     }
//     printf("total = %d\n",total);
//     return 0;
// }


// int main(){
//     char arr[] = "hello world!";
//     char b = '0';
//     int a = strlen(arr);
//     printf("%d\n",a);//strlen可以计算空格
//     printf("%c\n",b);//空格ascii码不是0
//     printf("%d\n",b);//字符0的ascii码不是0
//     return 0;
// }



// int main(){
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     int* a = &arr[1];
//     int* b = &arr[2];
//     printf("%d\n",a);
//     printf("%d\n",b);
//     printf("%d\n",a-b);
//     return 0;
// }



// int main()
// {
//     char *c[] = {"ENTER","NEW","POINT","FIRST"};//c是指针数组，元素类型是char*
//     char**cp[] = {c+3,c+2,c+1,c};//c+1相当于指针数组的首元素地址，类型是char**，每次增加一个char*
//     char***cpp = cp;
//     printf("%s\n", **++cpp);//POINT  cpp指向cp的首元素，++cp后指向cp第二个元素，然后两次解引用得到char*
//     //得到c+2指向的字符指针   注意此时的cpp指向cp第二个元素
//     printf("%s\n", *--*++cpp+3);//ER  *++cpp得到c+1，即指向"NEW"的字符指针的指针，--*++cpp得到指向"ENTER"的字符指针的指针
//     //此时的cp第三个元素不再是c+1而是c，虽然对后面的计算没有影响
//     //*--*++cpp得到"ENTER"首元素的指针char*，+3相当于往后3个char的位置，指向字符"ER"的首元素地址
//     printf("%s\n", *cpp[-2]+3);//ST   此时的cpp指向cp第三个元素，cpp[-2]相当于*(cpp-2)，即c+3，类型为char**
//     //*cpp[-2]得到"FIRST"首元素的指针char*，*cpp[-2]+3得到"ST"首元素的地址
//     printf("%s\n", cpp[-1][-1]+1);//EW  此时的cpp指向cp第三个元素，cpp[-1][-1]相当于*(*(cpp-1)-1)因此得到c+2指向的"POINT"
//     //然后还要减少一个char*，得到"NEW"的首元素地址的指针，解引用得到"NEW"的首元素地址
//     //cpp[-1][-1]+1得到"EW"的首元素地址
//     return 0;
// }


// int main()
// {
//     char *a[] = {"work","at","alibaba"};//这是一个字符指针数组，每个元素都是char*类型的指针
//     char**pa = a;//pa是一个char*的指针，指向a中的第一个元素
//     pa++;//pa++相当于增加一个char*的大小（指针类型关系到指针的+-大小）
//     printf("%s\n", *pa);//at
//     return 0;
// }


// int main()
// {
//     int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//     int *ptr1 = (int *)(&aa + 1);//二维数组的地址+1,越界了,强制转换成int* 后面-1就是会退一个int的大小
//     //也就是二维数组最后一个一维数组的最后一个元素的地址
//     int *ptr2 = (int *)(*(aa + 1)); //aa + 1得到第二个一维数组的地址,然后*(aa + 1)解引用相当于数组名,相当于首元素地址
//     //然后再进行转换得到第二个一维数组首元素的地址
//     printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10,5
//     return 0;
// }


// int main(){
//     int arr[4] = {1,2,3,4};
//     int (*p)[4] = arr;
//     printf("%d\n",(*p)[3]);//数组指针的使用方式
//     return 0;
// }


// int main()
// {
//     int a[5][5];
//     int(*p)[4];
//     p = a;
//     printf( "%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);FFFFFFFFFFFFFFFC,-4
//     return 0;
// }



// int main()
// {
//     int a[3][2] = { (0, 1), (2, 3), (4, 5) };//小括号里面是表达式 
//     // 之前说过，逗号表示不断执行，然后把最后一个表达式执行的结果返回
//     int b[3][2] = { {0, 1}, {2, 3}, {4, 5} };//这两个不同
// 	int *p1;
// 	p1 = a[0];//a[0]表示第一个一维数组, p1 = a[0]表示一维数组的首元素地址(因为不是sizeof(arr)或者&arr的形式)
// 	printf( "%d\n", p1[0]); // 1
//     int *p2;
// 	p2 = b[0];
// 	printf( "%d\n", p2[0]);//0
// 	return 0;
// }


// int main()
// {
//     int a[4] = { 1, 2, 3, 4 };
//     int *ptr1 = (int *)(&a + 1);
//     int *ptr2 = (int *)((int)a + 1);//首先int(a)将首元素地址转化成了int，然后+1。
//     //(int *)强制类型转换后，相当于是首元素后面一个字节的地址，而不是一个int后的地址。
//     //int类型在内存中以小端存储类似 01 00 00 00  02 00 00 00  03 00 00 00 00  04 00 00 00
//     //现在得到的就是   00 00 00 02   //*pt2解引用得到   02 00 00 00  //%x是16进制(4bit)
//     //0x02000000  打印的时候不打印0x 和最前面的0  ，结果就是 2000000
//     printf( "%x,%x", ptr1[-1], *ptr2);//4,2000000
//     return 0;
// }


// int main(){
//     printf("%d\n",sizeof(int));
//     printf("%d\n",sizeof(short));
//     printf("%d\n",sizeof(long));
//     printf("%d\n",sizeof(long long));
//     printf("%d\n",sizeof(float));
//     printf("%d\n",sizeof(double));
//     return 0;
// }



// //由于还没学习结构体，这里告知结构体的大小是20个字节
// struct Test
// {
//     int Num;
//     char *pcName;
//     short sDate;
//     char cha[2];
//     short sBa[4];
// }*p;
// //假设p 的值为0x100000。 如下表表达式的值分别为多少？
// //已知，结构体Test类型的变量大小是20个字节  //我的电脑里面是32字节
// int main()
// {
//     int a =10;
//     p = (struct Test*)0x100000;
//     unsigned long b = (unsigned long)p;
//     printf("%p\n", p + 0x1);//00000000 00100020  教程里面是00100014
//     //虽然我电脑里面的指针是8字节，long是4字节，但是好像没有影响，可能是小端存储的原因
//     printf("%p\n", (unsigned long)p + 0x1);//00000000 00100001教程里面是00100001
//     printf("%p\n", (unsigned int*)p + 0x1);//00000000 00100004教程里面是00100004
//     return 0;
// }


// int main()
// {
//     int a[5] = { 1, 2, 3, 4, 5 };
//     int *ptr = (int *)(&a + 1);
//     printf( "%d,%d", *(a + 1), *(ptr - 1));
//     return 0;
// }



// int main(){
//     //二维数组和指针笔试题
//     int a[3][4] = {0};
//     printf("%d\n",sizeof(a));//12*4 = 48
//     printf("%d\n",sizeof(a[0][0]));//4
//     printf("%d\n",sizeof(a[0]));//16  a第一个元素，是一个一维数组，相当于一维数组的数组名
//     printf("%d\n",sizeof(a[0]+1));//8  a第一个元素 a[0]表示一维数组的第一个元素地址
//     // a[0]+1表示一维数组a[0]的第二个元素的地址
//     printf("%d\n",sizeof(*(a[0]+1)));//4 注意：相当于*(&a[0][1])
//     printf("%d\n",sizeof(a+1));//8  a+1相当于 &a[0]+1 是第二个一维数组的地址
//     printf("%d\n",sizeof(*(a+1)));//16  对第二个一维数组解引用后，又相当于*(&a[1])==a[1]
//     printf("%d\n",sizeof(&a[0]+1));//8  第二个一维数组的地址
//     printf("%d\n",sizeof(*(&a[0]+1)));//16
//     printf("%d\n",sizeof(*a));//16  第一个一维数组的地址解引用
//     printf("%d\n",sizeof(a[3]));//16注意：越界了，但是sizeof不会计算，因此可以通过
//     return 0;
// }


// int main(){
//    // 字符数组和指针笔试题
    // char arr[] = {'a','b','c','d','e','f'};
    // printf("%d\n", sizeof(arr));  // 6 数组的大小，6*1 = 6字节
    // printf("%d\n", sizeof(arr+0));//8  首元素地址大小
    // printf("%d\n", sizeof(*arr));//1
    // printf("%d\n", sizeof(arr[1]));//1
    // printf("%d\n", sizeof(&arr));//8
    // printf("%d\n", sizeof(&arr+1));//8
    // printf("%d\n", sizeof(&arr[0]+1));//8
    // printf("%d\n", strlen(arr));//随机数
    // printf("%d\n", strlen(arr+0));//随机数
    // // printf("%d\n", strlen(*arr));//报错
    // // printf("%d\n", strlen(arr[1]));//报错
    // printf("%d\n", strlen(&arr));//随机数
    // printf("%d\n", strlen(&arr+1));//随机数
    // printf("%d\n", strlen(&arr[0]+1));//随机数
    // char arr[] = "abcdef";
    // printf("%d\n", sizeof(arr));//7
    // printf("%d\n", sizeof(arr+0));//8
    // printf("%d\n", sizeof(*arr));//1
    // printf("%d\n", sizeof(arr[1]));//1
    // printf("%d\n", sizeof(&arr));//8
    // printf("%d\n", sizeof(&arr+1));//8
    // printf("%d\n", sizeof(&arr[0]+1));//8
    // printf("%d\n", strlen(arr));//6
    // printf("%d\n", strlen(arr+0));//6
    // // printf("%d\n", strlen(*arr));//报错
    // // printf("%d\n", strlen(arr[1]));//报错
    // printf("%d\n", strlen(&arr));//6
    // printf("%d\n", strlen(&arr+1));//随机数
    // printf("%d\n", strlen(&arr[0]+1));//5
    // char *p = "abcdef";
    // printf("%d\n", sizeof(p));//8
    // printf("%d\n", sizeof(p+1));//8
    // printf("%d\n", sizeof(*p));//1
    // printf("%d\n", sizeof(p[0]));//1
    // printf("%d\n", sizeof(&p));//8
    // printf("%d\n", sizeof(&p+1));//8
    // printf("%d\n", sizeof(&p[0]+1));//8
    // printf("%d\n", strlen(p));//6
    // printf("%d\n", strlen(p+1));//5
    // // printf("%d\n", strlen(*p));//报错
    // // printf("%d\n", strlen(p[0]));//报错
    // printf("%d\n", strlen(&p));//随机数
    // printf("%d\n", strlen(&p+1));//随机数
    // printf("%d\n", strlen(&p[0]+1));//5
//     return 0;
// }


// int main(){
//     //一维数组和指针笔试题
//     int a[] = {1,2,3,4};
//     printf("%d\n",sizeof(a));	// 4*4=16
//     printf("%d\n",sizeof(a+0)); //注意这个结果不是16，而是8。sizeof(a)
//                                 //因为a+0不再表示一个数组，而是首元素地址，不完全等价于sizeof(a)
//                                 //
//     printf("%d\n",sizeof(*a));  //4  数组名表示首元素地址。*a表示首元素，是一个int。4个字节
//     printf("%d\n",sizeof(a+1));	//8  第二个元素的地址。	
//     printf("%d\n",sizeof(a[1]));//4	 第二个元素的大小
//     printf("%d\n",sizeof(&a));  //8  &a表示数组的地址
//     printf("%d\n",sizeof(*&a)); //16 *(&a)数组的地址解引用后表示数组
//     printf("%d\n",sizeof(&a+1));//8	数组之后的地址的大小
//     printf("%d\n",sizeof(&a[0]));//8 数组首元素的地址
//     printf("%d\n",sizeof(&a[0]+1));//8 数组第二个元素的地址
//     return 0;
// }




// //冒泡排序，按照qsort修改为可以接收任意类型的数组结构
// int cmp_int(const void* e1,const void* e2){
//     return *(int*)e1 - *(int*)e2; //这里需要强制类型转换，并根据文档说明写返回值
//     //文档中说明e1>e2返回一个大于0的值，e1<e2返回一个小于0的值，e1==e2返回0。
// }
// //用于交换的函数，需要注意的是这里需要width才能知道有多少字节需要交换
// //这里使用char进行交换是因为char只占一个字节，可以通过char和width配合找到不同类型元素的地址。
// //如果使用int*这种接收的话不能适用于其他类型的数组，比如字符数组，比如double类型的数组
// void swap(char* buf1,char* buf2,int width){
//     int i = 0;
//     for(i=0;i<width;i++){
//         char tmp = *buf1; //TODO：注意这里的tmp  如果使用char* tmp;  *tmp = *buf1;会报错，不知道为什么
//         *buf1 = *buf2;
//         *buf2 = tmp;
//         buf1++;
//         buf2++; 
//     }

// }
// void bubble_sort(void* base,int sz,int width,int(*cmp)(const void* e1,const void* e2)){
//     int i = 0;
//     for(i=0;i<sz-1;i++){
//         //一趟排序
//         int j = 0;
//         for(j=0;j<sz-1-i;j++){
//             if(cmp((char*)base+j*width,(char*)base+(j+1)*width ) > 0){
//                 swap((char*)base+j*width,(char*)base+(j+1)*width,width);
//             }
//         }
//     }
// }
// void test1(){
//     int arr[10] = {9,8,7,6,5,4,3,2,1,0};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int i = 0;
//     bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);  //此处的&cmp_int中的&可以省略
	
//     for(i=0;i<sz;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }
// int cmp_float(const void* e1,const void* e2){
//     // return (int)(*(float*)e1 - *(float*)e2);//这种写法不够严谨，+-0.xx的数会被忽略
//     if(*(float*)e1 > *(float*)e2){
//         return 1;
//     }else if (*(float*)e1 < *(float*)e2){
//         return -1;
//     }
//     else{
//         return 0;
//     }
// }
// void test2(){
//     float arr[] = {9.0,8.0,7.0,6.0,5.0,4.0};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int i = 0;
//     qsort(arr,sz,sizeof(arr[0]),cmp_float);
//     for(i=0;i<sz;i++){
//         printf("%f ",arr[i]);
//     }
//     printf("\n");
// }
// int main(){
//     test1(); 
//     test2();
//     return 0;
// }



// //回调函数例子 -- qsort
// int cmp_int(const void* e1,const void* e2){
//     return *(int*)e1 - *(int*)e2; //这里需要强制类型转换，并根据文档说明写返回值
//     //文档中说明e1>e2返回一个大于0的值，e1<e2返回一个小于0的值，e1==e2返回0。
// }
// void test1(){
//     int arr[10] = {9,8,7,6,5,4,3,2,1,0};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int i = 0;
//     qsort(arr,sz,sizeof(arr[0]),cmp_int);  //此处的&cmp_int中的&可以省略
	
//     for(i=0;i<sz;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }
// int cmp_float(const void* e1,const void* e2){
//     // return (int)(*(float*)e1 - *(float*)e2);//这种写法不够严谨，+-0.xx的数会被忽略
//     if(*(float*)e1 > *(float*)e2){
//         return 1;
//     }else if (*(float*)e1 < *(float*)e2){
//         return -1;
//     }
//     else{
//         return 0;
//     }
// }
// void test2(){
//     float arr[] = {9.0,8.0,7.0,6.0,5.0,4.0};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int i = 0;
//     qsort(arr,sz,sizeof(arr[0]),cmp_float);
//     for(i=0;i<sz;i++){
//         printf("%f ",arr[i]);
//     }
//     printf("\n");
// }
// int main(){
//     test1();
//     test2();
//     return 0;
// }



// //回调函数的简单例子
// void Calc(int (*pf)(int,int)){ //回调函数
//     int x = 0;
//     int y = 0;
//     printf("请输入两个数>");
//     scanf("%d%d",&x,&y);
//     printf("result = %d\n",pf(x,y));
// }
// int Add(int x,int y){
//     return x+y;
// }
// int Sub(int x,int y){
//     return x-y;
// }
// int Mul(int x,int y){
//     return x*y;
// }
// int Div(int x,int y){
//     return x/y;
// }
// int main(){
//     int input = 0;
//     printf("请选择>");
//     scanf("%d",&input);
//     switch(input){
//         case 1:
//             Calc(Add);
//             break;
//         case 2:
//             Calc(Sub);
//             break;
//         case 3:
//             Calc(Mul);
//             break;
//         case 4:
//             Calc(Div);
//             break;
//         case 0:
//             printf("退出\n");
//             break;
//         default:
//             printf("输入错误\n");
//             break;
//     }
// }



// //函数指针数组的应用
// //转移表
// void menu(){
//     printf("******************\n");
//     printf("***1.Add 2.Sub****\n");
//     printf("***3.Mul 4.Div****\n");
//     printf("***   0.exit  ****\n");
//     printf("******************\n");
// }
// int Add(int x,int y){
//     return x+y;
// }
// int Sub(int x,int y){
//     return x-y;
// }
// int Mul(int x,int y){
//     return x*y;
// }
// int Div(int x,int y){
//     return x/y;
// }
// int main(){
//     menu();
//     int input = 0;
//     int x = 0;
//     int y = 0;
//     int (*parr[])(int,int) = {0,Add,Sub,Mul,Div};
//     int sz = sizeof(parr)/sizeof(parr[0]); 
//     do{
//         printf("请选择>");
//         scanf("%d",&input);
//         if(input>=1 && input <=(sz-1)){
//             printf("请输入两个数>");
//             scanf("%d%d",&x,&y);
//             printf("result = %d\n",parr[input](x,y));
//         }else if(input == 0){
//             printf("游戏退出!\n");
//             break;
//         }else{
//             printf("输入错误!\n");
//         }
        
//     }while(input);
//     return 0;
// }


// //很绕的例子1
// (*(void(*)())0)()
// void(*)()
// (void(*)())0 //对0进行强行类型转换，将0转换成函数指针，0就是一个函数类型的地址
// (*(void(*)())0)()//函数地址解引用


// //很绕的例子2
// void (*signal(int,void(*)()))(int)
// void(*)() //函数指针
// signal(int,void(*)())//signal是函数名，两个参数，一个是整数，一个是函数指针
// void (*)(int)//这部分函数指针是返回值。去除掉函数的函数名和参数，其余部分就是返回值。
// //这个表达式的含义是，调用一个signal函数，传入一个整数，一个函数指针，返回一个函数指针
// void (*)(int) signal(int,void(*)()) //这种是不对的，因为void (*)(int)中的*应该靠近名字。
// //就和数组指针  int (*parr)[10]不写作 int(*)[] parr
// //可以通过typedef将函数指针简化
// typedef void(*pfun_t)(int)
// pfun_t signal(int,pfun_t)

// //函数指针
// int Add(int x,int y){
//     return x+y;
// }
// int main(){
//     int a = 10;
//     int b = 20;
//     printf("%p\n",Add);	//打印函数的地址
//     printf("%p\n",&Add);	//打印函数的地址
//     int (*pa)(int,int) = Add;//构造方式和数组指针的构造相识
//     printf("%d\n",(*pa)(3,2));
//     return 0;
// }

// //二级指针传参
// void test(int** ptr){
//     printf("num = %d\n", **ptr); 
// }
// int main()
// {
//     int n = 10;
//     int*p = &n;
//     int **pp = &p;
//     int* arr[10];
//     test(pp);	//传入二级指针
//     test(&p);	//传入一级指针的指针
//     test(arr);	//传入指针数组（的首元素地址）
//     return 0;
// }


// //二维数组传参
// void test(int arr[3][5])//ok
// void test(int arr[][])//错误，省略了列
// void test(int arr[][5])//ok
// //总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
// //因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
// //这样才方便运算。
// void test(int *arr)//错误
// void test(int* arr[5])//错误
// void test(int (*arr)[5])//ok 二维数组的首元素是一维数组，因此首元素地址就是一个数组指针
// void test(int **arr)//错误
// int main()
// {
//     int arr[3][5] = {0};
//     test(arr);
// }

// //一维数组传参
// void test(int arr[])//ok
// void test(int arr[10])//ok
// void test(int *arr)//ok
// void test2(int *arr[20])//ok
// void test2(int **arr)//ok
// int main(){
//     int arr[10] = {0};
// int *arr2[20] = {0};
//     test(arr);
//     test2(arr2);
// }



// //数组指针一般不用于一维数组，一维数组直接使用对应类型的指针的就行
// //比如：int arr[10];  int* p = &arr;//这样 *(p+i)每次也可以访问到数组的元素
// void print2(int (*p)[5],int x,int y){
//     int i = 0;
//     for(i=0;i<x;i++){
//         int j = 0;
//         for(j=0;j<y;j++){
//             printf("%d ",*(*(p+i)+j));//*(p+i)[j]//为什么这个*(p+i)是数组指针，还能加上j啊，
//         }
//         printf("\n");
//     }
// }
// int main(){
//     int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
//     //arr的首元素要将其看作一维数组的首元素，即3个带有5个元素的一维数组组成的一维数组
//     // print1(arr,3,5); //之前的方式，打印一个二维数组使用函数+循环的方式，需要传入2个容量的值
//     print2(arr,3,5);//把arr看作是第一行的地址
//     return 0;
// }



// //数组指针和指针数组
// int main(){
//     char* arr[5];
//     char* (*parr)[5] = &arr;  //这是一个数组指针，其中数组是一个指针数组
//通常一维数组不用数组指针
//     return 0;
// }



// //指针数组的使用
// int main(){
//     int arr1[] = {1,2,3,4,5};
//     int arr2[] = {2,3,4,5,6};
//     int arr3[] = {3,4,5,6,7};

//     int* parr[] = {arr1,arr2,arr3};
//     int i = 0;
//     for(i=0;i<3;i++){
//         int j = 0;
//         for(j=0;j<5;j++){
//             printf("%d ",*(parr[i]+j));
//         }
//         printf("\n");
//     }
//     return 0;
// }



// //常量字符串的地址（相同常量字符串的地址是相同的）
// int main(){
//     char arr1[] = "abcdef";
//     char arr2[] = "abcdef";
//     char* p1 = "abcdef";//其实应该加const,下同
//     char* p2 = "abcdef";
//     if(arr1 == arr2){  //if(p1 == p2)
//         printf("haha\n");//p1 == p2判断时 打印这个
//     }else{
//         printf("hehe\n");//arr1==arr2判断时 打印这个
//     }
//     //各不相同000000000061FE19
//     // 000000000061FE12
//     // 000000000061FE08
//     // 000000000061FE00
//     printf("%p\n",&arr1);
//     printf("%p\n",&arr2);
//     printf("%p\n",&p1);
//     printf("%p\n",&p2);
//     return 0;
// }


// //测试浮点数和整数存储的区别
// int main(){
//     int n = 9;
//     float* pf = (float*)&n;//强制类型转换，并没有修改内容（指针）
//     printf("n=%d\n",n);
//     printf("pf的值=%f\n",*pf);

//     *pf = 9.0;
//     printf("n=%d\n",n);
//     printf("pf的值=%f\n",*pf);
//     return 0;
// }



// //溢出和截断，0和'\0'的关系
// int main(){
//     int i;
//     char a[1000];		//'\0'的值是0，而且char作为有符号的数，存储的是00000000
//     for(i = 0;i<1000;i++){
//         a[i] = -1-i; //此处是负的，且需要截取最后8位才是a[i]。当a[i] = -256时，全是0，此时的i=255
//     }
//     printf("%d\n",strlen(a)); //255（因为要减去'\0'）
//     return 0;
// }


// //查看整数的存储是大端还是小端（小端-低位存在低地址）
// int main(){
//     int a = 20;
//     return 0;
// }