import javax.servlet.http.*;
import javax.servlet.*;
import java.io.*;

public class FibonacciServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse responce) throws ServletException, IOException {
        responce.setContentType("text/html;charset=utf-8");
        PrintWriter out = responce.getWriter();
        
        out.println("<html>");
        out.println("<head> <title>피보나치</title> <head>");
        out.println("<body>");
        
        int num1 = 1, num2 = 1, num3 = 2;
        out.printf("%d %d ", num1, num2);
        while (num3 < 100) {
            out.printf("%d ", num3);
            num1 = num2;
            num2 = num3;
            num3 = num1 + num2;
        }

        out.println("</body>");
        out.println("</html>");
    }
}