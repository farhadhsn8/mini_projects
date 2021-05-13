library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity project is
    port(A , B :in std_logic_vector(10 downto 0) ;rst,clk:in std_logic;start:in bit;answ:out bit;
     result :out std_logic_vector(10 downto 0) );
end project;
architecture gcd of project is
    type state is 
    (s0,s1,s2,s3,s31,s4,s5,s6,s7,s8);
    signal pr_state,nx_state :state;
    signal tmp:std_logic_vector(10 downto 0);
    signal y:std_logic_vector(10 downto 0);
    signal x:std_logic_vector(6 downto 1);
    signal reg1,reg2:std_logic_vector(10 downto 0);
    
    signal c:integer:=0 ;
 function alu (P,Q:in std_logic_vector(10 downto 0) ;
    sel:in std_logic_vector(1 downto 0)) return std_logic_vector is
        variable temp :std_logic_vector(10 downto 0);
        begin
            case sel is
        when "00" => temp:= std_logic_vector(unsigned(P)+unsigned(Q));
        when "01" => 

        if q(0)='0' then q(0)='1';
        else q(0)='0';
        end if;
        if q(1)='0' then q(1)='1';
        else q(1)='0';
        end if;
        if q(2)='0' then q(2)='1';
        else q(2)='0';
        end if;
        if q(3)='0' then q(3)='1';
        else q(3)='0';
        end if;
       
        if q(4)='0' then q(4)='1';
        else q(4)='0';
        end if;
        if q(5)='0' then q(5)='1';
        else q(5)='0';
        end if;
        if q(6)='0' then q(6)='1';
        else q(6)='0';
        end if;
        if q(7)='0' then q(7)='1';
        else q(7)='0';
        end if;
        if q(8)='0' then q(8)='1';
        else q(8)='0';
        end if;
        if q(9)='0' then q(9)='1';
        else q(9)='0';
        end if;
        if q(10)='0' then q(10)='1';
        else q(10)='0';
        end if;
        temp:= std_logic_vector(unsigned(P)-unsigned(Q)+"00000000001");

        when "10" => temp:=Q(9 downto 0) & '0';
        when "11" => temp:= '0' & Q(10 downto 1);
        when others =>temp :=(others=>'0');
        end case;
        return temp;
            end function;
    
   
    begin
      --  y(0)<='1';
    --y(1)<='0';
    --y(2)<='0';
    --y(3)<='0';
    --y(4)<='0';
    --y(5)<='0';
    --y(6)<='0';
    --y(7)<='0';
    --y(8)<='0';
    --y(9)<='0';
    --y(10)<='0';
    --x(1)<='0';
    --x(2)<='0';
    --x(3)<='0';
    --x(4)<='0';
    --x(5)<='0';
    --x(6)<='0';
    process(clk,rst) 
    begin 
    if(rst='1') then 
    pr_state<=s0;
    elsif (clk'event and clk='1') then 
    pr_state<=nx_state;
    end if;
    end process;
    process(pr_state)
    begin

        case pr_state is
    when s0 =>
        if (start = '1') then
        nx_state<=s1;
        else nx_state<=s0;
        end if;
    when s1 =>
        reg1<=A;
        reg2<=B;
        if(unsigned(reg1)=unsigned(reg2)) then
        result<= A;
        answ<='1';
        nx_state<=s8;
        else nx_state<=s2;
        end if;

    when s2 => 
        if (unsigned(reg2)>unsigned(reg1)) then
            nx_state<=s4;
            else nx_state<=s3;
        end if;


    when s3 => 
    if(reg2(9)='1') then 
    reg1<=alu(reg1 , reg2,"01");
    nx_state<=s5;
    else 
    reg2<=alu(reg1,reg2,"10");
    c<=c+1;
    nx_state<=s31;
    end if;

    when s31 =>
    nx_state<=s3;
       
 
    when s4=>
    tmp<=reg1;
    reg1<=reg2;
    reg2<=reg1;
    nx_state<=s2;


    when s5=>
    if (reg1(10)='1') then 
    reg1<=alu(reg1,reg2,"00");
    end if;
    nx_state<=s6;


    when s6=>
    if (c=0) then 
    nx_state<=s7;
    else 
    reg2<=alu(reg1,reg2,"11");
    c<=c-1;
    reg1<=alu(reg1 , reg2,"01");
    nx_state<=s5;
    end if;



    when s7=>
    if(reg1="10000000000") then
        result<=reg2;
        answ<='1';
        nx_state<=s8;
    else
      nx_state<=s4;
      end if;
      when s8 =>
      if(rst='1') then
      nx_state<=s0;
      else 
      nx_state<=s8;
      end if;
      end case;
    end process;
    end gcd;
