#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

static int FineName(const struct Contact* ps)
{
	int i = 0;
	char name[MAX_NAME];
	scanf("%s", name);
	//�������飬���жԱ�
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

//�����Ϣ
void ContactAdd(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼��������ɾ���ٲ���");
	}
	else
	{
		printf("����������>:");
		scanf("%s", ps->data[ps->size].name);
		printf("����������>:");
		scanf("%d",&(ps->data[ps->size].age));
		printf("�������Ա�>:");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰>:");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ>:");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
		
	}
}

//��ʾͨѶ¼
void ContactShow(const struct Contact* ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s \t %-4s \t %-3s \t %-12s \t %-20s\n","����","����","�Ա�","�绰","��ַ");
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
	//����һ���ַ������������жԱ�
	int pos = 0;
	printf("����������Ҫɾ��������>:");
	pos = FineName(ps);
	//ɾ��
	if (pos == -1)
	{
		printf("û���ҵ�������\n");
	}
	else
	{
		int j = 0;
		for (j=pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void ContactSearch(const struct Contact* ps)
{
	int pos = 0;
	printf("����������Ҫ���ҵ�����>:");
	pos = FineName(ps);

	if (pos == -1)
	{
		printf("û���ҵ�������\n");
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
	printf("����������Ҫ�ı�ԭ������>:");
	pos = FineName(ps);

	if (pos == -1)
	{
		printf("û���ҵ�������\n");
	}
	else
	{
		printf("����������>:");
		scanf("%s", ps->data[pos].name);
		printf("����������>:");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�>:");
		scanf("%s", ps->data[pos].sex);
		printf("������绰>:");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ>:");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ�\n");
		
	}

}

//�������ֽ�����������
//Ŀǰֻ��ʵ������������Ϊ����̫��������δ��ֵ�������滻���ˣ�Ĭ��Ϊ0��
static int Reverse_str_cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct Contact*)e2)->data->name, ((struct Contact*)e1)->data->name);
}

//��������
void ContactSort(struct Contact* ps)
{
	int sz = 0;
	sz = sizeof(ps->data) / sizeof(ps->data[0]);
	qsort(ps->data,sz, sizeof(ps->data[0]), Reverse_str_cmp_name);
	printf("����ɹ�\n");
}