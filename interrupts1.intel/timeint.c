

/****************************************************************************/
/*                                                                          */
/* 			     Module TIMEINT                                 */
/*			 External Declarations                              */
/*                                                                          */
/****************************************************************************/



/* external defined constants */

#define MAX_PAGE       16                 /* max size of page tables        */



/* external enumeration constants */

typedef enum {
    false, true                         /* the boolean data type            */
} BOOL;



/* exteral type definitions */

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



/* external variables */

extern PAGE_TBL *PTBR;                          /* page table base register */

extern int    Quantum;          /* global time quantum; contains the value
                                   entered at the beginning or changed
                                   at snapshot. Has no effect on timer
                                   interrupts, unless passed to set_timer() */




/* external routines */

extern set_timer(/* time_quantum */);
/*  int    time_quantum; */





/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*                              Module TIMEINT                              */
/*                             Internal Routines                            */
/*                                                                          */
/*                                                                          */
/****************************************************************************/





void timeint_handler()
{

}

/* end of module */
