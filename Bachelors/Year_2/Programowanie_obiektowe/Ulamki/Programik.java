package ulamkilab;

class Programik
{
	public static void main(String[] args)
	{
		LiczbaUD x = new LiczbaUD(2,3,4);
		LiczbaUD y = new LiczbaUD(4,1,5);

		System.out.println("X : " + x.toString());
		System.out.println("Y : " + y.toString());

		Ulamek w = new Ulamek( 3,4 );
		
		System.out.println("W : " + w.toString());
		
		x.mnozPrzez(w);
		System.out.println("X * W : " + x.toString() );
		
		
	}
}