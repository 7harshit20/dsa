#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void merge(int a[], int b[], int n, int m)
{
	int num = 0, p1 = 0, p2 = 0, i = 0;
	for (int j = 0; j < n; j++)
	{
		num = max(num, a[j]);
	}
	for (int j = 0; j < m; j++)
	{
		num = max(num, b[j]);
	}
	num = max(num, n);
	num = max(num, m);
	num++;
	while (p1 < n && p2 < m)
	{
		if (a[p1] > b[p2])
		{
			b[p2] = (b[p2] + (i * num));
			p2++;
		}
		else
		{
			a[p1] = (a[p1] + (i * num));
			p1++;
		}
		i++;
	}
	// cout<<"one"<<endl;
	while (p2 < m)
	{
		b[p2] = (b[p2] + (i * num));
		p2++;
		i++;
	}
	// cout<<"sec"<<endl;
	while (p1 < n)
	{
		a[p1] = (a[p1] + (i * num));
		p1++;
		i++;
	}
	// cout<<"third"<<endl;
	i = 0;
	while (i < n)
	{
		if ((a[i] / num) == i)
		{
			i++;
			continue;
		}
		if ((a[i] / num) < n)
		{
			swap(&a[i], &a[a[i] / num]);
		}
		else
		{
			swap(&a[i], &b[(a[i] / num) - n]);
		}
	}
	// cout<<"foutth"<<endl;
	i = 0;
	while (i < m)
	{
		if ((b[i] / num) == i + n)
		{
			i++;
			continue;
		}
		if ((b[i] / num) < n)
		{
			swap(&b[i], &a[b[i] / num]);
		}
		else
		{
			swap(&b[i], &b[(b[i] / num) - n]);
		}
	}
	i = 0;
	while (i < n + m)
	{
		if (i < n)
		{
			a[i] = a[i] % num;
		}
		else
		{
			b[i - n] %= num;
		}
		i++;
	}
	// cout<<"five"<<endl;
}

int main()
{
	int n, m;
	int arr1[] = {1, 3, 5, 9};
	int arr2[] = {2, 4, 6, 7, 8};
	merge(arr1, arr2, 4, 5);
	for (int i = 0; i < 4; i++)
	{
		cout << arr1[i] << " ";
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << " ";
	}
	return 0;
}