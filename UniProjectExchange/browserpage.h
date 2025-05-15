#pragma once

namespace UniProjectExchange {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class BrowseProjectsForm : public System::Windows::Forms::Form
    {
    public:
        BrowseProjectsForm(void)
        {
            InitializeComponent();
            connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=UniProjectExchange;Integrated Security=True;Encrypt=True;Trust Server Certificate=True";
            LoadProjects();
        }

    protected:
        ~BrowseProjectsForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ lblTitle;
    private: System::Windows::Forms::ListView^ lvProjects;
    private: System::Windows::Forms::ColumnHeader^ colImage;
    private: System::Windows::Forms::ColumnHeader^ colTitle;
    private: System::Windows::Forms::ColumnHeader^ colPrice;
    private: System::Windows::Forms::ColumnHeader^ colCategory;
    private: System::Windows::Forms::ImageList^ imageList1;
    private: System::Windows::Forms::Button^ btnViewDetails;
    private: System::Windows::Forms::Button^ btnRefresh;
    private: System::Windows::Forms::ComboBox^ cmbFilter;
    private: System::Windows::Forms::Label^ lblFilter;
    private: System::Windows::Forms::Button^ btnApplyFilter;
    private: String^ connectionString;
    private: System::ComponentModel::IContainer^ components;

