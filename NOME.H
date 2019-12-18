#ifndef NOME_H
#define NOME_H
/****************************************************************************
*   $MCI Módulo de definição: Módulo NOME
*
*   Arquivo gerado:              NOME.H
*   Letras identificadoras:      NOM
*
*   Projeto: Projeto Nome
*   Autores: jpp - João Pedro Paiva
*
*   $HA Histórico de evolução:
*       Versão  Autor   Data        Observações
*       1.00    jpp     11/12/2019  Início do desenvolvimento
*
*
*   $ED Descrição do módulo
*       Este módulo implementa um conjunto de funções para armazenar nomes em
*       listas duplamente encadeadas.
*
****************************************************************************/

/******************* Declarações exportadas pelo módulo ********************/


/* Tipo referência para uma lista de nomes */
typedef struct LIS_tagLista *NOM_tppCabecaNome;


/****************************************************************************
*
*  $TC Tipo de dados: NOM Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de nome
*
****************************************************************************/
typedef enum
{

    NOM_CondRetOK, /* Concluiu corretamente */

    NOM_CondRetFaltouMemoria /* Faltou memória para allocar */

} NOM_tpCondRet;


/****************************************************************************
*
*	$FC Função:
*       NOM Armazenar um nome em uma lista.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*  $EP Parâmetros
*       $P stringNome - O parâmetro que receberá a string do nome a ser
*           armazenado em forma de lista.
*           Este parâmetro é passado por valor.
*       $P listaNome - O parâmetro que receberá o endereço do ponteiro para
*           o ponnteiro para a cabeça da lista de nome.
*           Este parâmetro é passado por referência.
*
****************************************************************************/
NOM_tpCondRet NOM_criarNome(NOM_tppCabecaNome *listaNome, char *stringNome);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       O nome foi armazenado na lista.
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Imprimir um nome armazenado em forma de lista.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*  $EP Parâmetros
*       $P listaNome - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nome.
*           Este parâmetro é passado por referência.
*
****************************************************************************/
NOM_tpCondRet NOM_imprimirNome(NOM_tppCabecaNome listaNome);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       O nome foi imprimido.
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Destruir um nome armazenado em forma de lista.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*  $EP Parâmetros
*       $P listaNome - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nome.
*           Este parâmetro é passado por referência.
*
****************************************************************************/
NOM_tpCondRet NOM_destruirNome(NOM_tppCabecaNome listaNome);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       O nome foi destruido.
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Armazenar vários nomes de um arquivo txt em uma lista.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça.
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*  $EP Parâmetros
*       $P listaGrupo - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nomes.
*           Este parâmetro é passado por referência.
*       $P nomeArquivoDeNomes - O parâmetro que receberá a string com o nome
*           do arquivo de texto com os nomes.
*           Este parâmetro é passado por valor.
*       $P numTotalDeAlunos - O parâmetro que retornará o número de alunos do
*           do txt.
*           Este parâmetro é passado por referência.
*
****************************************************************************/
NOM_tpCondRet NOM_criarGrupo(NOM_tppCabecaNome *listaGrupo, char *nomeArquivoDeNomes, char *numTotalDeAlunos);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       Os nomes que estavam no arquivo txt foram armazenados em uma lista.
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça..
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetFaltouMemoria
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Imprimir uma lista de nomes.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça.
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*  $EP Parâmetros
*       $P listaGrupo - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nomes.
*           Este parâmetro é passado por referência.
*
****************************************************************************/
NOM_tpCondRet NOM_imprimirGrupo(NOM_tppCabecaNome listaGrupo);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       Os nomes que estavam na lista foram impressos.
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça..
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Destruir uma lista de nomes.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça.
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*  $EP Parâmetros
*       $P listaNome - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nome.
*           Este parâmetro é passado por referência.
*
****************************************************************************/
NOM_tpCondRet NOM_destruirGrupo(NOM_tppCabecaNome listaGrupo);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       O grupo foi destruido.
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça.
*		Valem as assertivas estruturais da nome em lista duplamente encadeada
*       com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Distribuir nomes em grupos randômicamente.
*
****************************************************************************/
NOM_tpCondRet NOM_criarListaDeGrupos(NOM_tppCabecaNome *listaDeGrupos, NOM_tppCabecaNome listaDeNomes, const char numDeGrupos, const char numDeAlunosEmCadaGrupo, char numTotalDeAlunos);


/****************************************************************************
*
*	$FC Função:
*       NOM Imprimir uma lista de grupos.
*
****************************************************************************/
NOM_tpCondRet NOM_imprimirGrupos(NOM_tppCabecaNome listaDeGrupos);


/****************************************************************************
*
*	$FC Função:
*       NOM Destruir uma lista de grupos.
*
****************************************************************************/
NOM_tpCondRet NOM_destruirListaDeGrupos(NOM_tppCabecaNome listaDeGrupos);

#endif /* NOME_H */