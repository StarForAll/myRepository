#include "stdafx.h"
#include "TXTEditor.h"


TXTEditor::TXTEditor()
{
}


TXTEditor::~TXTEditor()
{
}
BOOLEAN TXTEditor::ReadFile(WCHAR* pathName) {
	wifstream inFile(pathName, ios::in);   /////
	if (!inFile) {
		return FALSE;
	}
	inFile.imbue(locale(locale(), "", LC_CTYPE));
	wstring buffer;
	while (inFile.good()) {
		std::getline(inFile, buffer);
		FileContent.push_back(buffer);
	}
	inFile.close();
	return TRUE;
}

BOOLEAN TXTEditor::WriteFile(WCHAR* pathName, WCHAR* fileLines) {
	if (fileLines != NULL) {
		wstringstream mySS;
		mySS << fileLines;
		wofstream outFile(pathName,ios::out|ios::trunc);
		if (!outFile) {
			return FALSE;
		}
		outFile.imbue(locale(locale(), "", LC_CTYPE));
		wstring myString = mySS.str();
		outFile.write(myString.c_str(), wcslen(fileLines));
		outFile.close();
	}
	return TRUE;
}

vecLinesContainer TXTEditor::getFileLines(WCHAR* pathName) {
	ReadFile(pathName);
	return FileContent;
}