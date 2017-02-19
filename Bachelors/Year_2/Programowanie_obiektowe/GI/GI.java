import java.awt.* ;
import java.awt.event.* ;
import javax.swing.*;

public class GI extends JFrame{
	Label blad = new Label("");
	Label stan = new Label();
	JTextField wplata = new JTextField(20);
	JButton dodaj = new JButton("Wpłać/Wypłać");
	JButton anuluj = new JButton("Anuluj");
	JButton unlock = new JButton("Odblokuj");
	Konto konto = new Konto();
	
	GI(){
		setTitle("Millenium S.A.");
		Container cp = getContentPane();
		cp.setLayout(new GridLayout(4,2,20,20)) ;
		cp.add(new Label("Stan konta:")) ;
		cp.add(stan);
		stan.setText(Integer.toString(konto.dajStan()));
		cp.add(new Label("Wpłata/Wypłata:"));
		cp.add(wplata);
		cp.add(anuluj);
		dodaj.addActionListener(new Obl1L());
		anuluj.addActionListener(new anuluj());
		unlock.addActionListener(new unblock());
		cp.add(dodaj) ;
		cp.add(unlock);
		cp.add(blad);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true) ;
	}
	
	int dajLiczbe(JTextField tf){
		try{return Integer.parseInt(tf.getText()) ;} 
		catch (NumberFormatException e){ return 0 ; }
	}
	
	class Obl1L implements ActionListener{
		public void actionPerformed(ActionEvent e){
			dodaj.setEnabled(false);
			anuluj.setEnabled(false);
			try { 
				if (dajLiczbe(wplata) == 0) {
					blad.setText("Nic nie zrobiono.");
					return;
				}
				konto.operacja(dajLiczbe(wplata));
				if (dajLiczbe(wplata) < 0) {
					blad.setText("Wypłacono "+Math.abs(dajLiczbe(wplata)));
				} 
				else{
					blad.setText("Wpłacono "+dajLiczbe(wplata));
				}
				stan.setText(Integer.toString(konto.dajStan()));
			} 
			catch (DebetException e1) {
				blad.setText("Przekroczono kwote o "+(-konto.dajStan()-dajLiczbe(wplata)));
			}
		}
	}
	
	class rezult implements ActionListener{
		public void actionPerformed(ActionEvent e){
			stan.setText(Integer.toString(konto.dajStan()));
		}
	}
	
	class anuluj implements ActionListener{
		public void actionPerformed(ActionEvent e){
			try {
				konto.anuluj();
				blad.setText("Anulowano ostatnią operację");
			} 
			catch (CancelException e1) {
				blad.setText("Brak operacji do anulowania!");
			}
			stan.setText(Integer.toString(konto.dajStan()));
		}
	}
	
	class unblock implements ActionListener{
		public void actionPerformed(ActionEvent e){
			dodaj.setEnabled(true);
			anuluj.setEnabled(true);
		}
	}
}