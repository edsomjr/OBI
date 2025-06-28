{ OBI2005            }
{ Tarefa Energia     }
{ r. anido           }
{ versao recursiva   }

program energia;
const
   MAXE =  100;
var
	linhas	  : array[1..MAXE, 1..MAXE] of boolean;
	i, j, x, y : integer;
	e, l		  : integer;
   teste		  : integer;
	conectada : array [1..MAXE] of boolean;

function busca(v : integer):integer;
{ executa busca em profundidade a partir de v }
{ retorna número de estações encontradas      }
var i, c	: integer;
begin
	conectada[v] := true;
	c := 1;
	for i:=1 to e do
		if (not conectada[i]) and linhas[i,v] then
			{ se a estação i não foi ainda conectada e }
			{ existe ligação entre i e v, inicia nova busca }
			{ a partir de i }
			c := c + busca(i);
	{ retorna número de estações encontradas nesta busca }
	busca := c;
end;

begin
   teste := 0;
   readln(e, l);
   while e <> 0 do begin
		teste := teste + 1;
      writeln('Teste ', teste);
		{ inicializa linhas de transmissao}
      for i:= 1 to e do
			for j:= 1 to e do
				linhas[i,j] := false;
		for i:= 1 to e do
			conectada[i] := false;
      for i:= 1 to l do begin
			readln(x, y);
			linhas[x,y] := true;
			linhas[y,x] := true;
      end;
		{ executa busca em profundidade a partir de }
		{ qualquer estacao e imprime resultado }
		if busca(1) = e then writeln('normal')
		else writeln('falha');
		writeln;
      readln(e, l);
	end;
end.
