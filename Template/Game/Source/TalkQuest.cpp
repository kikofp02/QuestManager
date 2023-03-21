#include "TalkQuest.h"
#include "App.h"
#include "Audio.h"
#include "Input.h"
#include "Log.h"
#include "Point.h"
#include "Scene.h"

TalkQuest::TalkQuest(pugi::xml_node node) {
	// TODO 2 - Load all the parameters of the quest
	this->id = ;
	this->name = ;
	this->description = ;
	this->nextQuestId = ;
	this->npcId = ;
	this->reward = ;
	this->type = QuestType::TALK;
}

TalkQuest::~TalkQuest() {}

bool TalkQuest::Update() {
	bool ret = true;

	//Check completion event
	ListItem<NPC*>* nitem = app->scene->npcs.start;
	NPC* npc = nitem->data;
	while (nitem != nullptr)
	{

		if (npc->npcid == this->npcId) { break; }
		nitem = nitem->next;
		npc = nitem->data;
	}

	//Completion event: player is in npc boundaries and talks to him (G key)
	if ((app->scene->player->tile.x * 32 >= npc->boundaries.x) &&
		(app->scene->player->tile.x * 32 < npc->boundaries.x + npc->boundaries.w) &&
		(app->scene->player->tile.y * 32 >= npc->boundaries.y) &&
		(app->scene->player->tile.y * 32 < npc->boundaries.y + npc->boundaries.h) &&
		(app->input->GetKey(SDL_SCANCODE_G) == KEY_DOWN)) {
		ret = false;

		app->scene->points += this->reward;
	}

	return ret;
}