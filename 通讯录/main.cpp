#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#include"header.h"
#define  _CRT_SECURE_NO_WARNINGS
using namespace std;
/*
 *
 *
 *
 */

ContactRecord contacts[MAX_CONTACTS];
int num_contacts = 0;

int main()																		//定义了主函数main
{
	printf("\t\t************************************************\n");
	printf("\t\t***************欢迎进入通讯录*******************\n");
	printf("\t\t*************************************************\n");
	printf("按任意键进入主菜单\n");
	_getch();																	//等待用户输入任意内容
	readContacts(contacts, &num_contacts);
	int selectnum;
	while (1)																	//进入死循环，显示主菜单，根据用户的选择进行相应的操作。
	{
		selectnum = menu_select();												// 显示主菜单，并等待用户作出选择
		switch (selectnum)														//根据用户的选择进行不同的操作
		{
		case 0:
		{
			writeContacts(contacts, &num_contacts);
			//adduser();															// 添加用户信息
			break;
		}
		case 1:
		{
			list();																// 显示用户信息列表
			break;
		}
		case 2:
		{
			searchbyname();														// 按姓名查找用户信息
			break;
		}
		case 3:
		{
			searchbyphone();													// 按电话号码查找用户信息
			break;
		}
		case 4:
		{
			adduser();															// 修改用户信息
			break;
		}
		case 5:
		{
			sortbyname();														// 按姓名排序用户信息
			break;
		}
		case 6:
		{
			dele();																// 删除用户信息
			break;
		}
		case 7:
		{
			printf("BYE BYE!\n");
			system("pause");													// 暂停程序的运行，等待用户在控制台按下任意键后继续。
			getchar();
			exit(0);															// 直接跳出程序
		}
		}
	}
	getchar();

	cout << "哈哈哈哈哈哈哈" << endl;
	return 0;
}

