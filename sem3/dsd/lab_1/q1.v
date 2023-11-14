module q1(A,B,C,D,f);
input A,B,C,D;
output f;
assign f=(A&~C&D)|C;
endmodule
