#include <stdio.h>
#include <string.h>

#define ProductosMaximos 200
#define IVA 0.15

// Declaración de variables globales
int TotalProductos = 0, i, CodigoRepetido, Cantidad[ProductosMaximos], Respuesta, Encontrar, Respuesta1, Acumulado = 0;
char Codigo[ProductosMaximos][11], Nombre[ProductosMaximos][11], Categoria[ProductosMaximos][11], Clasificacion, opcion, Lote[ProductosMaximos][11], BuscarCodigoEditar[5], Edicion, BuscarCodigoEliminar[5], Encabezado[100], Linea[100];
float ValorUnitario[ProductosMaximos], AcumuladoPrecio = 0, ValorTotal[ProductosMaximos], ValorTotalIVA[ProductosMaximos];

void IngresarProducto() {
    // Ingresar producto
    if (TotalProductos < ProductosMaximos) {

        // Codigo del producto
        do {
            printf("Ingrese el código del producto: ");
            scanf("%s", Codigo[TotalProductos]);

            // Verificación que el código sea de 4 dígitos
            if (strlen(Codigo[TotalProductos]) != 4) {
                printf("Recuerde ingresar un código de 4 dígitos! Intente de nuevo!\n");
            }
            // Verificación que el código no sea repetido
            CodigoRepetido = 0;
            for (i = 0; i < TotalProductos; i++) {
                if (strcmp(Codigo[i], Codigo[TotalProductos]) == 0) {
                    CodigoRepetido = 1;
                    printf("El código está repetido!\n");
                }
            }
        } while (CodigoRepetido != 0 || strlen(Codigo[TotalProductos]) != 4);


        // Nombre del producto
        do {
            printf("Ingrese el nombre del producto: ");
            scanf("%s", Nombre[TotalProductos]);
            // Verificación de que el nombre del producto no sea de más de 10 caracteres
            if (strlen(Nombre[TotalProductos]) > 10) {
                printf("Ingrese un nombre de 10 caracteres! \n");
            }
        } while (strlen(Nombre[TotalProductos]) > 10);


        // Categoría del producto
        do {
            printf("Seleccione la categoría del producto:\n1. Frutas\n2. Lácteos\n3. Embutidos\n4. Carnes\n5. Bebidas\n6. Dulces\n7. Limpieza\n8. Otros\nOpción: ");
            scanf(" %c", &Clasificacion);
            switch (Clasificacion) {
            case '1':
                strcpy(Categoria[TotalProductos], "Frutas"); //NO IVA
                break;
            case '2':
                strcpy(Categoria[TotalProductos], "Lácteos"); //NO IVA
                break;
            case '3':
                strcpy(Categoria[TotalProductos], "Embutidos"); //NO IVA
                break;
            case '4':
                strcpy(Categoria[TotalProductos], "Carnes"); //NO IVA
                break;
            case '5':
                strcpy(Categoria[TotalProductos], "Bebidas");
                break;
            case '6':
                strcpy(Categoria[TotalProductos], "Dulces");
                break;
            case '7':
                strcpy(Categoria[TotalProductos], "Limpieza");
                break;
            case '8':
                strcpy(Categoria[TotalProductos], "Otros");
                break;
            default:
                printf("Selección no válida. Intente de nuevo.");
                Clasificacion = '0';
                break;
            }
        } while (Clasificacion == '0');

        // Lote del producto
        do {
            printf("Ingrese el lote del producto: ");
            scanf("%s", Lote[TotalProductos]);
            // Verificación de que el lote del producto sea de 4 dígitos
            if (strlen(Lote[TotalProductos]) != 4) {
              printf("Recuerde ingresar un lote de hasta 4 dígitos! Intente de nuevo!\n");
            }
        } while (strlen(Lote[TotalProductos]) != 4);

        // Cantidad disponible del producto
        do {
            printf("Ingrese la cantidad disponible del producto: ");
            scanf("%d", &Cantidad[TotalProductos]);
            // Verificación de que la cantidad del producto sea mayor a 0
            if (Cantidad[TotalProductos] < 0) {
              printf("Cantidad incorrecta! Intente de nuevo.\n");
              // Stock adecuado del producto
            } else if (Cantidad[TotalProductos] <= 3 || Cantidad[TotalProductos] == 0) {
              printf("Quedan muy pocas unidades disponibles. Se necesita reabastecer el stock de este producto.\n");
            }
        } while (Cantidad[TotalProductos] < 0);


        // Valor unitario del producto
        do {
            printf("Ingrese el valor unitario del producto: ");
            scanf("%f", &ValorUnitario[TotalProductos]);
            // Verificación de que el valor unitario del producto sea mayor a 0
            if (ValorUnitario[TotalProductos] < 0) {
              printf("Valor incorrecto! Intente de nuevo.\n");
            }
        } while (ValorUnitario[TotalProductos] < 0);

        // Actualización del total de productos.
        TotalProductos++;
    } else {
      printf("No hay más espacio en el inventario!\n");
    }
}


