#include <iostream>
using namespace std;

class single
{
public:
	// ��ȡ��ʵ��
	static single* getinstance();
	// �ͷŵ�ʵ���������˳�ʱ����
	static void deleteinstance();
	// ��ӡʵ����ַ
	void print();

private:
	// ���乹���������Ϊ˽�е�, ��ֹ�ⲿ���������
	single();
	~single();
	// ���俽������͸�ֵ�����Ϊ˽�к���, ��ֹ�ⲿ�����͸�ֵ
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
	cout << "���캯��" << endl;
}
single::~single()
{
	cout << "��������" << endl;
}

int main()
{

	return 0;
}