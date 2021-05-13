library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity rca is 
    generic (n:integer := 4);
    port (a_n,b_n : in std_logic_vector (n-1 downto 0);
        cin_n : in std_logic;-----------------------cin_n=0
        sum_n:out std_logic_vector (n-1 downto 0);
        cout_n:out std_logic
    );
end rca;

architecture structural of rca is
    component FA
    port (a,b,cin : in std_logic;
          sum,cout: out std_logic);
    end component;
    SIGNAL carry_n : BIT_VECTOR (n-2 downto 0); 
    begin
        c0:FA port map ( a_n(0) => a , b_n(0) => b , 0 => cin , sum_n(0) => sum , carry_n(0) => cout );
        c1ton_2: FOR i IN 1 TO n-2 GENERATE-------------------------------------------------------------------------------c1ton-2
        c: FA PORT MAP ( a_n(i) => a , b_n(i) => b ,  carry_n(i-1) => cin , sum_n(i) => sum , carry_n(i) => cout ); 
        END GENERATE;
        cn_1: FA PORT MAP (a_n(n-1) => a , b_n(n-1) => b ,  carry_n(n-2) => cin , sum_n(n-1) => sum , cout_n => cout);-------cn_1 
end structural;