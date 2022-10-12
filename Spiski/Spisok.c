#include <stdio.h>

struct list
{
	int a;	//Поле данных
	struct list* next;	//Указатель на следующий элемент
};
typedef struct list* LOS;

LOS createLOS(int n)
{
	LOS los = calloc(sizeof(struct list*));	//Создаем первый элемент
	LOS p1 = los, p2;
	p1->a = 1;
	for (size_t i = 1; i < n; i++)	//Создаем в цикле все остальные элементы
	{
		p2 = calloc(1, sizeof(struct list*));	//Инициализируем следующий элемент
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;	//Предыдущий элемент стал следующим
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

	if (k == 1)	//Если меняем первый элемент
	{
		el->next = los;
		los = el;
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
	return los;
}

void Zamena(LOS los, LOS item, int k)
{
	/*if (k == 1)
	{
		item->next = los;
		los = item;

	}
	else
	{*/
		for (size_t i = 1; i < k - 1; i++)
		{
			los = los->next;
		}
		item->next = los->next;
		los->next = item;
	/*}*/
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
		p1 = los->next;	//запомнили следующий
		free(los);	//удалили предыдущий
		los = p1;	//следующий стал первым
	}
}



int main()
{
	system("chcp 1251>nul");

	//	Вывод списка
	printf("Вывод списка\n");
	LOS los = createLOS(10);
	printLOS(los);

	//	Добавление элемента в список
	printf("\nДобавление элемента в список");
	LOS item = calloc(1, sizeof(struct list*));
	item->a = 25;
	item->next = NULL;
	insertitem(los, item, 5);
	printf("\n");
	printLOS(los);

	//	Удаление элемента из списка
	printf("\nУдаление элемента из списка");
	deleteitem(los, 5);
	printf("\n");
	printLOS(los);

	// Удаление списка
	printf("\nУдаление списка");
	
	printf("\n");
	printLOS(los);

	//Удаление первого элемента
	/*deletehead(los, 1);
	printf("\n");
	printLOS(los);*/

	//Замена элементов
	Zamena(los, 3, 5);
	printf("\n");
	printLOS(los);
	

	return 0;
}