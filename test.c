#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// criação do struct para a lista duplamente encadeado
typedef struct Node
{
  char nome[150];
  char sexo[2]; // fiz o teste com [1] e ele nao salvou totalmente, pois imagino q o 1 byte seja do espaço '\0'
  float salario;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct List
{
  struct Node *head; // Ponteiro para o primeiro nó da lista
  struct Node *tail; // Ponteiro para o último nó da lista
} List;

// criando o Nó
Node *createNode(float salario, char *sexo, char *nome)
{
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (newNode == NULL)
  {
    printf("Não foi possivel criar o No");
  }

  strcpy(newNode->nome, nome);
  strcpy(newNode->sexo, sexo);
  newNode->salario = salario;

  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;
}

void insertOrder(List *list, Node *no)
{
  // verificando se a lista está vazia
  if (!list->head)
  {
    // se estiver vazio ele preenche com o valor do No e retorna
    list->head = list->tail = no;
    return;
  }

  Node *current = list->head;
  while (current && strcmp(no->nome, current->nome) > 0)
  {
    current = current->next;
  }

  /** current
   * Se o current for Null significa que chegou ao final da lista, e então o "NO" pode ser inserido apos o ultimo
   * e utilizamos variavel de ponteiro auxiliar para adicionar o no a ultima posição da lista;
   */
  if (!current)
  {
    list->tail->next = no;
    no->prev = list->tail;
    list->tail = no;
  }
  else
  {
    /** se não for null o "NO" deve ser inserido antes, ou seja ser adicionado ao meio da lista
     * ou em outra posição especifica
     */
    no->next = current;
    no->prev = current->prev;

    /* verificando os "Nos" anteriores para seguir o fluxo de add na lista
     * Se current->prev não for NULL : se atualiza o ponteiro "Next".
     * Caso contrario ele cai no Else, e o "No" se torna o novo Head(cabeça) da Lista
     */
    if (current->prev)
    {
      current->prev->next = no;
    }
    else
    {
      list->head = no;
    }
    // Ajusta o ponteiro para o proximo "No";
    current->prev = no;
  }
}

void readFile(const char *arquivo, List *list)
{
  // cria a variavel para ler o arquivo
  FILE *item = fopen(arquivo, "r");
  char c[256]; // variavel char para ler cada linha do arquivo
  char resultado[150];
  char column2[20];
  /**
   * Verificando se o arquivo foi lido com sucesso, se não ele fecha o programa totalmente
   */
  if (item == NULL)
  {
    printf("Erro ao abrir arquivo!\n");
    exit(1);
  }

  while (fgets(c, sizeof(c), item))
  {
    c[strcspn(c, "\n")] = 0;

    // Usamos strtok para dividir a linha em partes
    char *nome = strtok(c, " "); // Pega a primeira parte (nome)
    char sexo[2];
    float salario = 0.0;
    // Agora precisamos pegar o restante da linha
    char *resto = strtok(NULL, "");
    if (resto != NULL)
    {
      /** Pega o resto da string
       * pega o sobrenome da string
       */
      char *result = strtok(resto, " ");
      /** strcat documentation
       * - Poderia usar esse strcat para juntar as strings, porém para ter espaço no meio teria que adicionar outro strcat antes com espaço.
       * - strcat(nome, " ");
       * - strcat(nome, result);
       */
      sprintf(resultado, "%s %s", nome, result);

      char *n1 = strtok(NULL, " \t");
      sexo[0] = n1[0]; // Armazena o caractere do sexo
      sexo[1] = '\0';
      strcpy(column2, n1 + 1);
      salario = atof(column2);
      // Vamos tentar separar o sexo e o salário
      // concatena o restante do nome:
    }

    Node *no = createNode(salario, sexo, resultado);
    insertOrder(list, no);
  }

  // limpa os dados ao terminar de ler
  fclose(item); // Fechar o arquivo
}

/** Reordenando a lista em crescente
 * A função abaixo reordena todos os elementos em ordem Crescente percorrendo a Lista
 */
void ordenarCrescente(List *list)
{
  printf("Mostrando dados em ordem crescente...\n");
  Node *current = list->head;
  while (current)
  {
    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s\nSexo: %s\nSalario: %.2f\n", current->nome, current->sexo, current->salario);
    current = current->next;
  }
  printf("-----------------------------------------------------------------");
}
void ordenarDecrescente(List *list)
{
  printf("Mostrando dados em ordem decrescente...\n");
  Node *current = list->tail;
  while (current)
  {
    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s\nSexo: %s\nSalario: %.2f\n", current->nome, current->sexo, current->salario);
    current = current->prev;
  }

  printf("-----------------------------------------------------------------");
}

int main()
{
  struct List lista = {NULL, NULL};
  int numMenu = 0;

  readFile("file example - ed", &lista);

  printf("1 - mostrar dados em ordem crescente\n");
  printf("2 - mostrar dados em ordem decrescente\n");

  scanf("%d", &numMenu);

  switch (numMenu)
  {
  case 1:
    ordenarCrescente(&lista);
    break;

  case 2:
    ordenarDecrescente(&lista);
    break;

  default:
    printf("Opção invalida!\n");
    break;
  }

  return 0;
}
