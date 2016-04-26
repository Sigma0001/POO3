#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>

using namespace std;
int *lista;

void Arreglo(int valor, int *size, int **lista)
{
	int _size = *size;
	_size++;
	int *temp = (int*)realloc(*lista, _size * sizeof(int));
	if (temp != NULL)
	{
		*lista = temp;
		(*lista)[(*size)] = valor;
		*size = _size;
	}
	else
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
}


void Burbuja()
{
	int i, j, temp;
	int n = 1;
	int *numeros = new int[n];

	std::cout << "Ingresa cantidad de parametros." << std::endl;
	{
		std::cout << "Cantidad.-";
		std::cin >> n;

	}


	std::cout << "Ingresa parametros." << std::endl;
	{
		for (i = 0; i < n; i++)
		{
			std::cout << i + 1 << ".-";
			std::cin >> numeros[i];

		}

	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (numeros[j] < numeros[i])
			{
				temp = numeros[j];
				numeros[j] = numeros[i];
				numeros[i] = numeros[j];
				numeros[i] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		std::cout << numeros[i] << " ";
	}
}

void Quicksort(int* arr, int izq, int der)
{
	int i = izq, j = der, tmp;
	int p = arr[(izq + der) / 2];

	while (i <= j)
	{
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++; j--;
		}
	}

	if (izq < j)
		Quicksort(arr, izq, j);
	if (i < der)
		Quicksort(arr, i, der);
}

void ShellSort()
{
	int i, j, temp;
	int n = 1;
	int *numeros = new int[n];

	std::cout << "Ingresa cantidad de parametros." << std::endl;
	{
		std::cout << "Cantidad.-";
		std::cin >> n;

	}


	std::cout << "Ingresa parametros." << std::endl;
	{
		for (i = 0; i < n; i++)
		{
			std::cout << i + 1 << ".-";
			std::cin >> numeros[i];

		}

		int k, e, increment, tempo, number_of_elements = n;
		for (increment = number_of_elements / 2; increment > 0; increment /= 2)
		{
			for (k = increment; k < number_of_elements; k++)
			{
				tempo = numeros[k];
				for (e = k; e >= increment; e -= increment)
				{
					if (tempo < numeros[e - increment])
					{
						numeros[e] = numeros[e - increment];
					}
					else
					{
						break;
					}
				}
				numeros[e] = tempo;
			}
		}

		for (int i1 = 0; i1 < n; i1++)
		{
			cout << numeros[i1] << " ";
		}
	}
}

int main()
{
		//clock_t t;
		//t = clock();

	int input;

	
	cout << "1.Burbuja\n";
	cout << "2.ShellSort\n";
	cout << "3.QuickSort\n";
	cout << "Que algoritmo usar?\n";
	cin >> input;
	switch (input) {
	case 1:
		Burbuja();
		break;

	case 2:
		ShellSort();
		break;

	case 3:

		int i, j, temp;
		int n = 1;
		int *numeros = new int[n];

		std::cout << "Ingresa cantidad de parametros." << std::endl;
		{
			std::cout << "Cantidad.-";
			std::cin >> n;

		}


		std::cout << "Ingresa parametros." << std::endl;
		{
			for (i = 0; i < n; i++)
			{
				std::cout << i + 1 << ".-";
				std::cin >> numeros[i];

			}

			Quicksort(numeros, 0, n);

			for (int k = 0; k < n; k++)
				cout << numeros[k + 1] << " ";
			break;
		}
	}



		//t = clock() - t;
		//std::cout <<  "\nTiempo de calculo: " << ((float)t) / CLOCKS_PER_SEC << "s" << std::endl;
	
return 0;
}

