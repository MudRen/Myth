// rewritten by snowcat on 4/11/1997
// room: cuiyun3

inherit ROOM;

int room_busy = 0;
int no_bone = 0;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

ɽ����ľ�дУ����������һ�����ﻨ��ľ���ɽ��Ρ����ʣ�
ɽ���������ƣ�������������Դ������������������������������
��ľ֮����·����һ��һ�����߰������֦������ȥ���������˷�
������

LONG);

  set("objects", ([
        __DIR__"npc/qiaofu" : 1,
      ]));
  set("outdoors", "firemount");
  set("exits", ([
        "westup"    : __DIR__"cuiyun2",
        "northdown" : __DIR__"cuiyun4",
      ]));

  setup();
}

void init()
{
  add_action("do_search", "search");
}

int do_search (string arg)
{
  object me = this_player();

  if (!arg || arg != "bone")
  {
    message_vision ("$N����ȥѰ��ʲô��\n",me);
    return 1;
  }

  if (!me->query_temp("know_palm_bone"))
  {
    message_vision ("$N����ȥ�ڿ���֦����ҷ���������\n",me);
    return 1;
  }

  if (me->query("combat_exp")<4000)
  {
    message_vision ("$N���в�����Ҳ�ڿ���֦��װģ�����ط�����ȥ��\n",me);
    return 1;
  }  

  if (room_busy)
  {
    remove_call_out ("reset_room_busy");
    call_out ("reset_room_busy",random(5)+5);
    message_vision ("$N�ڿ���֦��Ϲæ����\n",me);
    return 1;
  }

  if (no_bone)
  {
// remove_call_out("reset_no_bone");
// call_out("reset_no_bone",2700);
    message_vision ("$N�����ѿ���֦������Ҳ�Ҳ���ʲô���ˡ�\n",me);
    return 1;
  }

  if (random(10) == 0)
  {
    object bone = new (__DIR__"obj/bone");
    bone->move(me);
    message_vision ("$N�۾�һ�����Ž��ǣ�\n",me);
    message_vision ("\n$N��������û��ע��Ͻ��ѰŽ��Ǵ������\n",me);
    no_bone = 1;
    call_out ("reset_no_bone",3600);
    return 1;   
  }

  message_vision ("$N������ڿ���֦�﷭����ȥ�ҰŽ��ǡ�\n",me);
  room_busy = 1;
  call_out ("reset_room_busy",random(5)+5);
  return 1;
}

void reset_room_busy()
{
  room_busy = 0;
}

void reset_no_bone()
{
  no_bone = 0;
}
