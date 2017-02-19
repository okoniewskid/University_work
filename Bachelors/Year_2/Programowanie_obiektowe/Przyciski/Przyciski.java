import java.awt.* ;
import java.awt.event.* ;
import javax.swing.*;

class Przyciski extends JFrame{
	Integer score = 0;
	JTextField t = new JTextField(20);
 	JButton bZ = new JButton("Zeruj");
	JButton b1 = new JButton("przycisk 1") ;
  	JButton b2 = new JButton("przycisk 2") ;
	JButton b3 = new JButton("przycisk 3") ;
	JButton b4 = new JButton("przycisk 4") ;
	
  	Przyciski(){
    		setTitle("Przyciski");
    		Container cp = getContentPane();
                cp.setLayout(new FlowLayout());
		cp.add(bZ);
    		cp.add(b1);
    		cp.add(b2);
		cp.add(b3);
		cp.add(b4);
    		cp.add(t);
    		setDefaultCloseOperation(EXIT_ON_CLOSE);
    		setSize(500,200) ;
    		setVisible(true) ; 
    		b1.addActionListener( new NumerButton() );
   		b2.addActionListener( new NumerButton() );
		b3.addActionListener( new NumerButton() );
		b4.addActionListener( new NumerButton()	);
		bZ.addActionListener( new ZerujButton() );
    		b1.setBackground( Color.green );
		b2.setBackground( Color.green );
		b3.setBackground( Color.green );
		b4.setBackground( Color.green );
  	}

	class NumerButton implements ActionListener {
		
 		public void actionPerformed(ActionEvent e) 
		{
			JButton getBut = (JButton)e.getSource();
			int yellowCount = 0;
			if( getBut.getBackground() == Color.green )
			{
				if( b1.getBackground() == Color.yellow ){ yellowCount++; }
                                if( b2.getBackground() == Color.yellow ){ yellowCount++; }
                                if( b3.getBackground() == Color.yellow ){ yellowCount++; }
                                if( b4.getBackground() == Color.yellow ){ yellowCount++; }
                                if( yellowCount < 2 )
                                {
                                        getBut.setBackground( Color.yellow );
                                }

			}
			else
			{
				getBut.setBackground( Color.green );
			}
			
			score++;
			t.setText( score.toString() );
  		}		
	}
	
	class ZerujButton implements ActionListener {
		public void actionPerformed(ActionEvent e)
		{
			score = 0;
			t.setText(score.toString() );	
		}
	}

  	public static void main(String[] arg)
	{
    		JFrame f = new Przyciski() ;
  	}
}