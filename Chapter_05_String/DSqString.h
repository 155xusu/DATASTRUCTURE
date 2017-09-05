typedef struct {
	char *str;
	int length;
}DSqString;

//����ֵ����
bool StrAssign_Sq(DSqString &S, char *chars) {
	int i, j;
	char *c;
	for (i = 0, c = chars; *c; i++, c++);
	if (!i) {
		S.str = NULL; S.length = 0;
	}
	else {
		if (!(S.str = (char*)malloc(i * sizeof(char)))) return false;
		for (j = 0; j<i; j++) S.str[j] = chars[j];
		S.length = i;
	}
	return true;
}

//�����Ʋ���
bool StrCopy_Sq(DSqString &S, DSqString T) {
	//��˳��T���Ƶ�
	int i;
	if (S.str) free(S.str);
	if (!T.length) {
		S.str = NULL; S.length = 0;
	}
	else {
		if (!(S.str = (char*)malloc(T.length * sizeof(char)))) return false;
		for (i = 0; i<T.length; i++) {
			S.str[i] = T.str[i];
			S.length = T.length;
		}
	}
	return true;
}

//�󴮳��Ĳ���
int StrLength_Sq(DSqString s) {
	return s.length;
}

//���Ƚϲ���
int StrCompare_Sq(DSqString S, DSqString T) {
	int i = 0;
	while (i<S.length&&i<T.length) {
		if (S.str[i]>T.str[i])  return 1;
		else if (S.str[i]<T.str[i]) return -1;
		i++;
	}
	if (i<S.length) return 1;
	else if (i<T.length) return -1;
	return 0;
}

//�����Ӳ���
bool StrConcat_Sq(DSqString &S, DSqString T) {
	int i;
	if (T.length) {
		if (!(S.str = (char*)realloc(S.str, (S.length + T.length) * sizeof(char))))  return false;
		for (i = 0; i<T.length; i++) S.str[S.length + i] = T.str[i];
		S.length += T.length;
	}
	return true;
}

//ȡ�Ӵ�����
bool SubString_Sq(DSqString S, DSqString &Sub, int pos, int len) {
	int i;
	if (pos<0 || pos>S.length - 1 || len<0 || len>S.length - pos) {
		return false;
	}
	if (Sub.str) free(Sub.str);
	if (!len) { Sub.str = NULL; Sub.length = 0; }
	else {
		if (!(Sub.str = (char*)malloc(len * sizeof(char)))) return false;
		for (i = 0; i<len; i++) {
			Sub.str[i] = S.str[pos + i];
		}
		Sub.length = len;
	}
	return true;
}

//�Ӵ��Ķ�λ����
bool Index_Sq(DSqString S, DSqString T, int &pos) {
	//���鴮�в����Ƿ�����Ӵ�T,�����ڣ�����pos������λ��
	int i = 0, j = 0;
	while (i<S.length&&j<T.length) {
		if (S.str[i] == T.str[j]) {
			i++; j++;
		}
		else {
			i = i - j + 1;  //����
			j = 0;
		}
	}
	if (j == T.length) {
		pos = i - T.length;
		return true;
	}
	else {
		return false;
	}
}

//�����Ӵ��Ĳ���
bool StrInsert_Sq(DSqString &S, int pos, DSqString T) {
	//��˳��S�ĵ�pos���ַ�֮ǰ����T
	int i;
	if (pos<0 || pos>S.length) return false;
	if (T.str) {
		if (!(S.str = (char*)realloc(S.str, (S.length + T.length) * sizeof(char))))
			return false;
		for (i = S.length - 1; i >= pos; i--) {
			S.str[i + T.length] = S.str[i];
		}
		for (i = 0; i<T.length; i++) {
			S.str[pos + i] = T.str[i];
		}
		S.length += T.length;
	}
	return true;
}

//ɾ���Ӵ��Ĳ���
bool StrDelete_Sq(DSqString &S, int pos, int len) {
	//��˳��S�ĵ�pos���ַ���ʼɾ������Ϊlen���Ӵ���������ɾ�����S
	int i;
	if (pos<0 || len<0 || pos + len>S.length) return false;
	for (i = pos + len; i <= S.length - 1; i++) {
		S.str[i - len] = S.str[i];
	}
	S.str = (char*)realloc(S.str, (S.length - len) * sizeof(char));
	S.length -= len;
	return true;
}

//�û��Ӵ�����
void StrReplace_Sq(DSqString &S, DSqString T, DSqString V) {
	//�ô�v�û�����s�г��ֵ�������T��ȵĲ��ص�zichuan
	int pos;
	while (Index_Sq(S, T, pos)) {
		StrDelete_Sq(S, pos, T.length);
		StrInsert_Sq(S, pos, V);
	}
}

//���ı�������
void StrTraveres_Sq(DSqString S) {
	int i;
	for (i = 0; i<StrLength_Sq(S); i++) {
		cout << S.str[i];
	}
	cout << endl;
}

void DestroyString_Sq(DSqString &S) {
	free(S.str);
	S.str = NULL;
	S.length = 0;
}

void visualization(DSqString S, char* filename)
{   int temp;
	FILE *stream;  
    if( NULL == (stream = fopen(filename, "w")) )  
    {  
	   printf("open file error");  exit(0);  
    }  
    fprintf(stream, "digraph\n{\n node [shape = record] �� [label =\"");  
	for(int i=0;i<S.length-1;i++){
		fprintf(stream, "%c|",S.str[i]);
	}
	fprintf(stream, "%c\"",S.str[S.length-1]);
	fprintf(stream, "];}"); 
	fclose(stream);  
	system("dot -Tpng show.dot -o show.png");
	system("show.png");
}





