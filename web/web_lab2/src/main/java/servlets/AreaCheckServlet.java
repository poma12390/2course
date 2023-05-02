package servlets;


import data.Result;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

@WebServlet(name = "AreaCheckServlet", value = "/checkArea")
public class AreaCheckServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        try {
            HttpSession session = req.getSession();

            session.setAttribute("validity", "false");
            boolean validate = validateAll(req.getParameter("y"), req.getParameter("x"), req.getParameter("r"));
            if (validate) {
                long startTime = System.nanoTime();
                double x = Double.parseDouble(req.getParameter("y"));
                double y = Double.parseDouble(req.getParameter("x"));
                double r = Double.parseDouble(req.getParameter("r"));
                SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd 'at' HH:mm:ss z");
                Date date = new Date(System.currentTimeMillis());
                String currentTime = formatter.format(date);
                //boolean hit = (y <= r && y >= 0 && x >= 0 && x <= r / 2) || (x <= 0 && x >= y - r / 2 && y <= r / 2 && y >= 0) || (x >= 0 && y <= 0 && x * x + y * y <= r * r / 4);
                boolean hit= ((x * x + y * y <= r * r && x>=0 && y>=0) || (x>=0 && y<=0 && y>=-r/2 && x<=r) || (y<=0 && x<=0 && y>-x-r/2));
                Result result = new Result(Math.round(x * 100) / 100D, Math.round(y * 100) / 100D, r, currentTime, Math.ceil((System.nanoTime() - startTime) * (Math.pow(10,-3)*(Math.pow(10,5)))) / (Math.pow(10,5)), hit);
                List<Result> results;
                if (session.getAttribute("results") == null) {
                    results = new ArrayList<>();
                } else {
                    results = (ArrayList<Result>) session.getAttribute("results");
                }
                results.add(result);
                session.setAttribute("results", results);
                session.setAttribute("validity", "true");

                getServletContext().getRequestDispatcher("/index.jsp").forward(req, resp);
            } else {
                throw new IllegalArgumentException("Неверные значения параметров!");
            }
        } catch (IllegalArgumentException|IOException e){
            resp.setStatus(400);
            req.setAttribute("message", "-> Ошибка: " + e.getMessage());
            req.getRequestDispatcher("index.jsp").forward(req, resp);
        }

    }


    private boolean validateY(String xString) {
        try {
            double yValue = Double.parseDouble(xString);
            return yValue >= -3 && yValue <= 5;
        } catch (Exception exception) {
            return false;
        }
    }

    private boolean validateX(String yString) {
        try {
            double yValue = Double.parseDouble(yString);
            return yValue >= -3 && yValue <= 5;
        } catch (Exception exception) {
            return false;
        }
    }

    private boolean validateR(String rString) {
        try {
            List<Double> rRange = new ArrayList<>(Arrays.asList(1.0, 1.5, 2.0, 2.5, 3.0));

            double rValue = Double.parseDouble(rString);
            return rRange.contains(rValue);
        } catch (Exception exception) {
            return false;
        }
    }

    private boolean validateAll(String xString, String yString, String rString) {
        return validateY(yString) && validateX(xString) && validateR(rString);
    }

}