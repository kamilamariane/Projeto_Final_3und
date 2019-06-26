#include<stdio.h>
#include<stdlib.h>

int linhaA = 0, colunaA = 0; //para receber os parâmetros da matriz A
int linhaB = 0, colunaB = 0; //para receber os parâmetros da matriz B
int linhaC = 0, colunaC = 0; //para receber os parâmetros da matriz C
int matrizA[50][50]; //50 foi definido como o limite de todas as matrizes
int matrizB[50][50];
int matrizC[50][50]; //matriz resultante 
char arquivoA[20];
char arquivoB[20];
//ponteiros para os arquivos

FILE *fileout;
FILE *file;

int escolha(int numero)
{
	switch (numero)
	{
		case 1:
			//define os parâmetros da matriz B

			printf("Quantidade linhas da matriz A: ");
			scanf("%d", &linhaA); //recebe do usuario o numero de linhas da matriz A

			printf("Quantidade de colunas da matriz A: ");
			scanf("%d", &colunaA); //recebe do usuario o numero de colunas da matriz A

			break;

		case 2:
			//define os parâmetros da matriz B

			printf("Quantidade linhas da matriz B: ");
			scanf("%d", &linhaB); //recebe do usuario o numero de linhas da matriz B

			printf("Quantidade de colunas da matriz B: ");
			scanf("%d", &colunaB); //recebe do usuario o numero de colunas da matriz B

			break;

		case 3:
			//estrutura de repetição para percorrer a matriz A

			for (int i = 0; i < linhaA; i++)
			{ //percorre as linhas de A
				for (int j = 0; j < colunaA; j++)
				{ //percorre as colunas de A
					{
						matrizA[i][j] = rand() % 99; //preenche o elemento ij com um numero aleatorio
					}
				}
			}

			break;

		case 4:
			//estrutura de repetição para percorrer a matriz B

			for (int i = 0; i < linhaB; i++)
			{ //percorre as linhas de B
				for (int j = 0; j < colunaB; j++)
				{ //percorre as colunas de B
					{
						matrizB[i][j] = rand() % 99; //preenche o elemento ij com um numero aleatorio
					}
				}
			}
			break;

		case 5:
			//atribui manualmente os valores da matriz A

			printf(" \nDigite os valores da matriz A \n\n");
			for (int i = 0; i < linhaA; i++)
			{ //percorre as linhas de A
				for (int j = 0; j < colunaA; j++)
				{ //percorre as colunas de A
					{
						printf("Elemento[%d][%d]:", i, j); //pede ao usuário o elemento ij
						scanf("%d", &matrizA[i][j]); //lê do usuário o elemento ij
					}
				}
			}
			break;

		case 6:
			//atribui manualmente os valores da matriz B

			printf(" \nDigite os valores da matriz B \n\n");
			for (int i = 0; i < linhaB; i++)
			{ //percorre as linhas de B
				for (int j = 0; j < colunaB; j++)
				{ //percorre as colunas de B
					{
						printf("Elemento[%d][%d]:", i, j); //pede ao usuário o elemento ij
						scanf("%d", &matrizB[i][j]); //lê do usuário o elemento ij
					}
				}
			}
			break;

		case 7:
			//calcula a soma das matrizes A e B

			if (linhaA == linhaB && colunaA == colunaB)
			{
				for (int i = 0; i < linhaA; i++)
				{ //percorre as linhas de A
					for (int j = 0; j < colunaA; j++)
					{ //percorre as colunas de A
						matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
						//soma o elemento ij de A com o elemento ij de B e transcreve em ij de C

					}
				}
				linhaC = linhaA;
				colunaC = colunaA;
			}
			else
			{
				printf("Não é possivel somar as matrizes inseridas\n");
			}

			break;

		case 8:
			//calcula a subtração das matrizes A e B

			if (linhaA == linhaB && colunaA == colunaB)
			{
				for (int i = 0; i < linhaA; i++)
				{ //percorre as linhas de A
					for (int j = 0; j < colunaA; j++)
					{ //percorre as colunas de A
						matrizC[i][j] = matrizA[i][j] - matrizB[i][j];
						//subtrai o elemento ij de A com o elemento ij de B e transcreve em ij de C
					}
				}
				linhaC = linhaA;
				colunaC = colunaA;
			}
			else
			{
				printf("Não é possivel subtrair as matrizes inseridas\n");
			}
			break;

		case 9:
			//calcula o produto entre as matrizes A e B

			if (linhaA != colunaB)
			{
				/*se a linha de A for diferente da coluna de B 
				   nao é possivel multiplicar*/
				printf("\n \t Não é possivel multiplicar as matrizes \n");
			}
			for (int i = 0; i < linhaA; i++)
			{ //percorre todas as linhas de A  
				for (int j = 0; j < colunaB; j++)
				{ //percorre as colunas de A
					int somaprod = 0;
					/*zera a variavel que recebe o produto dos 
					  elementos cada vez que passa no loop para evitar q 
					  resultados anteriores atrapalhem*/
					for (int k = 0; k < linhaA; k++)
					{
						/*o contador k percorre 
						      a linha i de A a ser multiplicada pela coluna j de B*/
						somaprod += matrizA[i][k] *matrizB[k][j];
						/*aqui se multiplica os elementos linha x coluna das matrizes
						        e o resultado é guardado na variavel somaprod*/
						matrizC[i][j] = somaprod;
						/*resultado somaprod guardado 
						        no elemento ij da matriz C*/
					}
				}
			}
			linhaC = linhaA;
			colunaC = colunaB;
			break;

		case 10:
			//imprime a matriz A

			printf("\n A matriz A é: \n");
			for (int i = 0; i < linhaA; i++)
			{ //percorre as linhas de A
				for (int j = 0; j < colunaA; j++)
				{ //percorre as colunas de A
					printf("%4.1d", matrizA[i][j]); //imprime o elemento ij 
				}
				printf("\n");
				/*separa os elementos em cada passagem por
				     fins estéticos*/
			}
			break;

		case 11:
			//imprime a matriz B

			printf("\n A matriz B é: \n");
			for (int i = 0; i < linhaB; i++)
			{ //percorre as linhas de B
				for (int j = 0; j < colunaB; j++)
				{ //percorre as colunas de B
					printf("%4.1d", matrizB[i][j]); //imprime o elemento ij
				}
				printf("\n");
				/*separa os elementos em cada passagem por
				     fins estéticos*/
			}
			break;

		case 12:
    //imprime a matriz C
      printf ("\nA matriz resultante C é:\n");
			for (int i = 0; i < linhaC; i++)
			{ //percorre as linhas de B
				for (int j = 0; j < colunaC; j++)
				{ //percorre as colunas de B
					printf("%4.1d", matrizC[i][j]); //imprime o elemento ij
				}
				printf("\n");
				/*separa os elementos em cada passagem por
				     fins estéticos*/
			}
			break;

		case 13:
			//ler matriz A de um arquivo

			printf("Matrizes A disponiveis em arquivos:\n"
				"TipoA_3x4.txt \n"
				"TipoA_4x3.txt \n"
				"TipoA_5x5.txt \n"
				"\n");
			printf("A pasta em que se encontra os arquivos é Arquivos_A \n ");
			printf("Siga o modelo abaixo para escolher a matriz desejada:\n "
				"Arquivo_A/TipoA_numeroxnumero.txt \n\n");
			printf("Digite o tipo da matriz A disponivel em arquivo: \n");
			scanf("%s", arquivoA); //scaneia o nome do arquivo

			file = fopen(arquivoA, "r"); //coloca ela aqui p ser lida e aberta

			fscanf(file, "%d %d", &linhaA, &colunaA);
			/*le o numero de colunas
			   e linhas do arquivo*/

			for (int i = 0; i < linhaA; i++)
			{
				for (int j = 0; j < colunaA; j++)
				{
					fscanf(file, "%d", &matrizA[i][j]);
					/*le do do aquivo o 
					      elemento ij e transcreve em A*/
				}
			}
			printf("\nA matriz escolhida foi: \n");
			for (int i = 0; i < linhaA; i++)
			{
				for (int j = 0; j < colunaA; j++)
				{
					printf("%2d ", matrizA[i][j]);
				}
				printf("\n");
			}
			fclose(file);
			break;

		case 14:
			//ler matriz B de um arquivo
      
			printf("Matrizes A disponiveis em arquivos:\n"
				"TipoB_3x4.txt \n"
				"TipoB_4x3.txt \n"
				"TipoB_5x5.txt \n"
				"\n");
			printf("A pasta em que se encontra os arquivos é Arquivos_B\n ");
			printf("Siga o modelo abaixo:\n "
				"Arquivos_B/TipoB_numeroxnumero.txt \n\n");
			printf("Digite o tipo da matriz A disponivel em arquivo: \n");
			scanf("%s", arquivoB); //scaneia o nome do arquivo

			file = fopen(arquivoB, "r"); //coloca ela aqui p ser lida e aberta

			fscanf(file, "%d %d", &linhaB, &colunaB);
			/*le o numero de colunas
			   e linhas do arquivo*/

			for (int i = 0; i < linhaB; i++)
			{
				for (int j = 0; j < colunaB; j++)
				{
					fscanf(file, "%d", &matrizB[i][j]);
					/*le do do aquivo o 
					      elemento ij e transcreve em B*/
				}
			}
			printf("\nA matriz escolhida foi: \n"); //imprime a matriz
			for (int i = 0; i < linhaB; i++)
			{
				for (int j = 0; j < colunaB; j++)
				{
					printf("%2d ", matrizB[i][j]);
				}
				printf("\n");
			}
			fclose(file);
			break;

		case 15:
    //escrever matriz C em um arquivo
    
			fileout = fopen("Arquivo_C/matrizC.txt", "w");//abre o arquivo

			fprintf(fileout, "%d %d\n", colunaC, linhaC);/*escreve no arquivo numero de linhas e colunas*/

			for (int i = 0; i < linhaC; i++)
			{
				for (int j = 0; j < colunaC; j++)
				{
					{
						fprintf(fileout, "%4.1d", matrizC[i][j]);//imprime no arquivo a matriz C
					}
				}
				fprintf(fileout, "\n");//espaçamento entre coluna
			}
			printf("Matriz C salva em um arquivo com sucesso!");
			break;

		default:

			break;
	}
	return 0;
}
