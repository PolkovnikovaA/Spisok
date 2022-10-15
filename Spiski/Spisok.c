#include <stdio.h>

struct list
{
	int a;	//���� ������
	struct list* next;	//��������� �� ��������� �������
};
typedef struct list* LOS;

LOS createLOS(int n)
{
	LOS los = calloc(sizeof(struct list*));	//������� ������ �������
	LOS p1 = los, p2;
	p1->a = 1;
	for (size_t i = 1; i < n; i++)	//������� � ����� ��� ��������� ��������
	{
		p2 = calloc(1, sizeof(struct list*));	//�������������� ��������� �������
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;	//���������� ������� ���� ���������
	}
	p1->next = NULL;
	return los;
}

//LOS deletehead(LOS head, LOS los)
//{
//	LOS p1;
//	p1 = head->a;
//	free(head);
//	return p1;
//}

void deleteitem(LOS los, int k)
{
	for (size_t i = 1; i < k - 1; i++)
	{
		los = los->next;
	}
	printf("%d", los->a);
	LOS p1 = los->next;
	los->next = los->next->next;
}

LOS insertitem(LOS los, LOS item, int k)
{
	LOS el = malloc(sizeof(struct list*));
	el->a = item->a;

		for (size_t i = 1; i < k-1; i++)
		{
			los = los->next;
		}
		item->next = los->next;
		los->next = item;
	
	return los;
}

void Zamena(LOS los, int a, int m)
{
	LOS min = los;
	LOS max = los;
	LOS _max = los;
	if (a != 1) {
		for (size_t n = -1; n < a; n++)
		{
			min = min->next;
		}
		for (size_t n = 0; n < m - 2; n++)
		{
			_max = _max->next;
		}
		LOS l2 = _max->next;
		max = l2->next;
		LOS l1 = min->next;
		min->next = l2;
		_max->next = l1;
		l2->next = l1->next;
		l1->next = max;
		return los;
	}
}

void printLOS(LOS los)
{
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
}

void delete(LOS los)
{
	LOS p1 = los;
	while (p1)
	{
		p1 = los->next;	//��������� ���������
		free(los);	//������� ����������
		los = p1;	//��������� ���� ������
	}
}



int main()
{
	system("chcp 1251>nul");

	//	����� ������
	printf("����� ������\n");
	LOS los = createLOS(10);
	printLOS(los);

	//	���������� �������� � ������
	printf("\n���������� �������� � ������");
	LOS item = calloc(1, sizeof(struct list*));
	item->a = 25;
	item->next = NULL;
	insertitem(los, item, 5);
	printf("\n");
	printLOS(los);

	//	�������� �������� �� ������
	printf("\n�������� �������� �� ������");
	deleteitem(los, 5);
	printf("\n");
	printLOS(los);

	

	//�������� ������� ��������
	/*deletehead(los, 1);
	printf("\n");
	printLOS(los);*/

	//������ ���������
	printf("\n������ ���������");
	Zamena(los, 3, 5);
	printf("\n");
	printLOS(los);

	// �������� ������
	printf("\n�������� ������");

	printf("\n");
	
	free(los);

	return 0;
}