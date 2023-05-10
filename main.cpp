#include <Novice.h>

const char kWindowTitle[] = "LE2B_08_カワイヨリツグ_タイトル";



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
	int back = Novice::LoadTexture("./Resources./Fog.png");
	
	int mont[3];
		mont[0]=  Novice::LoadTexture("./Resources./mountain.png");
		mont[1] = Novice::LoadTexture("./Resources./mountain.png");
		mont[2] = Novice::LoadTexture("./Resources./mountain.png");
		
		/*const int kost = 10000;
		int boxX[kost] = { 0 };
		int boxY[kost] = { 0 };
		int siz[kost] = { 0 };
		int frg[kost] = { false };
		int speed[kost] = { 0 };
		
	
		for (int i = 0; i < kost; i++) {

			boxX[i] = 0;
			boxY[i] = 0;
			siz[i] = 3;
			speed[i] = 0;


		}*/
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

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
		/*for (int i = 0; i < kost; i++) {
			if (frg[i] == false) {
				frg[i] = true;
				boxX[i] = rand() % 1100 + 700;
				boxY[i] = rand() % 10 + 1000;
				speed[i] = 0;
				break;
			}
		}

		for (int i = 0; i < kost; i++) {
			if (frg[i] == true) {
				boxY[i] -= speed[i];
				speed[i] = 2;
			}
		}



		for (int i = 0; i < kost; i++) {
			if (boxY[i] <= 200) {
				frg[i] = false;
			}
		}*/


	
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
	
		
		//Novice::DrawSprite(0, 0, back, 1, 1, 0.0f, 0xffffffff);
		
		//Novice::SetBlendMode(BlendMode::kBlendModeAdd);
		
		Novice::DrawSprite(500, 0, mont[2], 1, 1, 0.0f, 0xffffffff);
		Novice::SetBlendMode(BlendMode::kBlendModeAdd);
		/*for (int i = 0; i < kost; i++) {
			if (frg[i] == true) {
				Novice::DrawSprite(boxX[i], boxY[i], back, siz[i], siz[i], 0.0f, 0xffffff64);
			}
		}*/
		Novice::SetBlendMode(BlendMode::kBlendModeNormal);
		Novice::DrawSprite(0, 10, mont[1], 1, 1, 0.0f, 0xffffffff);

		//Novice::SetBlendMode(BlendMode::kBlendModeSubtract);
		
		Novice::DrawSprite(300, 200, mont[0], 1, 1, 0.0f, 0xffffffff);
		
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
