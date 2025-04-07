#include <windows.h>

int main() {
	//HWND wndw = GetConsoleWindow();
	HDC hdc = GetDC(NULL);
	COLORREF green = RGB(0, 255, 0);
	COLORREF lavender = RGB(220, 208, 255);
	COLORREF dark_violet = RGB(148, 0, 211);
	COLORREF tan = RGB(210, 180, 140);
	COLORREF black = RGB(65, 65, 65);

	HBRUSH gb = CreateSolidBrush(green);
	HBRUSH lb = CreateSolidBrush(lavender);
	HBRUSH vb = CreateSolidBrush(dark_violet);
	HBRUSH tb = CreateSolidBrush(tan);
	HBRUSH bb = CreateSolidBrush(black);

	// Use SelectObject( HDC hdc, HBRUSH brush) to select the color
	
	SelectObject(hdc, bb);
	Rectangle(hdc, 500, 50, 1000, 1000);
	int w[4] = {500, 50, 1000, 1000};
	for ( int seg = 0; seg < 7; seg++) {
		SelectObject(hdc, lb);
		Rectangle(hdc, w[0] + 400, w[1] + 250 + (seg * 32), w[0] + 432, w[1] + 282 + (seg * 32));
		SelectObject(hdc, vb);
		Rectangle(hdc, w[0] + 404, w[1] + 254 + (seg * 32), w[0] + 412, w[1] + 278 + (seg * 32));
		Rectangle(hdc, w[0] + 420, w[1] + 254 + (seg * 32), w[0] + 428, w[1] + 278 + (seg * 32));
	}
	SelectObject(hdc, lb);

	POINT head1 = {w[0] + 408, w[1] + 250 - 32};
	POINT head2 = {w[0] + 424, w[1] + 250 - 32};
	POINT head3 = {w[0] + 400, w[1] + 250};
	POINT head4 = {w[0] + 432, w[1] + 250};
	const POINT points[4] = {head1, head2, head3, head4};
	CreatePolygonRgn(points, 4, WINDING);
	SelectObject(hdc, vb);
	Rectangle(hdc, w[0] + 412, w[1] + 250 - 16, w[0] + 420, w[1] + 250);
	SelectObject(hdc, bb);
	Rectangle(hdc, w[0] + 408, w[1] + 250 - 12, w[0] + 412, w[1] + 250 - 8);
	Rectangle(hdc, w[0] + 420, w[1] + 250 - 24, w[0] + 424, w[1] + 250 - 8);
	
	SelectObject(hdc, tb);
	Rectangle(hdc, w[0] + 500, w[1] + 500, w[2] + 516, w[3] + 516);

	DeleteObject(gb);
	DeleteObject(lb);
	DeleteObject(vb);
	DeleteObject(tb);
	DeleteObject(bb);
	
	//ReleaseDC(wndw, hdc);

	return 0;
}
