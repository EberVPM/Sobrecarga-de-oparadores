#include <iostream>

class Empleado {
private:
    int ClaveEmpleado;
    std::string Nombre, Domicilio, ReportaA;
    float Sueldo;
public:
    Empleado() {
        ClaveEmpleado = 0;
        Nombre = " ";
        Domicilio = " ";
        ReportaA = " ";
        Sueldo = 0;
    }
    Empleado(int clave, std::string nombre, std::string dom, std::string repa, float sueldo) {
        ClaveEmpleado = clave;
        Nombre = nombre;
        Domicilio = dom;
        ReportaA = repa;
        Sueldo = sueldo;
    }
    void Imprime() {
        std::cout << "Clave Empleado: " << ClaveEmpleado << std::endl;
        std::cout << "Nombre: " << Nombre << std::endl;
        std::cout << "Domicilio: " << Domicilio << std::endl;
        std::cout << "Reporta a: " << ReportaA << std::endl;
        std::cout << "Sueldo: " << Sueldo << std::endl;
    }
    void CambiaDomic(std::string domicilio) {
        Domicilio = domicilio;
    }
    void CambiaReporteA(std::string reporte) {
        ReportaA = reporte;
    }
    void ActualSueldo(float sueldo) {
        Sueldo += (Sueldo * sueldo) / 100;
    }

    friend bool operator == (Empleado& empleado1, Empleado& empleado2) {
        return (
                empleado1.ClaveEmpleado == empleado2.ClaveEmpleado &&
                empleado1.Nombre == empleado2.Nombre &&
                empleado1.Domicilio == empleado2.Domicilio &&
                empleado1.ReportaA == empleado2.ReportaA &&
                empleado1.Sueldo == empleado2.Sueldo
            );
    }

     friend bool operator != (Empleado& e1, Empleado& e2){
        return !(e1 == e2);
    }

    friend Empleado operator + (Empleado& e1, Empleado& e2) {
        return Empleado (e1.ClaveEmpleado + e2.ClaveEmpleado, e1.Nombre + e2.Nombre,
                        e1.Domicilio + e2.Domicilio, e1.ReportaA + e2.ReportaA,
                        e1.Sueldo + e2.Sueldo);
    }

    friend bool operator > (Empleado& e1, Empleado& e2) {
        return e1.Sueldo > e2.Sueldo;
    }

    friend bool operator < (Empleado& e1, Empleado& e2) {
        return e1.Sueldo < e2.Sueldo;
    }

    friend std::istream& operator >> (std::istream& i, Empleado& e) {
        std::cout << "Ingresa la clave: " << std::endl;
        i >> e.ClaveEmpleado;

        std::cout << "Ingresa el nombre: " << std::endl;
        std::cin.ignore();
        i >> e.Nombre;

        std::cout << "Ingresa el domicilio: " << std::endl;
        std::cin.ignore();
        i >> e.Domicilio;

        std::cout << "Ingresa el nombre de reporte: " << std::endl;
        std::cin.ignore();
        i >> e.ReportaA;

        std::cout << "Ingresa el sueldo: " << std::endl;
        i >> e.Sueldo;

        return i;
    }

    friend std::ostream& operator << (std::ostream& o, Empleado& e) {
        o << "Clave: " << e.ClaveEmpleado << std::endl;
        o << "Nombre: " << e.Nombre << std::endl;
        o << "Domicilio: " << e.Domicilio << std::endl;
        o << "Reporta a: " << e.ReportaA << std::endl;
        o << "Sueldo: " << e.Sueldo << std::endl;

        return o;
    }
};

int main()
{
    int opcion, clavePlanta = 1, clavePersonal = 2, clave;
    float sueldo;
    std::string domicilio, reporte;

    Empleado JefePlanta(clavePlanta, "Juan Pablo", "Madagascar, Calle Tortuga #34", "Michael", 100);
    Empleado JefePersonal(clavePersonal, "Michael", "Madagascar, Calle Tortuga #35", "Juan Pablo", 7855.6);
    Empleado nose;

    std::cout << "Suma empleado: " << std::endl;
    nose = JefePersonal + JefePlanta;
    std::cout << nose;


    std::cout << "Igualdad empleados: " << std::endl;
    if (JefePersonal == JefePlanta) {
        std::cout << "Empleados iguales" << std::endl;
    } else if (JefePersonal != JefePlanta) {
        std::cout << "Empleados no iguales" << std::endl;
    }

    std::cout << "Mayor que: " << std::endl;
    if (JefePersonal > JefePlanta) {
        std::cout << "JefePersonal es mayor" << std::endl;
    } else {
        std::cout << "JefePersonal es menor" << std::endl;
    }

    do {
        std::cout << "--------------------Menu--------------------" << std::endl;
        std::cout << "1. Cambiar domicilio de uno de los empleados" << std::endl;
        std::cout << "2. Imprimir los datos de un empleado" << std::endl;
        std::cout << "3. Actualizar sueldo de un empleado" << std::endl;
        std::cout << "4. Cambiar el nombre de reporta a" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;

                if (clave == clavePersonal) {
                    std::cout << "Ingrese el nuevo domicilio: ";
                    std::cin.ignore();
                    std::getline(std::cin, domicilio);
                    JefePersonal.CambiaDomic(domicilio);
                } else if (clave == clavePlanta) {
                    std::cout << "Ingrese el nuevo domicilio: ";
                    std::cin.ignore();
                    std::getline(std::cin, domicilio);
                    JefePlanta.CambiaDomic(domicilio);
                } else  {
                    std::cout << "Clave incorrecta :D" << std::endl;
                }
                break;
            case 2:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;

                if (clave == clavePersonal) {
                    JefePersonal.Imprime();
                } else if (clave == clavePlanta) {
                    JefePlanta.Imprime();
                } else  {
                    std::cout << "Clave incorrecta :D" << std::endl;
                }
                break;
            case 3:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;

                if (clave == clavePersonal) {
                    std::cout << "Ingrese el porcentaje a aumenta: ";
                    std::cin >> sueldo;
                    JefePersonal.ActualSueldo(sueldo);
                } else if (clave == clavePlanta) {
                    std::cout << "Ingrese el porcentaje a aumentar: ";
                    std::cin >> sueldo;
                    JefePlanta.ActualSueldo(sueldo);
                } else  {
                    std::cout << "Clave incorrecta :D" << std::endl;
                }
                break;
            case 4:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;

                if (clave == clavePersonal) {
                    std::cout << "Ingrese el nuevo nombre: ";
                    std::cin.ignore();
                    std::getline(std::cin, reporte);
                    JefePersonal.CambiaReporteA(reporte);
                } else if (clave == clavePlanta) {
                    std::cout << "Ingrese el nuevo nombre: ";
                    std::cin.ignore();
                    std::getline(std::cin, reporte);
                    JefePlanta.CambiaReporteA(reporte);
                } else  {
                    std::cout << "Clave incorrecta :D" << std::endl;
                }
                break;
            case 5:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion incorrecta :(" << std::endl;
        }

    } while (opcion != 5);
    return 0;
}
