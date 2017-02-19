package com.example.mockdemo.app;

import static org.easymock.EasyMock.createMock;
import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.replay;
import static org.easymock.EasyMock.verify;
import static org.hamcrest.CoreMatchers.anyOf;
import static org.hamcrest.CoreMatchers.equalTo;
import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import com.example.mockdemo.messenger.ConnectionStatus;
import com.example.mockdemo.messenger.MalformedRecipientException;
import com.example.mockdemo.messenger.MessageService;
import com.example.mockdemo.messenger.SendingStatus;


public class EasyMockAppTest {

	private Messenger messenger;
	private MessageService mock;
	
	private static final String VALID_SERVER = "inf.ug.edu.pl";
	private static final String INVALID_SERVER = "inf.ug.edu.eu";

	private static final String VALID_MESSAGE = "some message";
	private static final String INVALID_MESSAGE = "ab";
	
	@Before
	public void setUp() {
		mock = createMock(MessageService.class);
		messenger = new Messenger(mock);
	}
	
	@Test
	public void testInvalidConnection(){
		expect(mock.checkConnection(INVALID_SERVER)).andReturn(ConnectionStatus.FAILURE);
		replay(mock);
		assertEquals(1, messenger.testConnection(INVALID_SERVER));
		verify(mock);
	}
	
	@Test
	public void testValidConnection(){
		expect(mock.checkConnection(VALID_SERVER)).andReturn(ConnectionStatus.SUCCESS);
		replay(mock);
		assertEquals(0, messenger.testConnection(VALID_SERVER));
		verify(mock);
	}
	
	@Test
	public void testSendInvalidServer() throws MalformedRecipientException{
		expect(mock.send(INVALID_SERVER, VALID_MESSAGE)).andReturn(SendingStatus.SENDING_ERROR);
		replay(mock);
		assertEquals(1, messenger.sendMessage(INVALID_SERVER, VALID_MESSAGE));
		verify(mock);
	}
	
	@Test
	public void testSendInvalidMessage() throws MalformedRecipientException{
			expect(mock.send(VALID_SERVER, INVALID_MESSAGE)).andThrow(new MalformedRecipientException());
			replay(mock);
			assertEquals(2, messenger.sendMessage(VALID_SERVER, INVALID_MESSAGE));
			verify(mock);
		}
	
	@SuppressWarnings("unchecked")
	@Test
	public void testSendAllValid() throws MalformedRecipientException{
			expect(mock.send(VALID_SERVER, VALID_MESSAGE)).andReturn(SendingStatus.SENT);
			replay(mock);
			assertThat(messenger.sendMessage(VALID_SERVER, VALID_MESSAGE), anyOf(equalTo(0), equalTo(1)));
			verify(mock);
		}

}
