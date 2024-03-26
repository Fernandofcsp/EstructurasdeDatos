class Lista:
     def __init__(self):  #Inicializa la cola
         self.items = [1, 3, "gato", 8, "c", "pepe"]
     def Encolar(self, item): #Metodo para añadir elementos en la cola
         self.items.append(item)
     def desencolar(self):   #Metodo para eliminar el primer elemento de la cola y devolver su valor
         return self.items.pop(0)
     def isEmpty(self): #Metodo que verifica si la pila esta vacia 
         return self.items == []
     def ShowLast(self): #Muestra el ultimo elemento de la cola
         return self.items[len(self.items)-1]
     def ShowFirst(self): #Muestra el primer elemento de la cola
         return self.items[len(self.items)-len(self.items)]
     def Size(self): #Muestra el tamaño de la cola
         return len(self.items)
     def Show(self): #Muestra los elementos de la cola
         print(self.items)
     def ClearAll(self): ##Borra todos los elementos de la cola
         self.items = []


def main():     # Definimos la fincion main
  p=Lista()

  i = 10
  while (i > 0):
    print ('Seleccione una opcion\n1.- verificar si la cola esta vacia\n2.- añadir elementos')
    print ('3.- eliminar elementos\n4.- mostrar ultimo elemento\n5.- mostrar tamaño\n6.- Listar')
    print('7.- Borrar todos los elementos de la cola\n8.- Mostrar primer elemento\n0.- Salir\n')
    opcion = input('Respuesta:')
    if opcion == '1':
      print(p.isEmpty())
    elif opcion == '2':
      dato = input('Dato a añadir: ')
      p.Encolar(dato)
    elif opcion == '3' and p.isEmpty() == False: 
      print(p.desencolar())
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
      print ("Pila vacia u opcion inexistente")

if __name__ == '__main__':  
    main()
