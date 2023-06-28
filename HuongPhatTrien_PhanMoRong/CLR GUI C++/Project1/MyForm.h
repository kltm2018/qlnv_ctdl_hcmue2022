#pragma once
#include "LoginAd.h"
#include "LoginEmp.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnAdmin;
	private: System::Windows::Forms::Button^  btnEmp;
	private: System::Windows::Forms::Button^  btnExit;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAdmin = (gcnew System::Windows::Forms::Button());
			this->btnEmp = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(182, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(246, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"QUẢN LÝ NHÂN SỰ";
			// 
			// btnAdmin
			// 
			this->btnAdmin->Location = System::Drawing::Point(78, 93);
			this->btnAdmin->Name = L"btnAdmin";
			this->btnAdmin->Size = System::Drawing::Size(428, 30);
			this->btnAdmin->TabIndex = 1;
			this->btnAdmin->Text = L"Quản trị viên";
			this->btnAdmin->UseVisualStyleBackColor = true;
			this->btnAdmin->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btnEmp
			// 
			this->btnEmp->Location = System::Drawing::Point(78, 153);
			this->btnEmp->Name = L"btnEmp";
			this->btnEmp->Size = System::Drawing::Size(428, 30);
			this->btnEmp->TabIndex = 2;
			this->btnEmp->Text = L"Nhân viên";
			this->btnEmp->UseVisualStyleBackColor = true;
			this->btnEmp->Click += gcnew System::EventHandler(this, &MyForm::btnEmp_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(78, 211);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(428, 30);
			this->btnExit->TabIndex = 3;
			this->btnExit->Text = L"Thoát";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(591, 301);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnEmp);
			this->Controls->Add(this->btnAdmin);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Employee Management";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e){		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		LoginAd ^ epanel = gcnew LoginAd;
		epanel->Show();
	}
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (MessageBox::Show(L"Bạn có muốn thoát?", "Exit Prompt", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) Application::Exit();
	}
	private: System::Void btnEmp_Click(System::Object^  sender, System::EventArgs^  e) {
		LoginEmp ^ epanel = gcnew LoginEmp;
		epanel->Show();
	}
};
}
