
#include <iostream>
using namespace std;

string crc(string data, string gx){
	string crc_data = data;

	for (uint8_t i = 0; i < gx.length() - 1; i++) {// 원본 데이터 뒤에 gx-1만큼 0을 추가한다.
		data += "0";
	}
	string q = ""; //몫

	for (uint8_t i = 0; i < data.length(); i++){ // 사용하는 bit수를 고정하기위해서 uint8사용
		if (data[i] == '1'){
			q += '1'; // 몫
			for (uint8_t j = 0; j < gx.length(); j++){
				if ((data[i + j] - '0') ^ (gx[j] - '0')){ // xor연산 // string을 int형식으로 반환하기위해 0을 빼준다.
					data[i + j] = '1';
				}
				else data[i + j] = '0';

			}
		}
		else{
			q += '0';
			for (uint8_t j = 0; j < gx.length(); j++) {
				if ((data[i + j] - '0') ^ 0){ //나눌수 없는 경우 0과 xor
					data[i + j] = '1';
				}
				else data[i + j] = '0';
			}
		}
		if (q.length() == data.length() - gx.length() + 1) break; // 나머지가 gx-1의 길이가 될때 멈춤
	}
	
	crc_data += data.substr(crc_data.length(), gx.length() - 1); // 이어붙인다.
	return crc_data;
}

string check(string crc_data, string gx, string& remider) { // 에러 여부 확인
	string q = "";

	for (uint8_t i = 0; i < crc_data.length(); i++){ // xor연산
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

	remider = crc_data.substr(crc_data.length() - gx.length() + 1, gx.length() - 1); // 나머지를 구한다.

	bool error = false; //에러여부를 저장하는 변수
	for (uint8_t i = 0; i < remider.length(); i++){
		if (remider[i] != '0'){ // 0이 아니라면 에러가 생긴것이다.
			error = true;
			break;
		}
	}
	if (error) // 에러가 있다면
		return "error 발견";
	else // 에러가 없다면
		return "error 없음";
}

int main()
{
	cout << "12191728_김두미\n";
	string data = "101110";
	string gx = "1001";
	string remider = "";
	
	cout << "1번 예시 :" << "\n";
	cout << "Data:" << data << "\n";
	cout << "Gx:" << gx << "\n";
	cout << "CRC code:" << crc(data, gx) << "\n";
	cout << "오류검출:" << check(crc(data, gx), gx, remider) << "\n";

	cout << "\n";

	data = "110011";
	gx = "1001";
	cout << "\n";
	cout << "2번 예시 :" << "\n";
	cout << "Data:" << data << "\n";
	cout << "Gx:" << gx << "\n";
	cout << "CRC code:" << crc(data, gx) << "\n";
	cout << "오류검출:" << check(crc(data, gx), gx, remider) << "\n";
	
	cout << "\n";

	data = "110011";
	gx = "1001";
	cout << "\n";
	cout << "3번 예시 :" << "\n";
	cout << "Data:" << data << "\n";
	cout << "Gx:" << gx << "\n";
	cout << "CRC code:" << crc(data, gx) << "\n";
	cout << "오류검출:" << check("110011100", gx, remider) << "\n";
	
}