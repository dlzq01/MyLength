#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

#define LLEN 50

char dan[LLEN][LLEN];
double mm[LLEN];

bool isFirst(char* str) {
	for(int i = 0; str[i] != '\0'; i++) {
		if('=' == str[i]) return true;
	}
	return false;
}

bool sscmp(char* s1, char* s2) {
	int len1, len2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	for(int i = 0; i < len1; i++) {
		if(s1[i] != s2[i]) return false;
	}
	return true;
}

int find(char* str, int index) {
	for(int i = 0; i < index; i++) {
		if(sscmp(dan[i], str)) {
			return i;
		}
	}
	return -1;
}

int main() {
	char str[LLEN];
	int index;
	FILE* fp;
	index = 0;
	freopen("input.txt", "r", stdin);
	fp = freopen("output.txt", "w", stdout);
	fprintf(fp, "dlzq01@qq.com\n\n");
	while(gets(str)) {
		if(str[0] == '\r') continue;
		int n1;
		double n2, ans;
		char stmp1[LLEN], stmp2[LLEN];
		ans = 0;
		if(isFirst(str)) {
			sscanf(str, "%d%s = %lf%s", &n1, stmp1, &n2, stmp2);
			strcpy(dan[index], stmp1);
			mm[index++] = n2;
		}
		else {
			int nindex = 0;
			int fflag, nfflag;
			int len1 = strlen(stmp1);
			int len2 = strlen(stmp2);
			fflag = 1;
			while(str[nindex] != '\0') {
				sscanf(str+nindex, "%s%s", stmp1, stmp2);
				n2 = atof(stmp1);
				nindex += len1 + len2 + 2;
				switch(str[nindex+1]) {
					case '\0':
						nfflag = 0;
						break;
					case '+':
						nfflag = 1;
						break;
					case '-':
						nfflag = -1;
						break;
					default:
						break;
				}
				nindex += 2;
				if(!strcmp(stmp2, "feet")) {
					strcpy(stmp2, "foot");
				}
				int num = find(stmp2, index);
				if(1 == fflag) {
					ans = ans + n2*mm[num];
					fflag = nfflag;
				}
				else if(-1 == fflag) {
					ans = ans - n2*mm[num];
					fflag = nfflag;
				}
				if(0 == nfflag) {
					break;
				}
			}

			fprintf(fp, "%.2lf m\n", ans);

		}
		memset(str, 0, sizeof(str));
	}
	fclose(fp);
	fclose(stdout);
	fclose(stdin);
	return 0;
}

