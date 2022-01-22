#ifndef __EVENTO_H
#define __EVENTO_H

//decidir fazer bool assim pois estava dando um bug no meu pc, depois descobri que não era por causa disso, 
//mas deixei assim;
typedef enum { 
    false = 0, 
    true  //1
}bool;

typedef enum{
	TAREFA = 1,    //o 1 é para que nao inicie a enumeração do zero, e sim do 1;
	REUNIAO,       //2 
	ANIVERSARIO    //3
}tipoEvento;

typedef struct{
	char rua[50], bairro[50], cidade[50], estado[3];
    int numeroCasa;
}localEvento;

typedef struct{
    tipoEvento tipo;
    char assunto[200];
    int hrInicio, hrFim;

    int grau;
    int prioridade;
	
    localEvento endereco; //preferi fazer outro struct pro endereço para esse não ficar muito grande;
    bool presencaObrigatoria;
    char nomeAniver[100];
}Evento;

Evento* inicializaEvento(tipoEvento tipo, char *desc, int hrComeco, int hrFinal, int grau, int prio, char *rua, char *bairro, char *cidade, char *estado, int numCasa, bool po, char* nome);
Evento* inicializaTarefa(tipoEvento tipo, char *desc, int hrComeco, int hrFinal, int grau, int prio);
Evento* inicializaReuniao(tipoEvento tipo, char *desc, int hrComeco, int hrFinal, char *rua, char *bairro, char *cidade, char *estado, int numCasa, bool po);
Evento* inicializaAniver(tipoEvento tipo, char *desc, int hrComeco, int hrFinal, char *rua, char *bairro, char *cidade, char *estado, int numCasa, char* nome);
void imprimeEvento(Evento *even);
int temConflito(Evento *e1, int e2);

#endif