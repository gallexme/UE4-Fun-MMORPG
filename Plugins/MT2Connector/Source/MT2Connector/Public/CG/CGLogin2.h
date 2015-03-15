#pragma once

#include"M2CL/Core/Types.h"

#include <cstring>
#include <string>
#include"M2CL/Core/Logger.h"
#define CG_LOGIN2 109





#pragma pack(1)
struct CGLogin2 {
	uint8 header;
	char login[31];
	uint32 loginKey;
	uint32 clientKey[4];

	// Getter & Setter for Python because Python binding doesn't work with char arrays
	std::string getLogin() { return login; }

	void setLogin(const std::string nLogin) {
		if (nLogin.size() >= sizeof(this->login))
			throw std::exception();
		strncpy(this->login, nLogin.c_str(), nLogin.size());
	}
	void setLogin(const FString nLogin) {
		std::string tmplogin(TCHAR_TO_UTF8(*nLogin));
		if (tmplogin.size() >= sizeof(this->login))
			throw std::exception();
		strncpy(this->login, tmplogin.c_str(), tmplogin.size());
	}
	
};
#pragma pack()
