package okoniewskid.selenium;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.concurrent.TimeUnit;

import org.apache.commons.io.FileUtils;
import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.OutputType;
import org.openqa.selenium.TakesScreenshot;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.Select;
public class MtggoldfishTest {

	private static WebDriver driver;
	WebElement element;

	@BeforeClass
	public static void driverSetup() {
		System.setProperty("webdriver.chrome.driver", "C:\\Users\\dokoniewski\\Downloads\\chromedriver_win32\\chromedriver.exe");
		driver = new ChromeDriver();
		driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
	}
	
	@Test
	public void homePageTest(){
		driver.get("http://www.mtggoldfish.com/");
		
		element = driver.findElement(By.linkText("Articles"));
		
		assertNotNull(element);
	}
	
	@Test
	public void articlesPageTest(){
		driver.get("http://www.mtggoldfish.com/");
		driver.findElement(By.linkText("Articles")).click();
		
		String pageTitle = driver.getTitle();
		
		assertEquals("Magic the Gathering Articles", pageTitle);
	}

	@Test
	public void searchTest(){
		driver.get("http://www.mtggoldfish.com/");
		WebElement element = driver.findElement(By.id("query_string"));
		
		element.sendKeys("collected company");
		element.submit();
		
		String pageTitle = driver.getTitle();

		assertEquals("Collected Company, Dragons of Tarkir (DTK) Price History", pageTitle);
	}
	
	@Test
	public void loginTest(){
		driver.get("http://www.mtggoldfish.com/");
		driver.findElement(By.linkText("Login")).click();
		
		WebElement mail = driver.findElement(By.id("auth_key"));
		WebElement pass = driver.findElement(By.id("password"));
		WebElement submit = driver.findElement(By.xpath("/html/body/div[6]/div[2]/div/div[2]/form[1]/div[3]/input[2]"));
		
		mail.sendKeys("gumalek@wp.pl");
		pass.sendKeys("testpassword");
		submit.click();
		
		WebElement loggedIn = driver.findElement(By.linkText("Account"));
		
		driver.findElement(By.linkText("Account")).click();
		driver.findElement(By.linkText("Logout")).click();
		
		assertNotNull(loggedIn);
	}
	
	@Test
	public void checkBoxTest(){
		driver.get("http://www.mtggoldfish.com/");
		driver.findElement(By.linkText("Decks")).click();
		driver.findElement(By.linkText("User Submitted Decks")).click();
		WebElement checkbox = driver.findElement(By.xpath("/html/body/div[2]/div[5]/div/div[2]/form/div[2]/div/label[2]/input"));		
		checkbox.click();

		assertFalse(checkbox.isSelected());
	}
	
	@Test
	public void dropdownTest(){
		driver.get("http://www.mtggoldfish.com/");
		driver.findElement(By.linkText("Decks")).click();
		driver.findElement(By.linkText("User Submitted Decks")).click();
		
		Select select = new Select(driver.findElement(By.id("format")));
		select.selectByVisibleText("Block");
		
		List<WebElement> options = select.getOptions();
		assertEquals(options.get(5), select.getFirstSelectedOption());
	}
	
	@AfterClass
	public static void cleanp() {
		driver.quit();
	}
}
