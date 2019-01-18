// rewritten by snowcat on 4/11/1997
// Room: shimen

inherit ROOM;

void create ()
{
  set ("short", "ʯ����");
  set ("long", @LONG

�����������ʯ����ɽ�����ݶ��ɡ�����һ����ʯ(stone)������
Ϊ���϶���ʱ׼���ġ�

LONG);

  set("light_up", 1);
  set("outdoors", "firemount");
  set("exits", ([
// 19          "southup" : __DIR__"nonamero",
        "west" : __DIR__"dongkou",
      ]));
  set("item_desc", ([
        "stone" : "һ��ʯͷ��������Щʯͷ�������š�\n",
      ]));

  setup();
}

void init()
{
  add_action("do_get", "get");
  add_action("do_hit", "hit");
}

int do_get (string arg)
{
  object stone;
  object me = this_player();

  if (arg != "stone")
    return 0;

  stone = new (__DIR__"obj/stone");
  stone->move(me);
  message_vision("$N��ʯ�����ó�һ��ʯͷ��\n",me);
  return 1;
}

int do_hit (string arg)
{
  object me = this_player();

  if (!present("stone",me))
    return 0;

  me->add_temp("obstacle/firemount_hit_door",1);
  if ((arg != "shimen" &&
       arg != "door") ||
      me->query_temp("obstacle/firemount_hit_door") > 10)
  {
    message_vision("$N����ʯͷ��һ��С�������Լ����ϡ�\n",me);
    return 1;
  }
  message_vision("$N����ʯͷ������������ʯ�š�\n",me);
  call_out("cloud_or_fog_appear",random(5)+5,me);
  return 1;
}

void cloud_or_fog_disappear(object me)
{
  if(!me) return;
  message_vision ("$N�������ں�ɫ��������ʧ�ˡ�\n",me);
  destruct(me);
}

void cloud_or_fog_appear(object me)
{
  object cloud;
  object fog;

  if(!me) return;

  if (! present("cloud fog",this_object()) &&
      random(2) == 0)
  {
    cloud = new (__DIR__"npc/cloud");
    cloud->move(environment(me));
    message_vision("һ����ƽ��٣�$N��������֡�\n",cloud);
    call_out("cloud_or_fog_disappear",20,cloud);
  }

  if (! present("fog cloud",this_object()) &&
      random(2) == 0)
  {
    fog = new (__DIR__"npc/fog");
    fog->move(environment(me));
    message_vision("һ������٣�$N��������֡�\n",fog);
    call_out("cloud_or_fog_disappear",20,fog);
  }
}