// Ingreso de datos del producto editado
void ProductoEditado(int x){

    // Codigo del producto
    do{
      printf("Ingrese el nuevo código del producto: ");
      scanf("%s", Codigo[x]);

      // Verificación que el codigo sea de 4 dígitos
      if(strlen(Codigo[x])!=4){
        printf("Recuerde ingresar un código de 4 dígitos! Intente de nuevo!\n");
      }
      // Verificacion que el codigo no sea repetido
      CodigoRepetido=0;
      for(i=0;i<TotalProductos;i++){
        if(strcmp(Codigo[i], Codigo[x])==0 && Codigo[i] != Codigo[x]){
          CodigoRepetido=1;
          printf("El código está repetido!\n");
        }
      }
    }while(CodigoRepetido != 0 || strlen(Codigo[x]) != 4);


    // Nombre del producto
    do{
      printf("Ingrese el nuevo nombre del producto: ");
      scanf("%s", Nombre[x]);
      // Verificación de que el nombre del producto no sea de más de 10 caracteres
      if(strlen(Nombre[x])>10){
        printf("Ingrese un nombre de 10 caracteres! \n");
      }
    }while(strlen(Nombre[x]) >10);


    // Categoría del producto
    do{
      printf("Seleccione la categoría del producto:\n1. Frutas\n2. Lácteos\n3. Embutidos\n4. Carnes\n5. Bebidas\n6. Dulces\n7. Limpieza\n8. Otros\nOpción: ");
      scanf(" %c", &Clasificacion);
      switch(Clasificacion){
        case '1': 
          strcpy(Categoria[x], "Frutas");
        break;
        case '2':
          strcpy(Categoria[x], "Lácteos");
        break;
        case '3':
          strcpy(Categoria[x], "Embutidos");
        break;
        case '4':
          strcpy(Categoria[x], "Carnes");
        break;
        case '5':
          strcpy(Categoria[x], "Bebidas");
        break;
        case '6':
          strcpy(Categoria[x], "Dulces");
        break;
        case '7':
          strcpy(Categoria[x], "Limpieza");
        break;
        case '8':
          strcpy(Categoria[x], "Otros");
        break;
        default:
          printf("Selección no válida. Intente de nuevo.");
          Clasificacion = '0';
        break;
      }
    }while(Clasificacion == '0');

    // Lote del producto
    do{
      printf("Ingrese el lote del producto: ");
      scanf("%s", Lote[x]);
      // Verificación de que el lote del producto sea de 4 dígitos
      if(strlen(Lote[x])!=4){
        printf("Recuerde ingresar un lote de hasta 4 dígitos! Intente de nuevo!\n");
      }
    }while(strlen(Lote[x])!=4);

    // Cantidad disponible del producto
    do{
      printf("Ingrese la cantidad disponible del producto: ");
      scanf("%d", &Cantidad[x]);
      // Verificación de que la cantidad del producto sea mayor a 0
      if(Cantidad[x]<0){
        printf("Cantidad incorrecta! Intente de nuevo.\n");
        // Stock adecuado del producto
      }else if(Cantidad[x]<=3 || Cantidad[x]==0){
        printf("Quedan muy pocas unidades disponibles. Se necesita reabastecer el stock de este producto.\n");
      }
    }while(Cantidad[x]<0);
    // Valor unitario del producto
    do{
      printf("Ingrese el valor unitario del producto: ");
      scanf("%f", &ValorUnitario[x]);
      // Verificación de que el valor unitario del producto sea mayor a 0
      if(ValorUnitario[x]<0){
        printf("Valor incorrecto! Intente de nuevo.\n");
      }
    }while(ValorUnitario[x]<0);
}

