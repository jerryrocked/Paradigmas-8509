package actidadparadigma;

//@author Rodrigo Valladares ; rut: 20847226-7

import java.util.Scanner;
public class actividad{

  public static void main(String[] args) {
      System.out.println("-------¡Banco XYZ!-------"+""+"\nTipos de cuenta:\n");
      System.out.println("1. Cuenta de Ahorro"+"\n"+"2. Cuenta Corriente"+"\n"+"3. Cuenta a Plazo Fijo"+"\n"+"-------------------------");
      System.out.print("\nEscoja una opción: ");
      try (Scanner input = new Scanner(System.in)) {
		int opcion=input.nextInt();
		  switch (opcion) {
		      case 1:{
		          System.out.print("\n"+"---Seleccionó la Cuenta de Ahorro---"+"\n"+"Ingrese el monto que desea depositar: ");
		          float monto=input.nextFloat();
		          System.out.print("Ingrese la cantidad de años que quiere calcular para ver cuanta ganancias tendrá para ese entonces: ");
		          int año=input.nextInt();
		          float loot = 0,ganancia1=0;
		          for (int i=0;i<año;i++) {//este for es para que vaya sacando la ganancia año a año ya que cada año su saldo va a cambiar
		        	  loot = monto/100;
		        	  monto = loot+monto;
		        	  ganancia1 = ganancia1 + loot;
		          }
		          System.out.print("En "+(año)+" años la ganancia será de $"+ganancia1+" y el valor total será $"+monto);
		          break;
		          }
		      case 2:{
		          System.out.println("\n"+"---Seleccionó la Cuenta Corriente---"+"\n"+"Ingrese el monto que desea depositar: ");
		          float monto=input.nextFloat();
		          System.out.print("Ingrese la cantidad de años que quiere calcular para ver cuanta ganancias tendrá para ese entonces: ");
		          int año=input.nextInt();
		          float loot= (monto*0.5f)/100,ganancia1=0;
		          for (int i=0;i<año;i++) {//este for es para que vaya sacando la ganancia año a año ya que cada año su saldo va a cambiar
		        	  loot = monto*0.5f/100;
		        	  monto = loot+monto;
		        	  ganancia1 = ganancia1 + loot;
		          }
		          System.out.print("En "+(año)+" años la ganancia será de $"+ganancia1+" y el valor total será $"+monto);
		          break;
		          }
		      case 3:
		          System.out.print("---Seleccionó la Cuenta a Plazo Fijo---"+"\n"+"Por cuánto tiempo desea la cuenta"+"\n"+"1. Tres Meses"+"\n"+"2. Seis Meses\n");
		          int tiempo=input.nextInt();
		      switch (tiempo) {
		          case 1:{
		              System.out.print("\n"+"---Seleccionó la Cuenta a Plazo Fijo de 3 Meses---"+"\n"+"Ingrese el monto que desea depositar: ");
		              float monto=input.nextFloat();
		              float loot=(monto*1.2f)/100;
		              float lootre=loot*3;
		              float total = monto + lootre;
		              System.out.print("La ganancia en 3 meses es de $"+lootre+" y el total es $"+total);
		              break;
		              }
		          case 2:{
		              System.out.print("\n"+"---Seleccionó la Cuenta a Plazo Fijo de 6 Meses---"+"\n"+"Ingrese el monto que desea depositar: ");
		              float monto=input.nextFloat();
		              float loot= (float)((monto*1.2)/100);
		              float lootre=loot*6;
		              float total = monto + lootre;
		              System.out.println("La ganancia en 6 meses es de $"+lootre+" y el total es $"+total);
		              break;
		              }
		          default:
		              System.out.println("Opción no válida");

		              
		              break;
		      }
break;
		      default:
	              System.out.println("Opción no válida");

		          break;
		  }
  }
}
}
