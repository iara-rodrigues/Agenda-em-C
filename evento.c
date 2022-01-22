#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento.h"

//Fiz o inicializa evento separado em cases para inicializar corretamente cada tipo de evento,
//mas mesmo assim todo tipo de evento receberá todos os parametros, mesmo que para ele não seja necessario;
Evento* inicializaEvento(tipoEvento tipo, char *desc, int hrComeco, int hrFinal, int grau, int prio, char *rua, char *bairro, char *cidade, char *estado, int numCasa, bool po, char* nome){
	Evento  *even = (Evento*) malloc(sizeof(Evento));	
    //printf("aqui");
	if(even != NULL){
        switch (tipo){
        case 1:
            even->tipo = tipo;
            strcpy(even->assunto, desc);
            even->hrInicio = hrComeco;
            even->hrFim = hrFinal;
            even->grau = grau;
            even->prioridade = prio;
            //printf("AQUI");
            break;

        case 2:
            //printf("entrou case 2.1");
            even->tipo = tipo;
            strcpy(even->assunto, desc);
            even->hrInicio = hrComeco;
            even->hrFim = hrFinal;
            strcpy(even->endereco.rua, rua);
            strcpy(even->endereco.bairro, bairro);
            strcpy(even->endereco.cidade, cidade);
            strcpy(even->endereco.estado, estado);
		    even->endereco.numeroCasa = numCasa;
		    even->presencaObrigatoria = po;
            //printf("apaarentemente inseriu caso 2");
            break;

        case 3:
            even->tipo = tipo;
            strcpy(even->assunto, desc);
            even->hrInicio = hrComeco;
            even->hrFim = hrFinal;
		    strcpy(even->endereco.rua, rua);
            strcpy(even->endereco.bairro, bairro);
            strcpy(even->endereco.cidade, cidade);
            strcpy(even->endereco.estado, estado);
		    even->endereco.numeroCasa = numCasa;
            strcpy(even->nomeAniver, nome);
            //printf("no caso 3...");
            break;
        default:
            
            break;
        }
	}
	return even;
}


void imprimeEvento(Evento *even){
	switch(even->tipo){
		case 1:
			printf("\nTAREFA\n");
		break;
		case 2:
			printf("\nREUNIAO\n");
		break;
		case 3:
			printf("\nANIVERSARIO\n");
		break;
	}
    printf("\tAssunto: %s \n", even->assunto);
	printf("\tHorario das %dh as %dh.\n", even->hrInicio, even->hrFim);

    //Também separei o ImprimeEvento em cases, note que alguns eu deixei fora do switch já que todos os tipos
    //de evento precisam deles;

    switch(even->tipo){
		case 1:
			printf("\tGrau de esforco: %d\n", even->grau);
            printf("\tGrau de prioridade: %d\n", even->prioridade);
		break;

		case 2:
			printf("\tLocal:\n");
            printf("\tEstado: %s", even->endereco.estado);
            printf("\tCidade: %s\n", even->endereco.cidade);
            printf("\tRua: %s", even->endereco.rua);
            printf("\tNumero: %d\n", even->endereco.numeroCasa);
            printf("\tBairro: %s\n", even->endereco.bairro);
            if(even->presencaObrigatoria==1){
                printf("\tPresenca EH obrigatoria.\n");
            }else{
                printf("\tPresenca  NAO eh obrigatoria.\n");
            } 
		break;

		case 3:
            printf("\tLocal:\n");
            printf("\tEstado: %s", even->endereco.estado);
            printf("\tCidade: %s\n", even->endereco.cidade);
            printf("\tBairro: %s\n", even->endereco.bairro);
            printf("\tRua: %s", even->endereco.rua);
            printf("\tNumero: %d\n", even->endereco.numeroCasa);
            printf("\tNome do aniversariante: %s\n", even->nomeAniver);
		break;
	}
}

//A função temConflito foi feita para comparar se o horario digitado do novo evento (e2) é igual a algum horário
//já cadastrado para outro evento. 
//São passados como parametro uma variavel do tipo Evento e outra de tipo int, pois o evento só será inserido
//na agenda quando for verificado que o horario de Inicio dele não coincide com nenhum outro horário de início 
//de algum evento já cadastrado;
int temConflito(Evento *e1, int e2){
    //printf("TemConflito e1: %d, e2: %d", e1->hrInicio, e2);
    if(e1->hrInicio==e2){
        return 0;
    } else {
        return 1;
    }
}

