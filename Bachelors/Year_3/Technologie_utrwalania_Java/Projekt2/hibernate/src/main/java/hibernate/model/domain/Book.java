package hibernate.model.domain;

import javax.persistence.*;

@Entity
@NamedQueries({
        @NamedQuery(name = "books.all", query = "SELECT b FROM Book b")
})
public class Book implements java.io.Serializable{
    private Long id;
    private Student student;
    private String title;
    private String author;

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    public Long getId() {
        return id;
    }
    public void setId(Long id) {
        this.id = id;
    }

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "id_student",  nullable = false)
    public Student getStudent() {
        return student;
    }
    public void setStudent(Student student) { this.student = student; }

    @Column(nullable = false)
    public String getTitle() {
        return title;
    }
    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }
    public void setAuthor(String author) {
        this.author = author;
    }
}
