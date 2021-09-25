
#include <iostream>
using namespace std;

string crc(string data, string gx){
	string crc_data = data;

	for (uint8_t i = 0; i < gx.length() - 1; i++) {// ���� ������ �ڿ� gx-1��ŭ 0�� �߰��Ѵ�.
		data += "0";
	}
	string q = ""; //��

	for (uint8_t i = 0; i < data.length(); i++){ // ����ϴ� bit���� �����ϱ����ؼ� uint8���
		if (data[i] == '1'){
			q += '1'; // ��
			for (uint8_t j = 0; j < gx.length(); j++){
				if ((data[i + j] - '0') ^ (gx[j] - '0')){ // xor���� // string�� int�������� ��ȯ�ϱ����� 0�� ���ش�.
					data[i + j] = '1';
				}
				else data[i + j] = '0';

			}
		}
		else{
			q += '0';
			for (uint8_t j = 0; j < gx.length(); j++) {
				if ((data[i + j] - '0') ^ 0){ //������ ���� ��� 0�� xor
					data[i + j] = '1';
				}
				else data[i + j] = '0';
			}
		}
		if (q.length() == data.length() - gx.length() + 1) break; // �������� gx-1�� ���̰� �ɶ� ����
	}
	
	crc_data += data.substr(crc_data.length(), gx.length() - 1); // �̾���δ�.
	return crc_data;
}

string check(string crc_data, string gx, string& remider) { // ���� ���� Ȯ��
	string q = "";

	for (uint8_t i = 0; i < crc_data.length(); i++){ // xor����
		if (crc_data[i] == '1'){
			q += '1';
			for (uint8_t j = 0; j < gx.length(); j++){
				if ((crc_data[i + j] - '0') ^ (gx[j] - '0')){
					crc_data[i + j] = '1';
				}
				else crc_data[i + j] = '0';
			}
		}
		else {
			q += '0';
			for (uint8_t j = 0; j < gx.length(); j++){
				if ((crc_data[i + j] - '0') ^ 0){
					crc_data[i + j] = '1';
				}
				else crc_data[i + j] = '0';
			}
		}
		if (q.length() == crc_data.length() - gx.length() + 1) break;
	}

	remider = crc_data.substr(crc_data.length() - gx.length() + 1, gx.length() - 1); // �������� ���Ѵ�.

	bool error = false; //�������θ� �����ϴ� ����
	for (uint8_t i = 0; i < remider.length(); i++){
		if (remider[i] != '0'){ // 0�� �ƴ϶�� ������ ������̴�.
			error = true;
			break;
		}
	}
	if (error) // ������ �ִٸ�
		return "error �߰�";
	else // ������ ���ٸ�
		return "error ����";
}

int main()
{
	cout << "12191728_��ι�\n";
	string data = "101110";
	string gx = "1001";
	string remider = "";
	
	cout << "1�� ���� :" << "\n";
	cout << "Data:" << data << "\n";
	cout << "Gx:" << gx << "\n";
	cout << "CRC code:" << crc(data, gx) << "\n";
	cout << "��������:" << check(crc(data, gx), gx, remider) << "\n";

	cout << "\n";

	data = "110011";
	gx = "1001";
	cout << "\n";
	cout << "2�� ���� :" << "\n";
	cout << "Data:" << data << "\n";
	cout << "Gx:" << gx << "\n";
	cout << "CRC code:" << crc(data, gx) << "\n";
	cout << "��������:" << check(crc(data, gx), gx, remider) << "\n";
	
	cout << "\n";

	data = "110011";
	gx = "1001";
	cout << "\n";
	cout << "3�� ���� :" << "\n";
	cout << "Data:" << data << "\n";
	cout << "Gx:" << gx << "\n";
	cout << "CRC code:" << crc(data, gx) << "\n";
	cout << "��������:" << check("110011100", gx, remider) << "\n";
	
}