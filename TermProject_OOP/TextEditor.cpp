#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define MAX_LINE 19	// 0~19 줄 인덱스
#define MAX_BYTE 75	// 1~75 글자 수

static string msg = "";		// 콘솔메세지
void console(string msg) {	// 콘솔 출력 함수
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "n: 다음페이지, p: 이전페이지, i: 삽입, d: 삭제, c: 변경, s: 찾기, t: 저장 후 종료" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "(콘솔메세지) " << msg << endl; 
	cout << "-------------------------------------------------------------------------------------------" << endl;
}

class TextEditor {			// 텍스트 에디터
private:
	vector<string> vec;			// 전체 내용 저장
	static TextEditor* editor;	// SingleTon 공용 객체
	int page = 0;				// 현재 페이지 수
	bool last = false;			// 마지막 페이지인지 나타내는 부울 변수
	TextEditor(vector<string> vec = {}) { this->vec = vec; }	// 생성자
public:
	vector<string> getVector() { return vec; }					// 전체 내용 반환
	void setVector(vector<string> vec) { editor->vec = vec; }	// 전체 내용 저장
	int getPage() { return page; }								// 페이지 수 반환
	void nextPage() { page++; }									// 페이지 수 1 증가
	void prevPage() { page--; }									// 페이지 수 1 감소
	bool isLast() { return last; }								// last 변수 반환
	void setLast(bool last) {editor->last = last;}				// last 변수 설정
	static TextEditor* getInstance() {							// SingleTon 객체 생성 여부 확인
		if (editor == NULL) editor = new TextEditor();
		return editor;
	}

	void ToNextPage();				// 다음 페이지로(n)
	void ToPrevPage();				// 이전 페이지로(p)
	void Insert(string word);		// 단어 삽입하기(i)
	void Delete(string word);		// 단어 삭제하기(d)
	void Change(string word);		// 단어 교체하기(c)
	void Search(string word);		// 단어 탐색하기(s)
	void SaveAndExit();				// 저장하고 종료(t)
};
TextEditor* TextEditor::editor = 0;	// 전역변수 초기화

