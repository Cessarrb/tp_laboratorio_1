#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size=0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int i;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;

			for(i=0;i<nodeIndex;i++)
			{
				pNode = pNode->pNextNode;
			}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nodoAnterior;
    Node* nodoNuevo;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) //uso el <= para cuando queres agregar uno al final
    {
    	nodoNuevo = (Node*) malloc(sizeof(Node*));

    	if(nodoNuevo != NULL)
    	{
    		nodoNuevo->pElement = pElement; //le asigno la direccion al dato

    		if(nodeIndex==0) //por si es el primer nodo
    		{
    			nodoNuevo->pNextNode = this->pFirstNode; //guardo en el primer nodo la direccion de lo que apuntaba el nodo anterior
    			this->pFirstNode = nodoNuevo; //la lista apuntaria al nuevo primer nodo, si la lista esta vacia pNextNode queda en NULL
    		}
    		else
    		{
    			nodoAnterior = getNode(this, nodeIndex-1);
    			nodoNuevo->pNextNode = nodoAnterior->pNextNode; //al nuevo nodo le asigno a lo que apuntaba el nodo anterior, y si es el ultimo queda en NULL
    			nodoAnterior->pNextNode = nodoNuevo; //al nodo que apunta al siguiente nodo le asigno la direccion del nuevo nodo
    		}
			this->size++;
			returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo;

    if(this != NULL && index >=0 && index <=ll_len(this))
    {
    	pNodo = getNode(this, index);

    	if(pNodo != NULL)
    	{
    		returnAux = pNodo->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAuxNodo;


    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	pAuxNodo=getNode(this, index); //puedo cambiarlo por un ll_Get?
    	if(pAuxNodo!=NULL)
    	{
    		pAuxNodo->pElement=pElement;
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int returnAux = -1;
    Node* pNodoEliminar;
    Node* pNodoAnterior;

    if(this != NULL && index >=0 && index < ll_len(this))
    {
		pNodoEliminar = getNode(this, index); //asigno el nodo que se va a eliminar
    	if(index==0)
    	{
    		this->pFirstNode=pNodoEliminar->pNextNode; //a la lista que apunta al primer nodo le asigno lo que apuntaba el nodo que se va a eliminar
    	}
    	else
    	{
    		pNodoAnterior = getNode(this, index-1);
    		pNodoAnterior->pNextNode = pNodoEliminar->pNextNode; //al nodo anterior hago que apunte a lo que apuntaba el nodo antes de ser eliminado
    	}
    	this->size--;
    	free(pNodoEliminar);
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
    	for(i=ll_len(this);i>=0;i--) // aca tendria que poner ll_len-1?
    	{
    		ll_remove(this, i);
    	}
    	if(ll_len(this)==0)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this); //verificar retorno con una condicion y ahi usar el free(this)*
    	free(this);
    	this = NULL;
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNodoAux;
    int i;

    if(this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
			pNodoAux = getNode(this, i); //modificar por ll_get
			if(pNodoAux->pElement == pElement)
			{
				returnAux = i;
				break;
			}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this)!=0)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1; //puedo sacar este else y este returno ponerle en otro lado
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >=0 && index <= ll_len(this))
    {
		returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >=0 && index <= ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	//puedo poner returnAux = 0 aca creo
		if(ll_indexOf(this, pElement)!=-1)
		{
			returnAux = 1;
		}
		else
		{
			returnAux = 0; //puedo sacar este else y este returno ponerle en otro lado
		}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pNodoAux;

    if(this != NULL && this2 != NULL)
    {
    	if(ll_len(this2)!=0)
    	{
    		for(i=0;i<ll_len(this2);i++)
			{
    			//aca podria poner el returnAux = 1
				pNodoAux = ll_get(this2, i);
				if(!ll_contains(this, pNodoAux))
				{
					returnAux = 0;
					break;
				}
				else
				{
					returnAux = 1; //puedo sacar este else y este returno ponerle en otro lado
				}
			}
    	}
    	else
    	{
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pNodoAux = NULL;
	int i;

    if(this != NULL && (from >=0 && from <= ll_len(this)) && (to > from && to <= ll_len(this)))
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(i=from;i<to;i++)
    		{
    			pNodoAux = ll_get(this, i);
    			if(pNodoAux != NULL)
    			{
    				addNode(cloneArray, i, pNodoAux);
    			}
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		cloneArray = ll_subList(this, 0, ll_len(this)); //aca el len serie menos 1?
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    void* pElementoUno;
    void* pElementoDos;
    void* pElementoAux;
    int validacionOrden;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
	{
    	for(i=0;i<ll_len(this)-1;i++)
    	{
    		pElementoUno = ll_get(this, i);
    		for(j=i+1;j<ll_len(this);j++)
    		{
    			pElementoDos = ll_get(this, j);
    			validacionOrden = pFunc(pElementoUno, pElementoDos);

    			if((order == 1 && (validacionOrden == 1 )) ||
    				(order == 0	&& (validacionOrden == -1)))
    			{
    				pElementoAux = pElementoUno;
    				pElementoUno = pElementoDos;
    				pElementoDos = pElementoAux;
    			}
    			ll_set(this, i, pElementoUno);
    			ll_set(this, j, pElementoDos);
    		}
    	}
    	returnAux = 0;
	}

    return returnAux;

}
