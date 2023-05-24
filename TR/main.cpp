#include <Novice.h>
#include "main.h"
#include <cstdlib>
#include <ctime>

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeigth);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	game->Initialize(sphere, dirt1);
	dirt2->Initialize();
	dirt3->Initialize();
	dirt4->Initialize();
	dirt5->Initialize();
	Vector2 spd;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;

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
		if (keys[DIK_SPACE] && sphere->mIsShot == false) {
			num2 = rand() % 5;
			num3 = rand() % 3 - 2;
			num4 = rand() % 2 - 3;
			num5 = rand() % -5;
		}
		game->Update(sphere, dirt1);
		dirt2->Update();
		dirt3->Update();
		dirt4->Update();
		dirt5->Update();
		if (sphere->mIsHit && sphere->mPosition.y!=360.0f) {
			dirt1->mPosition.x = sphere->mDirtPosition.x;
			dirt1->mPosition.y = sphere->mDirtPosition.y;
			dirt2->mPosition.x = sphere->mDirtPosition.x;
			dirt2->mPosition.y = sphere->mDirtPosition.y;
			dirt3->mPosition.x = sphere->mDirtPosition.x;
			dirt3->mPosition.y = sphere->mDirtPosition.y;
			dirt4->mPosition.x = sphere->mDirtPosition.x;
			dirt4->mPosition.y = sphere->mDirtPosition.y;
			dirt5->mPosition.x = sphere->mDirtPosition.x;
			dirt5->mPosition.y = sphere->mDirtPosition.y;
			/*spd = game->GetTheta(sphere);
			dirt->mVelocity.x = spd * 5;
			dirt->mVelocity.y = -(sphere->mVelocity.y)/3;*/
			spd = game->GetSpeed(sphere);
			dirt1->mVelocity.x = spd.x;
			dirt1->mVelocity.y = spd.y;
			dirt2->mVelocity.x = spd.x + num2;
			dirt2->mVelocity.y = spd.y - num2;
			dirt3->mVelocity.x = spd.x + num3;
			dirt3->mVelocity.y = spd.y - num3;
			dirt4->mVelocity.x = spd.x + num4;
			dirt4->mVelocity.y = spd.y - num4;
			dirt5->mVelocity.x = spd.x + num5;
			dirt5->mVelocity.y = spd.y - num5;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		game->Draw(sphere, dirt1);
		//dirt2->mPosition.x = dirt->mPosition.x + num;
		//dirt2->mPosition.y = dirt->mPosition.y - num;
		dirt2->Draw();
		dirt3->Draw();
		dirt4->Draw();
		dirt5->Draw();
		Novice::ScreenPrintf(0, 0, "%f", game->GetTheta(sphere));
		Novice::ScreenPrintf(0, 20, "%f", dirt1->mPosition.x);
		Novice::ScreenPrintf(0, 40, "%f", dirt1->mPosition.y);
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
