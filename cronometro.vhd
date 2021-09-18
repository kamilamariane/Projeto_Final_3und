library ieee;
use ieee.std_logic_1164.all;
use work.pacote.all;
use ieee.numeric_std.all;

entity cronometro is
generic (SEGUNDOS:  integer := 49999999); 	-- numero de clocks para um segundo
port(
	CLOCK_50 :  in std_logic;
	START_PAUSE : in std_logic;
	RESTART	: in std_logic;
	HEX0_D :  out std_logic_vector (6 downto 0);
	HEX1_D :  out std_logic_vector (6 downto 0);
	HEX2_D :  out std_logic_vector (6 downto 0);
	HEX3_D :  out std_logic_vector (6 downto 0);
	HEX4_D :  out std_logic_vector (6 downto 0);
	HEX5_D :  out std_logic_vector (6 downto 0);
	HEX6_D :  out std_logic_vector (6 downto 0);
	HEX7_D :  out std_logic_vector (6 downto 0)
);
end cronometro;

architecture behaviour of cronometro is
	signal S_P : boolean;							-- sinal para o botão START_PAUSE
	signal R_T : boolean;							-- sinal para o botão RESTART
	signal TEMP: integer range 0 to SEGUNDOS; -- contagem
	signal SS0 : integer range 0 to 59 := 0; 	-- contagem geral de segundos
	signal SS1 : integer range 0 to 9 := 0;  	-- primeiro segmento de segundos
	signal SS2 : integer range 0 to 5 := 0;   -- segundo segmento de segundos
	signal MM0 : integer range 0 to 9 := 0; 	-- primeiro segmento de minutos
	signal MM1 : integer range 0 to 5 := 0; 	-- segundo segmento de minutos
	signal HH0 : integer range 0 to 9 := 0; 	-- primeiro segmento de horas
	signal HH1 : integer range 0 to 2 := 0; 	-- segundo segmento de horas
	
	begin 												-- atribuição de valores para os segmentos
		HEX0_D <= integertoseg(10);
		HEX1_D <= integertoseg(10);
		HEX2_D <= integertoseg(SS1);
		HEX3_D <= integertoseg(SS2);
		HEX4_D <= integertoseg(MM0);
		HEX5_D <= integertoseg(MM1);
		HEX6_D <= integertoseg(HH0);
		HEX7_D <= integertoseg(HH1);
		S_P <= toboolean(START_PAUSE);
		R_T <= not toboolean(RESTART);
		
		process(CLOCK_50)
		begin
		 if rising_edge(CLOCK_50) then
			if(TEMP /= SEGUNDOS) then  			-- borda ascendente do clock para contar os segundos quando necessario
				TEMP <= TEMP + 1;
			else
				if(R_T) then
					HH0 <= 0;
					HH1 <= 0;
					MM0 <= 0;
					MM1 <= 0;
					SS0 <= 0;
					SS1 <= 0;
					SS2 <= 0;
				elsif(S_P) then
					TEMP <= 0;
					SS0 <= SS0 + 1;
					SS1 <= SS1 + 1;
					if(SS1 = 9) then
						SS1 <= 0;
						SS2 <= SS2 + 1;
					if(SS0 = 59) then
						SS0 <= 0;
						SS1 <= 0;
						SS2 <= 0;
						MM0 <= MM0 + 1;
						if(MM0 = 9) then
							MM0 <= 0;
							MM1 <= MM1 + 1;
							if(MM1 = 5) then
								MM1 <= 0;
								HH0 <= HH0 + 1;
								if(HH0 = 9) then
									HH0 <= 0;
									HH1 <= HH1 + 1;
								elsif(HH0 = 3 and HH1 = 2) then
									HH0 <= 0;
									HH1 <= 0;
									MM0 <= 0;
									MM1 <= 0;
									SS1 <= 0;
									SS2 <= 0;
								end if;
							end if;
						end if;
					end if;
				end if;
			end if;
		end if;
	end if;
end process;
end behaviour;
