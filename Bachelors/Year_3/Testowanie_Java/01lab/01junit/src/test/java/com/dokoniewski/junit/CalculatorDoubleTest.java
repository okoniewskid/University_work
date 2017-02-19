package com.dokoniewski.junit;

import static org.junit.Assert.*;

import org.junit.Test;

public class CalculatorDoubleTest {

private CalculatorDouble calc = new CalculatorDouble();
	
	@Test
	public void testAdd() {
		assertEquals( 1.08, calc.add(3.20, -2.12), 0);
	}
	
	@Test
	public void testSubstract() {
		assertEquals(4.13, calc.substract(2.12, -2.01), 0);
	}
	
	@Test
	public void testMultiply() {
		assertEquals(7.54, calc.multiply(-2.12, -3.56), 0.01);
		assertEquals(-7.54, calc.multiply(-2.12, 3.56), 0.01);
	}
	
	@Test
	public void testDivide() {
		assertEquals(3.3, calc.divide(-6.6, -2), 0.01);
		assertEquals(-3.3, calc.divide(-6.6, 2), 0.01);
	}
	
	@Test
	public void testGreater() {
		assertEquals(false, calc.greater(-6, -3));
		assertEquals(true, calc.greater(3, 2));
	}
}
