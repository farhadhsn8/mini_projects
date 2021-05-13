library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity FA is 
    port (a,b,cin : in std_logic;
          sum,cout: out std_logic);
end FA;

architecture behavior of FA is
    begin
        cout <= ( a and b ) or ( a and cin ) or( b and cin) ;
        sum <=  (a xor b) xor cin ;
    end behavior;