import java.util.Scanner;

public class App {

    // Funcion Banco pide los datos al usuario y hace los calculos de ganancia anual
    // y mensual
    static void Banco() {

        // pide el nombre y el tipo de cuenta que el cliente desee crear
        Scanner datos = new Scanner(System.in);
        System.out.println("Banco XYZ\n");

        System.out.println("Ingrese su nombre: ");
        String nombre = datos.nextLine();

        System.out.println("Señor(a) " + nombre + " que tipo de cuenta desea abrir?\n");

        System.out.println("1. CUENTA AHORRO (1% ANUAL)");
        System.out.println("2. CUENTA CORRIENTE (0,5% ANUAL)");
        System.out.println("3. CUENTA A PLAZO FIJO (1,2% MENSUAL)");
        System.out.println("ESCOJA UNA OPCION:");
        int opc = datos.nextInt();

        // inicia variables para calculo de ganancia
        double porcAnual = 0;
        double valorIngresado = 0;
        double ganancia = 0;

        switch (opc) {
            case 1:

                // Si el cliente selecciona CUENTA AHORRO
                porcAnual = 0.01;

                System.out.println("Cuanto desea ingresar en tu cuenta?: ");
                valorIngresado = datos.nextDouble();

                ganancia = valorIngresado * porcAnual;

                System.out.println("Con la CUENTA AHORRO usted ganara " + Math.round(ganancia) + " anualmente");
                break;

            case 2:

                // Si el cliente selecciona CUENTA CORRIENTE
                porcAnual = 0.005;

                System.out.println("Cuanto desea ingresar en tu cuenta?: ");
                valorIngresado = datos.nextDouble();

                ganancia = valorIngresado * porcAnual;

                System.out.println("Con la CUENTA CORRIENTE usted ganara " + Math.round(ganancia) + " anualmente");

                break;

            case 3:

                // Si el cliente selecciona CUENTA A PLAZO FIJO
                System.out.println("1. Tres meses");
                System.out.println("2. Seis meses");
                System.out.println("ESCOJA UNA OPCION:");
                int opc2 = datos.nextInt();

                if (opc2 == 1) {
                    porcAnual = (0.012 * 3) / 12;

                    System.out.println("Cuanto desea ingresar en tu cuenta?: ");
                    valorIngresado = datos.nextDouble();

                    ganancia = valorIngresado * porcAnual;

                    System.out.println(
                            "Con la CUENTA A PLAZO FIJO usted ganara " + Math.round(ganancia) + " a los tres meses");
                }
                if (opc2 == 2) {
                    porcAnual = (0.012 * 6) / 12;

                    System.out.println("Cuanto desea ingresar en tu cuenta?: ");
                    valorIngresado = datos.nextDouble();

                    ganancia = valorIngresado * porcAnual;

                    System.out.println(
                            "Con la CUENTA A PLAZO FIJO usted ganara " + Math.round(ganancia) + " a los seis meses");
                }

                break;
        }

        datos.close();
    }

    public static void main(String[] args) throws Exception {

        // LLama a la funcion Banco
        Banco();
    }
}
