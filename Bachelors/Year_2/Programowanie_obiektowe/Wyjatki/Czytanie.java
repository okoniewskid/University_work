import java.io.* ;
import java.util.* ;
class mojWyjatek extends Exception{}

class Czytanie{
   static BufferedReader sysin =
           new BufferedReader(new InputStreamReader(System.in));

   String czytajNP() throws IOException, mojWyjatek{
   //  pyta o  nazwe pliku
      System.out.print("podaj nazwe pliku ");
      String linia;
      linia = sysin.readLine() ;
      if(linia.equals("")) throw new mojWyjatek();
      return linia.trim();
   }

  void czytaj(ArrayList<Double> a) throws IOException, mojWyjatek{
  // czytanie z pliku
    int nr=1 ;                  // numer wiersza
    String nazwa = czytajNP();
       try (BufferedReader br = new BufferedReader(new FileReader(nazwa))) {
           String wiersz;
           while ((wiersz = br.readLine()) != null){
               a.add(new Double(wiersz));
               nr++;
           }  }
  }

}
class Wyjatki{
  static void srednia(ArrayList<Double> a){
      double s=0.0d;
      s = a.stream().map((a1) -> (a1)).reduce(s, (accumulator, _item) -> accumulator + _item);
      System.out.println("srednia z liczb w tablicy: "+s/a.size());
  }
  public static void main(String[] args)throws IOException{
      ArrayList<Double> a = new ArrayList<>();
      Czytanie cz = new Czytanie();
      try{
      cz.czytaj(a);
      srednia(a);
      }catch(mojWyjatek e){
        System.out.print("nazwa pliku pusta");
      }
      
      
      
      
      }
  }

