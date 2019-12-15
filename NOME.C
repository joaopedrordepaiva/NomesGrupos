/*******************************************************************************
*   $MCI Módulo de implementação: Módulo NOME
*
*   Arquivo gerado:              NOME.C
*   Letras identificadoras:      NOM
*
*   Projeto: Projeto Nome
*   Autores: jpp - João Pedro Paiva
*
*   $HA Histórico de evolução:
*       Versão  Autor   Data        Observações
*       1.00    jpp     11/12/2019  Início do desenvolvimento
*
*******************************************************************************/

#include "LISTA.H"
#include "NOME.H"
#include <stdlib.h>
#include <stdio.h>

/********************** Variáveis encapuladas no módulo ***********************/

/**************** Protôtipos das funções encapuladas no módulo ****************/

static unsigned char NOM_comprimentoNome(char *stringNome);

/***************** Código das funções exportadas pelo módulo ******************/

/*******************************************************************************
*
*	$FC Função:
*       NOM Armazenar um nome em uma lista.
*
*******************************************************************************/
NOM_tpCondRet NOM_criarNome(NOM_tppCabecaNome *listaNome, char *stringNome)
{

    unsigned char comprimentoNome, numNosListaNome;

    char *auxStringNome;

    if (LIS_criarLista(free, listaNome) != LIS_CondRetOK)
        return NOM_CondRetFaltouMemoria;

    comprimentoNome = NOM_comprimentoNome(stringNome);

    numNosListaNome = (unsigned char)comprimentoNome / 8;

    do
    {
        auxStringNome = (char *)malloc(8);
        if (!auxStringNome)
            return NOM_CondRetFaltouMemoria;

        for (int i = 0; i < 8; i++)
        {

            auxStringNome[i] = *stringNome;
            if (!*stringNome)
                break;
            stringNome++;
        }
        LIS_InserirNoApos(*listaNome, auxStringNome);
    } while (numNosListaNome--);

    return NOM_CondRetOK;
}

/*******************************************************************************
*
*	$FC Função:
*       NOM Imprimir um nome em uma lista.
*
*******************************************************************************/
NOM_tpCondRet NOM_imprimirNome(NOM_tppCabecaNome listaNome)
{

    // LIS_tpCondRet condRetDeLista;

    char *stringNoListaNome;

    LIS_vaiParaPrimeiroNo(listaNome);

    do /* Enquanto não chegou ao final da lista */
    {
        LIS_obterConteudo(listaNome, (void **)&stringNoListaNome);

        for (int i = 0; i < 8; i++)
        {
            printf("%c", stringNoListaNome[i]);
            if (!stringNoListaNome[i])
            {
                printf("\n");
                break;
            }
        }
    } while (LIS_vaiParaProximoNo(listaNome) == LIS_CondRetOK);

    return NOM_CondRetOK; /* Retorna condição de teste bem sucedido */
}

/*******************************************************************************
*
*	$FC Função:
*       LIS Destruir lista nó por nó e liberar cabeça da lista.
*
*******************************************************************************/
NOM_tpCondRet NOM_destruirNome(NOM_tppCabecaNome listaNome)
{
    LIS_DestruirLista(listaNome);

    return NOM_CondRetOK;
}

/*******************************************************************************
*
*	$FC Função:
*       NOM Armazenar vários nomes de um arquivo txt em uma lista.
*
*******************************************************************************/
NOM_tpCondRet NOM_criarGrupo(NOM_tppCabecaNome *listaGrupo, char *nomeArquivoDeNomes, char *numTotalDeAlunos)
{

    NOM_tppCabecaNome listaNome;
    FILE *pArquivoDeNomes;
    char stringNome[256];

    if (LIS_criarLista((void (*)(void*)) NOM_destruirNome, listaGrupo) != LIS_CondRetOK)
        return NOM_CondRetFaltouMemoria;

    pArquivoDeNomes = fopen(nomeArquivoDeNomes, "r");

    if (!pArquivoDeNomes)
        return NOM_CondRetFaltouMemoria;

    *numTotalDeAlunos = 0;

    while (fgets(stringNome, 256, pArquivoDeNomes))
    {
        LIS_criarLista(free, &listaNome);
        NOM_criarNome(&listaNome, stringNome);
        LIS_InserirNoApos(*listaGrupo, listaNome);
        ++*numTotalDeAlunos;
    }

    return NOM_CondRetOK;
}

