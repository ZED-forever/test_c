#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu{
    char name[10];
    int age;
    char id[10];
}Stu;//这里需要分号
void print1(Stu s){
    printf("%s\n%d\n%s\n",s.name,s.age,s.id);
}
void print2(Stu* ps){
    printf("%s\n%d\n%s\n",ps->name,ps->age,ps->id);
}
int main(){
    //使用struct Stu创建了一个对象s1，并初始化
    Stu s1 = {"张三",20,"2023063001"};
    Stu* ps = &s1;
    // printf("%s\n%d\n%s\n",s1.name,s1.age,s1.id);
    // printf("%s\n%d\n%s\n",(*ps).name,ps->age,ps->id);
    print1(s1);
    print2(ps);
    return 0;
}



// struct S{
//     int a;
//     char b;
//     double c;
// };
// struct T{
//     char ch[10];
//     struct S s;
//     char* pc;
// };
// int main(){
//     char arr[] = "haha";
//     struct T t = {"hehe",{10,'w',3.14},arr};//嵌套使用
//     printf("%s,%d,%c,%lf,%s\n",t.ch,t.s.a,t.s.b,t.s.c,t.pc);//打印
//     printf("%s\n",&arr[0]);//打印haha	为什么一个字符指针可以接收字符数组？可能数组本身就是指针形式传入的
//     return 0;
// }



// void Init_arry(int* a[],int sz){
//     int i =0;
//     for(i = 0;i<sz;i++){
//         a[i] = &i;
//         printf("i=%d\n",i);
//         printf("%p\n",&i);
//     }
// }
// int main(){
//     int* a[3] = {0};
//     int sz = 3;
//     int i =0;
//     Init_arry(a,sz);
//     for(i=0;i<sz;i++){
//         printf("%d\n",a[i]);
//     }
//     return 0;
// }



// //递归实现指数运算
// double Pow(int a ,int k){
//     if(k>0)
//         return Pow(a,k-1) * a;
//     else if(k==0)
//         return 1;
//     else
//         return(1.0/Pow(a,-k));
// }
// int main(){
//     int a = 0;
//     int k = 0;
//     double ret = 0;
//     scanf("%d%d",&a,&k);
//     ret = Pow(a,k);
//     printf("ret = %lf",ret);
//     return 0;
// }



// //字符串逆序-递归
// void reverse_str(char arr[]){
//     int sz = strlen(arr);
//     char tmp = arr[0];
//     arr[0] = arr[sz-1];
//     arr[sz-1] = '\0';
//     if(sz >= 4){
//         reverse_str(arr+1);
//     }
//     arr[sz-1] = tmp;
// }
// int main(){
//     char arr[] = "abcdefg";
//     reverse_str(arr);
//     printf("%s\n",arr);
//     return 0;
// }



// //指针的+-法
// int main(){
//     int arr[10] = {};
//     int* p = &arr; //这里的指针是int*，一次修改一个int
//     int i = 0;
//     for(i=0;i<10;i++){
//         *(p+i) = 1;
//     }
//     return 0;
// }


// //为什么都是存放地址，指针还有类型
// //不同类型会影响到解引用，和指针的+-法
// int main(){
//     int a = 0x11223344;
//     int* pa = &a;
//     char* pc = &a;
//     printf("%p\n",pa);
//     printf("%p\n",pc);
//     return 0;
// }


// int main(){
//     printf("%d\n",sizeof(int*));//8  代表64位平台
//     printf("%d\n",sizeof(int));//4字节
//     printf("%d\n",sizeof(char*));
//     printf("%d\n",sizeof(double*));
//     return 0;
// }


// //整型提升3
// int main(){
//     char c =1;
//     printf("%u\n",sizeof(c));//1
//     printf("%u\n",sizeof(+c));//4
//     printf("%u\n",sizeof(!c));//4课程中的结果是1，不清楚为什么
//     return 0;
// }


// //整型提升2
// int main(){
//     char a = 0xb6;
//     short b = 0xb600;
//     int c = 0xb6000000;
//     if(a == 0xb6)   //10110110整型提升后        11111111111111111111111110110110
//         printf("a");
//     if(b == 0xb600) //1011011000000000整型提升后11111111111111111011011000000000
//         printf("b");
//     if(c == 0xb6000000)
//         printf("c");//只打印这个
//     return 0;
// }

//整型提升1
// int main(){
//     char a =3;		//00000011	00000000000000000000000000000011	32位
//     char b = 127;	//01111111	00000000000000000000000001111111	32位
//     char c = a + b;	//10000010	11111111111111111111111110000010	32位
//     printf("%d\n",c);//-126就是截断了
//     return 0;
// }


