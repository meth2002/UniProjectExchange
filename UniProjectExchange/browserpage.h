#pragma once
#include "projectdetailspage.h"
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
    using namespace System::Diagnostics;

    public ref class BrowseProjectsForm : public System::Windows::Forms::Form
    {
    public:
        BrowseProjectsForm(void)
        {
            InitializeComponent();
            connectionString = DatabaseConfig::ConnectionString;
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
    
    private: System::Windows::Forms::ImageList^ imageList1;
    private: System::Windows::Forms::Button^ btnViewDetails;
    
    
   
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
           
            this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
            this->btnViewDetails = (gcnew System::Windows::Forms::Button());
           
            this->SuspendLayout();
             
            // lblTitle
            
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblTitle->Location = System::Drawing::Point(30, 30);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(204, 29);
            this->lblTitle->TabIndex = 0;
            this->lblTitle->Text = L"Browse Projects";
             
            // table Projects
            
            this->lvProjects->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
               this->colTitle,
                    this->colPrice
            });
        
            this->lvProjects->FullRowSelect = true;
            this->lvProjects->GridLines = true;
            this->lvProjects->HideSelection = false;
           // this->lvProjects->LargeImageList = this->imageList1;
            this->lvProjects->Location = System::Drawing::Point(30, 62);
            this->lvProjects->MultiSelect = false;
            this->lvProjects->Name = L"lvProjects";
            this->lvProjects->Size = System::Drawing::Size(740, 368);
            //this->lvProjects->SmallImageList = this->imageList1;
            this->lvProjects->TabIndex = 1;
            this->lvProjects->UseCompatibleStateImageBehavior = false;
            this->lvProjects->View = System::Windows::Forms::View::Details;
            this->lvProjects->SelectedIndexChanged += gcnew System::EventHandler(this, &BrowseProjectsForm::ProjectSelected);
            this->lvProjects->DoubleClick += gcnew System::EventHandler(this, &BrowseProjectsForm::ProjectDoubleClick);
             
            
            // column Title
            
            this->colTitle->Text = L"Title";
            this->colTitle->Width = 250;
            
            // column Price
            
            this->colPrice->Text = L"Price";
            this->colPrice->Width = 100;
            
            // button ViewDetails
            
            this->btnViewDetails->Location = System::Drawing::Point(30, 450);
            this->btnViewDetails->Name = L"btnViewDetails";
            this->btnViewDetails->Size = System::Drawing::Size(150, 40);
            this->btnViewDetails->TabIndex = 2;
            this->btnViewDetails->Text = L"View Details";
            this->btnViewDetails->UseVisualStyleBackColor = true;
            this->btnViewDetails->Click += gcnew System::EventHandler(this, &BrowseProjectsForm::ViewDetails_Click);
            
          
            
            
           
            // BrowseProjectsForm
            
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 500);
           
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
          SqlCommand^ command = gcnew SqlCommand("SELECT ProjectId, Title, Price FROM Projects", connection);

          try {
              connection->Open();
              SqlDataReader^ reader = command->ExecuteReader();

              while (reader->Read()) {
                  String^ id = reader["ProjectId"]->ToString();
                  String^ title = reader["Title"]->ToString();
                  String^ price = "Rs." + Convert::ToDouble(reader["Price"]).ToString("N2");
                 
                  ListViewItem^ item = gcnew ListViewItem(title);
                  item->SubItems->Add(price);
                  item->Tag = id;

             

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
                
                LoadProjects();
            }
        }
    }

    
    private: System::Void BrowseProjectsForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
;}