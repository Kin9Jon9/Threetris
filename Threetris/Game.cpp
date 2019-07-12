#include "Game.h"
#include "Field.h"
Game* Game::Inst = NULL;

Game::Game():curField(NULL){
}

Game::~Game() {

}

bool Game::init() {

	// 스테이지 초기화

	curField = new Field;
	if (!curField->init())
		return false;

	return true;
}

void Game::run() {
	curField->draw();
}

