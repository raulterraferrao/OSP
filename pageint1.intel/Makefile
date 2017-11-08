###############################################################
#   Students' Makefile for Operating Systems Project          #
#                     Use As Is                               #
###############################################################


# The assignment directory 
ASG_DIR = /home/osp/pageint1.intel/

# The default C compiler 
C_COMP = cc 


#make OSP:  

OSP : $(ASG_DIR)osp.o dialog.o pageint.o 
	$(C_COMP) $(ASG_DIR)osp.o dialog.o pageint.o  -lm -g -o OSP

dialog.o : dialog.c
	$(C_COMP) -c -g dialog.c

pageint.o : pageint.c 
	$(C_COMP) -c -g pageint.c 

