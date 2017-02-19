import java.util.zip.*;
import java.io.*;

class Gzip{
    public static void main(String[] args) throws IOException{
        BufferedInputStream wej = new BufferedInputStream(
               			   new FileInputStream("Gzip.java"));
	BufferedOutputStream wy = new BufferedOutputStream(
               			   new GZIPOutputStream(
	       			    new FileOutputStream("Gzip.java.gz")));
	int c;
	while ((c = wej.read())!= -1)
	    wy.write(c);
	wej.close();
	wy.close();
    }
}