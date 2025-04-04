#pragma once
#include <cliext/vector>
#include "Question.h"

namespace CodeBrain {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:
		int points = 0;
		cliext::vector<Question^> question;
		cliext::vector<String^> selection;
		array<String^>^ sel = gcnew array<String^>(8);
		
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;

	public:
		String^ name ="";
		   int numQuestion = 1;
		MyForm2(void)
		{
			InitializeComponent();
			shuffle();
			label3->Text = points + " points";
			//
			//TODO: Add the constructor code here
			//
		}
			//
		
		void getdata(System::String^ s) {
			this->name= s;
		}
		void shuffle() {
			
			
		}
		String^ review() {
			String^ s1="";
			this->radioButton1->Visible = false;
			this->radioButton2->Visible = false;
			this->radioButton3->Visible = false;
			this->radioButton4->Visible = false;
			int i = 3;
		
				s1 = s1 + question[i]->getQestion() + "\n";
				s1 = s1 + question[i]->getAnswers()[0] + "\n";
				s1 = s1 + question[i]->getAnswers()[1] + "\n";
				s1 = s1 + question[i]->getAnswers()[2] + "\n";
				s1 = s1 + question[i]->getAnswers()[3] + "\n";
				s1 = s1 + question[i]->getCorrect() + "\n";
			
			return s1;

		}

