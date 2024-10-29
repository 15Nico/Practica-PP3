#include <iostream>
#include <vector> //Nico
#include <string> //Nico
#include <iomanip> //Nico
#include <algorithm> //Nico
//#include <limits> //Nico

#include "Empleado.h"
#include "Desarrollador.h"
#include "Tester.h"
#include "GerenteProyecto.h"
#include "Proyecto.h"
#include "Tarea.h"
#include "Cliente.h" //Nico
#include "ReunionSeguimiento.h" //Nico



using namespace std;

//Funciones de Cliente. Nico
void mostrarClientes(const vector<Cliente>& clientes) {
    for (const auto& cliente : clientes) {
        cout << "\nCliente " << cliente.getIdCliente() << ":\n";
        cout << "Nombre: " << cliente.getNombre() << "\n";
        cout << "Apellido: " << cliente.getApellido() << "\n";
        cout << "Empresa: " << cliente.getEmpresa() << "\n";
        cout << "Correo: " << cliente.getCorreoElectronico() << "\n";
        cout << "Telefono: " << cliente.getTelefono() << "\n";
        cout << "Direccion: " << cliente.getDireccion() << "\n";
    }
}

void agregarCliente(vector<Cliente>& clientes) {

    string nombre, apellido, empresa, correoElectronico, telefono, direccion;

    cout << "Ingrese nombre: ";
    cin.ignore(); // Ignora el salto de línea anterior
    getline(cin, nombre);

    cout << "Ingrese apellido: ";
    getline(cin, apellido);

    cout << "Ingrese empresa: ";
    getline(cin, empresa);

    cout << "Ingrese correo electronico: ";
    getline(cin, correoElectronico);

    cout << "Ingrese telefono: ";
    getline(cin, telefono);

    cout << "Ingrese direccion: ";
    getline(cin, direccion);

    clientes.emplace_back(nombre, apellido, empresa, correoElectronico, telefono, direccion);
    cout << "Cliente agregado con exito.\n" << endl;
}

void eliminarCliente(vector<Cliente>& clientes) {
    string entrada;
    int idEliminar;

    cout << "Ingrese el ID del cliente a eliminar: ";
    cin.ignore(); // Ignora el salto de línea anterior
    getline(cin, entrada);

    // Conversión de string a int
    try {
        idEliminar = stoi(entrada);
    } catch (const invalid_argument&) {
        cout << "ID invalido. Por favor, ingrese un numero entero.\n" << endl;
        return;
    }

    // Buscar el cliente por ID
    auto it = find_if(clientes.begin(), clientes.end(),
        [idEliminar](const Cliente& cliente) {
            return cliente.getIdCliente() == idEliminar;
        });

    // Verificar si se encontró el cliente
    if (it != clientes.end()) {
        clientes.erase(it);
        cout << "Cliente eliminado con exito.\n" << endl;
    } else {
        cout << "No se encontro el cliente con ID \n" << idEliminar << endl;
    }
}

void buscarClientePorID(const vector<Cliente>& clientes) {
    string entrada;
    int idBuscar;

    cout << "Ingrese el ID del cliente a buscar: ";
    cin.ignore(); // Ignora el salto de línea anterior
    getline(cin, entrada);

    // Conversión de string a int
    try {
        idBuscar = stoi(entrada);
    } catch (const invalid_argument&) {
        cout << "ID invalido. Por favor, ingrese un numero entero.\n" << endl;
        return;
    }

    // Buscar el cliente por ID
    auto it = find_if(clientes.begin(), clientes.end(),
        [idBuscar](const Cliente& cliente) {
            return cliente.getIdCliente() == idBuscar;
        });

    // Verificar si se encontró el cliente
    if (it != clientes.end()) {
        cout << "Cliente encontrado:\n";
        cout << "ID: " << it->getIdCliente() << "\n";
        cout << "Nombre: " << it->getNombre() << "\n";
        cout << "Apellido: " << it->getApellido() << "\n";
        cout << "Empresa: " << it->getEmpresa() << "\n";
        cout << "Correo: " << it->getCorreoElectronico() << "\n";
        cout << "Telefono: " << it->getTelefono() << "\n";
        cout << "Direccion: " << it->getDireccion() << "\n";
    } else {
        cout << "No se encontro el cliente con ID \n" << idBuscar << endl;
    }
}

