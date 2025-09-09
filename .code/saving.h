#ifndef saving_defined
#define saving_defined
#include<random>
#include<vector>
#include<queue>
#include"lib/sha256.h"
extern "C" {
	#include"lib/aes.c"
}
namespace saving{
	constexpr size_t IV_SIZE = 16;
	constexpr size_t SALT_SIZE = 128;
	std::vector<uint8_t> generateRandomBytes(size_t size) {
		std::vector<uint8_t> data(size);
		std::random_device rd;
		std::uniform_int_distribution<int> dist(0, 255);
		for (auto &b : data) {
			b = static_cast<uint8_t>(dist(rd));
		}
		return data;
	}

	inline std::vector<uint8_t> hexToBytes(const std::string &hex) {
		std::vector<uint8_t> bytes;
		if (hex.length() % 2 != 0) return bytes;

		for (size_t i = 0; i < hex.length(); i += 2) {
			std::string byteString = hex.substr(i, 2);
			uint8_t byte = static_cast<uint8_t>(std::stoi(byteString, nullptr, 16));
			bytes.push_back(byte);
		}
		return bytes;
	}

	std::string bytesToHex(const std::vector<uint8_t>& data) {
		std::ostringstream oss;
		oss << std::hex;
		for (uint8_t byte : data) {
			oss.width(2);
			oss.fill('0');
			oss << static_cast<int>(byte);
		}
		return oss.str();
	}

	std::vector<uint8_t> sha256KeyFromPasswordWithSalt(const std::string &password, const std::vector<uint8_t> &salt) {
		std::string combined(salt.begin(), salt.end());
		combined += password;
		std::vector<uint8_t> key(picosha2::k_digest_size);
		picosha2::hash256(combined.begin(), combined.end(), key.begin(), key.end());
		return key;
	}

	bool encryptFile(const std::string &filepath, const std::string &password, std::vector<uint8_t> data) {
		std::vector<uint8_t> salt = generateRandomBytes(SALT_SIZE);
		std::vector<uint8_t> iv = generateRandomBytes(IV_SIZE);
		std::vector<uint8_t> key = sha256KeyFromPasswordWithSalt(password, salt);

		size_t pad = 16 - (data.size() % 16);
		data.insert(data.end(), pad, 0x0B);

		AES_ctx ctx;
		AES_init_ctx_iv(&ctx, key.data(), iv.data());
		AES_CBC_encrypt_buffer(&ctx, data.data(), data.size());

		std::ofstream out(filepath, std::ios::binary);
		if (!out) return false;
		out.write(reinterpret_cast<const char*>(iv.data()), iv.size());
		out.write(reinterpret_cast<const char*>(salt.data()), salt.size());
		out.write(reinterpret_cast<const char*>(data.data()), data.size());
		return true;
	}

	std::vector<uint8_t> decryptFile(const std::string &filepath, const std::string &password) {
		std::ifstream in(filepath, std::ios::binary);
		if (!in) return std::vector<uint8_t>();;

		uint8_t iv[IV_SIZE];
		in.read(reinterpret_cast<char*>(iv), IV_SIZE);
		if (in.gcount() != IV_SIZE) return std::vector<uint8_t>();;

		std::vector<uint8_t> salt(SALT_SIZE);
		in.read(reinterpret_cast<char*>(salt.data()), SALT_SIZE);
		if (in.gcount() != SALT_SIZE) return std::vector<uint8_t>();;

		std::vector<uint8_t> ciphertext((std::istreambuf_iterator<char>(in)), {});
		if (ciphertext.size() % 16 != 0) return std::vector<uint8_t>();;

		std::vector<uint8_t> key = sha256KeyFromPasswordWithSalt(password, salt);

		AES_ctx ctx;
		AES_init_ctx_iv(&ctx, key.data(), iv);
		AES_CBC_decrypt_buffer(&ctx, ciphertext.data(), ciphertext.size());

		while (!ciphertext.empty() && ciphertext.back() == 0x0B) {
			ciphertext.pop_back();
		}

		return ciphertext;
	}
}
#endif