		String^ selectedAns() {
			String^ res;
			if (radioButton1->Checked) {
				res = radioButton1->Text;
			}
			if (radioButton2->Checked) {
				res = radioButton2->Text;
			}
			if (radioButton3->Checked) {
				res = radioButton3->Text;
			}
			if (radioButton4->Checked) {
				res = radioButton4->Text;
			}
			return res;
		}
		/**/double getfeedback() {
			double correct = 0;
			int i = 0;
			for each (String ^ line in sel) {
				if (question[i]->getCorrect()->Equals(line)) {
					correct++;
				}
				i++;
			}

			return (correct/8)*100;
		}
		void makeQuestions(String^ ss) {
			if (ss->Equals("pyhton")) {
				label2->Text = "LEVEL1";
			}
			if (ss->Equals("python1")) {
				label2->Text = "LEVEL2";
			}
			if (ss->Equals("python2")) {
				label2->Text = "LEVEL3";
			}
		
			
			array<String^>^ lines = File::ReadAllLines(ss +".txt");
			String^ q = "";
			int n = 0;
			Question^ qq;
			String^ as;
			cliext::vector<String^> a;
			for each (String ^ line in lines) {
				if (n == 1) {
					as = line;
					n = 54;
					array<String^>^ sub = line->Split('@');
					for each (String ^ i in sub) {
						a.push_back(i);
					}
					qq = gcnew Question(q, a);
					question.push_back(qq);
					q = "";
					a.clear();

				}
			
				if (line->Equals("###")) {
					n++;
				}
				if (n == 0) {
					q = q + line + "\n";
				}
				if (n == 54) {
					n = 0;
				}
			}
			richTextBox1->Text = question[0]->getQestion();
			radioButton1->Text = question[0]->getAnswers()[0];
			radioButton2->Text = question[0]->getAnswers()[1];
			radioButton3->Text = question[0]->getAnswers()[2];
			radioButton4->Text = question[0]->getAnswers()[3];
			

		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Panel^ panel1;




	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button1->Location = System::Drawing::Point(42, 444);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"PREVIOS";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button2->Location = System::Drawing::Point(693, 444);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 35);
			this->button2->TabIndex = 1;
			this->button2->Text = L"NEXT";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->radioButton4);
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->richTextBox1);
			this->panel1->Location = System::Drawing::Point(86, 75);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(681, 350);
			this->panel1->TabIndex = 3;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton4->Location = System::Drawing::Point(238, 315);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(125, 24);
			this->radioButton4->TabIndex = 8;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton3->Location = System::Drawing::Point(238, 274);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(125, 24);
			this->radioButton3->TabIndex = 7;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(238, 235);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(125, 24);
			this->radioButton2->TabIndex = 6;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(238, 187);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(125, 24);
			this->radioButton1->TabIndex = 5;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(675, 166);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(366, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"LEVEL1";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm2::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(720, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 32);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Question 1 of 8";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm2::label1_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)));
			this->ClientSize = System::Drawing::Size(853, 510);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		
		this->numQuestion--;
		richTextBox1->Clear();
		this->label1->Text = "Question " + this->numQuestion + " of 8";
		if (numQuestion == 1) {
			this->button1->Visible = false;
		}
		if (numQuestion < 9) {
			this->button2->Text = "NEXT";
		}
		
		if (question[numQuestion - 1]->getAnswers().size() == 2) {
			radioButton3->Visible = false;
			radioButton4->Visible = false;
			richTextBox1->Text = question[numQuestion - 1]->getQestion();
			radioButton1->Text = question[numQuestion - 1]->getAnswers()[0];
			radioButton2->Text = question[numQuestion - 1]->getAnswers()[1];

		}
		else {
			radioButton3->Visible = true;
			radioButton4->Visible = true;
			richTextBox1->Text = question[numQuestion - 1]->getQestion();
			radioButton1->Text = question[numQuestion - 1]->getAnswers()[0];
			radioButton2->Text = question[numQuestion - 1]->getAnswers()[1];
			radioButton3->Text = question[numQuestion - 1]->getAnswers()[2];
			radioButton4->Text = question[numQuestion - 1]->getAnswers()[3];
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
		
		if (this->selectedAns()->Equals(question[numQuestion-1])) {
			points++;
			label3->Text = points+" points";
		}
		//clear textbox
		if (numQuestion < 8) {
			sel[numQuestion - 1] = this->selectedAns();
			richTextBox1->Clear();
		}
		this->numQuestion++;
		
		this->label1->Text = "Question " + this->numQuestion + " of 8";
		if (numQuestion != 1) {
			this->button1->Visible = true;
		}
		if (numQuestion == 9) {
			richTextBox1->Clear();
			this->button2->Text = "SUBMIT";
			this->label1->Text = "YOU DONE  ";
			this->radioButton1->Visible = false;
			this->radioButton2->Visible = false;
			this->radioButton3->Visible = false;
			this->radioButton4->Visible = false;
			richTextBox1->Text = "you done ";

		}
		if (numQuestion==10 ) {
			this->radioButton1->Visible = false;
			this->radioButton2->Visible = false;
			this->radioButton3->Visible = false;
			this->radioButton4->Visible = false;
			richTextBox1->Clear();
			this->label1->Visible = false;
			this->button1->Text="Review";
			this->button2->Text = "levels";
			richTextBox1->Text = "you got  "+getfeedback() + "%";
			
		}
		if (numQuestion==11) {
			this->radioButton1->Visible = false;
			this->radioButton2->Visible = false;
			this->radioButton3->Visible = false;
			this->radioButton4->Visible = false;
			

		}

	
		if (question[numQuestion - 1]->getAnswers().size()==2) {
			radioButton3->Visible = false;
			radioButton4->Visible = false;
			richTextBox1->Text = question[numQuestion - 1]->getQestion();
			radioButton1->Text = question[numQuestion - 1]->getAnswers()[0];
			radioButton2->Text = question[numQuestion - 1]->getAnswers()[1];

		}
		
		else if (numQuestion  <9 && question[numQuestion - 1]->getAnswers().size() == 4) {
			radioButton3->Visible = true;
			radioButton4->Visible = true;
			richTextBox1->Text = question[numQuestion - 1]->getQestion();
			radioButton1->Text = question[numQuestion - 1]->getAnswers()[0];
			radioButton2->Text = question[numQuestion - 1]->getAnswers()[1];
			radioButton3->Text = question[numQuestion - 1]->getAnswers()[2];
			radioButton4->Text = question[numQuestion - 1]->getAnswers()[3];
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};


}
