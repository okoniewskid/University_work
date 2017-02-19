package com.dokoniewski.wejsciowka;

import static org.easymock.EasyMock.createMock;
import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.replay;
import static org.easymock.EasyMock.verify;
import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

public class EasyMockTest {

	private static final int ISBN = 1234;
	private static final int ISBN2 = 4321;
	private static final String TITLE = "Hamlet";
	private static final String TITLE2 = "Król Lear";
	private static final String AUTHOR = "Shakespeare";
	
	private BookManager bookManager;
	private IMyList mock;
	private Book book = new Book(AUTHOR, TITLE, ISBN);
	private Book book2 = new Book(AUTHOR, TITLE2, ISBN2);
	private List<Book> books = new ArrayList<Book>();
	
	@Before
	public void setUp() {
		mock = createMock(IMyList.class);
		bookManager = new BookManager(mock);
	}

	@Test
	public void checkAdding() {
		expect(mock.addBook(book)).andReturn(true).atLeastOnce();
		replay(mock);
		assertTrue(bookManager.addBook(book));
		verify(mock);
	}
	
	@Test
	public void checkRemove() {
		expect(mock.deleteBook(book)).andReturn(true).atLeastOnce();
		replay(mock);
		assertTrue(bookManager.deleteBook(book));
		verify(mock);
	}

	@Test
	public void checkGetAll() {
		books.add(book);
		books.add(book2);
		expect(mock.getAll()).andReturn(books);
		replay(mock);
		assertEquals(books, bookManager.getAllBooks());
		verify(mock);
	}
	
	@Test
	public void checkGetByTitle() {
		expect(mock.getByTitle(TITLE)).andReturn(book);
		replay(mock);
		assertEquals(book, bookManager.getByTitle(TITLE));
		verify(mock);
	}
	
	@Test
	public void checkGetByISBN() {
		expect(mock.getByISBN(ISBN)).andReturn(book);
		replay(mock);
		assertEquals(book, bookManager.getByISBN(ISBN));
		verify(mock);
	}
}
