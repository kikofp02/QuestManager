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

Now that we have an idea of what we need in our game we can start to create our quest manager. I will put a mock scenario for you to understand how the quest manager works. I wont teach you how to recreate the quest manager from scrach but I'll try to make you understand the core of it's workflow and the utilities it offers for you to develop it in your projects. So please download the template for the exercises [here]().

## Implementing a Quest Manager

In our template we have
```c++
//Lorem ipsum
int lorem = 0;
end
```

### TODOS

Now you will go throug a certain amount of TODOS in which you will have to solve certain code proposals in order for the quest manager to work completly.

#### TODO 1