void TextEditor::ToNextPage() {		// 다음 페이지로(n)
	if (editor->isLast()) return;	// 마지막 페이지면 리턴

	vector<string> vec = editor->getVector();
	bool pageChange = false;						// 목표 페이지 확인
	if (editor->getPage() == 0) pageChange = true;	// 첫 시작은 무조건 한 장 넘겨야함

	system("cls");									// 콘솔 초기화
	int lineNum = 0, lineByte = MAX_BYTE + 1;		// 현재 줄 넘버, 현재 줄 글자 수
	string firstWord = "";							// 넘어온 첫 단어
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		string nowWord = *it;						// 현재 확인중인 단어
		if (pageChange) {							// 목표 페이지인 경우
			if (lineByte + nowWord.length() > MAX_BYTE) {	// 줄이 넘어가는 경우
				cout << endl;						// 줄바꿈
				if (lineNum++ > MAX_LINE) break;	// 20줄 넘어가면 종료
				if (lineNum < 10) cout << " ";		// 10번째 줄 미만인 경우
				cout << lineNum << "| ";			// 줄 번호 표시
				lineByte = 0;						// 현재 줄 글자 수 초기화
			}
			if (firstWord != "") {					// 넘어온 첫 단어가 있을 경우
				cout << firstWord + " ";			// 이것부터 출력
				firstWord = "";						// 초기화
			}
			cout << nowWord + " ";					// 현재 확인중인 단어 출력
		}
		else {										// 페이지가 넘어가지 않은 경우
			if (lineByte + nowWord.length() > MAX_BYTE) {	// 줄이 넘어가는 경우
				lineByte = 0;						// 줄 글자 수 초기화
				if (lineNum > MAX_LINE * editor->getPage()) {	// 목적 페이지 확인 (현재 페이지에 따라)
					pageChange = true;				// 목표 페이지 도달
					lineByte = MAX_BYTE + 1;		// 다음 줄부터 출력할 수 있게 초과값
					lineNum = 0;					// 줄 넘버 0으로 초기화
					firstWord = nowWord;			// 첫 단어로 넘긴다
					continue;						// 건너뛰기
				}
				lineNum++;							// 목적 페이지 도달 안했다면 줄 넘버 증가
			}
		}
		lineByte += (int)nowWord.length() + 1;		// 줄 글자 수에 단어 길이 + 공백 한 칸 길이 덧셈

		if (it + 1 == vec.end()) {										// 마지막 단어에 도달한 경우
			vector<string> reverse_vec = editor->getVector();			// 전체 내용 불러오기
			int reverse_lineNum = 0, reverse_lineByte = MAX_BYTE + 1;	// 현재 줄 넘버, 현재 줄 글자 수
			vector<string> lastPage;									// 마지막 페이지는 따로 저장
			for (vector<string>::reverse_iterator rit = reverse_vec.rbegin(); rit != reverse_vec.rend(); ++rit) {
				string reverse_nowWord = *rit;							// 현재 확인중인 단어
				if (reverse_lineByte + reverse_nowWord.length() > MAX_BYTE) {	// 단어 포함 시 줄이 넘어가는 경우
					if (reverse_lineNum++ > MAX_LINE) break;			// 줄이 20줄을 넘기는 경우 중단
					reverse_lineByte = 0;								// 현재 줄 글자 수 초기화
				}
				lastPage.emplace_back(reverse_nowWord);					// 단어 하나씩 추가
				reverse_lineByte += reverse_nowWord.length() + 1;		// 줄 글자 수에 단어 길이 + 공백 한 칸 길이 덧셈
			}

			system("cls");					// 콘솔 초기화
			string reverse_firstWord;		// 넘어간 첫 단어
			reverse_lineNum = 0, reverse_lineByte = MAX_BYTE + 1;	// 현재 줄 넘버, 현재 줄 글자 수 다시 초기화
			for (vector<string>::reverse_iterator rit = lastPage.rbegin(); rit != lastPage.rend(); ++rit) {
				string reverse_nowWord = *rit;	// 현재 확인중인 단어
				if (reverse_lineByte + reverse_nowWord.length() > MAX_BYTE) {	// 단어 포함 시 줄이 넘어가는 경우
					cout << endl;								// 줄 바꿈
					if (reverse_lineNum++ > MAX_LINE) break;	// 20줄 넘어간 경우 중단	
					if (reverse_lineNum < 10) cout << " ";		// 10줄 미만인 경우 맞춤
					cout << reverse_lineNum << "| ";			// 줄 번호 표시
					reverse_lineByte = 0;						// 현재 줄 글자 수 초기화
				}
				if (reverse_firstWord != "") {					// 넘어온 첫 단어가 있다면
					cout << reverse_firstWord + " ";			// 이것부터 출력
					reverse_firstWord = "";						// 초기화
				}
				cout << reverse_nowWord + " ";					// 현재 단어 출력
				reverse_lineByte += (int)reverse_nowWord.length() + 1;	// 줄 글자 수에 단어 길이 + 공백 한 칸 길이 덧셈
			}
			editor->setLast(true); // 마지막 페이지로 설정
		}
	}
	cout << endl;		// 줄바꿈
	editor->nextPage();	// 페이지 수 1 증가
}

void TextEditor::ToPrevPage() {			// 이전 페이지로(p)
	if (editor->getPage() == 1) return;	// 첫 페이지일 경우 반환

	vector<string> vec = editor->getVector();		// 전체 내용 불러오기
	bool pageChange = false;						// 목표페이지에 도달했는지
	if (editor->getPage() == 2) pageChange = true;	// 2페이지면 다음이 1페이지라 바로 도달 

	system("cls");									// 콘솔 초기화
	editor->setLast(false);							// 마지막 페이지 해제
	int lineNum = 0, lineByte = MAX_BYTE + 1;		// 현재 줄 넘버, 현재 줄 글자 수
	string firstWord = "";							// 넘어온 첫 단어
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		string nowWord = *it;	 // 현재 확인중인 단어
		if (pageChange) {		// 목표 페이지 도달
			if (lineByte + nowWord.length() > MAX_BYTE) {	// 줄이 넘어가는 경우
				cout << endl;						// 줄바꿈
				if (lineNum++ > MAX_LINE) break;	// 20줄 넘는 경우 종료
				if (lineNum < 10) cout << " ";		// 10줄 미만 시 맞춤
				cout << lineNum << "| ";			// 줄 번호 표시
				lineByte = 0;						// 현재 줄 글자 수 초기화
			}
			if (firstWord != "") {					// 넘어온 첫 글자가 있을 경우
				cout << firstWord + " ";			// 이것부터 출력
				firstWord = "";						// 초기화
			}
			cout << nowWord + " ";					// 현재 단어 출력
		}
		else {										// 목표 페이지 도달 못한 경우
			if (lineByte + nowWord.length() > MAX_BYTE) {	// 줄이 넘어가는 경우
				lineByte = 0;						// 현재 줄 글자 수 초기화
				if (lineNum > MAX_LINE * (getPage() - 2)) {	// 전전페이지의 다음 시작일 경우
					pageChange = true;				// 목표 페이지 도달
					lineByte = MAX_BYTE + 1;		// 현재 줄 글자 수 초과로 초기화
					lineNum = 0;					// 현재 줄 넘버 초기화
					firstWord = nowWord;			// 첫 단어로 넘기기
					continue;						// 건너뛰기
				}
				lineNum++;							// 도달 못한 경우 줄 넘버 증가
			}
		}
		lineByte += (int)nowWord.length() + 1;		// 줄 글자 수에 단어 길이 + 공백 한 칸 길이 덧셈
	}
	cout << endl;		// 줄 바꿈
	editor->prevPage();	// 페이지 수 1 감소
}

