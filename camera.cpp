#include"camera.h"
#include"DxLib.h"

//���X�N���[���Ȃ̂�X���W�����p�ӂ��ĂȂ�
int camera_X = 0;					//�J������X���W

const int Velocity_X = 300;		//�J������X�����ړ����x

void CamerainputMove(float dt)
{
	if (CheckHitKey(KEY_INPUT_A))
	{
		camera_X -= Velocity_X * dt;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		camera_X += Velocity_X * dt;
	}
}

void CameraInitalize()
{
	camera_X = 0;
}

int GetCamera_X()
{
	return camera_X;
}
