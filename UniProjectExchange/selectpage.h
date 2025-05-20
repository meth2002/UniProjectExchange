#pragma once
#include "loginpage.h"
#include "registerpage.h"

namespace UniProjectExchange {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// class select page
	public ref class selectpage : public System::Windows::Forms::Form
	{
	public:
		selectpage(void)
		{
			InitializeComponent();
			
		}

	protected:
		
		~selectpage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;

	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			 
			// login button  
			
			this->button1->Location = System::Drawing::Point(77, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(167, 66);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &selectpage::button1_Click);
			
			// Register button
			
			this->button2->Location = System::Drawing::Point(444, 97);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 66);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Register";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &selectpage::button2_Click);
			
			//about select page
			
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(707, 347);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"selectpage";
			this->Text = L"selectpage";
			this->Load += gcnew System::EventHandler(this, &selectpage::selectpage_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		UniProjectExchange::loginpage^ loginForm = gcnew UniProjectExchange::loginpage();
		loginForm->ShowDialog();
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		UniProjectExchange::registerpage^ registerForm = gcnew UniProjectExchange::registerpage();
		registerForm->ShowDialog();
		this->Close();
	}
	private: System::Void selectpage_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
