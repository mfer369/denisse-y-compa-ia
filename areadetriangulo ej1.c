#include<stdio.h>

int main() {
	float altura;
	float area;
	float base;
	printf("ingresa la base del triangulo\n");
	scanf("%f",&base);
	printf("ingresa la altura del triangulo\n");
	scanf("%f",&altura);
	area = (base*altura)/2;
	if (area>0) {
		printf("el area del triangulo es:%f\n",area);
	} else {
		printf("numeros ingresados son negatigvos\n");
	}
	return 0;
}

