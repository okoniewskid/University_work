package hibernate.model.service;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import hibernate.model.domain.Book;
import hibernate.model.domain.Student;
import org.junit.Before;
import org.junit.After;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.test.context.transaction.TransactionConfiguration;
import org.springframework.transaction.annotation.Transactional;

import java.util.ArrayList;
import java.util.List;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = { "classpath:/beans.xml" })
@TransactionConfiguration(transactionManager = "txManager", defaultRollback = true)
@Transactional
public class ManagerTest {

    @Autowired
    Manager manager;

    private final String imie1 = "Imie1";
    private final String uczelnia1 = "Uczelnia1";
    private final String imie2 = "Imie2";
    private final String uczelnia2 = "Uczelnia2";
    private final String title1 = "Tytuł1";
    private final String author1 = "Autor1";
    private final String title2 = "Tytuł2";
    private final String author2 = "Autor2";
    private List<Long> bookIds = new ArrayList<Long>();
    private List<Long> studentIds = new ArrayList<Long>();

    @Before
    public void DataInitialization() {

        List<Book> allBooks = manager.getAllBooks();
        List<Student> allStudents = manager.getAllStudents();

        for (Book book : allBooks)
            bookIds.add(book.getId());

        for (Student student : allStudents)
            studentIds.add(student.getId());
    }

    @After
    public void DetaDeletion() {
        boolean delete;
        List<Book> bookList = manager.getAllBooks();
        List<Student> studentList = manager.getAllStudents();

        for (Book book : bookList) {
            delete = true;
            for (Long bookID : bookIds)
                if (book.getId() == bookID) {
                    delete = false;
                    break;
                }
            if (delete)
                manager.delete(book);
        }

        for (Student student : studentList) {
            delete = true;
            for (Long studentID : studentIds)
                if (student.getId() == studentID) {
                    delete = false;
                    break;
                }
            if (delete)
                manager.delete(student);
        }
    }

    @Test
    public void getById() {

        Student s = new Student();
        s.setImie(imie1);
        s.setUczelnia(uczelnia1);
        
        Book b = new Book();
        b.setTitle(title1);
        b.setAuthor(author1);
        b.setStudent(s);
        
        Long StudentId = manager.add(s);
        Long BookId = manager.add(b);
        
        Book newBook = manager.getBookById(BookId);
        Student newStudent = manager.getStudentById(StudentId);

        assertEquals(StudentId, newStudent.getId());
        assertEquals(imie1, newStudent.getImie());
        assertEquals(uczelnia1, newStudent.getUczelnia());
        assertEquals(BookId, newBook.getId());
        assertEquals(title1, newBook.getTitle());
        assertEquals(author1, newBook.getAuthor());
        assertEquals(newStudent.getId(), newBook.getStudent().getId());
    }

    @Test
    public void checkAdd() {

        Student s = new Student();
        s.setImie(imie1);
        s.setUczelnia(uczelnia1);
        
        Book b = new Book();
        b.setTitle(title1);
        b.setAuthor(author1);
        b.setStudent(s);
        
        List<Book> allBooks = manager.getAllBooks();
        List<Student> allStudents = manager.getAllStudents();

        Long StudentId = manager.add(s);
        Long BookId = manager.add(b);
        
        List<Book> allBooks2 = manager.getAllBooks();
        List<Student> allStudents2 = manager.getAllStudents();

        Book newBook = manager.getBookById(BookId);
        Student newStudent = manager.getStudentById(StudentId);

        assertEquals(StudentId, newStudent.getId());
        assertEquals(imie1, newStudent.getImie());
        assertEquals(uczelnia1, newStudent.getUczelnia());
        assertEquals(BookId, newBook.getId());
        assertEquals(title1, newBook.getTitle());
        assertEquals(author1, newBook.getAuthor());
        assertEquals(newStudent.getId(), newBook.getStudent().getId());
        assertEquals(allBooks2.size(), allBooks.size()+1);
        assertEquals(allStudents2.size(), allStudents.size()+1);
    }

