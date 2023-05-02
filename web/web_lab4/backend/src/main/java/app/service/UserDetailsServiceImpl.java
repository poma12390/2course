package app.service;

import app.model.User;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.*;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.HashSet;
import java.util.Set;

@Service
public class UserDetailsServiceImpl implements UserDetailsService {

    private UserService service;

    public UserDetailsServiceImpl(UserService service){
        this.service = service;
    }

    @Transactional
    public UserDetails loadUserByUsername(String name) throws UsernameNotFoundException{

        User user = service.getUser(name);
        if(user==null) throw new UsernameNotFoundException("Login not found");
        Set<GrantedAuthority> roles = new HashSet<>();
        roles.add(new SimpleGrantedAuthority("USER"));
        return new org.springframework.security.core.userdetails.User(user.getLogin(),
                user.getPassword(),
                roles);

    }
}
