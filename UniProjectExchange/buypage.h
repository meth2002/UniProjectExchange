#pragma once
#include "DatabaseConfig.h"	
namespace UniProjectExchange {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	public ref class buyForm : public System::Windows::Forms::Form
	{
	public:
		buyForm(void)
		{
			InitializeComponent();
			connectionString = DatabaseConfig::ConnectionString;
			LoadAvailableSymbols();
		}

	protected:
		~buyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cmbSymbol;

	private: System::Windows::Forms::TextBox^ txtQuantity;
	private: System::Windows::Forms::Button^ btnBuy;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Label^ lblPrice;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Timer^ timer1;
	private: String^ connectionString;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(buyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
			this->btnBuy = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lblPrice = (gcnew System::Windows::Forms::Label());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(653, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Buy Form";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(532, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 22);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Quantity:";
			// 
			// txtQuantity
			// 
			this->txtQuantity->Location = System::Drawing::Point(658, 118);
			this->txtQuantity->Name = L"txtQuantity";
			this->txtQuantity->Size = System::Drawing::Size(282, 22);
			this->txtQuantity->TabIndex = 4;
			this->txtQuantity->TextChanged += gcnew System::EventHandler(this, &buyForm::QuantityChanged);
			this->txtQuantity->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &buyForm::QuantityKeyPress);
			// 
			// btnBuy
			// 
			this->btnBuy->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnBuy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuy->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnBuy->Location = System::Drawing::Point(586, 328);
			this->btnBuy->Name = L"btnBuy";
			this->btnBuy->Size = System::Drawing::Size(138, 40);
			this->btnBuy->TabIndex = 5;
			this->btnBuy->Text = L"Buy";
			this->btnBuy->UseVisualStyleBackColor = false;
			this->btnBuy->Click += gcnew System::EventHandler(this, &buyForm::BuyButton_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(829, 330);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(100, 40);
			this->btnCancel->TabIndex = 6;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &buyForm::CancelButton_Click);
			// 
			// lblPrice
			// 
			this->lblPrice->AutoSize = true;
			this->lblPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrice->Location = System::Drawing::Point(671, 196);
			this->lblPrice->Name = L"lblPrice";
			this->lblPrice->Size = System::Drawing::Size(53, 20);
			this->lblPrice->TabIndex = 7;
			this->lblPrice->Text = L"Price:";
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotal->Location = System::Drawing::Point(673, 239);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(51, 18);
			this->lblTotal->TabIndex = 8;
			this->lblTotal->Text = L"Total:";
			// 
			// timer1
			// 
			this->timer1->Interval = 5000;
			this->timer1->Tick += gcnew System::EventHandler(this, &buyForm::UpdatePrices);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(21, 37);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(438, 442);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// buyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(952, 513);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblTotal);
			this->Controls->Add(this->lblPrice);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnBuy);
			this->Controls->Add(this->txtQuantity);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Name = L"buyForm";
			this->Text = L"Buy Stocks";
			this->Load += gcnew System::EventHandler(this, &buyForm::Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Form_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
		UpdatePrices(nullptr, nullptr);
	}

