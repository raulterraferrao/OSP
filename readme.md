
 ## Cpu1.intel ##

Na pasta cpu1.intel foi implementado um escalonamento round-robin no arquivo cpu.c . Ou seja, um processo será interrompido sempre que um quantum de tempo expirar, e a fila de pronto será do tipo FIFO.

Para cada vez que o processo for escalado, irá ser impresso o tempo decorrido desde a última vez em que ele foi escalado.

Existem três parâmetros:

    par.avg
    par.low
    par.high

O primeiro parâmetro produzirá uma simulação curta com o trace ligado. O par.low testará seu programa com uma baixa freqüência de chegada de novos processos; em par.high esta frequência é alta.



 ## Cpu2.intel ##

Os critérios são os seguintes:

Na pasta cpu2.intel foi implementado escalonamento round-robin com quantum variável. Ou seja, um processo será interrompido sempre que um quantum de tempo expirar. No algoritmo de escalonamento existe uma prioridade que leve em consideração a fração do quantum utilizada na última vez que o processo foi escalado.

1.     caso na última vez em que o processo tenha sido escalado, tenha utilizado menos de 10% do valor do quantum, então o próximo quantum será reduzido à metade (o limite mínimo para o quantum é 4);

2.     caso na última vez em que o processo tenha sido escalado, tenha utilizado mais de 90% do valor do quantum, então o próximo quantum será dobrado. O valor máximo do quantum é 600.

3.     A cada 10 vezes que a função dispatch é chamada, é impresso em stderr todos os processos que estão na fila de pronto, e o valor do quantum utilizado na última vez em que ele foi escalado de acordo com o formato.

 ### Formato ###

 ************************************************************************************************************

*                                              Impressão da fila de pronto

* Valor do contador:      <<colocar o valor do contador de qtas vezes schedule foi invocado>>

* Clock:                        <<valor obtido da função getclock()

*

* [<<id do primeiro processo da fila>>, <<valor do último quantum>>]

* [<<id do segundo processo da fila>>, <<valor do último quantum>>]

* ...

* [<<id do último processo da fila>>, <<valor do último quantum>>]

*

* ************************************************************************************************************