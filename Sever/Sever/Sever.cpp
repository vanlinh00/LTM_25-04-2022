

#include <stdio.h>
#include <winsock2.h>

#include <iostream>
#include <cstdio>

#pragma comment(lib, "ws2_32")

int main()
{
	// Khoi tao thu vien
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	// Tao socket
	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Khai bao dia chi server
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(8000);

	// Gan cau truc dia chi voi socket
	bind(listener, (SOCKADDR*)&addr, sizeof(addr));

	// Chuyen sang trang thai cho ket noi
	listen(listener, 5);

	// Cho ket noi moi
	SOCKET client = accept(listener, NULL, NULL);
	// Lien tuc doc du lieu tu ban phim va gui sang client
		// Nhan du lieu tu client
#pragma warning(disable:4996)

	char buf[256];
	while (1)
	{
		int ret = recv(client, buf, sizeof(buf), 0);
		// Them ky tu ket thuc xau va in ra man hinh
		buf[ret] = 0;
		printf("%s\n", buf);

		const char* filePath = "C:/Users/84372/Desktop/2021_2/LapTrinhMang/ThucHanh/LTM_25_8_2022/my_document.txt";
		FILE* file;

		file = fopen(filePath, "a+");


			
		//writeToFile(file);
		fprintf(file, buf);
		fclose(file);
	}




	// Dong ket noi va giai phong thu vien
	closesocket(client);
	closesocket(listener);
	WSACleanup();

}