	private: System::Void BuyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cmbSymbol->SelectedItem == nullptr || String::IsNullOrEmpty(txtQuantity->Text)) {
			MessageBox::Show("Please select a symbol and enter quantity", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ symbol = cmbSymbol->SelectedItem->ToString();
		int quantity;
		if (!Int32::TryParse(txtQuantity->Text, quantity) || quantity <= 0) {
			MessageBox::Show("Please enter a valid quantity", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		double price = GetCurrentPrice(symbol);
		double total = price * quantity;

		// Check if user has enough balance
		double balance = GetUserBalance();
		if (total > balance) {
			MessageBox::Show("Insufficient funds for this purchase", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Execute buy order
		if (ExecuteBuyOrder(symbol, quantity, price)) {
			MessageBox::Show("Purchase successful!", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		else {
			MessageBox::Show("Purchase failed. Please try again.", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void SymbolChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdatePriceDisplay();
		UpdateTotalDisplay();
	}

	private: System::Void QuantityChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateTotalDisplay();
	}

	private: System::Void QuantityKeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Only allow numbers and backspace
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}

	private: System::Void UpdatePrices(System::Object^ sender, System::EventArgs^ e) {
		UpdatePriceDisplay();
		UpdateTotalDisplay();
	}

	private: void LoadAvailableSymbols() {
		// This would typically come from your database
		cmbSymbol->Items->Add("AAPL");
		cmbSymbol->Items->Add("MSFT");
		cmbSymbol->Items->Add("GOOGL");
		cmbSymbol->Items->Add("AMZN");
		cmbSymbol->Items->Add("TSLA");
	}

	private: void UpdatePriceDisplay() {
		if (cmbSymbol->SelectedItem != nullptr) {
			String^ symbol = cmbSymbol->SelectedItem->ToString();
			double price = GetCurrentPrice(symbol);
			lblPrice->Text = "Price: $" + price.ToString("N2");
		}
		else {
			lblPrice->Text = "Price: $-.--";
		}
	}

	private: void UpdateTotalDisplay() {
		if (cmbSymbol->SelectedItem != nullptr && !String::IsNullOrEmpty(txtQuantity->Text)) {
			String^ symbol = cmbSymbol->SelectedItem->ToString();
			int quantity;
			if (Int32::TryParse(txtQuantity->Text, quantity)) {
				double price = GetCurrentPrice(symbol);
				double total = price * quantity;
				lblTotal->Text = "Total: $" + total.ToString("N2");
				return;
			}
		}
		lblTotal->Text = "Total: $-.--";
	}

	private: double GetCurrentPrice(String^ symbol) {
		// In a real application, this would fetch live market data
		// This is just a placeholder with mock data
		if (symbol == "AAPL") return 155.30;
		if (symbol == "MSFT") return 245.50;
		if (symbol == "GOOGL") return 1275.25;
		if (symbol == "AMZN") return 112.75;
		if (symbol == "TSLA") return 185.60;
		return 0.0;
	}

	private: double GetUserBalance() {
		// This would query your database for the user's current balance
		return 10000.00; // Placeholder value
	}

	private: bool ExecuteBuyOrder(String^ symbol, int quantity, double price) {
		// Implement database transaction to record the purchase
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlCommand^ command = gcnew SqlCommand();
		command->Connection = connection;

		try {
			connection->Open();
			// Start transaction
			SqlTransaction^ transaction = connection->BeginTransaction();
			command->Transaction = transaction;

			try {
				// 1. Deduct funds from user's account
				command->CommandText = "UPDATE Users SET Balance = Balance - @Amount WHERE UserId = @UserId";
				command->Parameters->AddWithValue("@Amount", quantity * price);
				command->Parameters->AddWithValue("@UserId", GetCurrentUserId());
				command->ExecuteNonQuery();

				// 2. Add to holdings (or update if already exists)
				command->CommandText = "IF EXISTS (SELECT 1 FROM Holdings WHERE UserId = @UserId AND Symbol = @Symbol) "
					"UPDATE Holdings SET Quantity = Quantity + @Quantity, AvgPrice = ((Quantity * AvgPrice) + (@Quantity * @Price)) / (Quantity + @Quantity) "
					"WHERE UserId = @UserId AND Symbol = @Symbol "
					"ELSE "
					"INSERT INTO Holdings (UserId, Symbol, Quantity, AvgPrice) VALUES (@UserId, @Symbol, @Quantity, @Price)";
				command->Parameters->AddWithValue("@Symbol", symbol);
				command->Parameters->AddWithValue("@Quantity", quantity);
				command->Parameters->AddWithValue("@Price", price);
				command->ExecuteNonQuery();

				// 3. Record transaction
				command->CommandText = "INSERT INTO Transactions (UserId, Symbol, Quantity, Price, Type, Timestamp) "
					"VALUES (@UserId, @Symbol, @Quantity, @Price, 'BUY', GETDATE())";
				command->ExecuteNonQuery();

				transaction->Commit();
				return true;
			}
			catch (Exception^ ex) {
				transaction->Rollback();
				return false;
			}
		}
		catch (Exception^ ex) {
			return false;
		}
		finally {
			if (connection->State == ConnectionState::Open)
				connection->Close();
		}
	}

	private: int GetCurrentUserId() {
		// This would return the actual logged-in user's ID
		return 1; // Placeholder
	}
	};
}