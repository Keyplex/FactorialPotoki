#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>

VOID Factr(VOID);
DWORD WINAPI TreadFactr(LPVOID param);
DWORD WINAPI TreadFactr1(LPVOID param);

int n = 10;
int main(int argc, char* args[])
{
	TreadFactr(0);
	return 0;
}

VOID Factr(VOID)
{
	HANDLE hF[2];
	hF[0] = CreateThread(NULL, 0, TreadFactr, NULL, 0, 0);
	hF[1] = CreateThread(NULL, 0, TreadFactr1, NULL, 0, 0);
	WaitForMultipleObjects(2, hF, TRUE, INFINITE);
}

DWORD WINAPI TreadFactr(LPVOID param)
{
	int f = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			f = 1;
		}
		else
		{
			f *= i;
		}
		printf("factorial %d = %d\n", i, f);
	}
	ExitThread(0);
}

DWORD WINAPI TreadFactr1(LPVOID param)
{
	int f = 0;
	int f1 = 1;
	int f2 = 1;
	for (int i = 0; i <= n; i++)
	{
		if (i > 2)
		{
			f = 1;
			f1 = f2;
			f2 += f;
		}		
		printf("%d element Fibonachi %d \n", i, f2);
	}
	ExitThread(0);
}