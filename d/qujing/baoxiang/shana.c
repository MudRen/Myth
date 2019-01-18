// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/luochi1.c

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

ɽ�ϻ���������ʯ��㣬�β��س���һЩ���ֹ�ľ��·����
ʯ��Χ�Ƶ�������ɽ���У��ػ����ۡ��Ĵ��紵�ݶ����չȻ�����
���˻�Ȼ��֪������

LONG);

  set("exits", ([
        "southwest"  : __DIR__"shan1",
        "east"       : __DIR__"luochi2",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

void init ()
{
  object who = this_player();
  object where = environment(who);

  if (! present("qingpao guai",where))
  {
    object guai = new (__DIR__"npc/qingpao");
    guai->move(where);
  }
}

int valid_leave (object who, string dir)
{
  remove_call_out ("clearing");
  call_out ("clearing",3);
  return ::valid_leave(who, dir);
}

void clearing ()
{
  object guai = present ("guai", this_object());

  if (! guai)
    return;

  guai->disappearing();
  remove_call_out ("clearing");
  call_out ("clearing",3);
}
