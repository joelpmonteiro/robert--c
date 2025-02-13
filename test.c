#include <stdio.h>
#include <stdlib.h>

void fn1() { printf("Mostrando dados em ordem crescente...\n"); }
void fn2() { printf("Mostrando dados em ordem decrescente...\n"); }

void menuItem()
{
  int numMenu = 0;
  printf("1 - mostrar dados em ordem crescente\n");
  printf("2 - mostrar dados em ordem decrescente\n");

  scanf("%d", &numMenu);

  switch (numMenu)
  {
  case 1:
    fn1();
    break;

  case 2:
    fn2();
    break;

  default:
    break;
  }

  // Codigo para adicionar uma repetição do codigo menu ao parar a programação normal do codigo
  //  while (numMenu != 1 && numMenu != 2)
  //  {
  //    // ler o valor do numero

  // }
}

int main()
{
  menuItem();
  return 0;
}
