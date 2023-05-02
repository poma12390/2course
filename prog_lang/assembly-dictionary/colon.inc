%macro colon 2

%2:
%ifdef NEXT_ELEM
dq NEXT_ELEM
%else
dq 0
%endif
db %1, 0
%define NEXT_ELEM %2	
%endmacro