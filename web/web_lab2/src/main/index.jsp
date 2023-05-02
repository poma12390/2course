<%@ page import="data.Result" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<!DOCTYPE html>
<html lang="en">
<%
    List<Result> results = new ArrayList<>();
    if (request.getSession().getAttribute("results") != null) {
        results = (ArrayList<Result>) request.getSession().getAttribute("results");
    }
%>
<head>
    <meta charset="UTF-8">
    <title>ITMO</title>
    <link rel="shortcut icon" href="logo.png" type="image/png">
    <script src="https://cdn.jsdelivr.net/npm/js-cookie@rc/dist/js.cookie.min.js"></script>
    <!--    @mixin border-radius($radius){-->
    <!--    border-radius: $radius;-->
    <!--    } SCSS -->
    <style>


        #canvas {
            height: 350px;

        }


        .input_buttons {

            border-radius: 100px;
        }


        .input_buttons {
            border-radius: 10px;
        }


        body {
            background-image: url("/webapp/space.jpg");
            background-size: 100%;
        }

        table {


            table-layout: fixed;
            margin-bottom: 2%;
            background-color: #F39C12;
            width: auto;
        }

        th {
            font-weight: bold;
            padding: 0.15%;
            background: #FFBB97;
            border: 1px solid #dddddd;
        }

        td {
            padding: 5px 10px;
            border: 1px solid #eee;
            text-align: left;
        }

        tbody tr:nth-child(odd) {
            background: #F8C471;
        }

        tbody tr:nth-child(even) {
            background: #F5B041;
        }


        h1 {
            margin: auto;
            background-color: yellow;
            border: 1px solid black;
            font: 33px sans-serif;
        }

        div {
            margin-left: auto;
            margin-right: auto;
            text-align: center;
        }


        .table {
            display: flex;
            flex-direction: column;
            margin-left: auto;
            margin-right: auto;
        }

        .proga {
            border: 5mm ridge rgba(250, 150, 50);
        }

        [data-tooltip]:active {
            content: attr(data-tooltip); /* Выводим текст */
        }

       input[type="submit"] {
            display: flex;
            margin: 1%;
            height: 28px;
            border: solid black;
            width: 46px;
            border-width: 3px 3px 5px 5px;
            border-radius: 16% 95% 25% 95%/95% 16% 92% 5%;
            transform: rotate(-2deg);
        }

        .main-table {
            display: flex;
            flex-direction: column;
            gap: 10px;
            background-color: #FFDEAD;

        }

        .form__y-input, .form__row {
            padding-bottom: 3px;
            text-align: left;
        }

        .input_buttons {
            text-align: left;

        }

        .rez {
            display: flex;
            flex-direction: column;
            gap: 7px;
        }

        div > #canvas {
            background-color: #FFBB97;
            margin-left: auto;
            margin-right: auto;
            text-align: center;
            border-bottom: solid #D2691E;
        }

        .rez {
            float: left;

        }

        .input_table {
            display: flex;
            flex-direction: row;
            width: 550px;
            margin-left: auto;
            margin-right: 100px;

        }

        /* ToolTip classses */
        .tooltip {
            display: inline-block;
        }

        .tooltip .tooltiptext {
            margin-left: 89px;
            width: 190px;
            visibility: hidden;
            background-color: #F1C40F;
            border-radius: 4px;
            border: 1px solid #aeaeae;
            position: absolute;
            z-index: 1;
            padding: 5px;
            margin-top: 13px;
            opacity: 0;
            transition: opacity 0.5s;
            font-size: 14px;
        }
        .divi{
            display: flex;
            flex-direction: row;
        }

        .tooltip .tooltiptext::after {
            content: " ";
            position: absolute;
            top: 5%;
            right: 100%;
            margin-top: -5px;
            border-width: 5px;
            border-style: solid;
            border-color: transparent #aeaeae transparent transparent;
        }


        .tooltip:hover .tooltiptext {
            visibility: visible;
            opacity: 1;
        }

    </style>

</head>
<body>

