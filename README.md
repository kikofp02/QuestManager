## Welcome!

Hello there, I'm Francisco Ferrerós and by the time beeing I am studing a Bachelor's Degree in Videogame Design and Development at the Universitat Politécnica de Catalunya, Barcelona - Spain. I'm currently on my second year of the career and in the sillabus Project II i was demanded to create a research about how to implement a Quest Manager for our RPG game projects.To help with the explanation you can find a slides presentation below.

[Link to the presentation](https://docs.google.com/presentation/d/1sUzmROdSO6PizK6M_0evII9T5EJ6JOWZUksZApChd1Y/edit?usp=sharing)

## Introduction

First of all, what are quests? If you are here I sopose you already know that but, to refresh our memory, quests (within the scope of videogames) are tasks or demands that players get in a certain point of a game, that if they complete, usualy, they get a reward in exchange. Lots of game progresions are based on the completion of the game's quests due that the rewards of the quest, usualy are upgrades for the player, money, history progress or other main pillars on the game's progression.

As you can see, due to the importance of the quests in videogames, it is very common that games don't have one quest but lots of them. If we are supposed to manage that in terms of code, to help us, here is where quest managers enter in the scene. Quest managers are the ones that lead the quests of a game. They manage the saves of the quests and their states, they update the quests and they trigger them when they are supposed to.

## Creating your quest manager

So, now you know that you need a quest manager, but wher you should start? Before starting to code anything, you must plan how you whant your game quest system to be so lets get into it.

### Quest System

The quest system consist in how the quests are implemented in your game. Are you planing to have a main storyline of quests and then secondary quests that pop up douring the playthrough. Or perhaps you only whant a system without the quests visible in game but use the quest manager to trak the progress of the player. Here you must think depply on what type of game is yours but there are some things to take into account when planing the quest system:

1.  **Importance:** what is the role of the quests in your game? Are they just a way to trak progression, does the player upgarde by completing them, there is a story questline or are they just play a secondary role in the game?
2.  **Linearity:** will the solution of the quests guide the player by one path or he could find multiple solutions?
3.  **Generation:** how are the quests triggered or generated? Are all the quests acquired the same way?
4.  **Modularity:** which are your quest types to make presets for the quests? The most common types are:
  - Syntax or text quests: these are the ones dedicated to chat with npc and chose the right path of the dialogue.
  - Gather quests: you are demanded to collect a certain ammount of a specific collectable.
  - Kill quests: in these you have to killa certain ammount of a specific mob or enemy.
  - Delivery quests: you are given an item that has to be given to a certain npc.
  - Escort quests: in which you have to guide an npc to a certain place and fight to protect him douring the journey.
  - Hybrid quests: these are combinations of the above types.
5.  **Relations:** what other systems is our quest manager relatid with? Such as a _Dialogue system, Events System, NPC's System, Game World, etc_.

Now that we have an idea of what we need in our game we can start to create our quest manager. I will put a mock scenario for you to understand how the quest manager works. I wont teach you how to recreate the quest manager from scrach but I'll try to make you understand the core of it's workflow and the utilities it offers for you to develop it in your projects. So please download the template for the exercises [here](https://github.com/kikofp02/QuestManager/tree/Handout).

## Implementing a Quest Manager

In our template we will recreate a mock scenario. We have a map, with a player that can move within the tiles and some NPC, all made very basic. So we will try to create a story where us, the player, are demanded with a questline. The example goes throug 2 quests:
1.  A Text/Chat quest where you are demanded to talk with a certain NPC.
2.  A Collect quest where you have to find and collect one item on the world.

So now, with a questline we can begin to create the quest manager. The main steps we need or quest manager to follow will be:
- Have the proper parameters on the config file of the program.
- Make the quest manager to create the quests at the begining of the program.
- Load the parameters of the config file to the proper quest in each quest constructor.
- Create a list of the quests that start active on the begining of the app.
- Load to an active quests list the quests that are currently running.
- Make the quest manager instantiate and run all the active quests updates.
- Generate some kind of event on each quest update that if it happens makes the update return false, indicating that the quest has been completed.
- Make the quest manager do the arrangements for the change of the active quest to the next quest in the questline.

### TODOS

Now you will go throug a certain amount of TODOS in which you will have to solve certain code proposals in order for the quest manager to work completly. The main foundations are allready implemented so if you solve the issues the program will run correctly. You can find the answeres here and a solved program in this [branch](https://github.com/kikofp02/QuestManager/tree/Solved_Handout).

#### TODO 1

Edit the config.xml file to complete the quests parameters.

```c++
// config.xml file changes:

		<!-- Complete the quest structure -->
		<quest type="0" id="1" name="TALK WITH GRANDPA KIKO" description="Search for your grandfather hwo needs your help." nextQuestId="2" npcId="2" reward="700"></quest>
		<quest type="1" id="2" name="FIND GRANDPA S LOST CHESTS" description="Grandpa's chests disappeared long ago. They have to be somewhere!" nextQuestId="0" itemId="1" reward="0"></quest>
```

#### TODO 2

Load the parameters to the quest in his constructor.

```c++
// TextQuest.cpp file changes:

TalkQuest::TalkQuest(pugi::xml_node node) {
	// TODO 2 - Load all the parameters of the quest
	this->id = node.attribute("id").as_int();
	this->name = node.attribute("name").as_string();
	this->description = node.attribute("description").as_string();
	this->nextQuestId = node.attribute("nextQuestId").as_int();
	this->npcId = node.attribute("npcId").as_int();
	this->reward = node.attribute("reward").as_int();
	this->type = QuestType::TALK;
}
```

#### TODO 3

Make the creation of the quests in the quest manager's awake depending on the quest type marked in the config file.

```c++
// QuestManager.cpp file changes:

		Quest* quest;
		// TODO 3 - Create the quests depending on the type attribute
		switch ((QuestType)node.attribute("type").as_int())
		{
		case QuestType::TALK:
			quest = new TalkQuest(node);
			break;
		case QuestType::COLLECT:
			quest = new CollectQuest(node);
			break;
		default:
			break;
		}

		quests.Add(quest);
```

#### TODO 4

Nest in the config file the quests that will start enabled and then, on the quest manager, add them to the list of active quests.

```c++
// config.xml file changes:
    
		<activequests>
			<!-- TODO 4 - Add the list of quests active on the begining of the program -->
			<quest id="1"></quest>
		</activequests>
    
    
// QuestManager.cpp file changes:

		ListItem<Quest*>* qitem = quests.start;
		while (qitem != nullptr)
		{
			Quest* item = qitem->data;
			//TODO 4 - If it's a quest that has to go in the actives list, add it to it
			if (item->id == node.attribute("id").as_int()) {
				activeQuests.Add(item);
				break;
			}

			qitem = qitem->next;
		}
```

#### TODO 5

Update the lists of quests when a quest is completed (output of the update of the quest is fasle).

```c++
		if (pQuest->Update() == false) {
			// TODO 5 - When the quest is completed, we have to deleted from actives list, add the next quest to actives list and then add the completed quest to the copleted quests list
			activeQuests.Del(item);

			ListItem<Quest*>* qitem = quests.start;
			while (qitem != nullptr)
			{
				Quest* item = qitem->data;
				if (item->id == pQuest->nextQuestId) {
					activeQuests.Add(item);
					break;
				}

				qitem = qitem->next;
			}

			completedQuests.Add(pQuest);
		}
```

## Review

Well, that's all I had to offer for this research. The quest manager implemented here is something rudimentary that was made for the purpose of the understanding of the true functionalities of a proper quest manager. Althogh, I spent lots of time for it to be profitable for others making it modular and esy to personalize. I encourage you to use it for your projects or whatever you whant.

Thanks for reviewing my hard work, it makes me feel that skipping a sleep cicle to finish this was worth doing.

## Bibliography

- [Link to the presentation](https://docs.google.com/presentation/d/1sUzmROdSO6PizK6M_0evII9T5EJ6JOWZUksZApChd1Y/edit?usp=sharing)
- [Documentation for the explanation](https://en.wikipedia.org/wiki/Quest_(video_games)#Overview)
- [Documentation for the coding](https://www.youtube.com/playlist?list=PL4G2bSPE_8umJfOuXxut28OQyIliW2Pfp)
- [Awesome project with lots of inspiring ideas](https://github.com/MagiX7/TheHunterOdyssey)
