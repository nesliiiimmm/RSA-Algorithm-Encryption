#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int gcd(int a, int b)
{
	int temp;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}
int FindD(int fi, int e)
{
	int i;
	for (i = 2; i < fi; i++)
	{
		if (i*e%fi == 1) break;
	}
	return i;
}
int Sifreleme_Cözme(int m, int n, int e){
	int k = 1;
	while (e>0){
		if (e % 2 == 1)
		{
			k = (k*m) % n;
		}
		e = e / 2;
		m = (m*m) % n;
	}
	return k;
}
/*int Asal(int x)//asal sayý olup olmadýðýný belirliyor
{
	int i;
	if (x % 2 == 0)
		return 0;
	for (i = 3; i < x; i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}

int FindE(int fi)//bununla e belirlemek çok fazla uzun sürdüðü için bi e sayýsýný kendimiz seçtik...
int k;
while (1)
{
k = rand() % fi + 2;
if (Asal(k) == 1 && gcd(fi, k) == 1) break;

}
return k;
}
*/

/*int Sifreleme_Cözme(int m,int n,int e)//bu da sifreleme ve çözmeyi saðlar ama bizden istenen
//diðer türlü olduðu için bunu deðil diger fonksiyonu kullanýyoruz
{
int i, k = 1;
for (i = 1; i <= e; i++)
{
k = (k*m) % n;
}
return k;
}*/
int main()
{
	int Asal[10] = { 101, 103, 107, 109, 113, 127, 131, 137, 139, 149 };//100 ile 150 arasýnda 
	int E[20] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73 };//asal sayý bulmak çok zaman aldýðý için bu sayýlarý verdim
	int p, q, n, fi, e, d, c;
	int message;
	srand(time(NULL));
	message = (rand() % 100) + 1;//1 den 100 e kadar bir sayý belirlendi..bunu kullanýcýdanda alabilirdik veya
	p = Asal[rand() % 10];
	while (1)
	{
		q = Asal[rand() % 10];
		if (p != q) break;
	}
	n = p*q;
	fi = (p - 1)*(q - 1);
	printf("p=%d\nq=%d\nn=%d\nphi(n)=%d\n", p, q, n, fi);
	while (1)
	{
		e = E[rand() % 20];
		if (gcd(fi, e) == 1)
			break;
	}
	d = FindD(fi, e);
	printf("public key=(%d,%d)\nprivate key=(%d,%d)\n", n, e, n, d);
	printf("Message:%d\n", message);
	c = Sifreleme_Cözme(message, n, e);
	printf("Encryped Message:%d\n", c);
	c = Sifreleme_Cözme(c, n, d);
	printf("Original Message:%d\n", c);

	return 0;
}