void editarCliente(vector<Cliente>& clientes) {
    string entrada;
    int idEditar;

    cout << "Ingrese el ID del cliente a editar: ";
    cin.ignore(); // Ignora el salto de línea anterior
    getline(cin, entrada);

    // Conversión de string a int
    try {
        idEditar = stoi(entrada);
    } catch (const invalid_argument& ) {
        cout << "ID invalido. Por favor, ingrese un numero entero.\n" << endl;
        return;
    }

    // Buscar el cliente por ID
    auto it = find_if(clientes.begin(), clientes.end(),
        [idEditar](const Cliente& cliente) {
            return cliente.getIdCliente() == idEditar;
        });

    // Verificar si se encontró el cliente
    if (it != clientes.end()) {
        cout << "Informacion del Cliente Encontrado:\n\n";
        cout << "ID: " << it->getIdCliente() << "\n";
        cout << "Nombre: " << it->getNombre() << "\n";
        cout << "Apellido: " << it->getApellido() << "\n";
        cout << "Empresa: " << it->getEmpresa() << "\n";
        cout << "Correo: " << it->getCorreoElectronico() << "\n";
        cout << "Telefono: " << it->getTelefono() << "\n";
        cout << "Direccion: " << it->getDireccion() << "\n";

        // Menú de edición
        int opcion;
        cout << "Seleccione el campo a editar:" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Apellido" << endl;
        cout << "3. Empresa" << endl;
        cout << "4. Correo electronico" << endl;
        cout << "5. Telefono" << endl;
        cout << "6. Direccion" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignora el salto de línea

        switch (opcion) {
            case 1:
                {
                    string nombre;
                    cout << "Ingrese el nuevo nombre: ";
                    getline(cin, nombre);
                    it->setNombre(nombre);
                }
                break;
            case 2:
                {
                    string apellido;
                    cout << "Ingrese el nuevo apellido: ";
                    getline(cin, apellido);
                    it->setApellido(apellido);
                }
                break;
            case 3:
                {
                    string empresa;
                    cout << "Ingrese la nueva empresa: ";
                    getline(cin, empresa);
                    it->setEmpresa(empresa);
                }
                break;
            case 4:
                {
                    string correo;
                    cout << "Ingrese el nuevo correo electronico: ";
                    getline(cin, correo);
                    it->setCorreoElectronico(correo);
                }
                break;
            case 5:
                {
                    string telefono;
                    cout << "Ingrese el nuevo telefono: ";
                    getline(cin, telefono);
                    it->setTelefono(telefono);
                }
                break;
            case 6:
                {
                    string direccion;
                    cout << "Ingrese la nueva direccion: ";
                    getline(cin, direccion);
                    it->setDireccion(direccion);
                }
                break;
            default:
                cout << "Opcion invalida\n" << endl;
        }

        cout << "Cliente editado con exito" << endl;
    } else {
        cout << "No se encontro el cliente con ID \n" << idEditar << endl;
    }
}


//Funciones de Reuniones de seguimiento. Nico
void mostrarReuniones(const vector<ReunionSeguimiento>& reuniones) {
    cout << "Lista de Reuniones:" << endl;
    for (const auto& reunion : reuniones) {
        reunion.imprimirReunion();
        cout << endl;
    }
}

