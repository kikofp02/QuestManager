#include "Player.h"
#include "App.h"
#include "Textures.h"
#include "Audio.h"
#include "Input.h"
#include "Render.h"
#include "Log.h"
#include "Point.h"
#include "Physics.h"

#define FACING_LEFT false
#define FACING_RIGHT true
#define IDLE_STATIC 1
#define IDLE 2
#define RUNNING 3
#define JUMPING 4
#define FALLING 5
#define CHARGING 6
#define DYING 7
#define INITCHARGING 8
#define ENDCHARGING 9
#define WINING 10
#define ATTACKING 11
#define SPECIAL 12


Player::Player() : Entity(EntityType::PLAYER)
{
	name.Create("Player");

}

Player::~Player() {

}

bool Player::Awake() {
	//Get Player parameters from XML
	position.x = parameters.attribute("x").as_int();
	position.y = parameters.attribute("y").as_int();
	texturePath = parameters.attribute("texturepath").as_string();

	return true;
}

bool Player::Start() {

	//initilize textures
	texture = app->tex->Load(texturePath);

	// L07 DONE 5: Add physics to the player - initialize physics body
	//pbody = app->physics->CreateRectangle(position.x+16, position.y+16, 32, 50, bodyType::DYNAMIC);
	pbody = app->physics->CreateCircle(position.x, position.y, 20, bodyType::DYNAMIC);

	// L07 DONE 6: Assign player class (using "this") to the listener of the pbody. This makes the Physics module to call the OnCollision method
	pbody->listener = this; 

	// L07 DONE 7: Assign collider type
	pbody->ctype = ColliderType::PLAYER;

	currentAnim = &idlestaticleftanim;
	facing = FACING_RIGHT;
	dieLeftAnim.Reset();
	dieRightAnim.Reset();

	return true;
}

bool Player::Update()
{
	//PLAYER MOVEMENT
	
	//WINNING SEQUENCE
	
	//ANIMATION STATE MACHINE

	return true;
}

bool Player::PostUpdate() {
	SDL_Rect rect = currentAnim->GetCurrentFrame();
	app->render->DrawTexture(texture, position.x - 38, position.y - 27, &rect);
	currentAnim->Update();

	return true;
}

bool Player::CleanUp()
{
	return true;
}

void Player::OnCollision(PhysBody* physA, PhysBody* physB) {

}

void Player::EndCollision(PhysBody* physA, PhysBody* physB)
{
	
}

PhysBody* Player::getpBody()
{
	return pbody;
}
