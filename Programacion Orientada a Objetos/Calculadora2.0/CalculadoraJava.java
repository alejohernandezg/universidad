import java.util.Scanner;

public class Main {

	public static class NoDivisible extends Exception {
		private final String message;

		public NoDivisible(final String mensaje) {
			message = mensaje;
		}

		public String getMessage() {
			return message;
		}
	}

	public static void main(final String [] args) {
		final Scanner scanner = new Scanner(System.in);
		int izq = readInteger(scanner, "Digite el numero izquierdo: ");
		int der = readInteger(scanner, "Digite el numero derecho: ");
		int res = pedirOperacion(scanner, izq, der);
		System.out.println("El resultado es: " + res + ".");
	}

	public static int pedirOperacion(final Scanner scanner, final int izq, final int der) {
		int operacion = readInteger(scanner, "Que operacion desea realizar?");
		return resolver(scanner, izq, der, operacion);
	}

	public static int resolver(final Scanner scanner, int izq, int der, int operacion) {
		int res = 0;
		if (operacion == 1) {
			res = suma(izq, der);
		} else if (operacion == 2) {
			res = resta(izq, der);
		} else if (operacion == 3) {
			try {
				res = div(izq, der);
			} catch (NoDivisible e) {
				return resolver(scanner, izq, readInteger(scanner, "Digite el numero derecho: "), operacion);
			}
		} else if (operacion == 4) {
			res = multi(izq, der);
		} else {
			return pedirOperacion(scanner, izq, der);
		}
		return res;
	}

	public static int suma(int izq, int der) {
		return izq + der;
	}

	public static int resta(int izq, int der) {
		return izq - der;
	}

	public static int multi(int izq, int der) {
		return izq * der;
	}

	public static int div(int izq, int der) throws NoDivisible {
		if (der == 0) {
			throw new NoDivisible("El numero es cero.");
		}
		return izq / der;
	}

	public static int readInteger(Scanner scanner, String message) {
		final int number;
		System.out.println(message);
		try {
			number = Integer.parseInt(scanner.nextLine());
		} catch (NumberFormatException e) {
			return readInteger(scanner, message);
		}
		return number;
	}

 }