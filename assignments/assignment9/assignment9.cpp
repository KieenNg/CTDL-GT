#include<iostream>
using namespace std;

// giai thuat sap xep chen 
void insertion_sort(int n, int a[])
{
    int temp;
    for(int i=1; i<n; i++)
    {
        temp=a[i];
        int j=i-1;
        while(temp<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

// giai thuat sap xep chon 
void swap(int& x, int& y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void selection_sort(int n, int a[])
{
	for(int i=0; i<n; i++)
	{
	    int min=i;
	    for(int j=i+1; j<n; j++)
		{
		    if(a[j]<a[min]) min=j;
		}
		swap(a[min], a[i]);
	}
}

// giai thuat sap xep noi bot
void burble_sort(int n, int a[])
{
	for(int i=0; i<n-1; i++) 
	{
		for(int j=0; j<n-1; j++)
		{
			if(a[j+1]<a[j]) swap(a[j], a[j+1]);
		}
	}
}

// giai thuat sap xep noi bot cai tien
void bubble_sort_optimized(int n, int a[])
{
    bool swapped; 
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false; 
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true; 
            }
        }
        if (!swapped) break;
    }
}

// giai thuat sap xep nhanh
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; 
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}

// giai thuat sap xep vun dong
void heapify(int arr[], int n, int i)
{
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} 

// giai thuat sap xep tron 
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; 
    int n2 = right - mid;   

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; 

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// giai thuat tim kiem nhi phan
int search_binary(int number, int a[], int first, int last)
{
	int mid=(first+last)/2;
	if(number<a[mid])
	{
		search_binary(number, a, first, mid);
	}
	else if(number>a[mid])
	{
		search_binary(number, a, mid+1, last);
	}
	else return mid;
}

int main()
{
    int a[100];
    int n;
    cout << "Nhap so phan tu trong mang: "; cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    
    /*insertion_sort(n, a);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }*/

    /*selection_sort(n, a);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }*/
    
    /*burble_sort(n, a);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }*/
    
    /*bubble_sort_optimized(n, a);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }*/
    
    /*quick_sort(a, 0, n - 1);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }*/
    
    /*heap_sort(a, n);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }*/
    
    /*merge_sort(a, 0, n - 1);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }*/
    
    /*int index=search_binary(5, a, 0, n-1);
    cout << index;*/
    
    
}


