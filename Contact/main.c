#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("*************************************\n");
	printf("*****1.add            2.del    ******\n");
	printf("*****3.search         4.change ******\n");
	printf("*****5.show           6.sort   ******\n");
	printf("*****0.exit                    ******\n");
	printf("*************************************\n");
}

int main()
{
	int input = 0;
	struct Contact con;
	struct PeoInfo peo;
	InitContact(&con);
	do {
		input = 0;
		menu();
		printf("请选择操作>:");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:ContactAdd(&con);
			break;
		case Del:ContactDel(&con);
			break;
		case Search:ContactSearch(&con);
			break;
		case Change:ContactChange(&con);
			break;
		case Show:ContactShow(&con);
			break;
		case Sort:ContactSort(&con);
			break;
		default:
			printf("选择错误,请重新选择\n");
			break;

		}
	} while (input);
	return 0;
}