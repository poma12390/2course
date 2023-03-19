package parsers;


import org.apache.commons.lang3.StringUtils;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class function_parser {
    static int size;
    public static double[] find_index(String function){
        System.out.println(function);
        ArrayList<String> coef=new ArrayList<>();
        String x="-?([0-9]+)\\.?([0-9]*)x*(\\^[0-9])*";
        Pattern pattern = Pattern.compile(x);
        Matcher matcher = pattern.matcher(function);
        while (matcher.find()) {
            coef.add(function.substring(matcher.start(), matcher.end()));
        }
        System.out.println(coef);
        String[]temp=coef.get(0).split("[x^]");
        size= Integer.parseInt(temp[2]);
        double[] indexes = new double[size+1];

        for (String s : coef) {
            if (s.contains("x^")) {
                temp = s.split("[x^]");
                indexes[Integer.parseInt(temp[2])] = Double.parseDouble(temp[0]);

            } else if (s.contains("x")) {
                temp = s.split("x");
                indexes[1] = Double.parseDouble(temp[0]);
            } else {
                indexes[0] = Double.parseDouble(s);
            }

        }
        //System.out.println(Arrays.toString(indexes));
        return indexes;
    }
}
