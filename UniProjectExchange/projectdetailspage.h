#pragma once

namespace UniProjectExchange {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class ProjectDetailsForm : public System::Windows::Forms::Form
    {
    public:
        ProjectDetailsForm(String^ projectId)
        {
            InitializeComponent();
            connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=UniProjectExchange;Integrated Security=True;Encrypt=True;Trust Server Certificate=True";
            this->projectId = projectId;
            LoadProjectDetails();
            LoadProjectComponents();
        }

    protected:
        ~ProjectDetailsForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ lblTitle;
    private: System::Windows::Forms::PictureBox^ picProjectImage;
    private: System::Windows::Forms::Label^ lblDescription;
    private: System::Windows::Forms::RichTextBox^ txtDescription;
    private: System::Windows::Forms::Label^ lblPrice;
    private: System::Windows::Forms::Label^ lblPriceValue;


    private: System::Windows::Forms::Label^ lblComponents;
    private: System::Windows::Forms::ListBox^ lbComponents;
    private: System::Windows::Forms::Button^ btnBuy;
    private: System::Windows::Forms::Button^ btnClose;
    private: String^ connectionString;
    private: String^ projectId;
    private: double projectPrice;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProjectDetailsForm::typeid));
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->picProjectImage = (gcnew System::Windows::Forms::PictureBox());
            this->lblDescription = (gcnew System::Windows::Forms::Label());
            this->txtDescription = (gcnew System::Windows::Forms::RichTextBox());
            this->lblPrice = (gcnew System::Windows::Forms::Label());
            this->lblPriceValue = (gcnew System::Windows::Forms::Label());
            this->lblComponents = (gcnew System::Windows::Forms::Label());
            this->lbComponents = (gcnew System::Windows::Forms::ListBox());
            this->btnBuy = (gcnew System::Windows::Forms::Button());
            this->btnClose = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picProjectImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // lblTitle
            // 
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblTitle->Location = System::Drawing::Point(536, 9);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(66, 29);
            this->lblTitle->TabIndex = 0;
            this->lblTitle->Text = L"Title";
            // 
            // picProjectImage
            // 
            this->picProjectImage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->picProjectImage->Location = System::Drawing::Point(541, 64);
            this->picProjectImage->Name = L"picProjectImage";
            this->picProjectImage->Size = System::Drawing::Size(300, 200);
            this->picProjectImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->picProjectImage->TabIndex = 1;
            this->picProjectImage->TabStop = false;
            // 
            // lblDescription
            // 
            this->lblDescription->AutoSize = true;
            this->lblDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblDescription->Location = System::Drawing::Point(857, 64);
            this->lblDescription->Name = L"lblDescription";
            this->lblDescription->Size = System::Drawing::Size(112, 20);
            this->lblDescription->TabIndex = 2;
            this->lblDescription->Text = L"Description:";
            // 
            // txtDescription
            // 
            this->txtDescription->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->txtDescription->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txtDescription->Location = System::Drawing::Point(861, 106);
            this->txtDescription->Name = L"txtDescription";
            this->txtDescription->ReadOnly = true;
            this->txtDescription->Size = System::Drawing::Size(400, 100);
            this->txtDescription->TabIndex = 3;
            this->txtDescription->Text = L"";
            // 
            // lblPrice
            // 
            this->lblPrice->AutoSize = true;
            this->lblPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblPrice->Location = System::Drawing::Point(857, 246);
            this->lblPrice->Name = L"lblPrice";
            this->lblPrice->Size = System::Drawing::Size(59, 20);
            this->lblPrice->TabIndex = 4;
            this->lblPrice->Text = L"Price:";
            // 
            // lblPriceValue
            // 
            this->lblPriceValue->AutoSize = true;
            this->lblPriceValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblPriceValue->Location = System::Drawing::Point(950, 246);
            this->lblPriceValue->Name = L"lblPriceValue";
            this->lblPriceValue->Size = System::Drawing::Size(65, 20);
            this->lblPriceValue->TabIndex = 5;
            this->lblPriceValue->Text = L"Rs.0.00";
            this->lblPriceValue->Click += gcnew System::EventHandler(this, &ProjectDetailsForm::lblPriceValue_Click);
            // 
            // lblComponents
            // 
            this->lblComponents->AutoSize = true;
            this->lblComponents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblComponents->Location = System::Drawing::Point(537, 277);
            this->lblComponents->Name = L"lblComponents";
            this->lblComponents->Size = System::Drawing::Size(119, 20);
            this->lblComponents->TabIndex = 8;
            this->lblComponents->Text = L"Components:";
            // 
            // lbComponents
            // 
            this->lbComponents->FormattingEnabled = true;
            this->lbComponents->ItemHeight = 16;
            this->lbComponents->Location = System::Drawing::Point(541, 323);
            this->lbComponents->Name = L"lbComponents";
            this->lbComponents->Size = System::Drawing::Size(720, 100);
            this->lbComponents->TabIndex = 9;
            // 
            // btnBuy
            // 
            this->btnBuy->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->btnBuy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnBuy->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->btnBuy->Location = System::Drawing::Point(895, 450);
            this->btnBuy->Name = L"btnBuy";
            this->btnBuy->Size = System::Drawing::Size(120, 40);
            this->btnBuy->TabIndex = 10;
            this->btnBuy->Text = L"Buy Now";
            this->btnBuy->UseVisualStyleBackColor = false;
            this->btnBuy->Click += gcnew System::EventHandler(this, &ProjectDetailsForm::Buy_Click);
            // 
            // btnClose
            // 
            this->btnClose->Location = System::Drawing::Point(1141, 450);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(120, 40);
            this->btnClose->TabIndex = 11;
            this->btnClose->Text = L"Close";
            this->btnClose->UseVisualStyleBackColor = true;
            this->btnClose->Click += gcnew System::EventHandler(this, &ProjectDetailsForm::Close_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
            this->pictureBox1->Location = System::Drawing::Point(82, 90);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(372, 400);
            this->pictureBox1->TabIndex = 12;
            this->pictureBox1->TabStop = false;
            // 
            // ProjectDetailsForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->ClientSize = System::Drawing::Size(1273, 565);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->btnBuy);
            this->Controls->Add(this->lbComponents);
            this->Controls->Add(this->lblComponents);
            this->Controls->Add(this->lblPriceValue);
            this->Controls->Add(this->lblPrice);
            this->Controls->Add(this->txtDescription);
            this->Controls->Add(this->lblDescription);
            this->Controls->Add(this->picProjectImage);
            this->Controls->Add(this->lblTitle);
            this->Name = L"ProjectDetailsForm";
            this->Text = L"Project Details";
            this->Load += gcnew System::EventHandler(this, &ProjectDetailsForm::ProjectDetailsForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picProjectImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: void LoadProjectDetails() {
        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ command = gcnew SqlCommand("SELECT Title, Description, Price, Category, ImagePath FROM Projects WHERE Id = @Id", connection);
        command->Parameters->AddWithValue("@Id", projectId);

        try {
            connection->Open();
            SqlDataReader^ reader = command->ExecuteReader();

            if (reader->Read()) {
                lblTitle->Text = reader["Title"]->ToString();
                txtDescription->Text = reader["Description"]->ToString();
                projectPrice = Convert::ToDouble(reader["Price"]);
                lblPriceValue->Text = "Rs." + projectPrice.ToString("N2");
                lblCategoryValue->Text = reader["Category"]->ToString();

                // Load image if available
                if (reader["ImagePath"] != DBNull::Value) {
                    String^ imagePath = reader["ImagePath"]->ToString();
                    if (File::Exists(imagePath)) {
                        picProjectImage->Image = Image::FromFile(imagePath);
                    }
                }
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading project details: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (connection->State == ConnectionState::Open)
                connection->Close();
        }
    }

    private: void LoadProjectComponents() {
        lbComponents->Items->Clear();

        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ command = gcnew SqlCommand("SELECT ComponentName, Description FROM ProjectComponents WHERE ProjectId = @ProjectId", connection);
        command->Parameters->AddWithValue("@ProjectId", projectId);

        try {
            connection->Open();
            SqlDataReader^ reader = command->ExecuteReader();

            while (reader->Read()) {
                String^ component = reader["ComponentName"]->ToString() + ": " + reader["Description"]->ToString();
                lbComponents->Items->Add(component);
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading project components: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (connection->State == ConnectionState::Open)
                connection->Close();
        }
    }

    private: System::Void Buy_Click(System::Object^ sender, System::EventArgs^ e) {
        // Check if user has enough balance
        double userBalance = GetUserBalance();
        if (userBalance < projectPrice) {
            MessageBox::Show("Insufficient funds to purchase this project", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Confirm purchase
        if (MessageBox::Show("Are you sure you want to purchase this project for " + lblPriceValue->Text + "?",
            "Confirm Purchase", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

            if (ProcessPurchase()) {
                MessageBox::Show("Purchase completed successfully!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->DialogResult = System::Windows::Forms::DialogResult::OK;
                this->Close();
            }
            else {
                MessageBox::Show("Purchase failed. Please try again.", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    }

    private: bool ProcessPurchase() {
        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ command = gcnew SqlCommand();
        command->Connection = connection;

        try {
            connection->Open();
            SqlTransaction^ transaction = connection->BeginTransaction();
            command->Transaction = transaction;

            try {
                // 1. Deduct funds from buyer
                command->CommandText = "UPDATE Users SET Balance = Balance - @Amount WHERE Id = @UserId";
                command->Parameters->AddWithValue("@Amount", projectPrice);
                command->Parameters->AddWithValue("@UserId", GetCurrentUserId());
                command->ExecuteNonQuery();

                // 2. Add funds to seller
                command->Parameters->Clear();
                command->CommandText = "UPDATE Users SET Balance = Balance + @Amount WHERE Id = "
                    "(SELECT SellerId FROM Projects WHERE Id = @ProjectId)";
                command->Parameters->AddWithValue("@Amount", projectPrice);
                command->Parameters->AddWithValue("@ProjectId", projectId);
                command->ExecuteNonQuery();

                // 3. Transfer project ownership
                command->Parameters->Clear();
                command->CommandText = "UPDATE Projects SET SellerId = @NewOwnerId, IsSold = 1 WHERE Id = @ProjectId";
                command->Parameters->AddWithValue("@NewOwnerId", GetCurrentUserId());
                command->Parameters->AddWithValue("@ProjectId", projectId);
                command->ExecuteNonQuery();

                // 4. Record transaction
                command->Parameters->Clear();
                command->CommandText = "INSERT INTO Transactions (ProjectId, BuyerId, SellerId, Amount, TransactionDate) "
                    "VALUES (@ProjectId, @BuyerId, (SELECT SellerId FROM Projects WHERE Id = @ProjectId), @Amount, GETDATE())";
                command->Parameters->AddWithValue("@ProjectId", projectId);
                command->Parameters->AddWithValue("@BuyerId", GetCurrentUserId());
                command->Parameters->AddWithValue("@Amount", projectPrice);
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

    private: double GetUserBalance() {
        // Implement to get the actual user's balance from database
        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ command = gcnew SqlCommand("SELECT Balance FROM Users WHERE Id = @UserId", connection);
        command->Parameters->AddWithValue("@UserId", GetCurrentUserId());

        try {
            connection->Open();
            Object^ result = command->ExecuteScalar();
            return result != DBNull::Value ? Convert::ToDouble(result) : 0.0;
        }
        catch (Exception^ ex) {
            return 0.0;
        }
        finally {
            if (connection->State == ConnectionState::Open)
                connection->Close();
        }
    }

    private: int GetCurrentUserId() {
        // Implement to get the actual logged-in user ID
        return 1; // Placeholder
    }

    private: System::Void Close_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    private: System::Void lblPriceValue_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void ProjectDetailsForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}