void agregarReunion(vector<ReunionSeguimiento>& reuniones) {
    string nombre, fecha, hora, proyecto, resumenDecisiones;
    vector<string> asistentes, temasDiscutidos, proximasAcciones;

    cout << "Ingrese los datos de la nueva reunion:" << endl;
    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Fecha (dia-mes-anio): ";
    cin >> fecha;
    cin.ignore(); // Ignora el salto de línea

    cout << "Hora (hora:min): ";
    cin >> hora;
    cin.ignore(); // Ignora el salto de línea

    cout << "Proyecto: ";
    getline(cin, proyecto);

    cout << "Ingrese los asistentes (separados por coma): ";
    string asistentesStr;
    getline(cin, asistentesStr);
    size_t pos = 0;
    while ((pos = asistentesStr.find(',')) != string::npos) {
        asistentes.push_back(asistentesStr.substr(0, pos));
        asistentesStr.erase(0, pos + 1);
    }
    asistentes.push_back(asistentesStr);

    cout << "Ingrese los temas discutidos (separados por coma): ";
    string temasDiscutidosStr;
    getline(cin, temasDiscutidosStr);
    //pos = 0;
    while ((pos = temasDiscutidosStr.find(',')) != string::npos) {
        temasDiscutidos.push_back(temasDiscutidosStr.substr(0, pos));
        temasDiscutidosStr.erase(0, pos + 1);
    }
    temasDiscutidos.push_back(temasDiscutidosStr);

    cout << "Resumen de decisiones: ";
    getline(cin, resumenDecisiones);

    cout << "Ingrese las proximas acciones (separados por coma): ";
    string proximasAccionesStr;
    getline(cin, proximasAccionesStr);
    //pos = 0;
    while ((pos = proximasAccionesStr.find(',')) != string::npos) {
        proximasAcciones.push_back(proximasAccionesStr.substr(0, pos));
        proximasAccionesStr.erase(0, pos + 1);
    }
    proximasAcciones.push_back(proximasAccionesStr);

    ReunionSeguimiento nuevaReunion(nombre, fecha, hora, proyecto, asistentes, temasDiscutidos, resumenDecisiones, proximasAcciones);
    reuniones.push_back(nuevaReunion);
}

void eliminarReunion(vector<ReunionSeguimiento>& reuniones) {
    int id;
    cout << "Ingrese el ID de la reunion a eliminar: ";
    cin >> id;
    cin.ignore();

    auto it = std::remove_if(reuniones.begin(), reuniones.end(), [id](const ReunionSeguimiento& reunion) {
        return reunion.getIdReunion() == id;
    });
    reuniones.erase(it, reuniones.end());

    cout << "Reunion eliminada con exito." << endl;
}

void buscarReunionPorID(const vector<ReunionSeguimiento>& reuniones) {
    int id;
    cout << "Ingrese el ID de la reunion a buscar: ";
    cin >> id;
    cin.ignore();
    cout << endl;

    for (const auto& reunion : reuniones) {
        if (reunion.getIdReunion() == id) {
            reunion.imprimirReunion();
            return;
        }
    }

    cout << "No se encontro la reunion con ID " << id << "." << endl;
}

