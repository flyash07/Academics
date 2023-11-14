module decode4_16(en,a,y);
	input en;
	input [3:0]a;
	output [15:0]y;
	wire [3:0]b;
        
        decode24 m1(en,a[3:2],b[3:0]);
        decode24 m2(b[0],a[1:0],y[3:0]);
        decode24 m3(b[1],a[1:0],y[7:4]);
        decode24 m4(b[2],a[1:0],y[11:8]);
        decode24 m5(b[3],a[1:0],y[15:12]);
endmodule

module decode24(en,a,y);
	input en;
	input [1:0]a;
	output reg [3:0]y;
    always @ (a or en)
    begin
        if (en)
        begin
            if (a == 0) begin
                y[0] = 1;
                y[1] = 0;
                y[2] = 0;
                y[3] = 0;
            end
            else if (a == 1) begin
                y[0] = 0;
                y[1] = 1;
                y[2] = 0;
                y[3] = 0;
            end
            else if (a == 2) begin
                y[0] = 0;
                y[1] = 0;
                y[2] = 1;
                y[3] = 0;
            end
            else if (a == 3) begin
                y[0] = 0;
                y[1] = 0;
                y[2] = 0;
                y[3] = 1;
            end
        end
        else begin
            y[0] = 0;
            y[1] = 0;
            y[2] = 0;
            y[3] = 0;
        end
    end

endmodule

