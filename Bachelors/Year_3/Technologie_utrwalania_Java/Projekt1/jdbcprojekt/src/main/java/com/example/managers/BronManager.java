package com.example.managers;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.example.tables.Bron;

public class BronManager {
	
	private Connection connection;
	
	private String url = "jdbc:hsqldb:hsql://localhost/workdb";
	
	private String createTableBron = "CREATE TABLE Bron(id bigint UNIQUE GENERATED BY DEFAULT AS IDENTITY, nazwa varchar(20), obrazenia varchar(20))";
	
	private PreparedStatement addBronStmt;
	private PreparedStatement deleteAllBronStmt;
	private PreparedStatement getAllBronStmt;
	
	private Statement statement;
	
	public BronManager() {
		try {
			connection = DriverManager.getConnection(url);
			statement = connection.createStatement();
			ResultSet rs = connection.getMetaData().getTables(null, null, null,
							null);
			boolean tableExists = false;
			while (rs.next()) {
				if ("Bron".equalsIgnoreCase(rs.getString("TABLE_NAME"))) {
						tableExists = true;
						break;
				}
			}
			
			if (!tableExists)
					statement.executeUpdate(createTableBron);
			addBronStmt = connection
					.prepareStatement("INSERT INTO Bron (nazwa, obrazenia) VALUES (?, ?)");
			deleteAllBronStmt = connection
					.prepareStatement("DELETE FROM Bron");
			getAllBronStmt = connection
					.prepareStatement("SELECT id, nazwa, obrazenia FROM Bron");
		} catch (SQLException e) {
				e.printStackTrace();
		}
	}
	
	Connection getConnection() {
		return connection;
	}
	
	void clearBron() {
		try {
				deleteAllBronStmt.executeUpdate();
		} catch (SQLException e) {
				e.printStackTrace();
		}
	}
	
	public int addBron(Bron bron) {
		int count = 0;
		try {
				addBronStmt.setString(1, bron.getNazwa());
				addBronStmt.setString(2, bron.getObrazenia());
				
				count = addBronStmt.executeUpdate();
				
		} catch (SQLException e) {
				e.printStackTrace();
		}
		return count;
	}
	
	public List<Bron> getAllBron() {
		List<Bron> bron = new ArrayList<Bron>();
		
		try {
				ResultSet rs = getAllBronStmt.executeQuery();
				while (rs.next()) {
						Bron b = new Bron();
						b.setId(rs.getInt("id"));
						b.setNazwa(rs.getString("nazwa"));
						b.setObrazenia(rs.getString("obrazenia"));
						bron.add(b);
		}
		} catch (SQLException e) {
				e.printStackTrace();
		}
		return bron;
	}
	
}
