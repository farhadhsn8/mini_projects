library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity multiplication is 
    generic (dw:integer := 4);------------------------num of bit
    port (x,y : in std_logic_vector (dw-1 downto 0);
        z:out std_logic_vector (2*dw-1 downto 0)
    );
end multiplication;

architecture structural of multiplication is
    component RCA
    port (a_n,b_n : in std_logic_vector (dw-1 downto 0);
        cin_n : in std_logic;-----------------------cin_n=0
        sum_n:out std_logic_vector (dw-1 downto 0);
        cout_n:out std_logic
    );
    end component;
    SIGNAL sig : BIT_VECTOR ((dw+1)*(dw-1)-1 downto 0); 
    variable zero : bit_vector (10 downto 0) := "00000000000";
    

    begin

        if (y(0)='0' and y(1)='0')then
            mu0:RCA port map ( zero(dw-1 downto 0)=>a_n , zero(dw-1 downto 0) =>b_n , 0 =>cin_n , sig(dw-1 downto 0) => sum_n , sig(dw) => cout_n  );
            z(0)<=0;
        end if;
        if (y(0)='0' and y(1)='1')then
            mu0:RCA port map ( zero(dw-1 downto 0)=>a_n , x => b_n , 0 =>cin_n , sig(dw-1 downto 0) => sum_n , sig(dw) => cout_n  );
            z(0)<=0;
        end if;
        if (y(0)='1' and y(1)='0')then
            mu0:RCA port map ( x =>a_n , zero(dw-1 downto 0) =>b_n , 0 =>cin_n , sig(dw-1 downto 0) => sum_n , sig(dw) => cout_n  );
            z(0)<=x(0);
        end if;
        if (y(0)='1' and y(1)='1')then
            mu0:RCA port map ( x=>a_n , x(dw-1 downto 1) =>b_n(dw-2 downto 0) , 0=>b_n(dw-1) , 0 =>cin_n , sig(dw-1 downto 0) => sum_n , sig(dw) => cout_n  );
            z(0)<=x(0);
        end if;
        
        
        mu: FOR i IN 2 TO dw-1 GENERATE-------------------------------------------------------------------------------c1ton-2
        if (y(i)='0')then
            mu:RCA port map ( zero(dw-1 downto 0)=>a_n , sig(dw*(i-1)-2+i downto dw*(i-1)-5+i ) =>b_n , 0 =>cin_n , sig((dw+1)*(i-1)+3 downto (dw+1)*(i-1)) => sum_n , sig((dw+1)*i-1) => cout_n  );
        end if;
        if (y(i)='1')then
            mu:RCA port map ( x=>a_n , sig(dw*(i-1)-2+i downto dw*(i-1)-5+i )=>b_n , 0 =>cin_n , sig((dw+1)*(i-1)+3 downto (dw+1)*(i-1)) => sum_n , sig((dw+1)*i-1) => cout_n   );
        end if;
        END GENERATE;
        for j in 1 to dw-2 loop
            z(j)<=sig((dw+1)*(j-1));
        end loop;
        z(2*dw-1 downto dw-1)<=sig(dw*dw-2 downto dw*dw-dw-2);


        
    
end structural;