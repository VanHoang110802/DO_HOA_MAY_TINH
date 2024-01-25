/*
- Chuong trinh ve mui ten ban vao bang diem 
- Nhớ thêm linker: -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
*/
#include <cstdio>
#include <conio.h>
#include <graphics.h>
int main(){
    // bình thường, khi ta để những dòng code như này, thì ta đang làm việc với màn hình console, còn muốn làm việc với đồ họa thì:
    // tự động phát hiện độ phân giải của máy
   // int gd = DETECT, gm;
   // initgraph(&gd,&gm,"");    // gm để chế độ tham chiếu là để tự nó lấy thông tin khi bật chế độ đồ họa lên
    // tuy nhiên ta vẫn có thể thay đổi kích thước của cửa sổ đồ họa ( nhưng tui nghĩ nên để mặc định thì tốt hơn :'>)
    initwindow(700,500,"Hoang Dep Trai",200,100);
    // màu của trên đồ họa thì dùng câu lệnh sau:
    setcolor(15);    // 0-> 15
    //printf("Hello Van Hoang");  // xuất trên console
    outtextxy(200,400,"Chuong trinh dau tay: Ve mui ten chuan bi cam vao bang ngam."); // xuất chuỗi lên màn hình đồ họa
    int xdt3 = 100, ydt3 = 350;
    int xdt4 = 400, ydt4 = 165;
    line(xdt3,ydt3,xdt4,ydt4);
    for(int i =0;i<=50;i+=10){
        circle(600,50,i);
    }
    line(400,165,370,165);
    line(400,165,380,190);
    // sau khi code xong, phải đóng chế độ cửa sổ lại
    // nhớ dừng lại để xem màn hình nhé
    getch();
    closegraph();
    return 0;
}
