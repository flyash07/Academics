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




