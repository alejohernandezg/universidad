"""
ANTES DE CORRER EL CODIGO EJECUTAR EN TERMINAL:
-WINDOWS: PIP INSTALL NUMPY
-LINUX/MAC: PIP3 INSTALL NUMPY
"""
import numpy as npp
from collections import Counter
from math import sqrt

def PedirGrado():
    global num
    print("\nIngrese un grado, debe ser de 1 - 4")
    estado=True
    while estado:
        try:
            num=input(" ")
            num=int(num)
            if num > 4 or num == 0:
                raise ValueError ("¡No cumple con las condiciones! Intente de nuevo")
            
                estado = False
            break
        except:
            print("¡No cumple con las condiciones! Intente de nuevo")
       
    return num

def CoeficientesYCondiciones():
    global num
    a=0
    cofList=[]
    while a < num:
        cof=float(input("Ingrese un coeficiente: "))
        cofList.append(cof*(-1))
        a=a+1
##    print(cofList)

    b=0
    condList=[]
    while b< num:
        cond=float(input("Ingrese una condicion inicial: "))
        condList.append(cond)
        b=b+1
    
    i=0
    pol=[1]
    for i in cofList:
        pol.append(i)
        i=i+1
##    print(pol)
    
    if num >2:
        raices = npp.roots(pol)
    
##        print(raices)
    else:
        a=pol[0]
        b=pol[1]
        c=pol[2]
        raices=[]
        x1 = (-b + sqrt(b**2 - 4*a*c)) / (2 * a)
        x2 = (-b - sqrt(b**2 - 4*a*c)) / (2 * a)
        raices.append(x1)
        raices.append(x2)
##        print(raices)

    contRepetidos= Counter(raices)

##    print(contRepetidos)
    values = contRepetidos.values()
    for v in values:
        if v>1:
            contRepetidos2=2
        else:
            contRepetidos2=0
        
    if num == 4:
        if contRepetidos2 == 2:
            
            a11=(1*((raices[0])**0))
            a12=(1*0*((raices[0])**0))
            a13=(1*(0**2)*((raices[0])**0))
            a14=(1*(0**3)*(raices[0])**0)
            a21=(1*((raices[0])**1))
            a22=(1*1*((raices[0])**1))
            a23=(1*(1**2)*((raices[0])**1))
            a24=(1*(1**3)*(raices[0])**1)
            a31=(1*((raices[0])**2))
            a32=(1*2*((raices[0])**2))
            a33=(1*(2**2)*((raices[0])**2))
            a34=(1*(2**3)*(raices[0])**2)
            a41=(1*((raices[0])**3))
            a42=(1*3*((raices[0])**3))
            a43=(1*(3**2)*((raices[0])**3))
            a44=(1*(3**3)*(raices[0])**3)

            A=npp.matrix([[a11,a12,a13],[a21,a22,a23],[a31,a32,a33]])
            B=npp.matrix([[condList[0]],[condList[1]],[condList[2]]])
            X=A**(-1)*B
##            print("El resultado de x es:", X)
            print(X[0],"(",raices[0],")*n","+",X[1],"(n)",raices[1],")**n","+",X[2],"(n)**2",raices[2],")**n","+",X[3],"(n)**3",raices[3],")**n")
        else:
            a11=(1*(raices[0])**0)
            a12=(1*(raices[1])**0)
            a13=(1*(raices[2])**0)
            a14=(1*(raices[3])**0)
            a21=(1*(raices[0])**1)
            a22=(1*(raices[1])**1)
            a23=(1*(raices[2])**1)
            a24=(1*(raices[3])**1)
            a31=(1*(raices[0])**2)
            a32=(1*(raices[1])**2)
            a33=(1*(raices[2])**2)
            a34=(1*(raices[3])**2)
            a41=(1*(raices[0])**3)
            a42=(1*(raices[1])**3)
            a43=(1*(raices[2])**3)
            a44=(1*(raices[3])**3)

            A=npp.matrix([[a11,a12,a13,a14],[a21,a22,a23,a24],[a31,a32,a33,a34],[a41,a42,a43,a44]])
            B=npp.matrix([[condList[0]],[condList[1]],[condList[2]],[condList[3]]])
            X=A**(-1)*B
