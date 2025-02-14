#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// criação do struct para a lista duplamente encadeado
struct Node
{
  char nome[150];
  char sexo[2]; // fiz o teste com [1] e ele nao salvou totalmente, pois imagino q o 1 byte seja do espaço '\0'
  int salario;
  struct Node *prev;
  struct Node *next;
};

struct List
{
  struct Node *head; // Ponteiro para o primeiro nó da lista
  struct Node *tail; // Ponteiro para o último nó da lista
};

void readFile(const char *arquivo, struct List *list)
{
  // cria a variavel para ler o arquivo
  FILE *item = fopen(arquivo, "r");
  char c[256]; // variavel char para ler cada linha do arquivo
  // char nome[150], sexo[2];
  // int salario;

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
  // while ((c = fgetc(item)) != EOF)
  // {
  //   printf("%c", c);
  // }

  while (fgets(c, sizeof(c), item))
  {
    // printf(c);
    c[strcspn(c, "\n")] = 0;

    // Usamos strtok para dividir a linha em partes
    char *nome = strtok(c, " "); // Pega a primeira parte (nome)
    char *sexo = NULL;
    char *salario_str = NULL;
    int salario = 0;

    // Agora precisamos pegar o restante da linha
    char *resto = strtok(NULL, "");
    if (resto != NULL)
    {
      // Vamos tentar separar o sexo e o salário
      sexo = strtok(resto, " \t");
      salario_str = strtok(NULL, " \t");

      // Se conseguimos pegar o sexo e o salário, convertemos o salário para int
      if (sexo != NULL && salario_str != NULL)
      {
        salario = atoi(salario_str);
      }
    }

    if (nome != NULL && sexo != NULL && salario > 0)
    {
      printf("Nome: %s\n", nome);
      printf("Sexo: %s\n", sexo);
      printf("Salário: %d\n", salario);

      
    }
    else
    {
      printf("Erro ao processar linha: %s\n", c);
    }
  }

  // limpa os dados ao terminar de ler
  // free(item);
  // depois aqui fecha o arquivo depois de terminar de ler tudo.
  fclose(item); // Fechar o arquivo
}

void fn1()
{
  printf("Mostrando dados em ordem crescente...\n");
  // readFile("file example - ed");
}
void fn2()
{
  printf("Mostrando dados em ordem decrescente...\n");
  // readFile("file example - ed");
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
  struct List lista = {NULL, NULL};

  readFile("file example - ed", &lista);
  // menuItem();
  return 0;
}