// //条件操作符
// int main(){
//     int a = 0;
//     int b = 0;
//     b=(a>5?a=-3:3);
//     printf("%d\n",b);
//     printf("%d\n",a);
//     return 0;
// }


// //计算整数中2进制中1的数量
// int main(){
//     int a = 0;
//     int count = 0;
//     int len = sizeof(a)*8;
//     int i = 0;
//     scanf("%d",&a);
//     for(i=0;i<len;i++){
//         if(1==(1&(a>>i))){
//             count++;
//         }
//     }
//     printf("2进制中1的个数为:%d\n",count);
//     printf("%d\n",a);//a的值没有变
//     return 0;
// }


//左移操作的效果
// int main(){
//     int a = -1;
//     int b = a<<2;
//     printf("b = %d\n",b);
//     return 0;
// } 



// //交换两个变量不能使用第三个变量，按位异或
// int main(){
//     int a =3;
//     int b =5;
//     a = a^b;
//     b = a^b;
//     a = a^b;
//     printf("a=%d,b=%d",a,b);
//     return 0;
// }


// //交换两个变量不能使用第三个变量，但是这种写法会容易溢出
// int main(){
//     int a =3;
//     int b =5;
//     a = a+b;
//     b = a - b;
//     a = a -b;
//     printf("a=%d,b=%d",a,b);
//     return 0;
// }


// //冒泡排序
// void bubble_sort(int* arr,int sz){
//     int flag = 1;
//     int i = 0;
//     for(i = 0;i < sz-1;i++){
//         int j = 0;
//         for(j = 0;j < sz-i-1;j++){
//             if( arr[j] > arr[j+1]){
//                 int tmp = 0;
//                 tmp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = tmp; 
//                 flag = 0;
//             }
//         }
//         if( flag == 1){
//             break;
//         }
//     }
// }
// int main(){
//     int arr[] = {9,8,7,6,5,4,3,2,1,0};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int i = 0;    
//     bubble_sort(arr,sz);
//     for(i=0;i<sz;i++){
//         printf("%d",arr[i]);
//     }
//     return 0;
// }



// //递归 青蛙跳台
// int JumpJump(int n){
//     if(n>2)
//         return JumpJump(n-1) + JumpJump(n-2);
//     else if(n ==1)
//         return 1;
//     else if(n==2)
//         return 2;
// }
// //循环 青蛙跳台
// int JumpJump(int n){
//     int a = 1;
//     int b = 2;
//     int c = 3;
//     if( n>2){
//         while(n>2){
//             c = a+b;
//             a = b;
//             b = c;
//             n--;
//         }
//         return c;
//     }else if(n==1){
//         return 1;
//     }else{
//         return 2;
//     }
// }
// int main(){
//     int n = 0;
//     int ret = 0;
//     scanf("%d",&n);
//     ret = JumpJump(n);
//     printf("ret = %d\n",ret);
//     return 0;
// }


// //汉诺塔
// void Hanno(int n,char a, char b ,char c){
//     if(n>1){
//         Hanno(n-1,a,c,b);
//         printf("%c -> %c\n",a,c);
//         Hanno(n-1,b,a,c);
//     }else{
//         printf("%c -> %c\n",a,c);
//     }
// }

// int main(){
//     int n = 0;
//     char a = 'a';
//     char b = 'b';
//     char c = 'c';
//     scanf("%d",&n);
//     Hanno(n,a,b,c);
//     return 0;
// }


// //递归求斐波那契数列
// int Fib(int n){
//     if (n <= 2)
//         return 1;
//     else
//         return Fib(n-1) + Fib(n-2);
// }
// //循环求斐波那契
// int Fib(int n ){
//     int ret1 = 1;
//     int ret2 = 1;
//     int tmp = 0;
//     int i =0;
//     if (n<=2)
//         return 1;
//     for(i=3;i<=n;i++){
//         tmp = ret2;
//         ret2 = ret1 + ret2;
//         ret1 = tmp;
//     }
//     return ret2;
// }
// int main(){
//     int n = 0;
//     int ret = 0;
//     scanf("%d",&n);
//     ret = Fib(n);
//     printf("ret = %d\n",ret);
//     return 0;
// }



// //递归求阶乘
// int Fac(int n){
//     if (n <= 1)
//         return 1;
//     else
//         return n * Fac(n-1);
// }
// int main(){
//     int n = 0;
//     int ret = 0;
//     scanf("%d",&n);
//     ret = Fac(n);
//     printf("ret = %d",ret);
//     return 0;
// }



