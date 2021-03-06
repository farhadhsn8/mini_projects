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