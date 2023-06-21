//mfcs proyecto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACIENTES 10
#define MAX_NOMBRE 50
#define MAX_DIRECCION 100
#define MAX_MEDICAMENTOS 6

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
    char genero;
    char direccion[MAX_DIRECCION];
    char tipoSangre[5];
    int habitacionAsignada;
    int numMedicamentos;
    struct {
        char nombre[MAX_NOMBRE];
        char horario[50];
    } medicamentos[MAX_MEDICAMENTOS];
} Paciente;

typedef struct {
    int numero;
    int pacienteId;
} Cuarto;

typedef struct {
    int numero[MAX_MEDICAMENTOS];
    int pacienteId;
} Medicamento;

void registrarDatos(Paciente *paciente) {
    printf("=== Registro de Datos ===\n");
    printf("Nombre: ");
    fgets(paciente->nombre, MAX_NOMBRE, stdin);
    paciente->nombre[strcspn(paciente->nombre, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &(paciente->edad));
    getchar();

    printf("Genero (M/F): ");
    scanf(" %c", &(paciente->genero));
    getchar();

    printf("Direccion: ");
    fgets(paciente->direccion, MAX_DIRECCION, stdin);
    paciente->direccion[strcspn(paciente->direccion, "\n")] = '\0';

    printf("Tipo de sangre: ");
    fgets(paciente->tipoSangre, 5, stdin);
    paciente->tipoSangre[strcspn(paciente->tipoSangre, "\n")] = '\0';

    printf("Datos registrados con exito.\n\n");
}

void mostrarDatos(Paciente paciente) {
    printf("=== Datos del Paciente ===\n");
    printf("Nombre: %s\n", paciente.nombre);
    printf("Edad: %d\n", paciente.edad);
    printf("Genero: %c\n", paciente.genero);
    printf("Direccion: %s\n", paciente.direccion);
    printf("Tipo de sangre: %s\n", paciente.tipoSangre);
    printf("Habitacion asignada: %d\n", paciente.habitacionAsignada);

    printf("Medicamentos:\n");
    for (int i = 0; i < paciente.numMedicamentos; i++) {
        printf("Nombre: %s\n", paciente.medicamentos[i].nombre);
        printf("Horario: %s\n", paciente.medicamentos[i].horario);
        printf("\n");
    }

    printf("\n");
}

void relacionarCuarto(Paciente *paciente, Cuarto *cuarto) {
    printf("=== Relacionar al Paciente con un Cuarto ===\n");
    printf("Numero de Cuarto: ");
    scanf("%d", &(cuarto->numero));
    cuarto->pacienteId = paciente->edad;
    paciente->habitacionAsignada = cuarto->numero;
    getchar();

    printf("El paciente ha sido relacionado con el cuarto numero %d.\n\n", cuarto->numero);
}

void relacionarMedicamento(Paciente *paciente, Medicamento *medicamentos, int numMedicamentos) {
    if (numMedicamentos <= MAX_MEDICAMENTOS) {
        printf("=== Relacionar al Paciente con Medicamentos ===\n");
        paciente->numMedicamentos = numMedicamentos;

        for (int i = 0; i < numMedicamentos; i++) {
            printf("Nombre del medicamento %d: ", i + 1);
            fgets(paciente->medicamentos[i].nombre, MAX_NOMBRE, stdin);
            paciente->medicamentos[i].nombre[strcspn(paciente->medicamentos[i].nombre, "\n")] = '\0';

            printf("Horario del medicamento %d: ", i + 1);
            fgets(paciente->medicamentos[i].horario, 50, stdin);
            paciente->medicamentos[i].horario[strcspn(paciente->medicamentos[i].horario, "\n")] = '\0';

            printf("\n");
        }

        printf("El paciente ha sido relacionado con %d medicamento(s).\n\n", numMedicamentos);
    } else {
        printf("¡Error! Se ha excedido el numero maximo de medicamentos (%d).\n\n", MAX_MEDICAMENTOS);
    }
}

int main() {
    Paciente pacientes[MAX_PACIENTES];
    Cuarto cuarto;
    Medicamento medicamentos;
    int opcion;
    int numPacientes = 0;
    int numMedicamentos;

    do {
        printf("=== Sistema de Registro de Pacientes ===\n");
        printf("1. Registrar Datos\n");
        printf("2. Mostrar Datos\n");
        printf("3. Relacionar al Paciente con un Cuarto\n");
        printf("4. Relacionar al Paciente con Medicamentos\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                if (numPacientes < MAX_PACIENTES) {
                    registrarDatos(&pacientes[numPacientes]);
                    numPacientes++;
                } else {
                    printf("¡Error! Se ha alcanzado el maximo numero de pacientes.\n\n");
                }
                break;
            case 2:
                if (numPacientes > 0) {
                    int i;
                    printf("=== Lista de Pacientes ===\n");
                    for (i = 0; i < numPacientes; i++) {
                        printf("%d. %s\n", i + 1, pacientes[i].nombre);
                    }
                    printf("\n");

                    int pacienteSeleccionado;
                    printf("Seleccione un paciente: ");
                    scanf("%d", &pacienteSeleccionado);
                    getchar();

                    if (pacienteSeleccionado >= 1 && pacienteSeleccionado <= numPacientes) {
                        mostrarDatos(pacientes[pacienteSeleccionado - 1]);
                    } else {
                        printf("¡Error! Seleccion de paciente invalida.\n\n");
                    }
                } else {
                    printf("¡Error! No se han registrado pacientes.\n\n");
                }
                break;
            case 3:
                if (numPacientes > 0) {
                    int i;
                    printf("=== Lista de Pacientes ===\n");
                    for (i = 0; i < numPacientes; i++) {
                        printf("%d. %s\n", i + 1, pacientes[i].nombre);
                    }
                    printf("\n");

                    int pacienteSeleccionado;
                    printf("Seleccione un paciente: ");
                    scanf("%d", &pacienteSeleccionado);
                    getchar();

                    if (pacienteSeleccionado >= 1 && pacienteSeleccionado <= numPacientes) {
                        relacionarCuarto(&pacientes[pacienteSeleccionado - 1], &cuarto);
                    } else {
                        printf("¡Error! Seleccion de paciente invalida.\n\n");
                    }
                } else {
                    printf("¡Error! No se han registrado pacientes.\n\n");
                }
                break;
            case 4:
                if (numPacientes > 0) {
                    int i;
                    printf("=== Lista de Pacientes ===\n");
                    for (i = 0; i < numPacientes; i++) {
                        printf("%d. %s\n", i + 1, pacientes[i].nombre);
                    }
                    printf("\n");

                    int pacienteSeleccionado;
                    printf("Seleccione un paciente: ");
                    scanf("%d", &pacienteSeleccionado);
                    getchar();

                    if (pacienteSeleccionado >= 1 && pacienteSeleccionado <= numPacientes) {
                        printf("Numero de Medicamentos: ");
                        scanf("%d", &numMedicamentos);
                        getchar();

                        if (numMedicamentos > 0) {
                            relacionarMedicamento(&pacientes[pacienteSeleccionado - 1], &medicamentos, numMedicamentos);
                        } else {
                            printf("¡Error! Numero de medicamentos invalido.\n\n");
                        }
                    } else {
                        printf("¡Error! Seleccion de paciente invalida.\n\n");
                    }
                } else {
                    printf("¡Error! No se han registrado pacientes.\n\n");
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("¡Error! Opcion invalida.\n\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
