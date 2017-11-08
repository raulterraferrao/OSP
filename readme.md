
 # English #
 
 ## Cpu1.intel ##

In the cpu1.intel folder a round-robin scheduling was implemented in the file cpu.c. That is, a process is always interrupted when a quantum of time expires, and a ready queue will be FIFO type.

Each time the process is scaled, the time elapsed since the last time it was scaled will be printed.

There are three parameters:

    par.
    parlow
    par.high

The first parameter will produce a short simulation with the trace on. Par.low will test your program with a low frequency of arrival of new processes; in par.high this frequency is high.



 ## Cpu2.intel ##

In the cpu2.intel folder was implemented round-robin scheduling with variable quantum. That is, a process will be interrupted whenever a quantum of time expires. In the scheduling algorithm there is a priority that takes into account the fraction of the quantum used the last time the process was scaled.

1. if the last time the process was scaled, used less than 10% of the quantum value, then the next quantum will be halved (the minimum limit for quantum is 4);

2. If the last time the process was scaled, you have used more than 90% of the quantum value, then the next quantum will be doubled (the maximum quantum value is 600).

3. Every 10 times that the dispatch function is called, all processes that are in the ready queue and the quantum value used the last time it was scaled are printed in stderr according to the format.

 ### Format ###

 ************************************************************************************************************

*                                               Ready queue printing

* Value of the counter: << value of how much times schedule was invoked >>

* Clock: << got value of getclock () function

*

* [<< first queue process >>, << last quantum value >>]

* [<< second row process id >>, << last quantum value >>]

* ...

* [<< last queue process id >>, << last quantum value >>]


* ************************************************************************************************************

 # Portuguese #
 
 ## Cpu1.intel ##

Na pasta cpu1.intel foi implementado um escalonamento round-robin no arquivo cpu.c . Ou seja, um processo será interrompido sempre que um quantum de tempo expirar, e a fila de pronto será do tipo FIFO.

Para cada vez que o processo for escalado, irá ser impresso o tempo decorrido desde a última vez em que ele foi escalado.

Existem três parâmetros:

    par.avg
    par.low
    par.high

O primeiro parâmetro produzirá uma simulação curta com o trace ligado. O par.low testará seu programa com uma baixa freqüência de chegada de novos processos; em par.high esta frequência é alta.



 ## Cpu2.intel ##

Na pasta cpu2.intel foi implementado escalonamento round-robin com quantum variável. Ou seja, um processo será interrompido sempre que um quantum de tempo expirar. No algoritmo de escalonamento existe uma prioridade que leve em consideração a fração do quantum utilizada na última vez que o processo foi escalado.

1.     caso na última vez em que o processo tenha sido escalado, tenha utilizado menos de 10% do valor do quantum, então o próximo quantum será reduzido à metade (o limite mínimo para o quantum é 4);

2.     caso na última vez em que o processo tenha sido escalado, tenha utilizado mais de 90% do valor do quantum, então o próximo quantum será dobrado. O valor máximo do quantum é 600.

3.     A cada 10 vezes que a função dispatch é chamada, é impresso em stderr todos os processos que estão na fila de pronto, e o valor do quantum utilizado na última vez em que ele foi escalado de acordo com o formato.

 ### Formato ###

 ************************************************************************************************************

*                                              Impressão da fila de pronto

* Valor do contador:      << colocar o valor do contador de qtas vezes schedule foi invocado >>

* Clock:                   << valor obtido da função getclock() >>

*

* [<< id do primeiro processo da fila >>, << valor do último quantum >>]

* [<< id do segundo processo da fila >>, << valor do último quantum >>]

* ...

* [<< id do último processo da fila >>, << valor do último quantum >>]

*

* ************************************************************************************************************