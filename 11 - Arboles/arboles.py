class Node:
  def __init__(self, dato):
    self.izq = None
    self.der = None
    self.dato = dato
      
  def insertar(self, dato):
    if self.dato:
      if dato < self.dato:
        if self.izq is None:
          self.izq = Node(dato)
        else:
          self.izq.insertar(dato)
      elif dato > self.dato:
        if self.der is None:
          self.der = Node(dato)
        else:
          self.der.insertar(dato)
    else:
      self.dato = dato

  def busqueda(self, lkpval):
    if lkpval < self.dato:
      if self.izq is None:
        return str(lkpval)+" No encontrado..."
      return self.izq.busqueda(lkpval)
    elif lkpval > self.dato:
      if self.der is None:
        return str(lkpval)+" No encontrado..."
      return self.der.busqueda(lkpval)
    else:
      print(str(self.dato) + ' Encontrado...')

  def dibujar(self):
    if self.izq:
      self.izq.dibujar()
    print( self.dato),
    if self.der:
      self.der.dibujar()


raiz = Node(12)
raiz.insertar(6)
raiz.insertar(14)
raiz.insertar(3)
print(raiz.busqueda(7))
print(raiz.busqueda(14))
print(raiz.busqueda(6))
print("Arbol: ")
raiz.dibujar()