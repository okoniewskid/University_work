import java.util.*;

class Porownaj implements Comparator<Uczen> {
	@Override
	public int compare(Uczen u1, Uczen u2) {
		int i;
		double max1 = 0;
		for (i=0;i<u1.oceny.size();i++) {
			if (u1.oceny.get(i) > max1) max1 = u1.oceny.get(i);
		}
		int max2 = 0;
		for (i=0;i<u2.oceny.size();i++) {
			if (u2.oceny.get(i) > max2) max2 = u2.oceny.get(i);
		}
		if (max1 >= max2) return -1;
		else return 1;
	}
	
}

class WykazU
{
	private final ArrayList<Uczen> wykaz;

	WykazU()
	{
		wykaz = new ArrayList<>();
	}

	public void wstawUcznia( int id, String imie )
	{
		wykaz.add( new Uczen( id , imie ) );
	}

	public void wstawOcene( int id, int ocena)
	{
		Uczen toAdd = getUczen( id);
		//( toAdd != null ) ? toAdd.addMark( ocena ) : null;
		if( toAdd != null ){ toAdd.addMark( ocena ); }
	}

	public void wypisz( int id)
	{
		Uczen toPrint = getUczen( id );
		toPrint.printOceny();
	}

	public void wypisz()
	{
		System.out.println( "OCENY WSZYSTKICH" );
		Uczen currentUczen;
            for (Uczen wykaz1 : wykaz) {
                currentUczen = wykaz1;
                currentUczen.printOceny();
                System.out.println();
            }
	}
       
	public Uczen getUczen( int id)
	{
		Uczen correctUczen;
            for (Uczen wykaz1 : wykaz) {
                correctUczen = wykaz1;
                if( correctUczen.getID() == id )
                {
                    return correctUczen;
                }
            }
		return null;
	}
        
        
        
        public void sortujA() {
		Collections.sort(wykaz);
	}
	
	public void sortujM() {
		Collections.sort(wykaz, new Porownaj());
	}

}

class TestWykaz
{
	public static void main( String[] args )
	{
		WykazU wykaz = new WykazU();
		wykaz.wstawUcznia( 194922, "Marcin Putin" );
		wykaz.wstawOcene( 194922, 2);
		wykaz.wstawOcene( 194922, 3);
		wykaz.wstawUcznia( 193333, "Wojtek Obama" );
		wykaz.wstawOcene( 193333, 4 );
                wykaz.wstawOcene( 193333, 2 );
                wykaz.wstawOcene( 193333, 3 );
                wykaz.wstawUcznia( 193334, "Spiderman" );
		wykaz.wstawOcene( 193334, 1 );
                wykaz.wstawOcene( 193334, 2 );
                wykaz.wstawUcznia( 193335, "Piotrus Pan" );
		wykaz.wstawOcene( 193335, 6 );
                wykaz.wstawOcene( 193335, 5 );
                wykaz.wstawUcznia( 193336, "Ziom Ziomalski" );
		wykaz.wstawOcene( 193336, 4 );
                wykaz.wstawOcene( 193336, 3 );
                wykaz.wstawOcene( 193336, 3 );
		//wykaz.wypisz( 194922);
		System.out.println();
		//wykaz.wypisz();
                    wykaz.sortujA();
                    wykaz.wypisz();
                        wykaz.sortujM();
                        wykaz.wypisz();
	}
}
