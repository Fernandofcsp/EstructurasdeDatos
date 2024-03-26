abc = 'abcdefghijklmnopqrstuvwxyz0123456789!,.\n '   # abecedario

def cifrar(cadena, clave):

    texto_cifrado = ""        
    for letra in cadena:       
        suma = abc.find(letra) + clave          
        modulo = int(suma) % len(abc)       
        texto_cifrado = texto_cifrado + str(abc[modulo])
    return texto_cifrado

def descifrar(cadena, clave):

    texto_cifrado = ''
    for letra in cadena:
        suma = abc.find(letra) - clave
        modulo = int(suma) % len(abc)
        texto_cifrado = texto_cifrado + str(abc[modulo])
    return texto_cifrado

def main():   
      opc=''
      while (opc != 3):
          
        print("\nDeseas:")
        print("1.-cifrar texto\n2.-Leer texto (descifrar)\n3.-Salir\nIngresa una opcion: ")
        opcion = input('Respuesta:')
        if opcion == '1':
        
            cad = str(input('Cadena a Cifrar: ')).lower()   
            num = int(input('Clave numerica: '))          
            nombre = 'archivocifrado.txt'
            archivo = open(nombre, "w+")
            resultarch = cifrar(cad,num)
            archivo.write(resultarch)
            print (cifrar(cad,num))
            archivo.close()
        elif opcion == '2':
            nombre = 'archivocifrado.txt'
            archivo = open(nombre, "r")   ##Abrimos el archivo
            caracter = archivo.read(1)
            cadenalectura=''
            # Recorremos el archivo txt
            while(caracter != ''):
                cadenalectura = cadenalectura+caracter
                caracter = archivo.read()
                
            cad = cadenalectura.lower()
            archivo.close()
            nombre = 'archivodescifrado.txt'
            archivo = open(nombre, "w+")
            print (cad)
            ClaveNumerica = int(input('Ingrese la Clave numerica con la que se cifro el archivo: '))
            print ("Resultado descifrado:\n",descifrar(cad,ClaveNumerica))
            resultarch = descifrar(cad,ClaveNumerica)
            archivo.write(resultarch)
            archivo.close()
        elif opcion == '3':   
            opc = 3
            print("Adios")
        else:
            print ("Respuesta invalida")
        
if __name__ == '__main__': 
    main()