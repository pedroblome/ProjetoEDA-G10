#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------- UNIVERSIDADE DE BRASILIA - CAMPUS FGA -------------------------------------------//
//                                                   estrutura de dados e algoritmos                                             //
// GRUPO 10:
// Joao Pedro Alves Machado - 212028197
// Mayara Alves de OLiveira - 200025058         
//-------------------------------------------------------------------------------------------------------------------------------//


// Criando Menu de decisões

int menu(){
	char  localArchive[100];
	int length_palavra;
	int maior_comprimento;
	int qtde_palavra;
	int qntd_doc = 0;
	int qntd_voc;
	int lim;
	int lenString;
	
	int option = 0;
	while(option != 5){
		printf("---------------------------------------------------------------");
		printf("------------------------------- Menu --------------------------\n");
		printf("Bem-Vindo ao menu de opções de avaliação do Trip Adivisor.");
		printf("Insira a opção desejada: \n");
        printf("1 - Ler o dataset do Trip Adivisor.\n");
        printf("2 - Gerar vocabulario.\n");
        printf("3 - Exibir TF-IDFs.\n");
        printf("4 - Exibir TF-IDF de uma Nota. Em ordem decrescente de valor de TF-IDF.\n");
        printf("5 - Sair\n");
        printf("---------------------------------------------------------------\n");
        scanf("%d",&option);
        
        // Criando modo leitura do data set//

        if(option==1){
			printf("---------------------------------------------------------------");
        	printf("Por favor insira o nome do arquivo:\n");
        	scanf("%s", &localArchive);
        	printf("%s \n", &localArchive);
        	
        	FILE *origin;
        	FILE *Nota1;
        	FILE *Nota2;
        	FILE *Nota3;
        	FILE *Nota4;
        	FILE *Nota5;
        	
            Nota1 = fopen("files/Nota1.txt","w");
		    Nota2 = fopen("files/Nota2.txt","w");
		    Nota3 = fopen("files/Nota3.txt","w");
		    Nota4 = fopen("files/Nota4.txt","w");
		    Nota5 = fopen("files/Nota5.txt","w");

        	origin = fopen(localArchive, "r");
        	if(origin == NULL){
        		printf("não foi possível acessar o arquivo.\n");
			}if(Nota1 == NULL){
        		printf("não foi possível acessar o arquivo.\n");
			}if(Nota2 == NULL){
        		printf("não foi possível acessar o arquivo.\n");
			}if(Nota3 == NULL){
        		printf("não foi possível acessar o arquivo.\n");
			}if(Nota4 == NULL){
        		printf("não foi possível acessar o arquivo.\n");
			}if(Nota5 == NULL){
        		printf("não foi possível acessar o arquivo.\n");
			}
        	
			char reader[1000000];
			char *pointer;
			char line;
			char review;
			int i = 0;
			
			while(fgets(reader, 1000000, origin) != NULL){
				if(i>0){
				
					pointer = strtok(reader, "\"");
					line = *pointer ;
			
					pointer = strtok(NULL, ",");
					review = *pointer;
					//writing the information in the data;s
					if(review=='1'){
						fputs(reader, Nota1);
						fputs("\n", Nota1);
					}	
					if(review=='2'){
						fputs(reader, Nota2);
						fputs("\n", Nota2);
					}	
					if(review=='3'){
						fputs(reader, Nota3);
						fputs("\n", Nota3);
					}	
					if(review=='4'){
						fputs(reader, Nota4);
						fputs("\n", Nota4);
					}	
					if(review=='5'){
						fputs(reader, Nota5);
						fputs("\n", Nota5);
					}	
				}
				i++;
			}
			//closing the open files.
			fclose(origin);
			fclose(Nota1);
            fclose(Nota2);
            fclose(Nota3);
            fclose(Nota4);
            fclose(Nota5);
        	
		}
		// Criando o gerador de vocabulário 
		if(option == 2 ){
			{
			printf("------Gerando vocabulário de palavras------ \n");
            vocabularioCompleto = fopen("files/vocabularioCompleto.txt","w");
            vocabularioSemRepeticoes= fopen("files/vocabularioSemRepeticoes.txt","w");
            maior_comprimento = 0;
            
            // Abrindo csv e gerando vocabularios com e sem repeticao
            documento = Arquivo_AbreLeitura("text.csv");
			geraVocabularioCompleto(documento,vocabularioCompleto);
			fclose(vocabularioCompleto);
            vocabularioCompleto = fopen("files/vocabularioCompleto.txt","r"); // Abrindo para leitura//


            printf("Por favor insira o número de palavras que deseja testar :");
            scanf("%d",&lim);
            geraArquivoSemRepeticao(vocabularioSemRepeticoes,vocabularioCompleto,lim);

            fclose(vocabularioCompleto);
			fclose(vocabularioSemRepeticoes);
            fclose(documento);
            
        }
		
		}if(option == 3 ){
	
		}if(option == 4 ){
		
		}if(option == 5 ){
			printf("Programa encerrado!");
		}
}}
int main(int argc, char *argv[]) {
	menu();
return 0;

}

