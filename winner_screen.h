#ifndef WINNER_SCREEN_H
#define WINNER_SCREEN_H

class winner_screen
{
public:
  winner_screen();

  bool play_music() const noexcept { return m_play_music; }

private:
  /// Play the Amino Acid Fighter tune?
  bool m_play_music;
};

#endif // WINNER_SCREEN_H
