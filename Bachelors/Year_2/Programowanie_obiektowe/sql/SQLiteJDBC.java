import java.sql.*;
public class SQLiteJDBC


{
	
	
    public static void main( String args[] )
    {
	Connection c = null;
	Statement stmt = null;
	try {
	    Class.forName("org.sqlite.JDBC");
	    c = DriverManager.getConnection("jdbc:sqlite:main");
	    c.setAutoCommit(true);
	    System.out.println("Opened database successfully");
	    int dlugosc=0;
	    int max = 0;
	    stmt = c.createStatement();
//	    String sql = "UPDATE Pracownik set pensja=pensja*1.1 where rocznik >1990;";
//	    stmt.executeUpdate(sql);
	    ResultSet rs = stmt.executeQuery( "SELECT * FROM pracownik;" );
	    while ( rs.next() ) {
		String  imie = rs.getString("imie");
		int pensja  = rs.getInt("pensja");
                System.out.println(pensja);
		if(imie.length()>dlugosc){
			max=pensja;
		}
	    }
	System.out.println(max);

	    rs.close();
	    stmt.close();
	    c.close();
	} catch ( Exception e ) {
	    System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	    System.exit(0);
	}
	System.out.println("Operation done successfully");
    }
}