library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

package pacote is
	function integertoseg(N: integer) return std_logic_vector;
	function toboolean(N1: std_logic) return boolean;
end pacote;

package body pacote is
	function integertoseg(N: integer) return std_logic_vector is
		variable result: std_logic_vector (6 downto 0);
	begin
		case N is
			when 0 => result := "1000000";
			when 1 => result := "1111001";
			when 2 => result := "0100100";
			when 3 => result := "0110000";
			when 4 => result := "0011001";
			when 5 => result := "0010010";
			when 6 => result := "0000010";
			when 7 => result := "1011000";
			when 8 => result := "0000000";
			when 9 => result := "0010000";
			when 10 => result := "0111111";
			when others => result := (others => '0');
		end case;
		return result;
	end integertoseg;
	
	function toboolean(N1: std_logic) return boolean is
		variable resultb: boolean;
	begin
		case N1 is
			when '1' => resultb := true;
			when '0' => resultb := false;
			when others => resultb := false;
		end case;
		return resultb;
	end toboolean;
end pacote;
