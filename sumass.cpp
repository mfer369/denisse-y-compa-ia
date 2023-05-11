#include<stdio.h>

main() 
{

int sumar,n1,n2;
char escribe[50];

printf("escribe un numero");
scanf("%d",&n1);
printf("escribe otro numero");
scanf("%d",&n2);
sumar=n1+n2;
printf("escribe tu texto");
scanf("%s",&escribe);
printf("tu resultado es %d    ",sumar);

getchar();
getchar();
}

