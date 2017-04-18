import javax.servlet.http.*;
import javax.servlet.*;
import java.io.*;

public class AdderServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse responce) throws ServletException, IOException {
        String str1 = request.getParameter("num1");
        String str2 = request.getParameter("num2");
        int num1 = Integer.parseInt(str1);
        int num2 = Integer.parseInt(str2);
        int num3 = num1 + num2;

        responce.setContentType("text/html;charset=utf-8");
        PrintWriter out = responce.getWriter();
        out.println("<html>");
        out.println("<head> <title>덧셈 결과</title> <head>");
        out.println("<body>");
        out.printf("%d + %d = %d", num1, num2, num3);
        out.println("</body>");
        out.println("</html>");
    }
}