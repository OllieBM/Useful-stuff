#include<iostream>
#include<chrono>


//
//template<typename T>
//T* QuickSort(T* list, int N)
//{
//	/*T* tail = list + N-1;
//	return std::pair<T, T>(*list, *tail);*/
//	// find pivot?
//	//int pivot = 0; // index of elemnt?
//
//	int pivotIndex =N / 2;
//	int pivotValue = list[pivotIndex];
//	printf("pivot index = [%i] = %i\n", pivotIndex, list[pivotIndex]);
//	/*T head = list[0];
//	T tail =  list[N - 1];
//	printf("head %i,", head);
//	printf("tail %i\n", tail);*/
//	
//	/*T pivot = list[pivotIndex];
//
//	T temp = head;
//	*list = tail;
//	list[N-1] = temp;*/
//
//	//// sort this list
//	//for (int i = 0, j = pivotIndex-1; i<=j; ++i, --j)
//	//{
//	//	if (list[i] > list[j])
//	//		std::swap(list[i], list[j]);
//	//	if (list[pivotIndex] < list[i])
//	//		std::swap(list[i], list[pivotIndex]);
//	//	if (list[pivotIndex] > list[j])
//	//		std::swap(list[j], list[pivotIndex]);
//	//}
//	//for (int i = pivotIndex + 1, j = N - 1; i <= j; ++i, --j)
//	//{
//	//	if (list[i] > list[j])
//	//		std::swap(list[i], list[j]);
//	//	if (list[pivotIndex] < list[i])
//	//		std::swap(list[i], list[pivotIndex]);
//	//	if (list[pivotIndex] > list[j])
//	//		std::swap(list[j], list[pivotIndex]);
//	//}
//
//	// get next and previous items of pivot
//	//T prev = list[pivotIndex - 1];
//	//T next = list[pivotIndex + 1];
//
//
//	//for (int i = 0, j = N - 1; i < j; ++i, --j)
//	//{
//
//	//	if (list[i] >= list[pivotIndex] >=  list[j])
//	//		std::swap(list[i], list[j]);
//
//	//	/*if (list[i] > list[pivotIndex])
//	//		std::swap(list[i], list[pivotIndex]);
//	//	if (list[pivotIndex] > list[j])
//	//		std::swap(list[j], list[pivotIndex]);*/
//	//}
//
//	for (int x = 0; x < N; ++x)
//	{
//		printf("%i ", list[x]);
//	}
//	printf("\n");
//
//	// left loop
//	int j = N - 1;
//	for (int i = 0; i < j; ++i)
//	{
//		if (list[i] >= list[pivotIndex])
//		{
//			for (; j > i; --j)
//			{
//				if (list[pivotIndex] >= list[j])
//				{
//					
//					printf("swapping %i and %i\n", list[i], list[j]);
//					std::swap(list[i], list[j]);
//					PrintArr(list, N);
//					--j;
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//
//}

void PrintArr(int* arr, int N)
{
	for (int x = 0; x < N; ++x)
	{
		printf("%i ", arr[x]);
	}
	printf("\n");
}

void QuickSort(int* arr, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = arr[(left+right) / 2];

	while (i <j)
	{
		while (arr[i] < pivot)
			++i;
		while (arr[j] > pivot)
			--j;
		if (i <= j)
		{
			printf("swapping %i and %i\n", arr[i], arr[j]);
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}

	}
	//PrintArr(arr, 10);

	if (left < j)
		QuickSort(arr, left, j);
	if (i < right)
		QuickSort(arr, i, right);

}


void LazyQuickSort(int* arr, int left, int right, int count)
{
	//int i = left;
	//int j = right;
	//int pivot = arr[(left + right) / 2];

	//while (i < j)
	//{
	//	while (arr[i] < pivot)
	//		++i;
	//	while (arr[j] > pivot)
	//		--j;
	//	if (i <= j)
	//	{
	//		printf("swapping %i and %i\n", arr[i], arr[j]);
	//		std::swap(arr[i], arr[j]);
	//		++i;
	//		--j;
	//	}

	//}
	////PrintArr(arr, 10);

	//if (left < j)
	//	QuickSort(arr, left, j);
	//if (i < right)
	//	QuickSort(arr, i, right);

	/*for (int c = 0; c < count; ++c)
	{

	}*/
	int c = 0;
	while (c < count)
	{

		int i = left;
		int j = right;
		int pivot = arr[count];// arr[(left + right) / 2];
		while (i < j)
		{
			while (arr[i] < pivot)
				++i;
			while (arr[j] > pivot)
				--j;
			if (i <= j)
			{
				std::swap(arr[i], arr[j]);
				++i;
				--j;
				
			}
		}
		c++;

	};

}

// lazy sort 
void LS(int* arr, int N, int count)
{
	int* s = arr+0;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] < *s)
			std::swap(arr[i], *s);
	}
	
}

// vs
void LazyQuickSortB(int* arr, int left, int right, int count)
{

	if (count == 0)
		return;
	int i = left;
	int j = right;
	int pivot = arr[(left + right) / 2];

	while (i < j)
	{
		while (arr[i] < pivot)
			++i;
		while (arr[j] > pivot)
			--j;
		if (i <= j)
		{
			printf("swapping %i and %i\n", arr[i], arr[j]);
			std::swap(arr[i], arr[j]);
			PrintArr(arr, 10);
			++i;
			--j;
		}

	}
	//PrintArr(arr, 10);

	// tail recursion issues
	if (left < j)
		return LazyQuickSortB(arr, left, j, --count);
	//no right hand sort?
	if (i < right)
		return LazyQuickSortB(arr, i, right, --count);

	
}

void SimpleLazySort(int * arr, int N, int count)
{
	if (count == 0)
		return;
	int temp = 0; // store the index of the smallest
	for (int i = 1; i < N; ++i) // start at one
	{
		if (arr[temp] > arr[i])
			temp = i;
	}
	if(temp != 0)
		std::swap(arr[temp], arr[0]);

	return SimpleLazySort(arr + 1, --N, --count);
}


int main()
{

	/*std::string hello("Hello world");

	void* ptr = &hello;

	std::string* sptr = static_cast<std::string*>(ptr);
	printf("%s", sptr->c_str());
*/
	int arr[10] = { 10, 4, 8, 7, 5, 1, 6, 3, 9, 2 };
	PrintArr(arr, 10);
	//LazyQuickSortB(arr, 0, 9, 2);// QuickSort(arr, 0, 9);
	SimpleLazySort(arr, 10, 3);
	PrintArr(arr, 10);


	//PrintArr(arr, 10);

	/*int arr[10] = { 10, 4, 2, 7, 5, 1, 6, 3, 9, 8 };
	for (int i = 0; i < 9; ++i)
	QuickSort<int>(arr, 10);



	printf("-----\n Finished : \n");
	for (auto i : arr)
	{
		printf("%i ", i);
	}*/
	printf("\n-----\n");
	//for (int i = 0; i < 10; ++i)
	//{
	//	
	///*	for (auto i : arr)
	//	{
	//		printf("%i ", i);
	//	}
	//	printf("\n");*/
	//	//printf("%i\n", sizeof(arr)/sizeof(arr[0]));
	//	QuickSort<int>(arr, 10);
	//}

	return 0;
}
