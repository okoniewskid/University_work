package ulamkilab;

class Ulamek
{
	int licznik;
	int mianownik;
	
	static Ulamek razy( Ulamek u1, Ulamek u2 ){ return new Ulamek( u1.licznik*u2.licznik , u1.mianownik*u2.mianownik ); }

        @Override
	public String toString()
	{
		return licznik + "/" + mianownik;
	}
	
	void mnozPrzez( Ulamek u1 )
        { licznik *= u1.licznik; mianownik *= u1.mianownik; }
	void mnozPrzez( int l1 )
        { licznik *= l1; }
	Ulamek( int l , int m )
        { licznik = l; mianownik = m; }

	int getLicznik()
        { return licznik; }
	void setLicznik( int licz )
        { licznik = licz; }
	int getMianownik()
        { return mianownik; }
	void setMianownik( int mian )
        { mianownik = mian; }
}