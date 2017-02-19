package com.dokoniewski.junit;

import static org.junit.Assert.*;

import org.junit.Test;

public class LiczbaRzymskaTest {

	private LiczbaRzymska roman = new LiczbaRzymska(8);
	private LiczbaRzymska roman2 = new LiczbaRzymska(4);
	private LiczbaRzymska romanTooBig = new LiczbaRzymska(15);
	private LiczbaRzymska romanNegative = new LiczbaRzymska(-2);
	
	@Test
	public void testToStringProper() {
		assertEquals("VIII", roman.toString());
		assertEquals("IV", roman2.toString());
	}
	
	@Test
	public void testTooBigNumber() {
		assertEquals("Niepoprawna liczba", romanTooBig.toString());
	}
	
	@Test
	public void testNegativeNumber() {
		assertEquals("Niepoprawna liczba", romanNegative.toString());
	}
}
