#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "ArrayEmployees.h"


int utn_getNumero(int * pResultado, char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);
int getInt( int * pResultado);
int esNumerica ( char * cadena);
int utn_getFloat(float * pResultado, char * pMensaje,char * pMensajeError,float minimo,float maximo,int reintentos);
int getFloat( float * pResultado);
int getString(char *pResultado,char *pMensaje,char *pMensajeError,char minimo,char maximo,int reintentos);
float getFloatx(float *pResultado,
          char *pMensaje,
          char *pMensajeError,
          float minimo,
          float maximo,
          int reintentos);

#endif // FUNCIONES_H_INCLUDED
