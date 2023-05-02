<jsp:useBean id="age" scope="request" type="java.lang.Integer"/>
<jsp:useBean id="name" scope="request" type="java.lang.String"/>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>JSP Application</title>
</head>
<body>
<p>Name: ${name}</p>
<p>Age: ${age}</p>
</body>
</html>