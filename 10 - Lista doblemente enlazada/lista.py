class Nodo:
  def __init__(self, dato): #constructor del nodo
    self.dato = dato
    self.anterior = None
    self.siguiente = None

class Lista:
  def __init__(self): # constructor de la lsita
    self.primero = None

  def agregarI(self, dato):
    nuevo = Nodo(dato)
    if self.primero is None:
      self.primero = nuevo
    else:
      nuevo.siguiente = self.primero
      self.primero.anterior = nuevo
      self.primero = nuevo

  def agregarF(self, dato):
    nuevo = Nodo(dato)
    if self.primero is None:
      self.primero = nuevo
      return
    else:
      aux = self.primero
      while aux.siguiente is not None:
            aux = aux.siguiente
      aux.siguiente = nuevo
      nuevo.anterior = aux
  
  def insertar(self, pos, dato):
    cont = 1
    if self.primero is None:
      print("Lista vacia...\n")
    else:
      aux = self.primero
      while aux is not None:
        if pos == cont:
          break
        cont = cont + 1
        aux = aux.siguiente
      if aux is None:
          print("No hay tantos elementos en la lista...")
      else:
          nuevo = Nodo(dato)
          nuevo.anterior = aux
          nuevo.siguiente = aux.siguiente
          if aux.siguiente is not None:
              aux.siguiente.anterior = nuevo
          aux.siguiente = nuevo

  def imprimirLista(self):
    if self.primero is None:      
      print("No hay elementos en la lista.\n")
      return
    else:
      aux= self.primero
      while aux is not None:
        print(aux.dato , " ")
        aux= aux.siguiente

  def eliminarI(self):
    if self.primero is None:   
      print("La lista no tiene elementos...\n")
      return 
    if self.primero.siguiente is None:
      self.primero = None
      return
    self.primero.siguiente.anterior = None
    self.primero = self.primero.siguiente

  def eliminarF(self):
        if self.primero is None:
            print("La lista no tiene elementos...\n")
            return 
        if self.primero.siguiente is None:
            self.primero = None
            return
        aux= self.primero
        while aux.siguiente is not None:
            aux= aux.siguiente
        aux.anterior.siguiente = None
  
  def eliminarT(self):
    if self.primero is None:
      self.primero.siguiente = None
      self.primero = None
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