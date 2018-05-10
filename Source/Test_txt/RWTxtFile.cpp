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
	/*
	using namespace std;
	float numero;
	float numero2;
	float numero3;
	FVector Vetor = FVector(0.0f, 0.0f, 0.0f);
	ofstream output;
	output.open("NewLocation.txt");
	output << 121.1 << " " << 122.2 << " " << 123.3;
	output.close();
	ifstream input;
	input.open ("NewLocation.txt");
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