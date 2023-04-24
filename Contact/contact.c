#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

static int FineName(const struct Contact* ps)
{
	int i = 0;
	char name[MAX_NAME];
	scanf("%s", name);
	//便利数组，进行对比
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

//添加信息
void ContactAdd(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，请删除再操作");
	}
	else
	{
		printf("请输入姓名>:");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄>:");
		scanf("%d",&(ps->data[ps->size].age));
		printf("请输入性别>:");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话>:");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址>:");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
		
	}
}

//显示通讯录
void ContactShow(const struct Contact* ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s \t %-4s \t %-3s \t %-12s \t %-20s\n","姓名","年龄","性别","电话","地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s \t %-4d \t %-3s \t %-12s \t %-20s\n",
					ps->data[i].name,
					ps->data[i].age,
					ps->data[i].sex,
					ps->data[i].tele,
					ps->data[i].addr);
		}
	}
}

void ContactDel(struct Contact* ps)
{
	//创建一个字符串变量，进行对比
	int pos = 0;
	printf("请输入你需要删除的名字>:");
	pos = FineName(ps);
	//删除
	if (pos == -1)
	{
		printf("没有找到改名字\n");
	}
	else
	{
		int j = 0;
		for (j=pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void ContactSearch(const struct Contact* ps)
{
	int pos = 0;
	printf("请输入你需要查找的名字>:");
	pos = FineName(ps);

	if (pos == -1)
	{
		printf("没有找到改名字\n");
	}
	else
	{
		printf("%-20s \t %-4d \t %-3s \t %-12s \t %-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ContactChange(struct Contact* ps)
{
	char name[MAX_NAME];
	int pos = 0;
	printf("请输入你需要改变原的名字>:");
	pos = FineName(ps);

	if (pos == -1)
	{
		printf("没有找到改名字\n");
	}
	else
	{
		printf("请输入姓名>:");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄>:");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别>:");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话>:");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址>:");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功\n");
		
	}

}

//按照名字进行逆序排序
//目前只能实现逆序排序，因为数组太大，升序会把未赋值的数组替换上了（默认为0）
static int Reverse_str_cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct Contact*)e2)->data->name, ((struct Contact*)e1)->data->name);
}

//数组排序
void ContactSort(struct Contact* ps)
{
	int sz = 0;
	sz = sizeof(ps->data) / sizeof(ps->data[0]);
	qsort(ps->data,sz, sizeof(ps->data[0]), Reverse_str_cmp_name);
	printf("排序成功\n");
}