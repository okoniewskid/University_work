package com.example.mockdemo.app;

import static org.mockito.Mockito.*;
import static org.junit.Assert.*;

import org.mockito.Mock;
import org.junit.Before;
import org.junit.Test;
import org.mockito.MockitoAnnotations;

import com.example.mockdemo.messenger.ConnectionStatus;
import com.example.mockdemo.messenger.MalformedRecipientException;
import com.example.mockdemo.messenger.MessageService;
import com.example.mockdemo.messenger.SendingStatus;

public class MockitoAppTest {

	private static final String VALID_SERVER = "inf.ug.edu.pl";
	private static final String INVALID_SERVER = "inf.ug.edu.eu";

	private static final String VALID_MESSAGE = "some message";
	private static final String INVALID_MESSAGE = "ab";
	
	@Mock MessageService mock;
	private Messenger messenger;
	
	@Before 
	public void setUp() { 
		MockitoAnnotations.initMocks(this);
		messenger = new Messenger(mock); 
	}
	
	@Test
	public void testConnectionValidServer() {
		when(mock.checkConnection(VALID_SERVER)).thenReturn(ConnectionStatus.SUCCESS);
		assertEquals(0, messenger.testConnection(VALID_SERVER));
		verify(mock).checkConnection(VALID_SERVER);
	}
	
	@Test
	public void testConnectionInvalidServer() {
		when(mock.checkConnection(INVALID_SERVER)).thenReturn(ConnectionStatus.FAILURE);
		assertEquals(1, messenger.testConnection(INVALID_SERVER));
		verify(mock).checkConnection(INVALID_SERVER);
	}

	@Test
	public void testSendInvalidServer() throws MalformedRecipientException {
		when(mock.send(INVALID_SERVER, VALID_MESSAGE)).thenReturn(SendingStatus.SENDING_ERROR);
		assertEquals(1, messenger.sendMessage(INVALID_SERVER, VALID_MESSAGE));
		verify(mock).send(INVALID_SERVER, VALID_MESSAGE);
	}
	
	@Test
	public void testSendInvalidMessage() throws MalformedRecipientException {
		when(mock.send(VALID_SERVER, INVALID_MESSAGE)).thenThrow(new MalformedRecipientException());
		assertEquals(2, messenger.sendMessage(VALID_SERVER, INVALID_MESSAGE));
		verify(mock).send(VALID_SERVER, INVALID_MESSAGE);
	}
	
	@Test
	public void testSendAllValid() throws MalformedRecipientException {
		when(mock.send(VALID_SERVER, VALID_MESSAGE)).thenReturn(SendingStatus.SENT);
		assertEquals(0, messenger.sendMessage(VALID_SERVER, VALID_MESSAGE));
		verify(mock).send(VALID_SERVER, VALID_MESSAGE);
	}
}
