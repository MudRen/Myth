// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/luochi2.c

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
        "west"       : __DIR__"luochi1",
        "east"       : __DIR__"chaoxing",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

void init ()
{
  object who = this_player();
  object where = environment(who);

  if (! present("lanpao guai",where))
  {
    object guai = new (__DIR__"npc/lanpao");
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

