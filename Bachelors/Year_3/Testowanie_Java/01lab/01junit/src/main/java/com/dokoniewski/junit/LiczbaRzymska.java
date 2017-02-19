package com.dokoniewski.junit;

public class LiczbaRzymska {
private int liczba;
	
	LiczbaRzymska(int a){
		liczba = a;
	}

	@Override
	public String toString() {
		String roman = "";
		if(liczba>0 && liczba<=10){
			while (liczba >= 10) {
				roman += "X";
				liczba -= 10;
			}
			while (liczba >= 9) {
				roman += "IX";
				liczba -= 9;
			}
			while (liczba >= 5) {
				roman += "V";
				liczba -= 5;
			}
			while (liczba >= 4) {
				roman += "IV";
				liczba -= 4;
			}
			while (liczba >= 1) {
				roman += "I";
				liczba -= 1;
			}
		} else{
			roman = "Niepoprawna liczba";
		}
		return roman;
	}
}
