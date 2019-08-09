#pragma once
#include<string.h>

class Language {
	char lang[10];
	int view;
	bool isTrue(char L[], int x);
public:
	Language() :lang(""), view(0) {}
	Language(char L[], int x) {
		if (isTrue(L, x)) {
			strcpy(lang, L);
			view = x;
		}
	}
};