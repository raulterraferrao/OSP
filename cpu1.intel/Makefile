###############################################################
#   Students' Makefile for Operating Systems Project          #
#                     Use As Is                               #
###############################################################


# The assignment directory 
ASG_DIR = ~/osp/cpu1.intel/

# The default C compiler 
C_COMP = gcc -no-pie




#make OSP:  

OSP : $(ASG_DIR)osp.o dialog.o cpu.o 
	$(C_COMP) $(ASG_DIR)osp.o dialog.o cpu.o --enable-shared -lm -g -fPIC -o osp

dialog.o : dialog.c
	$(C_COMP) -c -g dialog.c

cpu.o : cpu.c 
	$(C_COMP) -c -g cpu.c 

