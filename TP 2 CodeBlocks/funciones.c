#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "funciones.h"

float getFloatx(float *pResultado,
          char *pMensaje,
          char *pMensajeError,
          float minimo,
          float maximo,
          int reintentos)
{
    int retorno = -1;
    float buffer;

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%f",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = 0;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >= 0);

    }
    return retorno;//VA A RETORNAR 0 SI ESTA TODOOK
}

int utn_getNumero(int * pResultado, char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos)
{

    int todoOk;
    int auxNumero = 1;
    while (reintentos>0)
    {
        printf(mensaje);
        if (getInt(&auxNumero))
        {
            if (auxNumero<=maximo && auxNumero>=minimo)
                break ;
        }
        fflush(stdin); //EN LINUX UTILIZAR __fpurge(stdin)
        reintentos--;
        printf(mensajeError);

    }
    if (reintentos==0)
    {
        todoOk=0;
    }
    else
    {
        todoOk=1;
        *pResultado = auxNumero;
    }
    return todoOk;
}

int getInt( int * pResultado)
{
    int todoOk=0;
    char buffer[64];
    scanf( "%s",buffer);
    if (esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        todoOk=1;
    }
    return todoOk;
}

int esNumerica ( char * cadena)
{
    int i=0;
    int todoOk = 1;
    if (cadena != NULL && strlen(cadena) > 0)
    {
        while (cadena[i] != '\0' )
        {
            if (cadena[i] < '0' || cadena[i] > '9' )
            {
                todoOk = 0;
                break ;
            }
            i++;
        }
    }
    return todoOk;
}

int utn_getFloat(float * pResultado, char * mensaje,char * mensajeError,float minimo,float maximo,int reintentos)
{

    int todoOk;
    float num;
    while (reintentos>0)
    {
        printf(mensaje);
        if (getFloat(&num)==1){
            if (num >= minimo && num <= maximo){
                todoOk=1;
                *pResultado = num;
                todoOk=1;
            }

        }
        fflush(stdin); //EN LINUX UTILIZAR __fpurge(stdin)
        reintentos--;
        printf(mensajeError);
    }
    if (reintentos==0)
    {
        todoOk=0;
    }

    return todoOk;
}

int getFloat( float * pResultado)
{
    int todoOk = 0;
    char buffer[64];
    scanf( "%s",buffer);
    if (esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        todoOk=1;
    }
    return todoOk;
}


int getString(char *pResultado,char *pMensaje,char *pMensajeError,char minimo,char maximo,int reintentos)
{

    int todoOk = 0;
    char buffer[100];

    if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo < maximo && reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            buffer[strlen(buffer)-1] = '\0';
            if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
            {
                strncpy(pResultado,buffer,maximo+1);
                todoOk = 1;
                break;
            }
            printf("%s",pMensajeError);
            reintentos--;
        }
        while(reintentos >=0);
    }
    return todoOk;
}