void editarReunion(vector<ReunionSeguimiento>& reuniones)
{
    int id;
    cout << "Ingrese el ID de la reunion a editar: ";
    cin >> id;
    cin.ignore();

    for (auto& reunion : reuniones) {
        if (reunion.getIdReunion() == id) {
            int opcion;
            do {
                cout << "\nMenu de edicion de reunion:" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Fecha" << endl;
                cout << "3. Hora" << endl;
                cout << "4. Proyecto" << endl;
                cout << "5. Asistentes" << endl;
                cout << "6. Temas discutidos" << endl;
                cout << "7. Resumen de decisiones" << endl;
                cout << "8. Proximas acciones" << endl;
                cout << "9. Guardar cambios" << endl;
                cout << "10. Volver" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcion;
                cin.ignore();

                switch (opcion) {
                case 1:
                    {
                        cout << "\nNombre (" << reunion.getNombre() << "): ";
                        string nombre;
                        getline(cin, nombre);
                        if (!nombre.empty()) {
                            reunion.setNombre(nombre);
                        }
                    }
                        break;

                case 2:
                    {
                        cout << "\nFecha (" << reunion.getFecha() << "): ";
                        string fecha;
                        getline(cin, fecha);
                        if (!fecha.empty()) {
                            reunion.setFecha(fecha);
                        }
                    }
                        break;

                case 3:
                    {
                        cout << "\nHora (" << reunion.getHora() << "): ";
                        string hora;
                        getline(cin, hora);
                        if (!hora.empty()) {
                            reunion.setHora(hora);
                        }
                    }
                        break;

                case 4:
                    {
                        cout << "\nProyecto (" << reunion.getProyecto() << "): ";
                        string proyecto;
                        getline(cin, proyecto);
                        if (!proyecto.empty()) {
                            reunion.setProyecto(proyecto);
                        }
                    }
                        break;

                case 5:
                    {
                        cout << "\nIngrese los asistentes (separados por coma): ";
                        string asistentesStr;
                        getline(cin, asistentesStr);
                        if (!asistentesStr.empty()) {
                            vector<string> asistentes;
                            size_t pos = 0;
                            while ((pos = asistentesStr.find(',')) != string::npos) {
                                asistentes.push_back(asistentesStr.substr(0, pos));
                                asistentesStr.erase(0, pos + 1);
                            }
                            asistentes.push_back(asistentesStr);
                            reunion.setAsistentes(asistentes);
                        }
                    }
                        break;

                case 6:
                    {
                        cout << "\nIngrese los temas discutidos (separados por coma): ";
                        string temasDiscutidosStr;
                        getline(cin, temasDiscutidosStr);
                        if (!temasDiscutidosStr.empty()) {
                            vector<string> temasDiscutidos;
                            size_t pos = 0;
                            while ((pos = temasDiscutidosStr.find(',')) != string::npos) {
                                temasDiscutidos.push_back(temasDiscutidosStr.substr(0, pos));
                                temasDiscutidosStr.erase(0, pos + 1);
                            }
                            temasDiscutidos.push_back(temasDiscutidosStr);
                            reunion.setTemasDiscutidos(temasDiscutidos);
                        }
                    }
                        break;

                case 7:
                    {
                        cout << "\nResumen de decisiones (" << reunion.getResumenDecisiones() << "): ";
                        string resumenDecisiones;
                        getline(cin, resumenDecisiones);
                        if (!resumenDecisiones.empty()) {
                            reunion.setResumenDecisiones(resumenDecisiones);
                        }
                    }
                        break;

                        case 8:
                            {
                                cout << "\nIngrese las proximas acciones (separados por coma): ";
                                string proximasAccionesStr;
                                getline(cin, proximasAccionesStr);
                                if (!proximasAccionesStr.empty()) {
                                    vector<string> proximasAcciones;
                                    size_t pos = 0;
                                    while ((pos = proximasAccionesStr.find(',')) != string::npos) {
                                        proximasAcciones.push_back(proximasAccionesStr.substr(0, pos));
                                        proximasAccionesStr.erase(0, pos + 1);
                                    }
                                    proximasAcciones.push_back(proximasAccionesStr);
                                    reunion.setProximasAcciones(proximasAcciones);
                                }
                            }
                                break;

                        case 9:
                            cout << "\nCambios guardados con exito.\n" << endl;
                        return;
                        case 10:
                            cout << "\nEdicion cancelada.\n" << endl;
                        return;
                        default:
                            cout << "\nOpcion invalida. Intente nuevamente." << endl;
                }
                } while (opcion != 9 && opcion != 10);
                return;
            }
        }
        cout << "\nNo se encontro la reunion con ID " << id << "." << endl;
    }


