//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������������������Ϸ�����չ��ȥ���������ʯ���̾Ͷ��ɣ���
�г�����·�����߶���һƬƬ���ֵ����ɴ����ľ���������紵
����������

LONG);

  set("exits", ([
        "west" : __DIR__"yuwang1",
        "east" : __DIR__"yuwang5",
      ]));

  set("outdoors", __DIR__);

  setup();
}

// mon 11/8/98 for ymdh's alternative_die.
void init()
{
    if(!this_player())  return;
    this_player()->delete_temp("ymdh/entered");
}

