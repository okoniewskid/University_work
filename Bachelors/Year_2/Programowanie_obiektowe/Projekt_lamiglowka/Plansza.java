package Daniel;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.plaf.nimbus.NimbusLookAndFeel;
import javax.swing.plaf.nimbus.NimbusStyle;

class Plansza extends JFrame implements Serializable {
    public ArrayList<Historia> historia = new ArrayList<Historia>();
    public ArrayList<Historia> historia2 = new ArrayList<Historia>();
    public Historia h1 = new Historia();
    public int val,kt,wsk;
    public int[][] tab2 = new int[10][10];
    public int[] sp = new int[14];
    JMenuBar menu= new JMenuBar();
    JMenu rozwijane = new JMenu("Menu");
    JMenuItem zapis = new JMenuItem("Zapisz gre");
    JMenuItem odczyt = new JMenuItem("Wczytaj gre");
    JMenuItem help = new JMenuItem("Zasady");
    JButton tab[][] = new JButton[10][10];
    JButton t[] = new JButton[14];
    JButton spr = new JButton("Sprawdz");
    JButton cofnij = new JButton("Cofnij");
    JButton dalej = new JButton("Dalej");
    JPanel plansza = new JPanel();
    JPanel margin = new JPanel();
    JPanel sterowanie = new JPanel();
    JPanel sprawdzenie = new JPanel();
    JLabel pusto = new JLabel(" ");
    Font myFont = new Font("Serif", Font.BOLD,14);
    
    public Plansza() {
        setTitle("Jedna Czasteczka");
        setSize(800, 600);
        setLocation(100, 100);
        setVisible(true);
        setJMenuBar(menu);
        menu.add(rozwijane);
        rozwijane.add(zapis);
        rozwijane.add(odczyt);
        rozwijane.add(help);
        zapis.addActionListener(new zapisywanie());
        odczyt.addActionListener(new odczytywanie());
        int i, j;
        
        spr.addActionListener(new D());
        help.addActionListener(new pomocc());
        
        Container cp = getContentPane();
        
        cp.setPreferredSize(new Dimension(800,600));
        cp.setLayout(new GridBagLayout());
        GridBagConstraints constraints = new GridBagConstraints();
        constraints.fill = GridBagConstraints.BOTH;
        constraints.weightx = 0.01; 
        constraints.weighty = 0.01;
        cp.add(plansza, constraints);
        constraints.fill = GridBagConstraints.BOTH;
        constraints.weightx = 0.001;  
        constraints.weighty = 0.001;
        cp.add(margin,constraints);
        constraints.fill = GridBagConstraints.BOTH;
        constraints.weightx = 0.001;
        constraints.weighty = 0.001;
        cp.add(sterowanie,constraints);

        sterowanie.setLayout(new GridLayout(15,1));  
        sterowanie.add(cofnij);
        sterowanie.add(dalej);
        sterowanie.add(spr);
        sterowanie.add(pusto);
        
        cofnij.addActionListener(new E());
        dalej.addActionListener(new F());
        plansza.setLayout(new GridLayout(8, 8));
        for (i = 1; i < 8; i++)
            for (j = 1; j < 8; j++) {
                tab[i][j] = new JButton(" ");
                tab[i][j].setFont(myFont);
                tab[i][j].setBackground(Color.WHITE);
                plansza.add(tab[i][j]);
                (tab[i][j]).addActionListener(new B(i, j));
            }
        setPlansza();
        pack();
        System.out.println(getSize());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    //Do guzikow
    class B implements ActionListener {
        int i, j;
        B(int i, int j){
            this.i = i;
            this.j = j;
        }
        public void actionPerformed(ActionEvent e) {
            JButton getBut = (JButton)e.getSource();
            if(getBut.getBackground() == Color.WHITE){
                val = 1;           
            }
            else{ val = 2;}
            historia.add(new Historia(i,j,tab2[i][j],val));
            if(getBut.getBackground() == Color.WHITE){
                getBut.setBackground(Color.LIGHT_GRAY);           
            }
            else{
                getBut.setBackground(Color.WHITE);  
            }
        }
    }
    //Sprawdzenie poprawnosci wyniku
    class D implements ActionListener{
        public void actionPerformed(ActionEvent e){
            boolean w=true;
            if(tab[1][2].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[1][4].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[2][5].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[2][7].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[3][4].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[3][6].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[4][1].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[4][3].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[4][7].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[5][2].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[5][6].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[6][3].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[6][5].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[6][7].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[7][2].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(tab[7][4].getBackground()!= Color.LIGHT_GRAY) w=false;
            if(w==false){
                pusto.setText("Bledne rozwiazanie");
            }
                else pusto.setText("Udalo sie!");
        }
    }
    //Cofnij
    class E implements ActionListener{
        public void actionPerformed(ActionEvent e){
            wsk=historia.size()-1;
            if(wsk>=0){
                h1 = historia.get(wsk);
                historia2.add(h1);
                historia.remove(wsk);
              if (h1.val == 1) tab[h1.x][h1.y].setBackground(Color.WHITE);
                else {
                    tab[h1.x][h1.y].setBackground(Color.LIGHT_GRAY);
                }
                tab2[h1.x][h1.y]=h1.value;
                System.out.println(h1.value);
            }
        }
    }
    //Dalej
    class F implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            wsk = historia2.size() - 1;
            System.out.println(wsk);
            if (wsk >= 0) {
                h1 = historia2.get(wsk);
                historia.add(h1);
                historia2.remove(wsk);
                if (h1.val == 1) tab[h1.x][h1.y].setBackground(Color.LIGHT_GRAY);
                else {
                    tab[h1.x][h1.y].setBackground(Color.WHITE);
                }
                tab2[h1.x][h1.y] = h1.val;
            }
        }
    }
    
