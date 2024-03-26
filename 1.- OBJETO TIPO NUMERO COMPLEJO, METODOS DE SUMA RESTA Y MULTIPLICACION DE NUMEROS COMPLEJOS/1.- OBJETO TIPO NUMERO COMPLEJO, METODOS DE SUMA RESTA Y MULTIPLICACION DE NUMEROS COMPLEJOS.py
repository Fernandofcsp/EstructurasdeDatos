from math import sqrt

class Complejo(object):

    def __init__(self, real, imag=0.0):
        self.real = real
        self.imag = imag
        print(self.real + self.imag)

    def __add__(self, otro):
        print('\nSuma:')
        return Complejo(self.real + otro.real, self.imag + otro.imag)

    def __sub__(self, otro):
        print('\nResta:')
        return Complejo(self.real - otro.real, self.imag - otro.imag)
    
    def __mul__(self, otro):
        print('\nMultiplicacion:')
        return Complejo((self.real * otro.real) - (self.imag * otro.imag),
            (self.imag * otro.real) + (self.real * otro.imag))

    def __truediv__(self, otro):
        print('\nDivision:')
        r = (otro.real**2 + otro.imag**2)
        return Complejo((self.real*otro.real - self.imag*otro.imag)/r,
            (self.imag*otro.real + self.real*otro.imag)/r)

    def __abs__(self):
        print('\nValor Absoluto:')
        new = (self.real**2 + (self.imag**2)*-1)
        return Complejo(sqrt(new.real))


i = Complejo(10, 15j)
k = Complejo(5, 10j)

#SUMA
i + k
#RESTA
i - k
# MULTIPLICACION
i * k
# DIVISION
i / k
#VALORES ABSOLUTOS
abs(i)
abs(k)
"""
SALIDA
(10+15j)
(5+10j)

Suma:
(15+25j)

Resta:
(5+5j)

Multiplicacion:
(200+175j)

Division:
(-2.6666666666666665-2.3333333333333335j)

Valor Absoluto:
18.027756377319946

Valor Absoluto:
11.180339887498949
"""