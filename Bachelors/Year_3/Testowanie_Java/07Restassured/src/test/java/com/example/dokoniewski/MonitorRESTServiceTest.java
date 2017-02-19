package com.example.dokoniewski;

import static com.jayway.restassured.RestAssured.delete;
import static com.jayway.restassured.RestAssured.get;
import static com.jayway.restassured.RestAssured.given;
import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.equalToIgnoringCase;
import static org.hamcrest.Matchers.*;
import static org.junit.Assert.assertEquals;

import java.util.ArrayList;

import javax.ws.rs.core.MediaType;

import org.junit.BeforeClass;
import org.junit.Test;

import com.example.dokoniewski.domain.Monitor;
import com.jayway.restassured.RestAssured;

public class MonitorRESTServiceTest {
	
	private static final String MONITOR_BRAND = "BenQ";
	private static final String MONITOR_BRAND2 = "Asus";
	private static final int FULL_HD = 1080;
	private static final int HD = 720;
	
	
	@BeforeClass
    public static void setUp(){
		RestAssured.baseURI = "http://localhost";
		RestAssured.port = 8080;
		RestAssured.basePath = "/projectjava/api";   	
    }
	
	@Test
	public void addMonitors(){		
		
		delete("/monitor/").then().assertThat().statusCode(200);
		
		Monitor monitor = new Monitor(MONITOR_BRAND, FULL_HD);
		
		given().
			contentType(MediaType.APPLICATION_JSON).
			body(monitor).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);
			
		String id = get("/monitor").path("monitor.id");
		
		Monitor rMonitor = given().pathParam("id", id).get("/monitor/{id}").as(Monitor.class);
		
		assertThat(MONITOR_BRAND, equalToIgnoringCase(rMonitor.getBrand()));
		assertEquals(FULL_HD, rMonitor.getPixels());
	}
	
	@Test
	public void deleteMonitor(){
		
		delete("/monitor/").then().assertThat().statusCode(200);
		
		Monitor monitor = new Monitor(MONITOR_BRAND, HD);
		Monitor monitor2 = new Monitor(MONITOR_BRAND2, FULL_HD);
		
		given().
	       contentType(MediaType.APPLICATION_JSON).
	       body(monitor).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);
		
		given().
	       contentType(MediaType.APPLICATION_JSON).
	       body(monitor2).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);
		
	    ArrayList<String> id = get("/monitor").path("monitor.id");
	
		given().
			pathParam("id", id.get(0)).
		when().
			delete("/monitor/{id}").
		then().
			assertThat().statusCode(200);
		
		String id2 = get("/monitor").path("monitor.id");
		
		Monitor rMonitor = given().pathParam("id", id2).get("/monitor/{id}").as(Monitor.class);
		 
		assertThat(MONITOR_BRAND2, equalToIgnoringCase(rMonitor.getBrand()));
		assertEquals(FULL_HD, rMonitor.getPixels());
	}

	@Test
	public void updateMonitor(){
		
		delete("/monitor/").then().assertThat().statusCode(200);
		
		Monitor monitor = new Monitor(MONITOR_BRAND, HD);
		
		given().
	       contentType(MediaType.APPLICATION_JSON).
	       body(monitor).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);
		
		String id = get("/monitor").path("monitor.id");
		
		given().
			pathParam("id", id).
		when().
			post("/monitor/{id}").
		then().
			assertThat().statusCode(200);
		
		Monitor rMonitor = given().pathParam("id", id).get("/monitor/{id}").as(Monitor.class);
		
		assertThat("Edytowany", equalToIgnoringCase(rMonitor.getBrand()));
	}
	
	@Test
	public void getAll(){
		
		delete("/monitor/").then().assertThat().statusCode(200);
		
		Monitor monitor = new Monitor(MONITOR_BRAND, HD);
		Monitor monitor2 = new Monitor(MONITOR_BRAND2, FULL_HD);
		
		given().
	       contentType(MediaType.APPLICATION_JSON).
	       body(monitor).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);
		
		given().
	       contentType(MediaType.APPLICATION_JSON).
	       body(monitor2).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);
		
		given().
		when().
			get("/monitor/").
		then().
    		body("monitor.brand", hasItems(MONITOR_BRAND, MONITOR_BRAND2)).
    		body("monitor.pixels", hasItems("720", "1080"));
		
		ArrayList<String> id = get("/monitor/").path("monitor.id");
		Monitor rMonitor1 = given().pathParam("id", id.get(0)).get("/monitor/{id}").as(Monitor.class);
		Monitor rMonitor2 = given().pathParam("id", id.get(1)).get("/monitor/{id}").as(Monitor.class);
		
		assertThat(MONITOR_BRAND, equalToIgnoringCase(rMonitor1.getBrand()));
		assertEquals(HD, rMonitor1.getPixels());
		
		assertThat(MONITOR_BRAND2, equalToIgnoringCase(rMonitor2.getBrand()));
		assertEquals(FULL_HD, rMonitor2.getPixels());
	}
	
	@Test
	public void getByPixels(){
		
		delete("/monitor/").then().assertThat().statusCode(200);
		
		Monitor monitor = new Monitor(MONITOR_BRAND, HD);
		Monitor monitor2 = new Monitor(MONITOR_BRAND2, FULL_HD);
		Monitor monitor3 = new Monitor(MONITOR_BRAND, FULL_HD);
		
		given().
	       contentType(MediaType.APPLICATION_JSON).
	       body(monitor).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);
		
		given().
	       contentType(MediaType.APPLICATION_JSON).
	       body(monitor2).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);
		
		given().
	       contentType(MediaType.APPLICATION_JSON).
	       body(monitor3).
	    when().	     
	    	post("/monitor/").
	    then().
	    	assertThat().statusCode(201);

		given().
			pathParam("monitorPixels", FULL_HD).
		when().
			get("/monitor/pixels/{monitorPixels}/").
		then().
    		body("monitor.brand", hasItems(MONITOR_BRAND, MONITOR_BRAND2)).
    		body("monitor.pixels", hasItems("1080"));
		
		ArrayList<String> id = get("/monitor/pixels/1080").path("monitor.id");
		Monitor rMonitor1 = given().pathParam("id", id.get(0)).get("/monitor/{id}").as(Monitor.class);
		Monitor rMonitor2 = given().pathParam("id", id.get(1)).get("/monitor/{id}").as(Monitor.class);
		
		assertThat(MONITOR_BRAND2, equalToIgnoringCase(rMonitor1.getBrand()));
		assertEquals(FULL_HD, rMonitor1.getPixels());
		
		assertThat(MONITOR_BRAND, equalToIgnoringCase(rMonitor2.getBrand()));
		assertEquals(FULL_HD, rMonitor2.getPixels());
	}
	
}
