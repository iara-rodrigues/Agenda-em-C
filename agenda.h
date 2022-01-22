#ifndef __AGENDA_H
#define __AGENDA_H

#define MAX 200
#include "evento.h"

//Separei os dados do usuário em outro struct para o código ficar mais organizado.
typedef struct{
    char nome[100];
    char email[100];
    int idUser;
}usuario;

//a variável 'dados' do tipo Evento*, foi criada para que seja um vetor com todos os eventos da agenda.
typedef struct{
	usuario usuario;
    int quantidadeEvento;
	Evento *dados[MAX];
}Agenda;

Agenda* criaAgenda(char* nome, char* email, int id);
void insereEvento(Agenda *a, int tipo, char *desc, int hrComeco, int hrFinal, int grau, int prio, char *rua, char *bairro, char *cidade, char *estado, int numCasa, bool po, char* nome);
void imprimeAgenda(Agenda *a);
void imprimeUsuarios(Agenda *a, int i);
int podeInserir(Agenda *a, int e);
//int IDcadastrado (int j, Agenda* a);

#endif