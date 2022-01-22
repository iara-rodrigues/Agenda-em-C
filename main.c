#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#define TOT 100

int main(void){
	//setei um valor máximo de agendas e eventos em cada agenda que podem ter para não precisar
	//ser feito uma alocação dinamica utilizando listas encadeadas;
	Agenda *a[TOT];
    int menu=0, op, op2, id=0, idAcesso, tpEvento, hrComeco, hrFinal, grau=0, priori=0, po, numCasa, aux;
    char desc[200], nome[100], email[100], est[3], cid[50], bairro[50], rua[50], nomeAniv[100];

	printf("Voce ja esta cadastrado?\n");
	printf("(O cadastro so pode ser feito agora)\n");
	printf("Digite 1 para sim ou 2 para nao\n");
	scanf("%d", &op);
	if (op != 1){
		do{
			printf("\n*********CADASTRO*********\n");
			printf("Digite seu nome para cadastrar sua Agenda: \n");
			setbuf(stdin, NULL);
			gets(nome);
            printf("Digite seu email: \n");
			setbuf(stdin, NULL);
			gets(email);
			printf("Seu ID para acessar a agenda eh %d. Guarde esse numero pois precisara dele.\n", id);
			system("pause");
			printf("\n");
			a[id] = criaAgenda(nome, email, id);
            id++; 
			printf("Digite 1 caso queira cadastrar outro usuario e 2 para acessar uma Agenda\n");
			scanf("%d", &op2);
		}while(id<TOT && op2 == 1);
	}

	printf("Para acessar a Agenda digite seu ID:\n");
	scanf("%d", &idAcesso);
	/*setbuf(stdin, NULL);
    gets(emailAcesso);*/

    //conferindo se o id digitando já cadastrou uma agenda
	aux = 0;
	for (int i=-1; i<id; i++){
		if(idAcesso==i){
			aux = 1;
		}
	}
	if (aux == 1){
		printf("Abrindo sua agenda...\n");
	} else {
		printf("\nO id digitado nao pertence a lista de IDs.\n");
		printf("Confira seu ID na lista abaixo\n");
		for (int i=0; i<id; i++){
			imprimeUsuarios(a[i], i);
		}
		printf("Para acessar a Agenda digite seu ID:\n");
		scanf("%d", &idAcesso);
	}
    
	//O loop do menu
	do{
		if(menu == 4){
			printf("Para acessar a Agenda digite seu ID:\n");
			scanf("%d", &idAcesso);

			//conferindo se o id digitando já cadastrou uma agenda
			aux = 0;
			for (int i=-1; i<id; i++){
				if(idAcesso==i){
					aux = 1;
				}
			}
			if (aux == 1){
				printf("Abrindo sua agenda...\n");
			} else {
				printf("\nO id digitado nao pertence a lista de IDs.\n");
				printf("Confira seu ID na lista abaixo\n");
				for (int i=0; i<id; i++){
					imprimeUsuarios(a[i], i);
				}
				printf("Para acessar a Agenda digite seu ID:\n");
				scanf("%d", &idAcesso);
			}
		}

		printf("\n\n************MENU************\n");
		printf("O que voce deseja realizar?\n");
		printf("1- Imprime Sua Agenda;\n");
		printf("2- Inserir Evento;\n");
		printf("3- Imprimir usuarios;\n");
		printf("4- Trocar de agenda;\n");
		printf("0 - Sair.\n");
		printf("---------------------------------------------------------------\n");
		printf("Digite a opcao escolhida:\n>>> ");
		scanf("%d", &menu);


	  switch (menu){ 
		case 0:
			exit(0);  //sai do programa;
		case 1:
			printf("Imprimindo Agenda...\n");
			imprimeAgenda(a[idAcesso]);
			system("pause");
			break;
        
		case 2:
			//Fiz as restrições de inserção aqui (digitar apenas os numeros nos intervalos corretos);

			printf("Inserindo um Evento...\n");
			printf("1- Tarefa\n");
			printf("2- Reuniao\n");
			printf("3- Aniversario\n");
			printf("Digite o tipo do Evento:\n");
			scanf("%d", &tpEvento);

            printf("Digite o Assunto do Evento: ");
            setbuf(stdin, NULL);
            gets(desc);
            printf("Digite a hora de Inicio do Evento: (valor inteiro entre 0 e 23): ");
            scanf("%d", &hrComeco);
            printf("Digite a hora de Termino do Evento: (valor inteiro entre 0 e 23): ");
            scanf("%d", &hrFinal);

			if((hrComeco>23) || (hrFinal>23) || (hrComeco<0) || (hrFinal<0)){
                printf("Por favor, digite os horarios corretamente.\n");
				printf("O evento nao foi inserido.\n");
				system("pause");
				printf("\n");
            } else{
				if(hrComeco>hrFinal){
					printf("Por favor, digite o horario de começo menor que o de termino.\n");
				} else{
					switch (tpEvento){
            		case 1:
						printf("Grau de esforco da tarefa: (valor inteiro entre 0 e 5):");
						scanf("%d", &grau);
						printf("Grau de prioridade da tarefa: (valor inteiro entre 0 e 5):");
						scanf("%d", &priori);
						if((grau>5) || (priori>5) || (grau<0) || (priori<0)){
							printf("Por favor, digite os valores corretamente.\n");
							printf("O evento nao foi inserido.\n");
						} else {
							if ((podeInserir(a[idAcesso],hrComeco))==1){
								insereEvento(a[idAcesso], tpEvento, desc, hrComeco, hrFinal, grau, priori, "", "", "", "", -1, 0, "");
							} else {
								printf("Outro evento ja comeca essa hora\n");
								printf("O evento nao foi inserido.\n");
							}
							
						}
						break;
					case 2:
						printf("Digite a SIGLA do estado da reuniao:");
						setbuf(stdin, NULL);
						gets(est);
						printf("Digite a cidade:");
						setbuf(stdin, NULL);
						gets(cid);
						printf("Digite o bairro:");
						setbuf(stdin, NULL);
						gets(bairro);
						printf("Digite a rua:");
						setbuf(stdin, NULL);
						gets(rua);
						printf("Digite o numero:");
						scanf("%d", &numCasa);
						printf("A presenca eh obrigatoria? 0-Nao, 1-Sim");
						scanf("%d", &po);
						if((po<0) || (po>1)){
							printf("Por favor, digite os valores corretamente.\n");
							printf("O evento nao foi inserido.\n");
						}else{
							if ((podeInserir(a[idAcesso], hrComeco))==1){
								insereEvento(a[idAcesso], tpEvento, desc, hrComeco, hrFinal, -1, -1, rua, bairro, cid, est, numCasa, po, "");
							} else {
								printf("Outro evento ja comeca essa hora\n");
								printf("O evento nao foi inserido.\n");
							}
						}
						break;
					case 3:
						printf("Digite a SIGLA do estado do aniversario:");
						setbuf(stdin, NULL);
						gets(est);
						printf("Digite a cidade:");
						setbuf(stdin, NULL);
						gets(cid);
						printf("Digite o bairro:");
						setbuf(stdin, NULL);
						gets(bairro);
						printf("Digite a rua:");
						setbuf(stdin, NULL);
						gets(rua);
						printf("Digite o numero:");
						scanf("%d", &numCasa);
						printf("Digite o nome do Aniversariante: ");
						setbuf(stdin, NULL);
						gets(nomeAniv);
						if ((podeInserir(a[idAcesso],hrComeco))==1){
							insereEvento(a[idAcesso], tpEvento, desc, hrComeco, hrFinal, -1, -1, rua, bairro, cid, est, numCasa, 0, nomeAniv);
						} else {
							printf("Outro evento ja comeca essa hora\n");
							printf("O evento nao foi inserido.\n");
						}
						break;
						default:
							printf("Digite um tipo valido de evento.");
							break;
					}
				}
			}
			break;
			
		case 3:
			//fiz um 'for' aqui, pois, diferente da função imprimeAgenda, a imprimeUsuarios não possui um 'for'.
			printf("Imprimindo Usuarios...\n");
			for (int i=0; i<id; i++){
				imprimeUsuarios(a[i], i);
			}
			break;
		
		case 4:
			//Volta para antes do switch para permitir o login em outra agenda;
			break;
					
		default:
			printf("Digite uma opcao valida.");
		}
	}while (menu != 0);  //sai do while quando a opção do menu digitada for zero;
	
}