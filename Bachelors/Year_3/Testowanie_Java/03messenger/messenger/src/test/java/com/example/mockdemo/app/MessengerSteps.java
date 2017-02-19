package com.example.mockdemo.app;

import static org.hamcrest.CoreMatchers.anyOf;
import static org.hamcrest.CoreMatchers.equalTo;
import static org.hamcrest.Matchers.*;
import static org.junit.Assert.*;

import org.jbehave.core.annotations.Given;
import org.jbehave.core.annotations.Then;
import org.jbehave.core.annotations.When;

import com.example.mockdemo.messenger.MessageServiceSimpleImpl;

public class MessengerSteps {

	private Messenger messenger;
	private String server;
	private String message;
	
	@Given("a messenger")
	public void messengerSetup(){
		messenger = new Messenger(new MessageServiceSimpleImpl());
	}
	
	@When("received $serv and $mes")
	public void setArguments(String serv, String mes){
		server = serv;
		message = mes;
	}
	
	@Then("sendMessage should return $result")
	public void shouldReturn(int result){
		assertEquals(result, messenger.sendMessage(server, message));
	}
	
    @SuppressWarnings("unchecked")
	@Then("correct sendMessage should return $result1 or $result2")
	public void shouldReturn(int result1, int result2){
		assertThat(messenger.sendMessage(server, message), either(is(result1)).or(is(result2)));
	}
}
