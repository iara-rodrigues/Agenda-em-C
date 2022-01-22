#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

//A agenda é criada inicialmente com os dados do usuario e setando a quantidade de eventos em zero;
Agenda* criaAgenda(char *nome, char *email, int id){
	Agenda *ag = (Agenda*) malloc(sizeof(Agenda));
	if(ag != NULL){
        strcpy(ag->usuario.nome, nome);
        strcpy(ag->usuario.email, email);
		ag->usuario.idUser = id;
		ag->quantidadeEvento = 0; 
	}
	return ag;
}

//Essa função foi criada para inserir um evento na agenda.
//Essa função recebe como parametro todos os elementos dos eventos e a agenda em que serão inseridos;
//Ela chama a função inicializaEvento e adiciona o evento na agenda em que o usuario está logado.
void insereEvento(Agenda *a, int tipo, char *desc, int hrComeco, int hrFinal, int grau, int prio, char *rua, char *bairro, char *cidade, char *estado, int numCasa, bool po, char* nome){
	if(a->quantidadeEvento <= MAX){   //MAX foi definido no agenda.h;
		printf("Evento inserido com sucesso\n");
		a->dados[a->quantidadeEvento] = inicializaEvento(tipo, desc, hrComeco, hrFinal, grau, prio, rua, bairro, cidade, estado, numCasa, po, nome);
		a->quantidadeEvento++;
	}else{
		printf("NAO FOI POSSIVEL INSERIR O EVENTO\n");
	}
}

//Essa função foi feita para imprimir todos os eventos de uma determinada agenda;
void imprimeAgenda(Agenda *a){
	for(int i = 0; i < a->quantidadeEvento; i++){ 
		imprimeEvento(a->dados[i]);
	}
}

//Essa função foi implementada para imprimir todos os usuarios já cadastrados. 
//Essa listagem ajuda quando algum usuario esquecer seu id, por exemplo.
void imprimeUsuarios(Agenda *a, int i){
	//for(int i = -1; i < a->usuario.idUser; i++){ 
		printf("ID: %d\t Nome: %s\t Email: %s\n", i, a->usuario.nome, a->usuario.email);
	//}
}

//Essa função foi implementada para chamar a função temConflito e resolver se poderá ou não inserir esse evento
//na agenda;
int podeInserir(Agenda *a, int e){
	//printf("podeInserir, entrou\n");
	int pi=1;
	for(int i=0; i<a->quantidadeEvento; i++){
		if(temConflito(a->dados[i], e) == 0){
			pi = 0;
		}
	}
	return pi;
}

//Essa função eu tinha feito para conferir se o id de acesso que o usuario digitou existia. 
//Mas resolvi fazer direto no main;
/*int IDcadastrado (int j, Agenda* a){
	int tf = 0;
	for (int i=-1; i<a->usuario.idUser; i++){
		if(j==i){
			tf = 1;
		}
	}
	return tf;
}*/