// Eliminar Producto
void EliminarProducto(){
  do{
    Encontrar=0;
    RepetirBuscarCodigoEliminar:
    printf("Ingrese el código del producto que desea eliminar: ");
    scanf("%s", BuscarCodigoEliminar);
    if(strlen(BuscarCodigoEliminar)!=4){
      printf("Recuerde ingresar un código de hasta 4 dígitos! Intente de nuevo!\n");
      goto RepetirBuscarCodigoEliminar;
    }
    for(i=0;i<TotalProductos;i++){
      if(strcmp(BuscarCodigoEliminar,Codigo[i])==0){
        strcpy(Codigo[i], Codigo[TotalProductos-1]);
        strcpy(Nombre[i], Nombre[TotalProductos-1]);
        strcpy(Categoria[i], Categoria[TotalProductos-1]);
        strcpy(Lote[i], Lote[TotalProductos-1]);
        Cantidad[i]=Cantidad[TotalProductos-1];
        ValorUnitario[i]=ValorUnitario[TotalProductos-1];
        TotalProductos--;
        printf("Producto eliminado.\n");
        Encontrar=1;
        break;
      }
    }
    if(Encontrar!=1){
      printf("Código no encontrado!\n");
      goto RepetirBuscarCodigoEliminar;
    }
    printf("Desea eliminar otro producto? Sí(1) No(0)\nOpción: ");
    scanf("%i", &Respuesta1);
  }while(Respuesta1==1);
}
//Editar Producto
void EditarProducto(){
  do {
    Encontrar = 0;
    // Buscar el producto mediante el código
    printf("Ingrese el código del producto que desea editar: ");
    scanf("%4s", BuscarCodigoEditar);
    getchar(); // Limpiar el búfer de entrada

    if (strlen(BuscarCodigoEditar) != 4) {
      printf("Recuerde ingresar un código de 4 dígitos! Intente de nuevo!\n");
      continue; 
    }

    for (i = 0; i < TotalProductos; i++) {
      if (strcmp(BuscarCodigoEditar, Codigo[i]) == 0) {
        Encontrar = 1;
        printf("Producto encontrado. Seleccione qué desea editar:\n1. Todo\n2. Nombre\n3. Categoría\n4. Lote\n5. Cantidad\n6. Valor\nOpción: ");
        scanf(" %c", &Edicion);
        getchar(); // Limpiar el búfer de entrada

        switch (Edicion) {
          case '1':
            ProductoEditado(i);
            break;
          case '2':
            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%10s", Nombre[i]);
            break;
          case '3':
            printf("Seleccione la nueva categoría del producto:\n1. Frutas\n2. Lácteos\n3. Embutidos\n4. Carnes\n5. Bebidas\n6. Dulces\n7. Limpieza\n8. Otros\nOpción: ");
            scanf(" %c", &Clasificacion);
            getchar(); // Limpiar el búfer de entrada
            switch(Clasificacion){
              case '1': strcpy(Categoria[i], "Frutas"); break;
              case '2': strcpy(Categoria[i], "Lácteos"); break;
              case '3': strcpy(Categoria[i], "Embutidos"); break;
              case '4': strcpy(Categoria[i], "Carnes"); break;
              case '5': strcpy(Categoria[i], "Bebidas"); break;
              case '6': strcpy(Categoria[i], "Dulces"); break;
              case '7': strcpy(Categoria[i], "Limpieza"); break;
              case '8': strcpy(Categoria[i], "Otros"); break;
              default: printf("Selección no válida. Intente de nuevo.\n"); break;
            }
            break;
          case '4':
            printf("Ingrese el nuevo lote del producto: ");
            scanf("%4s", Lote[i]);
            break;
          case '5':
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%i", &Cantidad[i]);
            break;
          case '6':
            printf("Ingrese el nuevo valor del producto: ");
            scanf("%f", &ValorUnitario[i]);
            break;
          default:
            printf("Selección no válida. Intente de nuevo.\n");
            break;
        }
        break; 
      }
    }
    if (Encontrar == 0) {
      printf("Código no encontrado!\n");
    }

    printf("Desea editar otro producto? Sí(1) No(0)\nOpción: ");
    scanf("%i", &Respuesta);
    getchar(); // Limpiar el búfer de entrada
  } while (Respuesta == 1);
}


