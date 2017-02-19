package com.dokoniewski.wejsciowka;

import static org.junit.Assert.*;

import org.junit.Test;

public class BookManagerTest {
	BookManager bookManager = new BookManager();
	private final static String AUTHOR = "autor";
	private final static String AUTHOR2 = "autor2";
	private final static String TITLE = "tytuł";
	private final static String TITLE2 = "tytuł2";
	private final static int ISBN = 1234;
	private final static int ISBN2 = 1235;
	
	@Test
	public void testAdd() {
		Book book = new Book(AUTHOR, TITLE, ISBN);
		
		bookManager.addBook(book);
		
		assertEquals(1, bookManager.books.size());
		assertEquals(book, bookManager.books.get(0));
	}
	
	@Test
	public void testDelete(){
		Book book = new Book(AUTHOR, TITLE, ISBN);
		Book book2 = new Book(AUTHOR2, TITLE2, ISBN2);
		
		bookManager.addBook(book);
		bookManager.addBook(book2);
		bookManager.deleteBook(book);
		
		assertEquals(1, bookManager.books.size());
	}

}
