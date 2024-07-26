#include<iostream>
using namespace std;
void showMainlnterface()
{
	cout << "***************************" << endl;
	cout << "***** 1，增加通讯信息 *****" << endl;
	cout << "***** 2，查找通讯信息 *****" << endl;
	cout << "***** 3，修改通讯信息 *****" << endl;
	cout << "***** 4，删除通讯信息 *****" << endl;
	cout << "***** 5，显示所有记录 *****" << endl;
	cout << "****** 0，退出通讯录 ******" << endl;
	cout << "***************************" << endl;
}
int main()
{
	showMainlnterface();
	system("pause");
	return 0;
}
