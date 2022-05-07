/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad3_JuanPabloRetamales;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author Juan Pablo Retamales
 */
class MarcoCombo extends JFrame{
	public MarcoCombo() {
		setBounds(200,20,600,400);
		setSize(400,300);
		setTitle("BANCO XYZ");
		
		LaminaCombo miLamina = new LaminaCombo();
		add(miLamina);
		setVisible(true);
		
	}
        class LaminaCombo extends JPanel{
	public LaminaCombo() {
		
		setLayout(new BorderLayout());
		caja1 = new JTextField();
		caja1.setBounds(100,50,200,30);
                add(caja1);
                JButton boton = new JButton("calcular");
		boton.setBounds(150,90,90,20);
		
		add(boton);
		texto = new JLabel("Dinero: $0",JLabel.CENTER);
                texto2 = new JLabel("",JLabel.CENTER);
                
		
		texto.setFont(new Font("Serif",Font.PLAIN,18));
                texto2.setFont(new Font("Serif",Font.PLAIN,18));
                
                
		add(texto);
		add(texto2,BorderLayout.SOUTH);
                
		JPanel laminaNorte = new JPanel();
                
		
		comboBox = new JComboBox();
		comboBox2 = new JComboBox();
		
		comboBox.addItem("CUENTA AHORRO");

		comboBox.addItem("CUENTA CORRIENTE");

		comboBox.addItem("CUENTA A PLAZO FIJO");
		
		comboBox2.addItem("3 MESES");

		comboBox2.addItem("6 MESES");
		
		comboBox2.setEnabled(false);
		
		eventoBoton miEvento = new eventoBoton();
                eventoComboBox miEvento2 = new eventoComboBox();
                boton.addActionListener(miEvento);
                comboBox.addActionListener(miEvento2);
		laminaNorte.add(comboBox);
                laminaNorte.add(comboBox2);
		
		add(laminaNorte,BorderLayout.NORTH);
		
		
		
				
		
	}
	  private class eventoComboBox implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                String aux1 = (String)comboBox.getSelectedItem();
                
                if("CUENTA A PLAZO FIJO".equals(aux1)){
                    
                   comboBox2.setEnabled(true);
                    
                }
                else{
                    comboBox2.setEnabled(false);
                }
            }
        }
        private class eventoBoton implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                
                int dinero=0;
                String aux1 = (String)comboBox.getSelectedItem();
                String aux2 = (String)comboBox2.getSelectedItem();
                
                if( isNumeric(caja1.getText())) {
                    texto2.setText("Listo");
                    if(aux1.equals("CUENTA AHORRO")){
                    dinero = Integer.valueOf(caja1.getText()) + Integer.valueOf(caja1.getText())/100;
                }
                if(aux1.equals("CUENTA CORRIENTE")){
                    dinero = Integer.valueOf(caja1.getText()) + Integer.valueOf(caja1.getText())*5/1000;
                }
                if(aux1.equals("CUENTA A PLAZO FIJO") && aux2.equals("3 MESES")){
                    dinero = Integer.valueOf(caja1.getText());
                    for(int i = 0;i<3;i++){
                        dinero = dinero*12/10;
                    }
                    
                }
                if(aux1.equals("CUENTA A PLAZO FIJO") && aux2.equals("6 MESES")){
                    dinero = Integer.valueOf(caja1.getText());
                    for(int i = 0;i<6;i++){
                        dinero = dinero*12/10;
                    }
                }
                
                texto.setText("Dinero: $" + String.valueOf(dinero));
                }
                else{
                    texto2.setText("ERROR: no ingreso un numero valido");
                    
                    
                }
                
                
            }
            public static boolean isNumeric(String str) { 
                try {  
                  Double.parseDouble(str);  
                  return true;
                } catch(NumberFormatException e){  
                  return false;  
                }  
              }
                      }
	
	
	
	private JTextField caja1;
	private JLabel texto,texto2;
	private JComboBox comboBox,comboBox2;
        

}

}
