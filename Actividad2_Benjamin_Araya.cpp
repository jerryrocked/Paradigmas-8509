//Nombre: Benjamin Araya
//rut: 19.323.060-1

#include <stdio.h>
#include <stdlib.h>

//estructura nodo
struct Nodo{
	int valor;
	struct Nodo *sig; // puntero de tipo struct Nodo
};

typedef struct Nodo tNodo; //tipo de dato tNodo
typedef tNodo *Lista;      //tipo de dato puntero tNodo

Lista CreaNodo(int valorNodo){
	/*variable auxiliar que contiene una direccion
	de memoria de un nodo*/
	Lista aux;
	/*solicitar memoria para un nuevo nodo*/
	aux = (Lista)malloc(sizeof(tNodo));
	/*verificar si hay memoria*/
	if(aux != NULL){
		aux->valor = valorNodo;
		aux->sig = NULL;
	}
	return aux;
}

void MostrarLista(Lista L){
    Lista aux = L; //puntero auxiliar para recorrer la lista
    printf("L ->");
    while(aux != NULL){
        //imprimir el valor
        printf("%d -> ",aux->valor);
        //auxiliar pasa al siguiente
        aux = aux->sig;
    }
    printf("NULL\n");
}

Lista InsertarAlPrincipio(Lista L, int x){
    Lista pNodo; //Puntero auxiliar
    pNodo = CreaNodo(x); //nuevo nodo con valor x
    pNodo->sig = L; //sig de nuevo nodo apunta al primero
    L = pNodo; //el nuevo nodo queda primero
    pNodo = NULL;
    return L;
}

Lista InsertarAlFinal(Lista L, int x){
    Lista pNodo, aux;
    pNodo = CreaNodo(x);
    aux = L;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = pNodo;
    pNodo = NULL;
    return L;
}

//Calcular largo de la lista
int LargoLista(Lista L){
    Lista aux = L;
    int n = 0;
    while (aux != NULL){
        aux = aux->sig;
        n++;
    }
    return n;
}

Lista InsertarEnPosicionP(Lista L, int x, int p){
    Lista aux,pNodo;
    int n,i = 0;
    n = LargoLista(L);
    if ((p < 0) || (p > n)){
        printf("Posicion no valida\n");
    }
    else{
        if (p == 0){
            L = InsertarAlPrincipio(L,x);
        }
        else if(p == n){
            L = InsertarAlFinal(L,x);
        }
        else {
            aux = L;
            pNodo = CreaNodo(x);
            while(i < (p-1)){
                aux = aux->sig;
                i++;
            }
            pNodo->sig = aux->sig;
            aux->sig = pNodo;

        }
    }
    pNodo = NULL;
    aux = NULL;
    return L;
}

/*buscar elemento en la lista
0: no esta el elemento
1: el elemento esta en la lista*/
int BuscarElemento(Lista L, int x){
    Lista aux = L;
    while(aux != NULL){
        if (aux->valor == x)
            return 1;
        aux = aux->sig;
    }
    return 0;
}

Lista EliminarElemento(Lista L, int x){
    Lista aux,aux2;
    //consultar si esta el elemento
    if(BuscarElemento(L,x) == 1){
        aux = L;
        /*Verificar si el elemento es el primero*/
        if(aux->valor == x){
            L = L->sig;
            aux->sig = NULL;
            free(aux); //Se libera el nodo
        }
        else{
            while(aux != NULL){
                if(aux->sig->valor == x) //si el valor siguiente es x, hacemos un break (Queremos pararnos en el valor anterior al que queremos eliminar)
                    break;
                aux = aux->sig; //si no cumple if, seguimos al siguiente valor
            }
            aux2 = aux->sig; //pongo al aux2 en el elemento que quiero eliminar
            aux->sig = aux2->sig; //linkeo aux->sig al valor siguiente del que quiero elminar
            aux2->sig = NULL; //deslinkeo el aux2->sig (donde esta el valor que quiero elminar)
            free(aux2); //libero el aux2 ya que ya no es necesario

        }
    }
    aux = NULL;
    aux2 = NULL;
    return L;
}

