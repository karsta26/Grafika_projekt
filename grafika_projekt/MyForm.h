#pragma once
#define cimg_use_tiff
#include "CImg.h"
using namespace cimg_library;
#include <string>
#include "Transform.h"

typedef float myType;

namespace grafika_projekt {

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
			this->label3->Text = "0";
			this->label4->Text = "1-8";
			openFileDialog1->Filter = "Tiff Files|*.tif|Tiff Files|*.tiff";
			openFileDialog1->Title = "Select a Tiff File";
			saveFileDialog1->Filter = "Bmp Files|*.bmp";
			saveFileDialog1->Title = "Select a bmp File";
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
				if (originImage)
					delete originImage;
				if (currentImage)
					delete currentImage;
			}
			
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
		System::String^ name;
		CImg<myType>* originImage;
		CImg<myType>* currentImage;
		Bitmap^ image1;
		
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::HScrollBar^  hScrollBar2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  button6;



	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(48, 34);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Otwórz";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(24, 70);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 28);
			this->button2->TabIndex = 1;
			this->button2->Text = L"kompresja liniowa";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(24, 114);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(159, 28);
			this->button3->TabIndex = 2;
			this->button3->Text = L"krzywa gamma";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(24, 270);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(159, 27);
			this->button4->TabIndex = 3;
			this->button4->Text = L"bez kompresji";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->LargeChange = 9;
			this->hScrollBar1->Location = System::Drawing::Point(24, 374);
			this->hScrollBar1->Maximum = 17;
			this->hScrollBar1->Minimum = 1;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(159, 17);
			this->hScrollBar1->TabIndex = 4;
			this->hScrollBar1->Value = 1;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(44, 158);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"wybierz wsp. gamma";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 313);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(157, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"wybierz 8-bitowy zakres";
			// 
			// hScrollBar2
			// 
			this->hScrollBar2->LargeChange = 1;
			this->hScrollBar2->Location = System::Drawing::Point(20, 223);
			this->hScrollBar2->Maximum = 30;
			this->hScrollBar2->Name = L"hScrollBar2";
			this->hScrollBar2->Size = System::Drawing::Size(163, 17);
			this->hScrollBar2->TabIndex = 7;
			this->hScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar2_Scroll);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(48, 427);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 28);
			this->button5->TabIndex = 8;
			this->button5->Text = L"zapisz obraz";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(101, 185);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 17);
			this->label3->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(101, 345);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 17);
			this->label4->TabIndex = 10;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->MinimumSize = System::Drawing::Size(600, 492);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(672, 506);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(211, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->MinimumSize = System::Drawing::Size(400, 369);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(672, 506);
			this->panel1->TabIndex = 12;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->hScrollBar2);
			this->panel2->Controls->Add(this->hScrollBar1);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(211, 506);
			this->panel2->TabIndex = 13;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(47, 468);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(105, 26);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Histogram\r\n";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel1);
			this->panel3->Controls->Add(this->panel2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(883, 506);
			this->panel3->TabIndex = 14;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(883, 506);
			this->Controls->Add(this->panel3);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(861, 543);
			this->Name = L"MyForm";
			this->Text = L"Obraz 16 bitowy";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (originImage)
			delete originImage;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			name = (gcnew System::String(openFileDialog1->FileName));
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
			originImage = new CImg<myType>();
			originImage->load_tiff(chars);
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			MessageBox::Show("Wczytano obrazek!");
		}
		else
		{
			MessageBox::Show("Wysp¹pi³ b³¹d!");
		}
	}
	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		this->label4->Text = System::String::Concat(System::Convert::ToString(e->NewValue), "-", System::Convert::ToString(e->NewValue + 7));
	}

	private: System::Void hScrollBar2_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		this->label3->Text = System::Convert::ToString(System::Convert::ToDouble(e->NewValue)/10.0);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//
		//tutaj wywolac funkcje wyswietlajaca obraz dla kompresji liniowej
		//
		if (!originImage)
		{
			MessageBox::Show("Najpierw stwórz obrazek");
			return;
		}
		CImg<myType> img = Transform::LinearTo8Bit(*originImage);
		if (currentImage)
			delete currentImage;
		currentImage = new CImg<myType>(img);
		changeDisplayImage(img);
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//
		//tutaj pokazujemy obraz na podstawie krzywej gamma
		//
		if (!originImage)
		{
			MessageBox::Show("Najpierw stwórz obrazek");
			return;
		}
		double gamma = this->hScrollBar2->Value;
		CImg<myType> img = Transform::GammaCurve(*originImage, gamma);
		if (currentImage)
			delete currentImage;
		currentImage = new CImg<myType>(img);
		changeDisplayImage(img);
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		//
		//tutaj wycinamy 8-bitowy zakres
		//
		if (!originImage)
		{
			MessageBox::Show("Najpierw stwórz obrazek");
			return;
		}
		int from = this->hScrollBar1->Value;
		CImg<myType> img = Transform::BitPerBit(*originImage, from, from+8);
		if (currentImage)
			delete currentImage;
		currentImage = new CImg<myType>(img);
		changeDisplayImage(img);
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		//
		//zapisywanie obrazu do pliku
		//
		if (!currentImage)
		{
			MessageBox::Show("Najpierw stwórz obrazek");
			return;
		}
			
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			name = (gcnew System::String(saveFileDialog1->FileName));
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
			currentImage->save(chars);
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			MessageBox::Show("Obrazek zapisano!");
		}
		else
		{
			MessageBox::Show("Wyst¹pi³ b³¹d!");
		}
	}
	private: System::Void changeDisplayImage(const CImg<myType>& img) {
		image1 = gcnew Bitmap(img.width(), img.height());

		cimg_forXY(img, x, y)
		{
			int r = static_cast<int>(img(x, y, 0));
			int g = static_cast<int>(img(x, y, 1));
			int b = static_cast<int>(img(x, y, 2));

			Color pixelColor = Color::FromArgb(r, g, b);
			image1->SetPixel(x, y, pixelColor);
		}

		pictureBox1->Image = image1;
	}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

	if (!originImage || !currentImage)
	{
		MessageBox::Show("Najpierw stwórz obrazek");
		return;
	}

	CImg<myType> img = CImg<myType>(*originImage).histogram(256);
	img.display_graph(0, 3);
	CImg<myType> img2 = CImg<myType>(*currentImage).histogram(256);
	img2.display_graph(0, 3);

}
};
}
