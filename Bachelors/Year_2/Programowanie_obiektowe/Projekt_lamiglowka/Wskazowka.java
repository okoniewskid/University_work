package Daniel;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Wskazowka extends JFrame{
    JLabel text = new JLabel();
    JButton zamknij = new JButton("Zamknij");
    ImageIcon ikona = new ImageIcon(getClass().getResource("wskazowka.jpg"));

    public Wskazowka(){
        setLayout(null);
        setName("Wskazowka");
        setSize(600 , 350);
        setLocation(150,150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        Container cp = getContentPane();
        cp.setLayout(null);       
        cp.add(zamknij);
        cp.add(text);
        text.setLocation(1,1);
        text.setSize(600,250);
        text.setIcon(ikona);
        zamknij.addActionListener(new close());
        zamknij.setBounds(260, 260, 100, 30);
    }

    class close implements ActionListener {
       public void actionPerformed(ActionEvent e){
            Wskazowka.this.dispose();
        }
    }
} 