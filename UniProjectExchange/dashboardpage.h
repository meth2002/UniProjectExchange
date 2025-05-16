#pragma once
#include "buypage.h"
#include "sellpage1.h"
#include "browserpage.h"

namespace UniProjectExchange {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class dashboard : public System::Windows::Forms::Form
	{
	public:
		dashboard(void)
		{
			InitializeComponent();
			// You can initialize user-specific data here
		}

	protected:
		~dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Button^ btnBuy;
	private: System::Windows::Forms::Button^ btnSell;
	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Label^ lblBalance;
	private: System::Windows::Forms::Label^ lblBalanceValue;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->btnBuy = (gcnew System::Windows::Forms::Button());
			this->btnSell = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->lblBalance = (gcnew System::Windows::Forms::Label());
			this->lblBalanceValue = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->Location = System::Drawing::Point(30, 30);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(214, 29);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Welcome, [User]!";
			// 
			// btnBuy
			// 
			this->btnBuy->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnBuy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuy->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnBuy->Location = System::Drawing::Point(50, 100);
			this->btnBuy->Name = L"btnBuy";
			this->btnBuy->Size = System::Drawing::Size(150, 50);
			this->btnBuy->TabIndex = 1;
			this->btnBuy->Text = L"BUY";
			this->btnBuy->UseVisualStyleBackColor = false;
			this->btnBuy->Click += gcnew System::EventHandler(this, &dashboard::BuyButton_Click);
			// 
			// btnSell
			// 
			this->btnSell->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnSell->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSell->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnSell->Location = System::Drawing::Point(250, 100);
			this->btnSell->Name = L"btnSell";
			this->btnSell->Size = System::Drawing::Size(150, 50);
			this->btnSell->TabIndex = 2;
			this->btnSell->Text = L"SELL";
			this->btnSell->UseVisualStyleBackColor = false;
			this->btnSell->Click += gcnew System::EventHandler(this, &dashboard::SellButton_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogout->Location = System::Drawing::Point(600, 30);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(100, 30);
			this->btnLogout->TabIndex = 3;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = true;
			this->btnLogout->Click += gcnew System::EventHandler(this, &dashboard::LogoutButton_Click);
			// 
			// lblBalance
			// 
			this->lblBalance->AutoSize = true;
			this->lblBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBalance->Location = System::Drawing::Point(450, 100);
			this->lblBalance->Name = L"lblBalance";
			this->lblBalance->Size = System::Drawing::Size(75, 20);
			this->lblBalance->TabIndex = 4;
			this->lblBalance->Text = L"Balance:";
			// 
			// lblBalanceValue
			// 
			this->lblBalanceValue->AutoSize = true;
			this->lblBalanceValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBalanceValue->Location = System::Drawing::Point(450, 130);
			this->lblBalanceValue->Name = L"lblBalanceValue";
			this->lblBalanceValue->Size = System::Drawing::Size(72, 20);
			this->lblBalanceValue->TabIndex = 5;
			this->lblBalanceValue->Text = L"Rs.0.00";
			this->lblBalanceValue->Click += gcnew System::EventHandler(this, &dashboard::lblBalanceValue_Click);
			// 
			// dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 450);
			this->Controls->Add(this->lblBalanceValue);
			this->Controls->Add(this->lblBalance);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->btnSell);
			this->Controls->Add(this->btnBuy);
			this->Controls->Add(this->lblWelcome);
			this->Name = L"dashboard";
			this->Text = L"Dashboard";
			this->Load += gcnew System::EventHandler(this, &dashboard::Dashboard_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void BuyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create and show the buy form
		BrowseProjectsForm^ buy = gcnew BrowseProjectsForm();
		buy->ShowDialog();
	}

	private: System::Void SellButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create and show the sell form
		SellProjectForm^ sell = gcnew SellProjectForm();
		sell->ShowDialog();
	}

	private: System::Void LogoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the dashboard and return to login
		this->Close();
	}

	private: System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadUserData();
	}

	private: void LoadUserData() {
		lblWelcome->Text = "Welcome, " + GetCurrentUserName() + "!";
		lblBalanceValue->Text = "$" + GetCurrentUserBalance().ToString("N2");
	}

	private: void RefreshDashboardData() {
		// Refresh the data grid with current holdings
		dataGridView1->DataSource = GetUserHoldings();
		dataGridView1->AutoResizeColumns();
	}

		   // These methods would be implemented to get actual data from your database
	private: String^ GetCurrentUserName() {
		// Implement database lookup for current user's name
		return "User"; // Replace with actual implementation
	}

	private: double GetCurrentUserBalance() {
		// Implement database lookup for current user's balance
		return 1000.00; // Replace with actual implementation
	}

	private: DataTable^ GetUserHoldings() {
		// Create sample data - replace with actual database call
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Symbol");
		dt->Columns->Add("Quantity");
		dt->Columns->Add("Avg Price");
		dt->Columns->Add("Current Price");
		dt->Columns->Add("Value");

		// Add sample rows
		dt->Rows->Add("AAPL", 10, 150.25, 155.30, 1553.00);
		dt->Rows->Add("MSFT", 5, 250.75, 245.50, 1227.50);
		dt->Rows->Add("GOOGL", 2, 1250.00, 1275.25, 2550.50);

		return dt;
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void lblBalanceValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}