import javax.servlet.http.*;
import javax.servlet.*;
import java.io.*;

public class HundredServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse responce) throws ServletException, IOException {
        int total = 0;
        for (int i = 0; i <= 100; i++) {
            total += i;
        }

        responce.setContentType("text/html;charset=utf-8");
        PrintWriter out = responce.getWriter();
        out.println("<html>");
        out.println("<head> <title>100</title> <head>");
        out.println("<body>");
        out.printf("1to 한글 100 = %d", total);
        out.println("</body>");
        out.println("</html>");
    }
}