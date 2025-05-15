#pragma once
#pragma once

namespace UniProjectExchange {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class AddComponentForm : public System::Windows::Forms::Form
    {
    public:
        AddComponentForm(void)
        {
            InitializeComponent();
        }

        // Properties to expose the entered component details
        property String^ ComponentName
        {
            String^ get() { return txtName->Text; }
        }

        property String^ ComponentDescription
        {
            String^ get() { return txtDescription->Text; }
        }

    protected:
        ~AddComponentForm()
        {
            if (components)
                delete components;
        }

    private:
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::Label^ lblDescription;
        System::Windows::Forms::TextBox^ txtDescription;
        System::Windows::Forms::Button^ btnOK;
        System::Windows::Forms::Button^ btnCancel;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->lblName = (gcnew System::Windows::Forms::Label());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->lblDescription = (gcnew System::Windows::Forms::Label());
            this->txtDescription = (gcnew System::Windows::Forms::TextBox());
            this->btnOK = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // 
            // lblName
            // 
            this->lblName->AutoSize = true;
            this->lblName->Location = System::Drawing::Point(20, 20);
            this->lblName->Name = L"lblName";
            this->lblName->Size = System::Drawing::Size(101, 17);
            this->lblName->Text = L"Component Name:";
            // 
            // txtName
            // 
            this->txtName->Location = System::Drawing::Point(20, 45);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(300, 22);
            // 
            // lblDescription
            // 
            this->lblDescription->AutoSize = true;
            this->lblDescription->Location = System::Drawing::Point(20, 80);
            this->lblDescription->Name = L"lblDescription";
            this->lblDescription->Size = System::Drawing::Size(79, 17);
            this->lblDescription->Text = L"Description:";
            // 
            // txtDescription
            // 
            this->txtDescription->Location = System::Drawing::Point(20, 105);
            this->txtDescription->Multiline = true;
            this->txtDescription->Name = L"txtDescription";
            this->txtDescription->Size = System::Drawing::Size(300, 80);
            // 
            // btnOK
            // 
            this->btnOK->Location = System::Drawing::Point(50, 200);
            this->btnOK->Name = L"btnOK";
            this->btnOK->Size = System::Drawing::Size(100, 30);
            this->btnOK->Text = L"OK";
            this->btnOK->UseVisualStyleBackColor = true;
            this->btnOK->Click += gcnew System::EventHandler(this, &AddComponentForm::btnOK_Click);
            // 
            // btnCancel
            // 
            this->btnCancel->Location = System::Drawing::Point(180, 200);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(100, 30);
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &AddComponentForm::btnCancel_Click);
            // 
            // AddComponentForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(350, 250);
            this->Controls->Add(this->lblName);
            this->Controls->Add(this->txtName);
            this->Controls->Add(this->lblDescription);
            this->Controls->Add(this->txtDescription);
            this->Controls->Add(this->btnOK);
            this->Controls->Add(this->btnCancel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"AddComponentForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Add Component";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        // Event handlers
        void btnOK_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (String::IsNullOrWhiteSpace(txtName->Text))
            {
                MessageBox::Show("Component Name cannot be empty.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }

        void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close();
        }
    };
}
