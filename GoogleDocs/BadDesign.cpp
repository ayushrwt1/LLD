#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentEditor
{
private:
    vector<string> document;
    string cachedRender;

public:
    DocumentEditor()
    {
        cachedRender = "";
    }

    void addImage(string imagePath)
    {
        document.push_back(imagePath);
    }

    void addText(string text)
    {
        document.push_back(text);
    }

    string renderDocument()
    {
        if (cachedRender.empty())
        {
            string result = "";
            for (auto element : document)
            {
                if (element.size() > 4 && element.substr(element.size() - 4) == ".jpg")
                {
                    result += "<img src='" + element + "' />";
                }
                else
                {
                    result += "<p>" + element + "</p>";
                }
            }
            cachedRender = result;
        }

        return cachedRender;
    }

    void saveToFile()
    {
        ofstream file("document.txt");
        if (file.is_open())
        {
            file << renderDocument();
            file.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Unable to open file for writing." << endl;
        }
    }
};

int main()
{

    DocumentEditor editor;
    editor.addText("This is a sample document.");
    editor.addImage("image1.jpg");
    editor.addText("This is another paragraph.");
    cout << editor.renderDocument() << endl;
    editor.saveToFile();

    return 0;
}