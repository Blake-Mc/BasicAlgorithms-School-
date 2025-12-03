#include <iostream>

using namespace std;

void menu();
void fill_array(int arr[], int size);
void print_array(int arr[], int size);
int linear_search(int arr[], int size, int key);
void select_sort(int arr[], int size);
void insert_sort(int arr[], int size);
void bubble_sort(int arr[], int size);


int main() {
    int choice;
    int a[9];
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            fill_array(a, 9);
            cout << "Enter the key you want to search: ";
            int key;
            cin >> key;
            int index = linear_search(a, 9, key);
            if (index == -1)
                cout << "The key " << key << " is not in array\n";
            else
                cout << "The key " << key << " is # " << (index + 1) << " element in array\n";
                break;
        }
        case 2:
        {
            fill_array(a, 9);
            select_sort(a, 9);
            cout << "After sort, the array is:\n";
            print_array(a, 9);
            break;
        }
        case 3:
            {
                fill_array(a, 9);
                insert_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
        case 4:
        {
            fill_array(a, 9);
            bubble_sort(a, 9);
            cout << "After sort, the array is:\n";
            print_array(a, 9);
            break;
        }
        case 5:
        {
            cout << "Thank you for using the array functions\n";
            break;
        }
        default:
        {
            cout << "Wrong choice. Please choose from menu: ";
            break;
        }
        }
    } while (choice != 5);
    return 0;
}

void menu()
{
    cout << "\nArray Function Menu:\n";
    cout << "1. Linear Search\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Bubble Sort\n";
    cout << "5. Exit\n";
}
//iterates through the array prompting the user to to enter each element
void fill_array(int arr[], int size)
{
    cout << "enter " << size << " elements\n";
    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void print_array(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

//goes down the list one at a time
//O(n)
int linear_search(int arr[], int size, int key)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
	return -1;
}

//finds the smallest element at puts it at the front of the unsorted part
//O(n^2)
void select_sort(int arr[], int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        int min = i;
        for (size_t n = i + 1; n < size; n++)
        {
            if (arr[n] < arr[min])
            {
                min = n;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

//builds a sorted array by taking each item and putting it in the correct place amongst the already sorted elements
//O(n^2)
void insert_sort(int arr[], int size)
{
    for (size_t i = 1; i < size; i++)
    {
        int key = arr[i];
        int n = i-1;
        while (n >= 0 && arr[n] > key)
        {
            arr[n + 1] = arr[n];
            n--;
        }
        arr[n + 1] = key;
    }
}

//sort the array by checkign each pair and swaping it based on which is larger and repeating through the array until it's all sorted
//O(n^2)
void bubble_sort(int arr[], int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t n = 0; n < size - i - 1; n++)
        {
            if (arr[n] > arr[n+1])
            {
                int temp = arr[n];
                arr[n] = arr[n + 1];
                arr[n + 1] = temp;
            }
        }
    }
}
