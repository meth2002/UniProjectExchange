#pragma once
#include "browserpage.h"
#include "sellpage1.h"


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





	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->btnBuy = (gcnew System::Windows::Forms::Button());
			this->btnSell = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());

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
			this->btnBuy->Text = L"BUYER";
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
			this->btnSell->Text = L"SELLER";
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

			// lblBalanceValue

			// dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 450);

			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->btnSell);
			this->Controls->Add(this->btnBuy);
			this->Controls->Add(this->lblWelcome);
			this->Name = L"dashboard";
			this->Text = L"Dashboard";
		
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void BuyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create and show the buy form
		BrowseProjectsForm^ buy = gcnew BrowseProjectsForm();
		buy->ShowDialog();
		// Refresh data after buy operation if needed
		//RefreshDashboardData();
	}

	private: System::Void SellButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create and show the sell form
		SellProjectForm^ sell = gcnew SellProjectForm();
		sell->ShowDialog();
		// Refresh data after sell operation if needed
		//RefreshDashboardData();
	}

	private: System::Void LogoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Close the dashboard and return to login
		this->Close();
	}

	

	
	





	
	};
}