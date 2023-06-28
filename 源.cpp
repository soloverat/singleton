#include <iostream>
using namespace std;

class single
{
public:
	// 获取单实例
	static single* getinstance();
	// 释放单实例，进程退出时调用
	static void deleteinstance();
	// 打印实例地址
	void print();

private:
	// 将其构造和析构成为私有的, 禁止外部构造和析构
	single();
	~single();
	// 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
	single(const single& signle);
	const single &operator=(const single& single);

private:
	static single* g_single;
};

single * single::g_single = new(nothrow) single();

single* single::getinstance()
{
	return g_single;
}

void single::deleteinstance()
{
	if (g_single)
	{
		delete g_single;
		g_single = nullptr;
	}
}

void single::print()
{
	cout << "this is:" << this << endl;
}
single::single()
{
	cout << "构造函数" << endl;
}
single::~single()
{
	cout << "析构函数" << endl;
}

int main()
{

	return 0;
}