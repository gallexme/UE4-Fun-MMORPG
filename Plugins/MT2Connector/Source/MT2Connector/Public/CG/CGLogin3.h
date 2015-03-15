#pragma once


#include"M2CL/Core/Types.h"
#include "MT2ConnectorPrivatePCH.h"
#include <cstring>
#include <string>

#include"M2CL/Core/Logger.h"
#include "CGLogin3.generated.h"

#define CG_LOGIN3 111



#pragma pack(1)
USTRUCT()
struct FCGLogin3 {
	GENERATED_USTRUCT_BODY();
	uint8 header;
	char login[31];
	char password[17];
	uint32 adwClientKey[4];

	// Getter & Setter for Python because Python binding doesn't work with char arrays
	std::string getLogin() { return login; }
	std::string getPassword() { return password; }
	void setLogin(const FString nLogin) {
		std::string tmplogin(TCHAR_TO_UTF8(*nLogin));
		if (tmplogin.size() >= sizeof(this->login))
			throw std::exception();
		strncpy(this->login, tmplogin.c_str(), tmplogin.size());
	}
	void setLogin(const std::string nLogin) {
		if (nLogin.size() >= sizeof(this->login))
			throw std::exception();
		strncpy(this->login, nLogin.c_str(), nLogin.size());
	}
	void setPassword(const FString nPassword) {
		std::string tmpPassword(TCHAR_TO_UTF8(*nPassword));
		if (tmpPassword.size() >= sizeof(this->login))
			throw std::exception();
		strncpy(this->password, tmpPassword.c_str(), tmpPassword.size());
	}
	void setPassword(const std::string nPassword) {
		if (nPassword.size() >= sizeof(this->password))
			throw std::exception();
		strncpy(this->password, nPassword.c_str(), nPassword.size());
	}
};
#pragma pack()
