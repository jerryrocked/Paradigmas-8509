/*Alen Paillalef
20.782.910-2*/

package actividad_3;

import java.util.Scanner;

public class Actividad_3 {

    public static void main(String[] args) {

        System.out.println("\n------------------------------------------");
        System.out.println("|     BIENVENIDO AL BANCO PAILLALEF      |");
        System.out.println("|                **   **                 |");
        System.out.println("------------------------------------------\n");
        System.out.println("-----------------------------------------------");
        System.out.println("| Elija alguna de nuestras cuentas Bancarias: |\n");
        System.out.println("|    1.- Presione 1 para Cuenta Ahorro        |\n");
        System.out.println("|    2.- Presione 2 para Cuenta Corriente     |\n");
        System.out.println("|    3.- Presione 3 para Cuenta a Plazo Fijo  |");
        System.out.println("|    (Solo disponible con 3 o 6 meses)        |\n");
        System.out.println("|    4.- Presione 4 si desea salir            |\n");
        System.out.println("| Ingrese el tipo de cuenta:                  |" );
        System.out.println("-----------------------------------------------");
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        float MT = 0;
        switch (TC){ 
            case 1:
                System.out.println("Ha escogido una Cuenta Ahorro\n");
                System.out.println("Indique monto que desea ingresar: ");
                int MA = sc.nextInt();
                MT = (float) (MA + (MA * 0.01));
                System.out.println("Su ahorro tras 1 año es: " + MT);
                break;
            case 2:
                System.out.println("Ha escogido una Cuenta Corriente\n");
                System.out.println("Indique monto que desea ingresar: ");
                int MC = sc.nextInt();
                MT = (float) (MC + (MC * 0.005));
                System.out.println("Su ahorro tras 1 año es: " + MT);
                break;
            case 3:
                System.out.println("\nHa escogido una Cuenta a Plazo Fijo\n");
                System.out.println("Elija entre las opciones disponibles:");
                System.out.println("    1.- Presione 1 si prefiere 3 Meses");
                System.out.println("    2.- Presione 2 si prefiere 6 Meses");
                int cantMeses = sc.nextInt();
                int MPF;
                if (cantMeses > 1){
                    System.out.println("Porfavor indique el monto que desea ingresar: ");
                    MPF = sc.nextInt();
                    MT = (float) (6*(MPF + (MPF*0.012)));
                    System.out.println("Su ahorro tras 6 meses: " + MT);
                }else{
                    System.out.println("Porfavor indique el monto que desea ingresar: ");
                    MPF = sc.nextInt();
                    MT = (float) (3*(MPF + (MPF*0.012)));
                    System.out.println("Su ahorro tras 3 meses: " + MT);
                }
                break;
            case 4:{
                break;
            }
        }
    }
}
