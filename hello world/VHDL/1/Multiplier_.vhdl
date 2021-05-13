library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity multiplier is
    generic ( data_width : integer := 4 );
    port(
        A : in std_logic_vector (data_width-1 downto 0);
        B : in std_logic_vector (data_width-1 downto 0);
        P : out std_logic_vector (2*data_width-1 downto 0)
    );
end multiplier;

architecture semi_structural of multiplier is

    component ripple_carry_adder is
        generic ( data_width : integer);
        port (
            A : in std_logic_vector (data_width-1 downto 0);
            B : in std_logic_vector (data_width-1 downto 0);
            Cin : in std_logic;
            S : out std_logic_vector (data_width-1 downto 0);
            Cout : out std_logic
        );
    end component;
    --for all : rca use entity work.ripple_carry_adder(behavioral);

    component and_array is
        generic (data_width: integer);
        port(
            A : in std_logic_vector (data_width-1 downto 0);
            B : in std_logic;
            O : out std_logic_vector (data_width-1 downto 0)
        );
    end component;
    --for all : aa use entity work.and_array(behavioral);

    type cons_array is array (0 to data_width-2) of std_logic_vector(data_width-1 downto 0);
    --AND product terms
    signal G : cons_array;
    signal B_signal : cons_array;
    
    begin
        ANDn: for i in 0 to data_width-2 generate
            and_gate: and_array
            generic map(data_width)
            port map ( A, B(i+1), G(i) );
        end generate;

        B_signal(0)(0) <= '0';
        b_signal_zero_input: and_array generic map(data_width) port map( A(data_width-1 downto 1), B(0), B_signal(0)(data_width-1 downto 1) );

        RCAn_Row: for i in 0 to data_width-2 generate
            RCAn_column: for j in 1 to data_width-1 generate
                    main: ripple_carry_adder 
                    generic map(data_width)
                    port map( 
                        A => G(i), 
                        B => B_signal(i), 
                        Cin =>'0',
                        Cout => B_signal(i+1)(data_width-1),
                        S(0) => P(i+1),
                        S => B_signal(i+1)(j-1)   
                    );
            end generate;
            M: if i = data_width-2 generate
                most: ripple_carry_adder
                generic map(data_width)
                port map(
                    A => G(i),
                    B => B_signal(i),
                    Cin => '0',
                    Cout => P(2*data_width-1),
                    S => P(2*data_width-2 downto i+1)
                );
            end generate;
        end generate;
        P(0) <= A(0) and B(0);
end architecture semi_structural;