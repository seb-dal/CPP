#pragma once

#include <cstdlib>

#include "ConsoleUtility.hpp"
#include "ConsoleCursorControler.hpp"

static double random(int min, int max) {
	double r0 = ((double)rand()) / static_cast<double>(RAND_MAX);
	return min + (max - min) * r0;
}

class drop {
#if 1
	static constexpr char symbols[106] = "0123456789/*-+azertyuiop^$*ùmlkjhgfdsqwxcvbn,;:!&é\"'(-è_çà)='~#{[|`\\^@]}NBVCXWQSDFGHJKLMPOIUYTREZA¨£µ%§.?";
	static constexpr int len_symbols = 105;
#else
	static constexpr char symbols[3] = "01";
	static constexpr int len_symbols = 2;
#endif

private:
	static short h, w;
	short x, len, y;
	int start, step;

	void init() {
		this->x = random(0, w);
		this->len = random(3, 16);
		this->y = random(-h - len, -len);
		this->start = random(0, len_symbols - 1);
		this->step = random(1, len_symbols / 2);
	}
public:
	static void INITIALIZE() {
		CU::getTerminalSize(w, h);
		h -= 2;
	}

	drop() {
		init();
	}
	~drop() {}

	void print() {
		if (y >= 0) {
			CCC::setCurPos(x, y);
			std::cout << " ";
		}

		if (y + len < h && y + len >= 0) {
			CCC::setCurPos(x, y + len);
			std::cout << symbols[(start + len * step) % len_symbols];
		}

		y += 1;
		start = (start + step) % len_symbols;

		if (y - 2 >= h) {
			init();
		}
	}

};

short drop::h = 0, drop::w = 0;