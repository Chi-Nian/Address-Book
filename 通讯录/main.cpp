#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"header.h"
#define  _CRT_SECURE_NO_WARNINGS
/*
 *
 *
 *
 */

ContactRecord contacts[MAX_CONTACTS];
int num_contacts = 0;

int main()																		//������������main
{
	printf("\t\t************************************************\n");
	printf("\t\t***************��ӭ����ͨѶ¼*******************\n");
	printf("\t\t*************************************************\n");
	printf("��������������˵�\n");
	_getch();																	//�ȴ��û�������������
	readContacts(contacts, &num_contacts);
	int selectnum;
	while (1)																	//������ѭ������ʾ���˵��������û���ѡ�������Ӧ�Ĳ�����
	{
		selectnum = menu_select();												// ��ʾ���˵������ȴ��û�����ѡ��
		switch (selectnum)														//�����û���ѡ����в�ͬ�Ĳ���
		{
		case 0:
		{
			writeContacts(contacts, &num_contacts);
			//adduser();															// ����û���Ϣ
			break;
		}
		case 1:
		{
			list();																// ��ʾ�û���Ϣ�б�
			break;
		}
		case 2:
		{
			searchbyname();														// �����������û���Ϣ
			break;
		}
		case 3:
		{
			searchbyphone();													// ���绰��������û���Ϣ
			break;
		}
		case 4:
		{
			adduser();															// �޸��û���Ϣ
			break;
		}
		case 5:
		{
			sortbyname();														// �����������û���Ϣ
			break;
		}
		case 6:
		{
			dele();																// ɾ���û���Ϣ
			break;
		}
		case 7:
		{
			printf("BYE BYE!\n");
			system("pause");													// ��ͣ��������У��ȴ��û��ڿ���̨����������������
			getchar();
			exit(0);															// ֱ����������
		}
		}
	}
	getchar();
	printf("��������");
	return 0;
}

