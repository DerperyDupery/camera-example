#pragma once
#include<iostream>

/// @brief Csvfile����}�b�v�̔z����擾
/// @param  �t�@�C���̖��O
void load_csvfile(std::string filepath);

/// @brief �}�b�v�̍��W�̏�����
void InitializeMap();

/// @brief �J�����̍��W����}�b�v�̍��W���X�V
/// @param camera_X �J������X���W
void UpdateMapPos(int camera_X);

/// @brief �}�b�v�̕`��
void DrawMap();
