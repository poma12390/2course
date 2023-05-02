package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.Console;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;

@WebServlet(name = "ControllerServlet", value = "/process")
public class    ControllerServlet extends HttpServlet {



    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        res.setContentType("text/html;charset=UTF-8");
        if (!Objects.equals(req.getParameter("x"), "") && !Objects.equals(req.getParameter("y"), "") && !Objects.equals(req.getParameter("r"), "")) {
            // validate parameters
            req.getRequestDispatcher("/checkArea").forward(req, res);
            //req.getRequestDispatcher("index1.jsp").forward(req, res);
            }
        else {
            req.setAttribute("message", "-> Ошибка: переданы не все параметры!");
            req.getRequestDispatcher("index.jsp").forward(req, res);
        }

//        if (req.getParameter("x") != null && req.getParameter("y") != null && req.getParameter("r") != null) {
//            // validate parameters
//            //req.getRequestDispatcher("/checkArea").forward(req, res);
//
//            // Hello
//
//            out.println("<html><body>");
//            out.println("<h1>" + "message " + "</h1>");
//            out.println("</body></html>");
//        }else {
//            out.println(req.getParameter("x"));
//            out.println(req.getParameter("y"));
//            out.println(req.getParameter("r"));
//            req.setAttribute("message", "-> Ошибка: переданы не все параметры!");
//            req.getRequestDispatcher("index1.jsp").forward(req, res);
//        }
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        req.setAttribute("message", "-> Ошибка: переданы не все параметры!");
        req.getRequestDispatcher("index.jsp").forward(req, res);
    }
    public void destroy() {
    }
//    @Override
//    protected void doGet(HttpServletRequest req, HttpServletResponse res)
//            throws ServletException, IOException {
//        if (req.getParameter("clear") != null && req.getParameter("clear").equals("true")) {
//            req.getRequestDispatcher("/clear").forward(req, res);
//        } else if (req.getParameter("x") != null && req.getParameter("y") != null && req.getParameter("r") != null) {
//            // validate parameters
//            req.getRequestDispatcher("/checkArea").forward(req, res);
//        } else {
//            // error message
//            req.setAttribute("message", "-> Ошибка: переданы не все параметры!");
//            req.getRequestDispatcher("index.jsp").forward(req, res);
//        }
//    }
//
//    @Override
//    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        req.getRequestDispatcher("index.jsp").forward(req, resp);
//    }
}
