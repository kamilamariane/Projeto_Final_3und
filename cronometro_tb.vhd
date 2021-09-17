LIBRARY ieee;
USE ieee.std_logic_1164.all;
use work.pacote.all;
use ieee.numeric_std.all;

ENTITY TB_cronometro IS
END TB_cronometro;


ARCHITECTURE rtl OF TB_cronometro IS
    COMPONENT cronometro
        PORT(
                CLOCK_50 : IN STD_LOGIC;
                START_PAUSE : IN STD_LOGIC;
                RESTART : IN STD_LOGIC;
            
                HEX0_D :  out std_logic_vector;
                HEX1_D :  out std_logic_vector;
                HEX2_D :  out std_logic_vector;
                HEX3_D :  out std_logic_vector;
                HEX4_D :  out std_logic_vector;
                HEX5_D :  out std_logic_vector; 
                HEX6_D :  out std_logic_vector;
                HEX7_D :  out std_logic_vector
   
       );
    END COMPONENT;
    
    SIGNAL CLOCK_50 : STD_LOGIC;
    SIGNAL START_PAUSE : STD_LOGIC;
    SIGNAL RESTART : STD_LOGIC;
    
    SIGNAL HEX0_D :  std_logic_vector (6 downto 0);
    SIGNAL HEX1_D :  std_logic_vector (6 downto 0);
    SIGNAL HEX2_D :  std_logic_vector (6 downto 0);
    SIGNAL HEX3_D :  std_logic_vector (6 downto 0);
    SIGNAL HEX4_D :  std_logic_vector (6 downto 0);
    SIGNAL HEX5_D :  std_logic_vector (6 downto 0); 
    SIGNAL HEX6_D :  std_logic_vector (6 downto 0);
    SIGNAL HEX7_D :  std_logic_vector (6 downto 0);
   
    
    BEGIN
    dut: cronometro PORT MAP
    (
        CLOCK_50 => CLOCK_50,
        START_PAUSE => START_PAUSE,
        RESTART => RESTART,
        HEX0_D => HEX0_D,
        HEX1_D => HEX1_D,
        HEX2_D => HEX2_D,
        HEX3_D => HEX3_D,
        HEX4_D => HEX4_D,
        HEX5_D => HEX5_D,
        HEX6_D => HEX6_D,
        HEX7_D => HEX7_D
    );

    
    stim_process: PROCESS
    BEGIN
              WAIT FOR 50 ns;
              RESTART <= '1';
             
              WAIT FOR 5 ns;
              START_PAUSE <= '1';
           
              WAIT FOR 5 ns;
              START_PAUSE <= '1';
             
              WAIT FOR 1500 ns;
              RESTART <= '1';
              
    END PROCESS;
END rtl;
