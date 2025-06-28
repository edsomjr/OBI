{ OBI2005               }
{ Tarefa Duende         }
{ r. anido              }
{ versao nao recursiva  }

program duende;
const
	MAX	  = 100;
	MAXFILA = 4*MAX;
type
	posicao = record
					 x, y, dist : integer
				 end;	  
var
	n, m, i, j	 : integer;
	caverna		 : array[0..MAX+1,0..MAX+1] of integer;
	fila			 : array[0..MAXFILA-1] of posicao;
	pos			 : posicao;
	f_ini, f_fim : integer;

procedure insere(i, j, distancia : integer);
begin
	caverna[i, j] := 2; { para duende não retornar }
	with fila[f_fim] do begin
		x := i; y := j; dist := distancia;
	end;
	f_fim := (f_fim + 1) mod MAXFILA;
	if (f_ini = f_fim) then begin
		writeln('FILA TRANSBORDOU!');
		exit;
	end;
end; { insere }

function retira: posicao;
var tmp: posicao;
begin
	if (f_ini = f_fim) then begin
		writeln('FILA VAZIA');
		exit;
	end;
	with fila[f_ini] do begin
		tmp.x := x; tmp.y := y; tmp.dist := dist;
	end;
	f_ini := (f_ini + 1) mod MAXFILA;
	retira := tmp;
end; { retira }

begin
	{ inicializa fila }
	f_ini := 0; f_fim := 0;
	{ le entrada }
	readln(n, m);
	for i:=1 to n do begin
		for j:=1 to m do begin
			read(caverna[i,j]);
			{ se é posição do duende, coloca na fila para processar }
			if caverna[i,j]=3 then insere(i,j, 0);
		end;
		readln;
	end;
	{ inicializa bordas da caverna }
	for i:=0 to n+1 do begin
		caverna[i,0] := 2;
		caverna[i,m+1] := 2;
	end;
	for j:=0 to m+1 do begin
		caverna[0,j] := 2;
		caverna[n+1,j] := 2;
	end;

	pos := retira;
	{ processa a fila -- a primeira posição na fila é a posição do duende }
	while (true) do begin
		with pos do begin
			{ verifica vizinhos; se é caminho (valor verdadeiro), coloca na fila }
			if caverna[x-1, y]=0 then break
			else if caverna[x-1,y]=1 then insere(x-1, y, pos.dist+1);
			if caverna[x+1, y]=0 then break
			else if caverna[x+1,y]=1 then insere(x+1, y, pos.dist+1);
			if caverna[x, y-1]=0 then break
			else if caverna[x, y-1]=1 then insere(x, y-1, pos.dist+1);
			if caverna[x, y+1]=0 then break
			else if caverna[x, y+1]=1 then insere(x, y+1, pos.dist+1);
		end;
		pos := retira;
	end;
	writeln(pos.dist+1);
end.
