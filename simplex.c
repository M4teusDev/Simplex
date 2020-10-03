#include <stdio.h>
#include <stdlib.h>

int  readMatrix(char *path, int **data);
void aloca(int **p, int tam);
int  qtdVariaveis(char *path);
int  qtdLinhas(char *path);
void inicializa_matriz(int lin, int col, float m[lin][col]);

int main ( void )
{
  char file[100] = "exemplo.txt";
  int *m = NULL, i = 0, tam_aloc, variaveis = 0, colunas = 0, linhas = 0, j = 0;
  tam_aloc  = readMatrix(file, &m);
  variaveis = qtdVariaveis(file);
  colunas = variaveis * 2 + 2;
  linhas    = variaveis + 1;

  float matriz[linhas + 1][colunas];

  inicializa_matriz(linhas + 1, colunas, matriz);
}

int readMatrix(char *path, int **data)
{
    FILE *file;
    file = fopen(path, "r");
    int aux = 0, tam_aloc = 0;

    if (file == NULL) {
        fprintf(stderr, "error: while trying to open `%s' for reading\n", path);
        return; //
    }
    
    while (fscanf(file, "%d ", &aux) == 1) {
      aloca(data, ++tam_aloc);
      *(*data + tam_aloc - 1) = aux;
    }

    fclose(file);
    return tam_aloc;
}

void aloca(int **p, int tam){

  if( (*p = (int *)realloc( *p ,tam * sizeof(int))) == NULL) {
        printf("Estamos sem memoria...");
        exit(1);
    }
}

int qtdVariaveis(char *path)
{
  FILE *file;
  int cont = 0, i = 0;
  char c, *result, linha[100];

  if ((file = fopen(path, "r")) == NULL)
      exit(1); 

  fread (&c, sizeof(char), 1, file);
  result = fgets(linha, 100, file);

  for(i = 0; i < strlen(linha); i++)
    if( *(result + i) == ' ')
      cont++;
    
  fclose(file);
  return cont + 1;
}

void inicializa_matriz(int lin, int col, float m[lin][col]) 
{
  int i = 0, j = 0;
  for(i = 0; i < lin; i++) {
    for(j = 0; j < col; j++){
      m[i][j] = 0.0;
    }
    printf("\n");
  }

}

// void monta_matriz(int lin, int col, float m[lin][col], int variaveis, int *p, int tam_aloc)
// {
//   for(i = variaveis; i < tam_aloc; i++)
//   {
//     printf("oi");
//   }
// }
