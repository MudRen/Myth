// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;

void create()
{
  set_name(HIB "��" NOR, ({ "fish"})); 
  set_weight(100);
  set("long","һ���㡣\n");
  set("unit", "��");
  set("value",100);
  setup();
  call_out ("start_jump",1+random(1));
}

void init ()
{
  add_action ("do_get", "get");
}

int do_get (string arg)
{
  object who = this_player();
  object fish = this_object();

  if (arg != "fish" &&
      arg != "all")
    return 0;
  if (random(2) < 1){
      fish->move(who);
      message_vision("$N�����ȥ׽�㣬������׽����!\n", who);
      remove_call_out("do_jump");
	}
  else
      message_vision("$N�����ȥ׽�㣬���һ�ڴ�$N���л����ˡ�\n",who);
  return 1;
}


int start_jump ()
{
  object fish = this_object();
  message_vision ("�����ˮ�����˳�����\n",fish);
  call_out("do_jump",5+random(5));
  return 1;
}

int do_jump ()
{
  object fish = this_object();
  string *msgs = ({
    "ž��һ�����������������\n",
    "�����������\n",
    "���ž��һ����\n",
    "���һͦ��Ծ�ڿ��С�\n",
    "�������һԾ��\n",
    "������˶���\n",
  });

  if (random(4) == 0)
  {
    call_out("jump_back",4);
    return 1;
  }

  message_vision (msgs[random(sizeof(msgs))],fish);
  call_out("do_jump",3+random(15));
  return 1;
}

int jump_back ()
{
  object fish = this_object();
  message_vision ("�������ˮ�в����ˡ�\n",fish);
  destruct (fish);
  return 1;
}
