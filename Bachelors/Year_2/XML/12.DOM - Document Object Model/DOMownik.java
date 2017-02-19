import org.w3c.dom.*;
import org.w3c.dom.bootstrap.DOMImplementationRegistry;
import org.w3c.dom.ls.DOMImplementationLS;
import org.w3c.dom.ls.LSOutput;
import org.w3c.dom.ls.LSParser;
import org.w3c.dom.ls.LSSerializer;
import java.io.FileOutputStream;
import org.w3c.dom.DOMConfiguration;
import org.w3c.dom.DOMError;
import org.w3c.dom.DOMErrorHandler;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
 
 
public class DOMownik
{
 
        public static void main(String[] args) {
 
 
            DOMImplementation domImpl =
                    new org.apache.xerces.dom.DOMImplementationImpl();
            Document nowyDOM = domImpl.createDocument("null", "autor", null);
            Element korzen = nowyDOM.getDocumentElement();
 
            Element imieElement = nowyDOM.createElement("imie");
            Element nazwiskoElement = nowyDOM.createElement("nazwisko");
            Text imieText = nowyDOM.createTextNode("Anna");
            Text nazwiskoText = nowyDOM.createTextNode("Nowicka");
            imieElement.appendChild(imieText);
            nazwiskoElement.appendChild(nazwiskoText);
            korzen.appendChild(imieElement);
            korzen.appendChild(nazwiskoElement);
 
            try {
                        /*
                         * ustawienie systemowej wlasnosci (moze byc dokonane w innym
                         * miejscu, pliku konfiguracyjnym w systemie itp.) konkretna
                         * implementacja DOM
                         */
                System.setProperty(DOMImplementationRegistry.PROPERTY,
                        "org.apache.xerces.dom.DOMXSImplementationSourceImpl");
                DOMImplementationRegistry registry = DOMImplementationRegistry
                        .newInstance();
 
                // pozyskanie implementacji Load & Save DOM Level 3 z rejestru
                DOMImplementationLS impl = (DOMImplementationLS) registry
                        .getDOMImplementation("LS");
 
                // stworzenie DOMBuilder
                LSParser builder = impl.createLSParser(
                        DOMImplementationLS.MODE_SYNCHRONOUS, null);
 
                // pozyskanie konfiguratora - koniecznie zajrzec do dokumentacji co
                // mozna poustawiac
                DOMConfiguration config = builder.getDomConfig();
 
                // stworzenie DOMErrorHandler i zarejestrowanie w konfiguratorze
                DOMErrorHandler errorHandler = getErrorHandler();
                config.setParameter("error-handler", errorHandler);
 
                // set validation feature
                config.setParameter("validate", Boolean.TRUE);
 
                // pozyskanie serializatora
                LSSerializer domWriter = impl.createLSSerializer();
                // pobranie konfiguratora dla serializatora
                config = domWriter.getDomConfig();
                config.setParameter("xml-declaration", Boolean.TRUE);
 
                // pozyskanie i konfiguracja Wyjscia
                LSOutput dOut = impl.createLSOutput();
                dOut.setEncoding("latin2");
                dOut.setByteStream(new FileOutputStream("osoba.xml"));
 
                System.out.println("Serializing document... ");
                domWriter.write(nowyDOM, dOut);
 
                // Wyjscie na ekran
                // dOut.setByteStream(System.out);
                // domWriter.writeNode(System.out, document);
 
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
 
        private static void printUsage() {
 
            System.err.println("usage: java Dom3Demo uri");
            System.err.println();
            System.err
                    .println("NOTE: You can only validate DOM tree against XML Schemas.");
 
        }
 
        // obsluga bledow za pomoca anonimowej klasy wewnetrznej implementujacej
        // DOMErrorHandler
        // por. SAX ErrorHandler
        public static DOMErrorHandler getErrorHandler() {
            return new DOMErrorHandler() {
                public boolean handleError(DOMError error) {
                    short severity = error.getSeverity();
                    if (severity == error.SEVERITY_ERROR) {
                        System.out.println("[dom3-error]: " + error.getMessage());
                    }
                    if (severity == error.SEVERITY_WARNING) {
                        System.out.println("[dom3-warning]: " + error.getMessage());
                    }
                    if (severity == error.SEVERITY_FATAL_ERROR) {
                        System.out.println("[dom3-fatal-error]: "
                                + error.getMessage());
                    }
                    return true;
                }
            };
        }
 
}
