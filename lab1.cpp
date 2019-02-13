// сортировка элементов массива в файле
// test - имя файла
void sort(const char * test)
{
	// нужно открыть файл и прочитать количество элементов
	FILE * f;
	f = fopen(test, "rb+");
	int n;
	fread(&n, sizeof(int), 1, f); // получили кол-во элементов
	int * tmp;
	// пока не равно количеству елементов
	for (int i = 0; i <= n; i++)
	{

		for (int j = 0; j < n - i; j++)
		{

			int  arr;
			int  arrNext;
			fseek(f, sizeof(int)*(j + 1), SEEK_SET); // очередной элемент
			fread(&arr, sizeof(int), 1, f); // считываем очередной элемент
			fseek(f, sizeof(int)*(j + 2), SEEK_SET); // следующий после очередного
			fread(&arrNext, sizeof(int), 1, f); // считываем очередной элемент
			fflush(f);
			if (arr>arrNext)
			{
				// правого, то меняем их местами
				tmp = new int[1];
				memcpy(tmp, &arr, sizeof(int));
				arr = arrNext;
				arrNext = *tmp;
				fseek(f, sizeof(int)*(j + 1), SEEK_SET); // позиция первого элемента
				fwrite(&arr, sizeof(int), 1, f);

				fseek(f, sizeof(int)*(j + 2), SEEK_SET);
				fwrite(&arrNext, sizeof(int), 1, f);

			}
		}
	}
	fclose(f);
}