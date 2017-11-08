				/// Bibliotecas ///

#include <stdio.h>
#include <stdlib.h>


/****************************************************************************/
/*                                                                          */
/* 			     Module CPU                                     */
/* 			External Declarations 				    */
/*                                                                          */
/****************************************************************************/


/* OSP constant      */

#define   MAX_PAGE                   16 /* max size of page tables          */

/* OSP enumeration constants */

typedef enum {
    false, true                         /* the boolean data type            */
} BOOL;

typedef enum {
    running, ready, waiting, done       /* types of status                  */
} STATUS;



/* external type definitions */

typedef struct page_entry_node PAGE_ENTRY;
typedef struct page_tbl_node PAGE_TBL;
typedef struct event_node EVENT;
typedef struct pcb_node PCB;



/* external data structures */

extern struct page_entry_node {
    int    frame_id;    /* frame id holding this page                       */
    BOOL   valid;       /* page in main memory : valid = true; not : false  */
    int    *hook;       /* can hook up anything here                        */
};

extern struct page_tbl_node {
    PCB    *pcb;        /* PCB of the process in question                   */
    PAGE_ENTRY page_entry[MAX_PAGE];
    int    *hook;       /* can hook up anything here                        */
};

extern struct pcb_node {
    int    pcb_id;         /* PCB id                                        */
    int    size;           /* process size in bytes; assigned by SIMCORE    */
    int    creation_time;  /* assigned by SIMCORE                           */
    int    last_dispatch;  /* last time the process was dispatched          */
    int    last_cpuburst;  /* length of the previous cpu burst              */
    int    accumulated_cpu;/* accumulated CPU time                          */
    PAGE_TBL *page_tbl;    /* page table associated with the PCB            */
    STATUS status;         /* status of process                             */
    EVENT  *event;         /* event upon which process may be suspended     */
    int    priority;       /* user-defined priority; used for scheduling    */
    PCB    *next;          /* next pcb in whatever queue                    */
    PCB    *prev;          /* previous pcb in whatever queue                */
    int    *hook;          /* can hook up anything here                     */
};


/* external variables */

extern PAGE_TBL *PTBR;		/* page table base register */

extern int    Quantum;		/* global time quantum; contains the value
				   entered at the beginning or changed 
				   at snapshot. Has no effect on timer
				   interrupts, unless passed to set_timer() */



/* external routines */

extern prepage(/* pcb */);
extern int start_cost(/* pcb */);
/*  PCB    *pcb; */    

extern set_timer(/* time_quantum */);
/*  int    time_quantum; */

extern int get_clock();

/****************************************************************************/
/*                                                                          */
/*				Implementação				    */
/*			  	Fila para Round-Robin			    */
/*                                                                          */
/****************************************************************************/

			/// Criando a estrutura da fila ///

typedef struct estrutura_fila {
	PCB * pt_inicio;					/* No inicial 		*/
	PCB * pt_fim;						/* No final		*/
}estrutura_fila;								

typedef estrutura_fila* pt_fila;				/* Define estrutura_fila * como pt_fila */

//pt_fila fila[10];							/* Cria um ponteiro para estrutura_fila */
pt_fila* fila;
int i;



			/// Declaração de funções utilizadas ///

/*void inicializar_fila();
void inserir(PCB * pcb,pt_fila fila);
PCB * retirar();
BOOL esta_na_fila (int id,pt_fila fila);
BOOL fila_vazia();		
void insert_ready(PCB *pcb);*/

			/// Variáveis globais ///
float Media = 0;
float Soma = 0;
float DesvioPadrao = 0;
float Count = 0;
int Contador = 0;

			/// Criando funções para a estrutura da fila ///

void inicializar_fila (int id){
	fila[id] = (pt_fila) malloc (sizeof (estrutura_fila)); 	/* Aloca espaço correspondente ao tamanho da estrutura da fila	*/
	if (fila[id] == NULL)  					/* Verifica se ocorreu um erro de alocação */
		exit(0);
	fila[id]->pt_inicio = NULL;					/* Inicia o início da fila como null */
	fila[id]->pt_fim = NULL;					/* Inicia o fim da fila como null */
}

