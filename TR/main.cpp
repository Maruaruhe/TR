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
	srand((unsigned)time(NULL));
	int num[4] = {};

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
			for (int i = 0; i < 4; i++) {
				num[i] = rand() % 5 - 5;
			}
		}
		game->Update(sphere, dirt1);
		dirt2->Update();
		dirt3->Update();
		dirt4->Update();
		dirt5->Update();
		if (sphere->mIsHit && sphere->mPosition.y!=360.0f) {
			dirt1->Initialize();
			dirt2->Initialize();
			dirt3->Initialize();
			dirt4->Initialize();
			dirt5->Initialize();
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
			spd = game->GetSpeed(sphere);
			dirt1->mVelocity.x = spd.x;
			dirt1->mVelocity.y = spd.y;
				dirt2->mVelocity.x = spd.x + num[0];
				dirt2->mVelocity.y = spd.y - num[1];
				dirt3->mVelocity.x = spd.x + num[1];
				dirt3->mVelocity.y = spd.y - num[2];
				dirt4->mVelocity.x = spd.x + num[2];
				dirt4->mVelocity.y = spd.y - num[3];
				dirt5->mVelocity.x = spd.x + num[3];
				dirt5->mVelocity.y = spd.y - num[0];
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		game->Draw(sphere, dirt1);
		if (sphere->mIsHit) {
			dirt2->Draw();
			dirt3->Draw();
			dirt4->Draw();
			dirt5->Draw();
		}
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
