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
*       2.00    jpp     27/12/2019  Documentação das funções
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
*       NOM Armazenar vários nomes de um arquivo txt em uma lista.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça.
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
NOM_tpCondRet NOM_criarListaDeNomes(NOM_tppCabecaNome *listaGrupo, char *nomeArquivoDeNomes, char *numTotalDeAlunos);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       Os nomes que estavam no arquivo txt foram armazenados em uma lista.
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça..
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
*
*
*  $EP Parâmetros
*       $P listaGrupo - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nomes.
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
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça.
*
*
*  $EP Parâmetros
*       $P listaDeGrupos - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de grupos.
*           Este parâmetro é passado por referência.
*       $P listaDeGrupos - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nomes.
*           Este parâmetro é passado por referência.
*       $P numDeGrupos - O parâmetro que receberá o número de grupos a serem
*           criados.
*           Este parâmetro é passado por valor.
*       $P numDeAlunosEmCadaGrupo - O parâmetro que receberá o número de alunos
*           de cada grupo a ser criado.
*           Este parâmetro é passado por valor.
*       $P numTotalDeAlunos - O parâmetro que receberá o número de alunos a
*           serem divididos em grupos.
*           Este parâmetro é passado por valor.
*
****************************************************************************/
NOM_tpCondRet NOM_criarListaDeGrupos(NOM_tppCabecaNome *listaDeGrupos, NOM_tppCabecaNome listaDeNomes, const char numDeGrupos, const char numDeAlunosEmCadaGrupo, char numTotalDeAlunos);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       A lista de grupos foi criada.
*		Valem as assertivas estruturais da lista de nomes duplamente
*       encadeada com cabeça.
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
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
*       NOM Imprimir grupos.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
*
*
*  $EP Parâmetros
*       $P listaDeGrupos - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nomes.
*           Este parâmetro é passado por referência.
*
****************************************************************************/
NOM_tpCondRet NOM_imprimirListaDeGrupos(NOM_tppCabecaNome listaDeGrupos);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       A lista de grupos foi impressa.
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Destruir lista de grupos.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
*
*
*  $EP Parâmetros
*       $P listaDeGrupos - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nomes.
*           Este parâmetro é passado por referência.
*
****************************************************************************/
NOM_tpCondRet NOM_destruirListaDeGrupos(NOM_tppCabecaNome listaDeGrupos);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       A lista de grupos foi destruída.
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Redistribuir lista de grupos randômicamente.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
*
*
*  $EP Parâmetros
*       $P listaDeGrupos - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nomes.
*           Este parâmetro é passado por referência.
*       $P numDeGrupos - O parâmetro que receberá o número de grupos a serem
*           criados.
*           Este parâmetro é passado por valor.
*       $P numDeAlunosEmCadaGrupo - O parâmetro que receberá o número de alunos
*           de cada grupo a ser criado.
*           Este parâmetro é passado por valor.
*       $P numTotalDeAlunos - O parâmetro que receberá o número de alunos a
*           serem divididos em grupos.
*           Este parâmetro é passado por valor.
*
****************************************************************************/
NOM_tpCondRet NOM_redistribuirListaDeGrupos(NOM_tppCabecaNome *listaDeGrupos, const char numDeGrupos, const char numDeAlunosEmCadaGrupo, char numTotalDeAlunos);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       A lista de grupos foi refeita.
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Salvar lista de grupos em um arquivo txt.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
*
*
*  $EP Parâmetros
*       $P listaDeGrupos - O parâmetro que receberá o endereço do ponteiro para
*           a cabeça da lista de nomes.
*           Este parâmetro é passado por referência.
*       $P nomeOutputDeGrupos - O parâmetro que receberá a string do nome do
*           arquivo onde os grupos criados devem ser salvos.
*           Este parâmetro é passado por valor.
*
****************************************************************************/
NOM_tpCondRet NOM_salvarListaDeGrupos(NOM_tppCabecaNome listaDeGrupos, char *nomeOutputDeGrupos);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       A lista de grupos foi salva no txt especficado.
*		Valem as assertivas estruturais da lista de grupos duplamente
*       encadeada com cabeça.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


/****************************************************************************
*
*	$FC Função:
*       NOM Copiar cada caractere de uma string para outra string.
*
*
*   $AE Assertivas de entrada esperadas:
*		Valem as assertivas estruturais do vetor de caracteres.
*
*
*  $EP Parâmetros
*       $P string1 - O parâmetro que receberá o endereço do primeiro caractere
*           da string receptora.
*           Este parâmetro é passado por valor.
*       $P string2 - O parâmetro que receberá o endereço do primeiro caractere
*           da string emissora.
*           Este parâmetro é passado por valor.
*
****************************************************************************/
NOM_tpCondRet NOM_stringCopia(char string1[], char string2[]);
/****************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       string1 recebeu cada caractere da string2.
*		Valem as assertivas estruturais do vetor de caracteres.
*
*
*   $FV Valor retornado
*       NOM_CondRetOK
*
****************************************************************************/


#endif /* NOME_H */