#include "QuestManager.h"
#include "App.h"
#include "Textures.h"
#include "TalkQuest.h"
#include "CollectQuest.h"

#include "Defs.h"
#include "Log.h"

QuestManager::QuestManager(bool active) : Module(active)
{
	name.Create("questmanager");
}

// Destructor
QuestManager::~QuestManager()
{}

// Called before render is available
bool QuestManager::Awake(pugi::xml_node& config)
{
	LOG("Loading Quest Manager");
	bool ret = true;

	for (pugi::xml_node node = config.child("quest"); node; node = node.next_sibling("quest"))
	{
		Quest* quest;
		// TODO 3 - Create the quests depending on the type attribute

		quests.Add(quest);
	}

	for (pugi::xml_node node = config.child("activequests").child("quest"); node; node = node.next_sibling("quest"))
	{
		ListItem<Quest*>* qitem = quests.start;
		while (qitem != nullptr)
		{
			Quest* item = qitem->data;
			//TODO 4 - If it's a quest that has to go in the actives list, add it to it
			

			qitem = qitem->next;
		}
	}

	return ret;
}

bool QuestManager::Start() {

	LOG("Starting Quest Manager");
	bool ret = true;

	return ret;
}

bool QuestManager::Update(float dt)
{
	bool ret = true;

	ListItem<Quest*>* item;
	Quest* pQuest = NULL;

	for (item = activeQuests.start; item != NULL; item = item->next)
	{
		pQuest = item->data;

		if (pQuest->Update() == false) {
			// TODO 5 - When the quest is completed, we have to deleted from actives list, add the next quest to actives list and then add the completed quest to the copleted quests list
			
		}
	}

	return ret;
}