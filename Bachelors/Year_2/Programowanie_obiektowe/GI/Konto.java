import java.util.ArrayList;
class DebetException extends Exception {}
class CancelException extends Exception {}

class Konto{
	private int stan;
	private ArrayList<Integer>operacje;
	Konto() { stan = 0; operacje = new ArrayList<Integer>(); }
	public void operacja(int ile) throws DebetException {
		if (stan + ile >= 0 ) {
			stan += ile;
			operacje.add(ile);
		} else throw new DebetException();
	}

	public int dajStan() { return stan ; }
	public void anuluj() throws CancelException {
		if (operacje.size() > 0) {
			stan -= operacje.get(operacje.size()-1);
			operacje.remove(operacje.size()-1);
		} else throw new CancelException();
	}
}