#include <Novice.h>
#include "main.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeigth);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	game->Initialize(sphere, dirt);
	Vector2 spd;

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
		game->Update(sphere, dirt);
		if (sphere->mIsHit && sphere->mPosition.y!=360.0f) {
			dirt->mPosition.x = sphere->mDirtPosition.x;
			dirt->mPosition.y = sphere->mDirtPosition.y + 20;
			/*spd = game->GetTheta(sphere);
			dirt->mVelocity.x = spd * 5;
			dirt->mVelocity.y = -(sphere->mVelocity.y)/3;*/
			spd = game->GetSpeed(sphere);
			dirt->mVelocity.x = spd.x;
			dirt->mVelocity.y = spd.y;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		game->Draw(sphere, dirt);
		Novice::ScreenPrintf(0, 0, "%f", game->GetTheta(sphere));
		Novice::ScreenPrintf(0, 20, "%f", dirt->mPosition.x);
		Novice::ScreenPrintf(0, 40, "%f", dirt->mPosition.y);
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
