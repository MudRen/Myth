// create by snowcat.c 2/8/1997

inherit ROOM;
inherit __DIR__"ground3";

#include <ground.h>

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������Ǹ߸ߵĹ������̨��ʮ�ɼ����ĳ��������������
����һȦ��ɫ���ʯ�������������Ƶ��ĸ��޴����ͭ������
�����м������ɵ�Ƥ��֯��̺��

LONG);

  set("exits", ([
        "westup"  : __DIR__"west",
        "eastup"  : __DIR__"east",
        "northup"  : __DIR__"north",
        "southup"  : __DIR__"south",
      ]));
  set("objects", ([
        __DIR__"npc/wei"  : 1,
        __DIR__"npc/siguan"  : 2,
      ]));
  set("no_quit",1);
  set("no_flee",1);
  set("broadcast",1);
  set("alternative_die",1);
  set("can_always_kill", 1);
  setup();
}

void init ()
{
  object who = this_player();

  if (wizardp(who))
  {
    init0();
    init1();
    init2();
    init3();
    call_out ("hinting",1,who);
  }
  add_action ("do_fight","fight");
  add_action ("do_fight","kill");
  
  who->delete_temp("sldh_opponent");
}

int check_fighters (object who, object ob)
{
  object *inv = all_inventory (environment(who));
  object wei = present ("wei zheng", environment(who));
  string names = "";
  int i = sizeof (inv);

  if (ob == wei)
    return 0;

  while (i--)
  {
    if (inv[i]==who || inv[i]==ob || inv[i]==wei)
      continue;
    if (inv[i]->is_fighting())
      names += inv[i]->name();
  }
  if (names != "")
  {
    message_vision ("$N��$n˵�����ⳡ��"+names+"������������ɱ�����Ժ�Ƭ�̣�\n",wei,who);
    return 0;
  }
  if (! userp(who) || ! userp(ob))
    return 1;
  call_out ("wait_and_announce",1,who,ob);

  // mon
  who->set_temp("sldh_opponent",ob);
  ob->set_temp("sldh_opponent",who);

  return 1;
}

void wait_and_announce (object who, object ob)
{
  mapping match = this_room()->query("match");
  int step;
  string name0, name1, names;

  if (! match)
    return;
  step = match["step"];
  if (step != STEP_FIGHT)
    return;
  if (! who || ! ob)
    return;
  name0 = who->query("name");
  name1 = ob->query("name");
  
  if (strcmp(name0,name1) > 0)
    names = name0 + name1;
  else
    names = name1 + name0;
  if (match["fighters"] == names)
    return;

  match["fighters"] = names;
  announce (name0 + "��" + name1 + "ˮ½��������ಫ��\n");
}

int do_fight (string arg)
{
  object who = this_player();
  object ob;

  if (! arg)
    return 0;
  ob = present (arg, environment(who));
  if (! ob)
    return 0;
  if (! check_fighters (who, ob))
    return 1;
  "/cmds/std/kill"->main(who,arg);
  return 1;
}

void hinting (object who)
{
  tell_object (who, "\n");
  tell_object (who, "����������������������������\n");
  tell_object (who, "����ֳﱸ�������������Ƚ׶Σ���ͬ�׶��в�ͬ�����\n");
  tell_object (who, "��ʹ������ʱ��ע���Ƿ���������ʦҲ�ڴ����ñ������ݡ���\n");
  tell_object (who, "�󡡡�������������������������������������������������\n");
  tell_object (who, "��������ʱʹ�� ? �� what ����ѯ������ʹ�õ���� ����\n");
  tell_object (who, "����������������������������\n");
  tell_object (who, "\n");
}

