import java.util.zip.*;
import java.io.*;

class Gunzip {
    public static void main(String[] args) throws IOException{
        BufferedInputStream wej = new BufferedInputStream(
               			   new GZIPInputStream(new FileInputStream("Gzip.java.gz")));
	BufferedOutputStream wy = new BufferedOutputStream(
               			   
	       			    new FileOutputStream("Gzip.java"));
	int c;
	while ((c = wej.read())!= -1)
	    wy.write(c);
	wej.close();
	wy.close();
    }
}