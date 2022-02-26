#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------- UNIVERSIDADE DE BRASILIA - CAMPUS FGA -------------------------------------------//
//                                                   estrutura de dados e algoritmos                                             //
// GRUPO 10:
// Joao Pedro Alves Machado - 212008197
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
		printf("---------------------------------------------------------------\n");
		printf("------------------------------- Menu --------------------------\n");
		printf("Bem-Vindo ao menu de opções de avaliação do Trip Adivisor.\n");
		printf("Insira a opção desejada: \n");
        printf("1 - Ler o dataset do Trip Adivisor.\n");
        printf("2 - Gerar vocabulario.\n");
        printf("3 - Exibir TF-IDFs.\n");
        printf("4 - Exibir TF-IDF de uma Nota. Em ordem decrescente de valor de TF-IDF.\n");
        printf("5 - Sair\n");
        printf("---------------------------------------------------------------\n");
        printf("Escolha :");
        scanf("%d",&option);


        if(option==1){
        	printf("Escreva o nome do arquivo:\n ");
        	scanf("%s", &localArchive);
        	printf("%s \n", &localArchive);

        	FILE *origin;
        	FILE *Nota_1;
        	FILE *Nota_2;
        	FILE *Nota_3;
        	FILE *Nota_4;
        	FILE *Nota_5;

            Nota_1 = fopen("files/Nota_1.txt","w");
		    Nota_2 = fopen("files/Nota_2.txt","w");
		    Nota_3 = fopen("files/Nota_3.txt","w");
		    Nota_4 = fopen("files/Nota_4.txt","w");
		    Nota_5 = fopen("files/Nota_5.txt","w");
        	origin = fopen(localArchive, "r");
        	if(origin == NULL){
        		printf("wasnt possible to access the archive.\n");
			}
			if(Nota_1 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota_2 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota_3 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota_4 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota_5 == NULL){
        		printf("wasnt possible to access the archive.\n");
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
						fputs(reader, Nota_1);
						fputs("\n", Nota_1);
					}	
					if(review=='2'){
						fputs(reader, Nota_2);
						fputs("\n", Nota_2);
					}	
					if(review=='3'){
						fputs(reader, Nota_3);
						fputs("\n", Nota_3);
					}	
					if(review=='4'){
						fputs(reader, Nota_4);
						fputs("\n", Nota_4);
					}	
					if(review=='5'){
						fputs(reader, Nota_5);
						fputs("\n", Nota_5);
					}	
				}
				i++;
			}
			// Fechando os arquivos abertos.
			fclose(origin);
			fclose(Nota_1);
            fclose(Nota_2);
            fclose(Nota_3);
            fclose(Nota_4);
            fclose(Nota_5);

		}
		if(option == 2 ){
			// Criando arquivos de destino para cada vocabulario.
			FILE *vocabulario_Totalrep;
			FILE *vocabulario_1rep;
        	FILE *vocabulario_2rep;
        	FILE *vocabulario_3rep;
        	FILE *vocabulario_4rep;
        	FILE *vocabulario_5rep;
        	
        	FILE *origin;
        	FILE *Nota_1;
        	FILE *Nota_2;
        	FILE *Nota_3;
        	FILE *Nota_4;
        	FILE *Nota_5;
        	
		
			vocabulario_Totalrep = fopen("files/vocabulario_Totalrep.txt", "w");
            vocabulario_1rep = fopen("files/vocabulario_1rep.txt","w");
			vocabulario_2rep = fopen("files/vocabulario_2rep.txt","w");
		    vocabulario_3rep = fopen("files/vocabulario_3rep.txt","w");
		    vocabulario_4rep = fopen("files/vocabulario_4rep.txt","w");
		    vocabulario_5rep = fopen("files/vocabulario_5rep.txt","w");
		
            Nota_1 = fopen("files/Nota_1.txt","r");
		    Nota_2 = fopen("files/Nota_2.txt","r");
		    Nota_3 = fopen("files/Nota_3.txt","r");
		    Nota_4 = fopen("files/Nota_4.txt","r");
		    Nota_5 = fopen("files/Nota_5.txt","r");
		    origin = fopen("files/text.csv", "r");
		    
		    
			if(Nota_1 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota_2 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota_3 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota_4 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}if(Nota_5 == NULL){
        		printf("Não foi possível acessar o arquivo.\n");
			}

			char reader[0];
			char *pointer;
			char *pointer2;

			
						
			while(fgets(reader, 100, Nota_1) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocabulario_1rep);
						fputs("\n", vocabulario_1rep);
						fputs(pointer, vocabulario_Totalrep);
						fputs("\n",vocabulario_Totalrep);
					}
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			while(fgets(reader, 100, Nota_2) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocabulario_2rep);
						fputs("\n", vocabulario_2rep);
						fputs(pointer, vocabulario_Totalrep);
						fputs("\n",vocabulario_Totalrep);
					}
					
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			while(fgets(reader, 100, Nota_3) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocabulario_3rep);
						fputs("\n", vocabulario_3rep);
						fputs(pointer, vocabulario_Totalrep);
						fputs("\n",vocabulario_Totalrep);
					}
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			while(fgets(reader, 100, Nota_4) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocabulario_4rep);
						fputs("\n", vocabulario_4rep);
						fputs(pointer, vocabulario_Totalrep);
						fputs("\n",vocabulario_Totalrep);
					}
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			while(fgets(reader, 100, Nota_5) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocabulario_5rep);
						fputs("\n", vocabulario_5rep);
						fputs(pointer, vocabulario_Totalrep);
						fputs("\n",vocabulario_Totalrep);
						
					}
					pointer = strtok(NULL," ,.!?\"");	
				}
		}
					// Fechando os arquivos aberto
			fclose(origin);
			fclose(Nota_1);
            fclose(Nota_2);
            fclose(Nota_3);
            fclose(Nota_4);
            fclose(Nota_5);
            
            fclose(vocabulario_Totalrep);
            fclose(vocabulario_1rep);
            fclose(vocabulario_2rep);
            fclose(vocabulario_3rep);
            fclose(vocabulario_4rep);
            fclose(vocabulario_5rep);

        
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