int main() {
    // Precargar datos de ejemplo
    vector<Empleado*> empleados = {
            new Desarrollador("Juan", "Desarrollador", "C++"),
            new Desarrollador("Pedro", "Desarrollador", "Java"),
            new Desarrollador("Luis", "Desarrollador", "Python"),
            new Tester("Maria", "Tester", "Pruebas de Rendimiento"),
            new Tester("Sofia", "Tester", "Pruebas Funcionales"),
            new Tester("Lucia", "Tester", "Pruebas de Seguridad"),
            new GerenteProyecto("Carlos", "Gerente de Proyecto", "Equipo A"),
            new GerenteProyecto("Miguel", "Gerente de Proyecto", "Equipo B"),
            new GerenteProyecto("Laura", "Gerente de Proyecto", "Equipo C"),
    };

    vector<Proyecto> proyectos = {
            Proyecto("Portal de Ventas Online", "Desarrollo de un portal de ventas para productos electronicos", "01/09/2024", "03/12/2024"),
            Proyecto("App de Pedidos de Comida", "Desarrollo de una aplicacion movil para pedidos de comida a domicilio", "03/09/2024", "01/12/2024"),
            Proyecto("Sistema de Gestion de Inventarios", "Sistema para gestionar inventarios de una cadena de tiendas", "07/09/2024", "06/12/2024"),
    };

    vector<Cliente> clientes = {
            Cliente("Juan", "Perez", "Farmacity", "juan.perez@farmacity.com", "123456789", "Calle 1, 123"),
            Cliente("Maria", "Gonzalez", "AnibalTuc", "maria.gonzalez@anibaltuc.com", "987654321", "Avenida 2, 456"),
            Cliente("Carlos", "Lopez", "FerTec", "carlos.lopez@fertec.com", "555555555", "Calle 3, 789"),
    };

    vector<Tarea> tareas={
            Tarea("Diseniar interfaz de usuario", "en progreso", "20/10/2024", empleados[1]), // Pedro
            Tarea("Pruebas de carga en el servidor", "pendiente", "25/10/2024", empleados[4]), // Maria
        };

    vector<ReunionSeguimiento> reuniones = {
        ReunionSeguimiento("Revision de Progreso Proyecto 1", "15-10-2024", "10:00", "Proyecto 1", {"Juan Perez", "Maria Garcia", "Pedro Lopez"}, {"Analisis de requisitos", "Diseno de la interfaz"}, "Se decidio realizar un prototipo funcional para la proxima reunion.", {"Crear prototipo funcional", "Realizar pruebas de usabilidad"}),
        ReunionSeguimiento("Discusion de Tareas Proyecto 2", "20-10-2024", "14:30", "Proyecto 2", {"Ana Rodriguez", "Luis Hernandez", "Sofia Martinez"}, {"Desarrollo de la base de datos", "Implementacion de la logica de negocio"}, "Se asignaron tareas a cada miembro del equipo.", {"Crear modelo de datos", "Implementar logica de negocio"}),
        ReunionSeguimiento("Revision de Avance Proyecto 3", "05-11-2024", "16:00", "Proyecto 3", {"Carlos Gomez", "Elena Sanchez", "Francisco Torres"}, {"Pruebas de integracion", "Depuracion de errores"}, "Se establecio un plan de pruebas para la siguiente semana.", {"Realizar pruebas de integracion", "Depurar errores"})
    };


int opcion;
do {
    cout << "=== Menu Principal ===" << endl;
    cout << "1. Mostrar informacion cargada" << endl;
    cout << "2. Gestion de Proyectos" << endl;
    cout << "3. Gestion de Empleados" << endl;
    cout << "4. Gestion de Tareas" << endl;
    cout << "5. Gestion de Clientes" << endl;
    cout << "6. Reunion de Seguimiento" << endl;
    cout << "7. Reportes" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            //MostrarInformacionPrecargada
            break;

        case 2:
            {
                int opcionProyecto;
                cout << "\n=== Gestion de Proyectos ===" << endl;
                cout << "1. Mostrar todos los proyectos" << endl;
                cout << "2. Agregar Proyecto" << endl;
                cout << "3. Asignar Empleados a Proyecto" << endl;
                cout << "4. Eliminar Proyecto" << endl;
                cout << "0. Volver" << endl;
                cin >> opcionProyecto;

                switch (opcionProyecto) {
                    case 1:
                        //MostrarProyectos
                        break;

                    case 2: {
                        //AgregarProyecto
                        break;
                    }

                    case 3: {
                        //AsignarEmpleadosAProyecto
                        break;
                    }

                    case 4: {
                        //EliminarProyecto
                        break;
                    }

                    case 0:
                        break;

                    default:
                        cout << "Opcion no valida." << endl;
                        break;
                }
            }
            break;

        case 3:
            {int opcionEmpleado;
                cout << "\n=== Gestion de Empleados ===" << endl;
                cout << "1. Mostrar todos los empleados" << endl;
                cout << "2. Agregar Empleado" << endl;
                cout << "3. Eliminar Empleado" << endl;
                cout << "0. Volver" << endl;
                cin >> opcionEmpleado;

                switch (opcionEmpleado) {
                case 1:
                    //MostrarEmpleados
                    break;

                case 2: {
                        //AgregarEmpleado
                        break;
                }

                case 3: {
                        //EliminarEmpleado
                        break;
                }

                case 0:
                    break;

                default:
                    cout << "Opcion no valida." << endl;
                    break;
                }}
            break;

        case 4:
            {int opcionTarea;
                cout << "\n=== Gestion de Tareas ===" << endl;
                cout << "1. Mostrar todas las tareas" << endl;
                cout << "2. Agregar Tarea" << endl;
                cout << "3. Asignar Empleado a Tarea" << endl;
                cout << "4. Eliminar Tarea" << endl;
                cout << "0. Volver" << endl;
                cin >> opcionTarea;

                switch (opcionTarea) {
                case 1:
                    //mostrarTareas
                    break;

                case 2:
                    //agregarTarea
                    break;

                case 3:
                    //asignarEmpleadoATarea
                    break;

                case 4:
                    //eliminarTarea
                    break;

                case 0:
                    break;

                default:
                    cout << "Opcion no valida." << endl;
                    break;
                }}
            break;

        case 5:
        {
            int opcionCliente;
            do {
                cout << "\n=== Gestion de Clientes ===" << endl;
                cout << "1. Mostrar todos los clientes" << endl;
                cout << "2. Agregar Cliente" << endl;
                cout << "3. Eliminar Cliente" << endl;
                cout << "4. Buscar Cliente por ID" << endl;
                cout << "5. Editar Cliente" << endl;
                cout << "0. Volver" << endl;
                cin >> opcionCliente;

                switch (opcionCliente) {
                case 1:
                    mostrarClientes(clientes);
                    break;
                case 2:
                    agregarCliente(clientes);
                    break;
                case 3:
                    eliminarCliente(clientes);
                    break;
                case 4:
                    buscarClientePorID(clientes);
                    break;
                case 5:
                    editarCliente(clientes);
                    break;
                case 0:
                    break;
                default:
                    cout << "Opcion invalida." << endl;
                }
            } while (opcionCliente != 0);
        } //Nico
            break;

        case 6:
            {
                int opcionReunion;
                do {
                    cout << "\n=== Gestion de Reuniones de Seguimiento ===" << endl;
                    cout << "1. Mostrar todas las reuniones" << endl;
                    cout << "2. Agregar Reunion" << endl;
                    cout << "3. Eliminar Reunion" << endl;
                    cout << "4. Buscar Reunion por ID" << endl;
                    cout << "5. Editar Reunion" << endl;
                    cout << "0. Volver" << endl;
                    cin >> opcionReunion;

                    switch (opcionReunion) {
                    case 1:
                        mostrarReuniones(reuniones);
                        break;
                    case 2:
                        agregarReunion(reuniones);
                        break;
                    case 3:
                        eliminarReunion(reuniones);
                        break;
                    case 4:
                        buscarReunionPorID(reuniones);
                        break;
                    case 5:
                        editarReunion(reuniones);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                    }
                } while (opcionReunion != 0);
            }
            break;

        case 7:
            {
                int opcionReporte;
                cout << "\n=== Reportes ===" << endl;
                cout << "1. Generar Reporte de Proyecto" << endl;
                cout << "2. Generar Reporte de Reuniones" << endl;
                cout << "3. Generar Reporte de Tareas" << endl;
                cout << "4. Generar Reporte de Clientes" << endl;
                cout << "0. Volver" << endl;

                switch (opcionReporte) {
                case 1:
                    //generarReporteProyecto();
                    break;
                case 2:
                    //generarReporteReuniones();
                    break;
                case 3:
                    //generarReporteTareas();
                    break;
                case 4:
                    //generarReporteClientes();
                    break;
                case 0:
                    break;
                default:
                    cout << "Opción invalida." << endl;
                }
            }
            break;

        case 0:
            break;

        default:
            cout << "Opcion no valida." << endl;
            break;
    }
} while (opcion != 0);

    return 0;
}