// //递归求字符串长度
// int my_len(char* c){
//     if(*c != '\0')
//         return 1+my_len(++c);
//     else
//         return 0;
// }
// int main(){
//     char ch[] = {0};
//     int len = 0;
//     scanf("%s",&ch);
//     len = my_len(ch);
//     printf("length = %d",len);
//     return 0;
// }


// void print(int n){
//     printf("%d",n%10);
//     if(n > 9){
//         print(n/10);
//     }
// }
// int main(){
//     int num =0;
//     scanf("%d",&num);
//     print(num);
//     return 0;
// }






// typedef struct LNode{

//     int data;

//     struct LNode *next;

// }LNode;

// void InitLinkList(LNode **L){

//     (*L)=(LNode *)malloc(sizeof(LNode));

//     (*L)->data=0;

//     (*L)->next=NULL;

// }

// int main(){

//     LNode *L=NULL;

//     InitLinkList(&L);//为什么这样就可以修改？

//     printf("%p\n",L);

//     return 0;

// }

// //此处的结构指针不能修改，因为传入的是拷贝
// typedef struct LNode{

//     int data;

//     struct LNode *next;

// }LNode;

// void InitLinkList(LNode *L) //类比 整数a，如果要对a进行修改，就需要传入 a的指针
//                             //因此 结构体*L，如果要对 *L进行修改，就需要传入 *L的指针
//                             //如果你需要对结构哦提L进行修改，就传入 L的指针
// {

//     L=(LNode *)malloc(sizeof(LNode));

//     L->data=0;

//     L->next=NULL;

// }

// int main()
// {

//     LNode *L=NULL;

//     InitLinkList(L);//不会生效

//     printf("%p\n",L);
//     // printf("Ls data is =%d",L->data);
//     return 0;

// }


// //猜数字1.1
// #include <time.h>
// void menu(){
//     printf("**********************\n");
//     printf("***1.play   0.exit****\n");
//     printf("**********************\n");
// }
// void game(){
//     printf("游戏开始！\n");
//     int res = 0;
//     int guess = 0;
//     res = rand()%100+1;//生成一个1-100内的随机数
    
//     while(1){
//         scanf("%d",&guess);
//         if(guess > res){
//             printf("猜大了\n");
//             break;
//         }
//         else if(guess < res){
//             printf("猜小了\n");
//             break;
//         }
//         else{
//             printf("猜对了！\n");
//             break;
//         }
            
//     }
// }

// int main(){
//     int input = 0;
//     srand((unsigned int)time(NULL));
//         do
//     {
//         menu();
//         printf("请选择 >");
//         scanf("%d",&input);
//         switch(input){
//         case 1:
//             game();
//             break;
//         case 0:
//             printf("退出游戏");
//             break;
//         default:
//             printf("输入错误！");
//             break;
//         }
//     } while (input);
//     return 0;
// }

// //猜数字1.0
// int main(){
//     int answer = 10;
//     int guess = 0;
//     char judge = 'Y';
//     printf("游戏开始！\n");
//     while(judge == 'Y'){
//         printf("请输入你的数字！");
//         scanf("%d",&guess);
//         if(guess == answer){
//             printf("猜对了！\n");
//             break;
//         }else{
//             printf("猜错了！\n");
//             printf("是否继续：Y/N  >");
//             scanf("%c",&judge);
//             scanf("%c",&judge);
//         }
//     }
//     printf("游戏结束！\n");
//     return 0;
// }



// //九九乘法表，并且对齐
// int main(){
//     int i =0;
//     for(i=1;i<=9;i++){
//         int j = 0;
//         for(j=1;j<=i;j++){
//             printf("%d*%d=%-2d  ",i,j,i*j);//-表示左对齐，2表示2个空位
//         }
//         printf("\n");
//     }
//     return 0;
// }



// // 3次机会的登录程序
// int main(){
//     char password[20] = {0};
//     int i = 0;
//     while(i<3){
//         printf("请输入密码>");
//         scanf("%s",&password);
//         if(strcmp(password,"123456") == 0){//只有strcmp才能比较两个字符串
//             printf("登录成功！\n");
//             break;
//         }else{
//             printf("密码错误!\n");
//         }
//         i++;
//     }
//     if(i == 3){
//         printf("次数用完了！\n");
//     }
//     return 0;
// }



