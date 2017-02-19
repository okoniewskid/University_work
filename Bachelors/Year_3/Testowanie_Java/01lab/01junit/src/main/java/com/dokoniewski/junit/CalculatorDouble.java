package com.dokoniewski.junit;

public class CalculatorDouble {
	public double add(double a ,double b){
		return a + b;
	}

	public double substract(double a ,double b){
		return a - b;
	}
	
	public double multiply(double a ,double b){
		return a*b;
	}
	
	public double divide(double a ,double b){
		return a/b;
	}
	
	boolean greater(double a, double b){
		if(a>b)
			return true;
		else
			return false;
	}
}
