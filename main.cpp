#include <iostream>


void merge(int arr[],int start, int end, int mid);

void mergeSort(int arr[], int start, int end)
{
	// int mid;
	// if (start < end){
	// 	mid=(start+end)/2;
	// 	mergeSort(arr, start, mid);
	// 	mergeSort(arr, mid+1, end);
	// 	merge(arr,start,end,mid);
	// }
	_asm {
		lea esi, arr // esi = &arr
		mov eax, start // eax = start
		mov ebx, end // ebx = end
		cmp eax, ebx // if (start < end)

		jge endMergeSort // jump to endMergeSort

		mov ecx, eax // ecx = start
		add eax, ebx // eax = start + end
		shr eax, 1 // eax = (start + end) / 2

		push eax // push mid
		push ecx // push start
		push esi // push &arr
		call mergeSort // mergeSort(arr, start, mid)
		add esp, 12 // pop 3 parameters

		push ebx // push end
		inc eax // mid + 1
		push eax // push mid + 1
		push esi // push &arr
		call mergeSort // mergeSort(arr, mid + 1, end)
		add esp, 12 // pop 3 parameters

		dec eax // mid
		push eax // push mid
		push ebx // push end
		push ecx // push start
		push esi // push &arr
		call merge // merge(arr, start, end, mid)
		add esp, 16 // pop 4 parameters

		endMergeSort:
	}
}

void merge(int arr[],int start, int end, int mid)
{
	int mergedarr[8];
	int i, j, k;
	i = start;
	k = start;
	j = mid + 1;
	
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			mergedarr[k] = arr[i];
			k++;
			i++;
		}
		else {
			mergedarr[k] = arr[j];
			k++;
			j++;
		}
	}
	
	while (i <= mid) {
		mergedarr[k] = arr[i];
		k++;
		i++;
	}
	
	while (j <= end) {
		mergedarr[k] = arr[j];
		k++;
		j++;
	}
	
	for (i = start; i < k; i++) {
		arr[i] = mergedarr[i];
	}
}

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;
    int* arr = new int[size];
    std::cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
