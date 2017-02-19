package com.dokoniewski.junit;

public class Calculator {
	public int add(int a ,int b){
		return a + b;
	}

	public int substract(int a ,int b){
		return a - b;
	}
	
	public int multiply(int a ,int b){
		return a*b;
	}
	
	public int divide(int a ,int b){
		return a/b;
	}
	
	boolean greater(int a, int b){
		if(a>b)
			return true;
		else
			return false;
	}
}
