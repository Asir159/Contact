#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _CONTACT_H
#define _CONTACT_H

#define MAX 1000

#define MAX_NAME 30
#define MAX_SEX  6 
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ʹ��ö�ٿ����ӿɶ���
enum Option
{
	Exit,
	ADD,
	Del,
	Search,
	Change,
	Show,
	Sort
};

//ͨѶ¼�����Ͷ���
struct PeoInfo
{
	char name[MAX_NAME];
	int  age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[30];
};

//ͨѶ¼������
struct Contact
{
	struct PeoInfo data[MAX];
	int size;
};

void InitContact(struct Contact *ps);				//��ʼ��ͨѶ¼
void ContactAdd(struct Contact* ps);				//���
void ContactShow(const struct Contact* ps);			//��ʾ
void ContactDel(struct Contact* ps);				//ɾ��
void ContactSearch(const struct Contact* ps);		//����
void ContactChange(struct Contact* ps);				//�ı�
void ContactSort(struct Contact* ps);				//������������

#endif 