Lista EliminarPosicionP(Lista L, int p){
    Lista aux,aux2;
    int n, i;
    n = LargoLista(L);
    if((p < 0) || (p >= n))
        printf("Esta fuera del rango");
    else{
        aux = L;
        if(p == 0) { //Si esque se quiere elminar la primera posicion
            L = L->sig;
            aux->sig = NULL;
            free(aux);
        }
        else{
            //Aca se elimina la posicion deseada (que no sea la primera)
            while(i < (p-1)){
                aux = aux->sig;
                i++;
            }
            aux2 = aux->sig;
            aux->sig = aux2->sig;
            aux2->sig = NULL;
            free(aux2);

        }

    }
    aux = NULL;
    aux2 = NULL;
    return L;
}

Lista ActualizarPosicionP(Lista L, int p, int x){
    Lista aux;
    int n, i = 0;
    n = LargoLista(L);
    if((p < 0) || (p >= n))
        printf("Esta fuera del rango");
    else {
        aux = L;
        while(i < p){
            aux = aux->sig;
            i++;
        }
        //printf("aux->valor: %d\n",aux->valor);
        aux->valor = x; //Actualizo el valor
    }
    aux = NULL;
    return L;
}

Lista AnularLista(Lista L){
    Lista aux = L;
    while(aux != NULL){
        L = aux->sig;
        aux->sig = NULL;
        free(aux);
        aux = L;
    }
    return L;
}

int LocalizarElemento(Lista L,int x){
    Lista aux = NULL;
    int i = 0;
    if(BuscarElemento(L,x) == 1){
        aux = L;
        while(aux != NULL){
            if(aux->valor == x){
                aux = NULL;
                return i;
            }
            aux = aux->sig;
            i++;
        }
    }
    else
        return -1;
}



int main(){
	Lista L = NULL, ptr;
	int n,x,p,p1;
  printf("LISTA VACIA:\n");
	MostrarLista(L);
	n = LargoLista(L);
	printf("Largo: %d\n",n);
  printf("INSERTAR NUMERO AL INICIO:\n");
  scanf("%d", &p);
	L = InsertarAlPrincipio(L,p);
	MostrarLista(L);
	n = LargoLista(L);
	printf("Largo: %d\n",n);

  printf("INSERTAR NUMERO AL INICIO:\n");
  scanf("%d", &p);
	L = InsertarAlPrincipio(L,p);
	MostrarLista(L);
	n = LargoLista(L);
	printf("Largo: %d\n",n);

  
	printf("INSERTAR NUMERO AL FINAL:\n");
  scanf("%d", &p);
	L = InsertarAlFinal(L,p);
	MostrarLista(L);
	n = LargoLista(L);
	printf("Largo: %d\n",n);

  printf("INSERTAR EL NUMERO:\n");
  scanf("%d", &p);
  printf("EN POSICION:\n");
  scanf("%d", &p1);
	L = InsertarEnPosicionP(L,p,p1);
	MostrarLista(L);
	n = LargoLista(L);
	printf("Largo: %d\n",n);

  printf("ELIMINAR EL NUMERO:\n");
  scanf("%d", &p);
	L = EliminarElemento(L,p);
	MostrarLista(L);

  printf("ELIMINAR LA POSICION:\n");
  scanf("%d", &p);
	L = EliminarPosicionP(L,p);
	MostrarLista(L);

  printf("ACTUALIZAR LA POSICION:\n");
  scanf("%d", &p1);
  printf("CON EL NUMERO:\n");
  scanf("%d", &p);
	L = ActualizarPosicionP(L,p1,p);
	MostrarLista(L);

  printf("BUSCAR POSICION DE NUMERO:\n");
  scanf("%d", &x);
  printf("Valor[%d] = %d\n",LocalizarElemento(L,x),x);

	return 0;
}
