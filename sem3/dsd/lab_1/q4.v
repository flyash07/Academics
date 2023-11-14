module q4(A,B,C,D,f);
input A,B,C,D;
output f;
assign f=~((~C|D)&(~A|B|C)&(A|~B|C|~D));
endmodule
