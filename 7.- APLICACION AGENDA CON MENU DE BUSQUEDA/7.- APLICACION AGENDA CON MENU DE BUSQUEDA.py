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
def buscar():
  busqueda = input('Codigo a buscar: ')
  archivo = open(nombre, 'r')
  encontrado = 0;
  for linea in archivo: #lee linea por linea
    if (linea.count(busqueda)): # busca que la variable se encuentre en la linea
      print (linea) #si hay coincidencia la imprime
      encontrado = 1; #variable de validacion para no preguntar si deseas agregar
      break   #sale del loop 
  if encontrado == 0: # si no hay concidencias pregunta si deseas agregar
    print ("No encontrado\n Deseas agregarlo?\n")
    respuesta = input("1.- Si | cualquier numero o letra - No\nIngresa una opcion: ")
    if respuesta == '1':
      escribir() # si ingresar si (1) llama a la funcion escribir
      
def main():     # Definimos la fincion main
  opc=''
  while (opc != 4):
      print("Que deseas hacer:\n1.-Leer la agenda\n2.-Agregar datos a la agenda\n3.-Buscar por codigo\n4.-Salir\nIngresa una opcion: ")
      opcion = input('Respuesta:')
      if opcion == '1':
          archivo = open(nombre, "r")
          for linea in archivo:
           print(linea)
      elif opcion == '2':
          escribir()
      elif opcion == '3':
          buscar()
      elif opcion == '4':
          opc = 4
          print("Adios")
      else:
          print('Opcion invalida')

if __name__ == '__main__':  #Declaramos que se va a ejecutar main
    main()