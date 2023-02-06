#pragma once

namespace EmployeeDB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConnect = gcnew MySqlConnection();
		MySqlCommand^ sqlCommand = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlAdapter = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlReader;
	private: System::Windows::Forms::Button^ refreshBtn;

		   DataTable^ sqlTable = gcnew DataTable();


	public:
		MyForm(void)
		{
			InitializeComponent();
			employeeDB();
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
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ genderCB;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ addressTextBox;
	private: System::Windows::Forms::Label^ adressLabel;
	private: System::Windows::Forms::TextBox^ lastTextBox;
	private: System::Windows::Forms::Label^ lastLabel;
	private: System::Windows::Forms::TextBox^ postTextBox;
	private: System::Windows::Forms::TextBox^ firstTextBox;
	private: System::Windows::Forms::Label^ postLabel;
	private: System::Windows::Forms::TextBox^ phoneTextBox;
	private: System::Windows::Forms::Label^ firstLabel;
	private: System::Windows::Forms::Label^ phoneLabel;
	private: System::Windows::Forms::TextBox^ idTextBox;
	private: System::Windows::Forms::Label^ IDLabel;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ exitBtn;
	private: System::Windows::Forms::Button^ ClearBtn;
	private: System::Windows::Forms::Button^ editBtn;
	private: System::Windows::Forms::Button^ deleteBtn;
	private: System::Windows::Forms::Button^ addBtn;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ startLB;

	private: System::Windows::Forms::Button^ searchBtn;
	private: System::Windows::Forms::TextBox^ searchTextBox;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ birthLB;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->birthLB = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->startLB = (gcnew System::Windows::Forms::Label());
			this->searchBtn = (gcnew System::Windows::Forms::Button());
			this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->genderCB = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->addressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->adressLabel = (gcnew System::Windows::Forms::Label());
			this->lastTextBox = (gcnew System::Windows::Forms::TextBox());
			this->lastLabel = (gcnew System::Windows::Forms::Label());
			this->postTextBox = (gcnew System::Windows::Forms::TextBox());
			this->firstTextBox = (gcnew System::Windows::Forms::TextBox());
			this->postLabel = (gcnew System::Windows::Forms::Label());
			this->phoneTextBox = (gcnew System::Windows::Forms::TextBox());
			this->firstLabel = (gcnew System::Windows::Forms::Label());
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->idTextBox = (gcnew System::Windows::Forms::TextBox());
			this->IDLabel = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->refreshBtn = (gcnew System::Windows::Forms::Button());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->ClearBtn = (gcnew System::Windows::Forms::Button());
			this->editBtn = (gcnew System::Windows::Forms::Button());
			this->deleteBtn = (gcnew System::Windows::Forms::Button());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->dateTimePicker2);
			this->panel1->Controls->Add(this->birthLB);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Controls->Add(this->startLB);
			this->panel1->Controls->Add(this->searchBtn);
			this->panel1->Controls->Add(this->searchTextBox);
			this->panel1->Controls->Add(this->genderCB);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->addressTextBox);
			this->panel1->Controls->Add(this->adressLabel);
			this->panel1->Controls->Add(this->lastTextBox);
			this->panel1->Controls->Add(this->lastLabel);
			this->panel1->Controls->Add(this->postTextBox);
			this->panel1->Controls->Add(this->firstTextBox);
			this->panel1->Controls->Add(this->postLabel);
			this->panel1->Controls->Add(this->phoneTextBox);
			this->panel1->Controls->Add(this->firstLabel);
			this->panel1->Controls->Add(this->phoneLabel);
			this->panel1->Controls->Add(this->idTextBox);
			this->panel1->Controls->Add(this->IDLabel);
			this->panel1->Location = System::Drawing::Point(28, 26);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1068, 182);
			this->panel1->TabIndex = 0;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->AllowDrop = true;
			this->dateTimePicker2->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker2->Cursor = System::Windows::Forms::Cursors::Default;
			this->dateTimePicker2->Location = System::Drawing::Point(840, 98);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(197, 20);
			this->dateTimePicker2->TabIndex = 10;
			// 
			// birthLB
			// 
			this->birthLB->AutoSize = true;
			this->birthLB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->birthLB->Location = System::Drawing::Point(716, 92);
			this->birthLB->Name = L"birthLB";
			this->birthLB->Size = System::Drawing::Size(100, 29);
			this->birthLB->TabIndex = 9;
			this->birthLB->Text = L"Birthday";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->AllowDrop = true;
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dateTimePicker1->Location = System::Drawing::Point(840, 65);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(197, 20);
			this->dateTimePicker1->TabIndex = 8;
			// 
			// startLB
			// 
			this->startLB->AutoSize = true;
			this->startLB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startLB->Location = System::Drawing::Point(716, 59);
			this->startLB->Name = L"startLB";
			this->startLB->Size = System::Drawing::Size(118, 29);
			this->startLB->TabIndex = 5;
			this->startLB->Text = L"Start Date";
			// 
			// searchBtn
			// 
			this->searchBtn->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->searchBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchBtn->Location = System::Drawing::Point(919, 23);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(98, 30);
			this->searchBtn->TabIndex = 1;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = false;
			this->searchBtn->Click += gcnew System::EventHandler(this, &MyForm::searchBtn_Click);
			// 
			// searchTextBox
			// 
			this->searchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTextBox->Location = System::Drawing::Point(721, 24);
			this->searchTextBox->Name = L"searchTextBox";
			this->searchTextBox->Size = System::Drawing::Size(192, 29);
			this->searchTextBox->TabIndex = 4;
			// 
			// genderCB
			// 
			this->genderCB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->genderCB->FormattingEnabled = true;
			this->genderCB->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->genderCB->Location = System::Drawing::Point(491, 96);
			this->genderCB->Name = L"genderCB";
			this->genderCB->Size = System::Drawing::Size(121, 28);
			this->genderCB->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(365, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Gender";
			// 
			// addressTextBox
			// 
			this->addressTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addressTextBox->Location = System::Drawing::Point(143, 127);
			this->addressTextBox->Name = L"addressTextBox";
			this->addressTextBox->Size = System::Drawing::Size(316, 29);
			this->addressTextBox->TabIndex = 1;
			// 
			// adressLabel
			// 
			this->adressLabel->AutoSize = true;
			this->adressLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adressLabel->Location = System::Drawing::Point(17, 127);
			this->adressLabel->Name = L"adressLabel";
			this->adressLabel->Size = System::Drawing::Size(102, 29);
			this->adressLabel->TabIndex = 0;
			this->adressLabel->Text = L"Address";
			// 
			// lastTextBox
			// 
			this->lastTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastTextBox->Location = System::Drawing::Point(143, 93);
			this->lastTextBox->Name = L"lastTextBox";
			this->lastTextBox->Size = System::Drawing::Size(199, 29);
			this->lastTextBox->TabIndex = 1;
			// 
			// lastLabel
			// 
			this->lastLabel->AutoSize = true;
			this->lastLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastLabel->Location = System::Drawing::Point(17, 92);
			this->lastLabel->Name = L"lastLabel";
			this->lastLabel->Size = System::Drawing::Size(117, 29);
			this->lastLabel->TabIndex = 0;
			this->lastLabel->Text = L"Lastname";
			// 
			// postTextBox
			// 
			this->postTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->postTextBox->Location = System::Drawing::Point(491, 24);
			this->postTextBox->Name = L"postTextBox";
			this->postTextBox->Size = System::Drawing::Size(199, 29);
			this->postTextBox->TabIndex = 1;
			// 
			// firstTextBox
			// 
			this->firstTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->firstTextBox->Location = System::Drawing::Point(143, 58);
			this->firstTextBox->Name = L"firstTextBox";
			this->firstTextBox->Size = System::Drawing::Size(199, 29);
			this->firstTextBox->TabIndex = 1;
			// 
			// postLabel
			// 
			this->postLabel->AutoSize = true;
			this->postLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->postLabel->Location = System::Drawing::Point(365, 23);
			this->postLabel->Name = L"postLabel";
			this->postLabel->Size = System::Drawing::Size(115, 29);
			this->postLabel->TabIndex = 0;
			this->postLabel->Text = L"Postcode";
			// 
			// phoneTextBox
			// 
			this->phoneTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneTextBox->Location = System::Drawing::Point(491, 59);
			this->phoneTextBox->Name = L"phoneTextBox";
			this->phoneTextBox->Size = System::Drawing::Size(199, 29);
			this->phoneTextBox->TabIndex = 1;
			// 
			// firstLabel
			// 
			this->firstLabel->AutoSize = true;
			this->firstLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->firstLabel->Location = System::Drawing::Point(17, 57);
			this->firstLabel->Name = L"firstLabel";
			this->firstLabel->Size = System::Drawing::Size(120, 29);
			this->firstLabel->TabIndex = 0;
			this->firstLabel->Text = L"Firstname";
			// 
			// phoneLabel
			// 
			this->phoneLabel->AutoSize = true;
			this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneLabel->Location = System::Drawing::Point(365, 58);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Size = System::Drawing::Size(83, 29);
			this->phoneLabel->TabIndex = 0;
			this->phoneLabel->Text = L"Phone";
			// 
			// idTextBox
			// 
			this->idTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idTextBox->Location = System::Drawing::Point(143, 23);
			this->idTextBox->Name = L"idTextBox";
			this->idTextBox->Size = System::Drawing::Size(199, 29);
			this->idTextBox->TabIndex = 1;
			// 
			// IDLabel
			// 
			this->IDLabel->AutoSize = true;
			this->IDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IDLabel->Location = System::Drawing::Point(17, 22);
			this->IDLabel->Name = L"IDLabel";
			this->IDLabel->Size = System::Drawing::Size(36, 29);
			this->IDLabel->TabIndex = 0;
			this->IDLabel->Text = L"ID";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->refreshBtn);
			this->panel2->Controls->Add(this->exitBtn);
			this->panel2->Controls->Add(this->ClearBtn);
			this->panel2->Controls->Add(this->editBtn);
			this->panel2->Controls->Add(this->deleteBtn);
			this->panel2->Controls->Add(this->addBtn);
			this->panel2->Location = System::Drawing::Point(28, 223);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(493, 48);
			this->panel2->TabIndex = 0;
			// 
			// refreshBtn
			// 
			this->refreshBtn->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->refreshBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->refreshBtn->Location = System::Drawing::Point(327, 3);
			this->refreshBtn->Name = L"refreshBtn";
			this->refreshBtn->Size = System::Drawing::Size(75, 38);
			this->refreshBtn->TabIndex = 1;
			this->refreshBtn->Text = L"Refresh";
			this->refreshBtn->UseVisualStyleBackColor = false;
			this->refreshBtn->Click += gcnew System::EventHandler(this, &MyForm::refreshBtn_Click);
			// 
			// exitBtn
			// 
			this->exitBtn->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->exitBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitBtn->Location = System::Drawing::Point(408, 3);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(75, 38);
			this->exitBtn->TabIndex = 0;
			this->exitBtn->Text = L"Exit";
			this->exitBtn->UseVisualStyleBackColor = false;
			this->exitBtn->Click += gcnew System::EventHandler(this, &MyForm::exitBtn_Click);
			// 
			// ClearBtn
			// 
			this->ClearBtn->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClearBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClearBtn->Location = System::Drawing::Point(246, 3);
			this->ClearBtn->Name = L"ClearBtn";
			this->ClearBtn->Size = System::Drawing::Size(75, 38);
			this->ClearBtn->TabIndex = 0;
			this->ClearBtn->Text = L"Clear";
			this->ClearBtn->UseVisualStyleBackColor = false;
			this->ClearBtn->Click += gcnew System::EventHandler(this, &MyForm::ClearBtn_Click);
			// 
			// editBtn
			// 
			this->editBtn->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->editBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editBtn->Location = System::Drawing::Point(165, 3);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(75, 38);
			this->editBtn->TabIndex = 0;
			this->editBtn->Text = L"Edit";
			this->editBtn->UseVisualStyleBackColor = false;
			this->editBtn->Click += gcnew System::EventHandler(this, &MyForm::editBtn_Click);
			// 
			// deleteBtn
			// 
			this->deleteBtn->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->deleteBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteBtn->Location = System::Drawing::Point(84, 3);
			this->deleteBtn->Name = L"deleteBtn";
			this->deleteBtn->Size = System::Drawing::Size(75, 38);
			this->deleteBtn->TabIndex = 0;
			this->deleteBtn->Text = L"Delete";
			this->deleteBtn->UseVisualStyleBackColor = false;
			this->deleteBtn->Click += gcnew System::EventHandler(this, &MyForm::deleteBtn_Click);
			// 
			// addBtn
			// 
			this->addBtn->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addBtn->Location = System::Drawing::Point(3, 3);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(75, 38);
			this->addBtn->TabIndex = 0;
			this->addBtn->Text = L"Add";
			this->addBtn->UseVisualStyleBackColor = false;
			this->addBtn->Click += gcnew System::EventHandler(this, &MyForm::addBtn_Click);
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->dataGridView1);
			this->panel3->Location = System::Drawing::Point(28, 290);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1068, 259);
			this->panel3->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1058, 249);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1108, 561);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"EmployeeDB";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void employeeDB() {
		try {
			sqlConnect->ConnectionString = "datasource=localhost; port=3306; username=newuser; password=1234; database=employeedb";
			sqlConnect->Open();
			sqlCommand->Connection = sqlConnect;
			sqlCommand->CommandText = "select * from employeedb";
			sqlReader = sqlCommand->ExecuteReader();
			sqlTable->Load(sqlReader);
			sqlConnect->Close();
			sqlReader->Close();
			dataGridView1->DataSource = sqlTable;
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
			sqlConnect->Close();
		}
		
	}

	private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			sqlConnect->ConnectionString = "datasource=localhost; port=3306; username=newuser; password=1234; database=employeedb";
			sqlConnect->Open();
			sqlCommand->Connection = sqlConnect;
			sqlCommand->CommandText = "insert into employeedb (ID, Firstname, Lastname, Address, " +
				"Postcode, Phone, Gender, Startdate, Birthday)"
				"value('" + idTextBox->Text + "','" + firstTextBox->Text + "','" + lastTextBox->Text + "','" +
				addressTextBox->Text + "','" + postTextBox->Text + "','" + phoneTextBox->Text + "','" + genderCB->Text + "','" +
				dateTimePicker1->Text + "','" + dateTimePicker2->Text + "')";
			sqlCommand->ExecuteNonQuery();
			sqlConnect->Close();
			employeeDB();
			RefreshDB();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
			sqlConnect->Close();
		}
		
	}
	private: System::Void deleteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			sqlConnect->ConnectionString = "datasource=localhost; port=3306; username=newuser; password=1234; database=employeedb";
			sqlCommand->Connection = sqlConnect;
			sqlConnect->Open();

			String^ ID = idTextBox->Text;
			sqlCommand->CommandText = "delete from employeedb where ID =" + ID + "", sqlConnect;
			sqlCommand->ExecuteNonQuery();

			MessageBox::Show("Deleted", "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
			sqlConnect->Close();
			employeeDB();
			RefreshDB();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
			sqlConnect->Close();
		}
	}

	private: System::Void editBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			sqlConnect->ConnectionString = "datasource=localhost; port=3306; username=newuser; password=1234; database=employeedb";
			sqlCommand->Connection = sqlConnect;
			sqlConnect->Open();

			String^ ID = idTextBox->Text;
			String^ Firstname = firstTextBox->Text;
			String^ Lastname = lastTextBox->Text;
			String^ Address = addressTextBox->Text;
			String^ Postcode = postTextBox->Text;
			String^ Phone = phoneTextBox->Text;
			String^ Gender = genderCB->Text;
			String^ Startdate = dateTimePicker1->Text;
			String^ Birthday = dateTimePicker2->Text;

			sqlCommand->CommandText = "update employeedb set ID = '" + ID + "', Firstname = '" + Firstname +
				"', Lastname = '" + Lastname + "', Address = '" + Address + "', Postcode = '" + Postcode +
				"', Phone = '" + Phone + "', Gender = '" + Gender + "', Startdate = '" + Startdate +
				"', Birthday = '" + Birthday + "' Where ID = " + ID + "", sqlConnect;

			sqlCommand->ExecuteNonQuery();
			sqlConnect->Close();
			employeeDB();
			RefreshDB();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
			sqlConnect->Close();
		}
	}

	

	private: System::Void ClearBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			idTextBox->Text = "";
			firstTextBox->Text = "";
			lastTextBox->Text = "";
			addressTextBox->Text = "";
			postTextBox->Text = "";
			phoneTextBox->Text = "";
			genderCB->Text = "";
			searchTextBox->Text = "";
			dateTimePicker1->ResetText();
			dateTimePicker2->ResetText();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		}
	}

	private: System::Void RefreshDB()
	{
		try {
			sqlConnect->ConnectionString = "datasource=localhost; port=3306; username=newuser; password=1234; database=employeedb";
			sqlCommand->Connection = sqlConnect;
			MySqlDataAdapter^ sqlAdapter = gcnew MySqlDataAdapter("Select * from employeedb", sqlConnect);
			DataTable^ sqlTable = gcnew DataTable();
			sqlAdapter->Fill(sqlTable);
			dataGridView1->DataSource = sqlTable;
			sqlConnect->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
			sqlConnect->Close();
		}
	}

	private: System::Void refreshBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		RefreshDB();
	}

	private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult exit;
		try {
			exit = MessageBox::Show("Do you want exit?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (exit == System::Windows::Forms::DialogResult::Yes) {
				Application::Exit();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		}
	}
	
	private: System::Void searchBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			DataView^ dataview = sqlTable->DefaultView;
			dataview->RowFilter = String::Format("Firstname like '%{0}%'", searchTextBox->Text);
			dataGridView1->DataSource = dataview->ToTable();

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		}
	}
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		try {
			idTextBox->Text = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
			firstTextBox->Text = dataGridView1->SelectedRows[0]->Cells[1]->Value->ToString();
			lastTextBox->Text = dataGridView1->SelectedRows[0]->Cells[2]->Value->ToString();
			addressTextBox->Text = dataGridView1->SelectedRows[0]->Cells[3]->Value->ToString();
			postTextBox->Text = dataGridView1->SelectedRows[0]->Cells[4]->Value->ToString();
			phoneTextBox->Text = dataGridView1->SelectedRows[0]->Cells[5]->Value->ToString();
			genderCB->Text = dataGridView1->SelectedRows[0]->Cells[6]->Value->ToString();
			dateTimePicker1->Text = dataGridView1->SelectedRows[0]->Cells[7]->Value->ToString();
			dateTimePicker2->Text = dataGridView1->SelectedRows[0]->Cells[8]->Value->ToString();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		}

	}


};
}
