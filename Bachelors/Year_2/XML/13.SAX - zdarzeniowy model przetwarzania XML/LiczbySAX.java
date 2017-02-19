/*
 * Created on 2004-11-29
 */
import java.io.IOException;
 
import javax.xml.parsers.FactoryConfigurationError;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
 
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
 
public class LiczbySAX {
  public static void main(String[] args) {
    if(args.length < 1) {
      System.out.println("Za malo parametrow");
      return;
    }
 
    try {
      SAXParserFactory factory = SAXParserFactory.newInstance();
      factory.setValidating(true);
      SAXParser parser = factory.newSAXParser();
     
      LiczbyHandler handler = new LiczbyHandler();
      LiczbyHandler2 handler2 = new LiczbyHandler2();
      parser.parse(args[0], handler);
      parser.parse(args[0], handler2);
 
      System.out.println("I Miejsce Kobiety: " +handler.getNazw());
      System.out.println("I Miejsce Mezczyzni: " +handler2.getNazw());
    } catch (FactoryConfigurationError e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    } catch (SAXException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    } catch (ParserConfigurationException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    } catch (IOException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
  }
 
  private static class LiczbyHandler extends DefaultHandler {
        enum Stan {ZEWN, ZAWODNIK, LICZBA, NAZW, WART};
 
    private int fWynik;
    private String nazw1 = "";
    private int ftest = 0;
    private Stan fStan = Stan.ZEWN;
    private Stan sStan = Stan.NAZW;
    private StringBuffer fBuf;
    private StringBuffer fBuf2;
   
    public int getResult() {
      return fWynik;
    }
   
    public String getNazw() {
        return nazw1;
    }
   
    public void startElement(String uri, String localName, String qName,
        Attributes attributes) throws SAXException {
      if("zawodnik".equals(qName)) {
        String attrVal = attributes.getValue("plec");
        if("k".equals(attrVal))
          fStan = Stan.ZAWODNIK;
          sStan = Stan.NAZW;
      }
      else { if("wynik".equals(qName)) {
        if(fStan == Stan.ZAWODNIK) {
          fStan = Stan.LICZBA;
          fBuf = new StringBuffer();
        }
      }
       else if("nazwisko".equals(qName)) {
          if(sStan == Stan.NAZW) {
                sStan = Stan.WART;
                fBuf2 = new StringBuffer();
        }
      }
      }
    }
   
    public void endElement(String uri, String localName, String qName)
    throws SAXException {
      if("zawodnik".equals(qName)) {
        if(fStan == Stan.ZAWODNIK) {
          fStan = Stan.ZEWN;
        }
      } else if("wynik".equals(qName)) {
        if(fStan == Stan.LICZBA) {
          fStan = Stan.ZAWODNIK;
          sStan = Stan.NAZW;
          try {
            ftest = Integer.parseInt(fBuf.toString());          
            if(ftest>fWynik) {
                fWynik=ftest;
                nazw1=fBuf2.toString();
            }
          } catch (NumberFormatException e) {
          }
        }
      }
    }
    public void characters(char[] ch, int start, int length)
        throws SAXException {
      if(fStan == Stan.LICZBA)
        fBuf.append(ch, start, length);
      if(sStan == Stan.WART)
          fBuf2.append(ch, start, length);
    }
  }
 
  private static class LiczbyHandler2 extends DefaultHandler {
                enum Stan {ZEWN, ZAWODNIK, LICZBA, NAZW, WART};
 
            private int fWynik;
            private String nazw1 = "";
            private int ftest = 0;
            private Stan fStan = Stan.ZEWN;
            private Stan sStan = Stan.NAZW;
            private StringBuffer fBuf;
            private StringBuffer fBuf2;
           
            public int getResult() {
              return fWynik;
            }
           
            public String getNazw() {
                return nazw1;
            }
           
            public void startElement(String uri, String localName, String qName,
                Attributes attributes) throws SAXException {
              if("zawodnik".equals(qName)) {
                String attrVal = attributes.getValue("plec");
                if("m".equals(attrVal))
                  fStan = Stan.ZAWODNIK;
                  sStan = Stan.NAZW;
              }
              else { if("wynik".equals(qName)) {
                if(fStan == Stan.ZAWODNIK) {
                  fStan = Stan.LICZBA;
                  fBuf = new StringBuffer();
                }
              }
               else if("nazwisko".equals(qName)) {
                  if(sStan == Stan.NAZW) {
                        sStan = Stan.WART;
                        fBuf2 = new StringBuffer();
                }
              }
              }
            }
           
            public void endElement(String uri, String localName, String qName)
            throws SAXException {
              if("zawodnik".equals(qName)) {
                if(fStan == Stan.ZAWODNIK) {
                  fStan = Stan.ZEWN;
                }
              } else if("wynik".equals(qName)) {
                if(fStan == Stan.LICZBA) {
                  fStan = Stan.ZAWODNIK;
                  sStan = Stan.NAZW;
                  try {
                    ftest = Integer.parseInt(fBuf.toString());          
                    if(ftest>fWynik) {
                        fWynik=ftest;
                        nazw1=fBuf2.toString();
                    }
                  } catch (NumberFormatException e) {
                  }
                }
              }
            }
            public void characters(char[] ch, int start, int length)
                throws SAXException {
              if(fStan == Stan.LICZBA)
                fBuf.append(ch, start, length);
              if(sStan == Stan.WART)
                  fBuf2.append(ch, start, length);
            }
          }
}
