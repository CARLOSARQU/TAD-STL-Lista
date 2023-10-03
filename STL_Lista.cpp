#include <iostream>
#include <list>

using namespace std;


void ejercicio_1_STL()
{
    list<int> listaEnlazada;
    int n_aleatorios;
    cout << "Ingrese la cantidad de numeros a generar: "; cin>>n_aleatorios;
    for (int i = 0; i < n_aleatorios; i++)
    {
        int numero = rand() % 1000;
        if (numero % 2 == 0)
        {
            listaEnlazada.push_back(numero);
        }
        else
            i--;
    }
    cout << "Lista de numeros aleatorios pares:" << endl;
    for (const auto& numero : listaEnlazada)
    {
        cout << numero << " ";
    }
    cout << endl;
}

void ejercicio_2_STL()
{
    list<int> listaEnlazada;

    int n;
    cout << "Ingrese la cantidad de numeros a agregar: ";
    cin >> n;

    cout << "Ingrese los numeros uno por uno:" << endl;
    for (int i = 0; i < n; i++) {
        int numero;
        cin >> numero;

        auto it = listaEnlazada.begin();
        while (it != listaEnlazada.end() && *it < numero) {
            ++it;
        }

        listaEnlazada.insert(it, numero);
    }

    cout << "Lista en orden creciente:" << endl;
    for (const auto& numero : listaEnlazada) {
        cout << numero << " ";
    }
    cout << endl;
}

void ejercicio_3_STL()
{
    list<int> listaEnlazada;

    int valor;
    cout << "Ingrese elementos de la lista (0 para terminar):" << endl;
    do {
        cin >> valor;
        if (valor != 0) {
            listaEnlazada.push_back(valor);
        }
    } while (valor != 0);

    cout << "Lista de elementos ingresados:" << endl;
    for (const auto& elemento : listaEnlazada) {
        cout << elemento << " ";
    }
    cout << endl;

    int totalElementos = listaEnlazada.size();
    cout << "Numero total de elementos (nodos): " << totalElementos << endl;
}

void ejercicio_4_STL()
{
    list<int> listaEnlazada;

    int valor;
    cout << "Ingrese elementos de la lista (0 para finalizar):" << endl;
    do {
        cin >> valor;
        if (valor != 0) {
            listaEnlazada.push_back(valor);
        }
    } while (valor != 0);

    cout << "Lista original:" << endl;
    for (const auto& elemento : listaEnlazada) {
        cout << elemento << " ";
    }
    cout << endl;

    listaEnlazada.reverse();

    cout << "Lista invertida:" << endl;
    for (const auto& elemento : listaEnlazada) {
        cout << elemento << " ";
    }
    cout << endl;
}

int main()
{
    ejercicio_1_STL();
    ejercicio_2_STL();
    ejercicio_3_STL();
    ejercicio_4_STL();

    return 0;
}
