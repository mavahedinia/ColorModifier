// 
// BeeSoft presents!
// Coded by MohammadAmin Vahedinia (MrRobot)
// This is a library to control the output text color and style (limited!!!)
//

#include <bits/stdc++.h>

using namespace std;

namespace ColorModifier{
	enum foregroundColorCode {
		Black = 30,
		Red = 31,
		Green = 32,
		Yellow = 33,
		Blue = 34,
		Magenta = 35,
		Cyan = 36,
		White = 37,
		Default = 39
	};

	enum textMode {
		Bold = 1,
		Dim = 2,
		Underline = 4,
		Hidden = 8,
		RST = 0
	};

	textMode totextMode(int i) {
		if (i == 1) return Bold;
		else if (i == 2) return Dim;
		else if (i == 4) return Underline;
		else if (i == 8) return Hidden;
		else return RST;
	}

	class Printer {
		foregroundColorCode def;
		textMode defText;
		public:
		// Initializers

		Printer() {
			def = Default;
			defText = RST;
		}

		Printer(foregroundColorCode _color) {
			def = _color;
			defText = RST;
		}

		Printer(textMode _text) {
			def = Default;
			defText = _text;
		}

		Printer(foregroundColorCode _color, textMode _text){ 
			def = _color;
			defText = _text;
		}

		//Setting functions

		void setColor(foregroundColorCode color) {
			cout << "\033[" << color << "m";
		}

		void resetColor() {
			cout << "\033[" << def << "m";
		}

		void setStyle(textMode text) {
			cout << "\033[" << text << "m";
		}

		void setStyle(int text) {
			if (text == 0) setStyle(RST);
			for(int i = 0; i < 4; i++) {
				if (text >> i & 1) {
					setStyle(totextMode(1 << i));
				}
			}
		}

		void resetStyle() {
			cout << "\033[" << defText << "m";
		}

		void resetAll() {
			resetStyle();
			resetColor();
		}

		// Printing Functions

		void message(string s) {
			cout << s;
		}

		void message(string s, foregroundColorCode color) {
			setColor(color);
			cout << s;
			resetColor();
		}

		void message(string s, foregroundColorCode color, textMode mode) {
			setStyle(mode);
			message(s, color);
			resetStyle();
		}

		void message(string s, foregroundColorCode color, int mode) {
			setStyle(mode);
			message(s, color);
			resetStyle();
		}

	};

	Printer printer;

	// Set Color and style Functions

	void setColor(foregroundColorCode color){
		printer.setColor(color);
	}

	void setStyle(textMode mode){
		printer.setStyle(mode);
	}

	void setStyle(int text) {
		printer.setStyle(text);
	}

	void resetColor() {
		printer.resetColor();
	}

	void resetStyle() {
		printer.resetStyle();
	}

	void resetAll() {
		resetStyle();
		resetColor();
	}

	// Printing Functions

	void message(string s) {
		printer.message(s);
	}

	void message(string s, foregroundColorCode color) {
		printer.message(s, color);
	}

	void message(string s, foregroundColorCode color, textMode mode) {
		printer.message(s, color, mode);
	}

	void message(string s, foregroundColorCode color, int mode) {
		printer.message(s, color, mode);
	}

	// Destructor

	void destroyPrinter() {
		resetAll();
	}

}
