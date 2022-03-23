#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <fstream>
#include <aspose_ocr.h>

void PerformOcrOnImage() {
	std::ofstream fout;
	fout.open("output.txt");

	if (!fout.is_open()) {
		std::wcout << "Error. File is not open!" << std::endl;
	}
	else {
		std::string image_path = "../Source/hello_html_md3276b7.png";

		const size_t len = 4096;
		wchar_t buffer[len] = { 0 };

		size_t size = aspose::ocr::page(image_path.c_str(), buffer, len);

		std::wcout << buffer << L"\n";
		std::wcout << "PerformOcrOnImage executed successfully" << L'\n';

		std::wstring ws(buffer);
		std::string str(ws.begin(), ws.end());

		for (int i = 0; i < str.length(); ++i) {
			fout << str[i];
		}	

		fout.close();
	}	
}

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	PerformOcrOnImage();
	std::wcout << "\nProgram Finished. Press Enter to Exit....";
}