// c++book2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//完美实现
void main20()
{
	//main20
	char a[20];
	gets_s(a);
	char *pa = &a[0];

	//char* pa = & a;这一步好像不行... ,因为a本身就是一个指针了
	while (*pa != '\0')
	{
		cout << *pa;
		pa++;
	}
	cout << "------------\n";

	printf("name:%d\n", &a);
	printf("first:%d\n", &a[0]);
}

//二维数组变成一维度的
void main21()
{
	int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

	int s[12];

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j];
		}
	}
	for (int i = 0; i < 12; i++)
	{
		cout << s[i];
	}

	cout << "-----------------\n";
	//指针遍历,相当于指针的嵌套..a[i][j] a[i]是第一行第一个的地址...没有必要&,因为本身就是地址..
	//指针的编号
	int *pa;
	pa = &a[0][0];
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		cout << pa;
		cout << "的地址上是";
		cout << *(pa++) << endl;
	}

	cout << "-----------\n";
	pa = a[0];

	cout << *(&a[0][0] + 1) << endl; //2
	cout << *(a[1] + 1) << endl;	 //6
	cout << *(*(a + 1) + 1) << endl; //
	cout << *(a + 1) << endl;		 //这个下面一样，说明是地址嵌套的关系
	cout << &a[1][0] << endl;
}
void main22()
{
	//输出的数字 有没有运算能力  有运算能力
	int i = 0;
	cout << i;		   //0
	cout << i++;	   //0
	cout << ++i;	   //2
	printf("%d", i);   //2
	printf("%d", i++); //2
	printf("%d", ++i); //4
}

void main23()
{
	//main 23
	//下面这样做不行,数组还是数组...
	//char a = "apple";

	char a[20] = "apple";
	char *pa = a;

	printf("%s", a);
	//这个字母 具有地址 字符串二相性？...
	cout << a << endl;

	cout << *pa << endl; //和数字字符串一样..
	cout << *(pa + 1);

	//通过字符串 实现字符串的连接
	char b[10] = {'w', 'o', 'r', 'l', 'd'};
	//说明两种定义方式都可以用
	for (int i = 0; i <= 5; i++)
		cout << b[i];
	cout << "-------------------------\n";
	cout << "b:" << b << endl;

	char *pb = b;
	//pa指针
	while (*pa != '\0')
	{

		pa++;
	}

	//注意while语句或者for语句的否定是到了那之后  发现不满足才发现是这样子的；本身那个值可以到达；这个很重要！！
	cout << *(pa - 1) << endl; //这样才是e。。。为什么呢---知道了
	//这个现象意味着 最开始的指针指向是第一个 ，但是可以调整...因为指针就是地址
	cout << a[0] << "---------\n";
	cout << "a:" << a << endl;
	cout << "*a:" << *a << endl;

	//注意数字和字符串的区别 同样是一个字母的时候 一个是地址，一个是全部

	int c[4] = {1, 2, 3, 4};
	cout << "c:" << c << endl;
	cout << "*c:" << *c << endl;

	cout << "b:" << b << endl;
	cout << "*pb:" << *pb << endl; //还是只是一个w

	while (*pb != '\0')
	{
		*pa = *pb;
		pa++;
		pb++;
		//必须加值
	}

	//cout << "之后b:" << endl; //就没有l..
	*pa = '\0';

	//sizeof 到底是什么意思...
	//cout <<"sizeof" <<sizeof(pa); //4
	//cout << "sizeof" << sizeof(a)<<"----------"<<endl;//为什么呢？ ...居然是20
	//cout << "sizeofb" << sizeof(b) << endl;

	cout << "用指针合并之后的数组" << a << endl;
	cout << sizeof(a);
	cout << *pa << endl;
	cout << "*a:" << *a << endl;
	//说明有两套指针系统..一套是最开始那个 ，不会消失，有二相性质，符合人的理解；另一个是之后的指针,没有二相性
	cout << "sizeof(pa)" << sizeof(pa);

	//居然还是20..
	//cout <<b;
	//while (*pa != a;)

	//数字只能这样定义 int c[6]={1,2,3,4,5,6};
}
//传递地址 即使没有用到 但是也要编译....

