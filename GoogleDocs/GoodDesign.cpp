#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class DocumentElement{
    public: 
        virtual string render() = 0;
};

class TextElement : public DocumentElement{
    private:
        string text;
    
    public:
        TextElement(string text){
            this->text = text;
        }

        string render() override{
            return text;
        }

};

class ImageElement : public DocumentElement{
    private:
        string imagePath;

    public:
        ImageElement(string imagePath){
            this->imagePath = imagePath;
        }

        string render() override{
            return imagePath;
        }
};


class Document{
    private:
        vector<DocumentElement*> elements;

    public:
        void addElement(DocumentElement* element){
            elements.push_back(element);
        }
        string renderDocument(){
            string result = "";
            for(auto element : elements){
                result += element->render() + "\n";
            }
            return result;
        }
};

class Persistence{
    public :
        virtual void save(string data) = 0;
};

class FilePersistence : public Persistence{
    private:
        string filename;

    public:
        FilePersistence(string filename){
            this->filename = filename;
        }

        void save(string data) override{
            ofstream file(filename);
            if(file.is_open()){
                file << data;
                file.close();
                cout << "Document saved to " << filename << endl;
            }else{
                cout << "Unable to open file for writing." << endl;
            }
        }
};

class DBPersistence : public Persistence{
    private:
        string data;

    public:
        DBPersistence(string data){
            this->data = data;
        }

        void save(string data) override{
            // Code to save data to database using connectionString
            cout << "Document saved to database." << endl;
        }
};

class DocumentEditor{
    private:
        Document document;
        Persistence* storage;
        string renderedDocument;

    public:
        DocumentEditor(Document* document, Persistence* storage){
            this->document = *document;
            this->storage = storage;
        }

        void addText(string text){
            document.addElement(new TextElement(text));
        }

        void addImage(string imagePath){
            document.addElement(new ImageElement(imagePath));
        }
        string renderDocument(){
            if(renderedDocument.empty()){
                renderedDocument = document.renderDocument();
            }
            return renderedDocument;
        }
        void saveDocument(){
            renderDocument();
            storage->save(renderedDocument);
        }
};


int main(){
    Document* doc = new Document();
    Persistence* fileStorage = new FilePersistence("document.txt");

    DocumentEditor editor(doc, fileStorage);

    editor.addText("Hello, World!");
    editor.addImage("image.jpg");
    editor.addImage("photo.png");
    editor.addText("Bye, World!");


    cout << "Rendered Documnet" << "  " << editor.renderDocument() << endl;
    editor.saveDocument();

    return 0;
}