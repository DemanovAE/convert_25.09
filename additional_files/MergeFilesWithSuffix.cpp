#include "TFile.h"
#include "TKey.h"

void MergeFilesWithSuffix(const char* file1_name, const char* file2_name, const char* output_name, const char* suffix = "_minus") {
    // Открываем исходные файлы
    TFile* f1 = TFile::Open(file1_name, "READ");
    TFile* f2 = TFile::Open(file2_name, "READ");
    
    if (!f1 || !f2 || f1->IsZombie() || f2->IsZombie()) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }
    
    // Создаём выходной файл
    TFile* out = TFile::Open(output_name, "RECREATE");
    if (!out) {
        std::cerr << "Error creating output file!" << std::endl;
        return;
    }
    
    // 1. Копируем все объекты из первого файла (без изменений)
    TIter nextkey(f1->GetListOfKeys());
    TKey* key;
    while ((key = (TKey*)nextkey())) {
        TObject* obj = key->ReadObj();
        if (obj) {
            out->WriteObject(obj, key->GetName());
        }
    }
    
    // 2. Копируем все объекты из второго файла с суффиксом suffix
    TIter nextkey2(f2->GetListOfKeys());
    while ((key = (TKey*)nextkey2())) {
        TObject* obj = key->ReadObj();
        if (obj) {
            TString newName = TString(key->GetName()) + suffix;
            out->WriteObject(obj, newName.Data());
        }
    }
    
    // Закрываем файлы
    f1->Close();
    f2->Close();
    out->Close();
    
    std::cout << "Merged files saved to " << output_name << std::endl;
    delete f1;
    delete f2;
    delete out;
}