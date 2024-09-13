from sys import stdin 
import string

MAXN = 20
delta = {}

class Nodo:
	def __init__ (self, valor):
		self.info = valor
		self.hijos = []


class Arboln:
	def __init__(self):
		self.raiz = None
		self.stackpadre = []

	def insertar(self,valor, funcion = False):
		if (self.raiz == None):
			self.raiz = Nodo(valor)
			self.stackpadre.append(self.raiz)
			return True

		else:
			self.stackpadre[-1].hijos.append(Nodo(valor))
			if funcion :
				self.stackpadre.append(self.stackpadre[-1].hijos[-1])
			return True
		return False

	def actualizarPadreActual(self):
		if self.stackpadre != []:
			self.stackpadre.pop()

def esVariable(arbol):
	if arbol.info[0] in string.ascii_uppercase and len(arbol.hijos) == 0:
		return True
	return False

def esFuncion(arbol):
	if len(arbol.hijos) > 0:
		return True
	return False

def esConstante(arbol):	
	if arbol.info[0] in string.ascii_lowercase and len(arbol.hijos) == 0:
		return True
	return False

def varEnArbo(arbol,variable):
	ans = False
	if arbol.info == variable:
		return True
	i = 0
	while i < len(arbol.hijos) and not(ans):
		ans = varEnArbo(arbol.hijos[i],variable)
		i += 1
	return ans



def cambiarVariable(arbol):
	global delta
	for x in delta:
		if arbol.info == x:
			arbol.info = delta[x].info
			arbol.hijos = delta[x].hijos
def imprimirArbol(nodo):
	if len(nodo.hijos) == 0:
		print(nodo.info)
	else:
		print("Soy", nodo.info , "y mis hijos son:")
		
		for hijo in nodo.hijos:
			
			imprimirArbol(hijo)
		print("--")

def cambiarFuncion(arbol):
	global delta
	flag = True
	if len(delta) > 0:
		for x in delta:
			if arbol.info == x:
				arbol.info = delta[x].info
				arbol.hijos = delta[x].hijos
				flag = False
		i=0
		while i < len(arbol.hijos) and flag:
				cambiarFuncion(arbol.hijos[i])
				i+=1

def contieneVariableDelta(arbol):
	ans = False
	for x in delta:
		if arbol.info == x:
			return True
		i = 0
		while i < len(arbol.hijos):
			ans = contieneVariableDelta(arbol.hijos[i])
			i +=1
		return ans

def optimizarDiccionario():
	global delta

	for x in delta:
		if esVariable(delta[x]):
			for y in delta:
			 	if x != y:
			 		if delta[x] == y:
			 			delta[x] = delta[y]
			 			if delta[x].hijos == delta[y].hijos and delta[x].info == delta[y].info:
			 				return False
	return True

def unificar(arbol1,arbol2):
	
	global delta
	
	ans = True

	if esVariable(arbol1):
		cambiarVariable(arbol1)

	if esVariable(arbol2):
		cambiarVariable(arbol2)

	if esFuncion(arbol1):
		cambiarFuncion(arbol1)

	if esFuncion(arbol2):
		cambiarFuncion(arbol2)

	lenHijosa1 = len(arbol1.hijos)
	lenHijosa2 = len(arbol2.hijos)

	if esFuncion(arbol1) and esVariable(arbol2):
		if not(varEnArbo(arbol1,arbol2.info)):
			if not(arbol2.info in delta):
				delta[arbol2.info] = arbol1
				arbol2.info = arbol1.info
				arbol2.hijos = arbol1.hijos
			return True

		return False

	if esFuncion(arbol2) and esVariable(arbol1):
		if not(varEnArbo(arbol2,arbol1.info)):
			if not(arbol1.info in delta):
				delta[arbol1.info] = arbol2
			return True
		return False
		

	if esVariable(arbol1) and esVariable(arbol2):
		if arbol1.info != arbol2.info:
			if arbol2.info in delta:
				if esVariable(delta[arbol2.info]):
					delta[arbol2.info] = arbol1
					arbol2.info = arbol1.info
					return True
				else:
					return False
			else:
				delta[arbol2.info] = arbol1
				arbol2.info = arbol1.info
		return True


	if esVariable(arbol1) and esConstante(arbol2):
		if not(arbol1.info in delta):
			delta[arbol1.info] = arbol2
			return True
		else:
			if delta[arbol1.info].info == arbol2.info:
				return True
		return False

	if esVariable(arbol2) and esConstante(arbol1):
		if not(arbol2.info in delta):
			delta[arbol2.info] = arbol1
			arbol2.info = arbol1.info
			return True
		else:
			arbol2.info = delta[arbol2.info].info
			return True
		return False

	if (esFuncion(arbol1) and esConstante(arbol2)) or (esFuncion(arbol2) and esConstante(arbol1)):
		return False

	if esConstante(arbol1) and esConstante(arbol2):
		if arbol1.info == arbol2.info:
			return True
		else:
			return False

	#Si alguno de los arboles tiene mas hijos que el otro no se puede generar la unificacion
	if esFuncion(arbol1) and esFuncion(arbol2): 

		if lenHijosa1 != lenHijosa2 or arbol1.info != arbol2.info:
			return False
		else:
			i = 0
			while i < lenHijosa1 and ans:
				ans = unificar(arbol1.hijos[i],arbol2.hijos[i])
				if not(optimizarDiccionario()):
					ans = False
				i += 1
	
	return ans




def solve(literales):
	global delta
	delta = {}
	#Aqui se guardaran los literales padres despues de realizar la conversion a arboles n-arios
	literalesarboles = []
	i = 0
	while i < len(literales):
		j = 0
		#Aqui se guardaran los padres de las funciones 
		namet = ""
		literal = Arboln()
		while j < len(literales[i]):

			if literales[i][j] == "(":
				literal.insertar(namet,True)
				namet = ""

			elif literales[i][j] == ",":
				if namet != "":
					literal.insertar(namet)
				namet = ""
			elif literales[i][j] == ")":
				if namet != "":
					literal.insertar(namet)
				literal.actualizarPadreActual()
				namet = ""

			elif j+1 == len(literales[i]) and literal.raiz == None:
				namet = namet + literales[i][j]
				literal.insertar(namet)
				namet = ""

			else:
				namet = namet + literales[i][j]
			j+= 1
		literalesarboles.append(literal)
			
		i+=1

	n = 0
	ans = True
	while n < len(literalesarboles)-1 and ans:
		if unificar(literalesarboles[n].raiz,literalesarboles[n+1].raiz):
			
			ans = True
		else:
			return False
		n += 1
	return ans




def main():
	line = stdin.readline().strip().split()
	name = line[0]
	n = int(line[1])
	while n != 0 :
		literales = []
		if n == 1:
			print("analysis inconclusive on", name)
		if n >= 2 and n <= MAXN:
			i = 0
			
			while n > i:
				literal = stdin.readline().strip()
				literales.append(literal)
				i += 1
			if solve(literales):
				print("analysis inconclusive on", name)
			else:
				print(name, "is a Starflyer agent")
		else:
			i = 0
			while i != n:
				line = stdin.readline().strip()
				i+=1

		line = stdin.readline().strip().split()
		name = line[0]
		n = int(line[1])

main()