//一般是把指针当成变量 那样子赋值...实验看能不能直接对地址进行调节
void main()
{
	//main24
	int a = 10;
	int b = 20;
	int *pa = NULL;
	int *pb = NULL;
	pa = &a;
	pb = &b;
	cout << "原来数据"
		 << "a:" << *pa << "b:" << *pb << endl;

	if (0)
	{
		int tem;
		tem = *pa;
		*pa = *pb;
		*pb = tem;
	}

	cout << "第一次交换"
		 << "a:" << *pa << "b:" << *pb << endl; //win 一旦以*指针的形式 存在就会一起变换
	cout << "a:" << a << "b:" << b << endl;		//win

	if (1)
	{
		int *tem;
		tem = pa;
		pa = pb;
		pb = tem;
	}
	cout << "第二次交换"
		 << "a:" << *pa << "b:" << *pb << endl; //win
	cout << "a:" << a << "b:" << b << endl;		//fail，但是如果是函数的话 就可以..

	cout << &a << pa << endl;
	cout << pb << &b << endl; //md 这才符合常理啊...

	if (0)
	{
		int tem;
		tem = a;
		a = b;
		b = tem;
	}
	cout << "第三次交换"
		 << "a:" << *pa << "b:" << *pb << endl; //win
	cout << "a:" << a << "b:" << b << endl;		//win

	//相当于 pa>>a（地址）>>10...这样子，*pa=a是等价的...都会发生改变   只是pa的话，不会发生变化  指针就是一次赋值而已
	//但是对应的pa pa也就发生了变化...
	//莫非这里也有嵌套...?
	//  -> 指针 中前方 不能影响后方，但是 可以影响前方 ，如果前方想要影响后方 就加 *
}
//多级指针回头再想...

void swap(int a, int b)
{
	int tem;
	tem = a;
	a = b;
	b = a;
}

void pswap(int *a, int *b)
{
	int tem;
	tem = *a;
	*a = *b;
	*b = tem;
}

//回去想思路
void main25()
{
	int a = 10, b = 20;
	int *pa = &a, *pb = &b;
	//swap(a, b);
	cout << "a:" << a << "b:" << b << endl;		 //10 20
	cout << "pa:" << *pa << "pb" << *pb << endl; //10 20

	//pswap(pa, pb);//这样就成功了...
	cout << "a:" << a << "b:" << b << endl;		 //20 10
	cout << "pa:" << *pa << "pb" << *pb << endl; //20 10

	pswap(&a, &b);
	cout << "a:" << a << "b:" << b << endl;		 //20 10
	cout << "pa:" << *pa << "pb" << *pb << endl; //20 10
}

//定义函数指针，实际上函数名字也就是函数的地址
int sum(int a, int b)
{
	return a + b;
}
void main26()
{
	int (*psum)(int, int); //妈的，这种定义方式好奇怪啊
	psum = sum;
	cout << (*sum)(3, 4) << endl; //这样子 也可以
	cout << (*psum)(3, 4) << endl;

	cout << "-------------------\n";
	void *p = NULL; //空类型的空指针
	p = sum;
	p = (int *)p;

	//cout << sizeof(*p) << endl;
	//cout << (*p)(3, 4) << endl;
	//指针怎么实现强制类型转换 妈的 好难..
	//cout << ( *(int)p)(3,4)<< endl;
}

//函数体内部赋值 感觉很神奇
//
int *pget(int *p)
{
	int i = 9;
	cout << "函数体内部的地址:" << &i << endl;
	cout << "内部的值" << i << endl;

	p = &i;
	return p; //只能返回指针
}

void main27()
{
	int *p = NULL;

	//直接输入地址
	p = pget(p);

	//为什么一改返回值之后 就不出代码了？
	cout << "hello" << endl;
	cout << "函数体外部的地址" << p << endl; //两个地址是一样的 说明函数具有地址传递地功能
	//但是值却消失了 说明所在区域没了.. 函数执行完之后 函数内容被去掉
	//但是如果是加了 static  ,那么那个值就会长期保存...

	cout << "函数体外部的值" << *p << endl;
}

