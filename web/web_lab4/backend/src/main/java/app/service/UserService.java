package app.service;

import app.model.User;
import app.repository.UserRepository;
import org.springframework.stereotype.Service;

@Service
public class UserService {

    private final UserRepository repository;

    public UserService(UserRepository repository) {
        this.repository = repository;
    }

    public User getUser(String name){

        if(repository.existsById(name)){
            return repository.getOne(name);
        }
        else return null;
    }

    public boolean addUser(User user){

        if(repository.existsById(user.getLogin())){
            return false;
        }
        else{
            repository.saveAndFlush(user);
            return true;
        }
    }
}
