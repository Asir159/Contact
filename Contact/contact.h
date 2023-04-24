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

//使用枚举可增加可读性
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

//通讯录的类型定义
struct PeoInfo
{
	char name[MAX_NAME];
	int  age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[30];
};

//通讯录的整体
struct Contact
{
	struct PeoInfo data[MAX];
	int size;
};

void InitContact(struct Contact *ps);				//初始化通讯录
void ContactAdd(struct Contact* ps);				//添加
void ContactShow(const struct Contact* ps);			//显示
void ContactDel(struct Contact* ps);				//删除
void ContactSearch(const struct Contact* ps);		//搜索
void ContactChange(struct Contact* ps);				//改变
void ContactSort(struct Contact* ps);				//排序，逆序排序

#endif 