/*******************************************************************************
*
*	$FC Função:
*       NOM Imprimir uma lista de nomes.
*
*******************************************************************************/
NOM_tpCondRet NOM_imprimirGrupo(NOM_tppCabecaNome listaGrupo)
{

    NOM_tppCabecaNome listaNome;

    LIS_vaiParaPrimeiroNo(listaGrupo);

    do /* Enquanto não chegou ao final da lista */
    {
        LIS_obterConteudo(listaGrupo, (void **) &listaNome);
        NOM_imprimirNome(listaNome);

    } while (LIS_vaiParaProximoNo(listaGrupo) == LIS_CondRetOK);

    return NOM_CondRetOK; /* Retorna condição de teste bem sucedido */
}


/*******************************************************************************
*
*	$FC Função:
*       NOM Destruir uma lista de nomes.
*
*******************************************************************************/
NOM_tpCondRet NOM_destruirGrupo(NOM_tppCabecaNome listaGrupo)
{
    LIS_DestruirLista(listaGrupo);

    return NOM_CondRetOK;
}


/*******************************************************************************
*
*	$FC Função:
*       NOM Distribuir nomes em grupos randômicamente.
*
*******************************************************************************/
NOM_tpCondRet NOM_criarListaDeGrupos(NOM_tppCabecaNome *listaDeGrupos, NOM_tppCabecaNome listaGrupo, const char numDeGrupos)
{
    if (LIS_criarLista((void (*)(void*)) NOM_destruirGrupo, listaDeGrupos) != LIS_CondRetOK)
        return NOM_CondRetFaltouMemoria;

    LIS_vaiParaPrimeiroNo(listaGrupo);

    do /* Enquanto não chegou ao final da lista */
    {
        LIS_obterConteudo(listaGrupo, (void **) &listaNome);
        NOM_imprimirNome(listaNome);

    } while (LIS_vaiParaProximoNo(listaGrupo) == LIS_CondRetOK);

    return NOM_CondRetOK; /* Retorna condição de teste bem sucedido */

}


/*******************************************************************************
*
*	$FC Função:
*       NOM Destruir uma lista de grupos.
*
*******************************************************************************/
NOM_tpCondRet NOM_destruirListaDeGrupos(NOM_tppCabecaNome listaDeGrupos)
{
    LIS_DestruirLista(listaDeGrupos);

    return NOM_CondRetOK;
}

/***************** Código das funções encapsuladas no módulo ******************/

/*******************************************************************************
*
*	$FC Função:
*       NOM Calcula o comprimento de uma string nome incluindo o '\0'.
*
*
*	$AE Assertivas de entrada esperadas:
*       string nome possui '\0'.
*
*
*  $EP Parâmetros
*       $P stringNome - O parâmetro que receberá a string nome.
*           Este parâmetro é passado por valor.
*
*******************************************************************************/
unsigned char NOM_comprimentoNome(char *stringNome)
{
    unsigned char comprimentoNome;

    comprimentoNome = 0;

    while (*stringNome)
    {
        stringNome++;
        comprimentoNome++;
    }

    return comprimentoNome++;
}
/*******************************************************************************
*
*	$AS Assertivas de saída esperadas:
*       Comprimento da string nome foi calculado corretamente.
*
*
*   $FV Valor retornado
*       comprimentoNome - o comprimento do nome
*
*******************************************************************************/
