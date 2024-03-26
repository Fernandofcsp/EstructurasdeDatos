

abc = '0123456789abcdefghijklmnopqrstuvwxyz '   # Definimos el abecedario

    # CIFRAR

def cifrar(cadena, clave):      # Definimos la funcion cifrar y le mandamos esos 2 atributos

    text_cifrado = ''           # Creamos variable de texto vacia, donde se almacenara el texto ya cifrado
    for letra in cadena:        #Hacemos una iteracion en la variable cadena
        suma = abc.find(letra) + clave          # Definimos suma como la posicion de la etra de abecedatio mas el numero clave
        modulo = int(suma) % len(abc)           # Definimos el modulo, convertimos suma a numero y se le aplica el modulo
        text_cifrado = text_cifrado + str(abc[modulo])      # Codificamos y aqui ya debe de estar la el texto recorrido

    return text_cifrado


    # DECIFRAR

def decifrar(cadena, clave):

    text_cifrado = ''
    for letra in cadena:
        suma = abc.find(letra) - clave
        modulo = int(suma) % len(abc)
        text_cifrado = text_cifrado + str(abc[modulo])

    return text_cifrado



def main():     # Definimos la fincion main
#eval(input('Cadena a cifrar: ')).lower()
    cad = str(input('Cadena a cifrar: ')).lower()    # Definimos nuestra cadena y la convertimos todo a minusculas
    num = int(input('Clave numerica: '))             # Definimos el numero con el que vamos a cifrar
    print (cifrar(cad,num))                             # Imprime el resultado de la funcion cifrar

    cadcifrada = str(input('Cadena a DEcifrar: ')).lower()
    clavenum = int(input('Clave numerica: '))
    print (decifrar(cadcifrada,clavenum))



if __name__ == '__main__':  #Declaramos que se va a ejecutar main
    main()