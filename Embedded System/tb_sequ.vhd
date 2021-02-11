library IEEE;
use IEEE.STD_LOGIC_1164.all;

ENTITY tb_sequ IS
END tb_sequ;
 
ARCHITECTURE behavior OF tb_sequ IS
  
COMPONENT sequ
PORT(
clk : IN std_logic;
din : IN std_logic;
rst : IN std_logic;
dout : OUT std_logic
);
END COMPONENT;

signal clk : std_logic := '0';
signal din : std_logic := '0';
signal rst : std_logic := '0';
signal dout : std_logic;


BEGIN
uut: sequ PORT MAP (
clk => clk,
din => din,
rst => rst,
dout => dout
);

clk_process :process
begin
clk <= '0';
wait for 10ns;
clk <= '1';
wait for 10ns;
end process;

stim_proc: process
begin
 
rst <= '1';
wait for 20 ns;
rst <= '0';

din <= '0';
wait for 20 ns;

din <= '1';
wait for 20 ns;
 
din <= '0';
wait for 20 ns;

din <= '1'; 
wait for 20 ns;

din <= '0';
wait for 20 ns;

din <= '0';
wait for 20 ns;

din <= '1';
wait for 20 ns;

din <= '0';
wait for 20 ns;

end process;
end behavior; 


