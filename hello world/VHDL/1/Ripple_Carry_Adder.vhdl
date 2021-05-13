library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ripple_carry_adder is
    generic ( data_width : integer:= 4 );
    port (
        A : in std_logic_vector (data_width-1 downto 0);
        B : in std_logic_vector (data_width-1 downto 0);
        Cin : in std_logic;
        S : out std_logic_vector (data_width-1 downto 0);
        Cout : out std_logic
    );
end ripple_carry_adder;

architecture behavioral of ripple_carry_adder is

    component full_adder is 
        port ( a, b, cin: in std_logic; sum, cout: out std_logic );
    end component;

    --for all : FA use entity work.full_adder(behav);

    signal carry_out : std_logic_vector(data_width downto 0);
    
    begin
        carry_out(0) <= Cin;
        FAn: for i in 0 to data_width-1 generate
        
            L : if i = 0 generate
                least: full_adder port map( A(i), B(i), carry_out(i), S(i), carry_out(i+1) );
            end generate;

            M : if i = data_width-1 generate
                most: full_adder port map( A(i), B(i), carry_out(i), S(i), carry_out(i+1) ) ;
            end generate;

            R : if i > 0 and i < data_width-1 generate
                rest: full_adder port map( A(i), B(i), carry_out(i), S(i), carry_out(i+1) ) ;
            end generate;
        end generate;
        Cout <= carry_out(4);
end behavioral;