void TextEditor::Insert(string word) {		// 단어 삽입하기(i)
	string input = word;	
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());	// 입력 속 공백제거
	string Line, Index, InputWord;	// 줄, 인덱스, 삽입될 단어
	int split = 0;	// 구별용 split
	for (int i = 2; i < input.length(); i++) {
		if (split == 0) {	// 줄 입력 중
			if (input[i] == ',') {
				split = 1;	// 이제부터 인덱스
				continue;
			}
			if (input[i] < '0' || input[i] > '9') {	// 입력 확인
				msg = "올바르지 않은 입력입니다. 다시 입력해주세요.";
				return;
			}
			Line += (char)input[i];	// 줄 값
		}
		else if (split == 1) {	// 인덱스 입력 중
			if (input[i] == ',') {
				split = 2;		// 이제부터 삽입될 단어
				continue;
			}
			if (input[i] < '0' || input[i] > '9') {	// 입력 확인
				msg = "올바르지 않은 입력입니다. 다시 입력해주세요.";
				return;
			}
			Index += (char)input[i];	// 인덱스 값
		}
		else if(i != input.length() - 1) InputWord += (char)input[i]; // 삽입될 단어
	}

	int line = stoi(Line);		// 정수화
	int index = stoi(Index);	// 정수화
	if (line > MAX_LINE + 1) {		// 입력 줄이 20 초과일 경우
		msg = "줄은 20번째까지만 출력 가능합니다.";
		return;
	}
	if (index > MAX_BYTE) {		// 입력 인덱스가 75 초과일 경우
		msg = "한 줄 당 75바이트씩(공백 포함) 존재합니다.";
		return;
	}

	vector<string> vec = editor->getVector();		// 전체 불러오기
	bool pageChange = false;						// 페이지 도달했는가
	if (editor->getPage() == 1) pageChange = true;	// 첫페이지일 경우 이미 도달
	int lineNum = 0, lineByte = MAX_BYTE + 1;		// 현재 줄 넘버, 현재 줄 글자 수
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		string nowWord = *it;		// 현재 확인 중인 단어
		if (pageChange) {			// 페이지 도달한 경우
			if (lineByte + nowWord.length() > MAX_BYTE) {	// 줄이 넘어가는 경우
				if (lineNum++ > MAX_LINE) break;			// 20줄 초과인경우 종료
				lineByte = 0;		// 현재 줄 글자 수 초기화
			}
			if (lineNum == line) {	// 삽입하려는 줄 넘버에 도달한 경우
				if (lineByte <= index && index <= lineByte + nowWord.length() + 1) {	// 단어 길이 속에 인덱스가 포함되면
					index -= lineByte;	// index를 조절
					string inserted;	// 현재 단어에 삽입된 단어
					for (int i = 0; i < nowWord.length(); i++) {
						if (i == index - 1) inserted += nowWord[i] + InputWord;	// 인덱스 도달 시 삽입될 단어와 함께 추가
						else inserted += nowWord[i];							// 아닌 경우 그냥 추가
					}
					*it = inserted;		// 삽입된 단어로 값 변경
					break;				// 종료
				}
			}
		}
		else {		// 페이지에 도달하지 못한 경우
			if (lineByte + nowWord.length() > MAX_BYTE) {		// 줄이 넘어가는 경우
				lineByte = 0;	// 현재 줄 글자 수 초기화
				if (lineNum > MAX_LINE * (editor->getPage() - 1)) {	// 이전 페이지에서 넘어와서 도달한 경우
					pageChange = true;			// 페이지 도달로 변경
					lineByte = MAX_BYTE + 1;	// 현재 줄 글자 수 초과로 초기화
					lineNum = 0;				// 줄 넘버 초기화
					continue;					// 건너뛰기
				}
				lineNum++;						// 도달하지 못한 경우 줄 넘버 1 증가
			}
		}
		lineByte += (int)nowWord.length() + 1;	// 줄 글자 수에 단어 길이 + 공백 한 칸 길이 덧셈
	}
	TextEditor::editor->setVector(vec);		// 삽입된 vector로 재설정

	if (editor->getPage() == 1) {		// 첫 페이지인 경우
		editor->nextPage();				// 페이지수 임의로 1 증가했다가
		system("cls");					// 콘솔 초기화 후
		editor->ToPrevPage();			// 이전 페이지로 돌아오는 것으로 새로고침
	}
	else {								// 첫 페이지가 아닌 경우
		editor->prevPage();				// 페이지수 임의로 1 감소했다가
		system("cls");					// 콘솔 초기화 후
		editor->ToNextPage();			// 다음 페이지로 돌아오는 것으로 새로고침
	}
}

