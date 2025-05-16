#pragma once
#include "DatabaseConfig.h"
#include "loginpage.h"
namespace UniProjectExchange {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	public ref class registerpage : public System::Windows::Forms::Form
	{
	public:
		registerpage(void)
		{
			InitializeComponent();
			connectionString = DatabaseConfig::ConnectionString;
		}

	protected:
		~registerpage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtConfirmPassword;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnBack;
	private: String^ connectionString;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(187, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Email";
			this->label1->Click += gcnew System::EventHandler(this, &registerpage::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(187, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(187, 180);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Confirm Password";
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(305, 77);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(200, 22);
			this->txtEmail->TabIndex = 3;
			this->txtEmail->TextChanged += gcnew System::EventHandler(this, &registerpage::txtEmail_TextChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(305, 127);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(200, 22);
			this->txtPassword->TabIndex = 4;
			// 
			// txtConfirmPassword
			// 
			this->txtConfirmPassword->Location = System::Drawing::Point(305, 177);
			this->txtConfirmPassword->Name = L"txtConfirmPassword";
			this->txtConfirmPassword->PasswordChar = '*';
			this->txtConfirmPassword->Size = System::Drawing::Size(200, 22);
			this->txtConfirmPassword->TabIndex = 5;
			// 
			// btnRegister
			// 
			this->btnRegister->Location = System::Drawing::Point(184, 250);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(100, 30);
			this->btnRegister->TabIndex = 6;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &registerpage::RegisterButton_Click);
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(405, 250);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(100, 30);
			this->btnBack->TabIndex = 7;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &registerpage::BackButton_Click);
			// 
			// registerpage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 385);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->txtConfirmPassword);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"registerpage";
			this->Text = L"Registration Page";
			this->Load += gcnew System::EventHandler(this, &registerpage::registerpage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void RegisterButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = txtEmail->Text;
		String^ password = txtPassword->Text;
		String^ confirmPassword = txtConfirmPassword->Text;

		// Validate inputs
		if (String::IsNullOrEmpty(email) || String::IsNullOrEmpty(password) || String::IsNullOrEmpty(confirmPassword)) {
			MessageBox::Show("Please fill in all fields", "Registration Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (password != confirmPassword) {
			MessageBox::Show("Passwords do not match", "Registration Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!IsValidEmail(email)) {
			MessageBox::Show("Please enter a valid email address", "Registration Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			if (EmailExists(email)) {
				MessageBox::Show("Email already registered", "Registration Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (RegisterUser(email, password)) {
				MessageBox::Show("Registration successful! You can now login", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				
				loginpage^ loginPage = gcnew loginpage();
				loginPage->Show();
			
				//this->Close();
			}
			else {
				MessageBox::Show("Registration failed", "Error",
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

	private: bool EmailExists(String^ email) {
		String^ query = "SELECT COUNT(*) FROM Users WHERE Email = @Email";

		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlCommand^ command = gcnew SqlCommand(query, connection);
		command->Parameters->AddWithValue("@Email", email);

		try {
			connection->Open();
			int count = safe_cast<int>(command->ExecuteScalar());
			return count > 0;
		}
		finally {
			if (connection->State == ConnectionState::Open)
				connection->Close();
		}
	}

	private: bool RegisterUser(String^ email, String^ password) {
		String^ query = "INSERT INTO Users (Email, PasswordHash) VALUES (@Email, @PasswordHash)";

		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlCommand^ command = gcnew SqlCommand(query, connection);
		command->Parameters->AddWithValue("@Email", email);
		command->Parameters->AddWithValue("@PasswordHash", HashPassword(password));

		try {
			connection->Open();
			int rowsAffected = command->ExecuteNonQuery();
			return rowsAffected > 0;
		}
		finally {
			if (connection->State == ConnectionState::Open)
				connection->Close();
		}
	}

	private: String^ HashPassword(String^ password) {
		return password;
	}

	private: bool IsValidEmail(String^ email) {
		try {
			// Simple email validation
			return System::Text::RegularExpressions::Regex::IsMatch(email,
				"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
		}
		catch (...) {
			return false;
		}
	}
	private: System::Void registerpage_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtEmail_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}