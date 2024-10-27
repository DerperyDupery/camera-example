#include"camera.h"
#include"map.h"
#include"Vector.h"
#include"DxLib.h"
#include"Screen.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::vector<int>>map;          // �}�b�v��2�����z��
Vector2D mapPos[27][60];   //�}�b�v�̍��W


const int MapChipSize = 40;

void load_csvfile(std::string filepath)
{
    std::string linebuf;                       // 1�s�ǂݍ��݃o�b�t�@
    std::string data;                          // �J���}��؂�Ő؂�o�����f�[�^�i�[�p

    //�t�@�C���I�[�v��
    std::ifstream csvFile(filepath);
    if (csvFile.fail())
    {
        printfDx("�t�@�C���̃I�[�v���Ɏ��s���܂���\n");
        return;
    }

    // �t�@�C������CSV�ǂݍ���
    int line = 0;
    while (getline(csvFile, linebuf))
    {
        // map�z��̍s��ǉ�
        map.emplace_back();
        //�J���}��؂�œǂ݂₷���悤�� istringstream�^�ɕϊ�
        std::istringstream iStream(linebuf);

        // �J���}��؂�P�ʂ�data�ɕ�����i�[
        while (getline(iStream, data, ','))
        {
            // ������f�[�^�𐔒l�ɕϊ����āAmap[line][]�̖����ɒǉ�
            map[line].emplace_back(stoi(data));
        }
        line++;
    }
}

void InitializeMap()
{
    //�}�b�v�̍��W�������ʂ�ɕ��ׂĂ�
    for (int iy = 0; iy < map.size(); iy++)
    {
        for (int ix = 0; ix < map[iy].size(); ix++)
        {
            mapPos[iy][ix] = { ix * MapChipSize,iy * MapChipSize };
        }
    }
}

void UpdateMapPos(int camera_X)
{
    //�}�b�v�̍��W�ɃJ�����̍��W�𑫂����ƂŃ}�b�v�𓮂����Ă���
    for (int iy = 0; iy < map.size(); iy++)
    {
        for (int ix = 0; ix < map[iy].size(); ix++)
        {
            mapPos[iy][ix].x += camera_X;
        }
    }
}

void DrawMap()
{
    for (int iy = 0; iy < map.size(); iy++)
    {
        for (int ix = 0; ix < map[iy].size(); ix++)
        {
            //�}�b�v�`�b�v�̍��W����ʓ���������
            if (0 - MapChipSize <= mapPos[iy][ix].x && mapPos[iy][ix].x <= SCREEN_X)
            {
                //�}�b�v�`�b�v��0���������̓O���[�A1���������͔�
                if (map[iy][ix] == 0)
                {
                    DrawBox(mapPos[iy][ix].x, mapPos[iy][ix].y, mapPos[iy][ix].x + MapChipSize, mapPos[iy][ix].y + MapChipSize, GetColor(127, 127, 127), FALSE);
                }
                else
                {
                    DrawBox(mapPos[iy][ix].x, mapPos[iy][ix].y, mapPos[iy][ix].x + MapChipSize, mapPos[iy][ix].y + MapChipSize, GetColor(255, 255, 255), FALSE);
                }
            }
        }
    }
}