void TextEditor::Delete(string word) {		// 단어 삭제하기(d)
	string input = word;
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());	// 입력 속 공백 제거
	string Line, Index, Byte;		// 줄, 인덱스, 바이트
	int split = 0;	// 입력 구분용
	for (int i = 2; i < input.length(); i++) {
		if (split == 0) {		// 줄 입력중
			if (input[i] == ',') {
				split = 1;		// 이제부터 인덱스 입력
				continue;
			}
			if (input[i] < '0' || input[i]>'9') {	// 입력 확인
				msg = "올바르지 않은 입력입니다. 다시 입력해주세요.";
				return;
			}
			Line += (char)input[i];	// 줄 입력
		}
		else if (split == 1) {	// 인덱스 입력중
			if (input[i] == ',') {
				split = 2;		// 이제부터 바이트 입력
				continue;
			}
			if (input[i] < '0' || input[i]>'9') {	// 입력 확인
				msg = "올바르지 않은 입력입니다. 다시 입력해주세요.";
				return;
			}
			Index += (char)input[i];	// 인덱스 입력
		}
		else Byte += (char)input[i];	// 바이트 입력
	}

	int line = stoi(Line);		// 정수화
	int index = stoi(Index);	// 정수화
	if (line > MAX_LINE + 1) {		// 입력 줄이 20 초과일 경우
		msg = "줄은 20번째까지만 출력 가능합니다.";
		return;
	}
	if (index > MAX_BYTE) {		// 입력 인덱스가 75 초과인 경우
		msg = "한 줄 당 75바이트씩(공백 포함) 존재합니다.";
		return;
	}
	int byte;
	try {byte = stoi(Byte);}
	catch (exception e) {	// 바이트로 정수 이외의 입력인 경우 
		msg = "바이트는 숫자만 입력가능합니다.";
		return;
	}
	
	vector<string> vec = editor->getVector();		// 전체 내용 불러오기
	bool pageChange = false;						// 페이지에 도달했는가
	if (editor->getPage() == 1) pageChange = true;	// 첫 페이지면 이미 도달
	int lineNum = 0, lineByte = MAX_BYTE + 1;		// 현재 줄 넘버, 현재 줄 글자 수
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		string nowWord = *it;		// 현재 확인 중인 단어
		if (pageChange) {			// 페이지에 도달한 경우
			if (lineByte + nowWord.length() > MAX_BYTE) {	// 줄이 넘어간 경우
				if (lineNum++ > MAX_LINE) break;			// 20줄 넘어간 경우 종료
				lineByte = 0;		// 줄 글자 수 초기화
			}
			if (lineNum == line) {	// 삭제할 줄에 도달한 경우
				if (lineByte <= index && index <= lineByte + nowWord.length() + 1) { // 단어 길이 속에 인덱스가 포함되면
					index -= lineByte;	// 인덱스 조절
					string deleted;		// 삭제된 단어
					for (int i = 0; i < nowWord.length(); i++) {
						if (i == index - 1) i += byte - 1;	// 바이트만큼 삭제
						else deleted += nowWord[i];			// 나머진 다시 추가
					}
					if (deleted == "") vec.erase(it);		// 전체 삭제 된 경우 벡터에서 통채로 지움
					else *it = deleted;						// 아닌 경우 값 수정
					break;									// 종료
				}
			}
		}
		else {			// 페이지에 도달하지 않은 경우
			if (lineByte + nowWord.length() > MAX_BYTE) {	// 줄이 넘어간 경우
				lineByte = 0;		// 줄 글자 수 초기화
				if (lineNum > MAX_LINE * (editor->getPage() - 1)) {	// 이전페이지에서 넘어온 경우
					pageChange = true;			// 페이지 도달로 수정
					lineByte = MAX_BYTE + 1;	// 현재 줄 글자 수 초과로 초기화
					lineNum = 0;				// 현재 줄 넘버 초기화
					continue;					// 건너뛰기
				}
				lineNum++;						// 도달하지 않은 경우 줄 넘버 1 증가
			}
		}
		lineByte += (int)nowWord.length() + 1;	// 줄 글자 수에 단어 길이 + 공백 한 칸 길이 덧셈
	}
	TextEditor::editor->setVector(vec);		// 삭제된 벡터로 재설정

	if (editor->getPage() == 1) {		// 첫 페이지인 경우
		editor->nextPage();				// 페이지수 임의로 1 증가했다가
		system("cls");					// 콘솔 초기화 후
		editor->ToPrevPage();			// 이전 페이지로 돌아오는 것으로 새로고침
	}
	else {								// 첫 페이지가 아닌 경우
		editor->prevPage();				// 페이지수 임의로 1 감소했다가
		system("cls");					// 콘솔 초기화 후
		editor->ToNextPage();			// 다음 페이지로 돌아오는 것으로 새로고침
	}
}

