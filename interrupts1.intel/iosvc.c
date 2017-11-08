


/****************************************************************************/
/*                                                                          */
/* 			     Module IOSVC                                   */
/*			External Declarations				    */
/*                                                                          */
/****************************************************************************/


#define MAX_PAGE        16              /* max num of pages in a process */


/* external enumeration constants */

typedef enum {
    false, true                         /* the boolean data type            */
} BOOL;

typedef enum {
    read, write                         /* type of actions for I/O requests */
} IO_ACTION;

typedef enum {
    running, ready, waiting, done       /* types of status                  */
} STATUS;



/* external type definitions */

typedef struct page_tbl_node PAGE_TBL;
typedef struct event_node EVENT;
typedef struct ofile_node OFILE;
typedef struct pcb_node PCB;
typedef struct iorb_node IORB;



/* external data structures */

extern struct pcb_node {
    int    pcb_id;         /* PCB id                                        */
    int    size;           /* process size in bytes; assigned by SIMCORE    */
    int    creation_time;  /* assigned by SIMCORE                           */
    int    last_dispatch;  /* last time the process was dispatched          */
    int    last_cpuburst;  /* length of the previous cpu burst              */
    int    accumulated_cpu;/*accumulated CPU time                           */
    PAGE_TBL *page_tbl;    /* page table associated with the PCB            */
    STATUS status;         /* status of process                             */
    EVENT  *event;         /* event upon which process may be suspended     */
    int    priority;       /* user-defined priority; used for scheduling    */
    PCB    *next;          /* next pcb in whatever queue                    */
    PCB    *prev;          /* previous pcb in whatever queue                */
    int    *hook;          /* can hook up anything here                     */
};

extern struct iorb_node {
    int    iorb_id;     /* iorb id                                          */
    int    dev_id;      /* associated device; index into the device table   */
    IO_ACTION action;   /* read/write                                       */
    int    block_id;    /* block involved in the I/O                        */
    int    page_id;     /* buffer page in the main memory                   */
    PCB    *pcb;        /* PCB of the process that issued the request       */
    EVENT  *event;      /* event used to synchronize processes with I/O     */
    OFILE  *file;       /* associated entry in the open files table         */
    IORB   *next;       /* next iorb in the device queue                    */
    IORB   *prev;       /* previous iorb in the device queue                */
    int    *hook;       /* can hook up anything here                        */
};



/* external variables */

extern PAGE_TBL *PTBR;                          /* page table base register */


/* external routines */

extern enq_io(/* iorb */);
/* IORB   *iorb; */





/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*                              Module IOSVC                                */
/*                            Internal Routines                             */
/*                                                                          */
/*                                                                          */
/****************************************************************************/





void iosvc_handler(iorb)
IORB *iorb;
{

}

/* end of module */
