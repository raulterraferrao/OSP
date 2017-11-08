###############################################################
#   Students' Makefile for Operating Systems Project          #
#                     Use As Is                               #
###############################################################


# The assignment directory 
ASG_DIR = /home/osp/interupts2.intel/

# The default C compiler 
C_COMP = cc 


#make OSP:  

OSP : $(ASG_DIR)osp.o dialog.o inter.o timeint.o procsvc.o pageint.o devint.o iosvc.o 
	$(C_COMP) $(ASG_DIR)osp.o dialog.o inter.o timeint.o procsvc.o pageint.o devint.o iosvc.o  -lm -g -o OSP

dialog.o : dialog.c
	$(C_COMP) -c -g dialog.c

inter.o : inter.c 
	$(C_COMP) -c -g inter.c 

timeint.o : timeint.c 
	$(C_COMP) -c -g timeint.c 

procsvc.o : procsvc.c 
	$(C_COMP) -c -g procsvc.c 

pageint.o : pageint.c 
	$(C_COMP) -c -g pageint.c 

devint.o : devint.c 
	$(C_COMP) -c -g devint.c 

iosvc.o : iosvc.c 
	$(C_COMP) -c -g iosvc.c 