//main28
void main28()
{
	//相当于各个地址存了个地址
	int *p[10];
	int a = 1;
	p[0] = &a;

	cout << *p[0] << endl; //1
	cout << &p[0] << endl;
	cout << p[0] << endl;

	//指针相当于一个数据类型..要记住了
	int **pp;
	pp = &p[0];
	cout << "**pp是：转化之后的地址" << *pp << endl; //和	前面地地址一样

	cout << "-----------------\n";
	char b[] = "apple";
	char *pb[10];
	//bi xu dou shi char
	pb[0] = &b[0];

	cout << *pb[0] << endl;
}

//main29 堆和栈
int *dui(int *p)
{
	p = new int;
	*p = 2;
	return p;
}
int *zhan(int *p)
{
	int a = 3;
	p = &a;
	return p;
}

void main29()
{
	int a = 2, b = 3;
	//&a = &b;  有的值 操作不行...比如这种

	int *p = NULL; //区分大小写
	p = new int;
	*p = 2;
	cout << *p << endl;

	int *pb = NULL;
	pb = &b;
	cout << *pb << endl;

	cout << "---------------\n";
	int *pdui = NULL;
	cout << *dui(pdui) << endl;

	int *pzhan = NULL;
	cout << *zhan(pzhan) << endl;

	cout << "===\n"
		 << endl;
	cout << *zhan(pzhan) << endl;

	delete pdui;
	for (int i = 0; i <= 3; i++)
		cout << *dui(pdui) << endl;

	for (int i = 0; i <= 3; i++)
		cout << *zhan(pzhan) << endl; //始终存在，根本看不到 销毁的过程..
}

//main30

int yinyong()
{
	return 1;
}
void main30()
{
	//引用
	int a = 1;
	int &b = a; //注意左值应用和右值引用的区别
	cout << b << endl;

	cout << "---------\n";
	cout << &a << &b << endl; //这一两个一模一样

	//cout << yinyong()++; 这个会报错 因为是左值

	int &&c = yinyong();
	cout << ++c << endl;
	//yinyong()之后就不再是临时变量了
}

void jiaohuan_(int a, int b)
{
	int tem;
	tem = a;
	a = b;
	b = tem;
}
void jiaohuan(int &a, int &b)
{
	int tem;
	tem = a;
	a = b;
	b = tem;
}

void pjiaohuan(int *a, int *b)
{
	int *tem = NULL;
	tem = a;
	a = b;
	b = tem;
}

void ppjiaohuan(int *a, int *b)
{
	int tem = NULL;
	tem = *a;
	*a = *b;
	*b = tem;
}
//main31
void main31()
{
	int a = 1, b = 2;
	int *pa = &a, *pb = &b;

	if (0)
	{
		cout << "第0情况";
		jiaohuan_(a, b); //未交换
		cout << "a:" << a << "b:" << b;
	}
	if (0)
	{
		cout << "第一情况";
		jiaohuan(a, b); //发生了交换
		cout << "a:" << a << "b:" << b;
	}
	if (0)
	{
		cout << "第二情况";
		cout << &a << &b << endl;
		pjiaohuan(&a, &b); //未交换，只是指针发生了交换,但是世纪地址没有发生交换
		cout << "a:" << a << "b:" << b;
		cout << &a << &b << endl;
	}
	if (0)
	{
		cout << "第三情况";
		ppjiaohuan(&a, &b); //交换成功...
		cout << "a:" << a << "b:" << b;
	}
	if (1)
	{
		cout << "第四情况";
		cout << pa << "pa对应地: " << &a << "--" << pb << "pb对应地：" << &b << endl;
		pjiaohuan(pa, pb); //交换失败
		cout << "a:" << a << "b:" << b << endl;
		cout << pa << "pa对应地: " << &a << "--" << pb << "pb对应地：" << &b << endl;
		cout << "a:" << *pa << "b:" << *pb << endl;
		//怎么感觉地址没有变化...//回去再看 是函数不一样
	}
	if (0)
	{
		cout << "第五情况";
		ppjiaohuan(pa, pb); //交换成功
		cout << "a:" << a << "b:" << b;
	}
}
//main32 cmd夺得
void main32(int argc, char *argv[])
{
	cout << "输入得到的符号" << endl;
	while (argc > 1)
	{
		++argv;
		cout << *argv << endl;
		argc--;
	}
}

//后面有个大作业。。。明天再做。。。
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
