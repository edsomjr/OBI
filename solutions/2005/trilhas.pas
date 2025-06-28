{ OBI2005            }
{ Tarefa Trilhas     }
{ r. anido           }

program trilhas;
const
	MAXVAL = 100000;
var
	n, m, i, j, a, b	 : integer;
	melhor_trilha		 : integer;
	esforco1, esforco2 : longint;
	min_esforco			 : longint;

begin
	min_esforco := MAXVAL;
	readln(n);
	for i:=1 to n do begin
		esforco1 := 0; esforco2 := 0;
		read(m); read(a);
		for j:=1 to m-1 do begin
			read(b);
			if a > b then { final para o inicio }
				esforco1 := esforco1 + a - b
			else	{ inicio para o final }
				esforco2 := esforco2 + b - a;
			a := b;
		end;
		readln;
		if (esforco1 > esforco2) then
			esforco1 := esforco2;
		if (esforco1 < min_esforco) then begin
			min_esforco := esforco1;
			melhor_trilha := i;
		end;
	end;
	writeln(melhor_trilha);
end.
