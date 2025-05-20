#pragma once
#include "DatabaseConfig.h"
#include "dashboardpage.h"
namespace UniProjectExchange {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	public ref class loginpage : public System::Windows::Forms::Form
	{
	public:
		loginpage(void)
		{
			InitializeComponent();

			connectionString = DatabaseConfig::ConnectionString;
		}

	protected:
		~loginpage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: String^ connectionString;

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			
			// label password
			
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(187, 155);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Password";
			this->label1->Click += gcnew System::EventHandler(this, &loginpage::label1_Click);
			 
			// label email
			
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(187, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Email";
			 
			// text box for password show as *
			
			this->textBox1->Location = System::Drawing::Point(305, 149);
			this->textBox1->Name = L"textBox1";
			this->textBox1->PasswordChar = '*';
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 2;
			 
			// text box for email
			
			this->textBox2->Location = System::Drawing::Point(305, 77);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &loginpage::textBox2_TextChanged);
			 
			// login button
			
			this->button1->Location = System::Drawing::Point(138, 249);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &loginpage::LoginButton_Click);
			 
			// back button
			 
			this->button2->Location = System::Drawing::Point(359, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &loginpage::BackButton_Click);
			
			// about login page
			 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 385);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"loginpage";
			this->Text = L"Login Page";
			this->Load += gcnew System::EventHandler(this, &loginpage::loginpage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Label click handler (if needed)
	}

	private: System::Void LoginButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = textBox2->Text;
		String^ password = textBox1->Text;

		if (String::IsNullOrEmpty(email) || String::IsNullOrEmpty(password)) {
			MessageBox::Show("Please enter both email and password", "Login Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			// Verify credentials against database
			if (VerifyCredentials(email, password)) {
				MessageBox::Show("Login successful!", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				
					dashboard^ dashboardpage = gcnew dashboard();
				dashboardpage->Show();

				// Proceed to main application or next form
			} 
			else {
				MessageBox::Show("Invalid email or password", "Login Failed",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Database error: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: bool VerifyCredentials(String^ email, String^ password) {
		String^ query = "SELECT PasswordHash FROM Users WHERE Email = @Email";

		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlCommand^ command = gcnew SqlCommand(query, connection);
		command->Parameters->AddWithValue("@Email", email);

		try {
			connection->Open();
			Object^ result = command->ExecuteScalar();

			if (result != nullptr) {
				String^ storedHash = result->ToString();
				return storedHash == HashPassword(password);
			}
			return false;
		}
		finally {
			if (connection->State == ConnectionState::Open)
				connection->Close();
		}
	}

	private: String^ HashPassword(String^ password) {
		return password;
	}
	private: System::Void loginpage_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}