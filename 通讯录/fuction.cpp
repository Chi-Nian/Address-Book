#define  _CRT_SECURE_NO_WARNINGS
/*
 *
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"header.h"
#define MAX_INPUT 100


struct record							// 定义一个名为record的结构体类型，用来存储学生的信息
{
	char name[20];						// 姓名，最多20个字符
	char phone[12];						// 电话，最多12个字符
	char adress[50];					// 地址，最多50个字符
	char postcode[8];					// 邮编，最多8个字符
	char e_mail[20];					// 电子邮箱，最多20个字符
}student[100];							// 定义一个结构体数组，用来存储多个学生的信息，数组大小为100，即最多存储100个学生的信息


void encrypt(char* pwd)					//这是一个名为encrypt的函数，用于对传入的字符串进行简单的加密处理
{
	int pwdlen = strlen(pwd);			// 获取字符串的长度，用于循环处理每个字符。
	for (int i = 0; i < pwdlen; i++)	//遍历字符串中的每个字符。
	{
		pwd[i] ^= 15;					// 对于每个字符，使用异或运算对其进行加密处理
	}
}


int  get_record_count()					// 直接返回0，表示当前通讯录中没有任何记录
{
	return 0;
}

int num = 0;															// 声明一个名为num的整型变量


int menu_select()													// 定义一个名为menu_select的函数，用来显示菜单并获取操作选项
{
	char s[80];														// 定义一个字符数组s，用来存储用户输入的字符串
	int a;															// 定义一个整型变量a，用来存储用户输入的数字选项
	system("cls");													// 清屏，清除控制台中之前的内容
	printf("\t\t***********欢迎进入通讯管理界面********\n\n");
	printf("\t\t\t0. 输入记录\n");
	printf("\t\t\t1. 显示记录\n");
	printf("\t\t\t2. 按姓名查找\n");
	printf("\t\t\t3. 按电话号码查找\n");
	printf("\t\t\t4. 插入记录 \n");
	printf("\t\t\t5. 按姓名排序\n");
	printf("\t\t\t6. 删除记录\n");
	printf("\t\t\t7. 保存并退出\n");
	printf("\t\t***********************************************\n\n");
	do {															// 使用do-while循环，确保用户输入的数字选项在0~7之间
		printf("Enter you choice(0~7):");
		scanf("%s", s);												// 获取用户输入的字符串，并存储到字符数组s中
		a = atoi(s);										// 将字符数组s中的字符串转换成整型数值，并存储到变量a中
	} while (a < 0 || a>7);											// 当用户输入的数字选项不在0~7之间，就继续提示用户输入
	return a;														// 返回用户输入的数字选项
}


int adduser()														// 定义一个名为adduser的函数，用来添加学生信息
{
	printf("\n\t\t\t**************** 请输入用户信息 ****************\n");
	printf("\t\t\t输入姓名:");
	scanf("%s", student[num].name);									// 获取用户输入的姓名，并存储到结构体数组中
	printf("\n\t\t\t输入电话号码:");
	scanf("%s", student[num].phone);								// 获取用户输入的电话号码，并存储到结构体数组中
	printf("\n\t\t\t输入地址:");
	scanf("%s", student[num].adress);								// 获取用户输入的地址，并存储到结构体数组中
	printf("\n\t\t\t输入邮编:");
	scanf("%s", student[num].postcode);								//获取用户输入的邮编，并存储到结构体数组中
	printf("\n\t\t\t输入e-mail:");
	scanf("%s", student[num].e_mail);								// 获取用户输入的电子邮件地址，并存储到结构体数组中
	num++;															// 学生信息数量加1
	printf("\n\t\t\t是否继续添加?(Y/N):");							// 提示用户是否继续添加
	if (_getch() == 'y' || _getch() == 'Y')							// 如果用户输入的是’y’或’Y’，则递归调用adduser函数添加学生信息
		adduser();
	return(0);														// 返回0,结束函数
}


void list()											// 定义一个名为list的函数，用来显示所有学生信息
{
	int i;
	system("cls");									// 清屏，清除控制台中之前的内容
	if (num != 0)									// 如果有学生信息，则显示所有学生信息
	{
		printf("\t\t\t*************** 以下为通讯录所有信息************\n");
		for (i = 0; i < num; i++)					// 遍历所有学生信息，并逐一显示
		{
			printf("\t\t\t姓名:%s\n", student[i].name);
			printf("\t\t\t电话:%s\n", student[i].phone);
			printf("\t\t\t地址:%s\n", student[i].adress);
			printf("\t\t\t邮编:%s\n", student[i].postcode);
			printf("\t\t\tEmail:%s\n", student[i].e_mail);
			if (i + 1 < num)						// 如果不是最后一个学生信息，提示用户按任意键继续
			{
				system("pause");					// 将控制台暂停，等待用户按任意键继续
			}
		}
		printf("\t\t\t************************************************\n");
	}
	else											// 如果没有学生信息，则提示用户
		printf("\t\t\t通讯录中无任何纪录\n");
	printf("\t\t\t按任意键返回主菜单:\n");
	_getch();										// 等待用户按任意键
	return;											// 返回，结束函数
}


int searchbyname()											// 定义一个名为searchbyname的函数，用来按姓名查找学生信息
{
	int mark = 0;											// 定义一个整型变量mark，用来标记是否查找到了符合条件的学生信息
	int i;													// 定义一个整型变量i，用来遍历所有学生信息
	printf("\t\t\t***************** 按姓名查找 *******************\n");
	char name[20];											// 定义一个字符数组name，用来存储用户输入的姓名
	printf("\t\t\t请输入姓名:");
	scanf("%s", name);										// 获取用户输入的姓名
	for (i = 0; i < num; i++)								// 遍历所有学生信息，查找符合条件的学生信息
	{
		if (strcmp(student[i].name, name) == 0)				// 如果找到了符合条件的学生信息，则输出信息并增加mark的值
		{
			printf("\t\t\t************* 以下是您查找的用户信息 ***********\n");
			printf("\t\t\t姓名: %s\n", student[i].name);
			printf("\t\t\t电话: %s\n", student[i].phone);
			printf("\t\t\t地址: %s\n", student[i].adress);
			printf("\t\t\te-mail:%s\n", student[i].e_mail);
			printf("\t\t\t************************************************\n");
			mark++;											//学生信息+1
			if ((i + 1) < num)								// 如果找到的学生信息不是最后一条，则询问用户是否继续查找
			{
				printf("\t\t\t是否继续查找相同名字的用户信息:(y/n)");
				if (_getch() == 'y' || _getch() == 'Y')
				{
					continue;								// 如果用户继续查找，则继续循环查找
				}
				else
					return(0);								// 如果用户不继续查找，则返回0，结束函数
			}
			else											// 如果找到的是最后一条学生信息，则提示用户按任意键返回主菜单
			{
				printf("\t\t\t按任意键返回主菜单");
				_getch();
				return(0);									// 返回0，结束函数
			}
		}
	}
	if (mark == 0)											// 如果没有找到符合条件的学生信息，则提示用户
	{
		printf("\t\t\t没有相同姓名的用户纪录\n");
		printf("\t\t\t按任意键返回主菜单\n");
		_getch();
		return(0);											// 返回0，结束函数
	}
	return 0;												// 如果有符合条件的学生信息，则返回0，结束函数
}


int searchbyphone()											//定义一个名为searchbyphone的函数，用来按电话号码查找学生信息
{
	int mark = 0;											// 定义一个整型变量mark，用来标记是否查找到了符合条件的学生信息
	int i;													// 定义一个整型变量i，用来遍历所有学生信息
	printf("\t\t\t****************** 按电话查找 ******************\n");
	char phone[10];											// 定义一个字符数组phone，用来存储用户输入的电话号码
	printf("\t\t\t请输入电话号码:");
	scanf("%s", phone);										// 获取用户输入的电话号码
	for (i = 0; i < num; i++)								// 遍历所有学生信息，查找符合条件的学生信息
	{
		if (strcmp(student[i].phone, phone) == 0)			// 如果找到了符合条件的学生信息，则输出信息并增加mark的值
		{
			printf("\t\t\t************** 以下是您查找的用户信息 **********\n");
			printf("\t\t\t姓名: %s\n", student[i].name);
			printf("\t\t\t电话: %s\n", student[i].phone);
			printf("\t\t\t地址: %s\n", student[i].adress);
			printf("\t\t\te-mail:%s\n", student[i].e_mail);
			printf("\t\t\t************************************************\n");
			printf("\t\t\t按任意键返回主菜单\n");
			mark++;											//学生信息+1
			_getch();										// 等待用户按任意键
			return(0);										// 返回0，结束函数
		}
	}
	if (mark == 0)											// 如果没有找到符合条件的学生信息，则提示用户
	{
		printf("\t\t\t没有改用户的信息\n");
		printf("\t\t\t按任意键返回主菜单\n");
		_getch();											// 等待用户按任意键
		return(0);											// 返回0，结束函数
	}
	return(0);												// 返回0，结束函数
}


void deletebyphone()												//定义了一个名为deletebyphone的函数，用于根据用户输入的电话号码删除通讯录中对应的记录。
{
	int i, j;														// 定义循环计数器i、j
	int deletemark = 0;												// 定义删除标记变量deletemark
	char phone[20];													// 定义电话号码变量phone
	printf("\t\t\t请输入要删除用户电话号码:");
	scanf("%s", phone);												//接收用户输入的电话号码


	if (num == 0)													// 若记录数组为空，则输出提示信息并返回
	{
		printf("\t\t\t对不起，文件中无任何纪录\n");
		printf("\t\t\t按任意键返回主菜单\n");
		_getch();
		return;
	}
	for (i = 0; i < num; i++)										// 遍历所有学生信息，找到与用户输入的电话号码相同的学生信息
	{
		if (strcmp(student[i].phone, phone) == 0)					// 输出该学生信息并询问用户是否删除该学生信息
		{
			printf("\t\t\t以下是您要删除的用户纪录:\n");
			printf("\t\t\t姓名: %s\n", student[i].name);
			printf("\t\t\t电话: %s\n", student[i].phone);
			printf("\t\t\t地址: %s\n", student[i].adress);
			printf("\t\t\te-mail:%s\n", student[i].e_mail);
			printf("\t\t\t是否删除?(y/n)");
			if (_getch() == 'y' || _getch() == 'Y')					// 若用户选择删除，则将该学生信息从记录数组中删除
			{
				for (j = i; j < num - 1; j++)						// 遍历所有学生信息，找到与用户输入的电话号码相同的学生信息
					student[j] = student[j + 1];
				num--;												// 学生信息数量减1
				deletemark++;										// 删除标记变量加1
				printf("\t\t\t删除成功");
				printf("\t\t\t是否继续删除?(y/n)");
				if (_getch() == 'y' || _getch() == 'Y')				// 若用户选择继续删除其他学生信息，则递归调用deletebyphone函数
					deletebyphone();
				return;												//删除后返回
			}
			else
				return;												// 否则，直接返回。
		}
		continue;													//continue语句用来控制循环，跳过当前迭代并立即开始新一轮迭代
	}
	if (deletemark == 0)											// 若找不到对应的学生信息，则输出提示信息并返回
	{
		printf("\t\t\t没有该用户的纪录");
		printf("\t\t\t是否继续删除?(y/n)");
		if (_getch() == 'y' || _getch() == 'Y')						// 若用户选择继续删除其他学生信息，则递归调用deletebyphone函数
			deletebyphone();
		return;														//删除后返回
	}
	return;															//返回函数
}


void deletebyname()
{
	int a = 0;											// 定义起始位置
	int findmark = 0;									// 定义查找成功标记
	int j;												// 定义循环计数器j
	int deletemark = 0;									// 定义删除成功标记
	int i;												// 定义循环计数器i
	char name[20];										// 定义姓名变量name
	printf("\t\t\t请输入要删除用户姓名:\n");
	scanf("%s", name);									// 接收用户输入的姓名
	for (i = a; i < num; i++)							// 遍历所有学生信息
	{
		if (strcmp(student[i].name, name) == 0)			// 找到对应姓名的学生信息
		{
			printf("\t\t\t以下是您要删除的用户纪录:");	// 输出该学生信息
			findmark++;// 查找成功标记加1
			printf("\t\t\t________________________________");
			printf("\t\t\t姓名: %s", student[i].name);
			printf("\t\t\t电话: %s", student[i].phone);
			printf("\t\t\t地址: %s", student[i].adress);
			printf("\t\t\te-mail:%s", student[i].e_mail);
			printf("\t\t\t________________________________");
			printf("\t\t\t是否删除?(y/n)");
			if (_getch() == 'y' || _getch() == 'Y')		// 若用户选择删除，则将该学生信息从记录数组中删除
			{
				for (j = i; j < num - 1; j++)			//遍历学生信息，找到后删除
					student[j] = student[j + 1];
				num--;									// 学生信息数量减1
				deletemark++;							// 删除标记变量加1
				printf("\t\t\t删除成功");
				if ((i + 1) < num)						// 判断是否存在相同姓名的学生信息
				{
					printf("\t\t\t是否继续删除相同姓名的用户信息?(y/n)");
					if (_getch() == 'y')				// 若存在，则继续删除
					{
						a = i;							// 更新起始位置
						continue;						// 继续遍历
					}
				}
				printf("\t\t\t是否继续删除?(y/n)");
				if (_getch() == 'y')					// 如果用户选择继续，则递归调用deletebyname函数执行删除操作
					deletebyname();
				return;
			}
			if ((i + 1) < num)							// 如果离学生信息数量还有多个信息，则继续询问是否删除相同姓名的学生信息
			{
				printf("\t\t\t是否继续删除相同姓名的用户信息?(y/n)");
				if (_getch() == 'y' || _getch() == 'Y')	// 若用户选择继续删除，则继续遍历相同姓名的学生信息
				{
					a = i;								// 更新起始位置
					continue;							// 继续遍历相同姓名的学生信息
				}
			}
		}
		else
			continue;									// 继续遍历其他学生信息
	}
	if ((deletemark == 0) && (findmark == 0))			//如果无法找到对应的学生信息，则输出提示信息并返回上一级函数
	{
		printf("\t\t\t没有该用户的纪录");
		printf("\t\t\t是否继续删除?(y/n)");
		if (_getch() == 'y' || _getch() == 'Y')
			deletebyphone();
		return;
	}
	else if (findmark != 0)								//如果找到了相同姓名的学生信息，但没有删除成功，则输出提示信息并返回上一级函数
	{
		printf("\t\t\t没有重名信息");
		printf("\t\t\t没有该用户的纪录");
		printf("\t\t\t是否继续删除?(y/n)");
		if (_getch() == 'y' || _getch() == 'Y')			// 如果用户选择继续删除，则递归调用deletebyphone函数
			deletebyphone();
		return;
	}
}


int dele()									//这是一个名为dele的函数，用于从通讯录中删除联系人的信息。
{
	char choic;								//输出菜单，供用户选择删除方式
	printf("\t\t\t1-按电话号码删除 2-按姓名删除");
	printf("\t\t\t请选择:");
	choic = _getch();						// 获取用户键盘输入的选择
	switch (choic)							// 判断用户的选择
	{
	case '1':deletebyphone(); break;		// 如果用户选择按电话号码删除，则调用 deletebyphone() 函数
	case '2':deletebyname(); break;			// 如果用户选择按姓名删除，则调用 deletebyname() 函数
	}
	return(0);								// 返回0，表示删除成功
}


int sortbyname()															//这是一个名为sortbyname的函数，用于将通讯录中的学生记录按照姓名的字典序进行升序排序。
{
	int i, j;
	struct record tmp;
	for (i = 1; i < num; i++)												// 冒泡排序算法，按照姓名升序排序
	{
		if (strcmp(student[i].name, student[i - 1].name) < 0)				// 对于每个i，判断当前学生姓名是否比前一个学生姓名小，即判断是否需要交换其位置
		{
			tmp = student[i];												// 将当前学生信息保存到tmp中
			j = i - 1;														// 设置一个指针j指向前一个学生
			do																// 执行do-while循环，将指针j所指向的学生移到j+1的位置
			{
				student[j + 1] = student[j];								// 将指针j所指向的学生移到j+1的位置
				j--;														// 将j指针向前移动一个位置
			} while ((strcmp(tmp.name, student[j].name) < 0 && j >= 0));	// 直到遇到一个学生姓名比tmp的姓名小或j已经到了第一个学生为止
			student[j + 1] = tmp;											// 将tmp插入到指针j所指向的学生之后的位置，排序完成
		}
	}
	printf("\t\t\t排序成功,是否显示?(y/n)");								// 输出排序结果，并询问用户是否要显示排序后的结果
	if (_getch() == 'y')													// 如果用户选择显示排序结果，则调用 list() 函数，输出通讯录中所有学生的记录
		list();
	return(0);																// 返回0，表示排序完成
}


int readContacts(ContactRecord* contacts, int* num_contacts)
{
	FILE* fp = fopen("contacts.txt", "rb");             // 以二进制只读方式打开
	if (fp == NULL) {
		perror("打开文件失败");
		return -1;
	}

	*num_contacts = 0;                                  // 初始化联系人数量为0

	struct ContactRecord tmp;

	//%20s的逻辑是 读取的时候一直读 直到遇见空格/换行/或者读满20个
	while (fscanf(fp, "%20s%20s%30s%20s%20s\n",         //这里的格式化读取有问题，要按照指定的格式来读取，才能读取到
		tmp.name, tmp.phone, tmp.address, tmp.postcode, tmp.email) == 5)
	{
		contacts[*num_contacts] = tmp;
		(*num_contacts)++;

		// 打印
		printf("联系人: %d\n", *num_contacts);
		printf("Name: %s\nPhone: %s\nAddress: %s\nPostcode: %s\nEmail: %s\n",
			tmp.name, tmp.phone, tmp.address, tmp.postcode, tmp.email);
		printf("-----------------------------------------------------------\n");
		if (*num_contacts >= MAX_CONTACTS) break;        //限制最大联系人数量
	}

	fclose(fp);  // 关闭文件
	fp = NULL;


	return 0;
}


// 必须把换行给留着，不然会读入错误
int writeContacts(ContactRecord contacts[], int* num_contacts)
{
	FILE* fp = fopen("contacts.txt", "a");  // 以追加方式打开文件
	if (fp == NULL) {
		perror("打开文件失败");
		return -1;
	}

	ContactRecord newContact;
	char input[MAX_INPUT];
	int new_contacts = 0;

	printf("请输入联系人信息（输入'q'退出）：\n");

	while (1) {

		printf("姓名: ");
		fgets(newContact.name, sizeof(newContact.name), stdin);
		if (strcmp(newContact.name, "q\n") == 0) break;
		//if (strlen(newContact.name) < 4+1 || strlen(newContact.name) > 8+1) {   // + 1是为了算入\n
		//    printf("您输入的姓名有误，请重新输入\n");
		//    continue;
		//}

		printf("电话: ");
		fgets(newContact.phone, sizeof(newContact.phone), stdin);

		/*if (phoneLength != 7 && phoneLength != 8 && phoneLength != 11) {
			printf("您输入的电话有误，请重新输入\n");
			continue;
		}*/


		printf("地址: ");
		fgets(newContact.address, sizeof(newContact.address), stdin);
		/*if (0 < strlen(newContact.address) || strlen(newContact.address) < 15) {
			printf("您输入的地址有误，请重新输入\n");
			continue;
		}*/


		printf("邮编: ");
		fgets(newContact.postcode, sizeof(newContact.postcode), stdin);
		/*if (0 < strlen(newContact.postcode) && strlen(newContact.postcode) < 6+1 || strlen(newContact.postcode) > 6+1) {
			printf("您输入的邮编有误，请重新输入\n");
			continue;
		}*/

		printf("邮箱: ");
		fgets(newContact.email, sizeof(newContact.email), stdin);
		//if (0 < strlen(newContact.email) && strlen(newContact.email) < 9 || strlen(newContact.email) > 18) {    //可以允许为空的输入
		//    printf("您输入的邮箱有误，请重新输入\n");
		//    continue;
		//}

		// 写入文件，保留换行符
		fprintf(fp, "%s%s%s%s%s",
			newContact.name,
			newContact.phone,
			newContact.address,
			newContact.postcode,
			newContact.email);

		if (*num_contacts < MAX_CONTACTS) {
			contacts[*num_contacts] = newContact;
			(*num_contacts)++;
			new_contacts++;
		}
		else {
			printf("联系人数量已达到最大限制，无法添加更多\n");
			break;
		}

		printf("联系人已添加---是否继续添加？(y/n): ");
		fgets(input, MAX_INPUT, stdin);
		if (input[0] != 'y' && input[0] != 'Y') break;
	}

	fclose(fp);
	printf("成功写入 %d 个新联系人到文件。\n", new_contacts);
	return 0;
}



