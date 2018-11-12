#ifndef NEGOCIO_H_INCLUDED

typedef struct
{
    int codigoCliente;
    char apellido[51];
    char nombre[51];
    char domicilio[51];
    char telefono[51];
    int isEmpty;
}eCliente;

typedef struct{
 int dia;
 int mes;
 int anio;
}eFecha;

typedef struct
{
    int codigoAlquiler;
    int codigoJuegos;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;
}eAlquiler;

typedef struct
{
    int codigoJuego;
    char descripcion[51];
    int importe;
    int isEmpty;
}eJuegos;

/**
* @brief Desplega un menu para que el usuario seleccione una opcion
* @return Devuelve la opcion elegida por el usuario
*/
int MenuJuegos();


/**
* @brief Inicializa los valores en 0
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - Cantidad del vector
*/
void inicializarJuego(eJuegos* lista,int len);


/**
* @brief Busca el primer espacio disponible.
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
* @return Devuelve la ubicacion del primer espacio disponible o -1(error)
*/
int primerEspacioligre(eJuegos* lista, int len);


/**
* @brief Agrega los datos del juego
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
* @param altaBanderaJuego - Cambia el valor si se ingresa un dato
* @return Devuelve la ubicacion o -1 para indicar error
*/
int addJuego(eJuegos* lista, int len, int* altaBanderaJuego);


/**
* @brief Busca el juego por codigo ingresado
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
* @param codigo - Codigo del juego a buscar
* @return Devuelve la ubicacion donde se encuentra el juego
*/
int findJuego(eJuegos* lista, int len,int codigo);


/**
* @brief Elimina datos del juego ingresado por codigo
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
*/
void BajaJuego(eJuegos* lista, int len);


/**
* @brief Imprime la lista de juegos
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
*/
void imprimirListaJuegos(eJuegos* lista,int len);


/**
* @brief Ordena por importe y descripcion
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
*/
void ordenarJuegos(eJuegos* lista, int len);


/**
* @brief Modifica los datos de un juego
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
*/
void modificarJuego(eJuegos* lista,int len);

/**
* @brief Inicializa los valores en 0
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - Cantidad del vector
*/
void inicializarCliente(eCliente* lista,int len);


/**
* @brief Busca el primer espacio disponible.
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
* @return Devuelve la ubicacion del primer espacio disponible o -1(error)
*/
int primerEspacioCliente(eCliente* lista, int len);


/**
* @brief Agrega los datos del cliente
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
* @param altaBanderaCliente - Cambia el valor si se ingresa un dato
*/
void addCliente(eCliente* lista, int len,int *altaBanderaCliente);


/**
* @brief Busca el cliente por codigo ingresado
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
* @param codigo - Codigo del cliente a buscar
* @return Devuelve la ubicacion donde se encuentra el cliente
*/
int findCliente(eCliente* lista, int len,int codigo);


/**
* @brief Desplega un menu para que el usuario seleccione una opcion
* @return Devuelve la opcion elegida por el usuario
*/
int menuClientes();


/**
* @brief Elimina datos del cliente ingresado por codigo
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
*/
void bajaCliente(eCliente* lista,int len);


/**
* @brief Modifica los datos de un cliente
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
*/
void modificarCliente(eCliente* lista,int len);


/**
* @brief Imprime la lista de Clientes
* @param eJuegos* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
*/
void imprimirListaClientes(eCliente* lista,int len);


/**
* @brief Ordena por apellido y nombre
* @param eJuegos* Cliente - Una lista de la estructura de clientes
* @param len - cantidad del vector
*/
void ordenarClientes(eCliente* lista, int len);


void addAlquiler(eCliente* listaC,int lenC,eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA);
int primerEspacioAlquiler(eAlquiler* lista,int len);
void inicializarAlquiler(eAlquiler* lista,int len);
void imprimirListaAlquileres(eAlquiler* listaA,int lenA);

//Informes

void promedioJuegosAlquilados(eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA);
void alquilerJuegoDeterminado(eCliente* listaC,int lenC,eAlquiler* listaA,int lenA,int codigoJ);
void alquilerClienteDeterminado(eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA,int codigoC);
void juegoMenosAlquilado(eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA);
void clienteMasAlquileres(eCliente* listaC,int lenC,eAlquiler* listaA,int lenA);
void ordenarJuegosInforme(eJuegos* lista, int len);
void juegoFechaDeterminada(eJuegos* listaJ,int lenJ ,eAlquiler* listaA, int lenA);
void clienteFechaDeterminada(eCliente* listaC,int lenC ,eAlquiler* listaA, int lenA);
#endif//NEGOCIO_H_INCLUDED
