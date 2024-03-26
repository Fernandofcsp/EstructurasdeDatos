nombre = "Agenda.txt"

def escribir():
  print('Ingresa los siguientes datos\n')
  name = str(input('Nombre: '))
  carrera = str(input('Carrera: '))
  codigo =str(input('Codigo: '))
  cadena = name+" "+carrera+" "+codigo+"\n"
  archivo = open(nombre, "a+")
  archivo.write(cadena)
  archivo.close()

def main():     # Definimos la fincion main
  opc=''
  while (opc != 3):
      print("Que deseas hacer:\n1.-Leer la agenda\n2.-Agregar datos a la agenda\n3.-Salir\nIngresa una opcion: ")
      opcion = input('Respuesta:')
      if opcion == '1':
          archivo = open(nombre, "r")
          for linea in archivo:
           print(linea)
      elif opcion == '2':
          escribir()
      elif opcion == '3':
          opc = 3
          print("Adios")
      else:
          print('Opcion invalida')

if __name__ == '__main__':  #Declaramos que se va a ejecutar main
    main()