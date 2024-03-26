class Pila:
     def __init__(self):  #Inicializa la pila
         self.items = [1, 3, "gato", 8, "c", "pepe"]
     def isEmpty(self): #Metodo que verifica si la pila esta vacia 
         return self.items == []
     def Push(self, item): #Metodo para añadir elementos en la pila
         self.items.append(item)
     def Pop(self): #elimina el ultimo elemento de la pila
         return self.items.pop()
     def ShowLast(self): #Muestra el ultimo elemento de la pila
         return self.items[len(self.items)-1]
     def ShowFirst(self): #Muestra el primer elemento de la pila
         return self.items[len(self.items)-len(self.items)]
     def Size(self): #Muestra el tamaño de la pila
         return len(self.items)
     def Show(self): #Muestra los elementos de la pila
         print(self.items)
     def ClearAll(self): ##Borra todos los elementos de la pila
         self.items = []


def main():     # Definimos la fincion main
  p=Pila()

  i = 10
  while (i > 0):
    print ('Seleccione una opcion\n1.- verificar si la pila esta vacia\n2.- añadir elementos')
    print ('3.- eliminar elementos\n4.- mostrar ultimo elemento\n5.- mostrar tamaño\n6.- Listar')
    print('7.- Borrar todos los elementos de la pila\n8.- Mostrar primer elemento\n0.- Salir\n')
    opcion = input('Respuesta:')
    if opcion == '1':
      print(p.isEmpty())
    elif opcion == '2':
      dato = input('Dato a añadir: ')
      p.Push(dato)
    elif opcion == '3' and p.isEmpty() == False: 
      print(p.Pop())
    elif opcion == '4' and p.isEmpty() == False:
      print(p.ShowLast())
    elif opcion == '5':
      print(p.Size())
    elif opcion == '6':
      p.Show()
    elif opcion == '7':
        p.ClearAll()
    elif opcion == '8':
        print(p.ShowFirst())
    elif opcion == '0':
      print('Nos vemos...')
      i = 0;
    else:
      print ("Respuesta invalida o pila vacia")

if __name__ == '__main__':  
    main()