##            print("El resultado de x es:", X)
            print(X[0],"(",raices[0],")**n","+",X[1],"(",raices[1],")**n","+",X[2],"(",raices[2],")**n","+",X[3],"(",raices[3],")**n")
            

    if num == 3:
        if contRepetidos2 == 2:
            
            a11=((raices[0])**0)
            a12=(1*0*((raices[0])**0))
            a13=(1*(0**2)*((raices[0])**0))
            a21=(1*((raices[0])**1))
            a22=(1*1*((raices[0])**1))
            a23=(1*(1**2)*((raices[0])**1))
            a31=(1*((raices[0])**2))
            a32=(1*2*((raices[0])**2))
            a33=(1*(2**2)*((raices[0])**2))
            
            A=npp.matrix([[a11,a12,a13],[a21,a22,a23],[a31,a32,a33]])
            B=npp.matrix([[condList[0]],[condList[1]],[condList[2]]])
            X=A**(-1)*B
##            print("El resultado de x es:", X)
            print(X[0],"(",raices[0],")*n","+",X[1],"(n)",raices[1],")**n","+",X[2],"(n)**2",raices[2],")**n")

        else:
            a11=(1*(raices[0])**0)
            a12=(1*(raices[1])**0)
            a13=(1*(raices[2])**0)
            a21=(1*(raices[0])**1)
            a22=(1*(raices[1])**1)
            a23=(1*(raices[2])**1)
            a31=(1*(raices[0])**2)
            a32=(1*(raices[1])**2)
            a33=(1*(raices[2])**2)

            A=npp.matrix([[a11,a12,a13],[a21,a22,a23],[a31,a32,a33]])
            B=npp.matrix([[condList[0]],[condList[1]],[condList[2]]])
            X=A**(-1)*B
##            print("El resultado de x es:", X)
            print(X[0],"(",raices[0],")**n","+",X[1],"(",raices[1],")**n","+",X[2],"(",raices[2],")**n")

    elif num == 2:
        if contRepetidos2 == 2:
            
            a11=(1*((raices[0])**0))
            a12=(1*0*((raices[0])**0))
            a21=(1*((raices[0])**1))
            a22=(1*1*((raices[0])**1))
            
            A=npp.matrix([[a11,a12],[a21,a22]])
            B=npp.matrix([[condList[0]],[condList[1]]])
            X=A**(-1)*B
##            print("El resultado de x es:", X)
            print(X[0],"(",raices[0],")*n","+",X[1],"(n)",raices[1],")**n")
            
        else:
            a11=(1*(raices[0])**0)
            a12=(1*(raices[1])**0)
            a21=(1*(raices[0])**1)
            a22=(1*(raices[1])**1)

            A=npp.matrix([[a11,a12],[a21,a22]])
            B=npp.matrix([[condList[0]],[condList[1]]])
            X=A**(-1)*B
##            print("El resultado de x es:", X)
            print(X[0],"(",raices[0],")**n","+",X[1],"(",raices[1],")**n")

    elif num == 1:

        a11=(1*(raices[0])**0)

        A=npp.matrix([[a11]])
        B=npp.matrix([[condList[0]]])
        X=A**(-1)*B
##        print("El resultado de x es:", X)
        print(X[0],"(",raices[0],")**n")

    #A=npp.matrix

    
#def matriz():
#    a=npp.matrix([[1,1,1],[-1,-2,3],[1,4,9]])
#    b=npp.matrix([[9],[10],[32]])
#    x=a**(-1)*b
#    print("El resultado de x es:", x)
##    print("El otro es:",a*x)
PedirGrado()
CoeficientesYCondiciones()
##Condiciones()
##factorizar()
##matriz()

