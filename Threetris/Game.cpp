#include "Game.h"
#include "Field.h"
Game* Game::Inst = NULL;

Game::Game():curField(NULL){
}

Game::~Game() {

}

bool Game::init() {

	// �������� �ʱ�ȭ

	curField = new Field;
	if (!curField->init())
		return false;

	return true;
}

void Game::run() {
	curField->draw();
}

