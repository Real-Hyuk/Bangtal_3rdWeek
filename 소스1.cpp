#include <bangtal>
using namespace bangtal;

int main()
{
	auto room1 = Scene::create("룸1", "Images/배경-1.png");
	auto room2 = Scene::create("룸2", "Images/배경-2.png");
	auto door1 = Object::create("Images/문-오른쪽-닫힘.png", room1, 800, 270);
	auto closed1 = true;
	door1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed1) {
			object->setImage("Images/문-오른쪽-열림.png");
			closed1 = false;
		}
		else {
			room2->enter();
		}
		return true;
		});

	auto door2 = Object::create("Images/문-왼쪽-열림.png", room2, 320, 270);
	door2->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		room1->enter();
		return true;
		});
	auto door3 = Object::create("Images/문-오른쪽-닫힘.png", room2, 800, 270,false);
	
	auto button = Object::create("Images/스위치.png", room2, 560, 470);
	button->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		door3->show();
		return true;
		});
	

	auto closed3 = true;
	door3->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed3) {
			object->setImage("Images/문-오른쪽-열림.png");
			closed3 = false;
		}
		else {
			endGame();
		}
		return true;
		});

	startGame(room1);
}