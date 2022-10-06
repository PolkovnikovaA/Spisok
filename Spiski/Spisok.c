#include <stdio.h>

struct list
{
	int a;
	struct list* next;
};
typedef struct list* LOS;

LOS createLOS(int n)
{
	LOS los = calloc(1, sizeof(LOS));
	LOS p1 = los, p2;
	p1->a = 1;
	for (size_t i = 1; i < n; i++)
	{
		p2 = calloc(1, sizeof(LOS));
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;
	}
	p1->next = NULL;
	return los;
}

void deleteitem(LOS los, int k)
{
	if (k==1)
	{
		for (size_t i = 1; i < k - 1; i++)
		{
			los = los->next;
		}
		/*printf("%d", los->a);*/
		LOS p2 = los->next;
		los->next = los->next->next;
		/*free(p1);*/
	}
	else
	{
		//for (size_t i = 1; i < k - 1; i++)
		//{
		//	los = los->next;
		//}
		///*printf("%d", los->a);*/
		//LOS p1 = los->next;
		//los->next = los->next->next;
		/*free(p1);*/
	}

	

}

LOS insertitem(LOS los, LOS item, int k)
{
	if (k == 1)
	{
		item->next = los;
		los = item;
		
	}
	else
	{
		for (size_t i = 1; i < k-1; i++)
		{
			los = los->next;
		}
		item->next = los->next;
		los->next = item;
	}
}

//void Zamena(LOS los, LOS item, int k)
//{
//	/*if (k == 1)
//	{
//		item->next = los;
//		los = item;
//
//	}
//	else
//	{*/
//		for (size_t i = 1; i < k - 1; i++)
//		{
//			los = los->next;
//		}
//		item->next = los->next;
//		los->next = item;
//	/*}*/
//}

void printLOS(LOS los)
{
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
}



int main()
{
	//	Вывод списка
	LOS los = createLOS(10);
	printLOS(los);

	//	Добавление элемента в список
	LOS item = calloc(1, sizeof(LOS));
	item->a = 45;
	item->next = NULL;
	insertitem(los, item, 1);
	printf("\n");
	printLOS(los);

	//	Удаление элемента из списка
	deleteitem(los, 1);
	printf("\n");
	printLOS(los);
	

	return 0;
}