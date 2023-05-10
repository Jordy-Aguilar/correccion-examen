#include <stdio.h>
#include <string.h>

int login();
void opciones();
void menu();
void reciclaje();
float calcularPrecioMaterial(char *material, float kilo);
float calcularBono(float total);
void redSocial();

int main(void)
{
  printf("Hello World\n");
  int resultadoLogin = login();
  if (resultadoLogin)
  {
    menu();
  }
  else
  {
    printf("Saliendo de la aplicacion");
  }
  return 0;
}

int login()
{
  // Usuario y contraseña predefinidos
  int intentos = 0;
  int valido = 0;
  char usuario[20] = "usuario";
  char contrasena[20] = "contrasena";

  // Variables para guardar los datos ingresados por el usuario
  char usuario_ingresado[20];
  char contrasena_ingresada[20];

  while (intentos < 3)
  {
    // Pedir al usuario que ingrese su usuario y contraseña
    printf("Ingrese su usuario: ");
    scanf("%s", usuario_ingresado);

    printf("Ingrese su contrasena: ");
    scanf("%s", contrasena_ingresada);

    // Validar si el usuario y contraseña ingresados son correctos
    if (strcmp(usuario, usuario_ingresado) == 0 &&
        strcmp(contrasena, contrasena_ingresada) == 0)
    {
      printf("Bienvenido, %s.\n", usuario);
      valido = 1;
      intentos = 3;
      break;
    }
    else
    {
      printf("Usuario o contrasena incorrectos intento: %d.\n", intentos + 1);
    }
    intentos++;
  }

  return valido;
}

void menu()
{
  int opcion;
  int valid = 1;
  do
  {
  opciones();
  printf("Opción: ");
  scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
      int count = 0;
      printf("Opción 1.\n");
      while (count < 5)
      {
        reciclaje();
        count++;
      }
      break;
    case 2:
      int count2 = 0;
      printf("Opción 2.\n");
      while (count2 < 5)
      {
        redSocial();
        count2++;
      }
      break;
    case 3:
      valid = 0;
      break;
    default:
      printf("Opcíón no válida.\n");
      break;
    }
  } while (valid);
}

void opciones()
{
  printf("Selecciona una de las siguientes opciones: \n");
  printf("1. Realizar reciclaje\n");
  printf("2. Interactuar en la red social\n");
  printf("3. Salir\n");
}

void reciclaje()
{
  char material[20];
  float kg;
  float precio;
  float bono;
  printf("Ingrese el tipo de material:\t");
  scanf("%s", &material);
  printf("Ingrese los kg: \t");
  scanf("%f", &kg);
  precio = calcularPrecioMaterial(material, kg);
  bono = calcularBono(precio);
  printf("El precio es: %.2f\n", precio);
  printf("El bono es de: %.2f\n", bono);
}

float calcularPrecioMaterial(char *material, float kilo)
{
  float precio = 0;
  float precioporkg = 0;
  if (strcmp(material, "papel") == 0)
  {
    precioporkg = 0.10;
  }
  else if (strcmp(material, "vidrio") == 0)
  {
    precioporkg = 0.20;
  }
  else if (strcmp(material, "plastico") == 0)
  {
    precioporkg = 0.15;
  }
  else if (strcmp(material, "metal") == 0)
  {
    precioporkg = 0.25;
  }
  else
  {
    precioporkg = 0;
  }

  precio = precioporkg * kilo;
  return precio;
}

float calcularBono(float total)
{
  int porcentajeGananado = 0;
  if (total < 50)
  {
    porcentajeGananado = 0;
  }
  else if (total >= 50 && total < 100)
  {
    porcentajeGananado = 5;
  }
  else if (total >= 100 && total < 500)
  {
    porcentajeGananado = 10;
  }
  else
  {
    porcentajeGananado = 20;
  }
  return (porcentajeGananado * total) / 100;
}

void redSocial()
{
  char mensaje[] = "";
  int puntuacion;
  printf("Ingrese el mensaje:\t");
  scanf("%s", &mensaje);
  printf("Ingrese la puntuación:\t");
  scanf("%d", &puntuacion);
  switch (puntuacion)
  {
  case 1:
    printf(" Mensaje negativo - %s :\t", mensaje);
    break;
  case 2:
    printf(" Mensaje negativo - %s :\t", mensaje);
    break;
  case 3:
    printf(" Mensaje neutral  - %s :\t", mensaje);
    break;
  case 4:
    printf(" Mensaje positivo - %s :\t", mensaje);
    break;
  case 5:
    printf("Mensaje positivo - %s :\t", mensaje);
    break;
  default:
    printf(" Por favor ingresa un número del 1 al 5 :\t");
    break;
  }
}