    class pomocc implements ActionListener{
        public void actionPerformed(ActionEvent e){
            new Wskazowka();
        }
    }
    
    class zapisywanie implements ActionListener{
        public void actionPerformed(ActionEvent e){
            {
                try {
                    FileOutputStream fileOut =
                            new FileOutputStream("src/Daniel/zapis.dat");
                    ObjectOutputStream out = new ObjectOutputStream(fileOut);
                    out.writeObject(Plansza.this);
                    out.close();
                    fileOut.close();
                    System.out.printf("Serialized data is saved in zapis.ser");
                } catch (IOException ne) {
                    System.out.printf("nie udalo sie zapisac");
                }
            }
        }
    }
    
    class odczytywanie implements ActionListener{
        public void actionPerformed(ActionEvent e){
            try
            {
                FileInputStream fileIn = new FileInputStream("zapis.ser");
                ObjectInputStream in = new ObjectInputStream(fileIn);
                Plansza f = (Plansza) in.readObject();
                f.setVisible(true);
                in.close();
                fileIn.close();
            }catch(IOException i)
            {
                return;
            }catch(ClassNotFoundException c)
            {
                System.out.println("nie znaleziono zapisu");
                return;
            }
        }
    }
   
void setPlansza(){
    tab[1][1].setLabel("" + 1);
    tab[1][1].setEnabled(false);
    tab[1][1].setBackground(Color.DARK_GRAY);
    tab[1][3].setLabel("" + 2);
    tab[1][3].setEnabled(false);
    tab[1][3].setBackground(Color.DARK_GRAY);
    tab[1][5].setLabel(""+2);
    tab[1][5].setEnabled(false);
    tab[1][5].setBackground(Color.DARK_GRAY);
    tab[1][7].setLabel(""+1);
    tab[1][7].setEnabled(false);
    tab[1][7].setBackground(Color.DARK_GRAY);
    tab[3][1].setLabel(""+1);
    tab[3][1].setEnabled(false);
    tab[3][1].setBackground(Color.DARK_GRAY);
    tab[3][3].setLabel("" + 2);
    tab[3][3].setEnabled(false);
    tab[3][3].setBackground(Color.DARK_GRAY);
    tab[3][5].setLabel("" + 3);
    tab[3][5].setEnabled(false);
    tab[3][5].setBackground(Color.DARK_GRAY);
    tab[3][7].setLabel("" + 3);
    tab[3][7].setEnabled(false);
    tab[3][7].setBackground(Color.DARK_GRAY);
    tab[5][1].setLabel("" + 2);
    tab[5][1].setEnabled(false);
    tab[5][1].setBackground(Color.DARK_GRAY);
    tab[5][3].setLabel("" +3);
    tab[5][3].setEnabled(false);
    tab[5][3].setBackground(Color.DARK_GRAY);
    tab[5][5].setLabel("" + 2);
    tab[5][5].setEnabled(false);
    tab[5][5].setBackground(Color.DARK_GRAY);
    tab[5][7].setLabel("" + 3);
    tab[5][7].setEnabled(false);
    tab[5][7].setBackground(Color.DARK_GRAY);
    tab[7][1].setLabel("" + 1);
    tab[7][1].setEnabled(false);
    tab[7][1].setBackground(Color.DARK_GRAY);
    tab[7][3].setLabel("" + 3);
    tab[7][3].setEnabled(false);
    tab[7][3].setBackground(Color.DARK_GRAY);
    tab[7][5].setLabel("" + 2);
    tab[7][5].setEnabled(false);
    tab[7][5].setBackground(Color.DARK_GRAY);
    tab[7][7].setLabel("" + 1);
    tab[7][7].setEnabled(false);
    tab[7][7].setBackground(Color.DARK_GRAY);
    tab[2][2].setEnabled(false);
    tab[2][4].setEnabled(false);
    tab[2][6].setEnabled(false);
    tab[4][2].setEnabled(false);
    tab[4][4].setEnabled(false);
    tab[4][6].setEnabled(false);
    tab[6][2].setEnabled(false);
    tab[6][4].setEnabled(false);
    tab[6][6].setEnabled(false);
    }
}

