#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_NUM_LIBROS = 3; // Tama�o m�ximo de un nodo en el �rbol B

// Definici�n de la estructura Libro
struct Libro {
    string nombre;
    string autor;
    string genero;
};

// Definici�n de la estructura Nodo para un �rbol B
struct Nodo {
    vector<Libro> libros;
    vector<Nodo*> hijos;
};

// Funci�n para insertar un libro en la biblioteca (�rbol B)
void insertarLibro(Nodo* raiz, Libro libro) {
    if (raiz->libros.size() < MAX_NUM_LIBROS) {
        raiz->libros.push_back(libro);
    } else {
        // Divisi�n del nodo lleno
        Nodo* nuevoNodo = new Nodo();
        int medio = raiz->libros.size() / 2;
        for (int i = medio + 1; i < raiz->libros.size(); ++i) {
            nuevoNodo->libros.push_back(raiz->libros[i]);
        }
        raiz->libros.erase(raiz->libros.begin() + medio + 1, raiz->libros.end());

        // Actualizaci�n de punteros
        if (raiz->hijos.empty()) {
            raiz->hijos.push_back(nuevoNodo);
        } else {
            Nodo* nodoPadre = raiz->hijos.back();
            nodoPadre->hijos.push_back(nuevoNodo);
        }

        // Manejo de nodos padres
        if (raiz->hijos.size() > MAX_NUM_LIBROS + 1) {
            // Si el nodo padre tambi�n est� lleno, dividirlo recursivamente
            // Llamar a una funci�n de divisi�n de nodos padres aqu� si es necesario
        }
    }
}

// Funci�n para buscar un libro en el �rbol B
Libro buscarLibro(Nodo* raiz, string nombre) {
	
    for (size_t i = 0; i < raiz->libros.size(); ++i) {
        if (raiz->libros[i].nombre == nombre) {
            return raiz->libros[i]; // Devolver el libro si se encuentra por nombre
        }
    }
    return Libro(); // Devolver un libro vac�o si no se encuentra ninguna coincidencia
}

// Funci�n para mostrar todos los libros en la biblioteca
void mostrarBiblioteca(Nodo* raiz) {
    for (size_t i = 0; i < raiz->libros.size(); ++i) {
        cout << "Nombre: " << raiz->libros[i].nombre << " | Autor: " << raiz->libros[i].autor << " | G�nero: " << raiz->libros[i].genero << endl;
    }
}

// Funci�n para eliminar un libro por nombre en el �rbol B
void eliminarLibroPorNombre(Nodo* raiz, string nombre) {
    for (vector<Libro>::iterator it = raiz->libros.begin(); it != raiz->libros.end(); ++it) {
        if (it->nombre == nombre) {
            raiz->libros.erase(it); // Borrar el libro si se encuentra por nombre
            return;
        }
    }
    cout << "Libro no encontrado." << endl;
}

int main() {
    Nodo* biblioteca = new Nodo();

    // Creaci�n de libros de ejemplo
    Libro libro1 = {"Jun y sus aventuras", "Fernando", "Comedia"};
    Libro libro2 = {"Pedo", "Gabriel", "Realismo"};
	Libro libro3 = {"nose", "Pedro", "Fantasia"};
	
	
	
    // Insertar libros en la biblioteca (�rbol B)
    insertarLibro(biblioteca, libro1);
    insertarLibro(biblioteca, libro2);
	insertarLibro(biblioteca, libro3);

    // Buscar y mostrar libros en el �rbol B
    cout << "Busqueda por nombre:" << endl;
    Libro resultadoNombre = buscarLibro(biblioteca, "Jun y sus aventuras");
    cout << "Libro encontrado - Nombre: " << resultadoNombre.nombre << " | Autor: " << resultadoNombre.autor << " | Genero: " << resultadoNombre.genero << endl;
	cout << " " << endl;
	cout << " " << endl;
	
	cout << "Busqueda por nombre:" << endl;
    Libro resultadoNombre1 = buscarLibro(biblioteca, "nose");
    cout << "Libro encontrado - Nombre: " << resultadoNombre1.nombre << " | Autor: " << resultadoNombre1.autor << " | Genero: " << resultadoNombre1.genero << endl;

	cout << " " << endl;
	cout << " " << endl;
    cout << "\nBiblioteca completa:" << endl;
    mostrarBiblioteca(biblioteca);

    // Eliminar libro por nombre en el �rbol B
    eliminarLibroPorNombre(biblioteca, "nose");
	cout << " " << endl;
	cout << " " << endl;
	
    cout << "\nBiblioteca despu�s de eliminar el libro:" << endl;
    mostrarBiblioteca(biblioteca);

    delete biblioteca; // Liberar memoria del nodo ra�z

    return 0;
}
