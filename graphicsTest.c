#include <stdio.h>
#include <windows.h>

void interpolate(byte *col1, byte *col2, byte *out, int stepnumber, int maxstep) {
	for ( int i = 0; i < 3; i++) {
		out[i] = col1[i] + stepnumber * ((col2[i] - col1[i]) / maxstep);
	}
}

int main() {
      	byte red[3] = {255, 0, 0};
      	byte orange[3] = {255, 127, 0};
      	byte yellow[3] = {255, 255, 0};
      	byte green[3] = {0, 255, 0};
	byte blue[3] = {0, 0, 255};
	byte indigo[3] = {75, 0, 130};
	byte violet[3] = {148, 0, 211};
	byte* colors[7] = {
		red,
		orange,
		yellow,
		green,
		blue,
		indigo,
		violet
	};
	byte cur[3];

      	RECT yeet = {0, 0, 400, 400};
      	HDC screenDC = GetDC(NULL);
      	for ( int col = 0; col < 7; col++) {
		for ( int stp = 0; stp < 100; stp++) {
			interpolate(colors[col], colors[col + 1], cur, stp, 100);
			FillRect(screenDC, &yeet, CreateSolidBrush(RGB(cur[0], cur[1], cur[2])));
		}
	}
}