BOOL fila_vazia(pt_fila fifo) {
	if (fifo->pt_inicio == NULL)
		return true;
	return false;
}

void inserir(PCB * pcb,pt_fila fifo) {
	if (fila_vazia(fifo)){ 					/* Verifica se a fila esta vazia */
		fifo->pt_inicio = pcb; 				/* Coloca o processo no inicio da fila */
		fifo->pt_fim = pcb; 				/* Coloca o processo no fim da fila */

	}	
	else { 							/* Caso não esteja vazia */
		fifo->pt_fim->next = pcb; 			/* O ultimo processo da fila aponta para o novo processo */
		fifo->pt_fim = pcb; 				/* O processo é inserido no fim da fila */
	}
}

PCB * retirar(pt_fila fifo) {
	PCB * pcb;						/* Cria um ponteiro para o processo que o retornará posteriormente */
	if (!fila_vazia(fifo)){ 					/* Verifica se a fila NAO esta vazia */
		pcb = fifo->pt_inicio; 				/* Ponteiro pcb aponta para o inicio da fila */
		fifo->pt_inicio = fifo->pt_inicio->next;		/* Atualiza o inicio da fila */		
		return pcb; 					/* Retorna o ponteiro contendo a localização do processo */	
	}
	return NULL; 						/* Caso a fila esteja vazia, retorna null */
}

BOOL esta_na_fila (int id,pt_fila fifo) {
	if (!fila_vazia(fifo)){ 					/* Verifica se a fila NAO esta vazia */
		PCB * aux;					/* Cria um ponteiro para o processo que o verificará se existe este id na fila */
		aux = fifo->pt_inicio;				/* Ponteiro aponta para o inicio na fila */
		while (aux != NULL) {				/* Percorre a fila ate encontrar o processo que contém o id ou chegar ao fim */
			if (id == aux->pcb_id) 			/* Verifica se o id é o mesmo do id do processo correspondente */
				return true;			/* Retorna verdadeiro se o processo for encontrado na fila */
			aux = aux->next;			/* Passa para o próximo processo da fila */
		}
	}
	return false;						/* Retorna falso se percorrer toda a fita e não encontrar o processo nela */
} 

void percorrer_fila(pt_fila fifo){

	if (!fila_vazia(fifo)){ 					/* Verifica se a fila NAO esta vazia */
		PCB * aux;								/* Cria um ponteiro para o processo que o verificará se existe este id na fila */
		aux = fifo->pt_inicio;					/* Ponteiro aponta para o inicio na fila */
		while (aux != NULL) {					/* Percorre a fila ate encontrar o processo que contém o id ou chegar ao fim */			/* Retorna verdadeiro se o processo for encontrado na fila */
			fprintf(stderr, "Processo : %d, ",aux->pcb_id);
			aux = aux->next;					/* Passa para o próximo processo da fila */
			Contador++;
			
		}
		fprintf(stderr, "\nQuantidade de processo : %d\n",Contador);
		Contador = 0;
	}else{
		fprintf(stderr, "\nQuantidade de processo : %d\n",Contador);
	}
}


		

/****************************************************************************/
/*                                                                          */
/*				Module CPU				    */
/*			     Internal Routines				    */
/*                                                                          */
/****************************************************************************/





void cpu_init()
{
	fila = (pt_fila*)malloc(10*sizeof(pt_fila));
	int i;
	for(i=0;i<10;i++){
		inicializar_fila(i); 					/* Cria a estrutura da fila de espera*/
	}
	set_timer (Quantum); 					/* Determina o tempo para processo igual ao quantum */	
}

