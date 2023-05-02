package app.model;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;


import javax.persistence.*;
import java.util.*;

@Entity
@Table(name = "s_users")
@JsonIgnoreProperties({"points", "password","hibernateLazyInitializer", "handler"})
public class User {
    @Id
    @Column(name = "login", nullable = false)
    private String login;
    @Column(name = "password", nullable = false)
    private String password;
    @OneToMany(fetch = FetchType.EAGER, mappedBy = "owner")
    private Set<Point> points;

    public User(String login, String password) {
        this.login = login;
        this.password = new BCryptPasswordEncoder().encode(password);
        this.points = new LinkedHashSet<>();
    }

    public User() {
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public Set<Point> getPoints() {
        return points;
    }

    public void setPoints(Set<Point> points) {
        this.points = points;
    }
}
