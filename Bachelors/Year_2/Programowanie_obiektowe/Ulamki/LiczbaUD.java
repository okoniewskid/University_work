package ulamkilab;

class LiczbaUD extends Ulamek
{
	private int calosci;
	
	LiczbaUD( int c, int l, int m )
	{
		super( l, m );
		calosci = c;
		
		fixLicznik();
	}
	
        @Override
	void mnozPrzez( int n ) 
	{
		licznik *= n;
		fixLicznik();
	}
    
        @Override
	void mnozPrzez( Ulamek u )
	{
		Ulamek wynik = Ulamek.razy( u , new Ulamek( licznik + ( calosci * mianownik ) , mianownik ) );
		ulamekToThis( wynik );
		fixLicznik();
	}
    
	void mnozPrzez( LiczbaU l )
	{
		// Przesloniete
	}
	
	private void ulamekToThis( Ulamek u1 )
	{
		calosci = u1.getLicznik() / u1.getMianownik();
		licznik = u1.getLicznik() - ( u1.getMianownik() * calosci );
		mianownik = u1.getMianownik();
	}
	
	private void fixLicznik()
	{
		if( licznik >= mianownik )
		{
			calosci = calosci + ( licznik / mianownik );
			licznik = licznik % mianownik;
		}
	}
	
        @Override
	public String toString()
	{
		return calosci + " " + licznik + "/" + mianownik;
	}


}