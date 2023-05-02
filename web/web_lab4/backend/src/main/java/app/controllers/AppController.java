package app.controllers;

import app.requests.BaseResponse;
import app.service.*;
import app.model.*;
import app.requests.*;

import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.view.RedirectView;

import java.util.Set;

@RestController
@RequestMapping("/")
@EnableWebSecurity
public class AppController {

    private final UserService userService;

    private final DataService data;

    public AppController(DataService data, UserService userService) {

        this.data = data;
        this.userService = userService;
    }

        @GetMapping(value = {"/", "/login", "/register", "/application", "/registration", "authorisation"})
    public RedirectView redirectToIndex() {
        return new RedirectView("/index.html");
    }

    @PostMapping("/add")
    public BaseResponse addPoint(@RequestBody PointAddRequest pointAddRequest){
        pointAddRequest.check();
        User user = userService.getUser(SecurityContextHolder.getContext().getAuthentication().getName());
        Point point = pointAddRequest.createPoint(user);
        data.addPoint(point);
        return new BaseResponse(200, user.getPoints());
    }

    @PostMapping("/register")
    public BaseResponse addUser(@RequestBody UserAddRequest userAddRequest){
        boolean isOk = userService.addUser(userAddRequest.createUser());
        return new BaseResponse(isOk?200:400, isOk);
    }

    @GetMapping("/get")
    public BaseResponse getElements(){
        User user = userService.getUser(SecurityContextHolder.getContext().getAuthentication().getName());
        return new BaseResponse(200, user.getPoints());
    }

    @PostMapping("/update")
    public BaseResponse updatePoint(@RequestBody PointUpdateRequest request){
        request.check();
        User user = userService.getUser(SecurityContextHolder.getContext().getAuthentication().getName());
        Set<Point> points = data.updatePoint(request.getId(), user, request.getX(), request.getY());
        int status = points==null?400:200;
        return new BaseResponse(status, points);
    }

    @PostMapping("/delete")
    public BaseResponse deletePoint(@RequestBody PointUpdateRequest request){
        User user = userService.getUser(SecurityContextHolder.getContext().getAuthentication().getName());
        Set<Point> points = data.deletePoint(request.getId(), user);
        int status = points==null?400:200;
        return new BaseResponse(status, points);
    }

    @PostMapping("/ok")
    public BaseResponse ok(){
        return new BaseResponse(200,"ok");
    }

    @PostMapping("/err")
    public BaseResponse err(){
        return new BaseResponse(400,"error");
    }
}
