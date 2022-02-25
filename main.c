#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------- UNIVERSIDADE DE BRASILIA - CAMPUS FGA -------------------------------------------//
//                                                   estrutura de dados e algoritmos                                             //
// GRUPO 10:
// Joao Pedro Alves Machado - 212028197
// Mayara Alves de OLiveira - 200025058         
//-------------------------------------------------------------------------------------------------------------------------------//


// Criando Menu de decisÃµes

int menu(){
	char localArchive[100];
	int length_palavra;
	int maior_comprimento;
	int qtde_palavra;
	int qntd_doc = 0;
	int qntd_voc;
	int lim;
	int lenString;
	
	int option = 0;
	while(option != 5){
		printf("------------------------------------------------------");
		printf("--------------------- Menu ----------------\n");
		printf("Bem-Vindo ao menu de opções de avaliação do Trip Adivisor.");
		printf("Insira a opção desejada: \n");
        printf("1 - Ler o dataset do Trip Adivisor.\n");
        printf("2 - Gerar vocabulario.\n");
        printf("3 - Exibir TF-IDFs.\n");
        printf("4 - Exibir TF-IDF de uma Nota. Em ordem decrescente de valor de TF-IDF.\n");
        printf("5 - Sair\n");
        printf("---------------------------------------------------------\n");
        scanf("%d",&option);
        
        // Criando modo leitura do data set//

        if(option==1){
			printf("------------------------------------------------------\n");
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
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota1 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota2 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota3 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota4 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota5 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
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
					//escrever as informações nos dados
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
			//fechando os arquivos abertos.
			fclose(origin);
			fclose(Nota1);
            fclose(Nota2);
            fclose(Nota3);
            fclose(Nota4);
            fclose(Nota5);
        	
		}
		// Criando o gerador de vocabulário 
		if(option == 2 ){
			FILE *VocabularioCompleto;
        	FILE *VocabularioSemRepeticoes;
        	FILE *Texto;
    
    		char palavra[100000000];
    		char localArquivo[100];
   			printf("------------------------------------------------------\n");
        	printf("Por favor insira o nome do arquivo:\n");
        	scanf("%s", &localArquivo, palavra);
        	printf("%s \n", &localArquivo);
        	
        	Texto  = fopen(localArquivo, "r");
        	VocabularioCompleto = fopen("files/VocabularioCompleto.txt","w");
		    VocabularioSemRepeticoes = fopen("files/VocabularioSemRepeticoes.txt","w");
        	if(Texto == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(VocabularioCompleto == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(VocabularioSemRepeticoes == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
        	}	

			int lengthPalavra;
			int maior_comprimento;
			
			 while(!feof(Texto))
    	{   
       		 // ler palavra por palavra
        	fscanf(Texto,"%s",palavra);
        	lengthPalavra = len(palavra); 

       		 if(maior_comprimento < lengthPalavra){
            maior_comprimento = lengthPalavra;
        	}

        	// pontuacao
       		 void pontuacao(char *palavra,int *len)
			{
   		 	int i = 0;
         	int aux;
    	 	char pontuacao[4] = {',','.','"'};


    		for(i = 0;i < 3;i++){
        		if(palavra[*len-1] == pontuacao[i]){
        	    palavra[strlen(palavra) - 1] = palavra[strlen(palavra)];
       	     *len--;
       			 }
   			 }
    
    		for(i = 0;i < 4;i++)
  			  {
       		 if(palavra[0] == pontuacao[i]){
         	   for(aux = 0 ; aux < *len ; aux++){
                palavra[aux] = palavra[aux+1];
      	      }
        	    *len--;
       			 }
    			}
				}

    		return 0;
			}
			// verifica se a string lida começa com números
			int verifica_num(char *palavra){

    		char num[11] = {'0','1','2','3','4','5','6','7','8','9'};

   			 for(int i = 0 ; i < 11 ; i ++){
        		if(palavra[0] == num[i])
       		 {
           	 return 1;
       	 }
   		 }
    		return 0;
			}

        pontuacao(palavra,&lengthPalavra);

       	 if(((length_palavra > 4) && (length_palavra <= 20)) && (verifica_num(palavra) == 0)){
           	 fprintf(VocabularioCompleto,"%s\n",palavra);
           	 qtde_palavra++;
      			  }
   			 }
		}

        	//fechando os arquivos abertos.
			fclose(Texto);
			fclose(VocabularioCompleto);
            fclose(VocabularioSemRepeticoes);
        }
      	
		}if(option == 3 ){
	
		}if(option == 4 ){
		
		}if(option == 5 ){
			printf("Programa encerrado!");
		}
	}
}

int main(int argc, char *argv[]) {
	menu();
return 0;

}

