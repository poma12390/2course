<%@ page import="data.Result" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<%
    List<Result> results = new ArrayList<>();
    if (request.getSession().getAttribute("results") != null) {
        results = (ArrayList<Result>) request.getSession().getAttribute("results");
    }
%>
<head>
    <title>Title</title>
</head>
<body>
<div>
    <table width="100%" id="result-table" class="result-table">
        <thead>
        <tr>
            <th>X</th>
            <th>Y</th>
            <th>R</th>
            <th>Current time</th>
            <th>Execution time</th>
            <th>Hit detect</th>
        </tr>
        </thead>
        <tbody>
        <%
            //                    if(results != null && results.size() > 0)
//                    System.out.println(results.get(0).getExecutionTime());
            for (int i = 0; i < results.size(); i++) {
                Result result = results.get(i);
        %>
        <tr>
            <td><%=result.getX()%>
            </td>
            <td><%=result.getY()%>
            </td>
            <td><%=result.getR()%>
            </td>
            <td><%=result.getCurrTime()%>
            </td>
            <td><%=result.getExecutionTime()%>
            </td>
            <td><%=result.getHit()%>
            </td>
        </tr>
        <%
            }
            ;
        %>
        </tbody>
    </table>
</div>
<div>
    <form class="form" action="${pageContext.request.contextPath}/process"  method="POST">
        <input type="submit" value="В дурку">
    </form>


</div>

</body>
</html>
