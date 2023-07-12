#include <Novice.h>
#include "main.h"

#include <imgui.h>

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeigth);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	sphere.Init();
	dirt.Init();

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
		sphere.Update();
		dirt.Update();


		ImGui::Begin("Window");
		ImGui::DragFloat("Gravity", &Gravity, 0.01f);
		ImGui::DragFloat("SphereMass", &sphereMass, 0.01f);
		ImGui::DragFloat("DirtMass", &dirtMass, 0.01f);
		ImGui::DragFloat("velo", &sphere.mFirstVelocity.y, 0.01f);
		ImGui::End();

		sphere.setGravity(Gravity);
		dirt.setGravity(Gravity);

		sphere.setMass(sphereMass);
		dirt.setMass(dirtMass);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		sphere.Draw();
		dirt.Draw();

		Novice::ScreenPrintf(0, 0, "%f", sphere.mFlame);
		Novice::ScreenPrintf(0, 20, "addpos:%f", sphere.mAddPosition.y);
		Novice::ScreenPrintf(0, 40, "firstspeed:%f", sphere.mFirstVelocity.y);
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