// //二分查找
// int main(){
//     int arry[10] ={1,2,3,4,5,6,8,9,10,11};
//     int size = sizeof(arry)/sizeof(arry[0]);
//     int target = 5;
//     int left = 0;
//     int right = size -1;

//     while(left <= right){
//         int mid = (left + right)/2;
//         if(arry[mid] < target){
//             left = mid +1;
//         }else if(arry[mid] > target){
//             right = mid -1;
//         }else{
//             printf("找到了，下标为%d",mid);
//             break;
//         }
//     }
//     if(left > right){
//         printf("找不到");
//     }
//     return 0;
// }



// int main(){
//     int i = 0;//这个也改了
//     while(i <= 10){
//         i ++;  //这样才不会死循环
//         if(i == 5){
//             continue;
//         }
//         printf("%d\n",i);//1,2,3,4,.....死循环
//     }

//     return 0;
// }



// int main()
// {
//     int ch =0;
//     while((ch = getchar()) != EOF)
//     {
//         if(ch < '0' || ch > '9')
//             continue;
//         putchar(ch);

//         printf("整数打印%d",ch);
//         printf("字符打印%c",ch);
//     }
//     return 0;
// }



// int main(){
//     int ch = 0; //这里怎么是整数？
//     while((ch = getchar()) != EOF)//EOF通过ctrl+z触发，end of file -> -1
//     {
//         putchar(ch);//类似printf("%c",ch)
//     }
//     return 0;
// }



// int main(){
//     int day = 0;
//     scanf("%d",&day);
//     switch(day)
//     {
//         case 1:
//             printf("星期一\n");
//         case 2:
//             printf("星期二\n");
//         case 3:
//             printf("星期三\n");
//         //省略
// }
// }



// struct Book{
//     char name[20];
//     short price;
// }; 							 //此处有分号
// int main(){
//     struct Book b1 = {"C语言程序设计",55};
//     printf("书名：%s\n",b1.name); //使用  .  来索引
//     printf("价格：%d\n",b1.price);
//     struct Book* p = &b1;
//     // b1.name="23";
//     strcpy(p->name,"C语言");
//     printf("书名：%s\n",(*p).name);//这种方式比较麻烦，推荐下面的方式
//     printf("书名：%s\n",p->name); //使用  ->  来索引结构体指针的内容
//     printf("价格：%d\n",p->price);
//     return 0;
// }


// int main()
// {
//     int a = 10;
//     int* p = &a;
//     int b = *p;
//     printf("p = %p\n",p);
//     printf("a = %d\n",a);
//     printf("b = %d\n",b);
//     *p = 20;
//     printf("a = %d\n", a);
//     printf("%d\n",sizeof(p));
//     return 0;
// }

// int main(){
//     char arry1[] = "abc";
//     char arry2[] = {'a','b','c'};  //此处结尾必为'\0'
//     char arry3[] = {'a','b','\0'};
//     char arry4[] = {'a',0,'c','b'};
//     int arry5[] = {1,2,3,4,5,6};
//     printf("arry1 = %s\n",arry1);
//     printf("arry2 = %s\n",arry2);
//     printf("arry3 = %s\n",arry3);
//     printf("len_arry4 = %d\n",strlen(arry4));
//     printf("arry4_2 = %c\n",arry4[1]);
//     printf("arry4_3 = %c\n",arry4[2]);
//     printf("arry5_len = %d\n",sizeof(arry5)/sizeof(arry5[0]));
//     return 0;
// }



// enum Color{
//     RED,
//     GREEN,
//     BLUE
// };
// int main(){
//     enum Color color = BLUE;
//     printf("color = %d\n",color);
//     printf("Blue = %d\n",BLUE);
//     return 0;
// }



// int main(){
//     const int n = 10;
//     int arr[10]={0}; 
//     return 0;
// }


// int main(){
//     int num1;
//     int num2;
//     int sum;
//     scanf("%d%d",&num1,&num2);
//     sum = num1 + num2;
//     printf("sum = %d",sum);
//     return 0;
// }


// int main()
// {
//     char a = "12qqqqqqqqqqqqqq3";
//     printf("char%d%c\n",sizeof(a),a);
//     printf("short%d\n",sizeof(short));
//     printf("int%d\n",sizeof(int));
//     printf("long%d\n",sizeof(long));
//     printf("longlong%d\n",sizeof(long long));
//     printf("float%d\n",sizeof(float));
//     printf("double%d\n",sizeof(double));
    
//     printf("你好世界！\n");
//     system("pause");
//     return 0;
// }