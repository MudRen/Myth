int valid_leave (object who, string dir)
{
  who = this_player();

  if (dir == "north")
    {
  return notify_fail ("���߹���?\n");
    }
  if (dir == "hell")
    {
    return notify_fail ("�����ܡ�\n");
    }
    return 1;
}
