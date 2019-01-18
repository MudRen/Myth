// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "媹�Ȫ");
  set ("long", @LONG

һ����Ȫˮ�������أ�һ��ʮ�ɶ೤������������ԡ��������
չ����͸����������ˮ�峹�ף����ĳ߶���ص�ˮ�ƹ��鷺
�񣬹Ƕ���ð��������

LONG);

  set("exits", ([
        "northup"    : __DIR__"menqiang",
      ]));
  set("objects", ([
        __DIR__"npc/girl6"    : 1,
        __DIR__"npc/girl7"    : 1,
      ]));
  set("resource", ([
        "water"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  object who = this_player();
  object where = this_object();

  if (! objectp(who)) return;
  if (who->query("combat_exp")<10000)
  {
    message_vision ("$N�ڽ�������һ�������������󡱡���\n",who);
//    who->unconcious();
  }
  remove_call_out ("boiling");
  call_out ("boiling",1,where);
  remove_call_out ("playing");
  call_out ("playing",2+random(4),where);
}

void boiling (object where)
{
  string *msgs = ({
   "һ������ð������",
   "Ȫˮ΢΢��ð��ˮ�ݷ�����",
   "��Ȫˮ��������",
   "������ˮ����Ʈ��",
   "�紵����ŨŨ������������Ʈ��",
   "������ð����ˮ��",
  });

  tell_room (where,msgs[random(sizeof(msgs))]+"��\n");
  remove_call_out ("boiling");
  if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
  call_out ("boiling",random(10)+20,where);
 
}

object finding (object where, int find_npc)
{
  object *obs = all_inventory (where);
  object ob;
  int i = sizeof(obs);

  if (i == 0)
    return 0;
  ob = obs[random(i)];
  if (! living(ob))
    return 0;
  if (interactive(ob) && find_npc)
    return 0;

  return ob; 
}

void playing (object where)
{
  object ob1 = finding (where,1);
  object ob2 = finding (where,0);

  remove_call_out ("playing");
  if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
  call_out ("playing",15+random(15),where);

  if (! objectp(ob1))
    return;
  if (! objectp(ob2))
    return;
  if (ob1->is_fighting())
    return;
  switch (random(10))
  {
    case 0:
    {
      ob1->command_function("remove all");
      break;
    }
    case 1:
    {
      ob1->command_function("wear all");
      break;
    }
    case 2:
    {
      ob1->command_function("look "+ob2->query("id"));
      break;
    }
    case 3:
    {
      ob1->command_function("smile "+ob2->query("id"));
      break;
    }
    case 4:
    {
      ob1->command_function("blush "+ob2->query("id"));
      break;
    }
    case 5:
    {
      ob1->command_function(":D "+ob2->query("id"));
      break;
    }
    case 6:
    {
      ob1->command_function(":) "+ob2->query("id"));
      break;
    }
    case 7:
    {
      ob1->command_function("beauty "+ob2->query("id"));
      break;
    }
    case 8:
    {
      ob1->command_function("tickle "+ob2->query("id"));
      break;
    }
    case 9:
    {
      ob1->command_function("wink "+ob2->query("id"));
      break;
    }
  }
}
