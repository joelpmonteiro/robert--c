#include <stdio.h>
#include <stdlib.h>

// criação do struct para a lista duplamente encadeado
struct List
{
  char nome[150];
  char sexo[1];
  int salario;
  struct Node *head;
  struct Node *tail;
};

void readFile(const char *arquivo)
{
  // cria a variavel para ler o arquivo
  FILE *item = fopen(arquivo, "r");
  char c; // variavel char para ler cada linha do arquivo

  /**
   * Verificando se o arquivo foi lido com sucesso, se não ele fecha o programa totalmente
   */
  if (item == NULL)
  {
    printf("Erro ao abrir arquivo!\n");
    exit(1);
  }

  /*
   *Essa linha e responsavel por ler cada linha do arquivo ate o final
   */
  while ((c = fgetc(item)) != EOF)
  {
    printf("%c", c);
  }

  // limpa os dados ao terminar de ler
  free(item);
  // depois aqui fecha o arquivo depois de terminar de ler tudo.
  fclose(item); // Fechar o arquivo
}

void fn1()
{
  printf("Mostrando dados em ordem crescente...\n");
  readFile("file example - ed");
}
void fn2()
{
  printf("Mostrando dados em ordem decrescente...\n");
  readFile("file example - ed");
}

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
