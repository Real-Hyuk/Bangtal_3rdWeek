#include <bangtal>
using namespace bangtal;

int main()
{
	auto room1 = Scene::create("��1", "Images/���-1.png");
	auto room2 = Scene::create("��2", "Images/���-2.png");
	auto door1 = Object::create("Images/��-������-����.png", room1, 800, 270);
	auto closed1 = true;
	door1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed1) {
			object->setImage("Images/��-������-����.png");
			closed1 = false;
		}
		else {
			room2->enter();
		}
		return true;
		});

	auto door2 = Object::create("Images/��-����-����.png", room2, 320, 270);
	door2->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		room1->enter();
		return true;
		});
	auto door3 = Object::create("Images/��-������-����.png", room2, 800, 270,false);
	
	auto button = Object::create("Images/����ġ.png", room2, 560, 470);
	button->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		door3->show();
		return true;
		});
	

	auto closed3 = true;
	door3->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed3) {
			object->setImage("Images/��-������-����.png");
			closed3 = false;
		}
		else {
			endGame();
		}
		return true;
		});

	startGame(room1);
}