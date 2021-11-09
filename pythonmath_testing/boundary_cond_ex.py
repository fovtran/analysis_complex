# -*- coding: utf-8 -*-
import random

def dard(n=1000):
    k = 0
    #Iteramos en el rango n
    for i in range(n):
        #generamos los n�meros aleatorios
        x = random.random()
        y = random.random()
        
        if (x ** 2 + y ** 2 <= 1):
            # Si cumple la condicion aumentamos en 1
            k = k + 1
    #para calcular aprox PI = 4 * float(k) / n
    #retornamos el numero de dardos que quedaron dentro del circulo
    return (4 * float(k) / n)

print (dard())
