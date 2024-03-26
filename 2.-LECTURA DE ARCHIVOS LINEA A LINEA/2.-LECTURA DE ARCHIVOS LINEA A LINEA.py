import os
nombre = "archivo.txt"

def leerlinea():
  if nombre in os.listdir("."):
    archivo = open(nombre, "r")
    for linea in archivo:
      print(linea)
    archivo.close()
  else:
    print("El archivo no existe")

def main():
  leerlinea()

if __name__ == '__main__':  
    main()
