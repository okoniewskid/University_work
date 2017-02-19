package com.example.dokoniewski;

import static com.jayway.restassured.RestAssured.get;
import static com.jayway.restassured.RestAssured.given;

import java.io.File;
import java.io.FileInputStream;
import java.sql.Connection;
import java.sql.DriverManager;

import javax.ws.rs.core.MediaType;

import org.dbunit.Assertion;
import org.dbunit.IDatabaseTester;
import org.dbunit.JdbcDatabaseTester;
import org.dbunit.database.DatabaseConnection;
import org.dbunit.database.IDatabaseConnection;
import org.dbunit.dataset.IDataSet;
import org.dbunit.dataset.ITable;
import org.dbunit.dataset.filter.DefaultColumnFilter;
import org.dbunit.dataset.xml.FlatXmlDataSetBuilder;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import com.example.dokoniewski.domain.Monitor;
import com.example.dokoniewski.service.MonitorManager;
import com.jayway.restassured.RestAssured;

public class MonitorServiceRESTDBTest {
	
	private static IDatabaseConnection connection ;
	private static IDatabaseTester databaseTester;
	
	private static MonitorManager mm = new MonitorManager();
	
	@BeforeClass
	public static void setUp() throws Exception{
		RestAssured.baseURI = "http://localhost";
		RestAssured.port = 8080;
		RestAssured.basePath = "/projectjava/api";
		
		Connection jdbcConnection;
		jdbcConnection = DriverManager.getConnection(
				"jdbc:hsqldb:hsql://localhost/workdb", "sa", "");
		connection = new DatabaseConnection(jdbcConnection);
	}
	
	@Before
	public void setUpTest() throws Exception{
		databaseTester = new JdbcDatabaseTester(
				"org.hsqldb.jdbcDriver", "jdbc:hsqldb:hsql://localhost/workdb", "sa", "");
		IDataSet dataSet = new FlatXmlDataSetBuilder().build(
				new FileInputStream(new File("src/test/resources/fullData.xml")));
		databaseTester.setDataSet(dataSet);
		databaseTester.onSetup();
	}

	@Test
	public void addMonitor() throws Exception{
	
		Monitor aMonitor = new Monitor("Asus", 480);
		given().contentType(MediaType.APPLICATION_JSON).body(aMonitor)
				.when().post("/monitor/").then().assertThat().statusCode(201);
		
		IDataSet dbDataSet = connection.createDataSet();
		ITable actualTable = dbDataSet.getTable("MONITOR");
		ITable filteredTable = DefaultColumnFilter.excludedColumnsTable
				(actualTable, new String[]{"ID"});
		
		IDataSet expectedDataSet = new FlatXmlDataSetBuilder().build(
				new File("src/test/resources/monitorData.xml"));
		ITable expectedTable = expectedDataSet.getTable("MONITOR");
		
		Assertion.assertEquals(expectedTable, filteredTable);
	}
	
	@Test
	public void deleteMonitor() throws Exception{
		
		String rMonitor_id = get("/monitor/pixels/1080").path("monitor.id");
		
		given().
			pathParam("id", rMonitor_id).
		when().
			delete("/monitor/{id}").
		then().
			assertThat().statusCode(200);
		
		IDataSet dbDataSet = connection.createDataSet();
		ITable actualTable = dbDataSet.getTable("MONITOR");
		ITable filteredTable = DefaultColumnFilter.excludedColumnsTable
				(actualTable, new String[]{"ID"});
		
		IDataSet expectedDataSet = new FlatXmlDataSetBuilder().build(
				new File("src/test/resources/monitorData2.xml"));
		ITable expectedTable = expectedDataSet.getTable("MONITOR");
		
		Assertion.assertEquals(expectedTable, filteredTable);
	}
	
	@Test
	public void updateMonitor() throws Exception{
		
		String rMonitor_id = get("/monitor/pixels/2048").path("monitor.id");
		
		given().
			pathParam("id", rMonitor_id).
		when().
			post("/monitor/{id}").
		then().
			assertThat().statusCode(200);
		
		IDataSet dbDataSet = connection.createDataSet();
		ITable actualTable = dbDataSet.getTable("MONITOR");
		ITable filteredTable = DefaultColumnFilter.excludedColumnsTable
				(actualTable, new String[]{"ID"});
		
		IDataSet expectedDataSet = new FlatXmlDataSetBuilder().build(
				new File("src/test/resources/monitorData3.xml"));
		ITable expectedTable = expectedDataSet.getTable("MONITOR");
		
		Assertion.assertEquals(expectedTable, filteredTable);
	}
	
	@AfterClass
	public static void tearDown() throws Exception{
		databaseTester.onTearDown();
	}

}
