#pragma once
#include "MyForm.h"




namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminPanel
	/// </summary>
	public ref class AdminPanel : public System::Windows::Forms::Form
	{
	public:
		AdminPanel(void)
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
		~AdminPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(40, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(220, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Thêm Employee";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(40, 75);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(220, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Xoá Employee";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(40, 111);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(220, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Tìm Employee";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminPanel::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(40, 148);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(220, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Cập nhật Employee";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(40, 186);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(220, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Hiển thị thông tin Employee";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(40, 262);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(220, 23);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Thoát";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &AdminPanel::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(40, 223);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(220, 23);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Trở về trang tuỳ chọn đăng nhập";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &AdminPanel::button7_Click);
			// 
			// AdminPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 297);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"AdminPanel";
			this->Text = L"AdminPanel";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show(L"Bạn có muốn thoát?", "Exit Prompt", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) Application::Exit();
	}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
//	MyForm ^ apanel = gcnew MyForm;
//	apanel->Show();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
