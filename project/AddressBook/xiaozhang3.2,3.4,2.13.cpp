#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"header.h"
// 3.2 显示登录界面
/*
负责人:
功能: 显示登录界面，并获取用户输入的用户名和密码。
参数: void
返回值:
	0: 登录成功
	-1: 登录失败
*/
int showLoginInterface() {
	char username[20];
	char password[20];
	printf("\n\t\t\t***********登录界面***********\n");
	printf("\t\t\t用户名：");
	scanf("%s", username);
	printf("\t\t\t密码：");
	scanf("%s", password);

	encrypt(password);  //对输入的密码进行加密处理，方便后面与存储的密码比较
	if (authenticateUser("user_data.txt", username, password)) {
		printf("\n\t\t\t登录成功！");
		return 0;
	}
	else {
		printf("\n\t\t\t用户名或密码有误，请重新输入！");
		return -1;
	}
}

// 3.4 显示编辑记录界面
/*
负责人:
功能: 显示编辑记录界面，允许用户选择要编辑的联系人，并输入新的联系信息。
参数:
contacts: 存放联系人的数组。
num_contacts: 数组中联系人的数量。
返回值: void
*/
void showEditRecordInterface(struct ContactRecord contacts[], int num_contacts) {
	int choice;                 //联系人的序号
	int index = choice - 1;     //将序号转换为数组索引
	printf("联系人总数：%d\n", num_contacts);
	for (int i = 0; i < num_contacts; i++) {
		printf("%d.姓名：%s，电话：%s，地址：%s，邮编：%s，邮箱：%s\n", i + 1, contacts[i].name,
			contacts[i].phone, contacts[i].address, contacts[i].postcode, contacts[i].e_mail);;
	}

	printf("\n\t\t\t请选择需要编辑的联系人（序号）：\n");
	scanf("%d", &choice);
	if (index >= 0 && index < num_contacts) {
		printf("\n\t\t\t请编辑该联系人：\n");
		printf("\t\t\t输入新姓名：");
		scanf("%s", contacts[index].name);
		printf("\n\t\t\t输入新电话：");
		scanf("%s", contacts[index].phone);
		printf("\n\t\t\t输入新地址：");
		scanf("%s", contacts[index].address);
		printf("\n\t\t\t输入新邮编：");
		scanf("%s", contacts[index].postcode);
		printf("\n\t\t\t输入新邮箱：");
		scanf("%s", contacts[index].e_mail);
		printf("编辑成功！");
	}
	else {
		printf("没有所选的序号，请重新选择。");
		scanf("%d", &choice);
	}
}

// 2.13 添加分组
int addGroup(struct ContactRecord contacts[], int* num_contacts, char* group) {
	char new_group[20];
	printf("请输入要添加的新分组名： ");
	scanf("%19s", new_group);

	//1.先选择查找方式查找到要插入该分组的联系人
	int choice;
	printf("请选择查找方式：\n");
	printf("1.按姓名查找\n");
	printf("2.按电话查找\n");
	printf("3.按地址查找\n");
	printf("4.按邮编查找\n");
	printf("5.按邮箱查找\n");
	printf("6.模糊查找\n");
	printf("7.多条件查找\n");
	scanf("%d", &choice);
	getchar();                        //捕获换行符

	//2.再去执行相应的查找
	int index = -1;                  //保存返回的索引
	switch (choice) {
	case 1: {
		char name[20];
		printf("输入要查找的联系人姓名：");
		scanf("19%s", name);
		index = searchContactByName(contacts, *num_contacts, name);
		break;
	}
	case 2: {
		char phone[20];
		printf("输入要查找的联系人电话：");
		scanf("%19s", phone);
		index = searchContactByPhone(contacts, *num_contacts, phone);
		break;
	}
	case 3: {
		char address[20];
		printf("输入要查找的联系人地址：");
		scanf("%19s", address);
		index = searchContactByAddress(contacts, *num_contacts, address);
		break;
	}
	case 4: {
		char postcode[8];
		printf("输入要查找的联系人邮编：");
		scanf("%7s", postcode);
		index = searchContactByPostcode(contacts, *num_contacts, postcode);
		break;
	}
	case 5: {
		char e_mail[20];
		printf("输入要查找的联系人邮箱：");
		scanf("%19s", e_mail);
		index = searchContactByEmail(contacts, *num_contacts, e mail);
		break;
	}
	case 6: {
		char keyword[50];
		printf("输入要查找的联系人关键字：");
		scanf("%49s", keyword);
		index = fuzzySearchContacts(contacts, *num_contacts, keyword);
		break;
	}
	case 7: {
		char name[20];
		char phone[20];
		char address[20];
		char postcode[8];
		char e_mail[20];
		printf("输入要查找的联系人信息：");
		scanf("19%s", name);
		scanf("%19s", phone);
		scanf("%19s", address);
		scanf("%7s", postcode);
		scanf("%19s", e_mail);
		index = multiConditionSearch(contacts, *num_contacts, name, phone, address, postcode, e_mail);
		break;
	}
	default:
		printf("没有这个查找方式选项.\n");
		return -1; 
	}

	//3.检查查找结果并更改分组
	if (index != -1) {
		strcpy(contacts[index].group, new_group);
		printf("添加新分组成功！\n");
	}
	else {
		printf("未找到该联系人，添加分组失败\n");
	}
	return 0;				//返回0表示成功添加分组
}


