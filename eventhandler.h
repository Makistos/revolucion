
namespace eventhandler {
	enum Events_e {
		QUIT = 0,
		KEY_UP = 1,
		KEY_DOWN = 2,
		KEY_LEFT = 3,
		KEY_RIGHT = 4,
		KEY_OTHER = 100
	};
	class EventHandler {
	public:
		EventHandler() {};
		~EventHandler() {};

		Events_e handle(SDL_Event e);
	};
}