// Acumulado Cantidades
int AcumuladoInventario(int Cantidad[]){
  int Acumulado = 0;
  for(i=0;i<TotalProductos;i++){
    Acumulado=Acumulado+Cantidad[i];
  }
  return Acumulado;
}

void IVAProductos() {
    for (i = 0; i < TotalProductos; i++) {
        if (strcmp(Categoria[i], "Frutas") == 0 || strcmp(Categoria[i], "Lácteos") == 0 || strcmp(Categoria[i], "Embutidos") == 0 || strcmp(Categoria[i], "Carnes") == 0) {
          // No se aplica IVA
          ValorTotal[i] = ValorUnitario[i];
        } else {
          ValorTotal[i] = ValorUnitario[i] * (1 + IVA);
        }
    }
}

// Cálculo del valor total
void IVAProductosTotal() {
  for (i = 0; i < TotalProductos; i++) {
    ValorTotalIVA[i] = ValorTotal[i]*Cantidad[i];
  }
}

// Acumulado Precio Total
float AcumuladoPrecioTotal(float ValorTotal[], int Cantidad[]){
  float AcumuladoPrecio = 0;  // Inicializa el acumulador
  for(i=0; i<TotalProductos; i++){
    AcumuladoPrecio += ValorTotal[i] * Cantidad[i]; 
  }
  return AcumuladoPrecio;
}


// Mostrar inventario
void MostrarInventario(){
  char Encabezado[155], Linea[155];
  IVAProductos();
  IVAProductosTotal();
  strcpy(Encabezado, "|  No.  |      Nombre      |  Codigo  |  Categoria  |  Lote  |  Cantidad  |  Valor Unitario  |  IVA  |  Valor Unitario IVA  | Valor Total IVA |");
  for(i=0; i<strlen(Encabezado); i++){
    if(Encabezado[i] == '|'){
      Linea[i] = '+';
    } else {
      Linea[i] = '-';
    }
  }
  Linea[strlen(Encabezado)] = '\0'; 
  printf("%s\n", Linea);
  printf("%s\n", Encabezado);
  printf("%s\n", Linea);
  for (i = 0; i < TotalProductos; i++) {
    if (strcmp(Categoria[i], "Frutas") == 0 || strcmp(Categoria[i], "Lacteos") == 0 || strcmp(Categoria[i], "Embutidos") == 0 || strcmp(Categoria[i], "Carnes")==0) {
    // Productos que no tienen IVA
    printf("| %5d | %16s | %8s | %11.10s | %6s | %10d | %16.2f | %5s | %20.2f |  %13.2f  |\n", i + 1, Nombre[i], Codigo[i], Categoria[i], Lote[i], Cantidad[i], ValorUnitario[i], "N/A", ValorTotal[i], ValorTotalIVA[i]);
    } else {
    // Productos que tienen IVA
    printf("| %5d | %16s | %8s | %11.10s | %6s | %10d | %16.2f | %5.2f | %20.2f |  %13.2f  |\n", i + 1, Nombre[i], Codigo[i], Categoria[i], Lote[i], Cantidad[i], ValorUnitario[i], IVA, ValorTotal[i], ValorTotalIVA[i]);
    }
  }
  printf("%s\n", Linea);
  int TotalInventario = AcumuladoInventario(Cantidad);  
  float Precio = AcumuladoPrecioTotal(ValorUnitario, Cantidad);
  printf("El acumulado del inventario es: %i\n", TotalInventario);
  printf("El acumulado del precio del inventario es: %.2f\n", Precio);
}