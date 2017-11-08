

/****************************************************************************/
/*                                                                          */
/* 			     Module PROCSVC                                 */
/* 			 External Declarations                              */
/*                                                                          */
/****************************************************************************/

#define MAX_PAGE 	16


/* external enumeration constants */
 
typedef enum {
    false, true                         /* the boolean data type            */
} BOOL;

typedef enum {
    running, ready, waiting, done       /* types of status                  */
} STATUS;



/* external type definitions */

typedef struct page_tbl_node PAGE_TBL;
typedef struct event_node EVENT;
typedef struct pcb_node PCB;
typedef struct page_entry_node PAGE_ENTRY;

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


extern struct event_node {
    int    event_id;    /* event id                                         */
    BOOL   happened;    /* indicates if the event has happebed (= true)     */
    PCB    *waiting_q;  /* queue of PCBs suspended on this event            */
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

extern PAGE_TBL *PTBR;                          /* page table base register */


/* external rountines */

extern deallocate(/* pcb  */);
/*  PCB    *pcb;   */
extern purge_iorbs(/* pcb */);
/*  PCB    *pcb;   */
extern giveup_rsrcs(/* pcb */);
/*  PCB    *pcb;   */
extern insert_ready(/* pcb */);
/*  PCB    *pcb;   */

extern purge_sockets(/* pcb */);
/*  PCB    *pcb;   */





/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*                              Module PROCSVC                              */
/*                             Internal Routines                            */
/*                                                                          */
/*                                                                          */
/****************************************************************************/





/*  Note: when an interrupt handler must call dispatch(), this should
          be done *** after *** the rest of the interrupt processing
	  has been done.
*/

void start_handler(pcb)
PCB *pcb;
{

}



void term_handler(pcb)
PCB  *pcb;
{

}



void kill_handler(pcb)
PCB *pcb;
{

}



void wait_handler(event)
EVENT *event;
{

}



void signal_handler(event)
EVENT *event;
{

}

/* end of module */
