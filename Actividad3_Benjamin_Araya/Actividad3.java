
package Actividad3_Benjamin_Araya;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class Actividad3 extends JFrame{
    private JPanel panel;
    private JTextField cajatexto;
    private JLabel ganancia;
    Actividad3(){
        setSize(500,500);
        setTitle("Banco XYZ");
        setLocationRelativeTo(null);
        this.getContentPane().setBackground(Color.gray);
        iniciarcomponentes();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    private void iniciarcomponentes(){
        colocarpanel();
        colocaretiqueta();
        colocarboton();
        colocartexto();
    }
    private void colocarpanel(){
        panel = new JPanel();
        panel.setLayout(null);
        this.getContentPane().add(panel);
    }
    private void colocaretiqueta(){
        JLabel etiqueta1 = new JLabel();
        etiqueta1.setText("BANCO XYZ");
        etiqueta1.setBounds(180,10,200,30);
        etiqueta1.setForeground(Color.red);
        etiqueta1.setFont(new Font("Arial",Font.BOLD,24));
        panel.add(etiqueta1);
        JLabel etiqueta2 = new JLabel();
        etiqueta2.setText("Monto de dinero (CLP):");
        etiqueta2.setBounds(10,50,200,30);
        etiqueta2.setForeground(Color.black);
        etiqueta2.setFont(new Font("Arial",Font.PLAIN,14));
        panel.add(etiqueta2);
        JLabel etiqueta3 = new JLabel();
        etiqueta3.setText("CUENTAS:");
        etiqueta3.setBounds(10,80,200,30);
        etiqueta3.setForeground(Color.black);
        etiqueta3.setFont(new Font("Arial",Font.BOLD,14));
        panel.add(etiqueta3);
        JLabel etiqueta4 = new JLabel();
        etiqueta4.setText("Se produce una ganancia de:");
        etiqueta4.setBounds(150,290,300,30);
        etiqueta4.setForeground(Color.black);
        etiqueta4.setFont(new Font("Arial",Font.ITALIC,14));
        panel.add(etiqueta4);
        JLabel etiqueta5 = new JLabel();
        etiqueta5.setText("Nombre: Benjamin Araya");
        etiqueta5.setBounds(350,415,300,30);
        etiqueta5.setForeground(Color.black);
        etiqueta5.setFont(new Font("Arial",Font.PLAIN,10));
        panel.add(etiqueta5);
        JLabel etiqueta6 = new JLabel();
        etiqueta6.setText("NRC: 8509");
        etiqueta6.setBounds(350,430,300,30);
        etiqueta6.setForeground(Color.black);
        etiqueta6.setFont(new Font("Arial",Font.PLAIN,10));
        panel.add(etiqueta6);
        
    }
    private void colocarboton(){
        JButton botonAH = new JButton();
        botonAH.setText("CUENTA AHORRO");
        botonAH.setBounds(150,90,200,40);
        botonAH.setEnabled(true);
        botonAH.setForeground(Color.blue);
        panel.add(botonAH);
        
        ganancia = new JLabel();
        ganancia.setBounds(180,320,200,30);
        panel.add(ganancia);
        ActionListener oa1 = new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                double g1 = Integer.parseInt(cajatexto.getText())*0.01;
                double rg1 = (double) Math.round(g1 * 100) / 100;
                ganancia.setText("$"+Double.toString(rg1)+" Pesos Anuales");
            }
        };
        botonAH.addActionListener(oa1);
        
        JButton botonCO = new JButton();
        botonCO.setText("CUENTA CORRIENTE");
        botonCO.setBounds(150,140,200,40);
        botonCO.setEnabled(true);
        botonCO.setForeground(Color.blue);
        panel.add(botonCO);
        
        ActionListener oa2 = new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                double g2 = Integer.parseInt(cajatexto.getText())*0.005;
                double rg2 = (double) Math.round(g2 * 100) / 100;
                ganancia.setText("$"+Double.toString(rg2)+" Pesos Anuales");
            }
        };
        botonCO.addActionListener(oa2);
        
        JButton botonPF = new JButton();
        botonPF.setText("CUENTA A PLAZO FIJO 3 MESES");
        botonPF.setBounds(125,190,250,40);
        botonPF.setEnabled(true);
        botonPF.setForeground(Color.blue);
        panel.add(botonPF);
        
        ActionListener oa3 = new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                double g3 = Integer.parseInt(cajatexto.getText())*0.012*3;
                double rg3 = (double) Math.round(g3 * 100) / 100;
                ganancia.setText("$"+Double.toString(rg3)+" Pesos en 3 Meses");
            }
        };
        botonPF.addActionListener(oa3);
        
        JButton botonPF2 = new JButton();
        botonPF2.setText("CUENTA A PLAZO FIJO 6 MESES");
        botonPF2.setBounds(125,240,250,40);
        botonPF2.setEnabled(true);
        botonPF2.setForeground(Color.blue);
        panel.add(botonPF2);
        
        ActionListener oa4 = new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                double g4 = Integer.parseInt(cajatexto.getText())*0.012*6;
                double rg4 = (double) Math.round(g4 * 100) / 100;
                ganancia.setText("$"+Double.toString(rg4)+" Pesos en 6 Meses");
            }
        };
        botonPF2.addActionListener(oa4);
    }
    private void colocartexto(){
        cajatexto = new JTextField();
        cajatexto.setBounds(170,50,150,30);
        panel.add(cajatexto);
    }
    
}
