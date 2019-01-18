// created 11/1/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;

void create()
{
  set_name("��", ({ "fish"})); 
  set_weight(100);
  set("long","һ���ɾ����㡣\n");
  set("unit", "��");
  set("value",100);
  setup();
}

int init ()
{
  remove_call_out ("start_jump");
  call_out ("start_jump",1+random(3));
  add_action ("do_get", "get");
  return 1;
}

int do_get (string arg)
{
  object who = this_player();
  object fish = this_object();

  if (arg != "fish" &&
      arg != "all")
    return 0;

  message_vision("$N�����ȥ׽$n��$nһ�ڴ�$N���л����ˡ�\n",who,fish);
  return 1;
}


int start_jump ()
{
  object fish = this_object();
  string str = fish->query("name")+"����һ����\n";
  tell_room (environment(fish),str);
  call_out("do_jump",5+random(5));
  return 1;
}

int do_jump ()
{
  object fish = this_object();
  string *msgs = ({
    "ž��һ����$N����������\n",
    "$N��������\n",
    "$Nž��һ����\n",
    "$Nһͦ��Ծ�ڿ��С�\n",
    "$N����һԾ��\n",
    "$N���˶���\n",
  });
  string str;

  if (random(4) == 0)
  {
    call_out("jump_back",4);
    return 1;
  }

  str = replace_string (msgs[random(sizeof(msgs))],
                        "$N",fish->query("name"));
  tell_room (environment(fish),str);
  call_out("do_jump",3+random(15));
  return 1;
}

int jump_back ()
{
  object fish = this_object();
  string str = fish->query("name")+"���߲����ˡ�\n";
  tell_room (environment(fish),str);
  destruct (fish);
  return 1;
}
