#pragma once
#include "addcomponentpage.h"
#include "DatabaseConfig.h" 

namespace UniProjectExchange {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;
    using namespace System::IO;

    public ref class SellProjectForm : public System::Windows::Forms::Form
    {
    public:
        SellProjectForm(void)
        {
            InitializeComponent();
            connectionString = DatabaseConfig::ConnectionString;
        }

    protected:
        ~SellProjectForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ lblTitle;
    private: System::Windows::Forms::TextBox^ txtProjectTitle;
    private: System::Windows::Forms::Label^ lblDescription;
    private: System::Windows::Forms::RichTextBox^ txtDescription;
    private: System::Windows::Forms::Label^ lblComponents;
    private: System::Windows::Forms::DataGridView^ dgvComponents;
    private: System::Windows::Forms::Button^ btnAddComponent;
    private: System::Windows::Forms::Button^ btnRemoveComponent;
    private: System::Windows::Forms::Label^ lblPrice;
    private: System::Windows::Forms::TextBox^ txtPrice;


    private: System::Windows::Forms::Label^ lblImage;
    private: System::Windows::Forms::PictureBox^ picProjectImage;
    private: System::Windows::Forms::Button^ btnUploadImage;
    private: System::Windows::Forms::Button^ btnSubmit;
    private: System::Windows::Forms::Button^ btnCancel;
    private: String^ connectionString;
    private: String^ base64Image;
    private: String^ imagePath;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->txtProjectTitle = (gcnew System::Windows::Forms::TextBox());
            this->lblDescription = (gcnew System::Windows::Forms::Label());
            this->txtDescription = (gcnew System::Windows::Forms::RichTextBox());
            this->lblComponents = (gcnew System::Windows::Forms::Label());
            this->dgvComponents = (gcnew System::Windows::Forms::DataGridView());
            this->btnAddComponent = (gcnew System::Windows::Forms::Button());
            this->btnRemoveComponent = (gcnew System::Windows::Forms::Button());
            this->lblPrice = (gcnew System::Windows::Forms::Label());
            this->txtPrice = (gcnew System::Windows::Forms::TextBox());
            this->lblImage = (gcnew System::Windows::Forms::Label());
            this->picProjectImage = (gcnew System::Windows::Forms::PictureBox());
            this->btnUploadImage = (gcnew System::Windows::Forms::Button());
            this->btnSubmit = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvComponents))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picProjectImage))->BeginInit();
            this->SuspendLayout();
            // 
            // lblTitle
            // 
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblTitle->Location = System::Drawing::Point(30, 30);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(118, 20);
            this->lblTitle->TabIndex = 0;
            this->lblTitle->Text = L"Project Title:";
            // 
            // txtProjectTitle
            // 
            this->txtProjectTitle->Location = System::Drawing::Point(150, 30);
            this->txtProjectTitle->Name = L"txtProjectTitle";
            this->txtProjectTitle->Size = System::Drawing::Size(300, 22);
            this->txtProjectTitle->TabIndex = 1;
            // 
            // lblDescription
            // 
            this->lblDescription->AutoSize = true;
            this->lblDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblDescription->Location = System::Drawing::Point(30, 70);
            this->lblDescription->Name = L"lblDescription";
            this->lblDescription->Size = System::Drawing::Size(112, 20);
            this->lblDescription->TabIndex = 2;
            this->lblDescription->Text = L"Description:";
            // 
            // txtDescription
            // 
            this->txtDescription->Location = System::Drawing::Point(150, 70);
            this->txtDescription->Name = L"txtDescription";
            this->txtDescription->Size = System::Drawing::Size(300, 100);
            this->txtDescription->TabIndex = 3;
            this->txtDescription->Text = L"";
            // 
            // lblComponents
            // 
            this->lblComponents->AutoSize = true;
            this->lblComponents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblComponents->Location = System::Drawing::Point(30, 190);
            this->lblComponents->Name = L"lblComponents";
            this->lblComponents->Size = System::Drawing::Size(119, 20);
            this->lblComponents->TabIndex = 4;
            this->lblComponents->Text = L"Components:";
            // 
            // dgvComponents
            // 
            this->dgvComponents->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvComponents->Location = System::Drawing::Point(150, 190);
            this->dgvComponents->Name = L"dgvComponents";
            this->dgvComponents->RowHeadersWidth = 51;
            this->dgvComponents->RowTemplate->Height = 24;
            this->dgvComponents->Size = System::Drawing::Size(300, 150);
            this->dgvComponents->TabIndex = 5;
            // 
            // btnAddComponent
            // 
            this->btnAddComponent->Location = System::Drawing::Point(150, 350);
            this->btnAddComponent->Name = L"btnAddComponent";
            this->btnAddComponent->Size = System::Drawing::Size(100, 30);
            this->btnAddComponent->TabIndex = 6;
            this->btnAddComponent->Text = L"Add Component";
            this->btnAddComponent->UseVisualStyleBackColor = true;
            this->btnAddComponent->Click += gcnew System::EventHandler(this, &SellProjectForm::AddComponent_Click);
            // 
            // btnRemoveComponent
            // 
            this->btnRemoveComponent->Location = System::Drawing::Point(260, 350);
            this->btnRemoveComponent->Name = L"btnRemoveComponent";
            this->btnRemoveComponent->Size = System::Drawing::Size(100, 30);
            this->btnRemoveComponent->TabIndex = 7;
            this->btnRemoveComponent->Text = L"Remove";
            this->btnRemoveComponent->UseVisualStyleBackColor = true;
            this->btnRemoveComponent->Click += gcnew System::EventHandler(this, &SellProjectForm::RemoveComponent_Click);
            // 
            // lblPrice
            // 
            this->lblPrice->AutoSize = true;
            this->lblPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblPrice->Location = System::Drawing::Point(30, 418);
            this->lblPrice->Name = L"lblPrice";
            this->lblPrice->Size = System::Drawing::Size(59, 20);
            this->lblPrice->TabIndex = 8;
            this->lblPrice->Text = L"Price:";
            this->lblPrice->Click += gcnew System::EventHandler(this, &SellProjectForm::lblPrice_Click);
            // 
            // txtPrice
            // 
            this->txtPrice->Location = System::Drawing::Point(150, 418);
            this->txtPrice->Name = L"txtPrice";
            this->txtPrice->Size = System::Drawing::Size(150, 22);
            this->txtPrice->TabIndex = 9;
            // 
            // lblImage
            // 
            this->lblImage->AutoSize = true;
            this->lblImage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblImage->Location = System::Drawing::Point(500, 30);
            this->lblImage->Name = L"lblImage";
            this->lblImage->Size = System::Drawing::Size(65, 20);
            this->lblImage->TabIndex = 12;
            this->lblImage->Text = L"Image:";
            // 
            // picProjectImage
            // 
            this->picProjectImage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->picProjectImage->Location = System::Drawing::Point(500, 60);
            this->picProjectImage->Name = L"picProjectImage";
            this->picProjectImage->Size = System::Drawing::Size(250, 200);
            this->picProjectImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->picProjectImage->TabIndex = 13;
            this->picProjectImage->TabStop = false;
            // 
            // btnUploadImage
            // 
            this->btnUploadImage->Location = System::Drawing::Point(500, 270);
            this->btnUploadImage->Name = L"btnUploadImage";
            this->btnUploadImage->Size = System::Drawing::Size(120, 30);
            this->btnUploadImage->TabIndex = 14;
            this->btnUploadImage->Text = L"Upload Image";
            this->btnUploadImage->UseVisualStyleBackColor = true;
            this->btnUploadImage->Click += gcnew System::EventHandler(this, &SellProjectForm::UploadImage_Click);
            // 
            // btnSubmit
            // 
            this->btnSubmit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnSubmit->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->btnSubmit->Location = System::Drawing::Point(500, 400);
            this->btnSubmit->Name = L"btnSubmit";
            this->btnSubmit->Size = System::Drawing::Size(120, 40);
            this->btnSubmit->TabIndex = 15;
            this->btnSubmit->Text = L"Submit";
            this->btnSubmit->UseVisualStyleBackColor = false;
            this->btnSubmit->Click += gcnew System::EventHandler(this, &SellProjectForm::Submit_Click);
            // 
            // btnCancel
            // 
            this->btnCancel->Location = System::Drawing::Point(630, 400);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(120, 40);
            this->btnCancel->TabIndex = 16;
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &SellProjectForm::Cancel_Click);
            // 
            // SellProjectForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->ClientSize = System::Drawing::Size(823, 509);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnSubmit);
            this->Controls->Add(this->btnUploadImage);
            this->Controls->Add(this->picProjectImage);
            this->Controls->Add(this->lblImage);
            this->Controls->Add(this->txtPrice);
            this->Controls->Add(this->lblPrice);
            this->Controls->Add(this->btnRemoveComponent);
            this->Controls->Add(this->btnAddComponent);
            this->Controls->Add(this->dgvComponents);
            this->Controls->Add(this->lblComponents);
            this->Controls->Add(this->txtDescription);
            this->Controls->Add(this->lblDescription);
            this->Controls->Add(this->txtProjectTitle);
            this->Controls->Add(this->lblTitle);
            this->Name = L"SellProjectForm";
            this->Text = L"Sell Your Project";
            this->Load += gcnew System::EventHandler(this, &SellProjectForm::Form_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvComponents))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picProjectImage))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void Form_Load(System::Object^ sender, System::EventArgs^ e) {
        // Initialize components data grid
        DataTable^ dt = gcnew DataTable();
        dt->Columns->Add("Component");
        dt->Columns->Add("Description");
        dgvComponents->DataSource = dt;
    }

    private: System::Void AddComponent_Click(System::Object^ sender, System::EventArgs^ e) {
        // Show a dialog to add a new component
        AddComponentForm^ addForm = gcnew AddComponentForm();
        if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            DataTable^ dt = (DataTable^)dgvComponents->DataSource;
            dt->Rows->Add(addForm->ComponentName, addForm->ComponentDescription);
        }
    }

    private: System::Void RemoveComponent_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dgvComponents->SelectedRows->Count > 0) {
            DataTable^ dt = (DataTable^)dgvComponents->DataSource;
            dt->Rows->RemoveAt(dgvComponents->SelectedRows[0]->Index);
        }
    }

    private: System::Void UploadImage_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
        openFileDialog->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.bmp";
        openFileDialog->Title = "Select Project Image";

        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            imagePath = openFileDialog->FileName;
            picProjectImage->Image = Image::FromFile(imagePath);
            array<Byte>^ imageBytes = File::ReadAllBytes(imagePath);
            base64Image = Convert::ToBase64String(imageBytes);
        }
    }

    private: System::Void Submit_Click(System::Object^ sender, System::EventArgs^ e) {
        // Validate inputs
        if (String::IsNullOrEmpty(txtProjectTitle->Text)) {
            MessageBox::Show("Please enter a project title", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (String::IsNullOrEmpty(txtDescription->Text)) {
            MessageBox::Show("Please enter a description", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        double price;
        if (!Double::TryParse(txtPrice->Text, price) || price <= 0) {
            MessageBox::Show("Please enter a valid price", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        //if (cmbCategory->SelectedIndex == -1) {
        //    MessageBox::Show("Please select a category", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        //    return;
        //}

        // Save project to database
        if (SaveProjectToDatabase()) {
            MessageBox::Show("Project submitted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            this->Close();
        }
        else {
            MessageBox::Show("Failed to submit project. Please try again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: bool SaveProjectToDatabase() {
        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ command = gcnew SqlCommand();
        command->Connection = connection;

        try {
            connection->Open();
            SqlTransaction^ transaction = connection->BeginTransaction();
            command->Transaction = transaction;

            try {
                // 1. Save the main project
                command->CommandText = "INSERT INTO Projects (Title, Description, Price, ImagePath) "
                    "VALUES (@Title, @Description, @Price, @ImagePath); SELECT SCOPE_IDENTITY();";
                command->Parameters->AddWithValue("@Title", txtProjectTitle->Text);
                command->Parameters->AddWithValue("@Description", txtDescription->Text);
                command->Parameters->AddWithValue("@Price", txtPrice->Text);
                //command->Parameters->AddWithValue("@Category", cmbCategory->SelectedItem->ToString());
               // command->Parameters->AddWithValue("@SellerId", GetCurrentUserId()); 
                command->Parameters->AddWithValue("@ImagePath", base64Image != nullptr ? base64Image : static_cast<Object^>(DBNull::Value));


                int projectId = Convert::ToInt32(command->ExecuteScalar());

                // 2. Save components
                DataTable^ dt = (DataTable^)dgvComponents->DataSource;
                for each (DataRow ^ row in dt->Rows) {
                    command->Parameters->Clear();
                    command->CommandText = "INSERT INTO ProjectComponents (ProjectId, ComponentName, Description) "
                        "VALUES (@ProjectId, @ComponentName, @Description)";
                    command->Parameters->AddWithValue("@ProjectId", projectId);
                    command->Parameters->AddWithValue("@ComponentName", row["Component"]->ToString());
                    command->Parameters->AddWithValue("@Description", row["Description"]->ToString());
                    command->ExecuteNonQuery();
                }

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
        // Implement to get the actual logged-in user ID
        return 1; // Placeholder
    }

    private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    private: System::Void lblPrice_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}


