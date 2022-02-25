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
        	printf("write the name of archive: ");
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
        		printf("wasnt possible to access the archive.\n");
			}
			if(Nota1 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota2 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota3 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota4 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota5 == NULL){
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
		if(option == 2 ){
			// criando arquivos de destino para cada vocabulario.
			FILE *vocabTotalrep;
			FILE *vocab1rep;
        	FILE *vocab2rep;
        	FILE *vocab3rep;
        	FILE *vocab4rep;
        	FILE *vocab5rep;
        	
        	FILE *vocab1;
        	FILE *vocab2;
        	FILE *vocab3;
        	FILE *vocab4;
        	FILE *vocab5;
        	
        	FILE *origin;
        	FILE *Nota1;
        	FILE *Nota2;
        	FILE *Nota3;
        	FILE *Nota4;
        	FILE *Nota5;
        	
        
        	vocab1 = fopen("files/vocab1.txt","w");
			vocab2 = fopen("files/vocab2.txt","w");
		    vocab3 = fopen("files/vocab3.txt","w");
		    vocab4 = fopen("files/vocab4.txt","w");
		    vocab5 = fopen("files/vocab5.txt","w");
		
			vocabTotalrep = fopen("files/vocabTotalrep.txt", "w");
            vocab1rep = fopen("files/vocab1rep.txt","w");
			vocab2rep = fopen("files/vocab2rep.txt","w");
		    vocab3rep = fopen("files/vocab3rep.txt","w");
		    vocab4rep = fopen("files/vocab4rep.txt","w");
		    vocab5rep = fopen("files/vocab5rep.txt","w");
		
            Nota1 = fopen("files/Nota1.txt","r");
		    Nota2 = fopen("files/Nota2.txt","r");
		    Nota3 = fopen("files/Nota3.txt","r");
		    Nota4 = fopen("files/Nota4.txt","r");
		    Nota5 = fopen("files/Nota5.txt","r");
		    origin = fopen("files/text.csv", "r");
			if(Nota1 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota2 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota3 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota4 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}if(Nota5 == NULL){
        		printf("wasnt possible to access the archive.\n");
			}

			char reader[0];
			char *pointer;
			char *pointer2;

			
						
			while(fgets(reader, 100, Nota1) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocab1rep);
						fputs("\n", vocab1rep);
						fputs(pointer, vocabTotalrep);
						fputs("\n",vocabTotalrep);
					}
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			while(fgets(reader, 100, Nota2) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocab2rep);
						fputs("\n", vocab2rep);
						fputs(pointer, vocabTotalrep);
						fputs("\n",vocabTotalrep);
					}
					
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			while(fgets(reader, 100, Nota3) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocab3rep);
						fputs("\n", vocab3rep);
						fputs(pointer, vocabTotalrep);
						fputs("\n",vocabTotalrep);
					}
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			while(fgets(reader, 100, Nota4) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocab4rep);
						fputs("\n", vocab4rep);
						fputs(pointer, vocabTotalrep);
						fputs("\n",vocabTotalrep);
					}
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			while(fgets(reader, 100, Nota5) != NULL){
				pointer=strtok(reader," ,.!?\"");
				while(pointer){
					if(strlen(pointer)>3){
						fputs(pointer, vocab5rep);
						fputs("\n", vocab5rep);
						fputs(pointer, vocabTotalrep);
						fputs("\n",vocabTotalrep);
						
					}
					pointer = strtok(NULL," ,.!?\"");	
				}
			}
			//closing the open files.
			fclose(origin);
			fclose(Nota1);
            fclose(Nota2);
            fclose(Nota3);
            fclose(Nota4);
            fclose(Nota5);
            
            fclose(vocabTotalrep);
            fclose(vocab1rep);
            fclose(vocab2rep);
            fclose(vocab3rep);
            fclose(vocab4rep);
            fclose(vocab5rep);
            
            fclose(vocab1);
            fclose(vocab2);
            fclose(vocab3);
            fclose(vocab4);
            fclose(vocab5);
            
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
