set serveroutput on
declare  
issue_p date; 
return_d date; 
days number(10);
begin 
    issue_p :='&iss';					
    dbms_output.put_line('issuee :'||issue_p);
    return_d :='&ret';
    dbms_output.put_line('return :'||return_d);
    days := return_d-issue_p; 
    DBMS_OUTPUT.PUT_LINE('No.of days: ' ||days);   
    if days<=7 then
        dbms_output.put_line('Fine:'||0);
    elsif days<=15 then
        dbms_output.put_line('Fine:'||(days-7));
    elsif days<=30 then
        dbms_output.put_line('Fine:'||(8+(days-15)*2));
    else
        dbms_output.put_line('Fine:'||(38+(days-30)*5));
    end if;
end;
/