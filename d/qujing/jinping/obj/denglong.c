// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>
#include <weapon.h>

inherit STICK;

string *names = ({
  "�ɻ���",
  "������",
  "ѩ����",
  "�ۻ���",
  "÷����",
  "������",
  "����",
  "�����",
  "����",
  "���õ�",
  "������",
  "������",
  "�����",
  "������",
  "������",
  "�λõ�",
  "�����",
  "�����",
  "�ɺ׵�",
});

void create()
{
  seteuid(getuid());

  set_name(names[random(sizeof(names))], ({ "deng long", "deng", "long"})); 
  set_weight(900);
  set("long","һ������Ѷ���"+query("name")+"��\n");
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 1);
  set("armor_type", "lamp");
  set("wear_msg", "\n$N����������ͷ����\n");
  set("wield_msg", "\n$N����������ͷ����\n");
  set("unequip_msg", "$N��������������\n");
  set("unwield_msg", "$N��������������\n");
  set("value",100);
  setup();
  init_stick(1);
}

int init ()
{
  add_action ("do_wear", "wear");
  //add_action ("do_wear", "wield");
  add_action ("do_remove", "remove");
  //add_action ("do_remove", "unwield");
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object denglong = this_object();
  int i;
  int j = 0;
  string people = "";
  object *obs = all_inventory(environment(me));

  if (! arg)
    return 0;
  if (present (arg,me) != denglong)
    return 0;

  i = sizeof (obs);
  while (i--)
  {
    if (living (obs[i]) && obs[i]!=me &&
        me->visible(obs[i]) ) //added by mon 1/18/98
    {
      j++;
      people = people + obs[i]->name();
    }
  }
  message_vision ("$N��һ�����һ��$n���û������\n",me,denglong);
  remove_call_out ("reacting");
  call_out ("reacting",1+random(3),me,people,j);
  return 0;
}

void reacting (object me, string people, int j)
{
  if (j == 0 || !me)
    return;

  if (j == 1)
    message_vision ("���̲�ס�е����õƣ��õƣ�\n",me);
  else
    message_vision (people+"�����̲�ס�����е����õƣ��õƣ�\n",me);
}

int do_remove (string arg)
{
  object me = this_player();
  object denglong = this_object();

  if (! arg)
    return 0;
  if (present (arg,me) != denglong)
    return 0;

  message_vision ("$N��ʹս�$n���۵�����һ����\n",me,denglong);
  return 0;
}

