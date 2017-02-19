package hibernate.model.service;

import hibernate.model.domain.Book;
import hibernate.model.domain.Student;

import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.transaction.annotation.Transactional;

import java.util.ArrayList;
import java.util.List;

@Component
@Transactional
public class Manager {

    @Autowired
    private SessionFactory sf;


    @SuppressWarnings("unchecked")
    public List<Book> getAllBooks() {
        return sf.getCurrentSession().getNamedQuery("books.all").list();
    }


    @SuppressWarnings("unchecked")
    public List<Student> getAllStudents() {
        return sf.getCurrentSession().getNamedQuery("student.all").list();
    }


    public Book getBookById(Long id) {
        return (Book) sf.getCurrentSession().get(Book.class, id);
    }


    public Student getStudentById(Long id) {
        return (Student) sf.getCurrentSession().get(Student.class, id);
    }


    public Long add(Book book) {
        Long id = (Long) sf.getCurrentSession().save(book);
        book.setId(id);
        Student student = (Student) sf.getCurrentSession().get(Student.class, book.getStudent().getId());
        student.getBooks().add(book);
        return id;
    }


    public Long add(Student student) {
        Long id = (Long) sf.getCurrentSession().save(student);
        student.setId(id);
        return id;
    }


    public void delete(Book b) {
        b = (Book) sf.getCurrentSession().get(Book.class, b.getId());
        Student s = (Student) sf.getCurrentSession().get(Student.class, b.getStudent().getId());
        s.getBooks().remove(b);
        sf.getCurrentSession().delete(b);
    }


    public void delete(Student s) {
        s = (Student) sf.getCurrentSession().get(Student.class, s.getId());
        sf.getCurrentSession().delete(s);
    }


    public void edit(Student s, String imie, String uczelnia) {
        s = (Student) sf.getCurrentSession().get(Student.class, s.getId());
        s.setImie(imie);
        s.setUczelnia(uczelnia);
        sf.getCurrentSession().update(s);
    }


    public void edit(Book book, Student student, String title, String author) {
        book = (Book) sf.getCurrentSession().get(Book.class, book.getId());
        book.setStudent(student);
        book.setTitle(title);
        book.setAuthor(author);
        sf.getCurrentSession().update(book);
    }


    public List<Book> findBooks(Student s) {
        List<Book> allBooks = getAllBooks();
        List<Book> books = new ArrayList<Book>();
        for (Book b : allBooks)
            if (b.getStudent().getId() == s.getId())
                books.add(b);
        return books;
    }
    
    public List<Book> findBooksByAuthor(String author){
    	List<Book> books = new ArrayList<Book>();
    	for(Book b : getAllBooks()) {
    		String auth = b.getAuthor();
    		if(auth == author)
    			books.add(b);
    	}
    	return books;
    }
}