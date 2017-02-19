package Daniel;

class Historia {
    public int x,y,value;
    public int val,valPrev;

    Historia() {
        
    }

    Historia(int a, int b,int d,int c){
        x=a;
        y=b;
        value=d;
        val=c;
   }
    
   public void setHistory(int a, int b, int c,int d){
        x=a;
        y=b;
        valPrev=c;
        value=d;
    }
}
