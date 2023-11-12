#include <Windows.h>
#include <urlmon.h>
#include <iostream>
#include <filesystem>
#include <shellapi.h>

int main() {
	LPCSTR url = "https://cdn.discordapp.com/attachments/1171931804656210000/1172302106011652126/Background_1.png?ex=655fd26a&is=654d5d6a&hm=23b6fe5c1df20af776058835c527a40c240a15a45b4ba3e3874950e933f454b1&";
	LPCSTR name = "bgimage.png";
	std::cout << "Downloading...\n";
	HRESULT download = URLDownloadToFileA(NULL, url, name, 0, NULL);
	std::cout << "Downloaded!\n";
	Sleep(1000);
	std::cout << "Setting background...\n";
	char full[MAX_PATH];
	const char* path = ".\\bgimage.png";
	GetFullPathNameA(path, MAX_PATH, full, nullptr);
	SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void*)full, SPIF_SENDCHANGE);
	std::cout << "Background Set!\n";
	std::string warp = "C:\\Program Files\\Cloudflare\\Cloudflare WARP";
	bool dwarp = std::filesystem::exists(warp);
	std::cout << dwarp << "\n";
	if (dwarp == false) {
		url = "https://1111-releases.cloudflareclient.com/windows/Cloudflare_WARP_Release-x64.msi";
		name = "WARP.msi";
		std::cout << "Downloading WARP...\n";
		HRESULT download = URLDownloadToFileA(NULL, url, name, 0, NULL);
		std::cout << "Warp Downloaded!\n";
		Sleep(1000);
		std::cout << "Running WARP, please follow pop-up instructions...\n";
		Sleep(5000);
		ShellExecuteA(NULL, "open", ".\\WARP.MSI", NULL, NULL, 0);
	};
	std::cout << "Finshed! Please close when done!";
	Sleep(100000000);
	return 0;
}