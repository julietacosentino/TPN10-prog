#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// --- Código del punto 1: Alumno ---
class Alumno {
public:
    string nombre;
    float nota1, nota2, nota3;
    
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << "\n";
        cout << "Nota 1: " << nota1 << "\n";
        cout << "Nota 2: " << nota2 << "\n";
        cout << "Nota 3: " << nota3 << "\n\n";
    }
};

// --- Código del punto 2: Persona ---
class Persona {
public:
    string nombre;
    int edad;
    Persona(string n, int e) : nombre(n), edad(e) {}
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

// --- Código del punto 3: Rectángulo ---
class Rectangulo {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const { return base * altura; }
    double calcularPerimetro() const { return 2 * (base + altura); }
    void mostrarDatos() const {
        cout << "Base: " << base << ", Altura: " << altura 
             << ", Área: " << calcularArea() 
             << ", Perímetro: " << calcularPerimetro() << endl;
    }
};

// --- Código del punto 4: Cuenta Bancaria ---
class CuentaBancaria {
private:
    string numeroCuenta;
    string nombreTitular;
    double saldo;
public:
    CuentaBancaria(string numero, string nombre, double saldoInicial)
        : numeroCuenta(numero), nombreTitular(nombre), saldo(saldoInicial) {}
    string obtenerNumeroCuenta() const { return numeroCuenta; }
    void depositar(double cantidad) { if (cantidad > 0) saldo += cantidad; }
    void retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) saldo -= cantidad;
        else cout << "Fondos insuficientes o cantidad inválida." << endl;
    }
    void mostrarDatos() const {
        cout << "Número de cuenta: " << numeroCuenta << endl;
        cout << "Nombre del titular: " << nombreTitular << endl;
        cout << "Saldo: " << saldo << endl;
    }
};

// --- Código del punto 5: Empleado ---
class Empleado {
private:
    string nombre;
    double salario;
    string departamento;
public:
    Empleado(string nom, double sal, string depto)
        : nombre(nom), salario(sal), departamento(depto) {}
    double obtenerSalario() const { return salario; }
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << "\nSalario: " << salario 
             << "\nDepartamento: " << departamento << endl;
    }
};

// --- Código del punto 6: Libro ---
class Libro {
private:
    string titulo;
    string autor;
    int anioPublicacion;
public:
    Libro(string tit, string aut, int anio)
        : titulo(tit), autor(aut), anioPublicacion(anio) {}
    int obtenerAnioPublicacion() const { return anioPublicacion; }
    void mostrarDatos() const {
        cout << "Título: " << titulo << "\nAutor: " << autor 
             << "\nAño de publicación: " << anioPublicacion << endl;
    }
};

// Funciones para cada opción
void opcionAlumnos() {
    vector<Alumno> alumnos;
    int numAlumnos;
    cout << "Ingrese el número de alumnos: ";
    cin >> numAlumnos;
    for (int i = 0; i < numAlumnos; i++) {
        Alumno alumno;
        cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
        cin >> alumno.nombre;
        cout << "Ingrese la nota 1: "; cin >> alumno.nota1;
        cout << "Ingrese la nota 2: "; cin >> alumno.nota2;
        cout << "Ingrese la nota 3: "; cin >> alumno.nota3;
        alumnos.push_back(alumno);
    }
    for (const auto& alumno : alumnos) alumno.mostrarDatos();
}

void opcionPersonas() {
    vector<Persona> personas = { {"Ana", 28}, {"Luis", 35}, {"Carlos", 22}, {"María", 30} };
    sort(personas.begin(), personas.end(), [](const Persona &a, const Persona &b) {
        return a.edad < b.edad;
    });
    for (const auto& persona : personas) persona.mostrarDatos();
}

void opcionRectangulos() {
    vector<Rectangulo> rectangulos;
    int n;
    cout << "¿Cuántos rectángulos quieres ingresar?: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double base, altura;
        cout << "Ingrese la base del rectángulo " << i + 1 << ": ";
        cin >> base;
        cout << "Ingrese la altura del rectángulo " << i + 1 << ": ";
        cin >> altura;
        rectangulos.emplace_back(base, altura);
    }
    for (const auto& rectangulo : rectangulos) rectangulo.mostrarDatos();
}

void opcionCuentasBancarias() {
    vector<CuentaBancaria> cuentas;
    int numeroCuentas;
    cout << "Ingrese el número de cuentas bancarias: ";
    cin >> numeroCuentas;
    for (int i = 0; i < numeroCuentas; i++) {
        string numeroCuenta, nombreTitular;
        double saldoInicial;
        cout << "Ingrese el número de cuenta: ";
        cin >> numeroCuenta;
        cout << "Ingrese el nombre del titular: ";
        cin.ignore();
        getline(cin, nombreTitular);
        cout << "Ingrese el saldo inicial: ";
        cin >> saldoInicial;
        cuentas.push_back(CuentaBancaria(numeroCuenta, nombreTitular, saldoInicial));
    }
    for (const auto& cuenta : cuentas) cuenta.mostrarDatos();
}

void opcionEmpleados() {
    vector<Empleado> empleados;
    int numeroEmpleados;
    cout << "Ingrese el número de empleados: ";
    cin >> numeroEmpleados;
    for (int i = 0; i < numeroEmpleados; i++) {
        string nombre, departamento;
        double salario;
        cout << "Ingrese el nombre del empleado: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese el salario: ";
        cin >> salario;
        cout << "Ingrese el departamento: ";
        cin.ignore();
        getline(cin, departamento);
        empleados.push_back(Empleado(nombre, salario, departamento));
    }
    sort(empleados.begin(), empleados.end(), [](const Empleado &a, const Empleado &b) {
        return a.obtenerSalario() > b.obtenerSalario();
    });
    for (const auto& empleado : empleados) empleado.mostrarDatos();
}

void opcionLibros() {
    vector<Libro> libros;
    int numeroLibros;
    cout << "Ingrese el número de libros: ";
    cin >> numeroLibros;
    for (int i = 0; i < numeroLibros; i++) {
        string titulo, autor;
        int anioPublicacion;
        cout << "Ingrese el título del libro: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Ingrese el autor: ";
        getline(cin, autor);
        cout << "Ingrese el año de publicación: ";
        cin >> anioPublicacion;
        libros.push_back(Libro(titulo, autor, anioPublicacion));
    }
    sort(libros.begin(), libros.end(), [](const Libro &a, const Libro &b) {
        return a.obtenerAnioPublicacion() < b.obtenerAnioPublicacion();
    });
    for (const auto& libro : libros) libro.mostrarDatos();
}

int main() {
    int opcion;
    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Alumnos\n";
        cout << "2. Personas\n";
        cout << "3. Rectángulos\n";
        cout << "4. Cuentas Bancarias\n";
        cout << "5. Empleados\n";
        cout << "6. Libros\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: opcionAlumnos(); break;
            case 2: opcionPersonas(); break;
            case 3: opcionRectangulos(); break;
            case 4: opcionCuentasBancarias(); break;
            case 5: opcionEmpleados(); break;
            case 6: opcionLibros(); break;
            case 0: cout << "Saliendo del programa.\n"; break;
            default: cout << "Opción no válida.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}