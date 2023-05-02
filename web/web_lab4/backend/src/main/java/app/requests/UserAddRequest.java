package app.requests;

import app.model.User;

public class UserAddRequest {
    private String login;
    private String password;

    public User createUser(){
        return new User(login, password);
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}