void TextEditor::Change(string word) {		// 단어 교체하기(c)
	string input = word;
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());	// 입력 속 공백 제거
	string from = "", to = "";	// 이전 단어, 수정된 단어
	bool isFirst = true;	// 입력 구분용
	for (int i = 2; i < input.length() - 1; i++) {
		if (isFirst) {		// 이전 단어 입력중
			if (input[i] == ',') {
				isFirst = false;	// 이제부터 수정된 단어
				continue;
			}
			if (input[i] >= '0' && input[i] <= '9') {	// 입력 확인
				msg = "올바르지 않은 입력입니다. 다시 입력해주세요.";
				return;
			}
			from += (char)input[i];	// 이전 단어 입력
		}
		else {	// 수정된 단어 입력중
			if (input[i] >= '0' && input[i] <= '9') { // 입력 확인
				msg = "올바르지 않은 입력입니다. 다시 입력해주세요.";
				return;
			}
			to += (char)input[i];	// 수정된 단어 입력
		}
	}

	vector<string> vec = editor->getVector();	// 전체 내용 불러오기
	vector<string> changed;		// 수정된 전체 내용
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it == from || (*it).find(from) != string::npos) {	// 이전 단어와 일치하거나 이전 단어를 포함하는 경우
			string changedWord;		// 수정된 단어
			for (int i = 0; i < (*it).length(); i++) {
				if (i == (*it).find(from)) {		// 이전 단어가 시작되는 인덱스인 경우
					changedWord += to;				// 수정된 단어로 추가
					i += from.length() - 1;			// 이전 단어만큼 건너뛰기
				}
				else changedWord += (*it)[i];		// 그 외의 글자는 그냥 추가
			}
			changed.emplace_back(changedWord);		// 수정된 전체 내용에 추가
		}
		else changed.emplace_back(*it);				// 일치나 포함하지 않으면 그냥 추가
	}
	TextEditor::editor->setVector(changed);			// 수정된 벡터로 재설정

	if (editor->getPage() == 1) {		// 첫 페이지인 경우
		editor->nextPage();				// 페이지수 임의로 1 증가했다가
		system("cls");					// 콘솔 초기화 후
		editor->ToPrevPage();			// 이전 페이지로 돌아오는 것으로 새로고침
	}
	else {								// 첫 페이지가 아닌 경우
		editor->prevPage();				// 페이지수 임의로 1 감소했다가
		system("cls");					// 콘솔 초기화 후
		editor->ToNextPage();			// 다음 페이지로 돌아오는 것으로 새로고침
	}
}

