library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity and_array is
    generic (data_width: integer:= 4);
    port(
        A : in std_logic_vector (data_width-1 downto 0);
        B : in std_logic;
        O : out std_logic_vector (data_width-1 downto 0)
    );
end and_array;

architecture behavioral of and_array is
    begin
        ANDn: for i in 0 to data_width-1 generate
            O(i) <= A(i) and B;
        end generate;
end behavioral;