# HAYKA_proyect
Establece conexciones entre en servdidor y clientes(automoviles)


**Dependencias**

Librerias standard de C,C++ Qt5

**Sistema operativo ArchLinux-Debian**


**Dependencias**

Ejecutar hayka.sh como administrador

chmod +x hayka.sh
./hayka.sh o sh hayka.sh


**Compilar test_hayka.cxx**

g++ -std=c++11 test_hayka.cxx -o test -lbsd

**Manual de uso**

Servidor: El servidor debe tener en una mismo directorio la interfaz y el archivo servidor_hayka.c, no necesita modificar ninguna linea de codigo.


Cliente:  En primer lugar debemos mencionar que puede tener varios clientes, limitados por la cantidad de contenedores que 
          tiene la interfaz. Ademas en cada cliente debe hacerse 3 modificaciones:
          
                    modificacion 1: en el archivo test_hayka.cxx debe cambiarse el id_car esta funcion debe retornar un 
                                    numero diferente para cada cliente.
                                    
                    modificacion 2: en el archivo connect.h linea 17 se debe colocar el ip que tiene el "servidor"
                    
                    modificacion 3: en el archivo connect.h linea 72 se debe cambiar la ruta correcta donde se guardara el 
                                    archivo value.txt
