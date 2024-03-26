nombre = "archivo.txt"
archivo = open(nombre, "r")   ##Abrimos el archivo
contador = 0   ##Contador de caracteres 
caracter = archivo.read(1)
cadenalectura=''
# Recorremos el archivo txt
while(caracter != ""):
    contador +=1
    cadenalectura = cadenalectura+caracter
    caracter = archivo.read(1)
# Cerramos el archivo
archivo.close()
# Imprimimos el numero de caracteres que tiene el texto
print("El numero de caracteres que tiene el texto es de: ", contador)
archivo = open(nombre, "r")   ##Abrimos el archivo
print("El texto del archivo es:\n",cadenalectura)
archivo.close()