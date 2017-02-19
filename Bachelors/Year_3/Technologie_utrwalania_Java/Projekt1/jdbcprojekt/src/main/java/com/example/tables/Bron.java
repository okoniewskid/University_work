package com.example.tables;

public class Bron {
	private long id;	
	private String nazwa;
	private String obrazenia;
	
	public Bron() {
	}
	
	public Bron(String nazwa, String obrazenia) {
		this.nazwa = nazwa;
		this.obrazenia = obrazenia;
	}
	
	public long getId() {
		return id;
	}
	public void setId(long id) {
		this.id = id;
	}
	
	public String getObrazenia() {
		return obrazenia;
	}
	public void setObrazenia(String obrazenia) {
		this.obrazenia = obrazenia;
	}
	
	public String getNazwa() {
		return nazwa;
	}
	public void setNazwa(String nazwa) {
		this.nazwa = nazwa;
	}
}