    private:


#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->lvProjects = (gcnew System::Windows::Forms::ListView());
            this->colImage = (gcnew System::Windows::Forms::ColumnHeader());
            this->colTitle = (gcnew System::Windows::Forms::ColumnHeader());
            this->colPrice = (gcnew System::Windows::Forms::ColumnHeader());
            this->colCategory = (gcnew System::Windows::Forms::ColumnHeader());
            this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
            this->btnViewDetails = (gcnew System::Windows::Forms::Button());
            this->btnRefresh = (gcnew System::Windows::Forms::Button());
            this->cmbFilter = (gcnew System::Windows::Forms::ComboBox());
            this->lblFilter = (gcnew System::Windows::Forms::Label());
            this->btnApplyFilter = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // lblTitle
            // 
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblTitle->Location = System::Drawing::Point(30, 30);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(204, 29);
            this->lblTitle->TabIndex = 0;
            this->lblTitle->Text = L"Browse Projects";
            // 
            // lvProjects
            // 
            this->lvProjects->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
                this->colImage, this->colTitle,
                    this->colPrice, this->colCategory
            });
            this->lvProjects->FullRowSelect = true;
            this->lvProjects->GridLines = true;
            this->lvProjects->HideSelection = false;
            this->lvProjects->LargeImageList = this->imageList1;
            this->lvProjects->Location = System::Drawing::Point(30, 62);
            this->lvProjects->MultiSelect = false;
            this->lvProjects->Name = L"lvProjects";
            this->lvProjects->Size = System::Drawing::Size(740, 368);
            this->lvProjects->SmallImageList = this->imageList1;
            this->lvProjects->TabIndex = 1;
            this->lvProjects->UseCompatibleStateImageBehavior = false;
            this->lvProjects->View = System::Windows::Forms::View::Details;
            this->lvProjects->SelectedIndexChanged += gcnew System::EventHandler(this, &BrowseProjectsForm::ProjectSelected);
            this->lvProjects->DoubleClick += gcnew System::EventHandler(this, &BrowseProjectsForm::ProjectDoubleClick);
            // 
            // colImage
            // 
            this->colImage->Text = L"Image";
            this->colImage->Width = 150;
            // 
            // colTitle
            // 
            this->colTitle->Text = L"Title";
            this->colTitle->Width = 250;
            // 
            // colPrice
            // 
            this->colPrice->Text = L"Price";
            this->colPrice->Width = 100;
            // 
            // colCategory
            // 
            this->colCategory->Text = L"Category";
            this->colCategory->Width = 150;
            // 
            // imageList1
            // 
            this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
            this->imageList1->ImageSize = System::Drawing::Size(16, 16);
            this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
            // 
            // btnViewDetails
            // 
            this->btnViewDetails->Location = System::Drawing::Point(30, 450);
            this->btnViewDetails->Name = L"btnViewDetails";
            this->btnViewDetails->Size = System::Drawing::Size(150, 40);
            this->btnViewDetails->TabIndex = 2;
            this->btnViewDetails->Text = L"View Details";
            this->btnViewDetails->UseVisualStyleBackColor = true;
            this->btnViewDetails->Click += gcnew System::EventHandler(this, &BrowseProjectsForm::ViewDetails_Click);
            // 
            // btnRefresh
            // 
            this->btnRefresh->Location = System::Drawing::Point(620, 450);
            this->btnRefresh->Name = L"btnRefresh";
            this->btnRefresh->Size = System::Drawing::Size(150, 40);
            this->btnRefresh->TabIndex = 3;
            this->btnRefresh->Text = L"Refresh";
            this->btnRefresh->UseVisualStyleBackColor = true;
            this->btnRefresh->Click += gcnew System::EventHandler(this, &BrowseProjectsForm::Refresh_Click);
            // 
            // cmbFilter
            // 
            this->cmbFilter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbFilter->FormattingEnabled = true;
            this->cmbFilter->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
                L"All Categories", L"Software", L"Hardware", L"Research",
                    L"Design", L"Other"
            });
            this->cmbFilter->Location = System::Drawing::Point(500, 30);
            this->cmbFilter->Name = L"cmbFilter";
            this->cmbFilter->Size = System::Drawing::Size(150, 24);
            this->cmbFilter->TabIndex = 4;
            // 
            // lblFilter
            // 
            this->lblFilter->AutoSize = true;
            this->lblFilter->Location = System::Drawing::Point(450, 33);
            this->lblFilter->Name = L"lblFilter";
            this->lblFilter->Size = System::Drawing::Size(39, 16);
            this->lblFilter->TabIndex = 5;
            this->lblFilter->Text = L"Filter:";
            // 
            // btnApplyFilter
            // 
            this->btnApplyFilter->Location = System::Drawing::Point(660, 30);
            this->btnApplyFilter->Name = L"btnApplyFilter";
            this->btnApplyFilter->Size = System::Drawing::Size(110, 25);
            this->btnApplyFilter->TabIndex = 6;
            this->btnApplyFilter->Text = L"Apply Filter";
            this->btnApplyFilter->UseVisualStyleBackColor = true;
            this->btnApplyFilter->Click += gcnew System::EventHandler(this, &BrowseProjectsForm::ApplyFilter_Click);
            // 
            // BrowseProjectsForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 500);
            this->Controls->Add(this->btnApplyFilter);
            this->Controls->Add(this->lblFilter);
            this->Controls->Add(this->cmbFilter);
            this->Controls->Add(this->btnRefresh);
            this->Controls->Add(this->btnViewDetails);
            this->Controls->Add(this->lvProjects);
            this->Controls->Add(this->lblTitle);
            this->Name = L"BrowseProjectsForm";
            this->Text = L"Browse Projects";
            this->Load += gcnew System::EventHandler(this, &BrowseProjectsForm::BrowseProjectsForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: void LoadProjects() {
        lvProjects->Items->Clear();

        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ command = gcnew SqlCommand("SELECT Id, Title, Price, Category, ImagePath FROM Projects", connection);

        try {
            connection->Open();
            SqlDataReader^ reader = command->ExecuteReader();

            while (reader->Read()) {
                String^ id = reader["Id"]->ToString();
                String^ title = reader["Title"]->ToString();
                String^ price = "$" + Convert::ToDouble(reader["Price"]).ToString("N2");
                String^ category = reader["Category"]->ToString();
                String^ imagePath = reader["ImagePath"] != DBNull::Value ? reader["ImagePath"]->ToString() : "";

                ListViewItem^ item = gcnew ListViewItem(title);
                item->SubItems->Add(price);
                item->SubItems->Add(category);
                item->Tag = id; // Store project ID in Tag

                // Load image if available
                if (!String::IsNullOrEmpty(imagePath) && File::Exists(imagePath)) {
                    try {
                        Image^ img = Image::FromFile(imagePath);
                        imageList1->Images->Add(img);
                        item->ImageIndex = imageList1->Images->Count - 1;
                    }
                    catch (...) {
                        item->ImageIndex = 0; // Use default image
                    }
                }
                else {
                    item->ImageIndex = 0; // Use default image
                }

                lvProjects->Items->Add(item);
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading projects: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (connection->State == ConnectionState::Open)
                connection->Close();
        }
    }

    private: System::Void ProjectSelected(System::Object^ sender, System::EventArgs^ e) {
        btnViewDetails->Enabled = lvProjects->SelectedItems->Count > 0;
    }

    private: System::Void ProjectDoubleClick(System::Object^ sender, System::EventArgs^ e) {
        if (lvProjects->SelectedItems->Count > 0) {
            ViewProjectDetails();
        }
    }

    private: System::Void ViewDetails_Click(System::Object^ sender, System::EventArgs^ e) {
        ViewProjectDetails();
    }

    private: void ViewProjectDetails() {
        if (lvProjects->SelectedItems->Count > 0) {
            String^ projectId = lvProjects->SelectedItems[0]->Tag->ToString();
            ProjectDetailsForm^ detailsForm = gcnew ProjectDetailsForm(projectId);
            if (detailsForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                // Refresh if purchase was made
                LoadProjects();
            }
        }
    }

    private: System::Void Refresh_Click(System::Object^ sender, System::EventArgs^ e) {
        LoadProjects();
    }

    private: System::Void ApplyFilter_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ filter = cmbFilter->SelectedItem != nullptr ? cmbFilter->SelectedItem->ToString() : "All Categories";

        if (filter == "All Categories") {
            foreach(ListViewItem ^ item in lvProjects->Items) {
                item->Hidden = false;
            }
        }
        else {
            foreach(ListViewItem ^ item in lvProjects->Items) {
                item->Hidden = (item->SubItems[2]->Text != filter);
            }
        }
    }
    private: System::Void BrowseProjectsForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}