void dispatch()
{
		printf("=============INICIO DISPATCH==========\n");
		fprintf(stderr, "===============================================\n");
		for(i=0;i<10;i++){
			fprintf(stderr, "\n\nFila de Prioridade : %d\n",i);
			percorrer_fila(fila[i]);
		}
	   PCB * proximo_processo;					/* Cria um ponteiro de processo que colocará um processo na fila */
	   if (PTBR != NULL && PTBR->pcb->status == running){ 	/* Verifica se a tabela de páginas não é nula e se há processo executando */ 			
			printf("o processo %d estava rodando \n",PTBR->pcb->pcb_id);
			insert_ready (PTBR->pcb); 			/* Caso esteja, insere o processo que está rodando na fila de pronto */
	   }else
	   		PTBR = NULL; 					/* Se não coloca a tabela de paginas como NULL */

		if(get_clock() >= 49995){		
			//printf("%f Count\n",Count);
			//printf("%f Soma\n",Soma);
			printf("%f media\n",Media);
			//printf("%d Clock\n",get_clock() );
		}



		for(i=0;i<10;i++){
			if (!fila_vazia(fila[i])){ 					/* Verifica se a fila não esta vazia */
				proximo_processo = retirar(fila[i]); 			/* O ponteiro do processo recebe o processo retirado da fila */
				prepage (proximo_processo); 			/* Chama a pre paginação do processo */
				proximo_processo->status = running; 		/* Muda o status do processo para executando */			
				printf("Processo %d , tempo desde o ultimo escalonamento %d, tempo de cpu %d, tempo acumulado %d\n",proximo_processo->pcb_id, get_clock() - proximo_processo->last_dispatch,proximo_processo->last_cpuburst,proximo_processo->accumulated_cpu);			
				printf("Quantum %d\n",*proximo_processo->hook);
				printf("Prioridade %d\n\n", proximo_processo->priority);
				Count++;
				Soma += get_clock() - proximo_processo->last_dispatch;
				Media = Soma/Count;
				set_timer(*proximo_processo->hook);
				proximo_processo->last_dispatch = get_clock();	/* muda a variavel last_dispatch do processo para o tempo atual	*/
				PTBR = proximo_processo->page_tbl;		/* Faz a tabela de paginas apontar para a tabela de páginas do processo retirado */
				break;
			}
	   }
	   printf("=============FIM DISPATCH==========\n");
}



void insert_ready(pcb)
PCB *pcb;
{
		printf("=============INICIO INSERIR==========\n");
		if(pcb->last_dispatch == -1){
			pcb->hook = malloc(sizeof(int));
	   		*pcb->hook = 5;
			pcb->priority = 0;
	   		printf("\nPrimeira vez do processo %d\n",pcb->pcb_id);

		}
		else{
			printf("LAST BURST FOI %d e *pcb->hook é %d\n",pcb->last_cpuburst,*pcb->hook);
			if(pcb->last_cpuburst > *pcb->hook*0.8){
				if(pcb->priority != 9){
					pcb->priority++;
					printf("O processo %d foi inserido na fila de maior prioridade %d\n",pcb->pcb_id, pcb->priority);
					*pcb->hook += 3;
				}				 
				else{
					printf("O processo %d foi inserido na fila de MESMA prioridade %d\n",pcb->pcb_id, pcb->priority);
				}
			}else if( pcb->last_cpuburst < *pcb->hook*0.5 ){
				if(pcb->priority != 0){
					pcb->priority--;
					printf("O processo %d foi inserido na fila de menor prioridade %d\n",pcb->pcb_id, pcb->priority);
					*pcb->hook -= 3; 
				}else{
					printf("O processo %d foi inserido na fila de MESMA prioridade %d\n",pcb->pcb_id, pcb->priority);
				}
			}else{
				printf("O processo %d foi inserido na fila de MESMA prioridade %d\n",pcb->pcb_id, pcb->priority);
			}
		}
	    if (!esta_na_fila(pcb->pcb_id,fila[pcb->priority])){ 			/* Verifica se o processo a ser inserido NAO existe na fila */
	 	   	pcb->next = NULL; 							/* Caso não exista, ele não esta na fila de espera e nao tem proximo */
	    	pcb->status = ready; 						/* Seu status e pronto */	
	
	    	inserir(pcb,fila[pcb->priority]); 							/* E insere na fila de pronto */
	    }
		printf("=============FIM INSERIR==========\n");

}

/* end of module */
