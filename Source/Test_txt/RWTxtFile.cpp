// Fill out your copyright notice in the Description page of Project Settings.

#include "RWTxtFile.h"

bool URWTxtFile::LoadTxt(FString FileNameA, FString& SaveTextA)
{
	enum { FILEREAD_AllowWrite = 0x04};
	//AllowWrite = 0x04;
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA), EFileRead::FILEREAD_AllowWrite);
}

bool URWTxtFile::SaveTxt(FString SaveTextB, FString FileNameB)
{
	enum { FILEWRITE_Append = 0x08};
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB), FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}

bool URWTxtFile::SaveArray(TArray<uint8> Array, FString FileNameC)
{
	enum { FILEWRITE_Append = 0x08};
	return FFileHelper::SaveArrayToFile(Array, *(FPaths::GameDir() + FileNameC), &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}

bool URWTxtFile::LoadArray(FString& FilenameD,TArray<uint8> ArrayB)
{
	return FFileHelper::LoadFileToArray(ArrayB, *(FPaths::GameDir() + FilenameD));
}

void URWTxtFile::CarregarTexto(FString FileNameE,  FVector&VetorLegal)
{
	//Funciona
	//IMPORTANTE: TEM QUE DEIXAR UM ESPA�O NO FINAL DO ARQUIVO, CASO CONTR�RIO O PROGRAMA
	//PERDE A �LTIMA COORDENADA.
	using namespace std;
	list<float> *lista = new list <float>();
	float numero;
	float numero1;
	float numero2;
	float numero3;
	int erro = 0;
	int tamanho = 0;
	numero = 0.0;
	numero1 = 0.0;
	numero2 = 0.0;
	numero3 = 0.0;
	FVector Vetor = FVector(0.0f, 0.0f, 0.0f);
	ifstream input;
	input.open("C:\\Users\\USP\\Documents\\GitHub\\Txt\\Location.txt");
	input >> numero;
	if (input.good()) {
		numero1 = numero;
	}
	else erro = 1;
	input >> numero;
	if (input.good()) {
		numero2 = numero;
	}
	else erro = 1;
	input >> numero;
	if (input.good()) {
		numero3 = numero;
	}
	else erro = 1;
	if (erro == 0) {
		Vetor.X = numero1;
		Vetor.Y = numero2;
		Vetor.Z = numero3;
	}
	VetorLegal = Vetor;
	while (input.good()) {
		input >> numero;
		if (input.good()) {
			lista->push_back(numero);
		}
	}
	input.close();
	ofstream output;
	output.open("C:\\Users\\USP\\Documents\\GitHub\\Txt\\Location.txt");
	for (tamanho = lista->size(); tamanho > 0; tamanho--) {
		output << lista->front()<<" ";
		lista->pop_front();
	}
	output.close();
	//input.close();
	//Escreve Arquivo
	/*
	ofstream output;
	output.open("C:\\Users\\USP\\Documents\\GitHub\\Txt\\Location.txt",ios_base::app);
	output << 123.1 << " " << 124.2 << " " << 125.3<<" ";
	output.close();
	*/
	//Le Arquivo
	/*
	ifstream input;
	input.open ("C:\\Users\\USP\\Documents\\GitHub\\Txt\\Location.txt");
	input >> numero;
	input >> numero2;
	input >> numero3;
	Vetor.X = numero;
	Vetor.Y = numero2;
	Vetor.Z = numero3;
	VetorLegal = Vetor;
	input.close();
	*/
	//Acrescentar Vetor, Carregar o texto inteiro
}

void URWTxtFile::LerTexto(FString FileNameD, FVector&Lugar)
{

}