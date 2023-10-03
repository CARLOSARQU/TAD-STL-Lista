#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

Nodo *insertar_principio(Nodo *inicio, Nodo *nuevo)
{
    nuevo->siguiente = inicio;
    return nuevo;
}

Nodo *insertar_final(Nodo *inicio, Nodo *nuevo)
{
    if(inicio == nullptr)
        inicio = nuevo;
    else
    {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr)
            aux = aux->siguiente;
        aux->siguiente = nuevo;
    }
    return inicio;
}

Nodo* insertar_ordenado(Nodo* inicio, Nodo* nuevo)
{
    if(inicio == nullptr || nuevo->dato < inicio->dato)
    {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else
    {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->dato < nuevo->dato)
        {
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }
    return inicio;
}

Nodo* generar_nodo(int dato)
{
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;
    return nuevo;
}

void imprimir_lista(Nodo* inicio)
{
    for (Nodo* aux = inicio; aux != nullptr; aux = aux->siguiente)
        cout << aux->dato << " ";
    cout << endl;
}

Nodo* buscar(Nodo* inicio, int datoBuscado) {
    Nodo* aux = inicio;
    while (aux != nullptr && aux->dato != datoBuscado)
        aux = aux->siguiente;
    return aux;
}

Nodo* eliminar(Nodo* inicio, int datoABorrar) {
    if (inicio != nullptr)
    {
        Nodo* aux = inicio;
        if (inicio->dato == datoABorrar)
        {
            inicio = inicio->siguiente;
            delete aux;
        }
        else
        {
            while (aux->siguiente != nullptr && aux->siguiente->dato != datoABorrar)
            {
                aux = aux->siguiente;
            }
            if (aux->siguiente->dato == datoABorrar)
            {
                Nodo* aEliminar = aux->siguiente;
                aux->siguiente = aEliminar->siguiente;
                delete aEliminar;
            }
        }
    }
    return inicio;
}

int contar_elementos(Nodo* inicio)
{
    int cont = 0;
    Nodo* actual = inicio;
    while (actual != nullptr)
    {
        cont++;
        actual = actual->siguiente;
    }
    return cont;
}

Nodo* invertir_lista(Nodo* inicio)
{
    Nodo* previo = nullptr;
    Nodo* actual = inicio;
    Nodo* siguiente = nullptr;

    while (actual != nullptr)
    {
        siguiente = actual->siguiente;
        actual->siguiente = previo;
        previo = actual;
        actual = siguiente;
    }

    return previo;
}

void ejercicio_1()
{
    Nodo *inicio = nullptr;
    int n_aleatorios=0;
    cout << "Ingrese la cantidad de numeros a generar: "; cin>>n_aleatorios;
    for (int i = 0; i < n_aleatorios; i++)
    {
        int numero = rand() % 1000;
        if (numero % 2 == 0)
        {
            Nodo* nuevo = generar_nodo(numero);
            inicio = insertar_ordenado(inicio, nuevo);
        }
        else
            i--;
    }

    cout << "Lista de numeros aleatorios pares:" << endl;
    imprimir_lista(inicio);
}

void ejercicio_2()
{
    Nodo* inicio = nullptr;

    int n;
    cout << "Ingrese la cantidad de numeros a agregar: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int valor;
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> valor;
        Nodo* nuevo = generar_nodo(valor);
        inicio = insertar_final(inicio, nuevo);
    }

    cout << "Lista en orden creciente: ";
    imprimir_lista(inicio);
}

void ejercicio_3()
{
    Nodo* inicio = nullptr;

    int valor;
    do
    {
        cout << "Ingrese un valor (0 para terminar): ";
        cin >> valor;
        if (valor != 0)
        {
            Nodo* nuevo = generar_nodo(valor);
            inicio = insertar_final(inicio, nuevo);
        }
    }
    while (valor != 0);

    cout << "Lista de elementos ingresados:" << endl;
    imprimir_lista(inicio);

    int total_elementos = contar_elementos(inicio);
    cout << "Numero total de elementos (nodos): " << total_elementos << endl;
}

void ejercicio_4()
{
    Nodo* inicio = nullptr;

    int valor;
    cout << "Ingrese elementos de la lista (0 para terminar):" << endl;
    do
    {
        cin >> valor;
        if (valor != 0)
        {
            Nodo* nuevo = generar_nodo(valor);
            inicio = insertar_final(inicio, nuevo);
        }
    }
    while (valor != 0);

    cout << "Lista original:" << endl;
    imprimir_lista(inicio);

    Nodo* lista_invertida = invertir_lista(inicio);

    cout << "Lista invertida:" << endl;
    imprimir_lista(lista_invertida);
}

int main()
{
    ejercicio_1();
    ejercicio_2();
    ejercicio_3();
    ejercicio_4();

    return 0;
}
