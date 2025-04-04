#pragma once
#include <cliext/vector>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <algorithm>


using namespace System;
using namespace cliext;
using namespace System::Collections::Generic;
using namespace msclr::interop;

ref class  Question {
private:
	String^ q;
	String^ ansCorrect;
	cliext::vector<String^> answers;
	bool isCorrect = false;

public:
	void makeCorrect() {
		if (!isCorrect) {
			isCorrect = true;
		}
	}
	Question(String^ Q, cliext::vector<String^> asw) {
		q = Q;
		answers = asw;
		ansCorrect = answers[0]; 
	}
	String^ getCorrect() {
		return ansCorrect;
	}
	String^ getQestion() {
		return q;
	}

	cliext::vector<String^> getAnswers() {
		return answers;
	}

};

