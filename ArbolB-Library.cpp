#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_NUM_LIBROS = 3; // Tamaño máximo de un nodo en el árbol B

// Definición de la estructura Libro
struct Libro {
    string nombre;
    string autor;
    string genero;
};

// Definición de la estructura Nodo para un árbol B
struct Nodo {
    vector<Libro> libros;
    vector<Nodo*> hijos;
};

// Función para insertar un libro en la biblioteca (árbol B)
void insertarLibro(Nodo* raiz, Libro libro) {
    if (raiz->libros.size() < MAX_NUM_LIBROS) {
        raiz->libros.push_back(libro);
    } else {
        // División del nodo lleno
        Nodo* nuevoNodo = new Nodo();
        int medio = raiz->libros.size() / 2;
        for (int i = medio + 1; i < raiz->libros.size(); ++i) {
            nuevoNodo->libros.push_back(raiz->libros[i]);
        }
        raiz->libros.erase(raiz->libros.begin() + medio + 1, raiz->libros.end());

        // Actualización de punteros
        if (raiz->hijos.empty()) {
            raiz->hijos.push_back(nuevoNodo);
        } else {
            Nodo* nodoPadre = raiz->hijos.back();
            nodoPadre->hijos.push_back(nuevoNodo);
        }

        // Manejo de nodos padres
        if (raiz->hijos.size() > MAX_NUM_LIBROS + 1) {
            // Si el nodo padre también está lleno, dividirlo recursivamente
            // Llamar a una función de división de nodos padres aquí si es necesario
        }
    }
}

// Función para buscar un libro en el árbol B
Libro buscarLibro(Nodo* raiz, string nombre) {
	
    for (size_t i = 0; i < raiz->libros.size(); ++i) {
        if (raiz->libros[i].nombre == nombre) {
            return raiz->libros[i]; // Devolver el libro si se encuentra por nombre
        }
    }
    return Libro(); // Devolver un libro vacío si no se encuentra ninguna coincidencia
}

// Función para mostrar todos los libros en la biblioteca
void mostrarBiblioteca(Nodo* raiz) {
    for (size_t i = 0; i < raiz->libros.size(); ++i) {
        cout << "Nombre: " << raiz->libros[i].nombre << " | Autor: " << raiz->libros[i].autor << " | Género: " << raiz->libros[i].genero << endl;
    }
}

// Función para eliminar un libro por nombre en el árbol B
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

    // Creación de libros de ejemplo
    Libro libro1 = {"Jun y sus aventuras", "Fernando", "Comedia"};
    Libro libro2 = {"Pedo", "Gabriel", "Realismo"};
	Libro libro3 = {"nose", "Pedro", "Fantasia"};
	
	
	
    // Insertar libros en la biblioteca (árbol B)
    insertarLibro(biblioteca, libro1);
    insertarLibro(biblioteca, libro2);
	insertarLibro(biblioteca, libro3);

    // Buscar y mostrar libros en el árbol B
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

    // Eliminar libro por nombre en el árbol B
    eliminarLibroPorNombre(biblioteca, "nose");
	cout << " " << endl;
	cout << " " << endl;
	
    cout << "\nBiblioteca después de eliminar el libro:" << endl;
    mostrarBiblioteca(biblioteca);

    delete biblioteca; // Liberar memoria del nodo raíz

    return 0;
}
