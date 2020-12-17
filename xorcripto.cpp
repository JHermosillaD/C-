/* La criptografía es una rama del cómputo que estudia cómo cifrar mensajes. Uno de los métodos criptográficos más fáciles es el cifrado XOR, que consiste en modificar los bits de un número aplicando la operación lógica XOR descrita en la siguiente tabla:

p  |  q  | p ⊕ q
=================
0  |  0  |   0
0  |  1  |   1
1  |  0  |   1
1  |  1  |   0

El ejercicio consiste en crear un programa que pida al usuario una cadena de texto, una clave secreta y encripte / desencripte el mensaje.*/

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
using message = string;

class credentials
{
    private:
        string text, letter, encryptedString;
        int key;
        bitset<8> encrypted;
        bitset<8> decrypted;
        vector<message> cell_letter;
    public:
        credentials(string Text, int Key)
        {
            text = Text;
            key = Key;
        }
    void encrypt()
    {
        cout << "Mensaje encriptado: " << endl;
	    for (char& i : text) 
        {
		    bitset<8> textbin(i); 
            bitset<8> keybin(key);
            encrypted = textbin ^ keybin;
            encryptedString = encrypted.to_string();
            decrypted = encrypted ^ keybin;
            letter = static_cast<char>(decrypted.to_ulong());
            cell_letter.push_back(letter);
            cout << encryptedString ;
	    }
        cout << endl;
    }
    void decrypt()
    {
        cout << "Mensaje original: " << endl;
        for (message i : cell_letter)
            cout << i ;
            cout << endl;
    }    
} ;

int main()
{
    string text;
    int key;
    cout << "Introduce una cadena de texto: ";
    cin >> text;
    cout << "Introduce una clave secreta: ";
    cin >> key;
    credentials xorcrypt = credentials(text,key);
    xorcrypt.encrypt();
    xorcrypt.decrypt();
    return 0;
}