import javax.servlet.http.*;
import javax.servlet.*;
import java.io.*;

public class PersonalInfoServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse responce) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        responce.setContentType("text/html;charset=utf-8");
        PrintWriter out = responce.getWriter();
        
        String name = request.getParameter("name");
        String id = request.getParameter("id");
        String password = request.getParameter("password");
        String gender = request.getParameter("gender");
        String inotice = request.getParameter("inotice");
        String cnotice = request.getParameter("cnotice");
        String dnotice = request.getParameter("dnotice");
        String job = request.getParameter("job");

        if (gender.equals("male")) gender = "남";
        else gender = "여";
        inotice = toNotice(inotice);
        cnotice = toNotice(cnotice);
        dnotice = toNotice(dnotice);

        out.println("<html>");
        out.println("<head> <title>개인 정보 입력 - 결과화면</title> <head>");
        out.println("<body>");
        out.println("<h2>결과화면</h2>");
        writeInfo(out, "이름", name);
        writeInfo(out, "아이디", id);
        writeInfo(out, "암호", password);
        writeInfo(out, "성별", gender);
        writeInfo(out, "공지 메일", inotice);
        writeInfo(out, "광고 메일", cnotice);
        writeInfo(out, "배송 확인 메일", dnotice);
        writeInfo(out, "직업", job);
        out.println("</body>");
        out.println("</html>");
    }
    private String toNotice(String radio)
    {
        if (radio == null) {
            return "받지 않음";
        }
        else if (radio.equals("on")) {
            return "받음";
        }
        else {
            return radio;
        }
    }

    private void writeInfo(PrintWriter out, String name, String data)
    {
        out.printf("%s : %s <br>", name, data);
    }
}