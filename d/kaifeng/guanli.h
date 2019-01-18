// create by snowcat.c 2/8/1997

#include <command.h>
#include <ground.h>

void init ()
{
  set("no_fight",1);
  set("no_magic",1);
  set("no_quit",1);
  add_action ("do_look","look");
}

void write_objects (object room, object who)
{
  mixed *inv = all_inventory (room);
  int i = sizeof(inv);

  while (i--)
  {
    object ob = inv[i];
    if (! who->visible(ob) || ob == who)
      continue;

    write ("  "+ob->short()+"\n");    
  }
}

int do_look (string arg)
{
  object who = this_player();
  object room = environment(who);

  if (arg)
    return 0;

  LOOK_CMD->look_room(who,room);

  room = load_object (__DIR__"ground");
  if (! room)
    return 1;

  write ("\n        ���������������������ڡ���������������\n");
  write (room->query("long"));    
  write_objects(room, who);
  write ("\n        ��������������������������������������\n");
  return 1;    
}

int can_enter (object who)
{
  object ground = load_object (__DIR__"ground");
  int step;
  int mode;
  mapping teams;

  if (! ground)
    return notify_fail ("�Բ��������ܽ���������ء�\n");
  
  step = ground->query("match/step");
  mode = ground->query("match/mode");
  teams = ground->query("match/teams");

  if (step == STEP_PREPARE)
    return notify_fail ("�Բ��𣬱�����δ��ʼ�������ܽ��볡�ء�\n");
  if (step == STEP_FINISH)
    return notify_fail ("�Բ��𣬱����Ѿ������������ܽ��볡�ء�\n");

  if (mode == MODE_SINGLE_SD)
  {
    object *inv = all_inventory(ground);
    int i, j;

    i = sizeof (inv);
    j = 0;
    while (i--)
    {
      if (userp(inv[i]) && !wizardp(inv[i]))
        j++;
    }
    if (j >= 2)
      return notify_fail ("�Բ��𣬳����Ѿ���ѡ�ֱ����������ܽ�ȥ��\n");
  }
  else
  {
    if (! teams)
      return notify_fail ("�Բ��𣬳�������δ��ӣ������ܽ�ȥ��\n");
    if (teams["current_player0_id"] != who->query("id") &&
        teams["current_player1_id"] != who->query("id")) 
      return notify_fail ("�Բ���������ѡ�֣����ܽ��볡�ء�\n");
 }
  return 1;
}
