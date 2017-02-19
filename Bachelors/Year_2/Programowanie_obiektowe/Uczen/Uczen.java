
import java.util.*;

public class Uczen implements Comparable<Uczen>
{
	public int id;
	public String imie;
	public ArrayList<Integer> oceny;

	public Uczen( int id, String imie )
	{
		this.id = id;
		this.imie = imie;
		this.oceny = new ArrayList<>();
	}

	public void addMark( int mark )
	{
		this.oceny.add( mark );
	}
	
	public void printOceny()
	{
		System.out.print( "Oceny Nr. " + this.id + " " + this.imie + " : " );
                oceny.stream().forEach((oceny1) -> {
                    System.out.print(oceny1.toString() + " ");
            });
	}

        @Override
        public boolean equals(Object o) {
		if (!(o instanceof Uczen)) return false;
		Uczen u = (Uczen)o;
            return u.id == id;
	}

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 53 * hash + this.id;
        return hash;
    }

	@Override
	public int compareTo(Uczen u) {
		return this.imie.compareTo(u.imie);
	}
	public int getID(){ return this.id; }
        public String getImie(){return this.imie;}
}