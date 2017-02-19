package com.dokoniewski.junit;

import static org.junit.Assert.*;

import org.junit.Test;

public class CalculatorTest {

private Calculator calc = new Calculator();
	
	@Test
	public void testAdd() {
		assertEquals(1, calc.add(3, -2));
	}
	
	@Test
	public void testSubstract() {
		assertEquals(4, calc.substract(2, -2));
	}
	
	@Test
	public void testMultiply() {
		assertEquals(8, calc.multiply(-2, -4));
		assertEquals(-8, calc.multiply(-2, 4));
	}
	
	@Test
	public void testDivide() {
		assertEquals(2, calc.divide(-6, -3));
		assertEquals(-2, calc.divide(-6, 3));
	}
	
	@Test
	public void testGreater() {
		assertEquals(false, calc.greater(-6, -3));
		assertEquals(true, calc.greater(3, 2));
	}
	
	@Test(expected = ArithmeticException.class)
	public void testDivException(){
		calc.divide(2, 0);
	}

}
