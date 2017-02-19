package hibernate.model.domain;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@NamedQueries({
        @NamedQuery(name = "student.all", query = "SELECT s FROM Student s"),
})
public class Student {
    private Long id;
    private String imie;
    private String uczelnia;

    private List<Book> books = new ArrayList<Book>();

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    public Long getId() {
        return id;
    }
    public void setId(Long id) {
        this.id = id;
    }

    @OneToMany(mappedBy = "student", cascade = CascadeType.ALL, fetch = FetchType.LAZY)
    public List<Book> getBooks() {
        return books;
    }
    public void setBooks(List<Book> books) {
        this.books = books;
    }

    @Column(nullable = false)
    public String getImie() {
        return imie;
    }
    public void setImie(String imie) {
        this.imie = imie;
    }

    public String getUczelnia() {
        return uczelnia;
    }
    public void setUczelnia(String uczelnia) {
        this.uczelnia = uczelnia;
    }
}

