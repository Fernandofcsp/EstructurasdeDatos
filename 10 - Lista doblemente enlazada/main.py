from lista import Lista

def main():
  lista = Lista()

  while True:
    print ("******** Lista Doblemente ligada ********\n")
    print ("1 - Agregar al inicio.\n2 - Agregar al final.")
    print ("3 - Insertar en la Lista\n4 - Mostrar toda la lista.")
    print ("5 - Eliminar al inicio.\n6 - Eliminar al final.")
    print ("7 - Eliminar todo.")
    print ("0 - Salir")
    opc = str(input ("Respuesta: "))
    print (opc)
    if opc == '1':
      print ("*** Agregar al inicio ***")
      dato = input("Valor del dato: ")
      lista.agregarI(dato)
      print ("elemento agregado.")
    elif opc == '2':
      print ("*** Agregar al final ***")
      dato = input("Valor del dato: ")
      lista.agregarF(dato)
      print ("elemento agregado.")
    elif opc == '3':
      print ("*** Insertar en una posicion. ***")
      dato = input("Valor del dato: ")
      pos = input("posicion del dato: ")
      lista.insertar(pos, dato)
      print ("elemento agregado.")
    elif opc == '4':
      print ("*** Lista completa: ***")
      lista.imprimirLista()
    elif opc == '5':
      print ("*** Eliminar al inicio ***")
      lista.eliminarI()
      print ("elemento eliminada.")
    elif opc == '6':
      print ("*** Eliminar al final ***")
      lista.eliminarF()
      print ("elemento eliminada.")
    elif opc == '7':
      print ("*** Eliminar lista ***")
      lista.eliminarT()
      print ("Lista eliminada.")
    elif opc == '0':
      exit(0)
    else:
      print ("Opcion invalida...")

if __name__ == "__main__":
  main()