<div class="table">
    <div class="proga">
        <div class="header">
            <h1>Кочнев Роман P32081 Вариант 4621
            </h1>
        </div>
        <div class="main-table">
            <canvas id="canvas"></canvas>
            <div class="input_table">
                <%
                    Result result1 = new Result(0,0,0,"0",0,false);
                    if (results.size()>0){
                        result1 = results.get(results.size()-1);
                    }
                %>
                <div class="rez">

                    <label id="y_value">X=<%=result1.getX()%></label>
                    <label id="x_value"> Y=<%=result1.getY()%></label>
                    <label id="r_value">R=<%=result1.getR()%></label>
                    Ввод параметров

                </div>
                <div class="inputs">
                    <form class="form" action="${pageContext.request.contextPath}/process"  method="POST">
                        <div class="form__y-input">
                            <div class="tooltip">
                                <span class="tooltiptext">
                                    Введите число в интервале [-3;5]
                                </span>
                                <label for="xParam"></label><input type="text" id="xParam" name="y"
                                                                   placeholder="Введите X"
                                                                   data-tooltip="Введите число в интервале [-3;5]">
                            </div>

                        </div>
                        <div class="form__row">
                            <input type="radio" id="radioButton-2" value="-2" name="x"
                                   onclick="set_Y_value('radioButton-2')">
                            <label for="radioButton-2">-2</label>
                            <input type="radio" id="radioButton-1.5" value="-1.5" name="x"
                                   onclick="set_Y_value('radioButton-1.5')">
                            <label for="radioButton-1.5">-1.5</label>
                            <input type="radio" id="radioButton-1" value="-1" name="x"
                                   onclick="set_Y_value('radioButton-1')">
                            <label for="radioButton-1">-1</label>
                            <input type="radio" id="radioButton-0.5" value="-0.5" name="x"
                                   onclick="set_Y_value('radioButton-0.5')">
                            <label for="radioButton-0.5">-0.5</label>
                            <input type="radio" id="radioButton0" value="0" name="x"
                                   onclick="set_Y_value('radioButton0')">
                            <label for="radioButton0">0</label>
                            <input type="radio" id="radioButton0.5" value="0.5" name="x"
                                   onclick="set_Y_value('radioButton0.5')">
                            <label for="radioButton0.5">0.5</label>
                            <input type="radio" id="radioButton1" value="1" name="x"
                                   onclick="set_Y_value('radioButton1')">
                            <label for="radioButton1">1</label>
                            <input type="radio" id="radioButton1.5" value="1.5" name="x"
                                   onclick="set_Y_value('radioButton1.5')">
                            <label for="radioButton1.5">1.5</label>
                            <input type="radio" id="radioButton2" value="2" name="x"
                                   onclick="set_Y_value('radioButton2')">
                            <label for="radioButton2">2</label>
                        </div>

                        <div class="form__row">
                            <input id="X_rez" type="hidden" name="r" value=<%=result1.getR()%>>
                            <button class="form__x-btn" type="button" value="1" id="b1" name="X" onclick="set_R_value(id)">1</button>
                            <button class="form__x-btn" type="button" value="1.5" id="b1_5" name="X" onclick="set_R_value(id)">1.5</button>
                            <button class="form__x-btn" type="button" value="2" id="b2" name="X" onclick="set_R_value(id)">2</button>
                            <button class="form__x-btn" type="button" value="2.5" id="b2_5" name="X" onclick="set_R_value(id)">2.5</button>
                            <button class="form__x-btn" type="button" value="3" id="b3" name="X" onclick="set_R_value(id)">3</button>
                        </div>
                        <div class="divi">
                            <input type="submit" value="Тык" />
<%--                                <button type="button" id="input" class="input_buttons" onclick="chek_input()">Тык--%>
<%--                                </button>--%>
                            <form class="form" action="${pageContext.request.contextPath}/process"  method="POST" id = "subForm">
                                <input type="submit" value="clear" onclick="deleteAllCookies()" id="input1"/>
                            </form>
                        </div>
                    </form>
                </div>

            </div>
            <div class="foot">
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

        </div>
    </div>

</div>


<script src="app.js"></script>
<script>

</script>
<script type="text/javascript" src="Code_js/draw.js"></script>
<script type="text/javascript" src="Code_js/Valid.js"></script>
<script type="text/javascript" src="Code_js/setters.js"></script>

</body>
</html>