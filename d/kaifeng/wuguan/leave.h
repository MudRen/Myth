int valid_leave (object who, string dir)
{
  who = this_player();

  if (dir == "north")
    {
  return notify_fail ("ÏëÌß¹İÂï?\n");
    }
  if (dir == "hell")
    {
    return notify_fail ("±ğÂÒÅÜ¡£\n");
    }
    return 1;
}
