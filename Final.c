#include "FuncionesInventario.h"

int main()
{
  char opcion;
  //Opciones disponibles
  do {
    printf("\nMenú:\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Mostrar inventario\n");
    printf("5. Salir\n");
    printf("Seleccione una opción: ");
    scanf(" %c", &opcion);
    //Estructura según
    switch(opcion) {
      case '1': //Ingreso de producto
        IngresarProducto();
        break;
      case '2': //Editar producto
        EditarProducto();
        break;
      case '3': //Eliminar producto
        EliminarProducto();
        break;
      case '4': //Listar productos
        MostrarInventario();
        break;
      case '5': //Salir
        break;
      default:
        printf("Opción incorrecta! Intente de nuevo.");
        break;
    }
  } while(opcion != '5');
  return 0;
}
