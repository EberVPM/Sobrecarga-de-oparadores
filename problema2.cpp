#include <iostream>

class Materia {
private:
    int Clave;
    std::string Nombre, ProfesorTit, LibroTexto;
public:
    Materia() {
        Clave = 0;
        Nombre = " ";
        ProfesorTit = " ";
        LibroTexto = " ";
    }
    Materia(int clave, std::string nombre, std::string profesor, std::string libro) {
        Clave = clave;
        Nombre = nombre;
        ProfesorTit = profesor;
        LibroTexto = libro;
    }

    void Imprime() {
        std::cout << "Clave de la materia: " << Clave << std::endl;
        std::cout << "Nombre de la materia: " << Nombre << std::endl;
        std::cout << "Nombre del profesor: " << ProfesorTit << std::endl;
        std::cout << "Nombre del libro: " << LibroTexto << std::endl;
    }

    void CambioClave(int nuevaClave) {
        Clave = nuevaClave;
    }

    void CambiaProfe(std::string profe) {
        ProfesorTit = profe;
    }

    friend bool operator == (Materia& m1, Materia& m2) {
        return (
                m1.Clave == m2.Clave && m1.Nombre == m2.Nombre &&
                m1.ProfesorTit == m2.ProfesorTit &&
                m1.LibroTexto == m2.LibroTexto
            );
    }

    friend bool operator != (Materia& m1, Materia& m2) {
        return !(m1 == m2);
    }

    friend Materia operator + (Materia& m1, Materia& m2) {
        return Materia(
                       m1.Clave + m2.Clave, m1.Nombre + m2.Nombre,
                       m1.ProfesorTit + m2.ProfesorTit,
                       m1.LibroTexto + m2.LibroTexto);
    }

    friend int operator > (Materia& m1, Materia& m2) {
        return m1.Clave > m2.Clave;
    }

    friend int operator < (Materia& m1, Materia& m2) {
        return m1.Clave < m2.Clave;
    }

    friend std::ostream& operator << (std::ostream& o, Materia& m) {
        o << "Clave: " << m.Clave << std::endl;
        o << "Nombre de la materia: " << m.Nombre << std::endl;
        o << "Nombre del profesor: " << m.ProfesorTit << std::endl;
        o << "Libro de texto: " << m.LibroTexto << std::endl;

        return o;
    }

    friend std::istream& operator >> (std::istream& i, Materia& m) {
        std::cout << "Ingresa la clave: ";
        i >> m.Clave;

        std::cout << "Ingresa el nombre de la materia: ";
        std::cin.ignore();
        i >> m.Nombre;

        std::cout << "Ingresa el nombre del profesor: ";
        std::cin.ignore();
        i >> m.ProfesorTit;

        std::cout << "Ingresa el nombre del libro: ";
        std::cin.ignore();
        i >> m.LibroTexto;

        return i;
    }
};

int main()
{
    int opcion, clave, nuevaClave;
    int clavepro = 1, clavedb = 2;
    std::string maestro;

    Materia Programacion(clavepro, "Programacion", "Francisco", "Programacion");
    Materia BasesDatos(clavedb, "Base de datos", "Antonieta", "DB2");
    Materia hijo, materia_a_reprobar;

    std::cout << "Nueva materia: " << std::endl;
    std::cin >> materia_a_reprobar;

    std::cout << "Suma de materias: " << std::endl;
    hijo = Programacion + BasesDatos;
    std::cout << hijo;

    std::cout << "Igualdad de materias: " << std::endl;
    if (Programacion == BasesDatos) {
        std::cout << "Materias iguales" << std::endl;
    } else if (Programacion != BasesDatos) {
        std::cout << "Materias diferentes" << std::endl;
    }

    std::cout << "Menor y mayor que: " << std::endl;
    if (Programacion > BasesDatos) {
        std::cout << "Progrmacion Mayor" << std::endl;
    } else if (Programacion < BasesDatos) {
        std::cout << "Progrmacion Menor" << std::endl;
    }



    do {
        std::cout << "--------------------------Menu--------------------------" << std::endl;
        std::cout << "1. Cambiar clave de la materia programacion" << std::endl;
        std::cout << "2. Cambiar nombre del maestro de base de datos" << std::endl;
        std::cout << "3. Imprimir todos los datos de la materia base de datos" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la nueva clave: ";
                std::cin >> nuevaClave;

                clavepro = nuevaClave;
                Programacion.CambioClave(nuevaClave);
                break;
            case 2:
                std::cout << "Ingrese el nuevo nombre del maestro: ";
                std::cin >> maestro;

                BasesDatos.CambiaProfe(maestro);
                break;
            case 3:
                BasesDatos.Imprime();
                break;
            case 4:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion incorrecta, intente de nuevo" << std::endl;
        }

    } while (opcion != 4);
    return 0;
}
