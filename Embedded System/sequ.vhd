library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity sequ is
		port(clk: in STD_LOGIC;
		rst: in STD_LOGIC;
		din: in STD_LOGIC;
		dout: out STD_LOGIC);
end sequ;

architecture behavior of sequ is 
type state_type is (s0,s1,s2,s3,s4);
signal present_state, next_state : state_type;
begin

sreg: process(clk,rst)
begin
	if rst = '1' then 
		present_state <= s0;
	elsif clk'event and clk = '1' then
		present_state <= next_state;
	end if;
end process;

c1 :process(present_state, din)
begin
	case present_state is 
		when s0 =>
			if din = '1' then 
				next_state <= s1;
			else
				next_state <= s0;
			end if;
		when s1 =>
			if din = '0' then 
				next_state <= s2;
			else
				next_state <= s1;
			end if;
		when s2 =>
			if din = '0' then 
				next_state <= s3;
			else
				next_state <= s1;
			end if;
		when s3 =>
			if din = '1' then 
				next_state <= s4;
			else
				next_state <= s0;
			end if;
		when s4 =>
			if din = '1' then 
				next_state <= s1;
			else
				next_state <= s0;
			end if;
	end case;
end process;

c2: process(present_state)
begin 
	if present_state = s4 then 
		dout <= '1';
	else 
		dout <= '0';
	end if;
end process;

end behavior;
