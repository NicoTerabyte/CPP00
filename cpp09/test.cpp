#include <iostream>
#include <vector>

// Funzione di merge che combina due sottovettori ordinati
void merge(std::vector<int>& vec, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (int i = 0; i < n1; i++)
	{
		L[i] = vec[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = vec[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			vec[k] = L[i];
			i++;
		}
		else
		{
			vec[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		vec[k] = L[i];
		i++;
		k++;
	}

	// Copia gli elementi rimanenti di R[]
	while (j < n2)
	{
		vec[k] = R[j];
		j++;
		k++;
	}
}

// Funzione principale che implementa il merge sort
void mergeSort(std::vector<int>& vec, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		// Ordina la prima metà
		mergeSort(vec, left, mid);

		// Ordina la seconda metà
		mergeSort(vec, mid + 1, right);

		// Unisci le due metà ordinate
		merge(vec, left, mid, right);
	}
}

int main()
{
	std::vector<int> vec = {38, 27, 43, 3, 9, 82, 10};

	std::cout << "Vettore originale: ";
	for (int num : vec)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	mergeSort(vec, 0, vec.size() - 1);

	std::cout << "Vettore ordinato: ";
	for (int num : vec)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}