void TextEditor::Search(string word) {		// 단어 탐색하기(s)
	string input = word;
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());	// 입력 공백 제거
	string search_word = "";	// 찾을 단어
	for (int i = 2; i < input.length() - 1; i++) search_word += input[i];	// 찾을 단어 입력

	system("cls");	// 콘솔 초기화
	cout << endl;	// 줄바꿈
	vector<string> vec = editor->getVector();	// 전체 내용 불러오기
	int lineNum = 1, lineByte = 0;				// 현재 줄 넘버, 현재 줄 글자 수
	bool found = false, pageChange = false;		// 찾은 경우, 페이지에 도달한 경우
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		string nowWord = *it;					// 현재 확인 중인 단어
		if (found == false) {			// 못 찾은 경우
			if (nowWord == search_word || nowWord.find(search_word) != string::npos) {	// 일치하거나 포함중인 경우
				found = true;			// 찾은 걸로 수정
				cout << " " << lineNum << "| " << nowWord << " ";	// 첫 문장 시작
				lineByte += (int)nowWord.length() + 1;	// 줄 글자 수에 단어 길이 + 공백 한 칸 길이 덧셈
			}
		}
		else {							// 찾은 경우
			if (lineByte + nowWord.length() > MAX_BYTE) {	// 줄이 넘어가는 경우
				cout << endl;						// 줄 바꿈
				if (lineNum++ > MAX_LINE) break;	// 20줄 초과인 경우 종료
				if (lineNum < 10) cout << " ";		// 10줄 미만인 경우 맞춤
				cout << lineNum << "| ";			// 줄 번호 표시
				lineByte = 0;						// 현재 줄 글자 수 초기화
			}
			cout << nowWord + " ";					// 현재 단어 출력
			lineByte += (int)nowWord.length() + 1;	// 줄 글자 수에 단어 길이 + 공백 한 칸 길이 덧셈
		}
	}
	if (!found) msg = "일치하는 결과가 없습니다.";	// 못 찾은 경우
}

void TextEditor::SaveAndExit() {		// 저장하고 종료(t)
	ofstream stream;						// 파일 쓰기로 선언
	stream.open("test.txt", ios::trunc);	// test.txt를 지우고 다시 쓰기
	if (stream.fail()) {					// 실패한 경우 종료
		cout << "save file opening failed" << endl;
		exit(1);
	}
	vector<string> save_contexts = editor->getVector();	// 내용 전체 불러오기
	for (vector<string>::iterator v = save_contexts.begin(); v != save_contexts.end(); v++) stream << *v + " ";	// 단어 + 공백 한 칸으로 저장
	stream.close();		// 파일 닫기
}

int main() {
	ifstream file;			// 파일 읽기로 선언
	file.open("test.txt");	// file 읽어오기
	if (file.fail()) {		// 실패한 경우 종료
		cout << "input file opening failed" << endl;
		exit(1);
	}

	vector<string> texts;	// 파일 전체 저장
	string word;			// 파일 속 단어
	while (file >> word) texts.emplace_back(word);	// 단어 단위로 읽어와 저장
	TextEditor::getInstance()->setVector(texts);	// 객체 속 벡터에 저장
	file.close();			// 파일 닫기

	TextEditor::getInstance()->ToNextPage();	// 첫 페이지 출력
	string order;	// 사용자 입력
	while (true) {
		console(msg);	// 콘솔 메세지 출력
		cout << "입력 : ";
	 
		getline(cin, order);	// 사용자 입력
		switch (order[0]) {		// 입력에 따라
		case 'n':	// 다음 페이지로
			if (TextEditor::getInstance()->isLast()) msg = "마지막 페이지입니다.";
			else {
				msg = "다음 페이지입니다.";
				TextEditor::getInstance()->ToNextPage();
			}
			break;
		case 'p':	// 이전 페이지로
			if (TextEditor::getInstance()->getPage() == 1) msg = "첫 페이지입니다.";
			else {
				msg = "이전 페이지입니다.";
				TextEditor::getInstance()->ToPrevPage();
			}
			break;
		case 'i':	// 단어 삽입하기
			msg = "삽입 수행 결과입니다.";
			TextEditor::getInstance()->Insert(order);
			break;
		case 'd':	// 단어 삭제하기
			msg = "삭제되었습니다. 해당 단어를 초과한 범위는 생략됩니다.";
			TextEditor::getInstance()->Delete(order);
			break;
		case 'c':	// 단어 변경하기
			msg = "변경되었습니다.";
			TextEditor::getInstance()->Change(order);
			break;
		case 's':	// 단어 탐색하기
			msg = "찾기 수행 결과입니다. 페이지는 변동 없습니다.";
			TextEditor::getInstance()->Search(order);
			break;
		case 't':	// 저장하고 종료
			TextEditor::getInstance()->SaveAndExit();
			return 0;
		default: msg = "존재하지 않는 명령입니다. 다시 입력해주세요.";
		}
	}
}