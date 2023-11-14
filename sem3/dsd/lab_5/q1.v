module q1(A,B,C,D,f);
	input A,B,C,D;
	wire f1;output f;
	     mux4_1 m1((!A|B),~B,(!A|B),1'b0,C,D,f1);
	assign f=f1;
endmodule

module mux4_1(w0,w1,w2,w3,s1,s0,f);
	input w0,w1,w2,w3,s1,s0;
	output reg f;
	always @(s1,s0)
	begin
		if (s1==1'b0)
		begin
			if (s0==1'b0) f=w0;
			else f=w1;
		end
		else 
		begin
		    if(s0==1'b0) f=w2;
		    else f=w3;
		end
	end
endmodule

