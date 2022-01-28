#include <rsttlsEngine.h>
loggerClass logger;
int main()
{
  if (logger.init() == 0)
  {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
      logger.log("SDL initilized...");
      try
      {
        gameClass game;
      }
      catch (int err)
      {
        logger.logError(err);
      }
    }
    else
    {
      logger.logSDL();
    }
  }
  else
  {
    std::cout<<"Failed to initilize logger\nExittng...\n";
  }
  return 0;
}