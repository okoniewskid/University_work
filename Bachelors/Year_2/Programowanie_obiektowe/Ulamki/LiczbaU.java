package ulamkilab;

class LiczbaU
{
	private int calosci;
	private Ulamek czescUlamkowa;

	LiczbaU( int c , Ulamek u )
	{
		calosci = c;
		czescUlamkowa = u;
		checkCzescUlamkowa();
	}
	
	void mnozPrzez( LiczbaU l )
	{

	}
	
	void mnozPrzez( int i )
	{
		czescUlamkowa.setLicznik( czescUlamkowa.getLicznik() * i );
		checkCzescUlamkowa();
	}
	
	void mnozPrzez( Ulamek u )
	{
		czescUlamkowa.mnozPrzez( u );
		checkCzescUlamkowa();
	}
	
	private void checkCzescUlamkowa()
	{
		if( czescUlamkowa.getLicznik() >= czescUlamkowa.getMianownik() )
		{
			int calosci = czescUlamkowa.getLicznik() / czescUlamkowa.getMianownik();
			czescUlamkowa.setLicznik( czescUlamkowa.getLicznik() - ( czescUlamkowa.getMianownik() * calosci ) );
		}
	}
	
	private Ulamek convertToUlamek()
	{
		return new Ulamek( czescUlamkowa.getLicznik() + ( czescUlamkowa.getMianownik() * calosci ) , czescUlamkowa.getMianownik() );
	}
	
	
	
	
	int getCalosci(){ return calosci; }
	void setCalosci( int cal ){ calosci = cal; }
	Ulamek getCzescUlamkowa(){ return czescUlamkowa; }
	void setCzescUlamkowa( Ulamek ux ){ czescUlamkowa = ux; }
	
	
}