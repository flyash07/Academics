module pe(s,f,en,z);
 	input [3:0]s; input en;
 	output reg [1:0]f; output reg z;
always @ (s,en) 
begin
z=1;
    if(en==1) begin
    casex(s)
        4'b1XXX: f = 2'b11; 
        4'b01XX: f = 2'b10; 
        4'b001X: f = 2'b01; 
        4'b0001: f = 2'b00;
        4'b0000:z=0;
    endcase
    end
end

endmodule
