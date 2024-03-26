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
          
        print("\nDeseas cifrar el texto del archivo por defecto o prefieres ingresar tu propio texto a cifrar:")
        print("1.-Mi propio texto\n2.-Archivo por defecto\n3.-Salir\nIngresa una opcion: ")
        opcion = input('Respuesta:')
        if opcion == '1':
        
            cad = str(input('Cadena a Cifrar: ')).lower()   
            num = int(input('Clave numerica: '))          
            print (cifrar(cad,num))
    
            CadenaCifrada = str(input('Cadena a Decifrar: ')).lower()
            ClaveNumerica = int(input('Clave numerica: '))
            print ("Resultado descifrado:\n",descifrar(CadenaCifrada,ClaveNumerica))
        elif opcion == '2':
            nombre = 'archivo.txt'
            archivo = open(nombre, "r")   ##Abrimos el archivo
            contador = 0   ##Contador de caracteres 
            caracter = archivo.read(1)
            cadenalectura=''
            # Recorremos el archivo txt
            while(caracter != ''):
                contador +=1
                cadenalectura = cadenalectura+caracter
                caracter = archivo.read()
                
            cad = cadenalectura.lower()
            archivo.close()
            print (cad)
            num = int(input('Ingrese la Clave numerica con la que desea cifrar: '))
            print ("Texto cifrado:\n")
            print (cifrar(cad,num))
            CadenaCifrada = (cifrar(cad,num))
            ClaveNumerica = int(input('Ingrese la Clave numerica con la que se cifro el archivo: '))
            print ("Resultado descifrado:\n",descifrar(CadenaCifrada,ClaveNumerica))
        elif opcion == '3':   
            opc = 3
            print("Adios")
        else:
            print ("Respuesta invalida")
        
if __name__ == '__main__': 
    main()