    @Test
    public void checkEdit() {

        Student s = new Student();
        s.setImie(imie1);
        s.setUczelnia(uczelnia1);
        Student st = new Student();
        st.setImie(imie1);
        st.setUczelnia(uczelnia1);
        
        Book b = new Book();
        b.setStudent(s);
        b.setTitle(title1);
        b.setAuthor(author1);
        Book bo = new Book();
        bo.setStudent(st);
        bo.setTitle(title1);
        bo.setAuthor(author1);
        
        Long StudentId = manager.add(s);
        Long BookId = manager.add(b);
        Long StudentId2 = manager.add(st);
        Long BookId2 = manager.add(bo);
        
        Book b1 = manager.getBookById(BookId);
        Student s1 = manager.getStudentById(StudentId);
        Book b2 = manager.getBookById(BookId2);
        Student s2 = manager.getStudentById(StudentId2);

        manager.edit(s, imie2, uczelnia2);
        manager.edit(b, s, title2, author2);

        assertEquals(title2, b1.getTitle());
        assertEquals(author2, b1.getAuthor());
        assertEquals(imie2, s1.getImie());
        assertEquals(uczelnia2, s1.getUczelnia());   
        assertEquals(title1, b2.getTitle());
        assertEquals(author1, b2.getAuthor());
        assertEquals(imie1, s2.getImie());
        assertEquals(uczelnia1, s2.getUczelnia());
    }

    @Test
    public void checkDelete() {

        Student s = new Student();
        s.setImie(imie1);
        s.setUczelnia(uczelnia1);
        Student st = new Student();
        st.setImie(imie2);
        st.setUczelnia(uczelnia2);
        Book b = new Book();
        b.setStudent(s);
        b.setTitle(title1);
        b.setAuthor(author1);
        Book bo = new Book();
        bo.setStudent(st);
        bo.setTitle(title2);
        bo.setAuthor(author2);

        Long StudentId = manager.add(s);
        Long BookId = manager.add(b);

        List<Book> allBooks = manager.getAllBooks();
        List<Student> allStudents = manager.getAllStudents();

        manager.delete(b);
        manager.delete(s);

        List<Book> allBooks2 = manager.getAllBooks();
        List<Student> allStudents2 = manager.getAllStudents();
        
        assertEquals(title2, bo.getTitle());
        assertEquals(author2, bo.getAuthor());
        assertEquals(imie2, st.getImie());
        assertEquals(uczelnia2, st.getUczelnia());
        assertEquals(allBooks2.size(), allBooks.size()-1);
        assertEquals(allStudents2.size(), allStudents.size()-1);
        assertNull(manager.getBookById(BookId));
        assertNull(manager.getStudentById(StudentId));
    }

    @Test
    public void checkFindBooks() {

        Student s1 = new Student();
        s1.setImie(imie1);
        s1.setUczelnia(uczelnia1);
        manager.add(s1);

        Book b1 = new Book();
        b1.setStudent(s1);
        b1.setTitle(title1);
        b1.setAuthor(author1);
        manager.add(b1);
        //Book b2 = new Book();
        //b2.setStudent(s1);
        //b2.setTitle(title2);
        //b2.setAuthor(author2);
        //manager.add(b2);
        List<Book> foundBooks = manager.findBooks(s1);

        assertEquals(foundBooks.size(), 1);
    }
    
    @Test
    public void checkFindByAuthor() {
    	Student s1 = new Student();
        s1.setImie(imie1);
        s1.setUczelnia(uczelnia1);
        manager.add(s1);
    	Book b1 = new Book();
        b1.setStudent(s1);
        b1.setTitle(title1);
        b1.setAuthor(author1);
        manager.add(b1);
        Book b2 = new Book();
        b2.setStudent(s1);
        b2.setTitle(title2);
        b2.setAuthor(author2);
        manager.add(b2);
        Book b3 = new Book();
        b3.setStudent(s1);
        b3.setTitle(title2);
        b3.setAuthor(author2);
        manager.add(b3);
        
        String author = b2.getAuthor();
        List<Book> foundBooks = manager.findBooksByAuthor(author);
        
        assertEquals(foundBooks.size(), 2);
    }

}