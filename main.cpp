#include <Novice.h>
#include <cmath>
const char kWindowTitle[] = "LE2B_08_カワイヨリツグ_タイトル";

int law(unsigned int red, unsigned int  green, unsigned int blue, int  alpha)
{
	//unsigned char top = 0x;
	int color = (red << 24) | (green << 16) | (blue << 8) | alpha;
	return color;
}

int clamp(int suteji, int min, int max) {
	if (suteji <= min) return min;
	if (suteji >= max) return max;
	return suteji;
}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int  kCHei = 1280;
	int  kCWid = 720;
	Novice::Initialize(kWindowTitle, kCHei, kCWid);
	//int back = Novice::LoadTexture("./Resources./whitemountain.png");

	int mont= Novice::LoadTexture("./Resources./mountain.png");



	float Red = 255.0f;
	float Green = 255.0f;
	float Blue = 255.0f;
	int Color = 255;

	int s = 50;
	float distance = 2.0f;
	float changeRate = 0.0f;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		changeRate = 1.0f / log(distance * 2);


		float blue = Blue * changeRate;
		float green = Green * changeRate;
		float red = Red * changeRate;

		if (keys[DIK_UP]) {
			distance += 0.01f;
			s += 1;
			Color += 2;
		}
		if (keys[DIK_DOWN]) {
			distance -= 0.01f;
			s -= 1;
			Color -= 2;
		}

		if (distance <= 1.58f) {
			distance = 1.60f;
		}
		if (distance >= 5.0f) {
			distance = 4.90f;
		}
		Color = clamp(Color, 0, 255);
		s = clamp(s, 0, 100);
			///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawSprite(0, 10, mont, 1, 1, 0.0f, law(red, green, blue, Color));
		Novice::DrawBox(640-s/2, 600-s/2, s, s, 0.0f, 0xffffffff, kFillModeSolid);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
