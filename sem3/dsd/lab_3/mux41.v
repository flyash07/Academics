module mux41(w,s,f);
input [0:3]w;
input [0:1]s;
output f;
reg f;
always@(w,s)
begin
	if (s==0)
		f=w[0];
	else if (s==1)
		f=w[1];
	else if (s==2)
		f=w[2];
	else 
		f=w[3];
end
endmodule
