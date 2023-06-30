#include "DxLib.h"
#include "rect.h"

//矩形の当たり判定 未完成
bool isHitRect(Rect b1, Rect b2)
{
	//未実装
	return false;
}
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DXライブラリの初期化処理 ここから
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//DXライブラリの初期化処理 ここまで

	int color = GetColor(255, 255, 255);

	Rect box1;//箱１
	box1.x = 100.0;
	box1.y = 50.0;
	box1.width = 150.0;
	box1.height = 100.0;

	Rect box2;//箱２
	box2.x = 400.0;
	box2.y = 450.0;
	box2.width = 50.0;
	box2.height = 100.0;
	
	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		if(CheckHitKey(KEY_INPUT_RIGHT)){
			box1.x++;
		}
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			box1.x--;
		}
		if (CheckHitKey(KEY_INPUT_DOWN)) {
			box1.y++;
		}
		if (CheckHitKey(KEY_INPUT_UP)) {
			box1.y--;
		}

		//二つのBOXが当たっているか確認
		if (isHitRect(box1, box2)) {
			//当たっている場合には色を赤にする
			color = GetColor(255, 0, 0);
		}
		else {
			//当たっていない場合には色を白にする
			color = GetColor(255, 255, 255);
		}

		DrawBox(box1.x,box1.y,box1.x+box1.width,box1.y+box1.height, color,true);
		DrawBox(box2.x, box2.y, box2.x + box2.width, box2.y + box2.height, color, true);
		
		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

